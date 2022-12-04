#pragma once

#include "CoreMinimal.h"
#include "DialogueAsset.h"
#include "StructsForLocalization.h"
#include "EditorStyleSet.h"

#include "Widget.h"
#include "Widgets/SLeafWidget.h"

DECLARE_DELEGATE_OneParam(FOnMeanChanged, float /*NewMean*/)
DECLARE_DELEGATE_OneParam(FOnStandardDeviationChanged, float /*NewStandardDeviation*/)

class SDialogueAssetWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SDialogueAssetWidget): _DialogueName(""),_DialogueContent(FStringTableForSentence())
	{}
		SLATE_ATTRIBUTE(FString, DialogueName)
		SLATE_ATTRIBUTE(FStringTableForSentence, DialogueContent)
		SLATE_END_ARGS()
public :

	void Construct(const FArguments& InArgs);

	int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;
	FVector2D ComputeDesiredSize(float) const override;

	FReply OnMouseButtonDown(const FGeometry& AllottedGeometry, const FPointerEvent& MouseEvent) override;
	FReply OnMouseButtonUp(const FGeometry& AllottedGeometry, const FPointerEvent& MouseEvent) override;
	FReply OnMouseMove(const FGeometry& AllottedGeometry, const FPointerEvent& MouseEvent) override;
private:
	TAttribute<float> Mean;
	TAttribute<FString> DialogueName;
	TAttribute<FStringTableForSentence> DialogueContent;

	FTransform2D GetPointsTransform(const FGeometry& AllottedGeometry) const;
};
