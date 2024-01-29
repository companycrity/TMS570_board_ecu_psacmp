Option Explicit
'Restore the work area from a backup directory after a metrics overlay.
'Author: Blake Latchford
'Date:3/27/14

Dim ProjectDir : ProjectDir = WScript.Arguments(0)
Dim BackupDir : BackupDir = WScript.Arguments(1)
Dim FSO

Const ReadOnly = 1

Set FSO = CreateObject("Scripting.FileSystemObject")

If Not FSO.FolderExists(BackupDir) Then
	WScript.Echo "No backup folder exists."
	WScript.Quit
End If

VerifyDirectory "", FSO.GetFolder(BackupDir)
RecursiveRestore "", FSO.GetFolder(BackupDir)

FSO.DeleteFolder(BackupDir)
WScript.Echo "Work area restored."
WScript.Quit

'Verify that the directory structure for the backup and work area match.
Sub VerifyDirectory(RelativePath, Folder)
	Dim SubFolder
	Dim SubFolderRelativePath
	
	For Each SubFolder in Folder.SubFolders
		SubFolderRelativePath = RelativePath & "\" & SubFolder.Name
		
		If Not FSO.FolderExists(ProjectDir & SubFolderRelativePath) Then
			WScript.Echo ("Backup folder '" & SubFolderRelativePath & "' not present in working area.")
			WScript.Quit
		End If
		
		VerifyDirectory SubFolderRelativePath, SubFolder
	Next
End Sub

'recurse through the backup directory, and copy all files from there to the work area.
Sub RecursiveRestore(RelativePath, Folder)
	Dim SubFolder
	Dim SubFolderRelativePath
	Dim File
	
	For Each File in Folder.Files
		RestoreFile RelativePath, File.Name
	Next
	
	'Recurse into all backup sub-folders.
	For Each SubFolder in Folder.SubFolders
		SubFolderRelativePath = RelativePath & "\" & SubFolder.Name
		
		If Not FSO.FolderExists(BackupDir & SubFolderRelativePath) Then
			WScript.Echo "Backup contains folder not in integration project."
			WScript.Quit
		End If
		
		RecursiveRestore SubFolderRelativePath, SubFolder
	Next
End Sub

'Copy the file from the backup to the project.
Sub RestoreFile(RelativePath, FileName)
	Dim BackupFileName
	Dim ProjectFileName
	
	BackupFileName = BackupDir & RelativePath & "\" & FileName
	ProjectFileName = ProjectDir & RelativePath & "\" & FileName
	
	ClearReadOnly BackupFileName
	ClearReadOnly ProjectFileName
	
	If Not FSO.FileExists(ProjectFileName) Then
		WScript.Echo "File '" & ProjectFileName & "' in backup, but not integration project."
		WScript.Quit
	End If
	
	LogInfo ("Restore file:" & ProjectFileName)
	FSO.CopyFile BackupFileName, ProjectFileName
End Sub

'Clear the read only attribute on a file.
Sub ClearReadOnly(FileName)
	Dim File
	
	If FSO.FileExists(FileName) Then
		Set File = FSO.GetFile(FileName)
		
		If File.Attributes AND ReadOnly Then
			File.Attributes = File.Attributes XOR ReadOnly
		End If
	End If
End Sub

'Only write the string to stdout if executing from console.
Sub LogInfo(str)
	Dim ScriptHostName
	
	ScriptHostName = Right(LCase(Wscript.FullName), 11)
	
	If ScriptHostName = "cscript.exe" Then
		WScript.Echo str
	End If
End Sub