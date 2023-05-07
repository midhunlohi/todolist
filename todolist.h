#ifndef __TODOLIST__H__
#define __TODOLIST__H__

#include<iostream>
#include<vector>
#include<fstream>
#include "item.h"

class todolist {
    public:
        todolist();
        todolist(const char*);
        void read();
        void display();
        void create();
        void save();
        void add();
        void clear();
        void check();
        int getcount();
    private:
        const char* filename;
        vector<item> list;
};

#endif