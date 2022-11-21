/*
 * Admission:
 * 	Students should be able to
 * 	- 'Book a ticket'
 * 	'Enter some bs input for admissionForm i.e specific data types / questions'
 *
 * Student Card
 * 	Students should be able to
 * 	- 'Get a dtudent id'
 * 	'Enter some bs input'
 *
 * Same for enrollmentAndCourseAdvise, travelConcession, resultAndGraduations
*/

#ifndef __MAIN_H__
#define __MAIN_H__
#include "main.h"
#endif

int main() {
	/* Keep this file simple take in parameters here and then call main application */

	/* Call main application */

	displayMenu();

	

	return 0;
}

void displayMenu(void) {
	drawTopLine();
	drawTitle("Main Menu");
	drawBottomLine();
	drawBody("1. Admission");
	drawBody("2. Student Card");
	drawBody("3. Enrollment and Course Advise");
	drawBody("4. Travel Concessions");
	drawBody("5. Result and Graduation");
	drawBody("6. Exit");
	drawBottomLine();
}

