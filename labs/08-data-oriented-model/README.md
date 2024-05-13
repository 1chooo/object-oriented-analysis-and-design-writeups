# Material 08 Lab - Data Oriented Model

## Course 

### Lab 01

1. 物件導向的 class   
  等同於database 的 _______________  
  等同於ERD 的 _________________  
2. 物件導向的 object  
  等同於 database 的 ______________  
  等同於 ERD 的 __________________  

> **My Answer**
> 1. Record
> 2. Entity

### Lab 02

Ada 是一個美國軍方設計的程式語言，想要用來解決軟體工程問題。寫Ada 的程式，你必須要把程式分成兩塊。請問這兩塊跟C++的類比是?

> **My Answer**
> 
> `.cpp` 叫做實作的部分跟 `.h` 叫做宣告的部分

### Lab 03

人類第一個物件導向語言的開發單位是?

> **My Answer**
> 
> 矽谷加州的 Simula smalltalk

### Lab 04

軟體工程與程式語言(PL)的專家走了許多 procedure-oriented 的冤枉路。最後回過頭發現 database 的人早就發現的東西。這個東西是?

> **My Answer**
> 
> 正規化，以資料為中心才是重點

### Lab 05

我在影片中說，如果你真正要我信服你懂物件導向，你要說的一兩句話是什麼?

> **My Answer**
> 
> 把資料搞對、辨識出系統未來需要的擴充，開始建立一些 class diagram 去預測未來需要的擴充透過繼承多型去做成 subclass

### Lab 06

所謂的 association 是一個 ____詞。它通常是database table 之間的 ______key

> **My Answer**
>
> 1. 動
> 2. foreign


### Lab 08

Methodology (方法論) 是什麼東西? 為什麼我們需要它

> **My Answer**
> 
> 我們需要個可以通用設計的要素。以做一件事情，每個人來做差異都很大的話叫做沒有方法，因此各個領域都有所謂的方法論，可能可以做到八九不離十，甚至其他人來做也會差不多

## Take Home

### Homework - Lab 07

以下的程式有什麼問題? 你要怎麼修改?

```cpp
class product {
  int pno ;
  
  vector<customer *> customers ;
}

class customer {
  int cno ;
  string name ;
  vector<product *> products ;
```

### Homework - Lab 09

請針對投影片最後一頁的問題進行分析，然後請以 UML 作答 (以舊的ERD diagram作答 一律0分)


