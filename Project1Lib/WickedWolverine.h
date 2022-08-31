/**
 * @file WickedWolverine.h
 * @author Nandini Tengli
 *
 * WickedWolverine header file
 */

#ifndef PROJECT1_WICKEDWOLVERINE_H
#define PROJECT1_WICKEDWOLVERINE_H

#include "Enemy.h"

/**
 *
 * Class that describes Enemy of type Wickedwolverine
 */
class WickedWolverine : public Enemy {
private:
    /// declaring the min speed for x
    const double MinSpeedX = 2;

    /// declaring the max speed for x
    const double MaxSpeedX = 20;

    ///declaring the min speed for y
    const double MinSpeedY = 14;

    ///declaring the max speed for y
    const double MaxSpeedY = 45;

public:

    ///Disable Default constructor
    WickedWolverine() = delete;

    ///Disable Copy constructor
    WickedWolverine(const WickedWolverine &) = delete;

    ///Disable default Assignment operator
    void operator=(const WickedWolverine &) = delete;

    //constructor
    WickedWolverine(Game * game, std::shared_ptr<wxImage> image, std::shared_ptr<wxBitmap> bitmap);

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     * @return int that signifies which collision action to use
     */
    int Accept(ItemVisitor* visitor) override {return visitor->VisitWickedWolverine(this);}


};

#endif //PROJECT1_WICKEDWOLVERINE_H
