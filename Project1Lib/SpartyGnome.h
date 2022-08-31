/**
 * @file SpartyGnome.h
 * @author Elia Spyratos
 *
 * Sparty Gnome header file
 */

#ifndef PROJECT1_SPARTYGNOME_H
#define PROJECT1_SPARTYGNOME_H

#include "Item.h"
#include "Vector.h"
#include "Level.h"

/**
 * Class for Sparty Gnome, the playable character
 */
class SpartyGnome : public Item{
private:
    /// Velocity vector
    Vector mVelocity;

    /// Initializing gravity
    double mGravity = 0;

    /// If Sparty is grounded, he can jump
    bool mGrounded = true;

    /// If Sparty is alive, we can play
    bool mAlive = true;

    /// If the leve has "started" yet
    bool mStarted = false;

    /// Bitmap Right
    std::shared_ptr<wxBitmap> mBitmapRight;

    /// Bitmap Left
    std::shared_ptr<wxBitmap> mBitmapLeft;

    /// Bitmap Jump
    std::shared_ptr<wxBitmap> mBitmapJump;

    /// Bitmap Right 2
    std::shared_ptr<wxBitmap> mBitmapRight2;

    /// Bitmap Left 2
    std::shared_ptr<wxBitmap> mBitmapLeft2;

    /// Bitmap Dead
    std::shared_ptr<wxBitmap> mBitmapDead;

    /// Image Right
    std::shared_ptr<wxImage> mImageRight;

    /// Image Left
    std::shared_ptr<wxImage> mImageLeft;

    /// Image Jump
    std::shared_ptr<wxImage> mImageJump;

    /// Image Right 2
    std::shared_ptr<wxImage> mImageRight2;

    /// Image Left 2
    std::shared_ptr<wxImage> mImageLeft2;

    /// Image Dead
    std::shared_ptr<wxImage> mImageDead;

    /// Animation integer to keep track of which we are doing, 0 = jump, 1 = right, 2 = right2, 3 = left, 4 = left 2, 5 = dead
    int mAnimationDirection = 0;

    /// Animation "frame" counter so Sparty swaps walking animation frames
    int mAnimationFrame = 0;

    /// Reset Level flag
    bool mResetLevel = false;

    /// Pointer to level
    Level* mLevel;

public:
    /// Default constructor (disabled)
    SpartyGnome() = delete;

    /// Copy constructor (disabled)
    SpartyGnome(const SpartyGnome &) = delete;

    /// Assignment operator
    void operator=(const SpartyGnome &) = delete;

    // Constructor
    SpartyGnome(Game* game, std::shared_ptr<wxImage> image, std::shared_ptr<wxBitmap> bitmap,
            std::shared_ptr<wxImage> imageLeft, std::shared_ptr<wxBitmap> bitmapLeft,
            std::shared_ptr<wxImage> imageRight, std::shared_ptr<wxBitmap> bitmapRight,
            std::shared_ptr<wxImage> imageLeft2, std::shared_ptr<wxBitmap> bitmapLeft2,
            std::shared_ptr<wxImage> imageRight2, std::shared_ptr<wxBitmap> bitmapRight2,
            std::shared_ptr<wxImage> imageDead, std::shared_ptr<wxBitmap> bitmapDead);

    // XmlSave function
    wxXmlNode* XmlSave(wxXmlNode* node) override;

    // Update function
    void Update(double elapsed) override;

    /**
     * Sets the gravity for Sparty
     * @param g Gravity to set
     */
    void SetGravity(double g) {mGravity = g;}

    /**
     * Sets the jump speed
     * @param jumpV Jump speed to set
     */
    void SetJumpSpeed(double jumpV) {mVelocity.SetY(jumpV);}

    // Jump function
    void Jump();

    // Move right function
    void MoveRight();

    // Move left function
    void MoveLeft();

    // Stop X movement function
    void StopXMovement();

    // Animate function
    void Animate();

     /**
      * Animate Jump function
      */
     void AnimateJump(){if(mAnimationDirection != 0 && mAlive && mStarted) {mItemBitmap = mBitmapJump; mAnimationDirection = 0; }}

     /**
      * Animate Right function
      */
     void AnimateRight(){if(mAnimationDirection != 1 && mAnimationDirection != 2 && mAlive && mStarted){ mItemBitmap = mBitmapRight; mAnimationDirection = 1;}}

     /**
      * Animate Left function
      */
     void AnimateLeft(){if(mAnimationDirection != 3 && mAnimationDirection != 4 && mAlive && mStarted){mItemBitmap = mBitmapLeft; mAnimationDirection = 3;}}

     /**
      * Reset function
      */
     void Reset(){mGravity = 0; SetJumpSpeed(0); mGrounded = true; mAlive = true; mStarted = false; mResetLevel = false;}

     /**
      * Die function
      */
     void Die(){mAlive = false; mItemBitmap = mBitmapDead; mAnimationDirection = 5;}

     /**
      * Returns if alive
      * @return Bool
      */
     bool IsAlive(){return mAlive;}

     /**
      * Returns if started
      * @return Started
      */
     bool HasStarted(){return mStarted;}

     /**
      * Returns if reset level needs to happen
      * @return Bool
      */
     bool LevelReset(){return mResetLevel;}

     // WormHole function
     void WormHole();

     /**
      * Setter for level
      * @param level The level object we are using
      */
     void SetLevel(Level* level){mLevel = level;}

    /**
    * Accept a visitor
    * @param visitor The visitor we accept
    * @return int to return for specific collision action
    */
    int Accept(ItemVisitor* visitor) override {return visitor->VisitSpartyGnome(this);}

};

#endif //PROJECT1_SPARTYGNOME_H
