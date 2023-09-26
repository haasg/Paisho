#include "HealthBarWidget.h"

#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Paisho/Character/HealthComponent.h"
#include "Paisho/Util/DebugUtil.h"

void UHealthBarWidget::BindToHealthComponent(const TObjectPtr<UHealthComponent> NewHealthComponent)
{
	HealthComponent = NewHealthComponent;
	NewHealthComponent->OnHealthChanged.AddDynamic(this, &ThisClass::Refresh);
	Refresh();
}

void UHealthBarWidget::Refresh()
{
	if(HealthComponent.IsValid())
	{
		const float CurrentHealth = HealthComponent->GetCurrentHealth();
		const float MaxHealth = HealthComponent->GetMaxHealth();
		const float HealthPercent = HealthComponent->CalcHealthPercent();
		this->Update(CurrentHealth, MaxHealth, HealthPercent);
	}
	else
	{
		ERROR("HealthBarWidget refreshed without a valid HealthComponent!");
	}
}

void UHealthBarWidget::Update(const float CurrentHealth, const float MaxHealth, const float HealthPercent)
{
	const FText Text = FText::FromString(FString::Printf(TEXT("%d/%d"), FMath::RoundToInt(CurrentHealth), FMath::RoundToInt(MaxHealth)));
	HealthText->SetText(Text);
	HealthBar->SetPercent(HealthPercent);
}