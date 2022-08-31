/**
 * @file AstroidDeclaration.h
 * @author Isabella Beth Engelman
 *
 * Astroid Declaration header file
 */

#ifndef PROJECT1_ASTROIDDECLARATION_H
#define PROJECT1_ASTROIDDECLARATION_H

#include "Declaration.h"

/**
 * AstroidDeclaration object
 */
class AstroidDeclaration: public Declaration {
private:

public:
    // Constructor
    AstroidDeclaration(Game* game, const std::wstring& filename, std::wstring& id);

    // Create function
    std::shared_ptr<Item>  Create() override;

};

#endif //PROJECT1_ASTROIDDECLARATION_H












