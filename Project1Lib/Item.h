/**
 * @file Item.h
 * @author Elia Spyratos
 *
 * Item header file
 */

#ifndef PROJECT1_ITEM_H
#define PROJECT1_ITEM_H

#include <wx/xml/xml.h>
#include <wx/osx/bitmap.h>
#include <wx/graphics.h>
#include "Vector.h"
#include "ItemVisitor.h"

class Game;
class SpartyGnome;

/**
 * Base class for any Item in our Sparty Gnome game
 */
class Item {
private:

    /// The game this item is contained in
    Game *mGame;

    /// The id associated with this item
    std::wstring mId;

    bool mMirror = false; ///< True mirrors the item image

protected:
    //Protected Copy
//    Item(Game *game, const std::wstring &filename);
    /// The underlying item image
    std::shared_ptr<wxImage> mItemImage;

    /// The bitmap we can display for this item
    std::shared_ptr<wxBitmap> mItemBitmap;

    Vector mP;          ///< Position

    /// Reference to Sparty
    std::shared_ptr<SpartyGnome> mSparty;

public:

    /// Constructor that includes image filename
    Item(Game *game, std::shared_ptr<wxImage> image, std::shared_ptr<wxBitmap> bitmap);

    /// Default constructor (disabled)
    Item() = delete;

    /// Copy constructor (disabled)
    Item(const Item &) = delete;

    // Destructor
    ~Item();

    /**
     * Set the pointer to sparty
     * @param sparty Sparty item to set
     */
    void SetSparty(std::shared_ptr<SpartyGnome> sparty){mSparty=sparty;}

    /// Assignment operator (deleted)
    void operator=(const Item &) = delete;

    /**
     * The x location of the item
     * @return X location in pixels
     */
    double GetX() const { return mP.X(); }

    /**
     * The Y location of the item
     * @return Y location in pixels
     */
    double GetY() const { return mP.Y(); }

    /**
     * Set the item location
     * @param x X location in pixels
     * @param y Y location in pixels
     */
    virtual void SetLocation(double x, double y) { mP.SetX(x); mP.SetY(y);}

    /**
     * Set the Id
     * @param id The id
     */
     void SetId(std::wstring id) {mId = id;}

    /**
    * Get the Id
    * @return The id
    */
    std::wstring GetId() {return mId;}

    // Draw function
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    // Draw function with offset
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int scrollX);

    /**
     * The game item is in
     * @return game we are in
     */
     Game* GetGame() const {return mGame;}

     // Distance to function
     double DistanceTo(std::shared_ptr<Item> item);

     // Save to xml function
     virtual wxXmlNode* XmlSave(wxXmlNode *node);

     // XmlLoad function
     virtual void XmlLoad(wxXmlNode *node);

    /**
     * Handle updates for animation
     * @param elapsed the Time since hte last update
     */
     virtual void Update(double elapsed) {};


     /**
      * Get the image's width
      * @return Double of the image's width
      */
      double GetImageWidth() { return mItemImage->GetWidth(); }

      /**
       * Get the image's height
       * @return Double of the image's height
       */
       double GetImageHeight() { return mItemImage->GetHeight(); }

       /**
        * Virtual set height and width function
        * @param h Height to set
        * @param w Width to set
        */
        virtual void SetHeightWidth(int h, int w) {}

        /**
         * Virtual get height function
         * @return Height of object
         */
        virtual double GetHeight(){return 0;}

        /**
         * Virtual get width function
         * @return Width of object
         */
        virtual double GetWidth(){return 0;}

         /**
          * Accept a visitor
          * @param visitor The visitor we accept
          * @return int returns an Int used to decide what collision we need
          */
          virtual int Accept(ItemVisitor* visitor) {return -1;}

          /**
           * What to do when colliding with sparty
           * If return 1, we collided with an enemy
           * @return bool returns if first collision has occurred
           */
          virtual bool Collide()  {return false;}
};

#endif //PROJECT1_ITEM_H
