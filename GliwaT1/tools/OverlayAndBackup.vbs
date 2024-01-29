Option Explicit
'Copy the overlay directory onto the project directory. Make a backup to restore the work area.
'Author: Blake Latchford
'Date:3/27/14

Dim ProjectDir : ProjectDir = WScript.Arguments(0)
Dim OverlayDir : OverlayDir = WScript.Arguments(1)
Dim BackupDir : BackupDir = WScript.Arguments(2)
Dim FSO

Const ReadOnly = 1

Set FSO = CreateObject("Scripting.FileSystemObject")

If FSO.FolderExists(BackupDir) Then
	WScript.Echo("OverlayBackup directory must be deleted before overlay is performed.")
	WScript.Quit
End If

VerifyDirectory "", FSO.GetFolder(OverlayDir)

'Only create the backup directory if the copy is expected to be completed.
FSO.CreateFolder BackupDir
RecursiveBackupAndOverlay "", FSO.GetFolder(OverlayDir)

WScript.Echo "Overlay performed successfully."
WScript.Quit

'Verify that the directory structure for the overlay and work area match.
Sub VerifyDirectory(RelativePath, Folder)
	Dim SubFolder
	Dim SubFolderRelativePath
	
	For Each SubFolder in Folder.SubFolders
		SubFolderRelativePath = RelativePath & "\" & SubFolder.Name
		
		If Not FSO.FolderExists(ProjectDir & SubFolderRelativePath) Then
			WScript.Echo ("Overlay folder '" & SubFolderRelativePath & "' not present in working area.")
			WScript.Quit
		End If
		
		VerifyDirectory SubFolderRelativePath, SubFolder
	Next
End Sub

'
Sub RecursiveBackupAndOverlay(RelativePath, Folder)
	Dim SubFolder
	Dim SubFolderRelativePath
	Dim File
	
	For Each File in Folder.Files
		OverlayFile RelativePath, File.Name
	Next
	
	For Each SubFolder in Folder.SubFolders
		SubFolderRelativePath = RelativePath & "\" & SubFolder.Name
		
		If Not FSO.FolderExists(BackupDir & SubFolderRelativePath) Then
			FSO.CreateFolder (BackupDir & SubFolderRelativePath)
		End If
		
		If Not FSO.FolderExists(ProjectDir & SubFolderRelativePath) Then
			WScript.Echo ("Overlay folder '" & SubFolderRelativePath & "' not present in working area.")
			WScript.Quit
		End If
		
		RecursiveBackupAndOverlay SubFolderRelativePath, SubFolder
	Next
End Sub

'Copy a file from the work area to the backup,
'then replace the work area file with the overlay file.
Sub OverlayFile(RelativePath, FileName)
	Dim OverlayFileName
	Dim BackupFileName
	Dim ProjectFileName
	
	OverlayFileName = OverlayDir & RelativePath & "\" & FileName
	BackupFileName = BackupDir & RelativePath & "\" & FileName
	ProjectFileName = ProjectDir & RelativePath & "\" & FileName
	
	ClearReadOnly OverlayFileName
	ClearReadOnly ProjectFileName
	
	LogInfo ("Copying file:" & RelativePath & "\" & FileName)
	
	If FSO.FileExists(ProjectFileName) Then
		ClearReadOnly BackupFileName
		FSO.CopyFile ProjectFileName, BackupFileName
	End If
	
	FSO.CopyFile OverlayFileName, ProjectFileName
End Sub

'Clear the readonly flag on a file to be overwritten.
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