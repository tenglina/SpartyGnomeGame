/**
 * @file PlayingArea.h
 * @author Isabella Beth Engelman
 *
 * PlayingArea header file
 */

#ifndef PROJECT1_PLAYINGAREA_H
#define PROJECT1_PLAYINGAREA_H

#include "Item.h"
#include "SpartyGnome.h"

/**
 * Class for the playable area
 */
class PlayingArea{
private:
    ///Pointer to sparty gnome
    std::shared_ptr<SpartyGnome> mSparty;

    ///Pointer to wxTimer for elapsed time
    std::shared_ptr<wxTimer> mElapsed;


public:
    /// Constructor
    PlayingArea() = default;

    // On key down event
    void OnKeyDown(wxKeyEvent &event);

    // On key up event
    void OnKeyUp(wxKeyEvent &event);

    /**
     * Sets the mSparty member variable
     * @param sparty Sparty to set
     */
    void SetSparty(std::shared_ptr<SpartyGnome> sparty) {mSparty = sparty;}

    /**
     * Sets the mElapsed member variable
     * @param elapsed wxTimer to set
     */
    void SetElapsed(std::shared_ptr<wxTimer> elapsed) {mElapsed = elapsed;}



};

#endif //PROJECT1_PLAYINGAREA_H
