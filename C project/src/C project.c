/**********************************************

  Student Management System
  By Adham Muhammed Elsayed

 *********************************************/

#include <stdio.h>
#include <stdlib.h> // must for dynamic allocation
#include <string.h>
#include <ctype.h>

// Define a structure to store student data
struct student
{
	// Student ID
	int id;
	// Student Name
	char name [50];
	// Student Age
	int age;
	// Student GPA
	float gpa;
};
// Define a structure to represent a node in a linked list
struct node
{
	// Student data
	struct student data;
	// pointer to next node (Student)
	struct node *next;
};
struct node *head = NULL;

//Functions declarations

// function to create or add a new node
struct node * add_new_node(const struct student *ptr);

// Case 1
void addStudent(const struct student *const ptr);
// Case 2
void displayStudents(void);
// Case 3
void searchStudentByID(int id);
// Case 4
void updateStudent(int id);
// Case 5
float calculateAverageGPA(void);
// Case 6
void searchHighestGPA(void);
// Case 7
void deleteStudent(int id);
// ContinueMoreTask
void ContinueMoreTask(void);
//function to free memory
void freeMemory(void);


//function to check for First name only
int contains_space(const char *str);

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int choice;
	printf("-----------------------------------------------------\n");
	printf("\t Welcome To Student Management System \t\n");
	while (1)
	{
		// pop menu to end user
		printf("-----------------------------------------------------\n");
		printf("1. Add Student\n");
		printf("2. Display Students\n");
		printf("3. Search for a Student by ID\n");
		printf("4. Update Student Information\n");
		printf("5. Calculate Average GPA\n");
		printf("6. Student with Highest GPA\n");
		printf("7. Delete Student\n");
		printf("8. Exit\n");
		printf("-----------------------------------------------------\n");
		printf("Enter Choice : ");
		scanf("%d", &choice);
		printf("-----------------------------------------------------\n");
		//Switch Statement
		switch (choice)
		{

		//Add a new Student//

		// Case 1: Add a new student
		case 1: {
			printf("\t\tAdd a new Student\t\t\n");
			struct student NewStudent;


			while (1) {
				// Input student ID
				printf("Enter Valid ID: ");
				if (scanf("%d", &NewStudent.id) == 1 && NewStudent.id > 0) {
					break; // Valid input
				}
				printf("Invalid ID input. ");
				while (getchar() != '\n'); // Clear invalid input from the buffer
			}


			// Input student Name
			while (1) {
			    printf("Enter Student Name (First Name Only): ");
			    scanf("%s", NewStudent.name);

			    // Validate the name for spaces
			    if (contains_space(NewStudent.name)) {
			        printf("Invalid input. Please enter the first name only (no spaces) :\n");
			        continue;
			    }

			    // Validate that the name contains only letters
			    int valid = 1;
			    for (int i = 0; NewStudent.name[i] != '\0'; i++) {
			        if (!((NewStudent.name[i] >= 'A' && NewStudent.name[i] <= 'Z') ||
			              (NewStudent.name[i] >= 'a' && NewStudent.name[i] <= 'z'))) {
			            valid = 0;
			            break;
			        }
			    }

			    if (!valid) {
			        printf("Invalid input. Name must contain only alphabetic characters.\n");
			        continue;
			    }

			    // If all checks pass, exit the loop
			    break;
			}

			// Input student Age
			printf("Enter Student Age: ");
			while (1) {
				if (scanf("%d", &NewStudent.age) == 1 && NewStudent.age > 0) {
					break; // Valid input
				}
				printf("Invalid Age input. Please enter a positive integer: ");
				while (getchar() != '\n'); // Clear invalid input from the buffer
			}

			// Input student GPA
			printf("Enter Student GPA (0.0 - 4.0): ");
			while (1) {
				if (scanf("%f", &NewStudent.gpa) == 1 && NewStudent.gpa >= 0.0 && NewStudent.gpa <= 4.0) {
					break; // Valid input
				}
				printf("Invalid GPA input. Please enter a value between 0.0 and 4.0: ");
				while (getchar() != '\n'); // Clear invalid input from the buffer
			}

			// Add the student to the linked list
			addStudent(&NewStudent);
			ContinueMoreTask();
			break;
		}


		//Display All Students//

		case 2:
		{
			// Print "Display All Students"
			printf("\t\tDisplay All Students\t\t\n");
			// Calling Function in case 2 and display students in linked list
			displayStudents();
			// Calling Function and ask if the user wants to continue.
			ContinueMoreTask();
			break;
		}

		//Search for a Student by ID//

		case 3:
		{
			// Print "Search for a Student by ID"
			printf("\t\tSearch for a Student by ID\t\t\n");
			int id;
			printf("Enter ID: ");
			if (scanf("%d", &id) != 1){
				printf("Invalid ID Input. Please enter a positive integer.\n");
				break;
			}
			// Calling Function in case 3 and Search for a Student by ID in linked list
			searchStudentByID(id);
			// Calling Function and ask if the user wants to continue.
			ContinueMoreTask();
			break;
		}

		//Update Student Information//

		case 4:
		{
			//Print "Update Student Information".
			printf("\t\tUpdate Student Information\t\t\n");
			int id;
			printf("Enter ID: ");
			if (scanf("%d", &id) != 1){
				printf("Invalid ID Input. Please enter a positive integer.\n");
				break;
			}
			// Calling Function in case 4 and Update Student Information in linked list
			updateStudent(id);
			// Calling Function and ask if the user wants to continue.
			ContinueMoreTask();
			break;
		}

		//Calculate Average GPA//

		case 5:
			// Print message "Calculate Average GPA".
			printf("\t\tCalculate Average GPA\t\t\n");
			// Calculate average GPA
			printf("Calculate average GPA:\n");
			// Calling Function in case 5 and Calculate Average GPA
			float average_GPA = calculateAverageGPA();
			if (average_GPA < 0.0) {
				printf("No students in the system to calculate GPA.\n");
			} else {
				printf("Average GPA: %f\n", average_GPA);
			}
			// Calling Function and ask if the user wants to continue.
			ContinueMoreTask();
			break;

			//Find Student with Highest GPA//

		case 6:
			// Print message "Find Student with Highest GPA".
			printf("\t\tFind Student with Highest GPA\t\t\n");
			// Calling Function in case 6 and Find Student with Highest GPA from linked list
			searchHighestGPA();
			// Calling Function and ask if the user wants to continue.
			ContinueMoreTask();
			break;

			//Delete a Student by ID//

		case 7:
			// Print message "Delete a Student by ID".
			printf("\t\tDelete a Student by ID\t\t\n");
			int id;
			printf("Enter ID: ");
			if (scanf("%d", &id) != 1){
				printf("Invalid ID input. Please enter a positive integer.\n");
				break;
			}
			// Calling Function in case 6 and Delete a Student by ID from linked list
			deleteStudent(id);
			// Calling Function and ask if the user wants to continue.
			ContinueMoreTask();
			break;

			//Exit from Program//

		case 8:
			// Exit from Program.
			printf("Exiting........\n");
			printf("-----------------------------------------------------\n");
			exit(0);
			break;
		default:
			printf("Invalid choice. Please select a valid option.\n");
		}
	}
}
/******************************
 *  Functions Implementation  *
 ******************************/


