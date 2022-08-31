/**
 * @file GameView.h
 * @author Tim Moran
 *
 * View class for the game
 */

#ifndef PROJECT1_GAMEVIEW_H
#define PROJECT1_GAMEVIEW_H

#include "Game.h"
#include "PlayingArea.h"
#include "Scoreboard.h"

/**
 * View class for the game
 **
 * Holds a game object, and also whatever item is being
 * held by the mouse (For level development purposes). Also contains
 * events for adding items, and mouse and keyboard events
 */
class GameView: public wxWindow {
private:
    /// The game we are building
    Game mGame;

    /// Scoreboard object
    Scoreboard mScoreBoard;

    /// The last stopwatch time
    double mTime;

    /// Level object
    Level mLevel = Level(&mGame, &mScoreBoard);

    /// Any item we are currently dragging
    std::shared_ptr<Item> mGrabbedItem;

    PlayingArea mPlayingArea;   ///<Playing Area object

    /// The timer that allows for animation
    wxTimer mTimer;

    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;

    ///Graphics context used for drawing
    std::shared_ptr<wxGraphicsContext> mGraphics;

    /// Whether or not we need to redraw the Game View
    bool mRedraw = false;





    /// Timer event
    void TimerEvent(wxTimerEvent& event);

    /// OnPaint event
    void OnPaintGameView(wxPaintEvent &event);



    /// Level 0 load event
    void OnLevel0(wxCommandEvent &event);

    /// Level 1 load event
    void OnLevel1(wxCommandEvent &event);

    /// Level 2 load event
    void OnLevel2(wxCommandEvent &event);

    /// Level 3 load event
    void OnLevel3(wxCommandEvent &event);

    /// Keyboard down event
    void OnKeyDown(wxKeyEvent& event);

    /// Keyboard up event moving this to playing area as listed on course website
    void OnKeyUp(wxKeyEvent& event);

public:

    /// Initialize
    void Initialize(wxFrame *parent);

    /**
     * Stop the time rso the window can close
     */
    void Stop() {mTimer.Stop();}

    /**
     * Set Graphics function
     * @param graphics Graphics Context to set
     */
    void SetGraphics(std::shared_ptr<wxGraphicsContext> graphics) {mGraphics = graphics;}

    /**
     * Set Redraw function
     * @param redraw Redraw bool to set
     */
    void SetRedraw(bool redraw) {mRedraw = redraw;}

};

#endif //PROJECT1_GAMEVIEW_H
