#include <stdio.h>
#include <stdlib.h>

/* Tree Node Structures */
struct treeNode{
	struct treeNode *leftPtr;
	int data;
	struct treeNode *rightPtr;
};

/* Prototypes */
void instructions(void);
void inOrder(struct treeNode *nodePtr);
void preOrder(struct treeNode *nodePtr);
void postOrder(struct treeNode *nodePtr);
struct treeNode *search(struct treeNode *rootPtr, int value);
void insert(struct treeNode **PtrtorootPtr, int value);
struct treeNode *max(struct treeNode *nodePtr);
struct treeNode *min(struct treeNode *nodePtr);


int main(void){
	/* Variable declaration and initialization */
	int choice, value;
	struct treeNode *rootPtr = NULL, *auxPtr;

	/* Menu */
	instructions();
	printf("? ");
	scanf("%d", &choice);

	while(choice != 0){
		switch(choice){
			case 1:
				printf("Enter value to be inserted: ");
				scanf("%d", &value);

				/* Check if value is already in the tree */
				auxPtr = search(rootPtr, value);

				if (auxPtr == NULL){
					/* PtrtorootPtr = &rootPtr */
					insert(&rootPtr, value);
				}
				else{
					printf("Duplicate data!\n");
				}
				break;
			case 2:
				printf("\n The inOrder tree walk is: \n");
				inOrder(rootPtr);
				printf("\n");
				break;
			case 3:
				printf("\n The preOrder tree walk is: \n");
				preOrder(rootPtr);
				printf("\n");
				break;
			case 4:
				printf("\n The postOrder tree walk is: \n");
				postOrder(rootPtr);
				printf("\n");
				break;
			case 5:
				/* Ask the user for the value to be searched */
				printf("Enter value to be searched: ");
				scanf("%d", &value);

				/* Store the result of search() in auxPtr*/
				auxPtr = search(rootPtr, value);

				/* Print auxPtr */
				printf("-Memory Address: %p\n", auxPtr);

				/* Check if auxPtr is not NULL */
				if (auxPtr != NULL){
					/* If it is not NULL print auxPtr->data */
					printf("-Value: %d\n", auxPtr->data);
				}
				else{
					/* If it is NULL print "NULL"*/
					printf("-Value: NULL\n");
				}
				break;
			case 6:
				printf("The maximum value is: \n");	
				auxPtr = max(rootPtr);

				if(auxPtr != NULL){
					printf("%d\n", auxPtr->data);
				}
				else{
					printf("Emptry tree!\n");
				}
				break;
			case 7:
				printf("The minmum value is: \n");	
				auxPtr = min(rootPtr);

				if(auxPtr != NULL){
					printf("%d\n", auxPtr->data);
				}
				else{
					printf("Emptry tree!\n");
				}
				break;
			default:
				printf("Invalid choice!\n\n");
				instructions();
				break;
		}
		printf("? ");
		scanf("%d", &choice);
	}
	return 0;
}

void instructions(void){
	printf("Enter your choice: \n"
		"1 to insert a new node\n"
		"2 to inOrder tree traversal\n"
		"3 to preOrder tree traversal\n"
		"4 to postOrder tree traversal\n"
		"5 to search a value\n"
		"6 to find max value\n"
		"7 to find min value\n"
		"0 to exit\n"
		);
}

void inOrder(struct treeNode *nodePtr){
	/* if subtree is not empty then traverse */
	if(nodePtr != NULL){
		inOrder(nodePtr->leftPtr);
		printf("%d ", nodePtr->data);
		inOrder(nodePtr->rightPtr);
	}
}

void preOrder(struct treeNode *nodePtr){
	/* if subtree is not empty then traverse */
	if(nodePtr != NULL){
		printf("%d ", nodePtr->data);
		preOrder(nodePtr->leftPtr);
		preOrder(nodePtr->rightPtr);
	}
}

void postOrder(struct treeNode *nodePtr){
	/* if subtree is not empty then traverse */
	if(nodePtr != NULL){
		postOrder(nodePtr->leftPtr);
		postOrder(nodePtr->rightPtr);
		printf("%d ", nodePtr->data);
	}
}

struct treeNode *search(struct treeNode *rootPtr, int value){
	struct treeNode *currentPtr;
	currentPtr = rootPtr;

	while(currentPtr != NULL && currentPtr->data != value){
		if (value > currentPtr->data){
			currentPtr = currentPtr->rightPtr;
		}
		else{
			currentPtr = currentPtr->leftPtr;
		}
	}

	return currentPtr;
}

void insert(struct treeNode **PtrtorootPtr, int value){
	struct treeNode *newPtr, *previousPtr, *currentPtr;

	/* Create new node */
	newPtr = malloc(sizeof(struct treeNode));

	/* Check if newPtr is not NULL */
	if (newPtr != NULL){
		newPtr->data = value;
		newPtr->rightPtr = NULL;
		newPtr->leftPtr = NULL;

		/* Iterate until right position */
		previousPtr = NULL;
		// *PtrtorootPtr = rootPtr
		currentPtr = *PtrtorootPtr;

		while(currentPtr != NULL){

			/* previousPtr Update */
			previousPtr = currentPtr;

			/* currentPtr Update */
			if (value > currentPtr->data){
				currentPtr = currentPtr->rightPtr;
			}
			else{
				currentPtr = currentPtr->leftPtr;
			}

		}

		/* Check if tree is empty */
		if (previousPtr == NULL){
			/* rootPtr (*PtrtorootPtr) Update */
			*PtrtorootPtr = newPtr;
		}
		/* Insert node to the right */
		else if (value > previousPtr->data){
			previousPtr->rightPtr = newPtr;
		}
		/* Insert node to the left */
		else{
			previousPtr->leftPtr = newPtr;
		}
	}
	else{
		printf("No memory available.\n");
	}
}

/*
struct treeNode *max(struct treeNode *rootPtr){
	struct treeNode *currentPtr;
	currentPtr = rootPtr;

	while(currentPtr->rightPtr != NULL){
		currentPtr = currentPtr->rightPtr;
	}

	return currentPtr;
}
*/

struct treeNode *max(struct treeNode *nodePtr){

	while(nodePtr->rightPtr != NULL){
		nodePtr = nodePtr->rightPtr;
	}

	return nodePtr;
}

struct treeNode *min(struct treeNode *nodePtr){
	
	while(nodePtr->leftPtr != NULL){
		nodePtr = nodePtr->leftPtr;
	}

	return nodePtr;
}













