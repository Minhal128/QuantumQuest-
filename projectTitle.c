#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project1.1.c"
#include "blockchainBaseConcept.c"

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// Function declarations
void signUp();
int login();


    
// Function to sign up a new user
void signUp() {
    char username[50], password[50];

    printf("\nEnter a username: ");
    scanf("%s", username);

    printf("Enter a password: ");
    scanf("%s", password);

    // Append user details to the file
    FILE *file = fopen("users.txt", "a");
    if (file == NULL) {
        printf("\nError opening file.\n");
        exit(1);
    }

    fprintf(file, "%s %s\n", username, password);
    fclose(file);
}

// Function to perform user login
int login() {
    char username[50], password[50];
    int found = 0;

    printf("\nEnter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    // Check if user credentials exist in the file
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("\nError opening file.\n");
        exit(1);
    }

    char storedUsername[50], storedPassword[50];
    while (fscanf(file, "%s %s", storedUsername, storedPassword) != EOF) {
        if (strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0) {
            found = 1;
            break;
        }
    }

    fclose(file);

    return found;
}


int main() {
    char web[50];
    int press,option;
    char again;
    printf("  *******         *****          *****           *******       *          ******\n");
    printf(" *              *       *      *       *       *               *         *\n");
    printf(" *             *         *    *         *      *               *         *\n");
    printf(" *     ***     *         *    *         *      *      ***      *         *******\n");
    printf(" *       *     *         *    *         *      *        *      *         *\n");
    printf(" *       *      *       *      *       *       *        *      *         *\n");
    printf("  *******         *****          *****           *******        ******    *******\n\n");

    printf("WEBSITE: www.iam.com\n\n");
    printf("\n\nEnter the website URL :| ");
    scanf("%s", web);
  
    if (strstr(web, "www.iam.com") != NULL) {
        printf("\n\nCorrect URL");
        printf("\n\n********* Welcome to IAM *********");
        int choice;

    do {
        printf("\n************* Welcome *************\n");
        printf("1. Login\n");
        printf("2. Sign Up\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (login()) {
                    printf("\nLogin successful!\n");
                    op();
                } else {
                    printf("\nLogin failed. Invalid credentials.\n");
                }
                break;
            case 2:
                signUp();
                printf("\nSign up successful! You can now log in.\n");
                op();
                break;
            case 3:
                printf("\nExiting program.\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please enter a valid option.\n");
        }

    } while (1);

    return 0;
}
}

