#include "TabToolPanel.h"
#include "OizoEditor/oizoEditor.h"

void TabToolPanel::Construct(const FArguments& InArgs)
{
    tool = InArgs._Tool;
    if (tool.IsValid())
    {
        // do anything you need from tool object
    }
    auto commandList = TSharedPtr<FUICommandList>();
    FMenuBarBuilder n = FMenuBarBuilder(commandList);
    auto GameToolBarBuilder = MakeShareable(new FExtender);
    
    FMenuBuilder onTestDesTrucsFrer(true, NULL);
    for (size_t i = 0; i < 12; i++)
    {
        onTestDesTrucsFrer.AddWidget(SNew(SButton).Text(FText::FromString(FString::FromInt(i))),FText::GetEmpty());
    }
    auto banana = onTestDesTrucsFrer.MakeWidget();



    ChildSlot
        [
            SNew(SHorizontalBox)
            +SHorizontalBox::Slot().VAlign(VAlign_Fill).HAlign(HAlign_Right)
            [
                SNew(SBorder).BorderBackgroundColor(FColor(192, 0, 192, 255))
                [
                    SNew(SScrollBox) 
                    +SScrollBox::Slot().VAlign(VAlign_Top)
                    [
                        SNew(SVerticalBox)
                        + SVerticalBox::Slot().VAlign(VAlign_Top)
                        [
                            SNew(STextBlock).Text(FText::FromString(TEXT("Dialogue :")))
                        ]
                        + SVerticalBox::Slot().VAlign(VAlign_Top)
                        [
                            SNew(SBorder).BorderBackgroundColor(FColor(0,0,0,255))
                            [
                                SNew(SEditableTextBox)
                                .Text(FText::FromString(TEXT("Type dialogue here")))
                                .OnTextCommitted(this, &TabToolPanel::DebugLogWhatIJustWriten)
                                .BackgroundColor(FColor(255,255,255,255))
                                .ForegroundColor(FColor(0,0,0,255))
                            ]
                        ]
                        + SVerticalBox::Slot().VAlign(VAlign_Top)
                        [
                            SNew(SNumericEntryBox<int>)
                            .AllowSpin(true)
                            .MinValue(1)
                            .MaxValue(30)
                            .MinSliderValue(1)
                            .MaxSliderValue(30)
                        ]
                        + SVerticalBox::Slot().VAlign(VAlign_Top)
                        [
                            SNew(SOverlay)+
                            SOverlay::Slot()
                           .Padding(FMargin(10))
                            [
                                SNew(STextBlock).Text(FText::FromString("Coucou"))
                            ]
                            +SOverlay::Slot()
                                [
                                    banana
                                ]
                        ]
                        + SVerticalBox::Slot().VAlign(VAlign_Top)
                        [
                            SNew(SButton)
                            .Text(FText::FromString("Banana"))
                            ]
                        
                    ]

                ]
            ]
        ];
}

void TabToolPanel::DebugLogWhatIJustWriten(const FText& text, ETextCommit::Type type)
{
    if (type == ETextCommit::Type::OnEnter)
    {
        FString tempString = text.ToString();
        UE_LOG(LogClass, Log, TEXT("%s"),*tempString);
    }
}

TSharedRef<class SWidget> TabToolPanel::JaiRiencompris(FMenuBarBuilder& menuBuilder)
{
    menuBuilder.AddPullDownMenu(FText::FromString("Coucou"), FText::FromString("Opens Menu 1"), FNewMenuDelegate::CreateRaw(this,&TabToolPanel::FillMenu1Entries));
    return menuBuilder.MakeWidget();
}

void TabToolPanel::FillMenu1Entries(FMenuBuilder& MenuBuilder)
{
    MenuBuilder.BeginSection("ExampleSection", FText::FromString("Dialogue Editor"));
    MenuBuilder.AddMenuSeparator(FName("Section_1"));
    MenuBuilder.EndSection();
}