//function to check for First name only
int contains_space(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            return 1; // Space found
        }
    }
    return 0; // No spaces
}

//function to free memory
void freeMemory(void)
{
    struct node *current = head;
    while (current != NULL)
    {
        struct node *temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
    printf("Memory freed successfully.\n");
}


// Function to create or add a new node with given student data.
struct node * add_new_node(const struct student *ptr)
{
	struct node *link = (struct node *)malloc(sizeof(struct node));
	if (link == NULL)
	{
		printf("Error: Unable to allocate memory.\n");
		return NULL;
	}
	link->data = *ptr;
	link->next = NULL;
	return link;
}

// Case 1 --> Function to add a new student to the linked list
void addStudent(const struct student *const ptr)
{
	if (ptr == NULL)
	{
		printf("Error: Invalid student data.\n");
		return;
	}

	struct node *link = add_new_node(ptr);
	if (link == NULL)
	{
		return;
	}

	if (head == NULL)
	{
		head = link;
		printf("Success: Student added successfully.\n");
		return;
	}

	struct node *current = head;
	while (current->next != NULL)
	{
		if (current->data.id == link->data.id)
		{
			printf("Error: This ID already exists.\n");
			free(link);
			return;
		}
		current = current->next;
	}

	if (current->data.id == link->data.id)
	{
		printf("Error: This ID already exists.\n");
		free(link);
		return;
	}

	current->next = link;
	printf("Success: Student added successfully.\n");
}

// Case 2 --> Function to display the details of all students
void displayStudents(void)
{
	if (head == NULL)
	{
		printf("No students available.\n");
		return;
	}

	struct node *current = head;
	while (current != NULL)
	{
		printf("[ID: %d, Name: %s, Age: %d, GPA: %.2f]\n", current->data.id, current->data.name, current->data.age, current->data.gpa);
		current = current->next;
	}
}

// Case 3 --> Function to search for a student by their ID and display their details if found
void searchStudentByID(int id)
{
    if (head == NULL)
    {
        printf("No students available.\n");
        return;
    }

    struct node *current = head;

    // Traverse the linked list to find the student with the matching ID
    while (current != NULL)
    {
        if (current->data.id == id)
        {
            printf("Student Found:\n");
            printf("[ID: %d, Name: %s, Age: %d, GPA: %.2f]\n",
                   current->data.id, current->data.name,
                   current->data.age, current->data.gpa);
            return;
        }
        current = current->next;
    }

    // If no match is found, print an error message
    printf("Error: Student with ID %d not found.\n", id);
}

// Case 4 --> Function to update the details of a student with the given ID
void updateStudent(const int id)
{
	if (head == NULL)
	{
		printf("No students available.\n");
		return;
	}

	struct node *current = head;
	while (current != NULL)
	{
		if (current->data.id == id)
		{
			struct student updatedData;
			updatedData.id = id;

			printf("Enter new name: ");
			scanf("%s", updatedData.name);

			printf("Enter new age: ");
			while (scanf("%d", &updatedData.age) != 1 || updatedData.age <= 0)
			{
				printf("Invalid input. Enter a valid age: ");
				while (getchar() != '\n');
			}

			printf("Enter new GPA (0.0 - 4.0): ");
			while (scanf("%f", &updatedData.gpa) != 1 || updatedData.gpa < 0.0 || updatedData.gpa > 4.0)
			{
				printf("Invalid input. Enter a valid GPA (0.0 - 4.0): ");
				while (getchar() != '\n');
			}

			current->data = updatedData;
			printf("Success: Student data updated successfully.\n");
			return;
		}
		current = current->next;
	}
	printf("Error: Student with ID %d not found.\n", id);
}

// Case 5 --> Function to calculate and return the average GPA of all students
float calculateAverageGPA(void)
{
	if (head == NULL)
	{
		printf("No students available.\n");
		return 0.0;
	}

	float sum = 0.0;
	int count = 0;
	struct node *current = head;

	while (current != NULL)
	{
		sum += current->data.gpa;
		current = current->next;
		count++;
	}

	return count > 0 ? (sum / count) : 0.0;
}

// Case 6 --> Function to find and display the student with the highest GPA
void searchHighestGPA(void)
{
    if (head == NULL)
    {
        printf("No students available.\n");
        return;
    }

    struct node *current = head;
    float highestGPA = head->data.gpa;

    // Step 1: Find the highest GPA in the list
    while (current != NULL)
    {
        if (current->data.gpa > highestGPA)
        {
            highestGPA = current->data.gpa;
        }
        current = current->next;
    }

    // Step 2: Print all students with the highest GPA
    printf("Students with the highest GPA (%f):\n", highestGPA);
    current = head; // Reset pointer to the head of the list

    int found = 0; // Flag to indicate if students are found
    while (current != NULL)
    {
        if (current->data.gpa == highestGPA)
        {
            printf("[Name: %s, ID: %d, Age: %d, GPA: %f]\n",
                   current->data.name, current->data.id,
                   current->data.age, current->data.gpa);
            found = 1;
        }
        current = current->next;
    }

    if (!found)
    {
        printf("No students found with GPA %f.\n", highestGPA);
    }
}

// Case 7 --> Function to delete a student from the linked list by their ID
void deleteStudent(const int id)
{
	if (head == NULL)
	{
		printf("No students available.\n");
		return;
	}

	struct node *current = head;
	struct node *prev = NULL;

	if (current->data.id == id)
	{
		head = current->next;
		free(current);
		printf("Success: Student with ID %d deleted.\n", id);
		return;
	}

	while (current != NULL && current->data.id != id)
	{
		prev = current;
		current = current->next;
	}

	if (current == NULL)
	{
		printf("Error: Student with ID %d not found.\n", id);
		return;
	}

	prev->next = current->next;
	free(current);
	printf("Success: Student with ID %d deleted.\n", id);
}



// Function to ask if the user wants to continue.
void ContinueMoreTask(void)
{
	int i = 0;
	char Continue_More_Task [] = {'Y', 'y','N', 'n', '\0'};
	printf("\nDo you want to continue (Yes/No)? \n");
	scanf("%s", Continue_More_Task);
	if ((Continue_More_Task [i] == 'N') || (Continue_More_Task [i] == 'n') || (Continue_More_Task [i] == 'Y') || (Continue_More_Task [i] == 'y'))
	{
		if ((Continue_More_Task [i] == 'N') || (Continue_More_Task [i] == 'n')){
			printf("Exitting...\n");
			printf("-----------------------------------------------------\n");
			exit(0);
		}
	}
	else
	{
		printf("Invalid choice.\n");
		ContinueMoreTask();
	}
}

