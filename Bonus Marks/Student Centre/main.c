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
	student_t admissionList[ARRAY_LENGTH];
	int admissionIndex = 0;
	student_t studentCardList[ARRAY_LENGTH];
	int studentCardIndex = 0;
	student_t enrollmentAndCourseAdviseList[ARRAY_LENGTH];
	int enrollmentAndCourseAdviseIndex = 0;
	student_t travelConcessionList[ARRAY_LENGTH];
	int travelConcessionIndex = 0;
	student_t resultAndGraduationsList[ARRAY_LENGTH];
	int resultAndGraduationsIndex = 0;

	startApplication(admissionList, &admissionIndex, studentCardList, &studentCardIndex, enrollmentAndCourseAdviseList, &enrollmentAndCourseAdviseIndex, travelConcessionList, &travelConcessionIndex, resultAndGraduationsList, &resultAndGraduationsIndex);

	return 0;
}

void displayMenu(void) {
	clear();
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

void startApplication(student_t admissionList[], int* admissionIndex, student_t studentCardList[], int* studentCardIndex, student_t enrollmentAndCourseAdviseList[], int* enrollmentAndCourseAdviseIndex, student_t travelConcessionList[], int* travelConcessionIndex, student_t resultAndGraduationsList[], int* resultAndGraduationsIndex) {
	/* Call main application */
	displayMenu();

	/* Get user input */
	int choice = readInt("Enter your choice: ");

	switch(choice) {
		case 1:
			admission(admissionList, admissionIndex);
			startApplication(admissionList, admissionIndex, studentCardList, studentCardIndex, enrollmentAndCourseAdviseList, enrollmentAndCourseAdviseIndex, travelConcessionList, travelConcessionIndex, resultAndGraduationsList, resultAndGraduationsIndex);
			/* Call admission */
			break;
		case 2:
			/* Call student card */
			break;
		case 3:
			/* Call enrollment and course advise */
			break;
		case 4:
			/* Call travel concession */
			break;
		case 5:
			/* Call result and graduation */
			break;
		case 6:
			/* Exit */
			break;
		default:
			printfError("Invalid choice");
			readkey("Press any key to continue...");
			startApplication(admissionList, admissionIndex, studentCardList, studentCardIndex, enrollmentAndCourseAdviseList, enrollmentAndCourseAdviseIndex, travelConcessionList, travelConcessionIndex, resultAndGraduationsList, resultAndGraduationsIndex);
		break;
	}
}

void displayAdmissionMenu() {
	clear();
	drawTopLine();
	drawTitle("Admission");
	drawBottomLine();
	drawBody("1. Book a ticket");
	drawBody("2. View Admission Queue");
	drawBody("3. Cancel Admission");
	drawBody("4. Back");
	drawBottomLine();
}

void createStudent(student_t studentList[] , int* studentIndex) {
	student_t student;
	student.name[0] = '\0';
	student.address[0] = '\0';
	student.phone[0] = '\0';
	student.email[0] = '\0';
	student.studentID[0] = '\0';
	student.course[0] = '\0';

	/* Get user input */
	char* name;
	while((name = readStringWithLimit("Enter your name: ", STRING_LENGTH)) == NULL) {
		printfError("Invalid name");
	}
	strcat(student.name, name);
	free(name);
	name = NULL;

	char* address;
	while((address = readStringWithLimit("Enter your address: ", STRING_LENGTH)) == NULL) {
		printfError("Invalid address");
	}
	strcat(student.address, address);
	free(address);
	address = NULL;

	char* phone;
	while((phone = readStringWithLimit("Enter your phone: ", STRING_LENGTH)) == NULL) {
		printfError("Invalid phone");
	}
	strcat(student.phone, phone);
	free(phone);
	phone = NULL;

	char* email;
	while((email = readStringWithLimit("Enter your email: ", STRING_LENGTH)) == NULL) {
		printfError("Invalid email");
	}
	strcat(student.email, email);
	free(email);
	email = NULL;

	char* studentID;
	while((studentID = readStringWithLimit("Enter your student ID: ", STRING_LENGTH)) == NULL) {
		printfError("Invalid student ID");
	}
	strcat(student.studentID, studentID);
	free(studentID);
	studentID = NULL;

	char* course;
	while((course = readStringWithLimit("Enter your course: ", STRING_LENGTH)) == NULL) {
		printfError("Invalid course");
	}
	strcat(student.course, course);
	free(course);
	course = NULL;

	/* Add to admission list */
	studentList[*studentIndex] = student;
	*studentIndex = *studentIndex + 1;
}

void listQueue(student_t studentList[], int* studentIndex, char title[]) {
	clear();
	drawTopLine();
	drawTitle(title);
	drawBottomLine();
	int i;
	for(i = 0; i < *studentIndex; i++) {
		drawBody(studentList[i].name);
	}
	drawBottomLine();
	readkey("Press any key to continue...");
}

void cancelQueue(student_t studentList[], int* studentIndex, char title[]) {
	char* studentID = readStringWithLimit("Enter student ID: ", STRING_LENGTH);
	int i;
	for(i = 0; i < *studentIndex; i++) {
		if(strcmp(studentID, studentList[i].studentID) == 0) {
			/* Remove student from admission list */
			int j;
			for(j = i; j < *studentIndex - 1; j++) {
				studentList[j] = studentList[j + 1];
			}
			*studentIndex = *studentIndex - 1;
			printf("\n\033[46;37;1m %s cancelled successfully \033[0m\n", title);
			readkey("Press any key to continue...");
			return;
		}
	}
	printfError("Student not found");
	readkey("Press any key to continue...");
}

void bookUniversityAdmission(student_t admissionList[], int* admissionIndex) {
	createStudent(admissionList, admissionIndex);
	printfSuccess("Admission booked successfully");
	readkey("Press any key to continue...");
}

void cancelUniversityAdmission(student_t admissionList[], int* admissionIndex) {
	cancelQueue(admissionList, admissionIndex, "Admission");
}

/* Admissions */
void admission(student_t admissionList[], int* admissionIndex) {
	/* Call admission application */
	displayAdmissionMenu();

	/* Get user input */
	int choice = readInt("Enter your choice: ");

	switch(choice) {
		case 1:
			/* Call book a ticket */
			bookUniversityAdmission(admissionList, admissionIndex);
			admission(admissionList, admissionIndex);
			break;
		case 2:
			/* Call enter some bs input for admissionForm i.e specific data types / questions */
			listQueue(admissionList, admissionIndex, "Admission Queue");
			admission(admissionList, admissionIndex);
			break;
		case 3:
			/* Cancel admission */
			cancelUniversityAdmission(admissionList, admissionIndex);
			admission(admissionList, admissionIndex);
			break;
		case 4:
			/* Call main menu */
			break;
		default:
			printfError("Invalid choice");
			readkey("Press any key to continue...");
			admission(admissionList, admissionIndex);
		break;
	}
}

