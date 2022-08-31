/**
 * @file WallDeclaration.h
 * @author Alexandra Case
 *
 * WallDeclaration header file
 */

#ifndef PROJECT1_WALLDECLARATION_H
#define PROJECT1_WALLDECLARATION_H

#include "Declaration.h"

/**
 * WallDeclaration object
 */
class WallDeclaration: public Declaration  {
private:

public:
    // Constructor
    WallDeclaration(Game* game, const std::wstring& filename, std::wstring& id);


    // Create item based on declaration
    std::shared_ptr<Item> Create() override;

};
#endif //PROJECT1_WALLDECLARATION_H
