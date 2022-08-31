/**
 * @file WisconsonCatDeclaration.h
 * @author Isabella Beth Engelman
 *
 * WisconsonCatDeclaration header file
 */

#ifndef PROJECT1_WISCONSONCATDECLARATION_H
#define PROJECT1_WISCONSONCATDECLARATION_H
#include "Declaration.h"

/**
 * WisconsonCatDeclaration object
 */
class WisconsonCatDeclaration: public Declaration {
private:

public:
    // Constructor
    WisconsonCatDeclaration(Game* game, const std::wstring& filename, std::wstring& id);

    // Create item based on declaration
    std::shared_ptr<Item> Create() override;
};

#endif //PROJECT1_WISCONSONCATDECLARATION_H
