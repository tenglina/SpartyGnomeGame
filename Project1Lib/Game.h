/**
 * @file Game.h
 * @author Elia Spyratos
 *
 * Header for game class
 */

#ifndef PROJECT1_GAME_H
#define PROJECT1_GAME_H

#include <memory>
#include "Item.h"
#include <random>
#include "Background.h"

/**
 * Game class
 *
 * Holds items in the game, the background item,
 * and nearest item function for finding nearest item relative
 * to a given item. As well as a hit test function, and a
 * function to move a given item to the front of the window
 */
class Game {
private:

    // BACKGROUND ITEM IS WHAT IS IN MITEMS AND IS WHAT UPDATES FROM THE DEFUALT
    /// Background of the game
    std::unique_ptr<wxBitmap> mBackground;

    /// Random number generator
    std::mt19937 mRandom;

    /// Game area height in virtual pixels
    const static int mHeight = 1024;

    /// Scale for virtual pixels
    double mScale;


public:

    // Constructor
    Game();

    // On draw function
    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);


    /**
     * Get the random number generator
     * @return Pointer to teh random number generator
     */
    std::mt19937 &GetRandom() {return mRandom;}

    /**
     * Get the width of the game
     * @return game width in pixels
     */
    double GetWidth() { return mBackground->GetWidth(); }

    /**
     * Get the height of the game
     * @return game width in pixels
     */
    double GetHeight() { return mBackground->GetHeight(); }


};

#endif //PROJECT1_GAME_H
