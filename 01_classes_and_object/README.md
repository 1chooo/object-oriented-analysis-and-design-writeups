# Material01 - Classes and Object

### What is a class ?

- class is just a type
- When you define a class X，you pass another X.h to be included by others.
- Without X.obj, it is still possible for others to compile his module.
- In C++, a class is just like a primitive type INT, CHAR

### What is an object?

- When you use a class to create a variable, the variable (along with its allocated memory) is called an object
- A class can have many objects
- Each object has its own memory
- Object is simply memory + behaviors (code)

```cpp
class Point {
          int z ;
    public:
          int x ;
          int y ;
};

Point  p,p1 ;
main() {
     p.x = 100;
     p.y = 200 ;
}
```

規格與定義是分開的

- 規格 class
- 定義 code (behavior)

### 執行檔案載入記憶體中的位置

`sbrk()`: use to find the initial address of the heap [^1]

```
+----------------------+
|       Data           |  <- Global Variable
+----------------------+
|      SysCode         |
+----------------------+
| Heap (top to bottom) |  <- If too much is allocated, it encounters Stack -> Out of Memory (Memory Leak)
|         ...          |
|                      |
|                      |
|         ...          |
| Stack (bottom to top)|  <- If too much is allocated, it encounters Heap -> Stack Overflow
+----------------------+
|       Kernel         |
+----------------------+
```

#### What's Heap?

- Heap in a process’s image (let’s rock)
- In `C`
  - use `malloc`, `calloc`, `free`
- In `C++`,
  - use `new`, `delete`
  - Be aware of **memory leaking**

Just like C, you have 3 places to place your object

- data (life time goes with program)
- stack (life time goes with functions)
- heap (life time vary)

### Exercise

What's wrong with the following code?

```cpp
Car* foo() {
    Car  mazda ;
        :
        :
    return &mazda ;
}
```

這個程式中有一個潛在的問題是，函數`foo()`嘗試返回一個指向本地變量`mazda`的指針。當函數返回時，本地變量`mazda`將被銷毀，這將導致返回的指針指向一個已經無效的內存位置。這可能導致未定義的行為，例如訪問無效的內存或崩潰。

要解決這個問題，可以通過動態分配內存來創建一個`Car`對象，並在返回指針之前確保不要在函數結束時銷毀該對象。例如，可以使用`new`運算符來動態分配內存，然後在不再需要時使用`delete`來釋放內存。下面是修正的示例：

```cpp
Car* foo() {
    Car* mazda = new Car();
    // 對 mazda 做一些操作
    return mazda;
}
```

在這個修正版本中，返回的是一個指向堆上動態分配的`Car`對象的指針，而不是指向本地變量。這樣可以確保在函數返回後該對象仍然存在，並且指針仍然有效。當不再需要時，應該通過`delete`來釋放內存，以避免內存泄漏。

---

## Dynamic Memory Allocation

這十個 `tbl` 一定有一個 `Table` 是沒有參數的建構子 `Table :: Table()`，否則會有 Compiler Error。
```cpp
Table tbl[10];  // constructor Table() will be called 10 times

delete[] tbl ;
```

```cpp
int *IDpt = new int;            // (in C) int *IDpt = malloc(sizeof(int));
float *theMoney = new float; 
char *letter = new char; 
```

The "new" operator returns the address to the start of the allocated block of memory. This address must be stored in a pointer. New allocates a block of space of the appropriate size in the heap for the object. Dynamically allocated memory is accessed indirectly via a pointer. It is possible for new to fail. This will be the case if no memory is available. In this case new throw a `bad_alloc` exception. Exception handling will be discussed in a latter lesson. 


```cpp
int *IDpt = new int; 
*IDpt = 5;  
int *IDpt = new int(5);         // Allocates an int object and initializes it to value 5. 
char *letter = new char('J'); 
```

```cpp
delete IDpt; 
delete theMoney; 
delete letter; 
```


### Dynamic allocated array

```cpp
int *pt = new int[1024];    //allocates an array of 1024 ints
double *myBills = new double[10000];

int *pt = new int[1024];    //allocates an array of 1024 ints
int *pt = new int(1024);    //allocates a single int with value 1024 
```

A dynamically allocated array is best initialized using a loop, as follows. 

```cpp
int *buff = new int[1024]; 
for (i = 0; i < 1024; i++) { 
    buff[i] = 52; 	// Assigns 52 to each element; 
    buff++; 
}
```

free the dynamic allocated objects

```cpp
delete[] pt; 
delete[] myBills;   // chapter11() will also release the memory :-)  
```


### (UNKNOWN) Copy constructor and `=` operator [LAB 03](#lab-03)

```cpp
#include <iostream>
using namespace std;
class Table
{
    char *p;
    int sz;

public:
    Table(int s = 15)
    {
        p = new char[100];
        cout << "constructor" << endl;
    }
    ~Table()
    {
        delete[] p;
        cout << "destructor" << endl;
    }
};
void h()
{
    Table t1;
    Table t2 = t1;
    Table t3;
    t3 = t2;
}
int main()
{
    h();

    return 0;
}
```

