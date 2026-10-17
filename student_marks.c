#include <stdio.h>

#define MAX_STUDENTS 5
#define SUBJECTS 3

void inputMarks(int marks[MAX_STUDENTS][SUBJECTS], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter marks for Student %d:\n", i + 1);

        for (int j = 0; j < SUBJECTS; j++) {
            do {
                printf("Subject %d (0-100): ", j + 1);
                scanf("%d", &marks[i][j]);

                if (marks[i][j] < 0 || marks[i][j] > 100) {
                    printf("Invalid marks! Try again.\n");
                }
            } while (marks[i][j] < 0 || marks[i][j] > 100);
        }
    }
}

int calculateTotal(int marks[]) {
    int total = 0;

    for (int i = 0; i < SUBJECTS; i++) {
        total += marks[i];
    }

    return total;
}

char calculateGrade(float average) {
    if (average >= 90)
        return 'A';
    else if (average >= 75)
        return 'B';
    else if (average >= 60)
        return 'C';
    else if (average >= 40)
        return 'D';
    else
        return 'F';
}

void displayResults(int marks[MAX_STUDENTS][SUBJECTS], int n) {
    printf("\n===== STUDENT RESULTS =====\n");

    for (int i = 0; i < n; i++) {
        int total = calculateTotal(marks[i]);
        float average = total / (float)SUBJECTS;
        char grade = calculateGrade(average);

        printf("\nStudent %d\n", i + 1);
        printf("Total Marks: %d/300\n", total);
        printf("Average: %.2f\n", average);
        printf("Grade: %c\n", grade);

        if (grade == 'F')
            printf("Status: Needs Improvement\n");
        else
            printf("Status: Passed\n");
    }
}

int main(void) {
    int marks[MAX_STUDENTS][SUBJECTS];
    int n;

    printf("STUDENT MARKS MANAGEMENT SYSTEM\n");
    printf("Enter number of students (1-%d): ", MAX_STUDENTS);
    scanf("%d", &n);

    if (n < 1 || n > MAX_STUDENTS) {
        printf("Invalid number of students!\n");
        return 1;
    }

    inputMarks(marks, n);
    displayResults(marks, n);

    return 0;
}