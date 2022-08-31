
/**
* @file Stanley.cpp
* @author Isabella Beth Engelman
 *
 * Stanley implementation file
*/

#include "pch.h"
#include "Stanley.h"

using namespace std;

/**
 * Stanley constructor
 * @param game Game we are tied to
 * @param image Image to use
 * @param bitmap Bitmap to use
 */
Stanley::Stanley(Game *game, std::shared_ptr<wxImage> image, std::shared_ptr<wxBitmap> bitmap): Item(game, image, bitmap)
{


}

/**
 * Collide function for money
 * @return returns true on first collide()
 */
bool Stanley::Collide()
{
    if(mCollided == false)
    {
        mCollided = true;

        mVelocity.SetY(-500);

        return true;
    }

    return false;
}

/**
 * Update function
 * @param elapsed The time since last call
 */
void Stanley::Update(double elapsed) {

    Vector newP = mP + mVelocity * elapsed;
    SetLocation(newP.X(), newP.Y());

    if(mP.Y() < -100)
    {
        mVelocity.SetY(0);
    }
}



