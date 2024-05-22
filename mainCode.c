/* Student Management System Documentation
Overview : 
This program is a console-based student management system implemented in C. It allows users to add, delete, display, and search for student records using a linked list data structure. Each student record contains the student's first name, ID, age, and a note.

Data Structures
struct node
This structure represents a student record. It contains the following fields:

char firstName[MAX_FIRSTNAME_LEN]: The student's first name.
char id[MAX_ID_LEN]: The student's ID.
char age[MAX_NOTE_LEN]: The student's age.
char note[MAX_NOTE_LEN]: A note about the student.
struct node* next: A pointer to the next node in the linked list.
Functions
void beGin(void)
Displays the introduction to the program, including instructions on how to use it. Clears the console screen.

void enterDecision(char* decision)
Prompts the user to enter a decision, reads the input, and processes it to remove any trailing newline characters and convert it to lowercase.

short testDecision(char* decision)
Compares the user's decision to predefined commands (add, delet, display, search, exit) and returns a corresponding integer value. Returns -1 if the decision is not recognized.

void createNode(struct node** START)
Creates a new node for a student record, appends it to the end of the linked list, and prompts the user to enter the student's details.

void enterStudent(struct node* newNode)
Prompts the user to enter the details (first name, ID, age, note) for a new student and stores them in the given node.

int numberNode(struct node* START)
Counts and returns the number of nodes in the linked list.

void displayNode(struct node* START)
Displays the details of all students in the linked list. The list is sorted alphabetically by the student's first name before being displayed.

void searchStudent(struct node* START)
Prompts the user to enter a student ID, searches for the corresponding student in the linked list, and displays their details if found.

void deleteNode(struct node** START)
Prompts the user to enter a student ID, searches for the corresponding student in the linked list, and deletes the node if found. Adjusts pointers to maintain the linked list structure and frees the memory of the deleted node.

void exIt(struct node** START)
Frees all memory allocated for the nodes in the linked list and exits the program. Displays a thank-you message and the number of students.

void convertInput(char* decision)
Converts all characters in the input string to lowercase.

void deletNewLine(char* string)
Removes newline characters from the input string.

void reArange(struct node* START)
Sorts the nodes in the linked list alphabetically by the student's first name.

Main Loop
The main function contains a loop that continuously prompts the user to enter a decision. Based on the user's decision, it calls the appropriate function to add, delete, display, or search for a student, or to exit the program.

Usage
Start the Program:

Run the program. It will display instructions and wait for the user to press the spacebar to start.
Enter a Decision:

Type a decision: add, delet, display, search, or exit.
add: Prompts for student details and adds a new student record.
delet: Prompts for a student ID and deletes the corresponding record.
display: Displays all student records sorted alphabetically by first name.
search: Prompts for a student ID and displays the corresponding record.
exit: Frees memory and exits the program.
Memory Management
The program dynamically allocates memory for each student node and frees it upon deletion or exit to prevent memory leaks.
Error Handling
The program checks for successful memory allocation and handles cases where no students are present for certain operations (e.g., delete, display, search).
Limitations
The program uses fixed-size arrays for storing strings, which may limit the maximum length of the input data.
The program relies on the user to enter valid input and does not perform extensive input validation. */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#define MAX_FIRSTNAME_LEN 30
#define MAX_ID_LEN 10
#define MAX_NOTE_LEN 7
struct node
{
    struct
    {
        char firstName[MAX_FIRSTNAME_LEN];
        char id[MAX_ID_LEN];
        char age[MAX_NOTE_LEN];
        char note[MAX_NOTE_LEN];
    };
    struct node* next;
};
void exIt(struct node**);           // FUNCTION TO EXIT FROM THE PROGRAM AND DELET ALL THE NODES
void beGin(void);                  // FUNCTION FOR INTRODUCTION TO THE CODE AND HOW TO USE IT
short testDecision(char*); // FUNCTION TO TEST THE DECISION THAT USER ENTERES
void enterDecision(char* ); // FUNCTION TO ENTER ONLY THE DECISION
void createNode(struct node**);      // FUNCTION TO CREAT A NEW NODE
int numberNode(struct node*);     // FUNCTION TO CALCULATE THE NUMBER OF NODES
void deleteNode(struct node**);      // FUNCTION TO DELET ONE NODE
void enterStudent(struct node*);    // FUNCTION TO ENTER STUDENT INFORMATIONS
void displayNode(struct node*);     // FUNCTION TO DISPLAY ALL THE DATA OF NODES
void searchStudent(struct node*);   // FUNCTION TO SEARCH FOR A STUDENT
void convertInput(char *);          // FUNCTION TO CONVERT THE USER ENTER DECISION TO LOWERCASE
void deletNewLine(char*);
void reArange(struct node*);
int main(void)
{
    beGin();
    struct node* START = NULL;
    char *decision;
    short state = 0, counter = 0;
    do
    {
        decision = calloc(MAX_ID_LEN ,sizeof(char));
        if(decision == NULL)
            printf("FAIL TO ALLOCATE MEMORY\n");
        else
        {
            memset(decision, '\0', MAX_ID_LEN);
            enterDecision(decision);
            state = testDecision(decision);
            if(state == 0)
                createNode(&START);
            else if(state == 1)
                deleteNode(&START);
            else if(state == 2)
                displayNode(START);
            else if(state == 3)
                searchStudent(START);
            else if(state == 4)
            {
                free(decision);
                exIt(&START);
            }
            else
                printf("ERROR REENTER THE DECISION\n");
            free(decision);
        }
    }while(true);
}
void enterDecision(char* decision)
{
    printf("enter the decision : ");
    fgets(decision, MAX_ID_LEN, stdin);
    deletNewLine(decision);
    convertInput(decision);
}
short testDecision(char* decision)
{
    if(strcmp(decision, "add") == 0)
        return 0;
    else if(strcmp(decision, "delet") == 0)
        return 1;
    else if(strcmp(decision, "display") == 0)
        return 2;
    else if(strcmp(decision, "search") == 0)
        return 3;
    else if(strcmp(decision, "exit") == 0)
        return 4;
    else    
        return -1;     
}
void createNode(struct node** START)
{
    struct node* newNode = malloc(sizeof(struct node));
    struct node* pointer;
    if(newNode == NULL)
        printf("NO MEMORY TO ALLOCATE IT\n");
    else
    {
        newNode->next = NULL;
        if(*START == NULL)
            *START = newNode;
        else
        {
            pointer = *START;
            while(pointer->next != NULL)
                pointer = pointer->next;
            pointer->next = newNode;
        } 
        enterStudent(newNode);
    }
}
void enterStudent(struct node* newNode)
{
    printf("STUDENT firstName : ");
    fgets(newNode->firstName, MAX_FIRSTNAME_LEN, stdin);
    deletNewLine(newNode->firstName);
    printf("STUDENT ID : ");
    fgets(newNode->id, MAX_ID_LEN, stdin);
    deletNewLine(newNode->id);
    printf("STUDENT NOTE : ");
    fgets(newNode->note, MAX_NOTE_LEN, stdin);
    deletNewLine(newNode->note);
    printf("STUDENT age : ");
    fgets(newNode->age, MAX_NOTE_LEN, stdin);
    deletNewLine(newNode->age);
}
int numberNode(struct node* START)
{
    struct node* pointer = START;
    int counter = 0;
    while(pointer != NULL)
    {
        ++counter;
        pointer = pointer->next;
    }
    return counter;
}
void displayNode(struct node* START)
{
    int i= 0;
    if(START == NULL)
        printf("NO STUDENT TO DISPLAY\n");
    else
    {
        reArange(START);
        system("cls");
        struct node* pointer = START;
        while(pointer != NULL)
        {
            printf("STUDENT %d : \n", i+1);
            printf("\tNAME : %s\n", pointer->firstName);
            printf("\tAGE : %s\n", pointer->age);
            printf("\tID : %s\n", pointer->id);
            printf("\tNOTE : %s\n", pointer->note);
            pointer = pointer->next;
            ++i;
        }
    }
}
void searchStudent(struct node* START)
{
    if(START == NULL)
        printf("NO STUDENT TO SEARCH\n");
    else 
    {
        bool state = false;
        char *ID = calloc(MAX_ID_LEN, sizeof(char));
        if(ID == NULL)
            printf("FAIL TO ALLOCATE MEMORY\n");
        else
        {
            struct node* pointer = START;
            struct node* p_current = NULL;
            printf("ID OF STUDENT : ");
            fgets(ID, MAX_ID_LEN, stdin);
            deletNewLine(ID);
            while(pointer != NULL)
            {
                if(strcmp(pointer->id,ID) == 0)
                {
                    state = true;
                    p_current = pointer;
                    break;
                }
                pointer = pointer->next;
            }
            if(state == true)
            {
                system("cls");
                printf("firstName : %s\n", p_current->firstName);
                printf("age : %s\n", p_current->age);
                printf("ID : %s\n", p_current->id);
                printf("NOTE : %s\n", p_current->note);
            }
            else
                printf("STUDENT IS NOT IN THE LIST\n");
            free(ID);
        }
    }
}
void deleteNode(struct node** START)
{
    if(*START == NULL)
        printf("NO STUDENT IN LIST TO DELET\n");
    else
    {
        bool state = false;
        int i = 0;
        char *ID = calloc(MAX_ID_LEN, sizeof(char));
        if(ID == NULL)
            printf("FAIL TO ALLOCATE MEMORY\n");
        else
        {
            struct node* pointer = *START;
            struct node* pointer_current = NULL;
            struct node* pointer_previous = NULL;
            printf("ID OF STUDENT YOU WANT DELET : ");
            fgets(ID, MAX_ID_LEN, stdin);
            deletNewLine(ID);
            while(pointer != NULL)
            {
                if(strcmp(pointer->id, ID) == 0)
                {
                    state = true;
                    pointer_current = pointer;
                    break;
                }
                pointer = pointer->next;
            }
            pointer = *START;
            if(state == true)
            {
                if(pointer_current == *START)
                {
                    *START = pointer_current->next;
                    free(pointer_current);
                }
                else if(pointer_current->next == NULL)
                {
                    while(pointer->next != pointer_current)
                        pointer = pointer->next;
                    pointer_previous = pointer;
                    pointer_previous->next = NULL;
                    free(pointer_current);
                }
                else
                {
                    while(pointer->next != pointer_current)
                        pointer = pointer->next;
                    pointer_previous = pointer;
                    pointer_previous->next = pointer_current->next;
                    free(pointer_current);
                }
            }
            else
                printf("STUDENT IS NOT IN THE LIST\n");
        }
        free(ID);
    }
}
void beGin(void)
{
    system("cls");
    printf("\t\t\t\t<<<<<<< STUDENT SYSTEM MANAGEMENT >>>>>>>\n");
    printf("\t\t\t\t\t\t1)-ADD\n");
    printf("\t\t\t\t\t\t2)-DELET\n");
    printf("\t\t\t\t\t\t3)-DISPLAY\n");
    printf("\t\t\t\t\t\t4)-SEARCH\n");
    printf("\n\t\t\t\tNOTE : \n");
    printf("\t\t\t\t\tFOR firstName MAX LENGTH IS 28\n");
    printf("\t\t\t\t\tFOR ID MAX LENGTH IS 8\n");
    printf("\t\t\t\t\tFOR age MAX LENGTH IS 28\n");
    printf("\t\t\t\t\tFOR NOTE MAX LENGTH IS 5\n");
    printf("ENTER SPACE TO START : ");
    char value;
    while(true)
    {
        value = getch();
        if(value == 0x20)
            break;
    }
    printf("\n");
}
void exIt(struct node** START)
{
    system("cls");
    if(*START == NULL)
    {
        printf("\t\t\t\t<<<<<<<< THANK YOU >>>>>>>>\n");
        printf("\t\t\t\t\tNUMBER OF STUDENT = %d\n", 0);
    }
    else
    {
        int counter = 0;
        struct node* pointer = *START;
        while(pointer != NULL)
        {
            ++counter;
            pointer = pointer->next;
        }
        printf("\t\t\t\t<<<<<<<< THANK YOU >>>>>>>>\n");
        printf("\t\t\t\t\tNUMBER OF STUDENT = %d\n", counter);
        pointer = *START;
        counter = 0;
        while((*START)->next != NULL)
        {
            (*START) = (*START)->next;
            free(pointer);
            pointer = *START;
        }
        free(pointer);
        *START = NULL;
    }
    exit(EXIT_SUCCESS);
}
void convertInput(char* decision)
{
    int i = 0;
    while(decision[i] != '\0')
    {
        if(decision[i] >= 'A' && decision[i] <= 'Z')
            decision[i] += 32;
        ++i;
    }
}
void deletNewLine(char* string)
{
    int i = 0;
    while(string[i] != '\0')
    {
        if(string[i] == '\n')
            string[i] = '\0';
        ++i;
    }
    i = 0;
}
void reArange(struct node* START)
{
    int counter = numberNode(START);
    struct node* pointer = START;
    char *string_name = calloc(MAX_FIRSTNAME_LEN, sizeof(char));
    if(string_name == NULL)
        printf("CANNOT ALLOCATE MEMORY FOR STRING_NAME");
    char *string_age = calloc(MAX_NOTE_LEN, sizeof(char));
    if(string_age == NULL)
        printf("CANNOT ALLOCATE MEMORY FOR STRING_AGE");
    char *string_id = calloc(MAX_ID_LEN, sizeof(char));
    if(string_id == NULL)
        printf("CANNOT ALLOCATE MEMORY FOR STRING_ID");
    char *string_note = calloc(MAX_NOTE_LEN, sizeof(char));
    if(string_note == NULL)
        printf("CANNOT ALLOCATE MEMORY FOR STRING_NOTE");
    --counter;
    while(counter >= 0)
    {
        pointer = START;
        while(pointer->next != NULL)
        {
            if(strcmp(pointer->firstName, pointer->next->firstName) > 0)
            {
                strcpy(string_name, pointer->next->firstName);
                strcpy(pointer->next->firstName, pointer->firstName);
                strcpy(pointer->firstName, string_name);

                strcpy(string_age, pointer->next->age);
                strcpy(pointer->next->age, pointer->age);
                strcpy(pointer->age, string_age);
    

                strcpy(string_id, pointer->next->id);
                strcpy(pointer->next->id, pointer->id);
                strcpy(pointer->id, string_id);

                strcpy(string_note, pointer->next->note);
                strcpy(pointer->next->note, pointer->note);
                strcpy(pointer->note, string_note);
            }
            pointer = pointer->next;
        }
        --counter;
    }
    free(string_age);
    free(string_id);
    free(string_name);
    free(string_note);
}
