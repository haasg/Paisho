#include "WaterBlast.h"

#include "Projectile.h"
#include "Paisho/Character/PaishoVillain.h"
#include "Paisho/Data/WeaponData.h"
#include "Paisho/Framework/PaishoGameState.h"
#include "Paisho/Util/DebugUtil.h"

void AWaterBlast::Fire()
{
	if(const TObjectPtr<APaishoGameState> GameState = GetWorld()->GetGameState<APaishoGameState>())
	{
		const FVector MyLocation = GetActorLocation();
		const TWeakObjectPtr<APaishoVillain> ClosestVillain = GameState->GetClosestVillainTo(MyLocation);
		if(ClosestVillain.IsValid())
		{
			// AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(AProjectile::StaticClass());
			// Projectile->SetLocation(MyLocation);
			// Projectile->SetSprite(WeaponData->GetProjectileSprite());
			//
			// Projectile->SetSpeed(WeaponData->GetProjectileSpeed());
			// const FVector ClosestVillainLocation = ClosestVillain->GetActorLocation();
			// const FVector UnitVectorToClosestVillain = (ClosestVillainLocation - MyLocation).GetSafeNormal();
			// Projectile->SetDirection(UnitVectorToClosestVillain);
			// const FRotator AngleToClosestVillain = UnitVectorToClosestVillain.Rotation();
			// const FRotator SpriteRotation = FRotator(0, 180, 0);
			// Projectile->SetRotation(AngleToClosestVillain + SpriteRotation);
		}
	} ELSE_ERROR("WaterBlast::Fire with nullptr GameState")
	
}
