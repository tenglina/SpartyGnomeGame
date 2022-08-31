/**
 * @file LevelEndDoor.h
 * @author Nandini Tengli
 *
 * Level End Door header file
 */

#ifndef PROJECT1_LEVELENDDOOR_H
#define PROJECT1_LEVELENDDOOR_H

#include "Item.h"
#include "Game.h"



/**
 * Class describing level end door
 *
 * connects one level to the next
 */
class LevelEndDoor : public Item{
private:


public:
    ///Disable default constructor
    LevelEndDoor() = delete;

    ///Disable Copy Constructor
    LevelEndDoor(const LevelEndDoor &) = delete;

    ///Assignment operator
    void operator=(const LevelEndDoor &) = delete;

    ///Constructor
    LevelEndDoor(Game* game, std::shared_ptr<wxImage> image, std::shared_ptr<wxBitmap> bitmap);

    // XmlSave function
    wxXmlNode* XmlSave(wxXmlNode* node) override;

    // XmlLoad function
    void XmlLoad(wxXmlNode *node) override;

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     * @return returns an int for which collision action we need
     */
    int Accept(ItemVisitor* visitor) override {return visitor->VisitLevelEndDoor(this);}

};

#endif //PROJECT1_LEVELENDDOOR_H
