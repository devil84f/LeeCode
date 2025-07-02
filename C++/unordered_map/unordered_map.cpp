#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    // ����unordered_map
    unordered_map<string, int> ageMap;
    
    // ����Ԫ��
    ageMap["Alice"] = 25;
    ageMap["Bob"] = 30;
    ageMap.insert({"Charlie", 35});
    
    // ����Ԫ��
    cout << "Alice's age: " << ageMap["Alice"] << endl;
    
    // ���Ԫ���Ƿ����
    if (ageMap.find("David") == ageMap.end()) {
        cout << "David not found" << endl;
    }
    
    // ����
    for (const auto& [key, value] : ageMap) {
        cout << key << ": " << value << endl;
    }
    
    // ɾ��Ԫ��
    ageMap.erase("Bob");
    
    return 0;
}