- How many times the default constructor is called? 請問Table預設的建構式被呼叫了幾次？

- How many times the default destructor is called ? (Table 的解構式被呼叫了幾次？)

- What is the final output?


#### 絕大部分的情況下「`copy`」 operator 與「`=`」 operator 有很大的不同

根本的原因: `copy` operator 會初始化一塊未經初始化的記憶體，而 `=` operator 必須妥善處理一個已經建構好的的物件



---

### Lab 02
Please answer what’s wrong with the following code
```cpp
Car * foo() {
    Car  mazda ;
    ...
    return &mazda ;
}
```

- My Ans: dangling pointer, Car mazda 要用 new 的方式！
- Prof Ans: 怕 mazda 是 local variable 怕把 stack return 到上一層，return 會清除掉，如果內容物讓上層去存取，可能 run 一 run 會當掉，因為 mazda 已經被清掉了。


### Lab 03
```cpp
#include <iostream>
using namespace std ;
class Table {
    char *p ;
    int sz ;
public:
    Table(int s=15) { 
        p = new char[100] ;
        cout << "constructor" << endl ;
         } 
    ~Table() { delete[] p ; 
      cout << "destructor" << endl ; 
      }
};
void h() {
    Table t1 ;      // Default constructor is called
    Table t2 = t1 ; // No Default constructor is called，compiler default is called
    Table t3 ;      // Default constructor is called
    t3 = t2 ;       // No constructor, deconstructor is called
}
main() { h(); }     // Destructor is called three times
```


- How many times the default constructor is called? 
- How many times the default destructor is called?
- What is the final output? And why?


My Ans:
1. 2 times 
2. 1 time 
3. malloc: Double free of object

## Lab 04

請用你的語言，向我們解釋object和class的不同之處。不限制語言，能表達你的論點即可。

My Ans:
- What is a class ? (一個 type)
  - class is just a type
  - When you define a class X，you pass another X.h to be included by others.
  - Without X.obj, it is still possible for others to compile his module.
  - In C++, a class is just like a primitive type INT, CHAR

- What is an object? (有記憶體的變數)
  - When you use a class to create a variable, the variable (along with its allocated memory) is called an object
  - A class can have many objects
  - Each object has its own memory
  - Object is simply memory+behaviors (code)


### Lab 05

在設計class時，你覺得什麼情況需要由程式設計師提供解構子(destructor)？

My Ans:

如個 class 裡面有用到 stack 跟 heap 的 segment 的時候，需要去主動去釋出，以避免佔用過多的記憶體導致 stack overflow, out of memory

Prof Ans:

```cpp
class OO {
    int a[1000];    // 4000 byte
    int b;          // 4 byte
    char abc;       // 1 byte
    char *p;        // 這裡就額外配置動態記憶體
}
```

### Lab 06

請問，一個 class 的 destructor 何時會被呼叫？

- My Ans:

    function 結束的時候需要被 clear 掉的時後

- Prof Ans:

    如果物件是 local variable，如果程式需要主動 delete，用 class 來宣告 global variable，程式結束的時候會被呼叫


### Lab 08

什麼時候 copy constructor 會被呼叫？ 請用一句話來說明。

- (WRONG) My Ans:

  `copy` operator 會初始化一塊未經初始化的記憶體

- Prof Ans:

```cpp
OO y = x;
OO y;
```


### Lab 10

copy constructor 與 assign operator 有什麼不同？

- My Ans: 
    `copy` constructor 會初始化一塊未經初始化的記憶體 (牽涉到一個新的變數或物件的建立)，而 `=` operator 必須妥善處理一個已經建構好的的物件 (`=` 沒有)


### Lab 13

In C++, you can still use pass-by-value to pass an object to a function, such as:


```cpp
void foo(X a) {
    …….
}

main() {
    X b ;
    foo(b);
}
```

Please explain
1. how C++ compiler implement the pass-by-value for you.
2. why it is not recommended to use pass-by-value to pass an object?

- My Ans:
1. b 的 address 會給到 a 
2. 因為在 C++ 中會建立兩個 a, b 的兩個記憶體段，因此不建議直接這樣共用

- Prof Ans:
`object size = 100 bytes`

`Python/JAVA`
```
int x;      // 4 byte
object x;   // 宣告時只會有一個指標，不會配置記憶體空間
```

`C++`
```cpp
int x;      // 4 byte
object x;   // 會直接配置記憶體空間
```

在 `C++` 叫做 **Pass by Value**，在 `Python` 叫做 **Pass by Reference**

呼叫 `foo()` 會 copy 一份 constructor 會複製一段到 `Stack`


[^1]: [系统调用与内存管理 (`sbrk、brk、mmap、munmap`)](https://blog.csdn.net/Apollon_krj/article/details/54565768)
