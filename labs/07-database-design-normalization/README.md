# Material 07 Lab - Database Design and Normalization <!-- omit in toc -->

**Table of Contents**
- [Course](#course)
  - [Lab 01](#lab-01)
  - [Lab 02](#lab-02)
  - [Lab 03](#lab-03)
  - [Lab 04](#lab-04)
  - [Lab 07](#lab-07)
  - [Lab 08](#lab-08)
- [Take Home](#take-home)
  - [Homework - Lab 05 (三倍)](#homework---lab-05-三倍)
  - [Homework - Lab 06](#homework---lab-06)
  - [Homework - Lab 09](#homework---lab-09)
  - [Homework - Lab 10](#homework---lab-10)
  - [Homework - Lab 11](#homework---lab-11)

## Course 

### Lab 01

資料庫的 foreign key 是什麼意思?

> **My Answer:**
>
> 用來關聯其他 Table 的 key。某個欄位識別的欄位的 Primary Key。

### Lab 02

什麼是正規化 (Normalization) ?  請用一句話解釋。

> **My Answer:**
>
> 是把 database 結構化的過程，以達到要擴充只要改一個地方就好，底層不用動

把一堆資料彼此的相依性，欄位隸屬於哪個 Table 的過程就是正規化。

### Lab 03

請問在資料庫的實作中，如果沒有正規劃好，通常系統會有什麼問題?

> **My Answer:**
>
> 我們要 query 的時候，要撰寫很多的程式邏輯，才有辦法得到我們要的內容，另外要新增內容的時候，也會被原先的設計限制。

### Lab 04

正規化的 NF (Normal Form) 是一種非常精準的數學定義，放諸四海皆標準嗎?  是或不是?  如果不是為何? 請說明。

> **My Answer:**
>
> 不是，未必皆標準。
> 
> 因為在不同的生活經驗有可能會有不同的經驗，就如同老師上課的範例，如果今天銷售對應的從原本的顧客，變成訂單編號，那資料庫的 Table 設計就合理了！因此 Normal Form 的標準應該是能夠針對 Case 去做應應設計。

### Lab 07

Normalization 的結果越高，
- (A) 通常有什麼好處?
- (B) 通常有什麼壞處?

> **My Answer:**
> - (A) 好處是我們可以在未來的改動中，固定我們的底層邏輯，同時也可以避免掉需要撰寫大量程式邏輯來取用 DataBase 的內容。
> - (B) 在設計的時候需要耗費大量的開發成本。

- 任何的 query 都可以在 Table 之間用 Database 的關聯性來取得，而不需要撰寫大量的程式邏輯。
- 在查詢簡單的問題的時候，可能本來很相近的資料，因為設計的考量會被拆成兩個 Table，這樣就會變得很複雜。效率會變差

### Lab 08

DataBase 的 JOIN operation 是怎麼一回事? 請用你自己的文字來解釋。

> **My Answer:**
>
> 當我們今天要透過 foriegn key 去關聯其他 Table 的資訊的時候，我們可以用 Join 來實現。



## Take Home


### Homework - Lab 05 (三倍)

請打開投影片的最後一頁，並且完成該作業。我會在現場當個誠實又精準的客戶回答你的問題。

(20 marks) 假設你負責分析一個系統，此系統的資料包含了下面許多欄位  
Please analyze a system which contains the following attributes

```
S#:     零件供應商的編號 (Supplier no)
SNAME:  零件供應商的姓名 (supplier name)
CITY1   零件供應商的城市 (The city of a supplier) 
P#      零件編號  (part no.)
PNAME   零件名稱 (part name)
COLOR   零件色彩 (part color)
WEIGHT  零件重量  (part weight)
CITY2   零件所儲存的城市 (city where the parts are stored)
QTY     零件的存量 (The quantity of the parts)
```

In your analysis, you found that a part can be supplied by several suppliers. Please determine how many tables should be used and what is the content of each table.  
在你分析的過程中，你發現一個零件可能有多個供應商可以供應。請簡單說明這樣一個資料庫系統，你要用幾個表格，每個表格的屬性又為何？


零件是輪胎、輪胎供應商管理系統、各種供應商、輪胎店

比如從米其林輪胎進口，有各種不同的規格跟標價，有些輪胎會在南港輪胎有個倉庫，也有些輪胎會在鎮馨輪胎會有倉庫。

Only for 大盤商要用的系統
1. 老師是大盤商，從國外進口輪胎，有各種不同的規格跟標價。輪胎就直接到供應商了！
   - 會知道輪胎在哪個倉庫，在哪個輪胎供應商，賣給哪個車行。
2. 會把輪胎給輪胎供應商，輪胎供應商會有自己的倉庫。
   - 有些輪胎會在南港輪胎、正新輪胎供應商，供應商有自己的倉庫。
3. 供應商的目的是要把輪胎賣給路邊的車行。


> **My Answer:**
> 
> Supplier Table
> | S# | SNAME | CITY1 |
> |----|-------|-------|
> 
> Part Table
> | P# | PNAME | COLOR | WEIGHT | CITY2 | QTY |
> |----|-------|-------|--------|-------|-----|
> 
> Relation Suplier between Part Table
> | S# | P# | CITY2 | QTY |
> |----|----|-------|-----|
> 
> ```mermaid
> ---
> title: Supplier supplies Part
> ---
> classDiagram
>     note "Author: Hugo"
>     direction LR
>     Supplier "1" --> "*" SupplyRelation: Supplies
>     Part "1" --> "*" SupplyRelation: Supplies
>     Supplier: *S#
>     Supplier: SNAME
>     Supplier: CITY1
>     Part: *P#
>     Part: PNAME
>     Part: COLOR
>     Part: WEIGHT
>     Part: CITY2
>     Part: QTY
>     SupplyRelation: *S#
>     SupplyRelation: *P#
>     SupplyRelation: Quantity
>     SupplyRelation: City2
> ```

### Homework - Lab 06

當你完成投影片最後一頁的作業。請把你完成的 DB table 改寫成物件導向的 class。

> **My Answer:**
> 
> ```cpp
> class Supplier;
> class Part;
> 
> class Relation {
> public:
>     int SNum;
>     int PNum;
>     std::string City;
>     int Qty;
> 
>     Supplier* supplier;
>     Part* part;
> };
> 
> class Supplier {
> public:
>     int SNum;
>     std::string SName;
>     std::string City;
>     std::vector<Relation*> relations;
> };
> 
> class Part {
> public:
>     int PNum;
>     std::string PName;
>     std::string Color;
>     float Weight;
>     std::string City;
>     int Qty;
>     std::vector<Relation*> relations;
> };
> ```

**feedback from TA:**

1. 零件本身不應直接儲存數量，數量的職責應屬於供應商
2. 零件與供應商的關係不應寫在 class Part 中，在 你的 relation 中允許輸入 part id 與 Supplier id，但是若將 relation 儲存至 class Part 中，是否意味著欄位 part id 只能儲存自己的 id？因為儲存的若非自己的 id，relations 欄位與 Part 就不存在相依性，也就是說，relations 就不與 Part 高度相關（Color、Weight 都是 class Part 的一部分，但儲存了別人 id 的 relation 算嗎？）；反之，若 relations 欄位只能儲存關於自己的零件關係，是否意味著 class Relation 就不應該儲存 part id，因為 part id 永遠是同一個（自己的），part id 將變成冗餘數據。因此將 relation 欄位儲存至 class Part 中不合適。

```cpp
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
```

做了以下修正：
1. 將零件數量的管理回歸到供應商
2. Relation 不會儲存 part id，進而透過 relation 去達成零件與供應商的關聯
3. 當初沒有封裝的實作，這些成員間應當使用 private 來保護，之後如要取用可以用 `get` 的方式來取得
4. 另外 `Supplier`, `Part` 的 Relation 改用 pointer 來儲存，並免有同一筆字料過度的關聯產生。


### Homework - Lab 09

有一個老師，要出許多作業給學生，但是每個學生在每一次的作業要做的內容都不太一樣。如範例顯示，

學生 Jeff Smith 第一次作業做的是 Article Summary，第二次作業做的是 Poetry analysis。但是 Nancy Jones 第一次作業做的是 Article Summary，第二次作業做的是 Reaction Paper。

這位老師想要用個 DBMS 來管理這些作業。請幫這位老師正規化一下

| Name | Assignment 1 | Assignment 2 |
| ---- | ------------ | ------------ |
| Jeff Smith | Article Summary | Poetry analysis |
| Nancy Jones | Article Summary | Reaction Paper |
| Jane Scott | Article Summary | Poetry analysis |

> **My Answer:**
> 
> Students Table:
> | Student_ID | Name       |
> |------------|------------|
> | 1          | Jeff Smith |
> | 2          | Nancy Jones|
> | 3          | Jane Scott |
> 
> Assignment Table:
> | Assignment_Name | Assignment_ID |
> |-----------------|---------------|
> | Article Summary  | 1             |
> | Poetry analysis  | 2             |
> | Reaction Paper   | 3             |
> 
> Relation Table:
> | Assignment_Number | Student_ID | Assignment_ID |
> |-------------------|------------|---------------|
> | 1                 | 1          | 1             |
> | 2                 | 1          | 2             |
> | 1                 | 2          | 1             |
> | 2                 | 2          | 3             |
> | 1                 | 3          | 1             |
> | 2                 | 3          | 2             |
> 
> ```mermaid
> ---
> title: Student Assignment
> ---
> classDiagram
>     note "Author: Hugo"
>     direction LR
>     Student "1" --> "*" Relation: Has
>     Assignment "1" --> "*" Relation: Has
>     Student: *Student_ID
>     Student: Name
>     Assignment: *Assignment_ID
>     Assignment: Assignment_Name
>     Relation: *Assignment_Number
>     Relation: Student_ID
>     Relation: Assignment_ID
> ```


### Homework - Lab 10

下面的例子，是一個未經正規化的表格。請先用你的 common sense 來理解裡面的名詞。

- A. (Insert Anomaly ) 請問我如果要新增一個 office number 到這個表格的時候，我會遇到什麼問題?
- B. (Deletion Anomaly) 請問如果 John Hunt 退休，我會遇到什麼問題
- C. 請把他正規化，解決上述的問題

**SalesStaff**
| EmployeeID | SalesPerson | SalesOffice | OfficeNumber | Customer1 | Customer2 | Customer3 |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: |
| 1003 | Mary Smith | Chicago | 312-555-1212 | Ford | GM |  |
| 1004 | John Hunt | New York | 212-555-1212 | Dell | HP | Apple |
| 1005 | Martin Hap | Chicago | 312-555-1212 | Boeing |  |  |


> **My Answer:**
> 
> 1. A. 當今天新增了 Office Number 到表格中，其實與其他 attribute 並沒有直接的關聯，有關連的只有 Sales Office，當今天 Sales Person 換辦公室了， Sales Office 也要跟著更換。
> 2. B. 當 John Hunt 退休了，所有跟 John Hunt 的資訊都會被刪除，這樣 Customer 的關聯也可能跟著被刪除。
> 
> SalesStaff Table:
> | EmployeeID | SalesPerson |
> | :-: | :-: |
> | 1003 | Mary Smith |
> | 1004 | John Hunt |
> | 1005 | Martin Hap |
> 
> Sales Office Table:
> | SalesOffice | OfficeNumber |
> | :-: | :-: |
> | Chicago | 312-555-1212 |
> | New York | 212-555-1212 |
> 
> Staff to Office Table:
> | EmployeeID | SalesOffice |
> | :-: | :-: |
> | 1003 | Chicago |
> | 1004 | New York |
> | 1005 | Chicago |
> 
> SalesPersonCustomer Table:
> | EmployeeID | Customer |
> | :-: | :-: |
> | 1003 | Ford |
> | 1003 | GM |
> | 1004 | Dell |
> | 1004 | HP |
> | 1004 | Apple |
> | 1005 | Boeing |
> 
> ```mermaid
> ---
> title: Sales Staff
> ---
> classDiagram
>     note "Author: Hugo"
>     direction LR
>     SalesStaff "1" --> "*" StaffToOffice: Works
>     SalesStaff "1" --> "*" SalesPersonCustomer: Sells
>     SalesOffice "1" --> "*" StaffToOffice: Has
>     SalesStaff: *EmployeeID
>     SalesStaff: SalesPerson
>     SalesOffice: *SalesOffice
>     SalesOffice: OfficeNumber
>     StaffToOffice: *EmployeeID
>     StaffToOffice: *SalesOffice
>     SalesPersonCustomer: *EmployeeID
>     SalesPersonCustomer: *Customer
> ```




### Homework - Lab 11

以下是一個 `customer` 的class。常見學生以下的寫法

```cpp
Class Customer {
   int id ;
   string address ;
   int ProductID[100] ;         // 購買產品的 ID
   int ProductCompanyID[100];   // 購買產品所屬的公司 ID
   bool used[100] ;             // 註記這個陣列的的元素是否已經被用來儲存
}
```

- A. 請先批評一番。
- B. 然後請改寫。


> **My Answer:**
> 
> My judge: 
>    1. 首先，ProductID 是一個固定大小的 array 當今天顧客買的東西大過 100 了，那就會造成錯誤，是要再多開一個 Customer 嗎？還是要再多開一個 array？
>    2. ProductCompany 也是同理，如果很多 ProductID 都來自同一個公司，那要存幾次？
>    3. used 是要依據 ProductID 來判斷的話，那每次都要遍歷整個 array，這樣的效率很差。
> 
> ```cpp
> class Customer {
>     int customerID;
>     string address;
> };
> 
> class Product {
>     int productID;
>     int ProductCompanyID;
> };
> 
> class UsedProduct {
>     int productID;
>     int customerID;
>     bool used;
> };
> ```
> 
> ```mermaid
> ---
> title: Customer Purchase
> ---
> classDiagram
>     note "Author: Hugo"
>     direction LR
>     Customer "1" --> "*" Product: Purchase
>     Product "*" --> "1" UsedProduct: is recorded
>     Customer: *customerID
>     Customer: address
>     Product: *ProductID
>     Product: customerID
>     Product: ProductCompanyID
>     UsedProduct: productID
>     UsedProduct: customerID
>     UsedProduct: used
> ```

