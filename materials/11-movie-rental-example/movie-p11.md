```java
  1 // Refactoring, a First Example, step2, (~p11)
  2
  3 import java.util.*;
  4
  5 public class Movie {
  6   public static final int CHILDRENS = 2;
  7   public static final int REGULAR = 0;
  8   public static final int NEW_RELEASE = 1;
  9
 10   private String _title;  // 名稱
 11   private int _priceCode; // 價格
 12
 13   public Movie(String title, int priceCode){
 14     _title = title;
 15     _priceCode = priceCode;
 16   }
 17
 18   public int getPriceCode(){
 19     return _priceCode;
 20   }
 21
 22   public void setPriceCode(int arg){
 23     _priceCode = arg;
 24   }
 25
 26   public String getTitle(){
 27     return _title;
 28   }
 29
 30   // jjhou add
 31   public static void main(String[] args) {
 32     System.out.println("Refactoring, a First Example, step2");
 33   }
 34 }
 35
 36 class Rental {
 37   private Movie _movie;   // 影 片
 38   private int _daysRented; // 租 期
 39
 40   public Rental(Movie movie, int daysRented) {
 41     _movie = movie;
 42     _daysRented = daysRented;
 43   }
 44
 45   public int getDaysRented() {
 46     return _daysRented;
 47   }
 48
 49   public Movie getMovie() {
 50     return _movie;
 51   }
 52 }
 53
 54 class Customer {
 55   private String _name; // 姓名
 56   private Vector _rentals = new Vector(); // 租 借 記 錄
 57
 58   public Customer(String name) {
 59     _name = name;
 60   }
 61
 62   public void addRental(Rental arg) {
 63     _rentals.addElement(arg);
 64   }
 65
 66   public String getName() { 
 67     return _name;
 68   }
 69 
 70   public String statement() { 
 71     double totalAmount = 0; // 總消費金額
 72     int frequentRenterPoints = 0; // 常客積點
 73     Enumeration rentals = _rentals.elements();
 74     String result = "Rental Record for " + getName() + "\n";
 75
 76     while(rentals.hasMoreElements()) {
 77       double thisAmount = 0;
 78       Rental each = (Rental) rentals.nextElement(); // 取得一筆租借記錄
 79
 80       thisAmount = amountFor(each); // 計算一筆租片費用 
 81  
 82       // add frequent renter points(累加 常客積點) 
 83       frequentRenterPoints++; 
 84       // add bonus for a two day new release rental
 85       if ((each.getMovie().getPriceCode() == Movie.NEW_RELEASE) && 
 86           each.getDaysRented() > 1) 
 87         frequentRenterPoints++;
 88
 89       // show figures for this rental(顯示此筆租借資料) 
 90       result += "\t" + each.getMovie().getTitle() + "\t" +
 91                 String.valueOf(thisAmount) + "\n";
 92       totalAmount += thisAmount;
 93     }
 94
 95     // add footer lines(結尾列印) 
 96     result += "Amount owed is " + String.valueOf(totalAmount) + "\n"; 
 97     result += "You earned " + String.valueOf(frequentRenterPoints) + 
 98               " frequent renter points"; 
 99     return result; 
100   } 
101 
102   private double amountFor(Rental aRental) { // 計 算 一 筆 租 片 費 用 
103     double result = 0; 
104     switch (aRental.getMovie().getPriceCode()) { 
105       case Movie.REGULAR: // 普通片 
106         result += 2; 
107         if (aRental.getDaysRented() > 2) 
108           result += (aRental.getDaysRented() - 2) * 1.5; 
109         break;
110       case Movie.NEW_RELEASE: // 新片 
111         result += aRental.getDaysRented() * 3; 
112         break; 
113       case Movie.CHILDRENS: // 兒童片
114         result += 1.5; 
115         if (aRental.getDaysRented() > 3) 
116           result += (aRental.getDaysRented() - 3) * 1.5;
117         break; 
118     } 
119     return result;
120   }
121 }
```