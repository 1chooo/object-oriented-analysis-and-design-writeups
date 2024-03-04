# Material 02 - Inheritance

```cpp
class Pet {
  public:
    // Constructors, Destructors
    Pet() : weight(1), food("Pet Chow") {}
    ~Pet() {}
    // Accessors
    void setWeight(int w) { weight = w; }
    int getWeight() { return weight; }
    void setfood(string f) { food = f; }
    string getFood() { return food; }
    // General methods
    void eat();
    void speak();

  protected: // subclasses can access these
    int weight;
    string food;
};

void Pet::eat() {
    cout << "Eating " << food << endl;
}

void Pet::speak() {
    cout << "Growl" << endl;
}

class Rat : public Pet {    // use inheritance to solve the reused problem
  public:
    Rat() {}
    ~Rat() {}
    // Other methods
    void sicken() {
        cout << "Spreading Plague" << endl;
    }
};

class Cat : public Pet {
  public:
    Cat() : numberToes(5) {}
    ~Cat() {}
    // Other accessors
    void setNumberToes(int toes) { numberToes = toes; }
    int getNumberToes() { return numberToes; }

  private:
    int numberToes;
};

int main() {
    Rat charles;
    Cat fluffy;

    charles.setWeight(25);
    cout << "Charles weighs " << charles.getWeight() << " lbs. " << endl;
    charles.speak();
    charles.eat();
    charles.sicken();

    fluffy.speak();
    fluffy.eat();
    cout << "Fluffy has " << fluffy.getNumberToes() << " toes " << endl;
    
    return 0;
}
```

- data members of the Pet base class are declared as `protected` -> subtypes of the base class will be directly access these variables
- `private` -> only the Pet class could directly access them; subclasses could not
- `public` -> any class or part of code could accessed them. This would defeat a key goal of object-oriented design: encapsulating data within a class and exposing the data only through the public interface.
- Each subtype of the base class has its own constructor and destructor. -> copy constructors and destructors are not inherited.

Rat, Cat inherit from Pet with `eat` and `speak` methods. Rat has a new method `sicken` and Cat has a new data member `numberToes` and methods `setNumberToes` and `getNumberToes`.

- Rat and Cat objects inherit the methods of the base class, Pet. We can call the speak method and the eat method on objects of type Rat and Cat. These methods were defined only in Pet and not in the subclasses.  
- Also, notice the each subclass extends the base class by adding methods and members. The Rat class has the "sicken" method. The Cat class has methods and members related to the number of toes an individual cat object has. 

> [!IMPORTANT] 
> This is the most common software reuse by extending additional behaviors in OO system development 

- The base class contains common members and methods used by the subclasses 
- The subtypes are more specialized than the base class. 

## Specialization

```cpp
class Pet {
  public:
    // Constructors, Destructors
    Pet() : weight(1), food("Pet Chow") {
        cout << "Pet Constructor" << endl;
    }
    ~Pet() {
        cout << "Pet Destructor" << endl;
    }
    // Accessors
    void setWeight(int w) { weight = w; }
    int getWeight() { return weight; }
    void setfood(string f) { food = f; }
    string getFood() { return food; }
    // General methods
    void eat();
    void speak();

  protected: // subclasses can access these
    int weight;
    string food;
};

void Pet::eat() {
    cout << "Eating " << food << endl;
}

void Pet::speak() {
    cout << "Growl" << endl;
}

class Rat : public Pet {
  public:
    Rat() { cout << "Rat Constructor" << endl; }
    ~Rat() { cout << "Rat Destructor" << endl; }
    // Other methods
    void sicken() {
        cout << "Spreading Plague" << endl;
    }
};

class Cat : public Pet {
  public:
    Cat() : numberToes(5) { cout << "Cat Constructor" << endl; }
    ~Cat() { cout << "Cat Destructor" << endl; }
    // Other accessors
    void setNumberToes(int toes) { numberToes = toes; }
    int getNumberToes() { return numberToes; }

  private:
    int numberToes;
};

int main() {
    Rat charles;
    Cat fluffy;

    return 0;
}
```

Output:

```bash
Pet Constructor    // Charles Pet Constructor
Rat Constructor    // Charles Rat Constructor
Pet Constructor    // Fluffy Pet Constructor
Cat Constructor    // Fluffy Cat Constructor
Cat Destructor     // Fluffy Cat Destructor
Pet Destructor     // Fluffy Pet Destructor
Rat Destructor     // Charles Rat Destructor
Pat Destructor     // Charles Pat Destructor
```

in user system stack, it looks like this:
```
+--------+     <-- Pet init Constructor    Base
| weight |                                  |
| food   |      (Pet)                       |
+-----------+                               |
| numoftoes |   (Cat)                       V
+-----------+  <-- Cat init Constructor  Specialized
```

- The **base class** part of an object is **always constructed first and destroyed last**. The **subclass** part of an object is **constructed last and destroyed first**. 
- The reason for this is that each object of a subtype consists of multiple parts, a base class part and a subclass part. The base class constructor forms the base class part. The subclass constructor forms the subclass part. Destructors clean up their respective parts. 

> [!IMPORTANT] 
> 每一個 subclass 要自行負責建構與清除自己的特異化的的部分

In the previous example, all the classes used default constructors. That is, the constructors took no arguments. Suppose that there were constructors that took arguments. How would this be handled? Here's a simple example. 
