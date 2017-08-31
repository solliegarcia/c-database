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
// File:        prototypes.c
//
// Description: This file contains the function prototypes for
//              all functions in the program.
******************************************************/

void fixString(char []);

int readfile(struct record **, char [ ]);

void writefile(struct record *, char [ ]);

int addRecord (struct record **, int, char [ ],char [ ]);

int printRecord (struct record *, int);

int modifyRecord (struct record *, int, char [ ]);

void printAllRecords(struct record *);

int deleteRecord(struct record **, int);

void getaddress (char [ ], int);

int mainMenu();

void getName();

int getAccountNum();


