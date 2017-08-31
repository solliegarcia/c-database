#include "record.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototypes.h"
/**********************************************************
// Function Name:   mainMenu
//
// Description:     prompt the user and get user input
//
// Parameters:      none
//
// Return Values:   menu_value
***********************************************************/

int mainMenu()
{
    char input[10];
    int menu_value;
    printf("\n-------------------------------------------\n");
    printf("[1]\tAdd a new record in the database.\n");
    printf("[2]\tModify a record in the database.\n");
    printf("[3]\tPrint information about a record using the accountno as the key.\n");
    printf("[4]\tPrint all information in the database.\n");
    printf("[5]\tDelete an existing record from the database.\n");
    printf("[0]\tExit the program.\n");
    printf("-------------------------------------------\n");
    printf("Please enter a number: ");
    fgets(input, 10, stdin);
    printf("-------------------------------------------\n");
    fixString(input);
    sscanf(input, "%d", &menu_value);

    return menu_value;
}

/**********************************************************
// Function Name:   getaddress
//
// Description:     gets multiple lines of text from the user, the address.
//
// Parameters:      char address[ ], int length
//
// Return Values:   n/a
***********************************************************/

void getaddress (char address[ ], int length)
{
    char *holder;
    int go = 1;
    int counter = 0;
    int counter2;

    memset(address, 0, sizeof(address));

    holder = (char *)malloc(sizeof(char)*length);

    printf("Please enter the address. Once finished, press enter two times.\n");
    while (go == 1)
    {
        fgets(holder, length, stdin);

        counter = counter + strlen(holder);

        if (holder[0] == '\n' && holder[1] == '\0')
        {
            go = 0;
        }

        if (counter <= length)
        {
             strcat(address, holder);
        }
        else
        {
          printf("\nAddress must be less than 80 characters. Try again.");

          for (counter2 = 0; counter2 < length; counter2++)
          {
              address[counter2] = '\0';
          }
        }
    }
    fixString(address);
}

/**********************************************************
// Function Name:   getAccountNum
//
// Description:     prompt the user and get an account number.
//
// Parameters:      none
//
// Return Values:   accountno
***********************************************************/

int getAccountNum()
{
    char input[20];
    char* character_input;
    char bad_input;
    int accountno = -1; 
    int valid_input;
    printf("YOUR ACCOUNT NUMBER MUST BE BETWEEN 1-999999\n");

    printf("Please enter an account number: ");
    while (accountno < 0)
    {
        character_input = fgets(input, 20, stdin);
        if (character_input == input)
        {
            valid_input = sscanf(input, "%d %c", &accountno, &bad_input);
            if (valid_input != 1)
            {
                printf("ERROR: invalid input, please only enter positive integers!\nPlease enter an account number: ");
                accountno = -1;
            }
            else if (accountno < 0)
            {
                printf("ERROR: invalid input, please only enter positive integers! \nPlease enter an account number: ");
            }
        }
    }
    return accountno;
}

/**********************************************************
// Function Name:   getName
//
// Description:     prompt the user and get name.
//
// Parameters:      char name[]
//
// Return Values:
***********************************************************/

void getName(char name[])
{
    printf("Please enter your name: ");
    fgets(name, 25, stdin);
    fixString(name);
}
