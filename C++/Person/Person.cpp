#include <iostream>

struct Person {
    std::string name;
    int age;
    std::string address;
    
    // 默认构造函数
    Person() : name("Unknown"), age(0), address("Not specified") {}
    
    // 带部分参数的构造函数
    Person(const std::string& n, int a) : name(n), age(a), address("Not specified") {}
    
    // 完整参数的构造函数
    Person(const std::string& n, int a, const std::string& addr) 
        : name(n), age(a), address(addr) {}
    
    // 拷贝构造函数
    Person(const Person& other) 
        : name(other.name), age(other.age), address(other.address) {
        std::cout << "Copy constructor called\n";
    }
};

struct Rectangle {
    int width;
    int height;
    std::string color;
    
    // 委托构造函数
    Rectangle() : Rectangle(10, 10, "black") {}
    
    Rectangle(int w, int h) : Rectangle(w, h, "black") {}
    
    // 主构造函数
    Rectangle(int w, int h, const std::string& c) 
        : width(w), height(h), color(c) {
        std::cout << "Constructing rectangle " << width << "x" << height 
                  << " with color " << color << "\n";
    }
};

struct Car {
    std::string make;
    std::string model;
    int year;
    double price;
    
    Car(const std::string& m, const std::string& mod, int y = 2023, double p = 25000.0)
        : make(m), model(mod), year(y), price(p) {
            std::cout << "make: " << make << " model: " << model 
                  << " year: " << year << " price: " << price << "\n";
        }
};

// 动态内存分配
struct DynamicArray {
    int* data;
    size_t size;
    
    // 构造函数
    DynamicArray(size_t s) : size(s) {
        data = new int[size];
        std::cout << "Allocated array of size " << size << "\n";
    }
    
    // 析构函数
    ~DynamicArray() {
        delete[] data;
        std::cout << "Freed array of size " << size << "\n";
    }
    
    // 拷贝构造函数(深拷贝)
    DynamicArray(const DynamicArray& other) : size(other.size) {
        data = new int[size];
        std::copy(other.data, other.data + size, data);
    }
    
    // 移动构造函数(C++11)
    DynamicArray(DynamicArray&& other) noexcept 
        : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
    }
};

int main() {
    // 重载构造函数
    Person p1;                  // 调用默认构造函数
    Person p2("Alice", 25);     // 调用两个参数的构造函数
    Person p3("Bob", 30, "123 Main St"); // 调用三个参数的构造函数
    Person p4 = p3;             // 调用拷贝构造函数

    // 委托构造函数
    Rectangle r1;
    Rectangle r2(5, 10);
    Rectangle r3(5, 10, "red");

    // 带默认参数的构造函数
    Car c1("Toyota", "Camry");         // 使用默认年份和价格
    Car c2("Honda", "Accord", 2022);   // 使用默认价格
    Car c3("Ford", "Mustang", 2021, 35000.0); // 使用所有参数

    // 动态内存分配
    DynamicArray arr1(10);     // 调用普通构造函数
    DynamicArray arr2 = arr1;  // 调用拷贝构造函数(深拷贝)
    DynamicArray arr3 = std::move(arr1); // 调用移动构造函数
}