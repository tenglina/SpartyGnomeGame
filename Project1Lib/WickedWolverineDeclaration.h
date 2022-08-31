/**
 * @file WickedWolverineDeclaration.h
 * @author Isabella Beth Engelman
 *
 * WickedWolverine header file
 */

#ifndef PROJECT1_WICKEDWOLVERINEDECLARATION_H
#define PROJECT1_WICKEDWOLVERINEDECLARATION_H
#include "Declaration.h"

/**
 * WickedWolverineDeclartion Object
 */
class WickedWolverineDeclaration:public Declaration {
private:

public:
    // Constructor
    WickedWolverineDeclaration(Game* game, const std::wstring& filename, std::wstring& id);

    // Create item based on declaration
    std::shared_ptr<Item> Create() override;
};

#endif //PROJECT1_WICKEDWOLVERINEDECLARATION_H
