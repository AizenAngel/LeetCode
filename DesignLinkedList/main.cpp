#include <bits/stdc++.h>
using namespace std;

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    int val;
    MyLinkedList* next;
    MyLinkedList* head;
    
    MyLinkedList() {
        val = 0;
        next = NULL;
        head = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        int count = get_list_len();

        if(index > count) {
            cout<<"Velicina liste: "<<count<<"\n";
            return -1;
        }
        
        MyLinkedList* tmp = head;
        count = 0;
        while(tmp){
            if(count == index)
                return tmp->val;
            
            count++;
            tmp = tmp->next;
        }
        
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) 
    {
        MyLinkedList *new_node=new MyLinkedList;
        new_node->val=val;
        new_node->next=head;
        head=new_node;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) 
    {
        MyLinkedList *new_node=new MyLinkedList;
        new_node->val=val;
        if(!head)
        {
            head=new_node;
        }
        else
        {
            MyLinkedList *tmp=head;
            while(tmp->next)
            {
                tmp=tmp->next;
            }
            tmp->next=new_node;
        }
    }
    
    int get_list_len(){
        int count = 0;
        
        auto curr_head = head;

        while(curr_head){
            curr_head = curr_head->next;
            count++;
        }
        
        return count;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        int count = get_list_len();
        auto new_element = new MyLinkedList();
        new_element->val = val;

        if(index == 0){
            addAtHead(val);
            return;
        }

        if(index > count){
            return;
        }

        if(index == count){
            addAtTail(val);
            return;
        }
        
        auto* tmp = head;

        count = 0;

        while(count != index - 1){
            tmp = tmp->next;
            count++;
        }

        auto* tail = tmp->next;
        tmp->next = new_element;
        new_element->next = tail;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        int count = get_list_len();

        if (index >= count)
            return;
        
        if (index == 0){
            if (head) {
                head = head->next;
            }

            return;
        }

        auto old_head = head;
        count = 0;

        while(old_head && count < index - 1){
            old_head = old_head->next;
            count++;
        }

        auto* del_elem = old_head->next;

        old_head->next = old_head->next->next; 
    
        delete del_elem;
    }

    void print_list(){
        
        auto* tmp = head;

        while(tmp){
            cout<<tmp->val<<" ";
            tmp = tmp->next;
        }
        cout<<"\n";
    }
};

/*
["MyLinkedList","addAtHead","addAtIndex","addAtTail","addAtHead","addAtIndex","addAtTail","addAtTail","addAtIndex","deleteAtIndex","deleteAtIndex","addAtTail"]
[[],[0],[1,4],[8],[5],[4,3],[0],[5],[6,3],[7],[5],[4]]

"MyLinkedList" []
"addAtHead" [0]
"addAtIndex" [1, 4]
"addAtTail" [8]
"addAtHead" [5]
"addAtIndex" [4, 3]
"addAtTail" [0]
"addAtTail" [5]
"addAtIndex" [6, 3]
"deleteAtIndex" [7]
"deleteAtIndex" [5]
"addAtTail" [4]
*/

int main(){
//    MyLinkedList* list = new MyLinkedList();

//     list->addAtHead(4);
//     list->print_list();

//     list->addAtIndex(1, 5);
//     list->print_list();
    

//     list->addAtTail(8);
//     list->print_list();
    
    
//     list->addAtHead(5);
//     list->print_list();
    
    
//     list->addAtIndex(4, 3);
//     list->print_list();
    
    
//     list->addAtTail(0);
//     list->print_list();
    
    
//     list->addAtTail(5);
//     list->print_list();
    
    
//     list->addAtIndex(6, 3);
//     list->print_list();
    
    
//     list->deleteAtIndex(7);
//     list->print_list();
    
    
//     list->deleteAtIndex(5);
//     list->print_list();
    
    
//     list->addAtTail(4);
//     list->print_list();

/*****************************************************************************/

//    MyLinkedList* list = new MyLinkedList();

//     list->addAtHead(1);
//     list->print_list();
    
//     list->addAtTail(3);
//     list->print_list();
    
//     list->addAtIndex(1, 2);
//     list->print_list();
    
//     cout<<list->get(1)<<"\n";
//     //list->print_list();
      
//     list->deleteAtIndex(1);
//     list->print_list();        
    
//     cout<<list->get(1)<<"\n";
//     //list->print_list();

/********************************************************************************/

/**
 MyLinkedList []
 addAtHead [2]
 deleteAtIndex [1]
 addAtHead [2]
 addAtHead [7]
 addAtHead [3]
 addAtHead [2]
 addAtHead [5]
 addAtTail [5]
 get [5]
 deleteAtIndex [6]
 deleteAtIndex  [4]
*/

    // MyLinkedList* list = new MyLinkedList();

    // list->addAtHead(2);
    // list->print_list();

    // list->deleteAtIndex(1);
    // list->print_list();
    
    // list->addAtHead(2);
    // list->print_list();

    // list->addAtHead(7);
    // list->print_list();

    // list->addAtHead(2);
    // list->print_list();

    // list->addAtHead(3);
    // list->print_list();

    // list->addAtHead(5);
    // list->print_list();

    // list->addAtTail(5);
    // list->print_list();

    // cout<<list->get(5)<<"\n";

    // list->deleteAtIndex(6);
    // list->print_list();        

    // list->deleteAtIndex(4);
    // list->print_list();  

/*********************************************************************************/

    MyLinkedList* list = new MyLinkedList();

    list->addAtHead(2);
    list->print_list();

    list->addAtIndex(0, 1);
    list->print_list();

    cout<<list->get(1)<<"\n";

    return 0;
}