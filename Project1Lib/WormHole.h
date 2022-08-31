/**
 * @file WormHole.h
 * @author Alexandra Case
 *
 * WormHole header file
 */


#ifndef PROJECT1_WORMHOLE_H
#define PROJECT1_WORMHOLE_H
#include "Item.h"

/**
 * WormHole class
 *
 */
class WormHole : public Item {
private:

    /// Rotation number for wormhole animation
    int rotation = 0;

public:
    /// Default constructor (disabled)
    WormHole() = delete;

    /// Copy constructor (disabled)
    WormHole(const WormHole &) = delete;

    /// The Assignment operator
    void operator=(const WormHole &) = delete;

    // Constructor
    WormHole(Game* game, std::shared_ptr<wxImage> image, std::shared_ptr<wxBitmap> bitmap);

    // XmlSave function
    wxXmlNode* XmlSave(wxXmlNode* node) override;

    /**
     * Collide function for wormholes
     * @return returns true
     */
    bool Collide() override {return true;}

    // Update function
    void Update(double elapsed) override;

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     * @return int that signifies which collision action to use
     */
    int Accept(ItemVisitor* visitor) override {return visitor->VisitWormHole(this);}

};


#endif //PROJECT1_WORMHOLE_H
