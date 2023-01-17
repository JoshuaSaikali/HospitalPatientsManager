Purpose :  Manipulating records of patients and employees in a hospital.
Developer Name: Joshua Saikali
Date: November 4th 2022

Files: employee.c, employee.h, hospital.c, patient.c, patient.h, populateRecords.c, populateRecords.h, struct.h
    -hospital.c
        - This file contains the control of the program. The control for the menu can be found in here.
    -employee.c
        - This file contains the functions to display the employees data to the user.
    -patient.c
        - This file contains the functions to dispay the patients data to the user.
    -populateRecords.c
        - This file contains the functions to populate the database with people.
    -struct.h
        - This file contains the structures for employees, patients, and person.

    -All other header files contain the function prototypes for their respective '.c' file.


Compiling Instructions:
- To begin, compile the program with the following command:
    > gcc hospital.c patient.c employee.c populateRecords.c

- To run the program enter the following command:
    > ./a.out NUM_RECORDS
        - NUM_RECORDS - can be any positive integer
    For example:
        > ./a.out 37


Limitations:
- The maximum number of records that can be created is 20 as per the definition of NUM_RECORDS.
    - If for example, > ./a.out 40  -  is inputed than numRecords will be set to 20
- There are a few limitations when it comes to user input
    - When using the menu, please enter an INTEGER. If a non-integer is entered the program will malfunction.
    - When using option 2, 'Search for all patients by Family Name', this option is case sensitive. 
        -You NEED to have the exact family name to find the patients.
        -Example: DO - "Johnson", NOT - "johnson"
        -Also, when entering you search query, the name has to be less than 20 characters.
            -Failure to do so will result in the program malfunctioning
    - When prompt if you want to quit, if a letter is entered that is anything other than "y", "Y", "n" and "N"
        then the program will interpret your answer as a no and the program will continue.
    - For option 4, Summary of Patients data, there is no instructions in the spec sheet for this option.
        -Even though there is nothing in the spec sheet I still completed the functionality for it.
        -There are no issues/limitations with this, just letting you know.
        -For the bonus question, it says to combine it with the Summary of Patients, but to also include this option (4)
            I decided to break the two Summary's into two different options
            - Option 4 - Summary of Patients
            - Option 6 - Summary by Department (Patients)
                (If you have any questions please feel free to email me as the spec sheet is a little unspecific)
                    - Joshuasaikali@cmail.carleton.ca 


How-to-use Instructions:
    - Once loaded into the program, you will be greated by a menu.
    - This menu has 7 options :
        1. Print all employees
        2. Search for all patients by Family Name
        3. Summary of Employees Data
        4. Summary of Patients data
        5. Size of structures (PersonRec, PatientRec and EmployeeRec)
        6. Summary by Department (Patients)
        0. Quit
    - Each option's function corresponds to it's title.
    - Enter the option that you would like to choose. Just enter a number and press ENTER.
    - Once an option has been chosen, you will be brough back to the menu.
    - Whenever you would like to quit, enter 0, a prompt will be brought up, if you would like to quit
        enter 'y' or 'Y' to confirm.
