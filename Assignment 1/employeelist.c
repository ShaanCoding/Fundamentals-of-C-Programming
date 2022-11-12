/******************************************************************************
 * 48430 Fundamentals of C Programming - Assignment 2
 * Name: Mohammed Shaan Shahroze Khan
 * Student ID: 13940236
 * Date of submission: 2nd October 2022 (02/10/2022)
 * A brief statement on what you could achieve (less than 50 words):
 * - This is a simple console based application that stores, saves, adds,
 * deletes & loads a managed list of 5 employees with their FTE, DOB, Name
 * and seniority within the company 
 *
 * A brief statement on what you could NOT achieve (less than 50 words):
 * - This program is limited to only 5 employees
 * - This program does not check if a certain month is 31 or 30 days long
 * - This program does not handle spaces for names
 *
 *****************************************************************************/

/******************************************************************************
 * List header files - do NOT use any other header files. Note that stdlib.h is
 * included in case you want to use any of the functions in there. However the
 * task can be achieved with stdio.h and string.h only.
 *****************************************************************************/
#include <stdlib.h>
#include <stdio.h>  /* Used printf, scanf, getchar, FILE, fopen, fprint,
fclose, fscanf */
#include <string.h> /* Used strcpy */

/******************************************************************************
 * List preprocessing directives - you may define your own.
 *****************************************************************************/
#define MAX_COMPANY_SIZE 5
#define MAX_NAME_SIZE 11
#define DB_NAME "database"

/******************************************************************************
 * List structs - you may define struct date_time and struct employee only.
 * Each struct definition should have only the fields mentioned in the
 * assignment description.
 *****************************************************************************/
struct date {
    int day;
    int month;
    int year;
};
typedef struct date date_t;

struct employee {
    char name[MAX_NAME_SIZE];
    float fte;
    int level;
    date_t birthday;
};
typedef struct employee employee_t;

/******************************************************************************
 * Function prototypes - do NOT change the given prototypes. However you may
 * define your own functions if required.
 *****************************************************************************/
void printMenu(void);
void addEmployee(employee_t employees[], int *index);
void deleteEmployee(int *index);
void displayEmployee(const employee_t employees[], const int index);
void saveEmployeeList(const employee_t employees[], const int index);
void loadEmployeeList(employee_t *employees, int *index);

date_t getEmployeeBirthday(void);
int getDay(void);
int getMonth(void);
int getYear(void);
float getEmployeeFTERatio(void);
int getEmployeeLevel(void);

/******************************************************************************
 * Main
 *****************************************************************************/
int main(void) {
    employee_t employees[MAX_COMPANY_SIZE];
    int employeeIndex = 0;

    int loopFlag = 1;

    while (loopFlag) {
        /* get user input & clear buffer incase of character input */
        printMenu();
        printf("Enter your choice>\n");
        int userInput;
        scanf("%d", &userInput);
        while ((getchar()) != '\n');

        /* Main program, which calls functions to navigate between menus */
        switch (userInput) {
        case 1:
            /* Reached limit of number of employees that can be added */
            if (employeeIndex >= 5) {
                printf("List is full");
                continue;
                /* Adds new employee */
            } else {
                addEmployee(employees, &employeeIndex);
            }
            break;
        case 2:
            /* If list is empty, will not delete further */
            if (employeeIndex <= 0) {
                printf("List is empty");
                /* If employee is present, will delete */
            } else {
                deleteEmployee(&employeeIndex);
            }
            break;
        case 3:
            /* If list is empty, will not display */
            if (employeeIndex <= 0) {
                printf("List is empty");
                /* Displays list of employees */
            } else {
                displayEmployee(employees, employeeIndex);
            }
            break;
        case 4:
            /* saves list of employees to database */
            saveEmployeeList(employees, employeeIndex);
            break;
        case 5:
            /* loads list of employees from database */
            loadEmployeeList(employees, &employeeIndex);
            break;
        case 6:
            /* Exits the program by terminating loop */
            loopFlag = 0;
            break;
        default:
            printf("Invalid choice.");
            break;
        }
    }

    return 0;
}

/******************************************************************************
 * FUNCTION DEFINITIONS
 *****************************************************************************/

/******************************************************************************
 * This function prints the initial menu with all instructions on how to use
 * this program.
 * inputs:
 * - none
 * outputs:
 * - none
 *****************************************************************************/
void printMenu(void) {
    printf("\n\n"
           "1. add employee\n"
           "2. delete last employee\n"
           "3. display employee list\n"
           "4. save the employee list to the database\n"
           "5. read the employee list from the database\n"
           "6. exit the program\n");
}

