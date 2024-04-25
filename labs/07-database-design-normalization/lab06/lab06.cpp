#include <iostream>
#include <string>
#include <vector>

class Supplier;
class Part;

class Relation {
public:
    int SNum;
    int PNum;
    std::string City;
    int Qty;

    Supplier* supplier;
    Part* part;
};

class Supplier {
public:
    int SNum;
    std::string SName;
    std::string City;
    std::vector<Relation*> relations;
};

class Part {
public:
    int PNum;
    std::string PName;
    std::string Color;
    float Weight;
    std::string City;
    int Qty;
    std::vector<Relation*> relations;
};

int main() {
    return 0;
}
