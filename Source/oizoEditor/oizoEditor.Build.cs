// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class oizoEditor : ModuleRules
{
	public oizoEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new 
			string[] 
			{ 
				"Core", 
				"CoreUObject", 
				"Engine", 
				"InputCore", 
				"AssetRegistry",
				"LevelEditor",
				"Slate",
				"EditorStyle",
				"AssetTools",
				"EditorWidgets",
				"UnrealEd",
				"BlueprintGraph",
				"AnimGraph",
				"ComponentVisualizers",
				"oizo"
			});

		PrivateDependencyModuleNames.AddRange(
			new string[] 
			{ 
				"Core",
				"CoreUObject",
				"Engine",
				"AppFramework",
				"Slate",
				"SlateCore",
				"AnimGraph",
				"UnrealEd",
				"Blutility",
				"KismetWidgets",
				"Mainframe",
				"PropertyEditor",
				"ComponentVisualizers",
				"UMG",
				"UMGEditor",
				"AssetRegistry",
				"oizo"
	        });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}