/**
 * @file ItemVisitor.h
 * @author Elia Spyratos
 *
 * Item visitor base class
 */

#ifndef PROJECT1_ITEMVISITOR_H
#define PROJECT1_ITEMVISITOR_H

// Forward references to all item types
class Astroid;
class Background;
class LevelEndDoor;
class Money;
class Platform;
class SpartyGnome;
class Stanley;
class Wall;
class WickedWolverine;
class WisconsonCat;
class WormHole;


/** Item visitor base class
 */
class ItemVisitor {
private:

public:
    virtual ~ItemVisitor() {}

    /**
     * Visit an Asteroid object
     * @param asteroid Asteroid we are visiting
     * @return int to return for deciding which collision action to perform
     */
     virtual int VisitAsteroid(Astroid* asteroid){return 2;}

    /**
    * Visit a Background object
    * @param background Background we are visiting
    * @return int to return for deciding which collision action to perform
    */
    virtual int VisitBackground(Background* background){return -1;}

    /**
     * Visit a LevelEndDoor object
     * @param levelEndDoor LevelEndDoor we are visiting
     * @return int to return for deciding which collision action to perform
     */
    virtual int VisitLevelEndDoor(LevelEndDoor* levelEndDoor){return 1;}

    /**
     * Visit a Money object
     * @param money Money we are visiting
     * @return int to return for deciding which collision action to perform
     */
    virtual int VisitMoney(Money* money){return -1;}

    /**
     * Visit a Platform object
     * @param platform Platform we are visiting
     * @return int to return for deciding which collision action to perform
     */
    virtual int VisitPlatform(Platform* platform){return 5;}

    /**
     * Visit a SpartyGnome object
     * @param partyGnome SpartyGnome we are visiting
     * @return int to return for deciding which collision action to perform
     */
    virtual int VisitSpartyGnome(SpartyGnome* partyGnome){return -1;}

    /**
     * Visit a Stanley object
     * @param stanley Stanley we are visiting
     * @return int to return for deciding which collision action to perform
     */
    virtual int VisitStanley(Stanley* stanley){return 4;}

    /**
     * Visit a Wall object
     * @param wall Wall we are visiting
     * @return int to return for deciding which collision action to perform
     */
    virtual int VisitWall(Wall* wall){return 5;}

    /**
     * Visit a WickedWolverine object
     * @param wickedWolverine WickedWolverine we are visiting
     * @return int to return for deciding which collision action to perform
     */
    virtual int VisitWickedWolverine(WickedWolverine* wickedWolverine){return 2;}

    /**
     * Visit a wisconsonCat object
     * @param wisconsonCat WisconsonCat we are visiting
     * @return int to return for deciding which collision action to perform
     */
    virtual int VisitWisconsonCat(WisconsonCat* wisconsonCat){return 2;}

    /**
     * Visit an WormHole object
     * @param wormHole WormHole we are visiting
     * @return int to return for deciding which collision action to perform
     */
    virtual int VisitWormHole(WormHole* wormHole){return 3;}

};

#endif //PROJECT1_ITEMVISITOR_H
