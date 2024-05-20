#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#define large 30
#define less 10
#define few 7
struct node
{
    struct
    {
        char name[large];
        char id[less];
        char country[large];
        char note[few];
    };
    struct node* next;
};
void exIt(struct node**);           // FUNCTION TO EXIT FROM THE PROGRAM AND DELET ALL THE NODES
void beGing(void);                  // FUNCTION FOR INTRODUCTION TO THE CODE AND HOW TO USE IT
short testDecision(char* decision); // FUNCTION TO TEST THE DECISION THAT USER ENTERES
void enterDecision(char* decision); // FUNCTION TO ENTER ONLY THE DECISION
void creatNode(struct node**);      // FUNCTION TO CREAT A NEW NODE
short numberNode(struct node*);     // FUNCTION TO CALCULATE THE NUMBER OF NODES
void deletNode(struct node**);      // FUNCTION TO DELET ONE NODE
void enterStudent(struct node*);    // FUNCTION TO ENTER STUDENT INFORMATIONS
void displayNode(struct node*);     // FUNCTION TO DISPLAY ALL THE DATA OF NODES
void searchStudent(struct node*);   // FUNCTION TO SEARCH FOR A STUDENT
void convertInput(char *);          // FUNCTION TO CONVERT THE USER ENTER DECISION TO LOWERCASE
void deletNewLine(char*);
int main(void)
{
    beGing();
    struct node* START = NULL;
    char *decision;
    short state = 0, counter = 0;
    do
    {
        decision = calloc(less ,sizeof(char));
        if(decision == NULL)
            printf("FAIL TO ALLOCATE MEMORY\n");
        else
        {
            memset(decision, '\0', less);
            enterDecision(decision);
            state = testDecision(decision);
            if(state == 0)
                creatNode(&START);
            else if(state == 2)
            {
                counter = numberNode(START);
                printf("NUMBER OF STUDENTS : %d\n", counter);
            }
            else if(state == 1)
                deletNode(&START);
            else if(state == 3)
                displayNode(START);
            else if(state == 4)
                searchStudent(START);
            else if(state == 5)
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
    fgets(decision, less, stdin);
    deletNewLine(decision);
    convertInput(decision);
}
short testDecision(char* decision)
{
    if(strcmp(decision, "add") == 0)
        return 0;
    else if(strcmp(decision, "delet") == 0)
        return 1;
    else if(strcmp(decision, "counting") == 0)
        return 2;
    else if(strcmp(decision, "display") == 0)
        return 3;
    else if(strcmp(decision, "search") == 0)
        return 4;
    else if(strcmp(decision, "exit") == 0)
        return 5;
    else    
        return -1;     
}
void creatNode(struct node** START)
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
    printf("STUDENT NAME : ");
    fgets(newNode->name, large, stdin);
    printf("length = %d\n", strlen(newNode->name));
    deletNewLine(newNode->name);
    printf("length = %d\n", strlen(newNode->name));
    exit(0);
    printf("STUDENT ID : ");
    fgets(newNode->id, less, stdin);
    deletNewLine(newNode->id);
    printf("STUDENT NOTE : ");
    fgets(newNode->note, few, stdin);
    deletNewLine(newNode->note);
    printf("STUDENT COUNTRY : ");
    fgets(newNode->country, large, stdin);
    deletNewLine(newNode->country);
}
short numberNode(struct node* START)
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
    int i = 0;
    if(START == NULL)
        printf("NO STUDENT TO DISPLAY\n");
    else
    {
        system("cls");
        struct node* pointer = START;
        while(pointer != NULL)
        {
            printf("STUDENT %d : \n", i+1);
            printf("\tNAME : %s\n", pointer->name);
            printf("\tCOUNTRY : %s\n", pointer->country);
            printf("\tID = %s\n", pointer->id);
            printf("\tNOTE : %s\n", pointer->note);
            printf("\n");
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
        char *ID = calloc(less, sizeof(char));
        if(ID == NULL)
            printf("FAIL TO ALLOCATE MEMORY\n");
        else
        {
            struct node* pointer = START;
            struct node* p_current = NULL;
            printf("ID OF STUDENT : ");
            fgets(ID, less, stdin);
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
                printf("NAME : %s\n", p_current->name);
                printf("COUNTRY : %s\n", p_current->country);
                printf("ID : %s\n", p_current->id);
                printf("NOTE : %s\n", p_current->note);
            }
            else
                printf("STUDENT IS NOT IN THE LIST\n");
            free(ID);
        }
    }
}
void deletNode(struct node** START)
{
    if(*START == NULL)
        printf("NO STUDENT IN LIST TO DELET\n");
    else
    {
        int i = 0;
        char *ID = calloc(less, sizeof(char));
        if(ID == NULL)
            printf("FAIL TO ALLOCATE MEMORY\n");
        else
        {
            struct node* pointer = *START;
            struct node* p_current = NULL;
            struct node* p_prev = NULL;
            printf("ID OF STUDENT YOU WANT DELET : ");
            fgets(ID, less, stdin);
            deletNewLine(ID);
            if(strcmp(pointer->id, ID) == 0)
            {
                *START = pointer->next;
                free(pointer);
            }
            else
            {
                while(pointer != NULL)
                {
                    if(strcmp(pointer->next->id,ID) == 0)
                    {
                        p_current = pointer->next;
                        p_prev = pointer;
                        break;
                    }
                    pointer = pointer->next;
                }
                if(p_current->next == NULL)
                {
                    free(p_current);
                    p_prev->next = NULL;
                }
                else
                {
                    p_prev->next = p_current->next;
                    free(p_current);
                }
            }
        }
        free(ID);
    }
}
void beGing(void)
{
    system("cls");
    printf("\t\t\t\t<<<<<<< STUDENT SYSTEM MANAGEMENT >>>>>>>\n");
    printf("\t\t\t\t\t\t1)-ADD\n");
    printf("\t\t\t\t\t\t2)-DELET\n");
    printf("\t\t\t\t\t\t3)-DISPLAY\n");
    printf("\t\t\t\t\t\t4)-SEARCH\n");
    printf("\n\t\t\t\tNOTE : \n");
    printf("\t\t\t\t\tFOR NAME MAX LENGTH IS 28\n");
    printf("\t\t\t\t\tFOR ID MAX LENGTH IS 8\n");
    printf("\t\t\t\t\tFOR COUNTRY MAX LENGTH IS 28\n");
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
        printf("\t\t\t\t\tNUMBER OF STUDENT  = %d\n", 0);
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