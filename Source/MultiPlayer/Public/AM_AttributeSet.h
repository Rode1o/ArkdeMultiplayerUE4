// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AM_AttributeSet.generated.h"


 #define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class MULTIPLAYER_API UAM_AttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public : 
	UAM_AttributeSet();

		// Control de recursos para limitar recursos en runtime
		virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	// revision de valores de efectos luego de su ejecucion
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
	void AdjustAttributeForMaxChange(
		FGameplayAttributeData& AffectedAttribute,
		const FGameplayAttributeData& MaxAttribute,
		float NewMaxValue,
		const FGameplayAttribute& AffectedAttributeProperty
	);

	// Atributos

	UPROPERTY(BlueprintReadOnly, Category = "Health")
		FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UAM_AttributeSet, Health);


	UPROPERTY(BlueprintReadOnly, Category = "Health")
		FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UAM_AttributeSet, MaxHealth);


	UPROPERTY(BlueprintReadOnly, Category = "Health")
		FGameplayAttributeData HealthRegen;
	ATTRIBUTE_ACCESSORS(UAM_AttributeSet, HealthRegen);



	UPROPERTY(BlueprintReadOnly, Category = "Mana")
		FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UAM_AttributeSet, Mana);


	UPROPERTY(BlueprintReadOnly, Category = "Mana")
		FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UAM_AttributeSet, MaxMana);


	UPROPERTY(BlueprintReadOnly, Category = "Mana")
		FGameplayAttributeData ManaRegen;
	ATTRIBUTE_ACCESSORS(UAM_AttributeSet, ManaRegen);


	UPROPERTY(BlueprintReadOnly, Category = "Stamina")
		FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UAM_AttributeSet, Stamina);


	UPROPERTY(BlueprintReadOnly, Category = "Stamina")
		FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UAM_AttributeSet, MaxStamina);


	UPROPERTY(BlueprintReadOnly, Category = "Stamina")
		FGameplayAttributeData StaminaRegen;
	ATTRIBUTE_ACCESSORS(UAM_AttributeSet, StaminaRegen);
};
