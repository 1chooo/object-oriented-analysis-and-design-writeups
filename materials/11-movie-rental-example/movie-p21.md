```java
  1 // Refactoring, a First Example, step3, (~p21)
  2
  3 import java.util.*;
  4
  5 public class Movie {
  6   public static final int CHILDRENS = 2;
  7   public static final int REGULAR = 0;
  8   public static final int NEW_RELEASE = 1;
  9
 10   private String _title; // 名稱
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
 32     System.out.println("Refactoring, a First Example, step3");
 33   }
 34 }
 35
 36 class Rental {
 37   private Movie _movie; // 影片
 38   private int _daysRented; // 租期
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
 52
 53   double getCharge() {
 54     double result = 0;
 55     switch (getMovie().getPriceCode()) {
 56       case Movie.REGULAR:
 57         result += 2;
 58         if (getDaysRented() > 2)
 59           result += (getDaysRented() - 2) * 1.5;
 60         break;
 61       case Movie.NEW_RELEASE:
 62         result += getDaysRented() * 3;
 63         break;
 64       case Movie.CHILDRENS:
 65         result += 1.5;
 66         if (getDaysRented() > 3) 
 67           result += (getDaysRented() - 3) * 1.5; 
 68         break; 
 69     }  
 70     return result; 
 71   } 
 72 } 
 73 
 74 class Customer { 
 75   private String _name; // 姓名 
 76   private Vector _rentals = new Vector(); // 租 借 記 錄 
 77 
 78   public Customer(String name) { 
 79     _name = name; 
 80   } 
 81 
 82   public void addRental(Rental arg) { 
 83     _rentals.addElement(arg); 
 84   } 
 85 
 86   public String getName() { 
 87     return _name; 
 88   } 
 89 
 90   public String statement() { 
 91     double totalAmount = 0; // 總消費金額 
 92     int frequentRenterPoints = 0; // 常 客 積 點 
 93     Enumeration rentals = _rentals.elements(); 
 94     String result = "Rental Record for " + getName() + "\n"; 
 95 
 96     while(rentals.hasMoreElements()) { 
 97       double thisAmount = 0; 
 98       Rental each = (Rental) rentals.nextElement(); // 取得一筆租借記錄 
 99 
100       // add frequent renter points(累加 常客積點) 
101       frequentRenterPoints++; 
102       // add bonus for a two day new release rental 
103       if ((each.getMovie().getPriceCode() == Movie.NEW_RELEASE) && 
104           each.getDaysRented() > 1) 
105         frequentRenterPoints++; 
106 
107       // show figures for this rental(顯示此筆租借資料) 
108       result += "\t" + each.getMovie().getTitle() + "\t" + 
109                 String.valueOf(each.getCharge()) + "\n"; 
110       totalAmount += each.getCharge(); 
111     } 
112 
113     // add footer lines(結尾列印) 
114     result += "Amount owed is " + String.valueOf(totalAmount) + "\n"; 
115     result += "You earned " + String.valueOf(frequentRenterPoints) + 
116               " frequent renter points"; 
117     return result; 
118   } 
119 } 
120 
121
```