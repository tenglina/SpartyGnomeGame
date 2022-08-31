/**
 * @file Money.h
 * @author Isabella Beth Engelman
 *
 * Money header file
 */

#ifndef PROJECT1_MONEY_H
#define PROJECT1_MONEY_H

#include "Item.h"
#include "Vector.h"

/**
 * Money class
 */
class Money: public Item {
private:

    /// Value for this money item
    int mValue = 0;

    /// Velocity vector for this money
    Vector mVelocity;

    /// Whether or not we have collided with Sparty yet
    bool mCollided = false;

public:

    /// Default constructor (disabled)
    Money() = delete;

    /// Copy constructor (disabled)
    Money(const Money &) = delete;

    /// Assignment operator
    void operator=(const Money &) = delete;

    // Constructor
    Money(Game* game, std::shared_ptr<wxImage> image, std::shared_ptr<wxBitmap> bitmap, int value);

    // XmlSave
    wxXmlNode* XmlSave(wxXmlNode* node) override;


    // Update function
    void Update(double elapsed) override;

    // Collide function
    bool Collide() override;

    /**
     * Value getter
     * @return the value of the money object
     */
    int GetValue() const {return mValue;}

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     * @return int to return for what collision action we need
     */
    int Accept(ItemVisitor* visitor) override {return GetValue();}

};

#endif //PROJECT1_MONEY_H
