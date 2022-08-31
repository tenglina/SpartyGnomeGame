/**
 * @file LevelEndDoorDeclaration.h
 * @author Isabella Beth Engelman
 *
 * LeveEndDoorDeclaration header file
 */

#ifndef PROJECT1_LEVELENDDOORDECLARATION_H
#define PROJECT1_LEVELENDDOORDECLARATION_H
#include "Declaration.h"

/**
 * LevelEndDoorDeclaration object
 *
 * Declaration for the Door at the end of the level
 */
class LevelEndDoorDeclaration: public Declaration {
private:

public:

    // Constructor
    LevelEndDoorDeclaration(Game* game, const std::wstring& filename, std::wstring& id);

    // Create function
    std::shared_ptr<Item>  Create();
};

#endif //PROJECT1_LEVELENDDOORDECLARATION_H
