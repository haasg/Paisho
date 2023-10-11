#include "FireBlast.h"

#include "Projectile.h"
#include "Paisho/Character/PaishoVillain.h"
#include "Paisho/Framework/PaishoGameState.h"
#include "Paisho/Data/WeaponData.h"
#include "Paisho/Util/DebugUtil.h"

void AFireBlast::Fire()
{
	if(const TObjectPtr<APaishoGameState> GameState = GetWorld()->GetGameState<APaishoGameState>())
	{
		const FVector MyLocation = GetActorLocation();
		const TObjectPtr<APaishoVillain> RandomVillain = GameState->GetRandomVillain();
		if(IsValid(RandomVillain))
		{
			const FVector RandomVillainLocation = RandomVillain->GetActorLocation();
			const FVector UnitVectorToRandomVillain = (RandomVillainLocation - MyLocation).GetSafeNormal();
			
			AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(AProjectile::StaticClass());
			Projectile->SetLocation(MyLocation);
			Projectile->SetSprite(WeaponData->GetProjectileSprite());
			Projectile->SetSpeed(WeaponData->GetProjectileSpeed());
			Projectile->SetDirection(UnitVectorToRandomVillain);
			const FRotator AngleToRandomVillain = UnitVectorToRandomVillain.Rotation();
			const FRotator SpriteRotation = FRotator(180, 180, 0);
			Projectile->SetRotation(AngleToRandomVillain + SpriteRotation);
		}
	} ELSE_ERROR("FireBlast::Fire with nullptr GameState")
}

