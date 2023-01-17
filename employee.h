// file is emoloyee.h
#ifndef EMPLOYEE_HEADER
#define EMPLOYEE_HEADER

// include files 
#include "struct.h"

/******************************************************/
// function prototypes

void printEmployees(PersonRec *person, int numRecords);
void printEmployeesSummary(PersonRec *person, int numRecords);
void calculateSummary(int *numEmployees, float *totalSalary, int numRecords, PersonRec *person);
void calculateSummaryByPosition(int *numEmployees, float *totalSalary, int numRecords, PersonRec *person, int pos);
void printSummary(int numEmployees, float totalSalary, float avgSalary);

#endif