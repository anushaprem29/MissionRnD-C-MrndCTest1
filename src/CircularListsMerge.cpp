/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};

void merge(struct node *head1, struct node *head2){
	struct node *temp;
	while (head1->next != NULL && head2 != NULL){
		if (head1->next->data > head2->data){
			temp = head1->next;
			head1->next = head2;
			head2 = head2->next;
			head1->next->next = temp;
		}
		head1 = head1->next;
	}
	if (head2 != NULL){
		head1->next = head2;
	}
}
int merge_circularlists(struct node **head1, struct node **head2){
	//Returns Length of merged Sorted circular SLL and also points *head1 to final SLL .
	int l1=0, l2=0;
	struct node *first = *head1;
	struct node *second = *head2;

	while (first->next != *head1 && head1!=NULL){
		l1++;
		first = first->next;
	}
	first->next = NULL;
	while (second->next != *head2 && head2!=NULL){
		l2++;
		second = second->next;
	}
	second->next = NULL;
	if (*head1 == NULL)	return l2;
	if (*head2 == NULL)	return l1;
	struct node *temp;
	if ((*head1)->data < (*head2)->data){
		merge(*head1, *head2);
	}
	else{
		head1 = head2;
		merge(*head2, *head1);
	}
	return l1+l2;
}