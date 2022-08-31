/**
 * @file Enemy.cpp
 * @author Nandini Tengli
 *
 * Enemy implementation file
 */

#include "pch.h"
#include "Enemy.h"


using namespace std;

/**
 * Constructor
 * @param game the game this enemy is part of
 * @param image Image this item will use
 * @param bitmap Bitmap this item will use
 */

Enemy::Enemy(Game *game, std::shared_ptr<wxImage> image, std::shared_ptr<wxBitmap> bitmap) : Item(game, image, bitmap)
{
    mTopY = mP.Y() - 100;
    mBottomY = mP.Y() + 100;
    mVelocity.SetY(50);
    mVelocity.SetX(0);
    mVelocityPos = 100;
    mVelocityNeg = -100;
}

/**
 * Update function
 * @param elapsed Time since last update
 */
void Enemy::Update(double elapsed){
    Vector newP = mP + mVelocity * elapsed;
    SetLocationMovement(mP.X(),newP.Y());
    if(mP.Y() < mTopY){
        mVelocity.SetY(mVelocityPos);
    }
    if(mP.Y() > mBottomY){
        mVelocity.SetY(mVelocityNeg);
    }
}

/**
 * Set Location function, and sets top and bottom for
 * turning around
 * @param x,y The new coordinates
 */
void Enemy::SetLocation(double x, double y){
    mP.SetX(x); mP.SetY(y);
    mTopY = mP.Y() - 300; mBottomY = mP.Y() + 5;


}

/**
 * SetlocationMovement function, sets
 * location without changing top and bottom points
 * to turn around
 * @param x,y The new coordinates
 */
void Enemy::SetLocationMovement(double x, double y){
    mP.SetX(x); mP.SetY(y);
}

/**
 * Collide function for enemies
 * @return returns true when collided for the first time
 */
 bool Enemy::Collide()
 {
     if(mCollided == false)
     {
         mCollided = true;
         return true;
     }
     return false;
 }


