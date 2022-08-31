/**
 * @file Level.h
 * @author Isabella Beth Engelman
 *
 * Level header file
 */

#ifndef PROJECT1_LEVEL_H
#define PROJECT1_LEVEL_H

#include <wx/graphics.h>
#include "Item.h"
#include "Background.h"
#include "Declaration.h"
#include <memory>
#include "ItemVisitor.h"
#include "Scoreboard.h"
#include"ItemVisitor.h"

class Game;
/**
 * Level Class
 *
 */
class Level {
private:

    /// Game this level object is tied to
    Game *mGame;

    /// All of the declarations to populate our game
    std::vector<std::shared_ptr<Declaration>> mDeclarations;

    /// All of the items to populate our game
    std::vector<std::shared_ptr<Item>> mItems;

    /// Reference to Sparty
    std::shared_ptr<SpartyGnome> mSparty;

    /// Scoreboard this level will use
    Scoreboard *mScoreboard;

    /// Int records which level we are on
    int mLevelWeAreOn = 0;

    /// Item visitor for collisions
    ItemVisitor mItemVisitor = ItemVisitor();


public:

    explicit Level(Game *game, Scoreboard *scoreboard);

    void AddItem(std::shared_ptr<Item> item);

    void AddDeclaration(std::shared_ptr<Declaration> declaration);

    void XmlItem(wxXmlNode *node);

    void XmlDeclaration(wxXmlNode *node);

    void MoveToFront(std::shared_ptr<Item> item);

    void Load(const wxString &filename);

    void Clear();

    void NextLevel();

    void AddItemsToGame(std::shared_ptr<wxGraphicsContext> graphics);

    /**
     * Sparty Gnome getter
     * @return a shared_ptr to the gnome
     */
    std::shared_ptr<SpartyGnome> GetSparty() {return mSparty;}

    void Update(double elapsed);

    void Accept(ItemVisitor* visitor);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int scrollX);

    void CreateSparty();

    void ResetLevel();

    /**
     * Sets the level we are on
     * @param level Level int to set
     */
    void SetLevelWeAreOn(int level){mLevelWeAreOn = level;}

    std::shared_ptr<Item> CollisionTest();

};

#endif //PROJECT1_LEVEL_H
//vector of shared pointers to items