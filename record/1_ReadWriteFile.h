// Copyright Alex Quevillon. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h" // Engine
#include "1_ReadWriteFile.generated.h"


UCLASS()
class U_1_ReadWriteFile : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * Open a text file and read its content
	 *
	 * @param FilePath			The path of your file
	 * @param bOutSuccess		If the action was a success or not
	 * @param OutInfoMessage	More information about the action's result
	 * 
	 * @return The string content of your file
	 */
	UFUNCTION(BlueprintCallable, Category = "Alex Quevillon|1 - Read Write File")
		static FString ReadStringFromFile(FString FilePath, bool& bOutSuccess, FString& OutInfoMessage);

	/**
	 * Create a text file with your content
	 *
	 * @param FilePath			The path of your file
	 * @param String			The string to want to write in the file
	 * @param bOutSuccess		If the action was a success or not
	 * @param OutInfoMessage	More information about the action's result
	 */
	UFUNCTION(BlueprintCallable, Category = "Alex Quevillon|1 - Read Write File")
		static void WriteStringToFile(FString FilePath, FString String, bool& bOutSuccess, FString& OutInfoMessage);

};
