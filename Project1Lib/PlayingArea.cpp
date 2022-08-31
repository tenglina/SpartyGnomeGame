/**
 * @file PlayingArea.cpp
 * @author Isabella Beth Engelman
 *
 * PlayingArea implementation file
 */

#include "pch.h"
#include "PlayingArea.h"
#include <vector>

using namespace std;

/**
 * On Key Down event
 * @param event Key Event
 */
void PlayingArea::OnKeyDown(wxKeyEvent &event)
{

    switch (event.GetKeyCode())
    {
    case WXK_RIGHT:
        // right arrow pressed
        mSparty->MoveRight();
        mSparty->AnimateRight();
        break;

    case WXK_LEFT:
        // left arrow pressed
        mSparty->MoveLeft();
        mSparty->AnimateLeft();
        break;

    case WXK_SPACE:
        // space bar pressed
        mSparty->Jump();
        mSparty->AnimateJump();
        break;

    }

}

/**
 * On Key Up function
 * @param event Key Event
 */
void PlayingArea::OnKeyUp(wxKeyEvent &event)
{
    switch (event.GetKeyCode())
    {
    case WXK_RIGHT:
        // right arrow pressed
        mSparty->StopXMovement();
        mSparty->AnimateJump();
        break;

    case WXK_LEFT:
        // left arrow pressed
        mSparty->StopXMovement();
        mSparty->AnimateJump();
        break;

    case WXK_SPACE:
        // space bar pressed
        break;

    }
}
