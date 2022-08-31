/**
 * @file GameView.cpp
 * @author Tim Moran
 *
 * GameView implementation file
 */

#include "pch.h"
#include "GameView.h"
#include <wx/dcbuffer.h>
#include "ids.h"
#include "Platform.h"
#include "WickedWolverine.h"
#include "Stanley.h"
#include "WormHole.h"
#include "Money.h"
#include "Enemy.h"
#include <filesystem>

using namespace std;

/// Frame duration in milliseconds
const int FrameDuration = 30;

/**
 * Initializes the game view
 * @param parent wxFrame parent
 */
void GameView::Initialize(wxFrame *parent)
{
    Create(parent, wxID_ANY);
    SetBackgroundStyle(wxBG_STYLE_PAINT);
    //SetBackgroundColour(*wxWHITE);
    Bind(wxEVT_PAINT, &GameView::OnPaintGameView, this);

    Bind(wxEVT_KEY_DOWN, &GameView::OnKeyDown, this);
    Bind(wxEVT_KEY_UP, &GameView::OnKeyUp, this);

    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLevel0, this, IDM_LEVEL0);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLevel1, this, IDM_LEVEL1);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLevel2, this, IDM_LEVEL2);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLevel3, this, IDM_LEVEL3);

    mLevel.NextLevel();
    mTimer.SetOwner(this);
    mTimer.Start(FrameDuration);

    Bind(wxEVT_TIMER, &GameView::TimerEvent, this);

    mStopWatch.Start();



}

/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void GameView::OnPaintGameView(wxPaintEvent& event)
{
    wxAutoBufferedPaintDC dc(this);
    wxBrush background(*wxBLACK);
    dc.SetBackground(background);
    dc.Clear();

    auto size = GetClientSize();
    auto graphics = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create(dc));
    mGame.OnDraw(graphics, size.GetWidth(), size.GetHeight());
    this->SetGraphics(graphics);


    // Compute the time that has elapsed
    // since the last call to OnPaint.
    auto newTime = mStopWatch.Time();
    auto elapsed = (double)(newTime - mTime) * 0.001;
    mTime = newTime;
    mScoreBoard.Timer(elapsed);

    mLevel.Update(elapsed);
    auto xOffset = (double)-mLevel.GetSparty()->GetX() +mGame.GetWidth() / 2.0f;
    if(mRedraw == false)
    {
        mLevel.AddItemsToGame(graphics);
        this->SetRedraw(true);
    }
    else
    {
        mLevel.Draw(graphics, xOffset);
    }

    mPlayingArea.SetSparty(mLevel.GetSparty());
    mScoreBoard.Draw(graphics);
}

/**
 * Timer handler
 * @param event Timer event
 */
void GameView::TimerEvent(wxTimerEvent& event)
{

    Refresh();
}

/**
 * Level 0 load event
 * @param event Command event
 */
 void GameView::OnLevel0(wxCommandEvent& event)
{
    filesystem::path p = filesystem::current_path();
    p = p.parent_path();
    p += L"/xml/level0.xml";

    mLevel.SetLevelWeAreOn(0);
    mScoreBoard.ResetTimer();
    mScoreBoard.SetTitle(L"Level 0: Press Space to Begin");
    mLevel.Load(p.string());
    mPlayingArea.SetSparty(mLevel.GetSparty());
    Refresh();
 }

/**
* Level 1 load event
* @param event Command event
*/
void GameView::OnLevel1(wxCommandEvent& event)
{
    filesystem::path p = filesystem::current_path();
    p = p.parent_path();
    p += L"/xml/level1.xml";

    mLevel.SetLevelWeAreOn(1);
    mScoreBoard.ResetTimer();
    mScoreBoard.SetTitle(L"Level 1: Press Space to Begin");
    mLevel.Load(p.string());
    mPlayingArea.SetSparty(mLevel.GetSparty());
    Refresh();
}

/**
 * Level 2 load event
 * @param event Command event
 */
void GameView::OnLevel2(wxCommandEvent& event)
{
    filesystem::path p = filesystem::current_path();
    p = p.parent_path();
    p += L"/xml/level2.xml";

    mLevel.SetLevelWeAreOn(2);
    mScoreBoard.ResetTimer();
    mScoreBoard.SetTitle(L"Level 2: Press Space to Begin");
    mLevel.Load(p.string());
    mPlayingArea.SetSparty(mLevel.GetSparty());
    Refresh();
}

/**
 * Level 3 load event
 * @param event Command event
 */
void GameView::OnLevel3(wxCommandEvent& event)
{
    filesystem::path p = filesystem::current_path();
    p = p.parent_path();
    p += L"/xml/level3.xml";

    mLevel.SetLevelWeAreOn(3);
    mScoreBoard.ResetTimer();
    mScoreBoard.SetTitle(L"Level 3: Press Space to Begin");
    mLevel.Load(p.string());
    mPlayingArea.SetSparty(mLevel.GetSparty());
    Refresh();
}

/**
 * Keyboard down handler
 * @param event Keydown event
 */
 void GameView::OnKeyDown(wxKeyEvent& event)
{
     mPlayingArea.OnKeyDown(event);
}

/**
 * Keyboard up handler
 * @param event Keydown event
 */
void GameView::OnKeyUp(wxKeyEvent& event)
{
    mPlayingArea.OnKeyUp(event);
}
