#include <iostream>
#include "linked_list.h"

using namespace std;

struct node* create_linked_list(int n) {
    if (n == 0) {
        return NULL;
    } else {
        struct node* root = new node;
        root->data = -1;
        struct node* linked_list = root;

        for (int i = 0 ; i < n; i++) {
            if (i < n-1) {
                linked_list->next = new node;
                linked_list->data = i+1;
                linked_list = linked_list->next;
            } else{
                linked_list->next = linked_list;
                linked_list->data = i+1;
            }
        }
        return root;
    }
}

void pointerJumping(node* head) {
    node* curr = head;
    node* end;
    node* next;
    while (curr->next != curr) {
        curr = curr->next;
    }
    end = curr;
    curr = head;
    while (curr->next != curr) {
        next = curr->next;
        curr->next = end;
        curr = next;
    }
}

int get_linked_list_data_item_value(struct node* start, int node_num, int total_elements) {
    if (node_num > total_elements) {
        return -1;
    } else {
        struct node* linked_list = start;
        for (int i = 0; i < node_num -1; i++) {
            linked_list = linked_list->next;
        }
        return linked_list->data;
    }
}

void print_linked_list(struct node* start, int total_elements) {
    struct node * linked_list =  start;

    for (int i = 0; i < total_elements; i++) {
        cout << linked_list->data << endl;
        linked_list = linked_list->next;
    }
}

bool update_data_in_linked_list(struct node* start, 
    int node_to_update, 
    int update_val, 
    int total_elements) {
        return true;
    }