/**
 * @file WisconsonCat.h
 * @author Nandini Tengli
 *
 * WisconsonCat header file
 */

#ifndef PROJECT1_WISCONSONCAT_H
#define PROJECT1_WISCONSONCAT_H

#include "Enemy.h"

/**
 * WisconsonCat Object
 */
class WisconsonCat : public Enemy{
private:


public:
    ///Disable Default constructor
    WisconsonCat() = delete;

    ///Disable Copy constructor
    WisconsonCat(const WisconsonCat &) = delete;

    ///Disable default Assignment operator
    void operator=(const WisconsonCat &) = delete;

    // Constructor
    WisconsonCat(Game * game, std::shared_ptr<wxImage> image, std::shared_ptr<wxBitmap> bitmap);

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     * @return int that signifies which collision action to use
     */
    int Accept(ItemVisitor* visitor) override {return visitor->VisitWisconsonCat(this);}



};

#endif //PROJECT1_WISCONSONCAT_H
