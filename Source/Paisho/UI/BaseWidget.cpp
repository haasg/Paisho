#include "BaseWidget.h"

UBaseWidget::UBaseWidget()
{
}

TObjectPtr<UCommonActivatableWidgetStack> UBaseWidget::GetLayerWidget(const EWidgetLayer LayerName)
{
	switch(LayerName)
	{
		case EWidgetLayer::Game:
			return GameStack;
		case EWidgetLayer::GameMenu:
			return GameMenuStack;
		case EWidgetLayer::Menu:
			return MenuStack;
		case EWidgetLayer::Prompt:
			return PromptStack;
		default:
			return nullptr;
	}
}
