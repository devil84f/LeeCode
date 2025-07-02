#include <iostream>

struct Person {
    std::string name;
    int age;
    std::string address;
    
    // Ĭ�Ϲ��캯��
    Person() : name("Unknown"), age(0), address("Not specified") {}
    
    // �����ֲ����Ĺ��캯��
    Person(const std::string& n, int a) : name(n), age(a), address("Not specified") {}
    
    // ���������Ĺ��캯��
    Person(const std::string& n, int a, const std::string& addr) 
        : name(n), age(a), address(addr) {}
    
    // �������캯��
    Person(const Person& other) 
        : name(other.name), age(other.age), address(other.address) {
        std::cout << "Copy constructor called\n";
    }
};

struct Rectangle {
    int width;
    int height;
    std::string color;
    
    // ί�й��캯��
    Rectangle() : Rectangle(10, 10, "black") {}
    
    Rectangle(int w, int h) : Rectangle(w, h, "black") {}
    
    // �����캯��
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

// ��̬�ڴ����
struct DynamicArray {
    int* data;
    size_t size;
    
    // ���캯��
    DynamicArray(size_t s) : size(s) {
        data = new int[size];
        std::cout << "Allocated array of size " << size << "\n";
    }
    
    // ��������
    ~DynamicArray() {
        delete[] data;
        std::cout << "Freed array of size " << size << "\n";
    }
    
    // �������캯��(���)
    DynamicArray(const DynamicArray& other) : size(other.size) {
        data = new int[size];
        std::copy(other.data, other.data + size, data);
    }
    
    // �ƶ����캯��(C++11)
    DynamicArray(DynamicArray&& other) noexcept 
        : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
    }
};

int main() {
    // ���ع��캯��
    Person p1;                  // ����Ĭ�Ϲ��캯��
    Person p2("Alice", 25);     // �������������Ĺ��캯��
    Person p3("Bob", 30, "123 Main St"); // �������������Ĺ��캯��
    Person p4 = p3;             // ���ÿ������캯��

    // ί�й��캯��
    Rectangle r1;
    Rectangle r2(5, 10);
    Rectangle r3(5, 10, "red");

    // ��Ĭ�ϲ����Ĺ��캯��
    Car c1("Toyota", "Camry");         // ʹ��Ĭ����ݺͼ۸�
    Car c2("Honda", "Accord", 2022);   // ʹ��Ĭ�ϼ۸�
    Car c3("Ford", "Mustang", 2021, 35000.0); // ʹ�����в���

    // ��̬�ڴ����
    DynamicArray arr1(10);     // ������ͨ���캯��
    DynamicArray arr2 = arr1;  // ���ÿ������캯��(���)
    DynamicArray arr3 = std::move(arr1); // �����ƶ����캯��
}