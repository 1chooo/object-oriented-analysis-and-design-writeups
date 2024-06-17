```java
  1 // Refactoring, a First Example, step5, (~p33)
  2
  3 import java.util.*;
  4
  5 public class Movie {
  6     public static final int CHILDRENS = 2;
  7     public static final int REGULAR = 0;
  8     public static final int NEW_RELEASE = 1;
  9
 10     private String _title; // 名稱
 11     private int _priceCode; // 價格
 12
 13     public Movie(String title, int priceCode) {
 14         _title = title;
 15         _priceCode = priceCode;
 16     }
 17
 18     public int getPriceCode() {
 19         return _priceCode;
 20     }
 21
 22     public void setPriceCode(int arg) {
 23         _priceCode = arg;
 24     }
 25
 26     public String getTitle() {
 27         return _title;
 28     }
 29
 30     // jjhou add
 31     public static void main(String[] args) {
 32         System.out.println("Refactoring, a First Example, step5");
 33     }
 34
 35 }
 36
 37 class Rental {
 38     private Movie _movie; // 影片
 39     private int _daysRented; // 租期
 40
 41     public Rental(Movie movie, int daysRented) {
 42         _movie = movie;
 43         _daysRented = daysRented;
 44     }
 45
 46     public int getDaysRented() {
 47         return _daysRented;
 48     }
 49
 50     public Movie getMovie() {
 51         return _movie;
 52     }
 53
 54     double getCharge() {
 55         double result = 0;
 56         switch (getMovie().getPriceCode()) {
 57             case Movie.REGULAR:
 58                 result += 2;
 59                 if (getDaysRented() > 2)
 60                     result += (getDaysRented() - 2) * 1.5;
 61                 break;
 62             case Movie.NEW_RELEASE:
 63                 result += getDaysRented() * 3;
 64                 break;
 65             case Movie.CHILDRENS:
 66                 result += 1.5;
 67                 if (getDaysRented() > 3)
 68                     result += (getDaysRented() - 3) * 1.5;
 69                 break;
 70         }
 71         return result;
 72     }
 73
 74     int getFrequentRenterPoints() {
 75         if ((getMovie().getPriceCode() == Movie.NEW_RELEASE) 
 76                 && getDaysRented() > 1)
 77             return 2;
 78         else
 79             return 1;
 80     }
 81 }
 82
 83 class Customer {
 84     private String _name; // 姓名
 85     private Vector _rentals = new Vector(); // 租 借 記 錄
 86
 87     public Customer(String name) {
 88         _name = name;
 89     }
 90
 91     public void addRental(Rental arg) {
 92         _rentals.addElement(arg);
 93     }
 94
 95     public String getName() {
 96         return _name;
 97     }
 98
 99     public String statement() {
100         Enumeration rentals = _rentals.elements();
101         String result = "Rental Record for " + getName() + "\n";
102
103         while (rentals.hasMoreElements()) {
104             Rental each = (Rental) rentals.nextElement();
105
106             // show figures for this rental
107             result += "\t" + each.getMovie().getTitle() + "\t" + 
108                     String.valueOf(each.getCharge()) + "\n";
109         }
110
111         // add footer lines( 結 尾 列 印 )
112         result += "Amount owed is " + 
113                 String.valueOf(getTotalCharge()) + "\n";
114         result += "You earned " + 
115                 String.valueOf(getTotalFrequentRenterPoints()) + 
116                 " frequent renter points";
117         return result;
118     }
119
120     public String htmlStatement() {
121         Enumeration rentals = _rentals.elements();
122         String result = "<H1>Rentals for <EM>" + getName() + 
123                 "</EM></H1><P>\n";
124         while (rentals.hasMoreElements()) {
125             Rental each = (Rental) rentals.nextElement();
126             // show figures for each rental
127             result += each.getMovie().getTitle() + ": " + 
128                     String.valueOf(each.getCharge()) + "<BR>\n";
129         }
130         // add footer lines
131         result += "<P>You owe <EM>" + 
132                 String.valueOf(getTotalCharge()) +
133                 "</EM><P>\n";
134         result += "On this rental you earned <EM>" +
135                 String.valueOf(getTotalFrequentRenterPoints()) + 
136                 "</EM> frequent renter points<P>";
137         return result;
138     }
139
140     // 譯註:此即所謂query method
141     private int getTotalFrequentRenterPoints() {
142         int result = 0;
143         Enumeration rentals = _rentals.elements();
144         while (rentals.hasMoreElements()) {
145             Rental each = (Rental) rentals.nextElement();
146             result += each.getFrequentRenterPoints();
147         }
148         return result;
149     }
150
151     // 譯註:此即所謂query method
152     private double getTotalCharge() {
153         double result = 0;
154         Enumeration rentals = _rentals.elements();
155         while (rentals.hasMoreElements()) {
156             Rental each = (Rental) rentals.nextElement();
157             result += each.getCharge();
158         }
159         return result;
160     }
161 }
```