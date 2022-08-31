/**
 * @file WickedWolverine.cpp
 * @author Nandini Tengli
 *
 * WickedWolverine implementation file
 */

#include "pch.h"
#include "WickedWolverine.h"

using namespace std;


/**
 * WickedWolverine
 * @param game Game we are tied to
 * @param image Image to use for drawing
 * @param bitmap Bitmap to use for drawing
 */
WickedWolverine::WickedWolverine(Game *game, std::shared_ptr<wxImage> image, std::shared_ptr<wxBitmap> bitmap) : Enemy(game, image, bitmap)
{
    double BaseSpeedX = MaxSpeedY + MinSpeedX;
    double BaseSpeedY = MinSpeedY + MaxSpeedY;
    mVelocity.Set(BaseSpeedX ,  BaseSpeedY);
}
