/**
 * @file BackgroundDeclaration.h
 * @author Isabella Beth Engelman
 *
 * BackgroundDeclaration header file
 */

#ifndef PROJECT1_BACKGROUNDDECLARATION_H
#define PROJECT1_BACKGROUNDDECLARATION_H


#include "Declaration.h"

/**
 * BackgroundDeclaration object
 */
class BackgroundDeclaration: public Declaration {
private:

public:

    // Constructor
    BackgroundDeclaration(Game *game, const std::wstring &filename, std::wstring &id);

    // Create function
    std::shared_ptr<Item> Create() override;

};

#endif //PROJECT1_BACKGROUNDDECLARATION_H
