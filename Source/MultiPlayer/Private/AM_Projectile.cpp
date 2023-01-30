// Fill out your copyright notice in the Description page of Project Settings.


#include "AM_Projectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"


// Sets default values
AAM_Projectile::AAM_Projectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	RootComponent = SphereComponent;
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	FireBallEffect = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Fire Effect"));
	FireBallEffect->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AAM_Projectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAM_Projectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

