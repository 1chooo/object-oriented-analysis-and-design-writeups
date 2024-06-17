```java
  1  // Refactoring, a First Example, step5, (~p33)
  2  
  3  import java.util.*;
  4  
  5  public class Movie {
  6  public static final int CHILDRENS = 2;
  7  public static final int REGULAR = 0;
  8  public static final int NEW_RELEASE = 1;
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
 34     double getCharge() {
 35         double result = 0;
 36         switch (getMovie().getPriceCode()) {
 37             case Movie.REGULAR:
 38                 result += 2;
 39                 if (getDaysRented() > 2)
 40                     result += (getDaysRented() - 2) * 1.5;
 41                 break;
 42             case Movie.NEW_RELEASE:
 43                 result += getDaysRented() * 3;
 44                 break;
 45             case Movie.CHILDRENS:
 46                 result += 1.5;
 47                 if (getDaysRented() > 3)
 48                     result += (getDaysRented() - 3) * 1.5;
 49                 break;
 50         }
 51         return result;
 52     }
 53 
 54     int getFrequentRenterPoints() {
 55         if ((getMovie().getPriceCode() == Movie.NEW_RELEASE) 
 56                 && getDaysRented() > 1)
 57             return 2;
 58         else
 59             return 1;
 60     }
 61 
 62 }
 63 
 64 class Rental {
 65     private Movie _movie; // 影片
 66     private int _daysRented; // 租期
 67 
 68     public Rental(Movie movie, int daysRented) {
 69         _movie = movie;
 70         _daysRented = daysRented;
 71     }
 72 
 73     public int getDaysRented() {
 74         return _daysRented;
 75     }
 76 
 77     public Movie getMovie() {
 78         return _movie;
 79     }
 80 
 81     double getCharge() {
 82         return _movie.getCharge(_daysRented);
 83     }
 84 
 85     int getFrequentRenterPoints() {
 86         return _movie.getFrequentRenterPoints(_daysRented);
 87     }
 88 }
 89 
 90 class Customer {
 91     private String _name; // 姓名
 92     private Vector _rentals = new Vector(); // 租 借 記 錄
 93 
 94     public Customer(String name) {
 95         _name = name;
 96     }
 97 
 98     public void addRental(Rental arg) {
 99         _rentals.addElement(arg);
100    }
101 
102    public String getName() {
103        return _name;
104    }
105 
106    public String statement() {
107        Enumeration rentals = _rentals.elements();
108        String result = "Rental Record for " + getName() + "\n";
109 
110        while (rentals.hasMoreElements()) {
111            Rental each = (Rental) rentals.nextElement();
112 
113            // show figures for this rental
114            result += "\t" + each.getMovie().getTitle() + "\t" + 
115                    String.valueOf(each.getCharge()) + "\n";
116        }
117 
118        // add footer lines( 結 尾 列 印 )
119        result += "Amount owed is " + 
120                String.valueOf(getTotalCharge()) + "\n";
121        result += "You earned " + 
122                String.valueOf(getTotalFrequentRenterPoints()) + 
123                " frequent renter points";
124        return result;
125    }
126 
127    public String htmlStatement() {
128        Enumeration rentals = _rentals.elements();
129        String result = "<H1>Rentals for <EM>" + getName() + 
130                "</EM></H1><P>\n";
131        while (rentals.hasMoreElements()) {
132            Rental each = (Rental) rentals.nextElement();
133            // show figures for each rental
134            result += each.getMovie().getTitle() + ": " + 
135                    String.valueOf(each.getCharge()) + "<BR>\n";
136        }
137        // add footer lines
138        result += "<P>You owe <EM>" + 
139                String.valueOf(getTotalCharge()) +
140                "</EM><P>\n";
141        result += "On this rental you earned <EM>" +
142                String.valueOf(getTotalFrequentRenterPoints()) + 
143                "</EM> frequent renter points<P>";
144        return result;
145    }
146 
147    // 譯註:此即所謂query method
148    private int getTotalFrequentRenterPoints() {
149        int result = 0;
150        Enumeration rentals = _rentals.elements();
151        while (rentals.hasMoreElements()) {
152            Rental each = (Rental) rentals.nextElement();
153            result += each.getFrequentRenterPoints();
154        }
155        return result;
156    }
157 
158    // 譯註:此即所謂query method
159    private double getTotalCharge() {
160        double result = 0;
161        Enumeration rentals = _rentals.elements();
162        while (rentals.hasMoreElements()) {
163            Rental each = (Rental) rentals.nextElement();
164            result += each.getCharge();
165        }
166        return result;
167    }
168 }
```