/******************************************************************************
 * This function adds a new employee of type employee_t to the employee array
 * declaed in the main function
 * inputs:
 * - @param employees - passing the employees array by reference to assign data
 *
 * - @param index - passing the value of index as a pointer to know the which
 * index employees is having a new employee added to, as well as incrementing
 * the index when successful
 *
 * outputs:
 * - none
 *****************************************************************************/
void addEmployee(employee_t employees[], int *index) {
    employee_t employee;

    /* Gets users name and limits it to a total of 10 characters */
    printf("Enter name>");
    char employeeName[MAX_NAME_SIZE];
    scanf("%10s", employeeName);
    while ((getchar()) != '\n');

    /* Assign employee name */
    strcpy(employee.name, employeeName);

    /* Assign generated employee date of birth to employee struct */
    employee.birthday = getEmployeeBirthday();

    /* Get employee FTE ratio. Range (>= 0.00 && <= 1.00 inclusive) */
    employee.fte = getEmployeeFTERatio();

    /* Get employee seniority level. Range (>= 7 && <= 18 inclusive) */
    employee.level = getEmployeeLevel();

    /* Add employee to employees array */
    employees[*index] = employee;
    /* Increment the total number of employees in index */
    *index = *index + 1;
}

/******************************************************************************
 * This function deletes the latest employee from the employees array
 * inputs:
 * - @param index - Passing pointer employeeIndex, for variable to be
 * deincremented
 * outputs:
 * - none
 *****************************************************************************/
void deleteEmployee(int *index) {
    /* Decrements index of number of employees, allowing the area to be
    overwritten with a new employee later & not-shown */
    *index = *index - 1;
}

/******************************************************************************
 * This function displays all employees from the employee array in a table
 * inputs:
 * - @param employees - The list of employees to print from
 * - @param index - The current count of employees stored in employees
 * outputs:
 * - none
 *****************************************************************************/
void displayEmployee(const employee_t employees[], const int index) {
    printf("Name       Birthday   FTE   Level\n"
    "---------- ---------- ----- -----\n");

    /* Loops through index number of employees, where index is employee count */
    int i = 0;
    for (i = 0; i < index; i++) {
        printf("%-10s %02d-%02d-%d %.3f %02d\n",
        employees[i].name,
        employees[i].birthday.day,
        employees[i].birthday.month,
        employees[i].birthday.year,
        employees[i].fte,
        employees[i].level
        );
    }
}

/******************************************************************************
 * This function will save employees data as text into the file named 
 * "database"
 * if the file does not exist, a new file will be created
 * ** NOTE: Previous data will be overwritten **
 * inputs:
 * - @param employees - The list of employees to save
 * - @param index - The current count of employees in employees
 * outputs:
 * - none
 *****************************************************************************/
void saveEmployeeList(const employee_t employees[], const int index) {
    /* Opens the process to begin writing the file */
    FILE *fp = NULL;
    fp = fopen(DB_NAME, "w");

    /* If file is locked or an exception occurs, throw error */
    if (fp == NULL) {
        printf("Write error\n");
        return;
    }

    /* Save all data - In a CSV format */
    fprintf(fp, "%d\n", index);
    int i = 0;
    for (i = 0; i < index; i++) {
        fprintf(fp, "%d,%d,%d,%f,%d,%s\n",
        employees[i].birthday.day,
        employees[i].birthday.month,
        employees[i].birthday.year,
        employees[i].fte,
        employees[i].level,
        employees[i].name
        );
    }

    /* Closes the process writing to the file */
    fclose(fp);
}

/******************************************************************************
 * This function will load employees data from the file named "database"
 * inputs:
 * - @param employees - The list of employees to load to
 * - @param index - The number of employees in the database
 * outputs:
 * - none
 *****************************************************************************/
void loadEmployeeList(employee_t *employees, int *index) {
    /* Opens the process to begin reading the file */
    FILE *fp = NULL;
    fp = fopen(DB_NAME, "r");

    /* If file is locked or an exception occurs, throw error */
    if (fp == NULL) {
        printf("Read error");
        return;
    }

    /* Save all data - In a CSV format */
    *index = 0;
    fscanf(fp, "%d[\n]", index);

    int i;
    for (i = 0; i < *index; i++) {
        fscanf(fp, "%d,%d,%d,%f,%d,%s[\n]",
        &employees[i].birthday.day,
        &employees[i].birthday.month,
        &employees[i].birthday.year,
        &employees[i].fte,
        &employees[i].level,
        employees[i].name
        );
    }

    /* Closes the process reading the file */
    fclose(fp);
}

