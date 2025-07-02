#include <unordered_set>
#include <string>
#include <iostream>

int main() {
    // ����unordered_set
    std::unordered_set<std::string> names;
    
    // ����Ԫ��
    names.insert("Alice");
    names.insert("Bob");
    names.insert("Charlie");
    
    // ���Ԫ���Ƿ����
    if (names.find("David") == names.end()) {
        std::cout << "David not found" << std::endl;
    }
    
    // ����
    for (const auto& name : names) {
        std::cout << name << std::endl;
    }
    
    // ɾ��Ԫ��
    names.erase("Bob");
    
    return 0;
}