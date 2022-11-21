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

void createStudent(student_t studentList[] , int* studentIndex);
void listQueue(student_t studentList[], int* studentIndex, char title[]);
void cancelQueue(student_t studentList[], int* studentIndex, char title[]);

void displayAdmissionMenu(void);
void bookUniversityAdmission(student_t admissionList[], int* admissionIndex);
void admission(student_t admissionList[], int* admissionIndex);

void displayStudentCardMenu();
void bookStudentCard(student_t studentCardList[], int* studentCardIndex);
void studentCard(student_t studentCardList[], int* studentCardIndex);

void displayEnrollmentAndCourseAdviseMenu();
void bookEnrollmentAndCourseAdvise(student_t enrollmentAndCourseAdviseList[], int* enrollmentAndCourseAdviseIndex);
void enrollmentCourseAdvise(student_t enrollmentAndCourseAdviseList[], int* enrollmentAndCourseAdviseIndex);

void displayTravelConcessionMenu();
void bookTravelConcession(student_t travelConcessionList[], int* travelConcessionIndex);
void travelConcession(student_t travelConcessionList[], int* travelConcessionIndex);

void displayResultAndGraduationMenu();
void bookResultAndGraduation(student_t resultAndGraduationsList[], int* resultAndGraduationsIndex);
void resultAndGraduation(student_t resultAndGraduationsList[], int* resultAndGraduationsIndex);

void displayAllBookingRecords(student_t admissionList[], int* admissionIndex, student_t studentCardList[], int* studentCardIndex, student_t enrollmentAndCourseAdviseList[], int* enrollmentAndCourseAdviseIndex, student_t travelConcessionList[], int* travelConcessionIndex, student_t resultAndGraduationsList[], int* resultAndGraduationsIndex);

void viewStudentHistory(student_t admissionList[], int* admissionIndex, student_t studentCardList[], int* studentCardIndex, student_t enrollmentAndCourseAdviseList[], int* enrollmentAndCourseAdviseIndex, student_t travelConcessionList[], int* travelConcessionIndex, student_t resultAndGraduationsList[], int* resultAndGraduationsIndex);

