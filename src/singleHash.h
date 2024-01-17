//
// Created by danie on 17/01/2024.
//

#ifndef FOOBAR_DT_SINGLEHASH_H
#define FOOBAR_DT_SINGLEHASH_H
#include "Ihash.h"

class singleHash:Ihash {
private:
    int size;
public:
    singleHash(int size);
    vector<int> hash(std::string URL);
};


#endif //FOOBAR_DT_SINGLEHASH_H
