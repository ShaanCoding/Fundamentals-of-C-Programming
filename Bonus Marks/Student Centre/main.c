#ifndef __MAIN_H__
#define __MAIN_H__
#include "main.h"
#endif

/******************************************************************************
 * This method is the main method of the program.
 * inputs:
 *     - none
 * outputs:
 *     - none
 *****************************************************************************/
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

/******************************************************************************
 * This method displays the main menu of the program.
 * inputs:
 *     - none
 * outputs:
 *     - none
 *****************************************************************************/
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
	drawBody("6. View Student Details");
	drawBody("7. Display All Bookings");
	drawBody("8. Exit");
	drawBottomLine();
}

/******************************************************************************
 * This method handles the business logic of the program redirecting it to the
 * appropriate sub menu.
 * inputs:
 *     - admissionList, admissionIndex, studentCardList, studentCardIndex,
 	   - enrollmentAndCourseAdviseList, enrollmentAndCourseAdviseIndex,
	   - travelConcessionList, travelConcessionIndex, resultAndGraduationsList,
	   - resultAndGraduationsIndex
 * outputs:
 *     - none
 *****************************************************************************/
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
			studentCard(studentCardList, studentCardIndex);
			startApplication(admissionList, admissionIndex, studentCardList, studentCardIndex, enrollmentAndCourseAdviseList, enrollmentAndCourseAdviseIndex, travelConcessionList, travelConcessionIndex, resultAndGraduationsList, resultAndGraduationsIndex);
			break;
		case 3:
			/* Call enrollment and course advise */
			enrollmentCourseAdvise(enrollmentAndCourseAdviseList, enrollmentAndCourseAdviseIndex);
			startApplication(admissionList, admissionIndex, studentCardList, studentCardIndex, enrollmentAndCourseAdviseList, enrollmentAndCourseAdviseIndex, travelConcessionList, travelConcessionIndex, resultAndGraduationsList, resultAndGraduationsIndex);
			break;
		case 4:
			/* Call travel concession */
			travelConcession(travelConcessionList, travelConcessionIndex);
			startApplication(admissionList, admissionIndex, studentCardList, studentCardIndex, enrollmentAndCourseAdviseList, enrollmentAndCourseAdviseIndex, travelConcessionList, travelConcessionIndex, resultAndGraduationsList, resultAndGraduationsIndex);
			break;
		case 5:
			/* Call result and graduation */
			resultAndGraduation(resultAndGraduationsList, resultAndGraduationsIndex);
			startApplication(admissionList, admissionIndex, studentCardList, studentCardIndex, enrollmentAndCourseAdviseList, enrollmentAndCourseAdviseIndex, travelConcessionList, travelConcessionIndex, resultAndGraduationsList, resultAndGraduationsIndex);
			break;
		case 6:
			/* Call viewStudentHistory */
			viewStudentHistory(admissionList, admissionIndex, studentCardList, studentCardIndex, enrollmentAndCourseAdviseList, enrollmentAndCourseAdviseIndex, travelConcessionList, travelConcessionIndex, resultAndGraduationsList, resultAndGraduationsIndex);
			startApplication(admissionList, admissionIndex, studentCardList, studentCardIndex, enrollmentAndCourseAdviseList, enrollmentAndCourseAdviseIndex, travelConcessionList, travelConcessionIndex, resultAndGraduationsList, resultAndGraduationsIndex);
		case 7:
			/* Call display all bookings */
			displayAllBookingRecords(admissionList, admissionIndex, studentCardList, studentCardIndex, enrollmentAndCourseAdviseList, enrollmentAndCourseAdviseIndex, travelConcessionList, travelConcessionIndex, resultAndGraduationsList, resultAndGraduationsIndex);
			startApplication(admissionList, admissionIndex, studentCardList, studentCardIndex, enrollmentAndCourseAdviseList, enrollmentAndCourseAdviseIndex, travelConcessionList, travelConcessionIndex, resultAndGraduationsList, resultAndGraduationsIndex);
			break;
		case 8:
			/* Exit */
			break;
		default:
			printfError("Invalid choice");
			readkey("Press any key to continue...");
			startApplication(admissionList, admissionIndex, studentCardList, studentCardIndex, enrollmentAndCourseAdviseList, enrollmentAndCourseAdviseIndex, travelConcessionList, travelConcessionIndex, resultAndGraduationsList, resultAndGraduationsIndex);
		break;
	}
}

