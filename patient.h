// file is patient.h

#ifndef PATIENT_HEADER
#define PATIENT_HEADER


// include files 
#include "struct.h"

/******************************************************/
// function prototypes

void printPatients(PersonRec *person, int numRecords);
void printPatientSummary(PersonRec *person, int numRecords);
void searchPatients(PersonRec *person, int numRecords);
void calculatePatientSummary(int *numPatients, float *totalCost, int numRecords, PersonRec *person);
void printSummaryDepartment(PersonRec *person, int numRecords);
void calculateSummaryByDepartment(int *numPatients, float *totalCost, float *dailyCost, int numRecords, PersonRec *person, int department);
void printSummaryTemplate(int numPatients, float totalCost, float avgCost, int byDep, float dailyCost);

#endif