/******************************************************************************
 * GET FUNCTIONS
 *****************************************************************************/

/******************************************************************************
 * This function will get the birthday of the employee
 * inputs:
 * - none
 * outputs:
 * - @return - the employees birthday in struct type date_t
 *****************************************************************************/
date_t getEmployeeBirthday(void) {
    date_t employeeDateOfBirth;

    /* Gets employee birthday day. Range (>= 1 && <= 31 inclusive) */
    employeeDateOfBirth.day = getDay();
    /* Get employee birthday month. Range (>= 1 && <= 12 inclusive) */
    employeeDateOfBirth.month = getMonth();
    /* Get employee birthday year. Range (>= 1800 && <= 2017 inclusive) */
    employeeDateOfBirth.year = getYear();

    return employeeDateOfBirth;
}

/******************************************************************************
 * This function will get the day the employee was born (a day between 1 & 31)
 * inputs:
 * - none
 * outputs:
 * - @return - the employees birthday day as an integer type
 *****************************************************************************/
int getDay(void) {
    /* Infinite loop that exits when day between 1 & 31 is inputted */
    for (;;) {
        printf("Enter birthday: day>");
        int employeeDay;
        scanf("%d", &employeeDay);
        /* clears buffer to prevent infinite loops from bad data */
        while ((getchar()) != '\n');

        if (employeeDay >= 1 && employeeDay <= 31) {
            return employeeDay;
        } else {
            printf("Invalid day. ");
        }
    }
}

/******************************************************************************
 * This function will get the month the employee was born
 * (a month between 1 & 12)
 * inputs:
 * - none
 * outputs:
 * - @return - the employees birthday month as an integer type
 *****************************************************************************/
int getMonth(void) {
    /* Infinite loop that exits when month between 1 & 12 is inputted */
    for (;;) {
        printf("Enter birthday: month>");
        int employeeMonth;
        scanf("%d", &employeeMonth);
        /* clears buffer to prevent infinite loops from bad data */
        while ((getchar()) != '\n');

        if (employeeMonth >= 1 && employeeMonth <= 12) {
            return employeeMonth;
        } else {
            printf("Invalid month. ");
        }
    }
}

/******************************************************************************
 * This function will get the year the employee was born
 * (a year between 1800 & 2017)
 * inputs:
 * - none
 * outputs:
 * - @return - the employees birthday year as an integer type
 *****************************************************************************/
int getYear(void) {
    /* Infinite loop that exits when year between 1800 & 2017 is inputted */
    for (;;) {
        printf("Enter birthday: year>");
        int employeeYear;
        scanf("%d", &employeeYear);
        /* clears buffer to prevent infinite loops from bad data */
        while ((getchar()) != '\n');

        if (employeeYear >= 1800 && employeeYear <= 2017) {
            return employeeYear;
        } else {
            printf("Invalid year. ");
        }
    }
}

/******************************************************************************
 * This function will get the FTE ratio the employee works
 * (a float between 0.00 & 1.00)
 * inputs:
 * - none
 * outputs:
 * - @return - the employees FTE ratio as an float type
 *****************************************************************************/
float getEmployeeFTERatio(void) {
    /* Infinite loop that exits when FTE between 0.00 & 1.00 is inputted */
    for (;;) {
        printf("Enter FTE>");
        float employeeFTE;
        scanf("%f", &employeeFTE);
        /* clears buffer to prevent infinite loops from bad data */
        while ((getchar()) != '\n');

        if (employeeFTE >= 0 && employeeFTE <= 1) {
            return employeeFTE;
        } else {
            printf("Invalid FTE. ");
        }
    }
}

/******************************************************************************
 * This function will get the level the employee is in the company
 * (a int between 7 & 18)
 * inputs:
 * - none
 * outputs:
 * - @return - the employees employment level as an int
 *****************************************************************************/
int getEmployeeLevel(void) {
    for (;;) {
        /* Infinite loop that exits when level between 7 & 18 is inputted */
        printf("Enter level>");
        int employeeLevel;
        scanf("%d", &employeeLevel);
        /* clears buffer to prevent infinite loops from bad data */
        while ((getchar()) != '\n');

        if (employeeLevel >= 7 && employeeLevel <= 18) {
            return employeeLevel;
        } else {
            printf("Invalid level. ");
        }
    }
}
