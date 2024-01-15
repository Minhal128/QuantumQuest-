#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void delay(int milliseconds) {
    for (int i = 0; i < milliseconds * 10000; i++) {
        // Adjust the loop condition and the multiplication factor as needed
    }
}

void printWithDelay(const char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        printf("%c", text[i]);
        fflush(stdout);
        delay(500); // Adjust the delay duration as needed

        if (text[i] == ' ') {
            printf(" ");
            fflush(stdout);
            delay(250);
        }
    }
}

void riddle1(const char *text)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        printf("%c", text[i]);
        fflush(stdout);
        delay(5000); // Adjust the delay duration as needed

        if (text[i] == ' ') {
            printf(" ");
            fflush(stdout);
            delay(2500);}
    }
    
}


void code(const char *text)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        printf("%c", text[i]);
        fflush(stdout);
        delay(5000); // Adjust the delay duration as needed

        if (text[i] == ' ') {
            printf(" ");
            fflush(stdout);
            delay(2500);}
    }
    
}

void msg(const char *text)
{
       for (int i = 0; text[i] != '\0'; i++)
    {
        printf("%c", text[i]);
        fflush(stdout);
        delay(5000); // Adjust the delay duration as needed

        if (text[i] == ' ') {
            printf(" ");
            fflush(stdout);
            delay(2500);}
    }
}


void decrypted() {

    // printf("Decrypted function executed.\n");
 char message1[]="Kqfsp kwtr ymj wjfw tk ymj gfxj";
    
    int key=5;
    for (int i = 0; i < strlen(message1); i++) {
        if (message1[i] >= 'A' && message1[i] <= 'Z') {
            message1[i] = (message1[i] - 'A' - key + 26) % 26 + 'A';
        } else if (message1[i] >= 'a' && message1[i] <= 'z') {
            message1[i] = (message1[i] - 'a' - key + 26) % 26 + 'a';
        }
    }

       printf("Decrypted Code\n\n\n");
       printf("\n");
       msg(message1);


}

void decrypted1() {

    // printf("Decrypted function executed.\n");
 char message1[]="Lmtbi, bpqa qa Mkpw. Qvqbqibqvo uwdm bw PY ivl izug jiam. Wdmz";
    
    int key=8;
    for (int i = 0; i < strlen(message1); i++) {
        if (message1[i] >= 'A' && message1[i] <= 'Z') {
            message1[i] = (message1[i] - 'A' - key + 26) % 26 + 'A';
        } else if (message1[i] >= 'a' && message1[i] <= 'z') {
            message1[i] = (message1[i] - 'a' - key + 26) % 26 + 'a';
        }
    }

       printf("Decrypted Code\n\n\n");
       printf("\n");
       msg(message1);


}

void decrypted2() {

    // printf("Decrypted function executed.\n");
 char message1[]="qpsu dbnfsbt, up uif mfgu xjoh";
    
    int key=1;
    for (int i = 0; i < strlen(message1); i++) {
        if (message1[i] >= 'A' && message1[i] <= 'Z') {
            message1[i] = (message1[i] - 'A' - key + 26) % 26 + 'A';
        } else if (message1[i] >= 'a' && message1[i] <= 'z') {
            message1[i] = (message1[i] - 'a' - key + 26) % 26 + 'a';
        }
    }

       printf("Decrypted Code\n\n\n");
       printf("\n");
       msg(message1);


}

void decrypted3() {

    // printf("Decrypted function executed.\n");
 char message1[]="Klsah ylhjolk ha aol thyr code";
    
    int key=7;
    for (int i = 0; i < strlen(message1); i++) {
        if (message1[i] >= 'A' && message1[i] <= 'Z') {
            message1[i] = (message1[i] - 'A' - key + 26) % 26 + 'A';
        } else if (message1[i] >= 'a' && message1[i] <= 'z') {
            message1[i] = (message1[i] - 'a' - key + 26) % 26 + 'a';
        }
    }

       printf("Decrypted Code\n\n\n");
       printf("\n");
       msg(message1);


}

