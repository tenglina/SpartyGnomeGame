/**
 * @file Scoreboard.cpp
 * @author Isabella Beth Engelman
 *
 * Scoreboard implementation file
 */

#include "pch.h"
#include "Scoreboard.h"
#include "Money.h"
#include <wx/graphics.h>
#include <string>

/**
 * Adds money to running count
 * @param money Money to add, multiplied by stanleys picked up
 */
void Scoreboard::AddMoney(int money)
{
    mMoney += money * mStan;
}

/**
 * Updates timer member variable
 * @param elapsed Time since last call
 */
void Scoreboard::Timer(double elapsed){
    //system call

    /*int hour = 0, min = 0, sec = 0;
    while(hour<1000000){
        sec++;
        if(sec==60){
            min++;
            sec=0;
            if(min==60){
                hour++;
                min=0;

            }
        }
    }*/
    ++mMilliseconds;
    if (mMilliseconds >= 20)
    {
        ++mSeconds;
        mMilliseconds = 0;
    }
    if (mSeconds >= 60)
    {
        ++mMinutes;
        mSeconds = 0;
    }
    // sleeps for one second
    // HAVE TO PRINT THIS OUTPUT ON SCREEN STILL
    // cout<<hour<<":"<<min<<":"<<sec;
    //sleep(1);
}

/**
 * Draw function
 * @param graphics Graphics to draw with
 */
void Scoreboard::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    //mGraphics = graphics;
    wxColour bkColor(*wxBLACK);
    wxColour textColor(wxColour(24,69,59));
    graphics->SetBrush(wxBrush(bkColor) );
    graphics->SetPen(wxPen(bkColor, 1, wxPENSTYLE_SOLID));
    wxFont font(wxSize(0, 50), wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    graphics->SetFont(font, textColor);
    //graphics->DrawText(std::to_string(mMinutes)+":"+std::to_string(mSeconds), 50, 0);
    //graphics->DrawText(std::to_string(mMoney), 1200, 0);

    //change colour and position of text depending on the level we are on
    if(mLevelIndicator == 0)
    {
        graphics->DrawText(mTitleMessage, 300, 400);
        if (mSeconds < 10)
        {
            graphics->DrawText(std::to_string(mMinutes)+":0"+std::to_string(mSeconds), 50, 0);
        }
        else
        {
            graphics->DrawText(std::to_string(mMinutes)+":"+std::to_string(mSeconds), 50, 0);
        }
        graphics->DrawText("$"+std::to_string(mMoney), 1200, 0);
    }
    else if(mLevelIndicator == 1)
    {
        graphics->DrawText(mTitleMessage, 300, 300);
        if (mSeconds < 10)
        {
            graphics->DrawText(std::to_string(mMinutes)+":0"+std::to_string(mSeconds), 50, 0);
        }
        else
        {
            graphics->DrawText(std::to_string(mMinutes)+":"+std::to_string(mSeconds), 50, 0);
        }
        graphics->DrawText("$"+std::to_string(mMoney), 1200, 0);
    }
    else if(mLevelIndicator == 2)
    {
        graphics->DrawText(mTitleMessage, 300, 350);
        if (mSeconds < 10)
        {
            graphics->DrawText(std::to_string(mMinutes)+":0"+std::to_string(mSeconds), 50, 0);
        }
        else
        {
            graphics->DrawText(std::to_string(mMinutes)+":"+std::to_string(mSeconds), 50, 0);
        }
        graphics->DrawText("$"+std::to_string(mMoney), 1200, 0);
    }
    else
    {
        wxColour textColourLevel3(*wxWHITE);
        graphics->SetFont(font, textColourLevel3);
        graphics->DrawText(mTitleMessage, 300, 400);
        if (mSeconds < 10)
        {
            graphics->DrawText(std::to_string(mMinutes)+":0"+std::to_string(mSeconds), 50, 0);
        }
        else
        {
            graphics->DrawText(std::to_string(mMinutes)+":"+std::to_string(mSeconds), 50, 0);
        }
        graphics->DrawText("$"+std::to_string(mMoney), 1200, 0);
    }
    graphics->DrawText(mMoneyMessage, 1150, 50);
    //Money Message
    if(mMoneyMessage != "")
    {
        mMoneyMessageCounter += 1;
        if(mMoneyMessageCounter == 20)
        {
            mMoneyMessageCounter = 0;
            mMoneyMessage = "";
        }
    }
}