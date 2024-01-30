#include <iostream>
#include "linked_list.h"

using namespace std;

// build_new_linked_list:
    // Returns a pointer to the first node in the linked list.
    // If total_new_elements is 0, then return null.

struct node* build_new_linked_list(int total_new_elements) {
    if (total_new_elements == 0) {
        return nullptr;
    } else {
        struct node* root = new node;
        root->data = -1;
        struct node* linked_list = root;

        for (int i = 0; i < total_new_elements; i++) {
            linked_list->next = new node;
            linked_list->data = i + 1;
            linked_list = linked_list->next;
        }

        return root;
    }
}


//get_linked_list_data_item_value:
    // Returns -1 if node_number is greater than total_elements.

int get_linked_list_data_item_value(struct node* start, int node_number, int total_elements) {
    if (node_number > total_elements) {
        return -1;
    } else {
        struct node* linked_list = start;

        for (int i = 0; i < node_number - 1; i++) {
            linked_list = linked_list->next;
        }

        return linked_list->data;
    }
}

void print_linked_list(struct node* start, int total_elements) {
    struct node* linked_list = start;

    for (int i = 0; i < total_elements; i++) {
        cout << linked_list->data << endl;
        linked_list = linked_list->next;
    }
}

void delete_linked_list(node* start) {
    node* current = start;
    node* next;

    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }

    start = nullptr;
}

//update_data_in_linked_list:
    // Returns false if node_to_update is greater than total_elements.
    // Returns true otherwise.

bool update_data_in_linked_list(struct node* start, int node_to_update, int update_val, int total_elements) {
    if (node_to_update > total_elements) {
        return false;
    } else {
        struct node* linked_list = start;

        for (int i = 0; i < node_to_update - 1; i++) {
            linked_list = linked_list->next;
        }

        linked_list->data = update_val;
        return true;
    }
}
