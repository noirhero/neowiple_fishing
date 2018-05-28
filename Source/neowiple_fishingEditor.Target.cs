// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class neowiple_fishingEditorTarget : TargetRules
{
	public neowiple_fishingEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "neowiple_fishing" } );
	}
}
