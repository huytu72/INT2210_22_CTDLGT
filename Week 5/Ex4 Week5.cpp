#include <iostream>
#include <string>
#include <map>

using namespace std;

class StudentManager {
private:
    map<int, pair<string, string>> students;

public:
    void insert(int ID, string& name, string& class_name) {
        students[ID] = make_pair(name, class_name);
    }

    void remove(int ID) {
        students.erase(ID);
    }

    string getInfo(int ID) {
        auto it = students.find(ID);
        if (it != students.end()) {
            return it->second.first + "," + it->second.second;
        } else {
            return "NA,NA";
        }
    }
};

int main() {
    StudentManager manager;

    string operation;
    int ID;
    string name, class_name;

    while (cin >> operation) {
        if (operation == "Insert") {
            cin >> ID >> name >> class_name;
            manager.insert(ID, name, class_name);
        } else if (operation == "Delete") {
            cin >> ID;
            manager.remove(ID);
        } else if (operation == "Infor") {
            cin >> ID;
            cout << manager.getInfo(ID) << endl;
        }
    }

    return 0;
}
