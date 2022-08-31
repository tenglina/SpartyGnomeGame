/**
 * @file Wall.h
 * @author Alexandra Case
 *
 * Wall header file
 */

#ifndef PROJECT1_WALL_H
#define PROJECT1_WALL_H

#include "Item.h"


/**
 * Wall Item
 *
 * Vertical Walls
 */
class Wall : public Item{

private:

    /// The height of the platform
    int mHeight;

    /// The width of the platform
    int mWidth;

public:
    /// Default constructor
    Wall() = delete;

    /// Copy constructor
    Wall(const Wall &) = delete;

    /// Assignment operator
    void operator=(const Wall &) = delete;

    // Constructor
    Wall(Game* game, std::shared_ptr<wxImage> image, std::shared_ptr<wxBitmap> bitmap);

    // XmlSave function
    wxXmlNode* XmlSave(wxXmlNode* node) override;

    /**
     * Sets height and width
     * @param h Height to set
     * @param w Width to set
     */
    void SetHeightWidth(int h, int w) override {mHeight = h; mWidth = w;}

    // Draw function
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    // Draw function
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int scrollX) override;

    /**
     * Get Height
     * @return mHeight
     */
    double GetHeight() override {return mHeight;}

    /**
     * Get Width
     * @return mWidth
     */
    double GetWidth() override {return mWidth;}

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     * @return int to return for specific collision action
     */
    int Accept(ItemVisitor* visitor) override {return visitor->VisitWall(this);}

};


#endif //PROJECT1_WALL_H
