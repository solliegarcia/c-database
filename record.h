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
// File:        record.h
//
// Description: This file contains the structure for a record. 
********************************************************/

extern int debugmode;

struct record
{
    int                accountno;
    char               name[25];
    char               address[80];
    struct record*     next;
};
