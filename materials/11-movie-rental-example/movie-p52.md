```java
  1 // Refactoring, a First Example, step7, (~p52)
  2
  3 import java.util.*;
  4
  5 public class Movie {
  6     public static final int CHILDRENS = 2;
  7     public static final int REGULAR = 0;
  8     public static final int NEW_RELEASE = 1;
  9
 10     private String _title;        // 名稱
 11     private Price _price;         // 價格   // <-- changed
 12
 13     public Movie(String title, int priceCode){
 14         _title = title;
 15         setPriceCode(priceCode);
 16     }
 17
 18     public int getPriceCode(){
 19         return _price.getPriceCode();   // <-- changed
 20     }
 21
 22     public void setPriceCode(int arg) {   // <-- changed
 23         switch (arg) {
 24             case REGULAR:               // 普通片
 25                 _price = new RegularPrice();
 26                 break;
 27             case CHILDRENS:             // 兒童片
 28                 _price = new ChildrensPrice();
 29                 break;
 30             case NEW_RELEASE:           // 新片
 31                 _price = new NewReleasePrice();
 32                 break;
 33             default:
 34                 throw new IllegalArgumentException("Incorrect Price Code");
 35         }
 36     }
 37
 38     public String getTitle(){
 39         return _title;
 40     }
 41
 42     // jjhou add
 43     public static void main(String[] args) {
 44         System.out.println("Refactoring, a First Example, step7");
 45
 46         Movie m1 = new Movie("Seven", Movie.NEW_RELEASE);
 47         Movie m2 = new Movie("Terminator", Movie.REGULAR);
 48         Movie m3 = new Movie("Star Trek", Movie.CHILDRENS);
 49
 50         Rental r1 = new Rental(m1, 4);
 51         Rental r2 = new Rental(m1, 2);
 52         Rental r3 = new Rental(m3, 7);
 53         Rental r4 = new Rental(m2, 5);
 54         Rental r5 = new Rental(m3, 3);
 55
 56         Customer c1 = new Customer("jjhou");
 57         c1.addRental(r1);
 58         c1.addRental(r4);
 59
 60         Customer c2 = new Customer("gigix");
 61         c2.addRental(r1);
 62         c2.addRental(r3);
 63         c2.addRental(r2);
 64
 65         Customer c3 = new Customer("jiangtao");
 66         c3.addRental(r3);
 67         c3.addRental(r5);
 68
 69         Customer c4 = new Customer("yeka");
 70         c4.addRental(r2);
 71         c4.addRental(r3);
 72         c4.addRental(r5);
 73
 74         System.out.println(c1.statement());
 75         System.out.println(c2.statement());
 76         System.out.println(c3.statement());
 77         System.out.println(c4.statement());
 78     }
 79
 80     double getCharge(int daysRented) {
 81         return _price.getCharge(daysRented);
 82     }
 83
 84     int getFrequentRenterPoints(int daysRented) {
 85         return _price.getFrequentRenterPoints(daysRented);
 86     }
 87 }
 88
 89 class Rental {
 90     private Movie _movie;         // 影片
 91     private int _daysRented;      // 租期
 92
 93     public Rental(Movie movie, int daysRented) {
 94         _movie = movie;
 95         _daysRented = daysRented;
 96     }
 97
 98     public int getDaysRented() {
 99         return _daysRented;
100     }
101 
102     public Movie getMovie() {
103         return _movie;
104     }
105 
106     double getCharge() {
107         return _movie.getCharge(_daysRented);
108     }
109 
110     int getFrequentRenterPoints() {
111         return _movie.getFrequentRenterPoints(_daysRented);
112     }
113 }
114 
115 class Customer {
116     private String _name;                                 // 姓名
117     private Vector _rentals = new Vector();               // 租借記錄
118 
119     public Customer(String name) {
120         _name = name;
121     }
122 
123     public void addRental(Rental arg) {
124         _rentals.addElement(arg);
125     }
126 
127     public String getName() {
128         return _name;
129     }
130 
131     public String statement() {
132         Enumeration rentals = _rentals.elements();
133         String result = "Rental Record for " + getName() + "\n";
134 
135         while (rentals.hasMoreElements()) {
136             Rental each = (Rental) rentals.nextElement();
137 
138             // show figures for this rental
139             result += "\t" + each.getMovie().getTitle() + "\t" +
140                       String.valueOf(each.getCharge()) + "\n";
141         }
142 
143         // add footer lines（結尾列印）
144         result += "Amount owed is " +
145                   String.valueOf(getTotalCharge()) + "\n";
146         result += "You earned " +
147                   String.valueOf(getTotalFrequentRenterPoints()) +
148                   " frequent renter points";
149         return result;
150     }
151 
152     public String htmlStatement() {
153         Enumeration rentals = _rentals.elements();
154         String result = "<H1>Rentals for <EM>" + getName() +
155                        "</EM></H1><P>\n";
156         while (rentals.hasMoreElements()) {
157             Rental each = (Rental) rentals.nextElement();
158             // show figures for each rental
159             result += each.getMovie().getTitle() + ": " +
160                       String.valueOf(each.getCharge()) + "<BR>\n";
161         }
162         // add footer lines
163         result += "<P>You owe <EM>" +
164                   String.valueOf(getTotalCharge()) +
165                   "</EM><P>\n";
166         result += "On this rental you earned <EM>" +
167                   String.valueOf(getTotalFrequentRenterPoints()) +
168                   "</EM> frequent renter points<P>";
169         return result;
170     }
171 
172     // 譯註：此即所謂query method
173     private int getTotalFrequentRenterPoints() {
174         int result = 0;
175         Enumeration rentals = _rentals.elements();
176         while (rentals.hasMoreElements()) {
177             Rental each = (Rental) rentals.nextElement();
178             result += each.getFrequentRenterPoints();
179         }
180         return result;
181     }
182 
183     // 譯註：此即所謂query method
184     private double getTotalCharge() {
185         double result = 0;
186         Enumeration rentals = _rentals.elements();
187         while (rentals.hasMoreElements()) {
188             Rental each = (Rental) rentals.nextElement();
189             result += each.getCharge();
190         }
191         return result;
192     }
193 }
194 
195 abstract class Price {
196     abstract int getPriceCode();            // 取得價格代號
197     abstract double getCharge(int daysRented);
198 
199     int getFrequentRenterPoints(int daysRented) {
200         return 1;
201     }
202 }
203 
204 class ChildrensPrice extends Price {
205     int getPriceCode() {
206         return Movie.CHILDRENS;
207     }
208 
209     double getCharge(int daysRented) {
210         double result = 1.5;
211         if (daysRented > 3)
212             result += (daysRented - 3) * 1.5;
213         return result;
214     }
215 }
216 
217 class NewReleasePrice extends Price {
218     int getPriceCode() {
219         return Movie.NEW_RELEASE;
220     }
221 
222     double getCharge(int daysRented) {
223         return daysRented * 3;
224     }
225 
226     int getFrequentRenterPoints(int daysRented) {
227         return (daysRented > 1) ? 2 : 1;
228     }
229 }
230 
231 class RegularPrice extends Price {
232     int getPriceCode() {
233         return Movie.REGULAR;
234     }
235 
236     double getCharge(int daysRented) {
237         double result = 2;
238         if (daysRented > 2)
239             result += (daysRented - 2) * 1.5;
240         return result;
241     }
242 }
243 
244 
245 
```