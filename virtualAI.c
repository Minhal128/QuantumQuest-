#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
#define HI.mp3
int intro() {
    char arr[100], name[100];
    printf("\nWelcome to AI\n");
    printf("Enter your name: \n");
    fgets(name, sizeof(name), stdin);
    printf("%s please greet our AI\n", name);

    printf("Enter a greeting: \n");
    fgets(arr, sizeof(arr), stdin);

    // Check if the input is "hello"
    if (strcmp(arr, "hello\n") == 0) {
        PlaySound(TEXT("E:\\dasti\\QuantumQuest-"), NULL, SND_SYNC);
    }

    return 0;
}
