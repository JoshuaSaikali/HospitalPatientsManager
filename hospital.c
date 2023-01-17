

#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "string.h"
#include "populateRecords.h"
#include "patient.h"
#include "employee.h"

#define NUM_RECORDS 20

void instruct();
int menu();
void printStructSizes();
int askToQuit();

int main(int argc, char *argv[])
{

	struct person *person = NULL;
	int numRecords = 0; // number of records to be created
	char rc = 0;

	// check the command line parameters for correct number of paramaters
	// if the number is wrong prompt for correct usage and quit
	if (argc != 2)
	{
		instruct();
	}

	// add code to get the number of records to be created
	// if number of records is not given then insruct the user what is required.
	if (atoi(argv[1]) < 1)
	{
		printf("Please enter a positive number\n");
		instruct();
	}
	else
	{
		// sets numRecords to cmd line argument
		numRecords = atoi(argv[1]);

		// if numRecords is greater than the max than it caps out
		if (numRecords > (int)NUM_RECORDS)
		{
			numRecords = NUM_RECORDS;
		}
	}

	// allocates memory for the person array
	person = malloc(numRecords * sizeof(PersonRec));

	// populating the array person with data of patients and employees
	populateRecords(person, numRecords);

	// add code here for menu handling
	while (1)
	{
		int choice = menu();
		while (choice < 0 || choice > 6)
		{
			printf("\n\nInvalid input - Options are between 0-5.\n\n");
			choice = menu();
		}
		switch (choice)
		{
		case 0:
			// quits program
			if (askToQuit() == 1)
			{
				free(person);
				exit(1);
			}
			break;
		case 1:
			// prints all employees
			printEmployees(person, numRecords);
			break;
		case 2:
			// search for all patients by Family name
			searchPatients(person, numRecords);
			break;
		case 3:
			// summary of employees data
			printEmployeesSummary(person, numRecords);
			break;
		case 4:
			// summary of patients data
			printPatientSummary(person, numRecords);
			break;
		case 5:
			// size of structures
			printStructSizes();
			break;
		case 6:
			// summary by department for patients
			printSummaryDepartment(person, numRecords);
			break;
		default:
			// if for somewhat it failed, this should never print
			printf("failed %d", choice);
		}
		printf("\n\n\n\n");
	}

	return 0;
}

void instruct()
{
	// instructs user for correct input and quits
	printf("Invoking the program: program_name number_of_records\n");
	printf("For example: hospital 37\n");
	exit(1);
}

int menu()
{
	// Menu Option
	printf("Welcome to the menu - Enter an option.\n");
	printf("1. Print all employees\n");
	printf("2. Search for all patients by Family Name\n");
	printf("3. Summary of Employees Data\n");
	printf("4. Summary of Patients data\n");
	printf("5. Size of structures (PersonRec, PatientRec and EmployeeRec)\n");
	printf("6. Summary by Department (Patients)\n");
	printf("0. Quit\n");
	int choice = -1;
	printf("Enter an option: ");
	scanf("%d", &choice);
	printf("\n\n\n\n");

	return (choice);
}

void printStructSizes()
{
	printf("Size of structures\n");
	printf("Size of PersonRec: %ld\n", sizeof(PersonRec));
	printf("Size of PatientRec: %ld\n", sizeof(PatientRec));
	printf("Size of EmployeeRec: %ld\n", sizeof(EmployeeRec));
}

int askToQuit()
{
	char input[1];
	printf("Do you want to quit? (y/n) ");
	scanf("%s", input);
	if (strcmp(input, "Y") == 0 || strcmp(input, "y") == 0)
	{
		return 1;
	}
	else if (strcmp(input, "N") == 0 || strcmp(input, "n") == 0)
	{
		return 0;
	}
}