/******************************************************************************
 * This method shows all current bookings on all categories.
 * inputs:
 *     - admissionList, admissionIndex, studentCardList, studentCardIndex,
 	   - enrollmentAndCourseAdviseList, enrollmentAndCourseAdviseIndex,
	   - travelConcessionList, travelConcessionIndex, resultAndGraduationsList,
	   - resultAndGraduationsIndex
 * outputs:
 *     - none
 *****************************************************************************/
void displayAllBookingRecords(student_t admissionList[], int* admissionIndex, student_t studentCardList[], int* studentCardIndex, student_t enrollmentAndCourseAdviseList[], int* enrollmentAndCourseAdviseIndex, student_t travelConcessionList[], int* travelConcessionIndex, student_t resultAndGraduationsList[], int* resultAndGraduationsIndex) {
	int i;
	clear();
	drawTopLine();
	drawTitle("All Booking Records");
	drawBottomLine();
	drawTopLine();
	drawBody("Admission");
	for(i = 0; i < *admissionIndex; i++) {
		char buffer[200];
		sprintf(buffer, "%d. %s | %s", i + 1, admissionList[i].name, admissionList[i].studentID);
		drawBody(buffer);
	}
	drawBottomLine();
	drawTopLine();
	drawBody("Student Card");
	for(i = 0; i < *studentCardIndex; i++) {
		char buffer[200];
		sprintf(buffer, "%d. %s | %s", i + 1, studentCardList[i].name, studentCardList[i].studentID);
		drawBody(buffer);
	}
	drawBottomLine();
	drawTopLine();
	drawBody("Enrollment and Course Advise");
	for(i = 0; i < *enrollmentAndCourseAdviseIndex; i++) {
		char buffer[200];
		sprintf(buffer, "%d. %s | %s", i + 1, enrollmentAndCourseAdviseList[i].name, enrollmentAndCourseAdviseList[i].studentID);
		drawBody(buffer);
	}
	drawBottomLine();
	drawTopLine();
	drawBody("Travel Concession");
	for(i = 0; i < *travelConcessionIndex; i++) {
		char buffer[200];
		sprintf(buffer, "%d. %s | %s", i + 1, travelConcessionList[i].name, travelConcessionList[i].studentID);
		drawBody(buffer);
	}
	drawBottomLine();
	drawTopLine();
	drawBody("Result and Graduation");
	for(i = 0; i < *resultAndGraduationsIndex; i++) {
		char buffer[200];
		sprintf(buffer, "%d. %s | %s", i + 1, resultAndGraduationsList[i].name, resultAndGraduationsList[i].studentID);
		drawBody(buffer);
	}
	drawBottomLine();
	readkey("Press any key to continue...");
}

/******************************************************************************
 * This method creates a new student record with validation
 * inputs:
 *     - studentList, studentIndex
 * outputs:
 *     - none
 *****************************************************************************/
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

/******************************************************************************
 * This method shows how many students are in the queue waiting for the service.
 * inputs:
 *     - admissionList, admissionIndex, index
 * outputs:
 *     - none
 *****************************************************************************/
