/**
 * @file Background.h
 * @author Elia Spyratos
 *
 * Background header file
 */

#ifndef PROJECT1_BACKGROUND_H
#define PROJECT1_BACKGROUND_H

#include "Item.h"

/**
 * Background class
 * Holds the background of a level
 */
class Background : public Item{
private:

public:
    /// Default constructor (disabled)
    Background() = delete;

    /// Copy constructor (disabled)
    Background(const Background &) = delete;

    /// Assignment operator
    void operator=(const Background &) = delete;

    // Constructor
    Background(Game* game, std::shared_ptr<wxImage> image, std::shared_ptr<wxBitmap> bitmap);

    // XmlSave function
    wxXmlNode* XmlSave(wxXmlNode* node) override;

};

#endif //PROJECT1_BACKGROUND_H
