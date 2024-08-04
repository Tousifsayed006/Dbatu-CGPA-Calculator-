#include <stdio.h>
#include <string.h>

#define MAX_SUBJECTS 10  
/*This line defines a constant MAX_SUBJECTS with a value of 10.
 It means the program can handle up to 10 subjects.*/

#define MAX_NAME_LENGTH 50
/*This line defines a constant MAX_NAME_LENGTH with a value of 50.
 It sets the maximum length for subject names and the student's */

typedef struct {
    char subject[MAX_NAME_LENGTH];
    char grade[3];
    int credit;
} Subject;
/*This defines a new type Subject using a struct. Each Subject has:
subject: a string to hold the subject's name (up to 50 characters).
grade: a string to hold the grade (up to 2 characters plus a null terminator).
credit: an integer to hold the credit value of the subject.*/

Subject subjects[MAX_SUBJECTS];
//Declares an array subjects of Subject structs to store information about each subject.

int subjectCount = 0;
//Initializes subjectCount to 0. This variable keeps track of how many subjects have been added.

char studentName[MAX_NAME_LENGTH];
//Declares a string studentName to store the student's name.

float getGradepoint(char grade[3]);
void addSubject();
void editSubject();
void calculateCGPA();
void markSheet();
void line();
//Declaration of all functions 

int main() {
    printf("\tDr.Babasaheb Ambedkar Technological\n\tUniversity CGPA Calculator\t\n\n");
    line();
    printf("Enter your Name: ");
    fgets(studentName, sizeof(studentName), stdin);
    studentName[strcspn(studentName, "\n")] = 0;

    while (1) {
        int choice;
        printf("\n1. Add Subject\n2. Edit Subject\n3. Calculate CGPA\n4. Mark sheet\n5. Exit\n\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        while (getchar() != '\n');

        switch (choice) {
            case 1:
                addSubject();
                break;
            case 2:
                editSubject();
                break;
            case 3:
                calculateCGPA();
                break;
            case 4:
                markSheet();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}
/*The main function is the entry point of the program.
Prints a welcome message and a line separator.
Prompts the user to enter their name and stores it in studentName. Removes the newline character at the end.
Enters an infinite loop to repeatedly present a menu with options to add/edit subjects, calculate CGPA, print mark sheet, or exit.
Prompts the user to enter their choice.
Clears the input buffer to handle any extra newline characters.
Uses a switch statement to call the appropriate function based on the user's choice:
1: Calls addSubject() to add a new subject.
2: Calls editSubject() to edit an existing subject.
3: Calls `calculate*/



float getGradepoint(char grade[3]) {
    if (strcmp(grade, "EX") == 0) return 10.0;
    if (strcmp(grade, "AA") == 0) return 9.0;
    if (strcmp(grade, "AB") == 0) return 8.5;
    if (strcmp(grade, "BB") == 0) return 8.0;
    if (strcmp(grade, "BC") == 0) return 7.5;
    if (strcmp(grade, "CC") == 0) return 7.0;
    if (strcmp(grade, "CD") == 0) return 6.5;
    if (strcmp(grade, "DD") == 0) return 6.0;
    if (strcmp(grade, "DE") == 0) return 5.5;
    if (strcmp(grade, "EE") == 0) return 5.0;
    return 0.0;
}
/*This function takes a grade (like "EX", "AA", etc.) and returns its corresponding grade point.
It uses strcmp to compare the input grade with predefined grades.
If the input grade matches a predefined grade, it returns the corresponding grade point.
If no match is found, it returns 0.0.*/

void addSubject() {
    if (subjectCount >= MAX_SUBJECTS) {
        printf("Maximum subjects reached!\n");
        return;
    }
    printf("Enter Subject Name: ");
    scanf("%s", subjects[subjectCount].subject);
    printf("Enter Grade (EX, AA, AB, BB, BC, CC, CD, DD, DE, EE): ");
    scanf("%2s", subjects[subjectCount].grade);
    printf("Enter Credit: ");
    scanf("%d", &subjects[subjectCount].credit);

    subjectCount++;
}
/*This function adds a new subject.
First, it checks if the subjectCount has reached MAX_SUBJECTS. If so, it prints a message and returns without adding a new subject.
Prompts the user to enter the subject name and stores it in the next available position in the subjects array.
Prompts the user to enter the grade and stores it.
Prompts the user to enter the credit value and stores it.
Increments subjectCount to indicate a new subject has been added.*/

void editSubject() {
    int number;
    printf("Enter Number Of Subject To Edit (0 to %d): ", subjectCount - 1);
    scanf("%d", &number);

    if (number < 0 || number >= subjectCount) {
        printf("Invalid Number...\n");
        return;
    }

    printf("Enter New Subject Name: ");
    scanf("%s", subjects[number].subject);
    printf("Enter New Grade: ");
    scanf("%2s", subjects[number].grade);
    printf("Enter New Credit: ");
    scanf("%d", &subjects[number].credit);
}
/*This function edits an existing subject.
Prompts the user to enter the index number of the subject to be edited.
Checks if the entered number is valid. If not, it prints an error message and returns.
Prompts the user to enter the new subject name and updates it in the subjects array.
Prompts the user to enter the new grade and updates it.
Prompts the user to enter the new credit value and updates it.*/

void calculateCGPA() {
    int totalCredits = 0;
    float weightedSum = 0;

    for (int i = 0; i < subjectCount; i++) {
        totalCredits += subjects[i].credit;
        weightedSum += getGradepoint(subjects[i].grade) * subjects[i].credit;
    }

    float cgpa = (totalCredits > 0) ? weightedSum / totalCredits : 0;
    printf("CGPA: %.2f\n", cgpa);
}
/*This function calculates and prints the CGPA.
Initializes totalCredits and weightedSum to 0.
Loops through each subject:
Adds the subject's credits to totalCredits.
Adds the product of the subject's grade point and credit to weightedSum.
Calculates the CGPA as weightedSum / totalCredits if there are any credits, otherwise sets CGPA to 0.
Prints the calculated CGPA.*/

void markSheet() {
    printf("\n\t\tMark Sheet\n");
    printf("-----------------------------------\n");
    printf("Student Name: %s\n", studentName);
    printf("\n");
    printf("| Subject         | Grade | Credit |\n");
    printf("-----------------------------------\n");

    for (int i = 0; i < subjectCount; i++) {
         printf("| %-15s | %-5s | %-6d |\n", subjects[i].subject, subjects[i].grade, subjects[i].credit);
    }

    printf("-----------------------------------\n");
    calculateCGPA();
}
/*This function prints a formatted mark sheet.
Prints headers for the mark sheet, including the student's name and column titles for subjects, grades, and credits.
Loops through each subject and prints its details in a formatted table.
Prints a closing line and calls calculateCGPA() to print the CGPA.*/

void line() {
    int length = 45;
    for (int i = 0; i < length; i++) {
        printf("-");
    }
    printf("\n");
}
//This function prints a line of 45 dashes to be used as a separator for better visual formatting.