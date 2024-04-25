#include <vector>
#include <string>

class Customer {
private:
    int id;
    std::string address;
    std::vector<int> productIDs;           // 購買產品的 ID
    std::vector<int> productCompanyIDs;    // 購買產品所屬的公司 ID
    std::vector<bool> used;                // 註記這個陣列的的元素是否已經被用來儲存

public:
    // Constructor
    Customer(int customerID, const std::string& customerAddress)
        : id(customerID), address(customerAddress) {}

    // Method to add purchased product
    void addProduct(int productID, int companyID) {
        productIDs.push_back(productID);
        productCompanyIDs.push_back(companyID);
        used.push_back(false);
    }

    // Getter for customer ID
    int getID() const {
        return id;
    }

    // Getter for customer address
    std::string getAddress() const {
        return address;
    }

    // Method to mark product as used
    void markProductAsUsed(int index) {
        if (index >= 0 && index < used.size()) {
            used[index] = true;
        }
    }

    // Method to check if a product is used
    bool isProductUsed(int index) const {
        if (index >= 0 && index < used.size()) {
            return used[index];
        }
        return false;
    }

    // Destructor (optional)
    ~Customer() {
        // Clean up resources if needed
    }
};
