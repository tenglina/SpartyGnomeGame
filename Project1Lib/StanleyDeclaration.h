/**
 * @file StanleyDeclaration.h
 * @author Isabella Beth Engelman
 *
 * StanleyImplementation header file
 */

#ifndef PROJECT1_STANLEYDECLARATION_H
#define PROJECT1_STANLEYDECLARATION_H

#include "Declaration.h"
#include "Stanley.h"

/**
 * StanleyDeclaration object
 */
class StanleyDeclaration: public Declaration {
private:

public:

    // Constructor that includes image filename
    StanleyDeclaration(Game *game, const std::wstring &filename, std::wstring &id);

    // Create item based on declaration
    std::shared_ptr<Item> Create() override;

};

#endif //PROJECT1_STANLEYDECLARATION_H
