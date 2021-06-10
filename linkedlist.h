#ifndef LIST_H
#define LIST_H
 
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
 
#include "node.h"

using namespace std;
class LinkedList{
    public:
        LinkedList();
        ~LinkedList();
        void add_sort(int);
        void del_by_data(int);
        void print();
        friend ostream& operator << (ostream &, const LinkedList &);
    private:
        Node *m_head;
        int size;
};



LinkedList::LinkedList()
{
    size = 0;
    m_head = NULL;
}

void LinkedList::add_sort(int _element)
{
    Node *new_node = new Node (_element);
    Node *temp = m_head;
 
    if (!m_head) {
        m_head = new_node;
    } 
    else {
        if (m_head->getElement() > _element) {
            new_node->setNext(m_head);
            m_head = new_node;
        } else {
            while ((temp->getNext() != NULL) && (temp->getNext()->getElement() < _element)) {
                temp = temp->getNext();
            }
            new_node->setNext(temp->getNext());
            temp->setNext(new_node) ;
        }
    }
    size++;
}

void LinkedList::print()
{
    Node *temp = m_head;
    if (!m_head) {
        cout << "La Lista está vacía " << endl;
    } 
    else {
        while (temp) {
            temp->print();
            temp = temp->getNext();
        }
    }
    cout << endl;
}

LinkedList::~LinkedList() {}

ostream& operator << (ostream &out, const LinkedList &p){
    Node *a = p.m_head;
    out<<"[";
    out<<a->getElement()<<" ";
    for(int i=0;i<p.size-1;i++){
        a = a->getNext();
        out<< a->getElement() << " ";
    }
    out<<"]";
    out<<endl;
    return out;
}

#endif // LIST_H