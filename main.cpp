#include "item.h"
#include "todolist.h"

int main(void) {
start:
    todolist mylist("mytasks.txt");
    mylist.read();
    if (mylist.getcount() > 0) {
        string choice = "";
        while(true) {
            cout << "1: Add" << endl;
            cout << "2: Clear" << endl;
            cout << "3: Display" << endl;
            cout << "4: Check/Uncheck" << endl;
input:
            std::getline(std::cin, choice);
            if (choice.empty()) {
                goto input; 
            }
            switch(stoi(choice)) {
                case 1:
                    mylist.add();
                    break;
                case 2:
                    mylist.clear();
                    break;
                case 3:
                    mylist.display();
                    break;
                case 4:
                    mylist.check();
                    break;
                default:
                    break;
            }
            choice.clear();
        }
    } else {
        mylist.create();
        mylist.save();
        goto start;
    }
}