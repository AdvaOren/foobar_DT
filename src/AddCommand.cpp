#include "AddCommand.h"

/**
 * name:execute
 * input:URL,array of indexes,vector of hash funcs, vector of blacklisted strings
 * output: marks the hashed indexes on the arrray and adds the URL to vector
 * */
void AddCommand::execute(string URL, int *array, vector<IHash*> hashes, vector<string>* blackList) {
    for (IHash* h: hashes) {
            array[h->hash(URL)] = 1;
    }
    blackList->push_back(URL);
}
