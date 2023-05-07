#include "todolist.h"
#include "item.h"
#include <string.h>
#include "iostream"
#include <sstream>
using namespace std;

void todolist::create(void) {
    string task;
    while(true) {
        std::getline(std::cin, task);
        if (task.empty()) {
            break;
        }
        item new_item(task);
        list.push_back(new_item);
    }
}

void todolist::add(void) {
    string task;
    int count = this->getcount() + 1; 
    cout << "Index : " << count << " >>";
    std::getline(std::cin, task);
    if (task.empty()) {
        return;
    }
    item new_item(task);
    list.push_back(new_item);
    this->save();
}

void todolist::check(void) {
    int index = 0;
    cout << "Enter the index:";
    cin >> index;
    index --;
    if ((index < 0) || (index > this->getcount())) {
        return;
    }
    this->list[index].done();
    this->save();
    return;    
}

void todolist::clear(void) {
    this->list.clear();
    remove(this->filename);
}

void todolist::display(void) {
    int count = 1;
    for (item myitem: this->list) {
        cout << count << ")" << myitem.text() << ":" << myitem.get_status() << endl;
        count++;
    }
    return;
}

int todolist::getcount(void) {
    return this->list.size();
}

void todolist::read(void) {
//    cout << "read" << endl;
    string line;
    ifstream myfile(this->filename);
    int token_field = 0;
    while(getline(myfile, line)) {
//        cout << line << endl;
        token_field = 0;
        std::stringstream mystream(line);
        std::string token;
        std::string task;
        while (std::getline(mystream, token, ':'))
        {
            //std::cout << "token" << token << std::endl;
            if (!token_field) {
                task = token;
                token_field ++;
            } else {
                item new_item(task);
                (token == "true") ? new_item.set_status(true) : new_item.set_status(false);
                this->list.push_back(new_item);
            }
        }
    }
    myfile.close();
}

void todolist::save(void) {
    std::ofstream fs(this->filename, std::ofstream::out);
    for (item myitem: this->list) {
        fs << myitem.text();
        fs << ":";
        fs << myitem.get_status();
        fs << endl;
    }
    return;
}

todolist::todolist(void) {

}

todolist::todolist(const char* name) {
    filename = name;
}