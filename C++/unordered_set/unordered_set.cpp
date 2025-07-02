#include <unordered_set>
#include <string>
#include <iostream>

int main() {
    // 创建unordered_set
    std::unordered_set<std::string> names;
    
    // 插入元素
    names.insert("Alice");
    names.insert("Bob");
    names.insert("Charlie");
    
    // 检查元素是否存在
    if (names.find("David") == names.end()) {
        std::cout << "David not found" << std::endl;
    }
    
    // 遍历
    for (const auto& name : names) {
        std::cout << name << std::endl;
    }
    
    // 删除元素
    names.erase("Bob");
    
    return 0;
}