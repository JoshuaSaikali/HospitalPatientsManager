#include "string.h"
#include "stdio.h"
#include "patient.h"

/********************************************************************/
void printPatient(PersonRec person)

{
    // create totalCost integer
    int cost = ((person.patient.dailyCost) * (person.patient.numDaysInHospital));
    char str[31];
    // sprintf first name and last name
    sprintf(str, "%s %s", person.firstName, person.familyName);
    // print employee
    printf("%-20s dept: %2d ", str, person.patient.department);
    printf(" days in hospital: %3d ", person.patient.numDaysInHospital);
    printf(" severity: %2d ", person.patient.severity);
    printf(" daily cost: %3d ", person.patient.dailyCost);
    printf(" total cost %5d\n", cost);
}

/********************************************************************/
void printPatients(PersonRec *person, int numRecords)
{

    // prints all patients
    printf("Patient List\n");
    for (int i = 0; i < numRecords; i++)
    {
        // checks if person is patient
        if (person->emplyeeOrPatient == 1)
        {
            printPatient(*person);
        }
        person++;
    }
}

/********************************************************************/
void printPatientSummary(PersonRec *person, int numRecords)
{
    // initialize variables
    int numPatients = 0;
    float totalCost = 0.0;
    float avgCost = 0.0;
    // calculate the corresponding values
    calculatePatientSummary(&numPatients, &totalCost, numRecords, person);
    avgCost = totalCost / numPatients;

    // print overall summary
    printf("Patient summary:\nTotal");
    printSummaryTemplate(numPatients, totalCost, avgCost, 0, 0.0);
}

void printSummaryDepartment(PersonRec *person, int numRecords)
{
    // initialize variables
    int numPatients = 0;
    float totalCost = 0.0;
    float avgCost = 0.0;
    float dailyCost = 0.0;
    // print summary by position
    printf("\nSummary by Department:\n");
    for (int i = 1; i < 7; i++)
    {
        // reset variables
        numPatients = 0;
        totalCost = 0.0;
        avgCost = 0.0;
        dailyCost = 0.0;
        // calculate the corresponding values
        calculateSummaryByDepartment(&numPatients, &totalCost, &dailyCost, numRecords, person, i);
        avgCost = totalCost / numPatients;

        // print summary by department
        printf("Department[%d] -", i);
        printSummaryTemplate(numPatients, totalCost, avgCost, 1, dailyCost);
    }
}

/********************************************************************/
void searchPatients(PersonRec *person, int numRecords)

{   
    // create family name variable
    // ask user for input
    char name[20];
    printf("Enter a family name: ");
    scanf("%s", name);
    printf("Patient List\n");
    for (int i = 0; i < numRecords; i++)
    {
        // checks if the family name is a match
        if (strcmp(person->familyName, name) == 0)
        {
            // checks if person is patient
            if (person->emplyeeOrPatient == 1)
            {
                printPatient(*person);
            }
        }
        person++;
    }
}

void calculatePatientSummary(int *numPatients, float *totalCost, int numRecords, PersonRec *person)
{
    // for each person
    for (int i = 0; i < numRecords; i++)
    {
        // if they are patients
        if (person->emplyeeOrPatient == 1)
        {
            *numPatients += 1;
            *totalCost += ((person->patient.dailyCost) * (person->patient.numDaysInHospital));
        }
        person++;
    }
}

void calculateSummaryByDepartment(int *numPatients, float *totalCost, float *dailyCost, int numRecords, PersonRec *person, int department)
{
    // for each person
    for (int i = 0; i < numRecords; i++)
    {
        // if they are patient
        if (person->emplyeeOrPatient == 1)
        {
            // if they are the same department as the parameter variable
            if (person->patient.department == department)
            {
                *numPatients += 1;
                *dailyCost += person->patient.dailyCost;
                *totalCost += ((person->patient.dailyCost) * (person->patient.numDaysInHospital));
            }
        }
        person++;
    }
}

void printSummaryTemplate(int numPatients, float totalCost, float avgCost, int byDep, float dailyCost)
{
    // template for printing patients data
    printf(" number of patients: %3d", numPatients);
    printf(" total cost to-date: %7.2f", totalCost);
    // checks if this function was called by summary by department
    if (byDep == 1)
    {
        printf(" daily cost: %7.2f", dailyCost);
    }
    printf(" average daily cost per patient: %7.2f\n", avgCost);
}