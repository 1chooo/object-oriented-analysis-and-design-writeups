# Material 12 Lab - UML Class Diagram <!-- omit in toc -->

## Course

### Lab 01

Please draw a UML relation between car and baggage

```cpp
class Car {
  public:
    ...
    void addBaggageWeight(Baggage* baggage);
    ...

  private:
    double weight;
};

void Car::addBaggageWeight(Baggage* baggage) {
  weight += baggage.getWeight();
}
```

```mermaid
classDiagram
  class Car {
    + void addBaggageWeight(Baggage* baggage)
    - double weight
  }
  class Baggage {
    + double getWeight()
  }

  Car "1" -- "0..*" Baggage
```

The relation between car and baggage is Association.


### Lab 04

```mermaid
classDiagram
    class Party {
        + string location
        + void Method()
    }
    class Person {
    }
    class Organization {
    }
    Person "1" -- "1" Party
    Organization "1" -- "1" Party
    Organization "*" -- "1" Organization
```

Person, Organization -> Party

Person 跟 Org 是 * 對 1

Org 對 Org 是 * 對 1

```cpp
class Party {
    string location;

    void Method() {}
};

class Person : public Party {
};

class Organization : public Party {
};
```


### Lab 06

    
請用 `C++`, `Java` 等等你熟悉的語言舉一個例子 dependency 的例子。這個例子不能是 association (aggregation)。


```cpp
class A {
    void Method() {
        B b;
        b.Method();
    }
};

class B {
    void Method() {}
};
```

A 依賴 B，但不是 aggregation

```mermaid
classDiagram
    class A {
        + void Method()
    }
    class B {
        + void Method()
    }
    A --> B
```

### Lab 07

當我的核心程式碼要寫到與某一個 GUI SDK 無關來增加未來核心程式碼的可移植性。請問你要怎麼做到這件事情。

請你實際寫個程式片段證實你的理解。

```cpp
class Core {
    void Method() {}
};

class GUI {
    Core core;

    void Method() {
        core.Method();
    }
};
```

如此我未來核心程式碼當我需要更改 GUI SDK 時，只需要更改 GUI 這個 class 即可。

```mermaid
classDiagram
    class Core {
        + void Method()
    }
    class GUI {
        - Core core
        + void Method()
    }
    GUI --> Core
```

### Lab 08

下面的UML diagram 中，名稱畫底線的意思是?

代表是 static 的意思，屬於 class 本身



### Lab 10

請由下面一段程式碼畫出與class Employer 相關的所有 classes 的 UML class diagram

```java
class Employer extend Person implements Managing {
   Person employee[100] ;

    public void hireAnEmployee(Person p) {
    ...
    }
    public void fireAnEmployee(Person p) {
    ...
    }
}
```

```mermaid
classDiagram
    class Person {
    }
    class Employer {
        - Person employee[100]
        + void hireAnEmployee(Person p)
        + void fireAnEmployee(Person p)
    }
    class Managing {
    }
    Employer --|> Person
    Employer --|> Managing
```



## Take Home

### Homework - Lab 11

你手上已經有了期中 project 的 UML editor 規格書。請分析這個規格書中的所有 terms，然後畫出 class diagram。(此題分數有 20 倍加權)

可以使用任何工具繪製。

#### Terms

`Components`
- `Component/Canvas.java`
- `Component/MenuBar.java`
- `Component/SidePanel.java`

`Listener`
- `Listener/MenuBarListener.java`

`Modes`
- `Mode/CreateLineMode.java`
- `Mode/CreateShapeMode.java`
- `Mode/Mode.java`
- `Mode/SelectMode.java`

`Shapes`
- `Shape/AssociationLine.java`
- `Shape/BasicObj.java`
- `Shape/ClassObj.java`
- `Shape/CompositionLine.java`
- `Shape/GeneralizationLine.java`
- `Shape/Group.java`
- `Shape/Line.java`
- `Shape/Port.java`
- `Shape/Shape.java`
- `Shape/UseCaseObj.java`

`Utils`
- `Utils/RenameObject.java`
- `Utils/Warning.java`

`Views`
- `View/UMLEditor.java`

`Main.java`

#### Class Diagram

Whole class diagram:

![](uml_class_diagram.png)

Views:

![](views.png)

Components:

![](components.png)

Actions:

![](actions.png)

Utils:

![](utils.png)

#### Discussion

1. 畫完全部的流程圖後，真的如助教當時所說的，有些繼承的關係是可以再精進的，尤其是我在畫 components 的時候，components 之間的關係很細分，但是沒有好好使用到多型，很多 class 都根據基底 class 要多宣告一次記憶體，我覺得這可以修正。
2. 在 Views 區塊有大量區域都要宣告 canvas 以及 Action 都需要使用到 canvas 的初始，也就是有太多功能依賴著 canvas 或許我可以把他拉出來變成獨立的 Action 去控制，不然就失去封裝的意義。
3. 我有很多 class 的 variable 一下宣告 public, 一下宣告 protected 但是在 subclass 我又宣告一次，這樣等於沒有善用繼承的結果，是可以修正的。 


#### Reference

- [簡單理解 UML 類別圖](https://misomiso43.medium.com/%E7%B0%A1%E5%96%AE%E7%90%86%E8%A7%A3-uml-%E9%A1%9E%E5%88%A5%E5%9C%96-f0b32a3272c)
- [UML Class Diagram Tutorial](https://www.visual-paradigm.com/guide/uml-unified-modeling-language/uml-class-diagram-tutorial/)