void decrypted4() {

    // printf("Decrypted function executed.\n");
 char message1[]="mnuncrwp rbajnu";
    
    int key=9;
    for (int i = 0; i < strlen(message1); i++) {
        if (message1[i] >= 'A' && message1[i] <= 'Z') {
            message1[i] = (message1[i] - 'A' - key + 26) % 26 + 'A';
        } else if (message1[i] >= 'a' && message1[i] <= 'z') {
            message1[i] = (message1[i] - 'a' - key + 26) % 26 + 'a';
        }
    }

       printf("Decrypted Code\n\n\n");
       printf("\n");
       msg(message1);


}


void condition() {
    int max_attempts = 3;
    int key = 0;
    int enter;
        printf("\n\nThis Riddle will Locate the Location of Israeli Gun Marks\n\n");

    for (int attempt = 1; attempt <= max_attempts; ++attempt) {
        char riddle[100];

        printf("\nBreak the Clue\n\n");
        printf("Attempt %d of %d\n", attempt, max_attempts);
        printf("Enter the answer: \n\n");
        scanf("%99s", riddle);  // Limit the input to 99 characters to avoid buffer overflow

        if (strcmp(riddle, "militarybase") == 0) {
            key = 5;
            printf("%c Key=%d\n\n", 251, key);

            printf("Enter the key to decrypt: \n");

            while (1) {
                if (scanf("%d", &enter) == 1) {
                    // Consume the newline character in the input buffer
                    while (getchar() != '\n');

                    if (enter == key) {
                        decrypted();
                        printf("\nGood Job.. You navigated Hamas to the military base\n");
                        return;  // Exit the function after successful decryption
                    } else {
                        printf("Error\nEnter the correct key to decrypt: \n");
                    }
                } else {
                    printf("Invalid input. Please enter a valid key: \n");
                    while (getchar() != '\n');  // Clear the input buffer
                }
            }
        } else {
            printf("Incorrect answer. Try again.\n");
        }
    }

    printf("You've exhausted all attempts. The location remains hidden.\n");
    printf("\n\nYou Lost\n\n");
}

void condition1() {
    int max_attempts = 3;
    int key = 0;
    int enter;
    printf("\n\nThis will indicate the enemy having which equipment\n");
    for (int attempt = 1; attempt <= max_attempts; ++attempt) {
        char riddle[100];

        printf("\nBreak the Clue\n\n");
        printf("Attempt %d of %d\n", attempt, max_attempts);
        printf("Enter the answer: \n\n");
        scanf("%99s", riddle);  // Limit the input to 99 characters to avoid buffer overflow

        if (strcmp(riddle, "sniper") == 0) {
            key = 8;
            printf("%c Key=%d\n\n", 251, key);

            printf("Enter the key to decrypt: \n");

            while (1) {
                if (scanf("%d", &enter) == 1) {
                    // Consume the newline character in the input buffer
                    while (getchar() != '\n');

                    if (enter == key) {
                        decrypted1();
                        printf("\nExcellent.. You help Hamas to conqured the sniper tower \n");
                        return;  // Exit the function after successful decryption
                    } else {
                        printf("Error\nEnter the correct key to decrypt: \n");
                    }
                } else {
                    printf("Invalid input. Please enter a valid key: \n");
                    while (getchar() != '\n');  // Clear the input buffer
                }
            }
        } else {
            printf("Incorrect answer. Try again.\n");
        }
    }

    printf("You've exhausted all attempts. The Hamas was imprisoned.\n");
    printf("\n\nYou Lost\n\n");
}


void condition2() {
    int max_attempts = 3;
    int key = 0;
    int enter;
    printf("\n\nThis key will Help Hamas to hacked the cameras\n");
    for (int attempt = 1; attempt <= max_attempts; ++attempt) {
        char riddle[100];

        printf("\nBreak the Clue\n\n");
        printf("Attempt %d of %d\n", attempt, max_attempts);
        printf("Enter the answer: \n\n");
        scanf("%99s", riddle);  // Limit the input to 99 characters to avoid buffer overflow

        if (strcmp(riddle, "binarycode") == 0) {
            key = 1;
            printf("%c Key=%d\n\n", 251, key);

            printf("Enter the key to decrypt: \n");

            while (1) {
                if (scanf("%d", &enter) == 1) {
                    // Consume the newline character in the input buffer
                    while (getchar() != '\n');

                    if (enter == key) {
                        decrypted2();
                        printf("\nMarvelous.. You help Hamas to hack the Israeli base cameras \n");
                        return;  // Exit the function after successful decryption
                    } else {
                        printf("Error\nEnter the correct key to decrypt: \n");
                    }
                } else {
                    printf("Invalid input. Please enter a valid key: \n");
                    while (getchar() != '\n');  // Clear the input buffer
                }
            }
        } else {
            printf("Incorrect answer. Try again.\n");
        }
    }

    printf("You've exhausted all attempts. The Hamas location was traced.\n");
    printf("\n\nYou Lost\n\n");
}
//Klsah ylhjolk ha aol thyr code