void listQueue(student_t studentList[], int* studentIndex, char title[]) {
	clear();
	drawTopLine();
	drawTitle(title);
	drawBottomLine();
	if(*studentIndex == 0) {
		drawBody("There is no students in the queue.");
	} else {
		char buffer[100];
		sprintf(buffer, "Students in the queue: %d", *studentIndex);
		drawBody(buffer);
		int i;
		for(i = 0; i < *studentIndex; i++) {
			char buffer[200];
			sprintf(buffer, "%d. %s | %s", i + 1, studentList[i].name, studentList[i].studentID);
			drawBody(buffer);
		}
	}
	
	drawBottomLine();
	readkey("Press any key to continue...");
}

/******************************************************************************
 * This method deletes a student record from the queue.
 * inputs:
 *     - studentList, studentIndex, title
 * outputs:
 *     - none
 *****************************************************************************/
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

/******************************************************************************
 * This method shows the admissionMenu options.
 * inputs:
 *     - none
 * outputs:
 *     - none
 *****************************************************************************/
void displayAdmissionMenu(void) {
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

/******************************************************************************
 * This method handles the business logic of the adding a student to 
 * the admission queue.
 * inputs:
 *     - admissionList, admissionIndex
 * outputs:
 *     - none
 *****************************************************************************/
void bookUniversityAdmission(student_t admissionList[], int* admissionIndex) {
	createStudent(admissionList, admissionIndex);
	printfSuccess("Admission booked successfully");
	readkey("Press any key to continue...");
}

/******************************************************************************
 * This method handles the business logic of removing a student from
 * the admission queue.
 * inputs:
 *     - admissionList, admissionIndex
 * outputs:
 *     - none
 *****************************************************************************/
void cancelUniversityAdmission(student_t admissionList[], int* admissionIndex) {
	cancelQueue(admissionList, admissionIndex, "Admission");
}

/******************************************************************************
 * This method handles the business logic of the admission menu.
 * inputs:
 *     - admissionList, admissionIndex
 * outputs:
 *     - none
 *****************************************************************************/
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

/******************************************************************************
 * This method is displays the student menu options.
 * inputs:
 *     - none
 * outputs:
 *     - none
 *****************************************************************************/
void displayStudentCardMenu(void) {
	clear();
	drawTopLine();
	drawTitle("Student Card");
	drawBottomLine();
	drawBody("1. Book a ticket");
	drawBody("2. View Student Card Queue");
	drawBody("3. Cancel Student Card");
	drawBody("4. Back");
	drawBottomLine();
}

/******************************************************************************
 * This method handles the business logic of the adding a student to
 * the student card queue.
 * inputs:
 *     - studentCardList, studentCardIndex
 * outputs:
 *     - none
 *****************************************************************************/
void bookStudentCard(student_t studentCardList[], int* studentCardIndex) {
	createStudent(studentCardList, studentCardIndex);
	printfSuccess("Student card booked successfully");
	readkey("Press any key to continue...");
}

/******************************************************************************
 * This method handles the business logic of removing a student from
 * the student card queue.
 * inputs:
 *     - studentCardList, studentCardIndex
 * outputs:
 *     - none
 *****************************************************************************/
void cancelStudentCard(student_t studentCardList[], int* studentCardIndex) {
	cancelQueue(studentCardList, studentCardIndex, "Student Card");
}

/******************************************************************************
 * This method handles the business logic of the student card menu.
 * inputs:
 *     - studentCardList, studentCardIndex
 * outputs:
 *     - none
 *****************************************************************************/
void studentCard(student_t studentCardList[], int* studentCardIndex) {
	/* Call student card application */
	displayStudentCardMenu();

	/* Get user input */
	int choice = readInt("Enter your choice: ");

	switch(choice) {
		case 1:
			/* Call book a ticket */
			bookStudentCard(studentCardList, studentCardIndex);
			studentCard(studentCardList, studentCardIndex);
			break;
		case 2:
			/* Call enter some bs input for admissionForm i.e specific data types / questions */
			listQueue(studentCardList, studentCardIndex, "Student Card Queue");
			studentCard(studentCardList, studentCardIndex);
			break;
		case 3:
			/* Cancel student card */
			cancelStudentCard(studentCardList, studentCardIndex);
			studentCard(studentCardList, studentCardIndex);
			break;
		case 4:
			/* Call main menu */
			break;
		default:
			printfError("Invalid choice");
			readkey("Press any key to continue...");
			studentCard(studentCardList, studentCardIndex);
		break;
	}
}

/******************************************************************************
 * This method is displays the enrollment advise menu options.
 * inputs:
 *     - none
 * outputs:
 *     - none
 *****************************************************************************/
void displayEnrollmentCourseAdviseMenu(void) {
	clear();
	drawTopLine();
	drawTitle("Enrollment Course Advise");
	drawBottomLine();
	drawBody("1. Book a ticket");
	drawBody("2. View Enrollment Course Advise Queue");
	drawBody("3. Cancel Enrollment Course Advise");
	drawBody("4. Back");
	drawBottomLine();
}

/******************************************************************************
 * This method handles the business logic of the adding a student to
 * the enrollment course advise queue.
 * inputs:
 *     - enrollmentCourseAdviseList, enrollmentCourseAdviseIndex
 * outputs:
 *     - none
 *****************************************************************************/
void bookEnrollmentCourseAdvise(student_t enrollmentCourseAdviseList[], int* enrollmentCourseAdviseIndex) {
	createStudent(enrollmentCourseAdviseList, enrollmentCourseAdviseIndex);
	printfSuccess("Enrollment course advise booked successfully");
	readkey("Press any key to continue...");
}

/******************************************************************************
 * This method handles the business logic of removing a student from
 * the enrollment course advise queue.
 * inputs:
 *     - enrollmentCourseAdviseList, enrollmentCourseAdviseIndex
 * outputs:
 *     - none
 *****************************************************************************/
void cancelEnrollmentCourseAdvise(student_t enrollmentCourseAdviseList[], int* enrollmentCourseAdviseIndex) {
	cancelQueue(enrollmentCourseAdviseList, enrollmentCourseAdviseIndex, "Enrollment Course Advise");
}

/******************************************************************************
 * This method handles the business logic of the enrollment course advise menu.
 * inputs:
 *     - enrollmentCourseAdviseList, enrollmentCourseAdviseIndex
 * outputs:
 *     - none
 *****************************************************************************/
void enrollmentCourseAdvise(student_t enrollmentCourseAdviseList[], int* enrollmentCourseAdviseIndex) {
	/* Call enrollment course advise application */
	displayEnrollmentCourseAdviseMenu();

	/* Get user input */
	int choice = readInt("Enter your choice: ");

	switch(choice) {
		case 1:
			/* Call book a ticket */
			bookEnrollmentCourseAdvise(enrollmentCourseAdviseList, enrollmentCourseAdviseIndex);
			enrollmentCourseAdvise(enrollmentCourseAdviseList, enrollmentCourseAdviseIndex);
			break;
		case 2:
			/* Call enter some bs input for admissionForm i.e specific data types / questions */
			listQueue(enrollmentCourseAdviseList, enrollmentCourseAdviseIndex, "Enrollment Course Advise Queue");
			enrollmentCourseAdvise(enrollmentCourseAdviseList, enrollmentCourseAdviseIndex);
			break;
		case 3:
			/* Cancel enrollment course advise */
			cancelEnrollmentCourseAdvise(enrollmentCourseAdviseList, enrollmentCourseAdviseIndex);
			enrollmentCourseAdvise(enrollmentCourseAdviseList, enrollmentCourseAdviseIndex);
			break;
		case 4:
			/* Call main menu */
			break;
		default:
			printfError("Invalid choice");
			readkey("Press any key to continue...");
			enrollmentCourseAdvise(enrollmentCourseAdviseList, enrollmentCourseAdviseIndex);
		break;
	}
}

/******************************************************************************
 * This method displays the travel concession menu options.
 * inputs:
 *     - none
 * outputs:
 *     - none
 *****************************************************************************/
void displayTravelConcessionMenu(void) {
	clear();
	drawTopLine();
	drawTitle("Travel Concession");
	drawBottomLine();
	drawBody("1. Book a ticket");
	drawBody("2. View Travel Concession Queue");
	drawBody("3. Cancel Travel Concession");
	drawBody("4. Back");
	drawBottomLine();
}

/******************************************************************************
 * This method handles the business logic of the adding a student to
 * the travel concession queue.
 * inputs:
 *     - travelConcessionList, travelConcessionIndex
 * outputs:
 *     - none
 *****************************************************************************/
void bookTravelConcession(student_t travelConcessionList[], int* travelConcessionIndex) {
	createStudent(travelConcessionList, travelConcessionIndex);
	printfSuccess("Travel concession booked successfully");
	readkey("Press any key to continue...");
}

/******************************************************************************
 * This method handles the business logic of removing a student from
 * the travel concession queue.
 * inputs:
 *     - travelConcessionList, travelConcessionIndex
 * outputs:
 *     - none
 *****************************************************************************/
void cancelTravelConcession(student_t travelConcessionList[], int* travelConcessionIndex) {
	cancelQueue(travelConcessionList, travelConcessionIndex, "Travel Concession");
}

/******************************************************************************
 * This method is handles the business logic of the travel concession menu.
 * inputs:
 *     - travelConcessionList, travelConcessionIndex
 * outputs:
 *     - none
 *****************************************************************************/
void travelConcession(student_t travelConcessionList[], int* travelConcessionIndex) {
	/* Call travel concession application */
	displayTravelConcessionMenu();

	/* Get user input */
	int choice = readInt("Enter your choice: ");

	switch(choice) {
		case 1:
			/* Call book a ticket */
			bookTravelConcession(travelConcessionList, travelConcessionIndex);
			travelConcession(travelConcessionList, travelConcessionIndex);
			break;
		case 2:
			/* Call enter some bs input for admissionForm i.e specific data types / questions */
			listQueue(travelConcessionList, travelConcessionIndex, "Travel Concession Queue");
			travelConcession(travelConcessionList, travelConcessionIndex);
			break;
		case 3:
			/* Cancel travel concession */
			cancelTravelConcession(travelConcessionList, travelConcessionIndex);
			travelConcession(travelConcessionList, travelConcessionIndex);
			break;
		case 4:
			/* Call main menu */
			break;
		default:
			printfError("Invalid choice");
			readkey("Press any key to continue...");
			travelConcession(travelConcessionList, travelConcessionIndex);
		break;
	}
}

/******************************************************************************
 * This method displays the main menu options.
 * inputs:
 *     - none
 * outputs:
 *     - none
 *****************************************************************************/
void displayResultAndGraduationMenu(void) {
	clear();
	drawTopLine();
	drawTitle("Result And Graduation");
	drawBottomLine();
	drawBody("1. Book a ticket");
	drawBody("2. View Result And Graduation Queue");
	drawBody("3. Cancel Result And Graduation");
	drawBody("4. Back");
	drawBottomLine();
}

/******************************************************************************
 * This method handles the business logic of the adding a student to
 * the result and graduation queue.
 * inputs:
 *     - resultAndGraduationList, resultAndGraduationIndex
 * outputs:
 *     - none
 *****************************************************************************/
void bookResultAndGraduation(student_t resultAndGraduationList[], int* resultAndGraduationIndex) {
	createStudent(resultAndGraduationList, resultAndGraduationIndex);
	printfSuccess("Result and graduation booked successfully");
	readkey("Press any key to continue...");
}

/******************************************************************************
 * This method handles the business logic of removing a student from
 * the result and graduation queue.
 * inputs:
 *     - resultAndGraduationList, resultAndGraduationIndex
 * outputs:
 *     - none
 *****************************************************************************/
void cancelResultAndGraduation(student_t resultAndGraduationList[], int* resultAndGraduationIndex) {
	cancelQueue(resultAndGraduationList, resultAndGraduationIndex, "Result And Graduation");
}

/******************************************************************************
 * This method is handles the business logic of the result and graduation menu.
 * inputs:
 *     - resultAndGraduationList, resultAndGraduationIndex
 * outputs:
 *     - none
 *****************************************************************************/
void resultAndGraduation(student_t resultAndGraduationList[], int* resultAndGraduationIndex) {
	/* Call result and graduation application */
	displayResultAndGraduationMenu();

	/* Get user input */
	int choice = readInt("Enter your choice: ");

	switch(choice) {
		case 1:
			/* Call book a ticket */
			bookResultAndGraduation(resultAndGraduationList, resultAndGraduationIndex);
			resultAndGraduation(resultAndGraduationList, resultAndGraduationIndex);
			break;
		case 2:
			/* Call enter some bs input for admissionForm i.e specific data types / questions */
			listQueue(resultAndGraduationList, resultAndGraduationIndex, "Result And Graduation Queue");
			resultAndGraduation(resultAndGraduationList, resultAndGraduationIndex);
			break;
		case 3:
			/* Cancel result and graduation */
			cancelResultAndGraduation(resultAndGraduationList, resultAndGraduationIndex);
			resultAndGraduation(resultAndGraduationList, resultAndGraduationIndex);
			break;
		case 4:
			/* Call main menu */
			break;
		default:
			printfError("Invalid choice");
			readkey("Press any key to continue...");
			resultAndGraduation(resultAndGraduationList, resultAndGraduationIndex);
		break;
	}
}

/******************************************************************************
 * This method displays the student information of a specific student.
 * inputs:
 *     - admissionList, admissionIndex, studentCardList, studentCardIndex,
 	   - enrollmentAndCourseAdviseList, enrollmentAndCourseAdviseIndex,
	   - travelConcessionList, travelConcessionIndex, resultAndGraduationsList,
	   - resultAndGraduationsIndex
 * outputs:
 *     - none
 *****************************************************************************/
void viewStudentHistory(student_t admissionList[], int* admissionIndex, student_t studentCardList[], int* studentCardIndex, student_t enrollmentAndCourseAdviseList[], int* enrollmentAndCourseAdviseIndex, student_t travelConcessionList[], int* travelConcessionIndex, student_t resultAndGraduationsList[], int* resultAndGraduationsIndex) {
	char* studentID = readString("Select student ID: ");

	/* Print all entries for specific student */
	clear();
	drawTopLine();

	drawTitle("Student History");
	drawBottomLine();

	int hasIDBeenFound = 0;

	int i;
	for(i = 0; i < *admissionIndex; i++) {
		/* If we find equal strings */
		if(strcmp(admissionList[i].studentID, studentID) == 0) {
			char buffer[100];
			sprintf(buffer, "Student ID: %s", admissionList[i].studentID);
			drawBody(buffer);
			sprintf(buffer, "Student Name: %s", admissionList[i].name);
			drawBody(buffer);
			sprintf(buffer, "Student Address: %s", admissionList[i].address);
			drawBody(buffer);
			sprintf(buffer, "Student Phone: %s", admissionList[i].phone);
			drawBody(buffer);
			sprintf(buffer, "Student Email: %s", admissionList[i].email);
			drawBody(buffer);
			sprintf(buffer, "Student Course: %s", admissionList[i].course);
			drawBody(buffer);
			hasIDBeenFound = 1;
		}
	}

	if(hasIDBeenFound == 0) {
		i = 0;
		for(i = 0; i < *studentCardIndex; i++) {
			/* If we find equal strings */
			if(strcmp(studentCardList[i].studentID, studentID) == 0) {
				char buffer[100];
				sprintf(buffer, "Student ID: %s", studentCardList[i].studentID);
				drawBody(buffer);
				sprintf(buffer, "Student Name: %s", studentCardList[i].name);
				drawBody(buffer);
				sprintf(buffer, "Student Address: %s", studentCardList[i].address);
				drawBody(buffer);
				sprintf(buffer, "Student Phone: %s", studentCardList[i].phone);
				drawBody(buffer);
				sprintf(buffer, "Student Email: %s", studentCardList[i].email);
				drawBody(buffer);
				sprintf(buffer, "Student Course: %s", studentCardList[i].course);
				drawBody(buffer);
				hasIDBeenFound = 1;
			}
		}
	}

	if(hasIDBeenFound == 0) {
		i = 0;
		for(i = 0; i < *enrollmentAndCourseAdviseIndex; i++) {
			/* If we find equal strings */
			if(strcmp(enrollmentAndCourseAdviseList[i].studentID, studentID) == 0) {
				char buffer[100];
				sprintf(buffer, "Student ID: %s", enrollmentAndCourseAdviseList[i].studentID);
				drawBody(buffer);
				sprintf(buffer, "Student Name: %s", enrollmentAndCourseAdviseList[i].name);
				drawBody(buffer);
				sprintf(buffer, "Student Address: %s", enrollmentAndCourseAdviseList[i].address);
				drawBody(buffer);
				sprintf(buffer, "Student Phone: %s", enrollmentAndCourseAdviseList[i].phone);
				drawBody(buffer);
				sprintf(buffer, "Student Email: %s", enrollmentAndCourseAdviseList[i].email);
				drawBody(buffer);
				sprintf(buffer, "Student Course: %s", enrollmentAndCourseAdviseList[i].course);
				drawBody(buffer);
				hasIDBeenFound = 1;
			}
		}
	}

	if(hasIDBeenFound == 0) {
		i = 0;
		for(i = 0; i < *travelConcessionIndex; i++) {
			/* If we find equal strings */
			if(strcmp(travelConcessionList[i].studentID, studentID) == 0) {
				char buffer[100];
				sprintf(buffer, "Student ID: %s", travelConcessionList[i].studentID);
				drawBody(buffer);
				sprintf(buffer, "Student Name: %s", travelConcessionList[i].name);
				drawBody(buffer);
				sprintf(buffer, "Student Address: %s", travelConcessionList[i].address);
				drawBody(buffer);
				sprintf(buffer, "Student Phone: %s", travelConcessionList[i].phone);
				drawBody(buffer);
				sprintf(buffer, "Student Email: %s", travelConcessionList[i].email);
				drawBody(buffer);
				sprintf(buffer, "Student Course: %s", travelConcessionList[i].course);
				drawBody(buffer);
				hasIDBeenFound = 1;
			}
		}
	}

	if(hasIDBeenFound == 0) {
		i = 0;
		for(i = 0; i < *resultAndGraduationsIndex; i++) {
			/* If we find equal strings */
			if(strcmp(resultAndGraduationsList[i].studentID, studentID) == 0) {
				char buffer[100];
				sprintf(buffer, "Student ID: %s", resultAndGraduationsList[i].studentID);
				drawBody(buffer);
				sprintf(buffer, "Student Name: %s", resultAndGraduationsList[i].name);
				drawBody(buffer);
				sprintf(buffer, "Student Address: %s", resultAndGraduationsList[i].address);
				drawBody(buffer);
				sprintf(buffer, "Student Phone: %s", resultAndGraduationsList[i].phone);
				drawBody(buffer);
				sprintf(buffer, "Student Email: %s", resultAndGraduationsList[i].email);
				drawBody(buffer);
				sprintf(buffer, "Student Course: %s", resultAndGraduationsList[i].course);
				drawBody(buffer);
				hasIDBeenFound = 1;
			}
		}
	}

	if(hasIDBeenFound == 0) {
		drawBody("Student ID has no entry in the database.");
	}

	drawBottomLine();

	readkey("Press any key to continue...");
}