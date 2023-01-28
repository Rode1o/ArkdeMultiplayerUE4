// Fill out your copyright notice in the Description page of Project Settings.


#include "AM_AttributeSet.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"

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
	// si se va a modificar un attribute 
	Super::PreAttributeChange(Attribute, NewValue);

	if(Attribute == GetMaxHealthAttribute())
	{
		AdjustAttributeForMaxChange(Health, MaxHealth, NewValue, GetHealthAttribute());
		
	}
	else if (Attribute == GetMaxManaAttribute())
	{
		AdjustAttributeForMaxChange(Mana, MaxMana, NewValue, GetManaAttribute());
		
	}
	else if (Attribute == GetMaxStaminaAttribute())
	{
		AdjustAttributeForMaxChange(Stamina, MaxStamina, NewValue, GetStaminaAttribute());
	}


}
// ------------------------------------------------------------------------------------------------------------------------------
void UAM_AttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	/// asegurar si un cambio realmente afecta a ese atributo, y no debe pasar el limite establecido
	/// 
	if (Data.EvaluatedData.Attribute.GetUProperty() ==
		FindFieldChecked<FProperty>(UAM_AttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UAM_AttributeSet, Health)))
	{
		Health.SetCurrentValue(FMath::Clamp(Health.GetCurrentValue(), 0.f,MaxHealth.GetCurrentValue()));
		Health.SetBaseValue(FMath::Clamp(Health.GetBaseValue(), 0.f,MaxHealth.GetCurrentValue()));
	}
	else if (Data.EvaluatedData.Attribute.GetUProperty() ==
		FindFieldChecked<FProperty>(UAM_AttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UAM_AttributeSet, Mana)))
	{
		Mana.SetCurrentValue(FMath::Clamp(Mana.GetCurrentValue(), 0.f,MaxMana.GetCurrentValue()));
		Mana.SetBaseValue(FMath::Clamp(Mana.GetBaseValue(), 0.f,MaxMana.GetCurrentValue()));
	}
	else if (Data.EvaluatedData.Attribute.GetUProperty() ==
		FindFieldChecked<FProperty>(UAM_AttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UAM_AttributeSet, Stamina)))
	{
		Stamina.SetCurrentValue(FMath::Clamp(Stamina.GetCurrentValue(), 0.f,MaxStamina.GetCurrentValue()));
		Stamina.SetBaseValue(FMath::Clamp(Stamina.GetBaseValue(), 0.f,MaxStamina.GetCurrentValue()));
	}






	
}
// ------------------------------------------------------------------------------------------------------------------------------

void UAM_AttributeSet::AdjustAttributeForMaxChange(FGameplayAttributeData& AffectedAttribute, const FGameplayAttributeData& MaxAttribute, float NewMaxValue, const FGameplayAttribute& AffectedAttributeProperty)
{

	UAbilitySystemComponent* AbilityComponent = GetOwningAbilitySystemComponent();
	const float CurrentMaxValue = MaxAttribute.GetCurrentValue();
	if (!FMath::IsNearlyEqual(CurrentMaxValue, NewMaxValue) && IsValid(AbilityComponent))
	{
		const float CurrentValue = AffectedAttribute.GetCurrentValue();
		float NewDelta = CurrentMaxValue > 0 ? (CurrentValue * NewMaxValue / CurrentMaxValue) - CurrentValue : NewMaxValue;
		AbilityComponent->ApplyModToAttributeUnsafe(AffectedAttributeProperty, EGameplayModOp::Additive, NewDelta );
	}


	
	
}
