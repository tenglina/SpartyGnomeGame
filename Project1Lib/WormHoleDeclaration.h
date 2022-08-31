/**
 * @file WormHoleDeclaration.h
 * @author Isabella Beth Engelman
 *
 * WormHoleDeclaration header file
 */

#ifndef PROJECT1_WORMHOLEDECLARATION_H
#define PROJECT1_WORMHOLEDECLARATION_H
#include "Declaration.h"

/**
 * WormHoleDeclaration object
 */
class WormHoleDeclaration: public Declaration {
private:

public:
    // Constructor
    WormHoleDeclaration(Game* game, const std::wstring& filename, std::wstring& id);

    // Create function
    std::shared_ptr<Item> Create();
};

#endif //PROJECT1_WORMHOLEDECLARATION_H
