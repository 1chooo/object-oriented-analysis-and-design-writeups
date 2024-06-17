```java
  1  // Refactoring, a First Example, step4, (~p25)
  2  
  3  import java.util.*;
  4  
  5  public class Movie {
  6      public static final int CHILDRENS = 2;
  7      public static final int REGULAR = 0;
  8      public static final int NEW_RELEASE = 1;
  9  
 10     private String _title; // 名稱
 11     private int _priceCode; // 價格
 12 
 13     public Movie(String title, int priceCode){
 14         _title = title;
 15         _priceCode = priceCode;
 16     }
 17 
 18     public int getPriceCode(){
 19         return _priceCode;
 20     }
 21 
 22     public void setPriceCode(int arg){
 23         _priceCode = arg;
 24     }
 25 
 26     public String getTitle(){
 27         return _title;
 28     }
 29 
 30     // jjhou add
 31     public static void main(String[] args) {
 32         System.out.println("Refactoring, a First Example, step4");
 33     }
 34 }
 35 
 36 class Rental {
 37     private Movie _movie; // 影片
 38     private int _daysRented; // 租期
 39 
 40     public Rental(Movie movie, int daysRented) {
 41         _movie = movie;
 42         _daysRented = daysRented;
 43     }
 44 
 45     public int getDaysRented() {
 46         return _daysRented;
 47     }
 48 
 49     public Movie getMovie() {
 50         return _movie;
 51     }
 52 
 53     double getCharge() {
 54         double result = 0;
 55         switch (getMovie().getPriceCode()) {
 56             case Movie.REGULAR:
 57                 result += 2;
 58                 if (getDaysRented() > 2)
 59                     result += (getDaysRented() - 2) * 1.5;
 60                 break;
 61             case Movie.NEW_RELEASE:
 62                 result += getDaysRented() * 3;
 63                 break;
 64             case Movie.CHILDRENS:
 65                 result += 1.5;
 66                 if (getDaysRented() > 3)
 67                     result += (getDaysRented() - 3) * 1.5;
 68                 break;
 69         }
 70         return result;
 71     }
 72 
 73     int getFrequentRenterPoints() {
 74         if ((getMovie().getPriceCode() == Movie.NEW_RELEASE) 
 75             && getDaysRented() > 1)
 76             return 2;
 77         else
 78             return 1;
 79     }
 80 }
 81 
 82 class Customer {
 83     private String _name; // 姓名
 84     private Vector _rentals = new Vector(); // 租 借 記 錄
 85 
 86     public Customer(String name) {
 87         _name = name;
 88     }
 89 
 90     public void addRental(Rental arg) {
 91         _rentals.addElement(arg);
 92     }
 93 
 94     public String getName() {
 95         return _name;
 96     }
 97 
 98     public String statement() {
 99         double totalAmount = 0; // 總消費金額
100        int frequentRenterPoints = 0; // 常 客 積 點
101        Enumeration rentals = _rentals.elements();
102        String result = "Rental Record for " + getName() + "\n";
103 
104        while(rentals.hasMoreElements()) {
105            double thisAmount = 0;
106            Rental each = (Rental) rentals.nextElement(); // 取得一筆租借記錄
107 
108            frequentRenterPoints += each.getFrequentRenterPoints();
109 
110            // show figures for this rental(顯示此筆租借資料)
111            result += "\t" + each.getMovie().getTitle() + "\t" + 
112                      String.valueOf(each.getCharge()) + "\n";
113            totalAmount += each.getCharge();
114        }
115 
116        // add footer lines(結尾列印)
117        result += "Amount owed is " + String.valueOf(totalAmount) + "\n";
118        result += "You earned " + String.valueOf(frequentRenterPoints) +
119                  " frequent renter points";
120        return result;
121    }
122 }
```