void condition3() {
    int max_attempts = 3;
    int key = 0;
    int enter;
    printf("\n\nThis key will Help Hamas to call their troops\n");
    for (int attempt = 1; attempt <= max_attempts; ++attempt) {
        char riddle[100];

        printf("\nBreak the Clue\n\n");
        printf("Attempt %d of %d\n", attempt, max_attempts);
        printf("Enter the answer: \n\n");
        scanf("%99s", riddle);  // Limit the input to 99 characters to avoid buffer overflow

        if (strcmp(riddle, "telepathy") == 0) {
            key = 7;
            printf("%c Key=%d\n\n", 251, key);

            printf("Enter the key to decrypt: \n");

            while (1) {
                if (scanf("%d", &enter) == 1) {
                    // Consume the newline character in the input buffer
                    while (getchar() != '\n');

                    if (enter == key) {
                        decrypted3();
                        printf("\nSuperb.. You help Hamas to call their troops \n");
                        return;  // Exit the function after successful decryption
                    } else {
                        printf("Error\nEnter the correct key to decrypt: \n");
                    }
                } else {
                    printf("Invalid input. Please enter a valid key: \n");
                    while (getchar() != '\n');  // Clear the input buffer
                }
            }
        } else {
            printf("Incorrect answer. Try again.\n");
        }
    }

    printf("You've exhausted all attempts. The Hamas troops was imprisoned by the enemies.\n");
    printf("\n\nYou Lost\n\n");
}

void condition4() {


    int max_attempts = 3;
    int key = 0;
    int enter;
    printf("\n\nThis key will Help Hamas to conquere\n");
    for (int attempt = 1; attempt <= max_attempts; ++attempt) {
        char riddle[100];

        printf("\nBreak the Clue\n\n");
        printf("Attempt %d of %d\n", attempt, max_attempts);
        printf("Enter the answer: \n\n");
        scanf("%99s", riddle);  // Limit the input to 99 characters to avoid buffer overflow

        if (strcmp(riddle, "time") == 0) {
            key = 9;
            printf("%c Key=%d\n\n", 251, key);

            printf("Enter the key to decrypt: \n");

            while (1) {
                if (scanf("%d", &enter) == 1) {
                    // Consume the newline character in the input buffer
                    while (getchar() != '\n');

                    if (enter == key) {
                        decrypted4();
                        printf("\nRemarkable.. You help Hamas to conquered the Israel \n");
                        printf("\n\nHistory has been created \n\n");
                        printf("\n\nCongratulations The Adinistrator is greatly pleased to the user, as hammas is helped by the user to conquer the Israel.\n\n");
                        return;  // Exit the function after successful decryption
                    } else {
                        printf("Error\nEnter the correct key to decrypt: \n");
                    }
                } else {
                    printf("Invalid input. Please enter a valid key: \n");
                    while (getchar() != '\n');  // Clear the input buffer
                }
            }
        } else {
            printf("Incorrect answer. Try again.\n");
        }
    }

    printf("You've exhausted all attempts. America Interupt the war and imprisoned Hamas .\n");
    printf("\n\nYou Lost\n\n");
}


