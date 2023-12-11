#include "Widgets/Docking/SDockTab.h"
//#include "Widgets/Docking/SDockTabStack.h"
#include "SlateApplication.h"
#include "TabTool.h"

class TabToolPanel : public SCompoundWidget
{
    SLATE_BEGIN_ARGS(TabToolPanel)
    {}
    SLATE_ARGUMENT(TWeakPtr<class TabTool>, Tool)
        SLATE_END_ARGS()

        void Construct(const FArguments& InArgs);

protected:
    TWeakPtr<TabTool> tool;

private:
    void DebugLogWhatIJustWriten(const FText& text, ETextCommit::Type type);
    TSharedRef<class SWidget> JaiRiencompris(FMenuBarBuilder& menuBuilder);
    void FillMenu1Entries(FMenuBuilder& MenuBuilder);
    void CreateGraphEditorWidget(UEdGraph* InGraph);
};