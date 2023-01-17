#include "employee.h"
#include "stdio.h"

void printEmployee(PersonRec person)

{
    // calculates salary to-date
    float salaryToDate = (float)(person.emp.salary * (person.emp.yearsService));
    char str[31];
    // sprint first name and last name
    sprintf(str, "%s %s", person.firstName, person.familyName);
    // print employee
    printf("%-20s dept: %2d ", str, person.emp.department);
    printf(" salary: %9.2f ", person.emp.salary);
    printf(" position: %2d ", person.emp.position);
    printf(" years of service: %4d ", person.emp.yearsService);
    printf(" salary to-date: %11.2f\n", salaryToDate);
}

void printEmployees(PersonRec *person, int numRecords)
{
    // prints all employees
    printf("Hospital Employees\n");
    for (int i = 0; i < numRecords; i++)
    {
        // checks if person is employee
        if (person->emplyeeOrPatient == 0)
        {
            printEmployee(*person);
        }
        person++;
    }
}

void printEmployeesSummary(PersonRec *person, int numRecords)
{
    // initialize variables
    int numEmployees = 0;
    float totalSalary = 0.0;
    float avgSalary = 0.0;
    // calculate the corresponding values
    calculateSummary(&numEmployees, &totalSalary, numRecords, person);
    avgSalary = totalSalary / numEmployees;

    // print overall summary
    printf("Employee summary:\nTotal");
    printSummary(numEmployees, totalSalary, avgSalary);

    // print summary by position
    printf("\nSummary by position:\n");
    for (int i = 0; i < 4; i++)
    {
        // reset variables
        numEmployees = 0;
        totalSalary = 0.0;
        avgSalary = 0.0;
        // calculate the corresponding values
        calculateSummaryByPosition(&numEmployees, &totalSalary, numRecords, person, i);
        avgSalary = totalSalary / numEmployees;
        
        // print summary by position
        printf("Position[%d] -", i);
        printSummary(numEmployees, totalSalary, avgSalary);
    }
}

void calculateSummary(int *numEmployees, float *totalSalary, int numRecords, PersonRec *person)
{
    //for each person
    for (int i = 0; i < numRecords; i++)
    {
        // if person is employee
        if (person->emplyeeOrPatient == 0)
        {
            *numEmployees += 1;
            *totalSalary += person->emp.salary;
        }
        person++;
    }
}

void calculateSummaryByPosition(int *numEmployees, float *totalSalary, int numRecords, PersonRec *person, int pos)
{
    //for each person
    for (int i = 0; i < numRecords; i++)
    {
        // if they are employees
        if (person->emplyeeOrPatient == 0)
        {
            // if they are the same pos as the parameter variable
            if (person->emp.position == pos)
            {
                *numEmployees += 1;
                *totalSalary += person->emp.salary;
            }
        }
        person++;
    }
}

void printSummary(int numEmployees, float totalSalary, float avgSalary)
{
    // template for printing employee data
    printf(" number of employees: %3d", numEmployees);
    printf(" Total salary: %10.2f", totalSalary);
    printf(" Average salary: %8.2f\n", avgSalary);
}