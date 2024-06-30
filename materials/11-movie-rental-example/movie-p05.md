```java
  1 // Refactoring, a First Example, step1, (~p5)
  2
  3 import java.util.*;
  4 =========================================================================
  5 public class Movie {
  6     public static final int CHILDRENS = 2;
  7     public static final int REGULAR = 0;
  8     public static final int NEW_RELEASE = 1;
  9
 10     private String _title; // 名 稱
 11     private int _priceCode; // 價 格
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
 32         System.out.println("Refactoring, a First Example, step1");
 33
 34         Movie m1 = new Movie("Seven", Movie.NEW_RELEASE);
 35         Movie m2 = new Movie("Terminator", Movie.REGULAR);
 36         Movie m3 = new Movie("Star Trek", Movie.CHILDRENS);
 37
 38         Rental r1 = new Rental(m1, 4);
 39         Rental r2 = new Rental(m1, 2);
 40         Rental r3 = new Rental(m3, 7);
 41         Rental r4 = new Rental(m2, 5);
 42         Rental r5 = new Rental(m3, 3);
 43
 44         Customer c1 = new Customer("jjhou");
 45         c1.addRental(r1);
 46         c1.addRental(r4);
 47
 48         Customer c2 = new Customer("gigix");
 49         c2.addRental(r1);
 50         c2.addRental(r3);
 51         c2.addRental(r2);
 52
 53         Customer c3 = new Customer("jiangtao");
 54         c3.addRental(r3);
 55         c3.addRental(r5);
 56
 57         Customer c4 = new Customer("yeka");
 58         c4.addRental(r2);
 59         c4.addRental(r3);
 60         c4.addRental(r5);
 61
 62         System.out.println(c1.statement());
 63         System.out.println(c2.statement());
 64         System.out.println(c3.statement());
 65         System.out.println(c4.statement());
 66     }
 67 }
 68 ==================================================================== 
 69 class Rental { 
 70     private Movie _movie; // 影片 
 71     private int _daysRented; // 租期 
 72
 73     public Rental(Movie movie, int daysRented) { 
 74         _movie = movie; 
 75         _daysRented = daysRented; 
 76     }
 77
 78     public int getDaysRented() { 
 79         return _daysRented; 
 80     }
 81
 82     public Movie getMovie() { 
 83         return _movie; 
 84     }
 85 }
 86 ==================================================================== 
 87 class Customer { 
 88     private String _name; // 姓名 
 89     private Vector _rentals = new Vector(); // 租借記錄 
 90
 91     public Customer(String name) { 
 92         _name = name; 
 93     }
 94
 95     public void addRental(Rental arg) { 
 96         _rentals.addElement(arg); 
 97     }
 98
 99     public String getName() { 
100         return _name; 
101     }
102
103     public String statement() { 
104         double totalAmount = 0; // 總消費金額 
105         int frequentRenterPoints = 0; // 常客積點 
106         Enumeration rentals = _rentals.elements(); 
107         String result = "Rental Record for " + getName() + "\n"; 
108
109         while(rentals.hasMoreElements()) { 
110             double thisAmount = 0; 
111             Rental each = (Rental) rentals.nextElement(); // 取得一筆租借記錄 
112
113             // determine amounts for each line 
114             switch(each.getMovie().getPriceCode()) { // 取 得 影 片 出 租 價 格 
115                 case Movie.REGULAR: // 普通片 
116                     thisAmount += 2; 
117                     if(each.getDaysRented() > 2) 
118                         thisAmount += (each.getDaysRented() - 2) * 1.5; 
119                     break; 
120
121                 case Movie.NEW_RELEASE: // 新片 
122                     thisAmount += each.getDaysRented() * 3; 
123                     break; 
124
125                 case Movie.CHILDRENS: // 兒童片 
126                     thisAmount += 1.5; 
127                     if(each.getDaysRented() > 3) 
128                         thisAmount += (each.getDaysRented() - 3) * 1.5; 
129                     break; 
130             } 
131
132             // add frequent renter points(累加 常客積點)
133             frequentRenterPoints++; 
134             // add bonus for a two day new release rental 
135             if ((each.getMovie().getPriceCode() == Movie.NEW_RELEASE) && 
136                 each.getDaysRented() > 1) 
137                 frequentRenterPoints++;
138 
139             // show figures for this rental(顯示此筆租借資料) 
140             result += "\t" + each.getMovie().getTitle() + "\t" + 
141                       String.valueOf(thisAmount) + "\n"; 
142             totalAmount += thisAmount;
143         }
144 
145         // add footer lines(結尾列印) 
146         result += "Amount owed is " + String.valueOf(totalAmount) + "\n";
147         result += "You earned " + String.valueOf(frequentRenterPoints) + 
148                   " frequent renter points"; 
149         return result;
150     }
151 }
152
```

> [!NOTE]
>
> 開始有問題了，用 line 49 又用了一次 r1

> [!NOTE]
> Take a look at `print_statement`
> 
> Image a future change – customer wants a new function called htmlStatement()
> 1. You will find you cannot reuse any code in p05 formally. 
> 2. Eventually, you copy-paste statement() and modify it into a new htmlStatement()
> 3. Some time in the future, you need to change the rule of computing frequent renter points
> 
> You need to change two places and maintain the consistency at two places.
> 
> 👉🏻 139 - 149 需要 copy paste
