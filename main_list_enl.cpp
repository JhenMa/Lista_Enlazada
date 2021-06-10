#include <iostream>
 
#include "linkedlist.h"

 
using namespace std;
 
int main()
{
        LinkedList list_1;
        LinkedList list_2;
        int ele, ele2, ele3, ele4;
        ele = 1,
        ele2 = 2;
        ele3 = 12;
        ele4 = 0;
        list_1.add_sort(ele);
        list_1.add_sort(ele2);
        list_1.add_sort(ele3);
        list_1.add_sort(ele4);
        list_1.print();
        cout<<list_1;
    return 0;
}