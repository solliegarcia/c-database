#include "record.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**********************************************************
// Function Name:   addRecord
//
// Description:     adds a new bank record including account number,
//                  name, and address.
//
// Parameters:      struct record **record1, int accountno, char name[ ], char address[ ]
//
// Return Values:   0
***********************************************************/

int addRecord (struct record **record1, int uaccountno, char uname[ ], char uaddress[ ])
{
    struct record *temp;
    struct record *prev;
    struct record *holder;

    if (debugmode == 1)
    {
        printf("************************************************\n");
        printf("Calling function: addRecord\n");
        printf("Address of record1: %p\n", record1);
        printf("Value of account number: %d\n", uaccountno);
        printf("Name: %s\n", uname);
        printf("Address: %s\n", uaddress);
        printf("************************************************\n");
    }

    if ((*record1) == NULL)
    {
        (*record1) = (struct record*)malloc(sizeof(struct record));
        (*record1)->accountno = uaccountno;
        strcpy((*record1)->name, uname);
        strcpy((*record1)->address, uaddress);
        (*record1)->next = NULL;
    } 
    else if ((*record1) != NULL) 
    {
        temp = (*record1);
        if (temp->accountno <= uaccountno)
        {
            while(temp->accountno <= uaccountno && temp->accountno != 0)
            {
                prev = temp;
                if (temp->next == NULL)
                {
                    temp = (struct record*)malloc(sizeof(struct record));
                    temp->accountno = 0;
                    prev->next = temp;
                }
                if (temp->next != NULL)
                {
                    temp = temp->next;
                }
            }
            if(temp->accountno >= uaccountno && prev->next != NULL)
            {
                holder = (struct record*)malloc(sizeof(struct record));
                holder->next = temp;
                prev->next = holder;
                temp = holder;
            }
        }
        else 
        {
            prev = (struct record*)malloc(sizeof(struct record));
            prev->next = temp;
            temp = prev;
            (*record1) = temp;
        }
        temp->accountno = uaccountno;
        strcpy(temp->name, uname);
        strcpy(temp->address, uaddress);
    }
    return 0;
}

/**********************************************************
// Function Name:   printRecord
//
// Description:     prints the record according to the account number input.
//
// Parameters:      struct record *record1, int accountno
//
// Return Values:   -1: if database is empty, 0 if not found, 1 if successful 
***********************************************************/

int printRecord (struct record *record1, int uaccountno)
{
    struct record * temp;
    int ret;

    if (debugmode == 1)
    {
        printf("************************************************\n");
        printf("Calling function: printRecord\n");
        printf("Address of record1: %p\n", record1);
        printf("Value of account number: %d\n", uaccountno);
        printf("************************************************\n");
    }

    temp = record1;
    ret = 1;
    if(temp == NULL)
    { 
        ret = -1;
    }
    else
    {
        while(temp->accountno != uaccountno && temp->next !=NULL)
        {
            temp = temp->next;
        }

        if(temp != NULL && temp->next == NULL && temp->accountno != uaccountno)
        {
	        ret = 0;
        }
        else
        {
            printf("%d\n",temp->accountno);
            printf("%s\n",temp->name);
            printf("%s\n",temp->address);
        }
    }
    return ret;
}

/**********************************************************
// Function Name:   modifyRecord
//
// Description:     change the address of the account number.
//
// Parameters:      struct record *record1, int accountno, char address[ ]
//
// Return Values:   -1: databse empty, -1: account not found. 1: successful
***********************************************************/

int modifyRecord (struct record *record1, int uaccountno, char uaddress[ ])
{
    struct record * temp;
    int ret;
 
    if (debugmode == 1)
    {
        printf("************************************************\n");
        printf("Calling function: modifyRecord\n");
        printf("Address of record1: %p\n", record1);
        printf("Value of account number: %d\n", uaccountno);
        printf("Address: \n%s", uaddress);
        printf("************************************************\n");
    }

    temp = record1;
    ret = 1;

    if (temp == NULL)
    {
        ret = -1;
    }
    else if (temp != NULL)
    {
        while (temp->accountno != uaccountno && temp->next != NULL)
	    {
	       temp = temp->next;
	    }
        if (temp != NULL && temp->next == NULL && temp->accountno != uaccountno) 
        {
            ret = 0;
        }
        else 
        {
            memset(temp->address, 0, sizeof(temp->address));
            strcpy(temp->address, uaddress);
        }
    }
    return ret;
}

/**********************************************************
// Function Name:   printAllRecords
//
// Description:     print all the records in the system.
//
// Parameters:      struct record *record1
//
// Return Values:   n/a
***********************************************************/

void printAllRecords(struct record *record1)
{
    struct record * temp;
    if (debugmode == 1)
    {
        printf("************************************************\n");
        printf("Calling function: printAllRecords\n");
        printf("Address of record1: %p\n", record1);
        printf("************************************************\n");
    }

    
    temp = record1;
    if (temp == NULL)
    {
        printf("The database is empty!\n");
    }
    else 
    {
        while(temp != NULL)
        {
            printf("\n" );
            printf("%d\n",temp->accountno );
            printf("%s\n",temp->name );
            printf("%s\n",temp->address );
            temp = temp->next;
        }
    }
}

/**********************************************************
// Function Name:   deleteRecord
//
// Description:     deletes a record from the database
//                  using the account number as a key.
//
// Parameters:      struct record **record1, int accountno
//
// Return Values:   -1: databse empty. -2 account not found: greater than 1, the amount of deleted records
***********************************************************/

int deleteRecord(struct record **record1, int uaccountno)
{
    struct record *temp;
    struct record *prev;
    struct record *holder;
    int ret, duplicate_counter;

    if (debugmode == 1)
    {
        printf("************************************************\n");
        printf("Calling function: deleteRecords\n");
        printf("Address of record1: %p\n", record1);
        printf("Value of account number: %d\n", uaccountno);
        printf("************************************************\n");
    }
    duplicate_counter = 0;
    ret = -1;
    temp = (*record1);
    prev = (*record1);

    while(temp != NULL)
    {
        if(temp == *record1)
        {
            if(uaccountno == temp->accountno)
            {
                holder = temp;
                *record1 = temp->next;
                temp = temp->next;
                prev = prev->next;

                free(holder);
                duplicate_counter++;

                ret = 0;
             }
             else
             {
                 temp = temp->next;
             }
        }
        else if(uaccountno == temp->accountno)
        {
            holder = temp;
            prev->next = temp->next;
            temp = temp->next;

            free(holder);
            duplicate_counter++;
 
            ret = 0;
        }
        else
        {
            prev = prev->next;
            temp = temp->next;
        }
        
    }
    if (duplicate_counter >= 1)
    {
        ret = duplicate_counter;
    }
    return ret;
}

