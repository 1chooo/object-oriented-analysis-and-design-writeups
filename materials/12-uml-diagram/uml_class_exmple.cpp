#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class IntArray; // Forward declaration

// Base Sorter class
class Sorter {
protected:
    std::string name;
    int compareCount;
    int exchangeCount;

public:
    Sorter(const std::string& name) : name(name), compareCount(0), exchangeCount(0) {}

    virtual void Sort(IntArray& values) = 0;

    std::string getName() const {
        return name;
    }

    void report() const {
        std::cout << "Sorter: " << name << "\n";
        std::cout << "Comparisons: " << compareCount << "\n";
        std::cout << "Exchanges: " << exchangeCount << "\n";
    }

    void incrementCompareCount() {
        ++compareCount;
    }

    void incrementExchangeCount() {
        ++exchangeCount;
    }
};

// IntArray class
class IntArray {
private:
    std::vector<int> array;
    Sorter* sorter;

public:
    void cleanUp() {
        array.clear();
    }

    void getInput(int size) {
        array.resize(size);
        std::cout << "Enter " << size << " integers:\n";
        for (int& value : array) {
            std::cin >> value;
        }
    }

    int getSize() const {
        return array.size();
    }

    bool isInIncreasingOrder() const {
        for (size_t i = 1; i < array.size(); ++i) {
            if (array[i - 1] > array[i]) {
                return false;
            }
        }
        return true;
    }

    void printOutput() const {
        for (const int value : array) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }

    void setSorter(Sorter* sorter) {
        this->sorter = sorter;
    }

    void sort() {
        if (sorter) {
            sorter->Sort(*this);
        }
    }

    int& operator[](size_t index) {
        return array[index];
    }

    const int& operator[](size_t index) const {
        return array[index];
    }

    size_t size() const {
        return array.size();
    }

    void swap(size_t i, size_t j) {
        std::swap(array[i], array[j]);
        if (sorter) {
            sorter->incrementExchangeCount();
        }
    }
};

// SelectionSorter class
class SelectionSorter : public Sorter {
public:
    SelectionSorter() : Sorter("SelectionSorter") {}

    void Sort(IntArray& values) override {
        size_t n = values.size();
        for (size_t i = 0; i < n - 1; ++i) {
            size_t minIndex = i;
            for (size_t j = i + 1; j < n; ++j) {
                incrementCompareCount();
                if (values[j] < values[minIndex]) {
                    minIndex = j;
                }
            }
            values.swap(i, minIndex);
        }
    }
};

// InsertionSorter class
class InsertionSorter : public Sorter {
public:
    InsertionSorter() : Sorter("InsertionSorter") {}

    void Sort(IntArray& values) override {
        size_t n = values.size();
        for (size_t i = 1; i < n; ++i) {
            int key = values[i];
            size_t j = i;
            while (j > 0 && values[j - 1] > key) {
                incrementCompareCount();
                values[j] = values[j - 1];
                --j;
            }
            values[j] = key;
            incrementExchangeCount();
        }
    }
};

// QuickSorter class
class QuickSorter : public Sorter {
public:
    QuickSorter() : Sorter("QuickSorter") {}

    void Sort(IntArray& values) override {
        quickSort(0, values.size() - 1, values);
    }

    void quickSort(int lower, int upper, IntArray& values) {
        if (lower < upper) {
            int pivotIndex = partition(lower, upper, values);
            quickSort(lower, pivotIndex - 1, values);
            quickSort(pivotIndex + 1, upper, values);
        }
    }

private:
    int partition(int lower, int upper, IntArray& values) {
        int pivot = values[upper];
        int i = lower - 1;
        for (int j = lower; j < upper; ++j) {
            incrementCompareCount();
            if (values[j] <= pivot) {
                ++i;
                values.swap(i, j);
            }
        }
        values.swap(i + 1, upper);
        return i + 1;
    }
};

// Main function
int main() {
    IntArray intArray;

    std::cout << "Enter the number of elements: ";
    int size;
    std::cin >> size;

    intArray.getInput(size);

    std::cout << "Select sorting method (1-Selection, 2-Insertion, 3-Quick): ";
    int choice;
    std::cin >> choice;

    Sorter* sorter = nullptr;
    switch (choice) {
        case 1:
            sorter = new SelectionSorter();
            break;
        case 2:
            sorter = new InsertionSorter();
            break;
        case 3:
            sorter = new QuickSorter();
            break;
        default:
            std::cout << "Invalid choice\n";
            return 1;
    }

    intArray.setSorter(sorter);
    intArray.sort();
    intArray.printOutput();

    sorter->report();

    delete sorter;
    return 0;
}
