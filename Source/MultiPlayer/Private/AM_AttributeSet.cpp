// Fill out your copyright notice in the Description page of Project Settings.


#include "AM_AttributeSet.h"

UAM_AttributeSet::UAM_AttributeSet()
{
	MaxHealth = 100.f;
	Health = MaxHealth;
	HealthRegen = 0.5f;

	MaxMana = 100.f;
	Mana = MaxHealth;
	ManaRegen = 2.f;

	MaxStamina = 100.f;
	Stamina = MaxHealth;
	StaminaRegen = 1.f;

}
// ------------------------------------------------------------------------------------------------------------------------------
void UAM_AttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);


}
// ------------------------------------------------------------------------------------------------------------------------------
void UAM_AttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
}
// ------------------------------------------------------------------------------------------------------------------------------

void UAM_AttributeSet::AdjustAttributeForMaxChange(FGameplayAttributeData& AffectedAttribute, const FGameplayAttributeData& MaxAttribute, float NewMaxValue, const FGameplayAttribute& AffectedAttributeProperty)
{
}
