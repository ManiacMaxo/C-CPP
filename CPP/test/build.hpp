#ifndef BUILD_HPP
#define BUILD_HPP

#include <string>
#include <vector>
#include "materials.hpp"
#include "receipt.hpp"
using namespace std;

class Build {
    vector<Solids> solids;
    vector<Liquids> liquids;
    Receipt receipt;

   public:
    Receipt get_receipt() { return receipt; }
};

#endif
