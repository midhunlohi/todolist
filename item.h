#ifndef __ITEM__H__
#define __ITEM__H__

#include <iostream>
#include <string>

using namespace std;

class item{
    public:
        item();
        item(string);
        string text();
        void done();
        bool is_done();
        string get_status();
        void set_status(bool status);
    private:
        string task;
        bool status;
};

#endif