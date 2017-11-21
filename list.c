#include "list.h"

/********************************************************************* 
 ** Function: init
 ** Description: Sets list node pointers to null 
 ** Parameters: the list
 ** Pre-Conditions: list pointers are garbage
 ** Post-Conditions: they are NULL
 *********************************************************************/
void init(struct list* cart){ 
	cart->head = NULL;
	cart->tail = NULL;
}
/********************************************************************* 
 ** Function: size 
 ** Description: finds out size of linked list and returns it
 ** Parameters: the list
 ** Pre-Conditions: none
 ** Post-Conditions: size int is returned
 *********************************************************************/
int size(struct list cart){
	int i = 0; // integer for counting purposes
	nodePtr temp;

	if(cart.head == NULL)
		return 0;
	else{
		temp = cart.head; // start a pointer at the head

		while(temp->next != NULL){
			temp = temp->next;
			i++;
		}
		return i+1; // i must be returned with an extra number simply
			    // because of how the counting works
	}
}
/********************************************************************* 
 ** Function: print
 ** Description: print the values in list
 ** Parameters: the list
 ** Pre-Conditions: none 
 ** Post-Conditions: nothing is altered
 *********************************************************************/
void print(struct list cart){ 
	nodePtr temp;

	if(cart.head == NULL){
		printf("----------------------------------------------------------------------------------------------------\n");
		printf("List - > Empty list\n");
		printf("----------------------------------------------------------------------------------------------------\n");
	}
	else{
		temp = cart.head; // start at beginning

		printf("----------------------------------------------------------------------------------------------------\n");
		printf("List -> "); 
		while(temp != NULL){ // while temp is not NULL 
			printf("%d ",temp->value); // print current value
			temp = temp->next; // move temp
		}
		printf("\n----------------------------------------------------------------------------------------------------\n");
	}
}
/********************************************************************* 
 ** Function: push_front
 ** Description: Push to front of list
 ** Parameters: the list and the integer to add
 ** Pre-Conditions: linked list is n length
 ** Post-Conditions: linked list is n+1 length
 *********************************************************************/
void push_front(struct list* cart, int input){
	nodePtr newNode;

	newNode = malloc(sizeof(struct node)*1);
	newNode->value = input;

	if(cart->head == NULL){ // if 0 elements
		cart->head = newNode;
		cart->tail = newNode;
		cart->head->next = NULL;
	}
	else if(cart->head->next == NULL){ // if 1 element
		newNode->next = cart->head;
		cart->head = newNode;
		cart->tail = cart->head->next;
		cart->tail->next = NULL;
	}
	else{
		newNode->next = cart->head;
		cart->head = newNode;
	}	
}
/********************************************************************* 
 ** Function: push_back
 ** Description: Push to end of list
 ** Parameters: the list and the integer to add
 ** Pre-Conditions: linked list is n length
 ** Post-Conditions: linked list is n+1 length
 *********************************************************************/
void push_back(struct list* cart, int input){ 
	nodePtr newNode;

	newNode = malloc(sizeof(struct node)*1);
	newNode->value = input;

	if(cart->head == NULL){ // if 0 elements
		cart->head = newNode;
		cart->tail = newNode;
		cart->head->next = NULL;
	}
	else if(cart->head->next == NULL){ // if 1 element
		cart->head->next = newNode;
		cart->tail = newNode;
		cart->tail->next = NULL;
	}
	else{
		cart->tail->next = newNode;
		cart->tail = newNode;
		cart->tail->next = NULL;		
	}
}
/********************************************************************* 
 ** Function: front 
 ** Description: Returns value at the front of the list
 ** Parameters: the list
 ** Pre-Conditions: none
 ** Post-Conditions: nothing is altered
 *********************************************************************/
int front(struct list cart){
	if(cart.head == NULL){
		printf("Empty list.\n");
		return 0;
	}
	else
		return cart.head->value;
}
/********************************************************************* 
 ** Function: back 
 ** Description: Returns value at the back of the list
 ** Parameters: the list
 ** Pre-Conditions: none
 ** Post-Conditions: nothing is altered
 *********************************************************************/
int back(struct list cart){ 
	if(cart.head == NULL){
		printf("Empty list.\n");
		return 0;
	}
	else 
		return cart.tail->value;
}
/********************************************************************* 
 ** Function: pop_back 
 ** Description: remove node from back and return value
 ** Parameters: the list 
 ** Pre-Conditions: list is n length
 ** Post-Conditions: list is n-1 length and the value of the removed
 ** node is returned
 *********************************************************************/
int pop_back(struct list* cart){
	int returnValue;

	if(cart->head == NULL){ // if 0 elements
		printf("No elements in list\n");
		return 9; // return an element other than 0 since it has significance
	}
	else if(cart->head->next == NULL){ // if 1 element
		returnValue = cart->head->value;
		free(cart->head);
		cart->head = NULL;
		return returnValue;
	}	
	else{
		cart->tail = cart->head; // start tail at head
		while(cart->tail->next->next != NULL){ // move tail to second to last position
			cart->tail = cart->tail->next;
		}
		returnValue = cart->tail->next->value;
		free(cart->tail->next);
		cart->tail->next = NULL;
		
		return returnValue;
	}
}
/********************************************************************* 
 ** Function: pop_front 
 ** Description: remove node from front and return value
 ** Parameters: the list 
 ** Pre-Conditions: list is n length
 ** Post-Conditions: list is n-1 length and the value of the removed
 ** node is returned
 *********************************************************************/
int pop_front(struct list* cart){
	int returnValue;
	nodePtr temp;
	
	if(cart->head == NULL){ // if 0 elements
		printf("No elements in list\n");
		return 9; // return an element other than 0 since it has significance
	}
	else if(cart->head->next == NULL){ // if 1 element
		returnValue = cart->head->value;
		free(cart->head);
		cart->head = NULL;
		return returnValue;
	}
	else{
		temp = cart->head; // set temp to head so we can delete it
		returnValue = cart->head->value; 
		cart->head = cart->head->next; 

		free(temp);
		return returnValue;
	}
}
/********************************************************************* 
 ** Function: empty 
 ** Description: returns true if list is empty
 ** Parameters: the list
 ** Pre-Conditions: none
 ** Post-Conditions: an int is returned for the status of the list
 *********************************************************************/
int empty(struct list cart){
	if(cart.head == NULL)
		return 1;
	else
		return 0;
}
/********************************************************************* 
 ** Function: delete 
 ** Description: Remove all nodes from list
 ** Parameters: the list 
 ** Pre-Conditions: the linked list is dynamically allocated
 ** Post-Conditions: the linked list is successfully freed
 *********************************************************************/
void delete(struct list* cart){ 
	nodePtr temp;

	if(cart->head == NULL)
		printf("No list to delete.\n");

	else{	
		while(cart->head->next != NULL){ // set temp to head, move head, and delete temp
			temp = cart->head;
			cart->head = cart->head->next;
			free(temp);
		}

		free(cart->head);
		cart->head = NULL;
	}
}
