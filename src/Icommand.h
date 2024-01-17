//
// Created by danie on 17/01/2024.
//

#ifndef FOOBAR_DT_ICOMMAND_H
#define FOOBAR_DT_ICOMMAND_H


#include <string>
#include "Ihash.h"
class Icommand {
public:
    virtual void execute(std::string, int* array, int size, vector<Ihash*> hashes) = 0;
};


#endif //FOOBAR_DT_ICOMMAND_H
