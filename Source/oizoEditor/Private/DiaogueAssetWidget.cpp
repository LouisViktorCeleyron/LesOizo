/*
#include "DiaogueAssetWidget.h"
#include "Editor.h"
#include "Editor/EditorEngine.h"
/*
void SDialogueAssetWidget::Construct(const FArguments& InArgs)
{
    DialogueContent = InArgs._DialogueContent;
    DialogueName = InArgs._DialogueName;
}

int32 SDialogueAssetWidget::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
    const int32 NumPoints = 512;
    TArray<FVector2D> Points;
    Points.Reserve(NumPoints);
    const FTransform2D PointsTransform = GetPointsTransform(AllottedGeometry);
    for (int32 PointIndex = 0; PointIndex < NumPoints; ++PointIndex)
    {
        const float X = PointIndex / (NumPoints - 1.0);
        Points.Add(PointsTransform.TransformPoint(FVector2D(X, 10)));
    }
    FSlateFontInfo FontStyle = FEditorStyle::GetFontStyle(TEXT("SourceControl.LoginWindow.Font"));
    auto brush = FEditorStyle::GetBrush("Sequencer.Section.StripeOverlay");
    //FSlateDrawElement::MakeBox(OutDrawElements, LayerId, AllottedGeometry.ToPaintGeometry(), brush);
    FSlateDrawElement::MakeText(OutDrawElements, LayerId, AllottedGeometry.ToPaintGeometry(),FText::FromString(DialogueName.Get()), FontStyle);
    //FSlateDrawElement::MakeLines(OutDrawElements, LayerId, AllottedGeometry.ToPaintGeometry(), Points);
    return LayerId;
}

FVector2D SDialogueAssetWidget::ComputeDesiredSize(float) const
{
    return FVector2D(200.0, 200.0);
}

FReply SDialogueAssetWidget::OnMouseButtonDown(const FGeometry& AllottedGeometry, const FPointerEvent& MouseEvent)
{
   /* if (GEditor && GEditor->CanTransact() && ensure(!GIsTransacting))
        GEditor->BeginTransaction(TEXT(""), INVTEXT("Edit Normal Distribution"), nullptr);
    return FReply::Handled().CaptureMouse(SharedThis(this));
}

FReply SDialogueAssetWidget::OnMouseButtonUp(const FGeometry& AllottedGeometry, const FPointerEvent& MouseEvent)
{
    if (GEditor) GEditor->EndTransaction();
    return FReply::Handled().ReleaseMouseCapture();
}

FReply SDialogueAssetWidget::OnMouseMove(const FGeometry& AllottedGeometry, const FPointerEvent& MouseEvent)
{
    if (!HasMouseCapture()) return FReply::Unhandled();
    const FTransform2D PointsTransform = GetPointsTransform(AllottedGeometry);
    const FVector2D LocalPosition = AllottedGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition());
    const FVector2D NormalizedPosition = PointsTransform.Inverse().TransformPoint(LocalPosition);
   
    return FReply::Handled();
}

FTransform2D SDialogueAssetWidget::GetPointsTransform(const FGeometry& AllottedGeometry) const
{
    const double Margin = 0.05 * AllottedGeometry.GetLocalSize().GetMin();
    const FScale2D Scale((AllottedGeometry.GetLocalSize() - 2.0 * Margin) * FVector2D(1.0, -1.0));
    const FVector2D Translation(Margin, AllottedGeometry.GetLocalSize().Y - Margin);

    
    return FTransform2D(Scale, Translation);
}
*/