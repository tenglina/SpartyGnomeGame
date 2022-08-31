/**
 * @file Astroid.h
 * @author Alexandra Case
 *
 * Astroid Header file
 */

#ifndef PROJECT1_ASTROID_H
#define PROJECT1_ASTROID_H

#include "Enemy.h"
#include "Game.h"

/**
 * Asteroid class
 * Inherits from Enemy
 */
class Astroid : public Enemy {
private:

    /// Rotation number for asteroid (for wavy movement)
    int rotation = 0;

public:
    /// Default constructor (disabled)
    Astroid() = delete;

    /// Copy constructor (disabled)
    Astroid(const Astroid &) = delete;

    /// Assignment operator (disabled)
    void operator=(const Astroid &) = delete;

    // Constructor
    Astroid(Game* game, std::shared_ptr<wxImage> image, std::shared_ptr<wxBitmap> bitmap);

    // XmlSave function
    wxXmlNode* XmlSave(wxXmlNode* node) override;

    // Update function
    void Update(double elapsed) override;

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     * @return Returns an int based on what object we are
     */
     int Accept(ItemVisitor* visitor) override {return visitor->VisitAsteroid(this);}



};



#endif //PROJECT1_ASTROID_H

