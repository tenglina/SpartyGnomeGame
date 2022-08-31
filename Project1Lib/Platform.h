/**
 * @file Platform.h
 * @author Xianting Zhang
 *
 * Platform header file
 */

#ifndef PROJECT_1_PLATFORM_H
#define PROJECT_1_PLATFORM_H

#include "Item.h"

/**
 * Platform object
 *
 * Horizontal Platforms
 */
class Platform : public Item{
private:
    /// The underlying item image left
    std::shared_ptr<wxImage> mItemImageLeft;

    /// The bitmap left we can display for this item
    std::shared_ptr<wxBitmap> mItemBitmapLeft;

    /// The underlying item image rught
    std::shared_ptr<wxImage> mItemImageRight;

    /// The bitmap right we can display for this item
    std::shared_ptr<wxBitmap> mItemBitmapRight;

    /// The height of the platform
    int mHeight;

    /// The width of the platform
    int mWidth;

public:
    /// Default constructor (disabled)
    Platform() = delete;

    /// Copy constructor (disabled)
    Platform(const Platform &) = delete;

    /// Assignment operator
    void operator=(const Platform &) = delete;

    // constructor
    Platform(Game * game, std::shared_ptr<wxImage> imageLeft, std::shared_ptr<wxBitmap> bitmapLeft,
            std::shared_ptr<wxImage> image, std::shared_ptr<wxBitmap> bitmap,
            std::shared_ptr<wxImage> imageRight, std::shared_ptr<wxBitmap> bitmapRight);

    /**
     * Sets height and width
     * @param h Height to set
     * @param w Width to set
     */
    void SetHeightWidth(int h, int w) override {mHeight = h; mWidth = w;}

    /**
     * Get Height function
     * @return the height of the platform
     */
    virtual double GetHeight() override {return mHeight;}

    /**
     * Get Width function
     * @return the width of the platform
     */
    virtual double GetWidth() override {return mWidth;}

    // Draw function
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    // Draw function
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int scrollX) override;

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     * @return int to return for which collision action to perform
     */
    int Accept(ItemVisitor* visitor) override {return visitor->VisitPlatform(this);}

};


#endif //PROJECT_1_PLATFORM_H
