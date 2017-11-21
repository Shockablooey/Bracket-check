/********************************************************************* 
 ** Program Filename: kevin.c 
 ** Author: Chase Stubblefield
 ** Date: 11 June 2017
 ** Description: program that uses a linked list to determine validity 
 ** of a sequence of brackets, braces, and parentheses
 ** Input: a sequence of brackets as a command line
 ** Output: valid/not valid, then choices for testing the linked list
 *********************************************************************/
#include "list.h"

void list_testing();

int main(int argc, char** argv){
	char c;
	int fail = 0; // begin bool at false
	int again = 0;
	struct list l2;
	int count = 0; // number of unclosed brackets
	init(&l2);
	
		printf("Please enter a string of brackets, braces, and parentheses.\n(Program ignores all other characters)\n");
		c = getchar();

		while(c != '\n' && c != EOF){ // while elements are still in the buffer
			if(c == '{')
				push_back(&l2, 0); // push 0 for BRACKET
			else if(c == '[')
				push_back(&l2, 1); // push 1 for BRACE
			else if(c == '(')
				push_back(&l2, 2); // push 2 for PARENTHESIS
			else if(c == '}'){
				if(pop_back(&l2) != 0)
					fail = 1; // if no match, fail
			}
			else if(c == ']'){
				if(pop_back(&l2) != 1)
					fail = 1; // if no match, fail
			}
			else if(c == ')'){ 
				if(pop_back(&l2) != 2)
					fail = 1; // if no match, fail 
			}
			c = getchar(); // get a new char for the while loop
		}
		if(fail == 1 || l2.head != NULL) // if something did not match or an element has not been popped (unclosed bracket)
			printf("Sequence INVALID.\n");
		else
			printf("Sequence VALID.\n");
		delete(&l2); // free memory

/****************************************************************************************************/ 
//
// COMMENT OUT THESE NEXT THREE LINES IF YOU WANT TO JUST TEST THE BRACKETS CHECKING. 
// The lines below allow you to comprehensively test the functionality of my linked list since for 
// the assignment, all I needed was init, push_back, and push_front (and delete)
//
/****************************************************************************************************/ 

		printf("Press ENTER to continue\n");
		while(getchar() != '\n');
		ear
ist_testing();

	return 0;
}
/********************************************************************* 
 ** Function: list_testing 
 ** Description: allows user to test the linked list 
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: a linked list is created and altered
 *********************************************************************/
void list_testing (){
	struct list l; 
	int done = 0; // used for ending program
	int input; // used for user input

	init(&l); // set head and tail to NULL	

	while(done == 0){
		system("clear");
		printf("====================================================================================================\n");
		printf("|            |                  |                  |                       |                       |\n");
		printf("|  1 - Size  |  2 - Print List  |  3 - Push Front  |   4 - Push Back       |  5 - Head             |\n");
		printf("|            |                  |                  |                       |                       |\n");
		printf("|  6 - Tail  |  7 - Pop Front   |  8 - Pop Back    |   9 - Check if Empty  |  10 - Delete List     |\n");
		printf("|            |                  |                  |                       |                       |\n");
		printf("====================================================================================================\n");
		scanf("%d",&input);

		if(input == 10){
			delete(&l);
			done = 1; // end loop
		}
		else if(input == 9)
			printf("Empty - %d\n",empty(l)); 
		else if(input == 8){
			pop_back(&l);
			print(l);
		}
		else if(input == 7){
			pop_front(&l);
			print(l);
		}
		else if(input == 6)
			printf("Tail - %d\n",back(l));
		else if(input == 5)
			printf("Head - %d\n",front(l));
		else if(input == 4){
			printf("Enter a value (int) to push on the back ");
			scanf("%d",&input);
			push_back(&l,input);
			print(l);
		}
		else if(input == 3){
			printf("Enter a value (int) to push on the front ");
			scanf("%d",&input);
			push_front(&l,input);
			print(l);
		}
		else if(input == 2)
			print(l);
		else if(input == 1)
			printf("Size - %d\n",size(l));
		else
			printf("Bad Input\n");

		printf("Press ENTER to continue\n");
		while(getchar() != '\n');
		while(getchar() != '\n');
	}
}
