#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Supplier;
class Part;

class Relation {
  private:
    int SNum;
    int PNum;
    std::string City;
    int Qty;

    Supplier *supplier;
};

class Supplier {
  private:
    int SNum;
    std::string SName;
    int Qty;
    std::string City1;

    Relation *relation;
};

class Part {
  private:
    int PNum;
    std::string PName;
    std::string Color;
    float Weight;
    std::string City2;

    Relation *relation;
};

int main() {
    printf("Hello, World!\n");
    return 0;
}
