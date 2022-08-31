/**
 * @file Enemy.h
 * @author Nandini Tengli
 *
 *
 */

#ifndef PROJECT1_ENEMY_H
#define PROJECT1_ENEMY_H

#include "Item.h"
#include "Game.h"

/**
 * Class describing items of type enemy
 */
class Enemy : public Item{

protected:
    /// Velocity vector
    Vector mVelocity;

    ///member variable top turn around point
    double mTopY;

    ///Member variable bottom turn around point
    double mBottomY;

    ///Member variable Positive Velocity
    double mVelocityPos;

    ///Member variable Negative Velocity
    double mVelocityNeg;

    /// Whether or not we have collided yet with Sparty
    bool mCollided = false;

public:

    ///constructor
    Enemy(Game * game, std::shared_ptr<wxImage> image, std::shared_ptr<wxBitmap> bitmap);

    ///disable default constructor
    Enemy() = delete;

    ///disable copy constructor
    Enemy(const Enemy &) = delete;

    ///Assignment operator
    void operator=(const Enemy &) = delete;

    void Update(double elapsed) override;

    bool Collide() override;

    void SetLocation(double x, double y) override;

    /// use this set location update will use
    void SetLocationMovement(double x, double y);


};

#endif //PROJECT1_ENEMY_H
