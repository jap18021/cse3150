#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "linked_list.h"


int zero_linked_list_elts = 0;
struct node* zero_linked_list_elts_null_node = NULL;

int one_element_linked_list = 1;
int data_value_of_initial_linked_list_elt = 1;
struct node* linked_list_one_elt = create_linked_list(one_element_linked_list);

int two_element_linked_list = 2;
int data_value_of_second_elt = 2;
struct node* linked_list_two_elts = create_linked_list(two_element_linked_list);


TEST_CASE("Testing Linked List") {

    SUBCASE("Final node points to itself") {
       
       node* curr = linked_list_two_elts;

       while (curr != curr->next)
       {curr = curr->next;}
       CHECK(curr == curr->next);
       
    }

    SUBCASE("Pointer jumping"){
        struct node * linked_list_five_elts = create_linked_list(5);
        struct node * array[5];
        node* start = linked_list_five_elts;
        node* curr = linked_list_five_elts;
        node* last;

        for(int i = 0; i < 5; i++)
        {array[i] = curr;
        curr = curr->next;}

        last = curr;

        for(int i = 0; i < 3; i++)
        {CHECK(array[i]->next != last);} 
        CHECK(array[3]->next == last);
        CHECK(array[4]->next == last);

        pointerJumping(linked_list_five_elts);
        for(int i = 0; i < 5; i++)
        {CHECK(array[i]->next == last);}
    }

    SUBCASE("Pointer jumping for a zero-element linked list") {
        struct node* linked_list_zero_elts = create_linked_list(0);

        CHECK(linked_list_zero_elts == nullptr);
    }

    SUBCASE("Pointer jumping for a one-element linked list") {
        int one_element_linked_list = 1;
        struct node* linked_list_one_elt = create_linked_list(one_element_linked_list);
        node* start = linked_list_one_elt;

        CHECK(linked_list_one_elt->next == linked_list_one_elt);

        CHECK(get_linked_list_data_item_value(linked_list_one_elt, 1, 1) == data_value_of_initial_linked_list_elt);
    } 
}