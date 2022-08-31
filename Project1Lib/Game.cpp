/**
 * @file Game.cpp
 * @author Elia Spyratos
 *
 * Implementation for game class
 */

#include "pch.h"
#include "Game.h"
#include <memory>
#include <wx/graphics.h>

using namespace std;

#ifdef WIN32
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#endif

/// Initial item X location
const int InitialX = 200;

/// Initial item Y location
const int InitialY = 200;

/**
* Game Constructor
*/
Game::Game()
{
    mBackground = make_unique<wxBitmap>(
            L"images/background.png", wxBITMAP_TYPE_ANY);

    // Seed the random number generator
    std::random_device rd;
    mRandom.seed(rd());

}

/**
 * Draw the game area
 * @param graphics The wxWidgets graphics context on which to draw
 * @param width Width of the client window
 * @param height Height of the client window
 */
void Game::OnDraw(shared_ptr<wxGraphicsContext> graphics, int width, int height)
{

    //
    // Automatic Scaling
    //
    mScale = double(height) / double(mHeight);
    graphics->Scale(mScale, mScale);

    auto virtualWidth = (double)width/mScale;
    graphics->PushState();

    //
    // Draw in virtual pixels on the graphics context
    //
    // INSERT DRAWING CODE HERE


    graphics->PopState();
}














