﻿#include "WaterBasic.h"

#include "Projectile.h"
#include "Paisho/Character/PaishoVillain.h"
#include "Paisho/Framework/PaishoGameState.h"
#include "Paisho/Data/WeaponData.h"
#include "Paisho/Util/DebugUtil.h"

void AWaterBasic::Fire()
{
	if(const TObjectPtr<APaishoGameState> GameState = GetWorld()->GetGameState<APaishoGameState>())
	{
		const FVector MyLocation = GetActorLocation();
		const TObjectPtr<APaishoVillain> ClosestVillain = GameState->GetClosestVillainTo(MyLocation);
		if(IsValid(ClosestVillain))
		{
			AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(AProjectile::StaticClass());
			Projectile->SetWeaponData(WeaponData);
			Projectile->SetLocation(MyLocation);
			Projectile->SetSpeed(WeaponData->GetProjectileSpeed());
			
			const FVector VillainLocation = ClosestVillain->GetActorLocation();
			const FVector UnitVectorToVillain = (VillainLocation - MyLocation).GetSafeNormal();
			Projectile->SetDirection(UnitVectorToVillain);
			
			const FRotator AngleToVillain = UnitVectorToVillain.Rotation();
			const FRotator SpriteRotation = FRotator(180, 180, 0);
			const FRotator ProjectileRotation = AngleToVillain + SpriteRotation;
			Projectile->SetRotation(ProjectileRotation);
			
			
		}
	} ELSE_ERROR("FireBlast::Fire with nullptr GameState")
}

