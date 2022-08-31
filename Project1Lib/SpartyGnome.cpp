/**
 * @file SpartyGnome.cpp
 * @author Elia Spyratos
 *
 * Sparty Gnome implementation file
 */

#include "pch.h"
#include "SpartyGnome.h"
#include "Game.h"


using namespace std;


/// Small value to ensure we do not stay in collision
const double Epsilon = 0.001;

///Maximum amount of time to allow for elapsed
const double MaxElapsed = 0.050;


/**
 * Constructor
 * @param game Game we are tied to
 * @param image Standing Image
 * @param bitmap Standing Bitmap
 * @param imageLeft Walking left image
 * @param bitmapLeft Walking left bitmap
 * @param imageRight Walking right image
 * @param bitmapRight Walking right bitmap
 * @param imageLeft2 Walking left image 2
 * @param bitmapLeft2 Walking left bitmap 2
 * @param imageRight2 Walking right image 2
 * @param bitmapRight2 Walking right bitmap 2
 * @param imageDead Dead image
 * @param bitmapDead Dead bitmap
 */
 SpartyGnome::SpartyGnome(Game* game, std::shared_ptr<wxImage> image, std::shared_ptr<wxBitmap> bitmap,
         std::shared_ptr<wxImage> imageLeft, std::shared_ptr<wxBitmap> bitmapLeft,
         std::shared_ptr<wxImage> imageRight, std::shared_ptr<wxBitmap> bitmapRight,
         std::shared_ptr<wxImage> imageLeft2, std::shared_ptr<wxBitmap> bitmapLeft2,
         std::shared_ptr<wxImage> imageRight2, std::shared_ptr<wxBitmap> bitmapRight2,
         std::shared_ptr<wxImage> imageDead, std::shared_ptr<wxBitmap> bitmapDead): Item(game, image, bitmap)
 {
    mImageLeft = std::move(imageLeft);
    mBitmapLeft = std::move(bitmapLeft);

    mImageRight = std::move(imageRight);
    mBitmapRight = std::move(bitmapRight);

    mImageJump = std::move(image);
    mBitmapJump = std::move(bitmap);

    mImageRight2 = std::move(imageRight2);
    mBitmapRight2 = std::move(bitmapRight2);

     mImageLeft2 = std::move(imageLeft2);
     mBitmapLeft2 = std::move(bitmapLeft2);

     mImageDead = std::move(imageDead);
     mBitmapDead = std::move(bitmapDead);

 }

/**
 * Save this item to an XML node
 * @param node The parent node we are going to be a child of
 * @return wxXmlNode* to return
 */
wxXmlNode* SpartyGnome::XmlSave(wxXmlNode* node)
{
    auto itemNode = Item::XmlSave(node);

    itemNode->AddAttribute(L"type", L"spartygnome");

    return itemNode;
}

/**
 * Jump function
 */
 void SpartyGnome::Jump()
{
    if(mGrounded && mVelocity.Y() < 20)
    {
        SetGravity(1000);
        SetJumpSpeed(-800);
        mGrounded = false;
        mStarted = true;
    }

    if(mAlive == false)
    {
        mResetLevel = true;
    }
}

/**
 * Move right function
 */
void SpartyGnome::MoveRight()
{
   if(mStarted)
    {
        mVelocity.SetX(500);
    }
}

/**
 * Move left function
 */
void SpartyGnome::MoveLeft()
{
    if(mStarted)
    {
        mVelocity.SetX(-500);
    }
}

/**
 * Stop X movement function
 */
void SpartyGnome::StopXMovement()
{
    mVelocity.SetX(0);
}

/**
 * Update for animations
 * @param elapsed elapsed time
 */
void SpartyGnome::Update(double elapsed)
{

    while(elapsed > MaxElapsed)
    {
        Update(MaxElapsed);
        elapsed-=MaxElapsed;
    }

    if(mAlive) {
        Item::Update(elapsed);

        //Gravity
        // Compute a new velocity with gravity added in.

        Vector newV(mVelocity.X(), mVelocity.Y()+mGravity*elapsed);

        // Update position
        Vector newP = mP+newV*elapsed;

        //
        // updating the Y location.
        //
        SetLocation(mP.X(), newP.Y());

        auto collided = mLevel->CollisionTest();
        //bool verticalCollision = mLevel->CollisionEdge(collided);
        if (collided!=nullptr)
        {
            //bool verticalCollision = mLevel->CollisionEdge(collided);
            //if(verticalCollision)
            //{
                if (newV.Y()>0) {
                    //We are falling, stop at the collision point
                    newP.SetY(collided->GetY()-(collided->GetHeight()/2)-(GetImageHeight()/2)-Epsilon);
                    mGrounded = true;
                }
                else {
                    //We are rising, stop at the collision point
                    newP.SetY(collided->GetY()+collided->GetHeight()/2+GetImageHeight()/2+Epsilon);

                }

                // If we collide, we cancel any velocity
                // in the Y direction
                newV.SetY(0);
                SetLocation(mP.X(), newP.Y());
            //}

        }

        //
        // updating the X location
        //
        SetLocation(newP.X(), mP.Y());

        collided = mLevel->CollisionTest();


        if (collided != nullptr)
       {
            //bool verticalCollision = mLevel->CollisionEdge(collided);
            //if(!verticalCollision)
            //{
                if (newV.X() > 0)
                {
                    //We are moving to the right, stop at the collision point
                    newP.SetX(collided->GetX() - collided->GetWidth() / 2 - (GetImageWidth() / 2.0) - Epsilon);
                }
                else
                {
                    //We are moving to the left, stop at the collision point
                    newP.SetX(collided->GetX() + collided->GetWidth() / 2 + (GetImageWidth() / 2) + Epsilon);
                }
                //If we collide, we cancel any velocity
                //in the X direction
                newV.SetX(0);
            //}

       }
        //Update the velocity and position
        mVelocity = newV;
        SetLocation(newP.X(), newP.Y());

        Animate();

        // Die if you fall off the edge
        if(mP.Y() > 1024)
        {
            Die();
        }

    }
}

/**
 * Animate function for sparty
 */
 void SpartyGnome::Animate()
 {
    mAnimationFrame += 1;

    if(mAnimationFrame > 6)
    {
        mAnimationFrame = 0;

        if(mAlive) {
            // 1 is right, 2 is right 2, 3 is left, 4 is left 2
            switch (mAnimationDirection) {
            case 0:
                break;
            case 1:
                mAnimationDirection = 2;
                mItemBitmap = mBitmapRight2;
                break;
            case 2:
                mAnimationDirection = 1;
                mItemBitmap = mBitmapRight;
                break;
            case 3:
                mAnimationDirection = 4;
                mItemBitmap = mBitmapLeft2;
                break;
            case 4:
                mAnimationDirection = 3;
                mItemBitmap = mBitmapLeft;
                break;
            }
        }
    }

 }

 /**
  * Wormhole function
  * Teleports the player
  */
  void SpartyGnome::WormHole()
  {
      SetLocation(2600, 0);
      mVelocity.SetY(0);
  }

