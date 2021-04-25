//
// Created by maxim on 23/04/2021.
//

#include <cstddef>
#include <iostream>
#include "llist.h"

using namespace std;

struct item {
    int id;
    struct item *prev, *next;
};

struct item *list = NULL;

int main() {
    struct item* item = new struct item;
    item->id = 5;
    DL_APPEND(list, item);

    cout << item->id << endl;
    cout << list->id << endl;

    return 0;
}