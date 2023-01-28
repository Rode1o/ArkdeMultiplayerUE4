// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "MultiPlayer/MultiPlayer.h"
#include "AM_GameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYER_API UAM_GameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAM_GameplayAbility();

	// Ability Input ID Start
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Gameplay Ability")
	EAM_AbilityInputID AbilityInputID;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Gameplay Ability")
	EAM_AbilityInputID AbilityID;
	// Ability Input ID End
	
	
};
