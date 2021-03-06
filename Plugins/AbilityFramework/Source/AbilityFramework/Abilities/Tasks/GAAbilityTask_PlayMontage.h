// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GAAbilityTask.h"
#include "GAGlobals.h"
#include "GAAbilityTask_PlayMontage.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FGASGenericMontageDelegate, FAFAbilityNotifyData, Data, FGameplayTag, Tag, FName, NotifyName);

/**
 *
 */
UCLASS()
class ABILITYFRAMEWORK_API UGAAbilityTask_PlayMontage : public UGAAbilityTask
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, meta = (ExposeOnSpawn = true))
		UAnimMontage* Montage;
	FName SectionName;
	float PlayRate;
	bool bUseActivationTime;

	UPROPERTY(BlueprintAssignable)
		FGASGenericMontageDelegate Played;
	UPROPERTY(BlueprintAssignable)
		FGASGenericMontageDelegate NotifyBegin;
	UPROPERTY(BlueprintAssignable)
		FGASGenericMontageDelegate NotifyTick;
	UPROPERTY(BlueprintAssignable)
		FGASGenericMontageDelegate NotifyEnd;

	UFUNCTION(BlueprintCallable, meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", BlueprintInternalUseOnly = "true"), Category = "AbilityFramework|Abilities|Tasks")
		static UGAAbilityTask_PlayMontage* AbilityPlayMontage(UObject* WorldContextObject,
			FName InTaskName, UAnimMontage* MontageIn, FName SectionNameIn, float PlayRateIn,
			bool bInUseActivationTime);

	virtual void Activate() override;

	void BroadcastStartNotifyState(const FAFAbilityNotifyData& DataIn, const FGameplayTag& InTag, const FName& InName);
	void BroadcastEndNotifyState(const FAFAbilityNotifyData& DataIn, const FGameplayTag& InTag, const FName& InName);
	void BroadcastTickNotifyState(const FAFAbilityNotifyData& DataIn, const FGameplayTag& InTag, const FName& InName);
};
