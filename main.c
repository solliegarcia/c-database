/*********************************************************
// Name:        Sollie Garcia
//
// Homework:    3b
//
// Class:       ICS 212
//
// Instructor:  Ravi Narayan
//
// Date:        Feb 5, 2017
//
// File:        main.c
//
// Description: This file contains the driver for navigating
//              the entire of the program.
********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "record.h"
#include "prototypes.h" 

int debugmode;

/**********************************************************
// Function Name:   main
//
// Description:     handles an option to run the program in "debug" mode
//                  Depending on what the user inputs for the menu,
//                  the main file will run the required functions to
//                  filfill the task requested
//
// Parameters:      int argc, char *argv[]
//
// Return Values:   0
***********************************************************/
int main(int argc, char *argv[])
{
    int menu_value, go, menu;
    struct record * start;
    char input[10];
    go = 1;
    start = NULL;
    if (argc == 2)
    {
        if (strcmp(argv[1], "debug") == 0)
        {
            printf("\n***** Debug mode on *****\n\n");
            debugmode = 1;
        }
        else
        {
            printf("ERROR: To many arguments or wrong argument.\n");
            exit(0);
        }
    }
    else if (argc > 2) 
    {
        printf("ERROR: To many arguments or wrong arugment.\n");
        exit(0);
    } 
    printf("Would you like to start with the program with a file import? (0/1)\n");
    fgets(input, 10, stdin);
    fixString(input);
    sscanf(input, "%d", &menu);
    switch(menu)
    {
        case 0:
            break;

        case 1:
            readfile(&start, "database.txt");
            break;
        default:
            printf("Invalid input! Starting without file import.\n");
            break;
    }

    
    printf("\t\t\tWelcome to the Bank of ICS212! \nTo navigate through the program type the value in the [] and hit enter!");
    menu_value = mainMenu();
    while(go == 1)
    {
        switch (menu_value)
        {
            case 0:
                writefile(start, "database.txt");
                printf("Goodbye!\n");
                go = 0;
                break;

            case 1:
            {
                int accountno;
                int length = 80;
                char address[80], name[25];
                accountno = getAccountNum();
                getName(name);
                getaddress(address, length);

                addRecord(&start, accountno, name, address);
                printf("Success! Returning to main menu...");
                menu_value = mainMenu();
                break;

            }

            case 2:
            {
                int accountno, ret;
                int length = 80;
                char newAddress[80];
                printf("Please have your account number and new address ready for input!\n");
                accountno = getAccountNum();
                getaddress(newAddress, length);
                ret = modifyRecord(start, accountno, newAddress);
                if (ret == 1)
                {
                    printf("Success!\n");
                }
                else if (ret == 0)
                {
                    printf("The record could not be found with the given account number: %d\n", accountno);
                }
                else
                {
                    printf("The databse is empty!\n");
                }
                printf("Returning to main menu...");
                menu_value = mainMenu();
                break;
            }

            case 3:
            {
                int accountno, ret;
                printf("Please have your account number you wish to print ready for input!\n");
                accountno = getAccountNum();
                ret = printRecord(start, accountno);
		if (ret == 1)
		{
                    printf("Success!\n");
		}
		else if (ret == 0)
		{
		    printf("The record could not be found with the given account number: %d\n", accountno);
		}
		else 
		{
	            printf("The database is empty!\n");
  		}
		printf("Returning to main menu...");
                menu_value = mainMenu();
                break;
            }

            case 4:
            {
                printf("Printing all records!\n\n");
                printAllRecords(start);
		printf("\n");
		printf("Returning to main menu...");
                menu_value = mainMenu();
                break;
            }

            case 5:
            {
                int accountno, ret;
                printf("Please have the account number you wish to remove ready!\n");
                accountno = getAccountNum();
                ret = deleteRecord(&start, accountno);
		printf("\n");
                if (ret == -1)
                {
                    printf("The account number: %d could not be deleted.\n\nReturning to main menu...", accountno); 
                } 
                else
                {
                    printf("Success! Deleted %d records.\nReturning to main menu...", ret);
                }
                menu_value = mainMenu();
                break;
            }

            default:
                printf("Invalid input!\n");
                menu_value = mainMenu();
                break;
        }
    }
    return 0;
}
