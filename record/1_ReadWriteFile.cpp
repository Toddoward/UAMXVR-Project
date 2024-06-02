

#include "1_ReadWriteFile.h"

#include "HAL/PlatformFileManager.h" // Core
#include "Misc/FileHelper.h" // Core

FString U_1_ReadWriteFile::ReadStringFromFile(FString FilePath, bool& bOutSuccess, FString& OutInfoMessage)
{
	// Check if the file exists
	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*FilePath))
	{
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("Read String From File Failed - File doesn't exist - '%s'"), *FilePath);
		return "";
	}

	FString RetString = "";

	// Try to read the file. Output goes in RetString
	if (!FFileHelper::LoadFileToString(RetString, *FilePath))
	{
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("Read String From File Failed - Was not able to read file. Is this a text file? - '%s'"), *FilePath);
		return "";
	}

	bOutSuccess = true;
	OutInfoMessage = FString::Printf(TEXT("Read String From File Succeeded - '%s'"), *FilePath);
	return RetString;
}


void U_1_ReadWriteFile::WriteStringToFile(FString FilePath, FString String, bool& bOutSuccess, FString& OutInfoMessage)
{
	// Try to write the string into the file
	if (!FFileHelper::SaveStringToFile(String, *FilePath))
	{
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("Write String To File Failed - Was not able to write to file. Is your file read only? Is the path valid? - '%s'"), *FilePath);
		return;
	}

	bOutSuccess = true;
	OutInfoMessage = FString::Printf(TEXT("Write String To File Succeeded - '%s'"), *FilePath);
}
