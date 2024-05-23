#ifndef PRODUCT_H
#define PRODUCT_H

#include <vector>
#include <string>

class Customer;  // 前向宣告

class Product {
public:
    Product(int number) : pno(number), customer(nullptr) {}

    int getPno() const { return pno; }
    Customer* getCustomer() const { return customer; }
    void setCustomer(Customer* cust) { customer = cust; }

private:
    int pno;
    Customer* customer;  // 每個產品屬於一個客戶
};

#endif // PRODUCT_H

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <vector>
#include <string>

class Product;  // 前向宣告

class Customer {
public:
    Customer(int number, const std::string& customerName) : cno(number), name(customerName) {}

    int getCno() const { return cno; }
    std::string getName() const { return name; }
    void addProduct(Product* product) { 
        products.push_back(product); 
        product->setCustomer(this);  // 設置產品的客戶為當前客戶
    }
    const std::vector<Product*>& getProducts() const { return products; }

private:
    int cno;
    std::string name;
    std::vector<Product*> products;
};

#endif // CUSTOMER_H
