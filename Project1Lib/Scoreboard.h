/**
 * @file Scoreboard.h
 * @author Isabella Beth Engelman
 *
 * Scoreboard header file
 */

#ifndef PROJECT1_SCOREBOARD_H
#define PROJECT1_SCOREBOARD_H

#include "Money.h"

/**
 * Scoreboard object
 */
class Scoreboard {



private:
    /// Amount of money collected
    int mMoney = 0;
    ///Minutes timer
    int mMinutes = 0;
    ///Seconds timer
    int mSeconds = 0;
    ///Milliseconds timer
    int mMilliseconds = 0;

    /// Stanley multiplier
    int mStan = 1;

    /// Stores the title message that is in the center of the screen
    wxString mTitleMessage = "";

    /// Stores the message under money to show what was picked up
    wxString mMoneyMessage = "";

    /// Counter so money message disappears after a bit
    int mMoneyMessageCounter;

    /// indicates the level we are on to change the placing of the text
    int mLevelIndicator = 0;

public:
    // Add money function
    void AddMoney(int money);
    // Timer function
    void Timer(double elapsed);

    /**
     * Resets the timer
     */
    void ResetTimer() {mMinutes = 0; mSeconds = 0; mMilliseconds = 0;}

    //Draw Function
    void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    /**
     * Sets the title text
     * @param title Text to set to
     */
    void SetTitle(wxString title){mTitleMessage = title;}

    /**
     * Increments mStan
     */
    void Stanley(){mStan += 1;}

    /**
     * Sets the money message
     * @param message Message to set
     */
    void SetMoneyMessage(wxString message){mMoneyMessage = message;}

    /**
     * Sets the mLevelIndicator
     * @param levelNum Number to set
     */
    void UpdateLevelIndicator(int levelNum) {mLevelIndicator = levelNum; }



};

#endif //PROJECT1_SCOREBOARD_H
