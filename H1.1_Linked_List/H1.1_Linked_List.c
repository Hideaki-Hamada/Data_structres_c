// Exercise 1. Implemenation of Linked Lists with operators
#include <stdio.h>
#include <stdlib.h>

struct listnode
{
    char Cat_Name[20];
    float Weight;
    char Cat_color[10];
    struct listnode *nextPtr;
};
typedef struct listnode Listnode;
typedef Listnode *ListnodePtr;

//Prototypes
void Menu();


int main(void)
{
    ListnodePtr startPtr = NULL;
    int User_choice;
    char item;

    Menu();
    scanf("%d", &User_choice);

    while(User_choice != 8){

        switch(User_choice){

            case 1:

        }
    }
















    return 0;
}

//Functions Block

void Menu(void)
{
    printf("\t\tWELCOME TO THE CAT SHELTER REGISTRY\t\t\n\n");
    printf("What do you want to do?\n");
    printf("Check if the registry is empty: (SET 1)\n");
    printf("Add a new cat at the end of the list: (SET 2)\n");
    printf("Add a new cat into an specific location: (SET 3)\n");
    printf("Delete a cat from the list into an specific location: (SET 4)\n");
    printf("Search a cat: (SET 5)\n");
    printf("Show all the cats of the shelter: (SET 6)");
    printf("Print the cat list backwards: (SET 7)\n");
    printf("Exit: (SET 8)\n");
}