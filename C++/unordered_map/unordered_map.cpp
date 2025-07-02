#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    // 创建unordered_map
    unordered_map<string, int> ageMap;
    
    // 插入元素
    ageMap["Alice"] = 25;
    ageMap["Bob"] = 30;
    ageMap.insert({"Charlie", 35});
    
    // 访问元素
    cout << "Alice's age: " << ageMap["Alice"] << endl;
    
    // 检查元素是否存在
    if (ageMap.find("David") == ageMap.end()) {
        cout << "David not found" << endl;
    }
    
    // 遍历
    for (const auto& [key, value] : ageMap) {
        cout << key << ": " << value << endl;
    }
    
    // 删除元素
    ageMap.erase("Bob");
    
    return 0;
}