void op() {
    int option, enter,a;
    int level;
    char again;
    int count = 4, key = 5; // Set the correct key value

    // 
    char Story[] = "Surviving a 2000 Israeli attack on his Palestinian family, Abdul was adopted by Israelis and joined their army. In 2023, driven by a thirst for revenge, he assisted Hamas by revealing a concealed entry point into Israel through encrypted codes. Abdul's choice highlights the intricate interplay between personal history and geopolitical tensions, emphasizing the need for nuanced approaches to conflict resolution and understanding the complex emotions involved..... Now you are abdul and you have to help Hammas.";
    char Story2[]= "When the boy Abdul succeed to enter the hammas militry force to israel, then he start to work on giving access of israeli's militry base to hammas forces, by entering them to rare phase of israil's sniper tower base, to be conquered by the hammas militry forces by giving them a encrypted key to access the sniper base. ";
    char Story3[]= " Abdul did so just to attack the israeli's, by doing so he wants to give full access of sniper base to hammas forces, by hacking their cameras, weapons, radars, and base devices by the professionalised hackers. Then Abdul give them command to hack the cameras of the base. ";
    char Story4[]= "Now after accessing control over the cameras Abdul guide them that, from where the Hammas forces have to enter to attack the Israeli's forces, as Abdul helps Hammas forces to guide their troops from where they have to enter the base ";
    char Story5[]= "At the conclusion, Hammas gain control over isreal and conquer it. Abdul suceed in taking the revenge of his parents and raise the flag of palestine in Israel.";
    //story end
    //riddle start
    char riddle[]="Beneath camouflage, secrets unfold, where discipline and courage are untold";
    char riddle2[]="A silent guardian in the shadows of green, where camouflage conceals the unseen. What am I?";
    char riddle3[]="Crack the digital fortress, where 101010 meets secrets untold";
    char riddle4[]="In silence I speak, unheard but felt, signaling across realms with a presence unfelt.";
    char riddle5[]="In shadows I rose, conquered realms unseen, my triumph whispered in the echoes of what might have been.";
    //riddle ends encrypted code start
    char code1[]="The encrypted code is 'Kqfsp kwtr ymj wjfw tk ymj gfxj'";
    char code2[]="The encrypted code is ' Lmtbi, bpqa qa Mkpw. Qvqbqibqvo uwdm bw PY ivl izug jiam. Wdmz' ";
    char code3[]="The encrypted code is 'qpsu dbnfsbt, up uif mfgu xjoh' ";
    char code4[]="The encrypted code is 'Klsah ylhjolk ha aol thyr' ";
    char code5[]="The encrypted code is 'mnuncrwp rbajnu' ";
   
    printf("\nWelcome\n");
    printf("\nHere are three exciting games for\n1- QuantumQuest (Encryption)\n2- EpicBlock Quest (Blockchain Basic)\n\n");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Story--\n");

            printWithDelay(Story);
            printf("\n");
            printf("\n\nFor the decryption, you have to find a key by resolving riddles, and you have only 3 tries\n\n");
            // printf("\n");
            printf("\n\n");
            code(code1);
            printf("\n\nClue\n\n");
            riddle1(riddle);
            condition();

            printf("\nLevel 1 Compelete\n");
            printf("\nPress 2 for Level 2\n");
            scanf("%d",&level);
            if (level==2)
            {
                printf("forward on--");

            printWithDelay(Story2);
            printf("\n");
            printf("\n\nFor the decryption, you have to find a key by resolving riddles, and you have only 3 tries\n\n");
            printf("\n");
            code(code2);
            printf("\n\nClue\n\n");
            riddle1(riddle2);
            condition1();
            }
            
            printf("\nLevel 2 Compeleted\n");
            printf("\nPress 3 for Level 3\n");
            scanf("%d",&level);

           if (level==3)
            {
            printf("forward on--");
            printWithDelay(Story3);
            printf("\n");
            printf("\n\nFor the decryption, you have to find a key by resolving riddles, and you have only 3 tries\n\n");
            printf("\n");
            code(code3);
            printf("\n\nClue\n\n");
            riddle1(riddle3);
            condition2();
            }
            printf("\nLevel 3 Compeleted\n");
            printf("\nPress 4 for Level 4\n");
            scanf("%d",&level);

            if (level==4)
            {
            printf("forward on--");
            printWithDelay(Story4);
            printf("\n");
            printf("\n\nFor the decryption, you have to find a key by resolving riddles, and you have only 3 tries\n\n");
            printf("\n");
            code(code4);
            printf("\n\nClue\n\n");
            riddle1(riddle4);
            condition3();
            }
            printf("\nLevel 4 Compeleted\n");
            printf("\nPress 5 for Level 5\n");
            scanf("%d",&level);

             if (level==5)
            {
            printf("forward on--");
            printWithDelay(Story5);
            printf("\n");
            printf("\n\nFor the decryption, you have to find a key by resolving riddles, and you have only 3 tries\n\n");
            printf("\n");
            code(code5);
            printf("\n\nClue\n\n");
            riddle1(riddle5);
            condition4();
            }
            break;

            case 2:
            block();
            break;
}
}