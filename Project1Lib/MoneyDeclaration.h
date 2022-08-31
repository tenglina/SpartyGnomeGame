/**
 * @file MoneyDeclaration.h
 * @author Isabella Beth Engelman
 *
 * MoneyDeclaration header file
 */

#ifndef PROJECT1_MONEYDECLARATION_H
#define PROJECT1_MONEYDECLARATION_H
#include "Declaration.h"

/**
 * MoneyDeclaration class
 */
class MoneyDeclaration: public Declaration{
private:

    /// Value to given to created objects
    int mValue;

public:
    // Constructor
   MoneyDeclaration(Game* game, const std::wstring& filename, std::wstring& id, int &value);

    // Create item based on declaration
    std::shared_ptr<Item> Create() override;
};

#endif //PROJECT1_MONEYDECLARATION_H
