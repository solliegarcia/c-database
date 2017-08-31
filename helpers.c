#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototypes.h"
#include "record.h"
/**********************************************************
// Function Name:   fixString
//
// Description:     replaces all the new line character with a null character
//
// Parameters:      char string[]
//
// Return Values:   n/a
***********************************************************/

void fixString(char string[])
{
    if (string[strlen(string) - 1] == '\n')
    {
        string[strlen(string) - 1] = '\0';
    }
}

/**********************************************************
// Function Name:   readfile
//
// Description:     attempts to read a file and import the data into 
					the database. It for some reason breaks the entire program
					so I included an option in the menu to run without reading file.
//
// Parameters:      struct record **record1, char filename[ ]
//
// Return Values:   -1 if no file, 0 if ok
***********************************************************/

int readfile( struct record **record1, char filename[ ] )
{
	FILE * input_file;
    int accountno;
    char name[25], address1[40], address2[40], address[80];
    char holder[10];
    int returnValue = 0;

    if(debugmode)
    { 
        printf("Debug Mode On\n");

        printf("\nFunction call: readfile\n");
        printf("Parameters passed\n");

        printf("filename: %s\n", filename);
    }

    input_file = fopen(filename, "r");

    if(input_file == NULL)
    {
        returnValue = -1;
    }
    else
    {
        while(fscanf(input_file, "%d", &accountno) !=  EOF)
        {
	   fgets(holder, 10, input_file); /*gets the line after the fscan*/

           fgets(name, 25, input_file);

           fgets(address1, 40, input_file);
           fgets(address2, 40, input_file);
           strcat(address1, address2);
           strcpy(address, address1);
 
           
           addRecord(record1, accountno, name, address); 
           
       }
    }
 
    fclose(input_file);

    return returnValue;
}

/**********************************************************
// Function Name:   writefile
//
// Description:     writes the current database to a file.
//
// Parameters:      struct record *record1, char filename[]
//
// Return Values:   none
***********************************************************/

void writefile(struct record *record1, char filename[])
{
	FILE * output_file;
	struct record *temp;
	temp = record1;

	output_file = fopen(filename, "w");

	while(temp != NULL)
    {
        fprintf(output_file, "%d\n", temp->accountno);
        fprintf(output_file, "%s\n", temp->name);
        fprintf(output_file, "%s\n", temp->address);
        fprintf(output_file, "\n");

        temp = temp->next;
    }

    fclose(output_file);
}

