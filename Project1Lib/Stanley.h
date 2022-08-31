/**
 * @file Stanley.h
 * @author Isabella Beth Engelman
 *
 *  Stanley header file
 */

#ifndef PROJECT1_STANLEY_H
#define PROJECT1_STANLEY_H

#include "Item.h"

/**
 * Stanley object
 */
class Stanley: public Item  {
private:

    /// Vector for velocity of stanley
    Vector mVelocity;

    /// Bool if stanley has collided with Sparty
    bool mCollided = false;

public:

    /// Default constructor (deleted)
    Stanley() = delete;

    ///Copy constructor (disabled)
    Stanley(const Stanley &) = delete;

    ///Assignment operator (deleted)
    void operator = (const Stanley &) = delete;

    // Cosntructor
    Stanley(Game *game, std::shared_ptr<wxImage> image, std::shared_ptr<wxBitmap> bitmap);

    // Update function
    void Update(double elapsed) override;

    // Collide function
    bool Collide() override;

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     * @return int to return for specific collision action
     */
    int Accept(ItemVisitor* visitor) override {return visitor->VisitStanley(this);}

};


#endif //PROJECT1_STANLEY_H
