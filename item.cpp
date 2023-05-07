#include "item.h"

item::item(string task) {
    this->task = task;
    this->status = false;
}

string item::text(void) {
    return this->task;
}

bool item::is_done() {
    return this->status;
}

string item::get_status() {
    if (this->status) {
        return "true";
    }  
    return "false";
}

void item::done() {
    if (!this->status) {
        this->status = true;
    } else {
        this->status = false;
    }
    return;
}

void item::set_status(bool status) {
    this->status = status;
    return;
}