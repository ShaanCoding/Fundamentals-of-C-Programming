#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __MENU_H__
#define __MENU_H__
#include "menu.h"
#endif

#ifndef __USERINPUT_H__
#define __USERINPUT_H__
#include "userInput.h"
#endif

#define STRING_LENGTH 50
#define ARRAY_LENGTH 500

struct student {
    char name[STRING_LENGTH];
    char address[STRING_LENGTH];
    char phone[STRING_LENGTH];
    char email[STRING_LENGTH];
    char studentID[STRING_LENGTH];
    char course[STRING_LENGTH];
};
typedef struct student student_t;
  
/* User needs to: Book a ticket for category, see number of people in queue, cancel ticket and view all booking records */

/* Function prototypes */
int main(void);
void displayMenu(void);
void startApplication(student_t admissionList[], int* admissionIndex, student_t studentCardList[], int* studentCardIndex, student_t enrollmentAndCourseAdviseList[], int* enrollmentAndCourseAdviseIndex, student_t travelConcessionList[], int* travelConcessionIndex, student_t resultAndGraduationsList[], int* resultAndGraduationsIndex);
void displayAdmissionMenu(void);
void createStudent(student_t studentList[] , int* studentIndex);
void listQueue(student_t studentList[], int* studentIndex, char title[]);
void cancelQueue(student_t studentList[], int* studentIndex, char title[]);
void bookUniversityAdmission(student_t admissionList[], int* admissionIndex);
void admission(student_t admissionList[], int* admissionIndex);