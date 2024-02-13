#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_


struct node { 
	int data;
	struct node* next;
};

struct node* create_linked_list(int n);
int get_linked_list_data_item_value(struct node* start, int node_num, int total_elements);
void print_linked_list(struct node* start, int total_elements);
void pointerJumping(node* head);
bool update_data_in_linked_list(struct node* start, 
	int node_to_update, 
	int update_val, 
	int total_elements);
	
#endif