#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project1.1.c"
#include "blockchainBaseConcept.c"

void signUp();
void login();
void again1() {
    char playAgain;
    printf("\n\nDo you want to play again?\n'y' for Yes\n'n' for No");
    scanf(" %c", &playAgain);  // Use a different variable to avoid conflicts with again
    getchar();  // Consume the newline character left in the buffer

    switch (playAgain) {
        case 'y':
        case 'Y':
            printf("Login First\n\n");
            login();
            // Call the appropriate function (e.g., op()) after login
            break;
        case 'n':
        case 'N':
            goto end;
        default:
            printf("Invalid choice\n");
    }
    end:
    printf("\nThank You\n");
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
        printf("\n\nPress 1 - for Login\nPress 2 - for Sign Up\n");

        scanf("%d", &press);
        getchar();

        switch (press) {
            case 1:
                login();
                break;
            case 2:
                signUp();
                op();
                again1();
                break;
            default:
                printf("\nInvalid choice\n");
                break;
        }
    } else {
        printf("Wrong URL");
        printf("Enter coorect url:\n");
        
    }
    // end:
    // printf("\nThank You\n");
    return 0;
}

void signUp() {
    char name[50], email[50], pass[50];

    printf("\n\nSign Up\n");

    printf("Enter the Username: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("\n\nEnter the Email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    while (1) {
        printf("\n\nEnter the Password: ");
        fgets(pass, sizeof(pass), stdin);
        pass[strcspn(pass, "\n")] = '\0';

        if (strchr(pass, ' ') == NULL) {
            break;
        } else {
            printf("\n\aSpaces are not allowed in PASSWORD!\n\n");
            printf("Re-Enter the password: ");
        }
    }

    // append 
    FILE *file = fopen("users.txt", "a");
    if (file == NULL) {
        printf("\nError opening file\n");
        exit(1);
    }

    fprintf(file, "%s %s %s\n", name, email, pass);

    fclose(file);

    printf("\nUser registered successfully!\n");
    //  op(option);
   

}

void login() {
    char email[50], pass[50];
    int found = 0;

    printf("\n\nLogin\n");

    printf("Enter the Email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    printf("\n\nEnter the Password: ");
    fgets(pass, sizeof(pass), stdin);
    pass[strcspn(pass, "\n")] = '\0';

    // Check if user credentials exist in the file
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("\nError opening file\n");
        exit(1);
    }

    char line[200];
    while (fgets(line, sizeof(line), file) != NULL) {
        char storedEmail[50], storedPass[50];
        sscanf(line, "%s %s", storedEmail, storedPass);

        if (strcmp(email, storedEmail) == 0 && strcmp(pass, storedPass) == 0) {
            found = 1;
            break;
        }
    }

    fclose(file);

    if (found) {
        printf("\nLogin successful!\n");
    } else {
        printf("\nInvalid email or password. Please try again.\n");
    }

    
}
