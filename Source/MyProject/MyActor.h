// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class MYPROJECT_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage")
	int32 TotalDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	float DamageTimeInSeconds;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "Damage")//transient means that it is a non-persistent value, it is meant to change
	float DamagePerSecond;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void PostInitProperties();

	UFUNCTION(BlueprintCallable, Category = "Damage")
	void CalculateValues();

	void PostEditChangeProperty(FPropertyChangedEvent & PropertyChangedEvent);
};
