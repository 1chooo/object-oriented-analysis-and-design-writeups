# Material 10 Lab - An Overview of UML <!-- omit in toc -->

## Table of Contents <!-- omit in toc -->
- [Course](#course)
  - [Lab 01](#lab-01)
  - [Lab 02](#lab-02)
  - [Lab 03](#lab-03)
  - [Lab 04](#lab-04)
  - [Lab 05](#lab-05)
  - [Lab 06](#lab-06)
  - [Lab 07](#lab-07)
  - [Lab 08](#lab-08)
  - [Lab 10](#lab-10)


## Course

### Lab 01

Model 與 Module 有什麼不一樣?

> **My Answer:**
> 
> 模型是小汽車、Module 為專注完成某些功能

### Lab 02

請你舉一種其他工程領域的模型可以用來檢驗設計的正確性。________  
請你舉一種其他工程領域的模型可以用來模擬(可執行的)設計的正確性 __________  

> **My Answer:**
>
> 1. 耐震測試模型
> 2. 真的拿蓋好的樣板下去模擬地震！？

MIS 類別的系統牽涉到流程的 CRUD

### Lab 03

UML class diagram 屬於不嚴謹的 model，這個意思是? 如果是嚴謹又如何?

> **My Answer:**
> 
> 缺乏工具來讓我們知道是好還是壞，需要額外開發工具來告訴我們這個設計是好還是壞

### Lab 04

請解釋什麼是 Modeling process，這個過程的重點是什麼?

> **My Answer:**
> 
> Modeling 在建模，不要動不動就直接去寫 code 可以先做設計上的思維考量在 design 的 level 去驗證概念是否是對的，對付複雜度很高的情況
> 
> Model 是可以 run 可以動起來的

### Lab 05

Simulation 是什麼意思?

> **My Answer:**
>
> 去驗證我們的模型可執行與否

### Lab 06

目前的發現，能夠用 UML tool 去進行分析需求，繪製 UML diagram 然後從 UML diagram 產生 code template，然後進行加工將系統完成。能夠採取這一套方式來進行開發的系統種類通常是____________________。

> **My Answer:**
>
> CASE tool: more strict to get acceptable codes

### Lab 07

一個 model 如果真的很有用，它應該可以幫你解決什麼問題?

> **My Answer:**
>
> 日後維護、新增功能的成本，並且是可以沿用的

### Lab 08

請按照穩定性(少變動)從最高到最低排列以下的東西

User interface  
Object classes  
Object behaviors  
Object attributes  

> **My Answer:**
>
> Object class  
> Object attributes  
> Object behaviors  
> Object interface

### Lab 10

當我看到 switch 的程式碼結構，想當然耳，我就把這片程式碼改寫成多型。請問這背後有什麼問題?

> **My Answer:**
>
> 如果這部分的程式碼跟常理的 Class 設計無關，而需要硬寫成 class 取代 switch 的話，完全是多餘的

如果是跟未來擴充無關的話，這就叫做 over designed!