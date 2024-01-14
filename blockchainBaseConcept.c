#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Yahan ek structure define kia gaya hai jo transaction ko represent karega.
typedef struct {
    char sender[50];
    char receiver[50];
    double amount;
} Transaction;

// Yahan ek structure define kia gaya hai jo block ko represent karega.
typedef struct {
    int index;
    time_t timestamp;
    Transaction data;
    char previousHash[65];
    char hash[65];
} Block;

// Yahan block ka hash calculate karne ka function hai.
void calculateHash(Block *block, char *hashOutput) {
    // Block ki information ko concatenate karnay ke liye ek string banao.
    char input[150];
    snprintf(input, sizeof(input), "%d%ld%s%s%lf", block->index, block->timestamp, block->data.sender, block->data.receiver, block->data.amount);

    // Simple hash function use karo (demonstration ke liye).
    unsigned long hash = 5381;
    int i = 0;

    while (input[i] != '\0') {
        hash = ((hash << 5) + hash) + input[i++];
    }

    // Hexadecimal form mein hash ko string mein convert karo.
    snprintf(hashOutput, 65, "%lx", hash);
}

// Yahan ek naya block create karne ka function hai.
Block createBlock(int index, Transaction data, char *previousHash) {
    Block newBlock;

    // Block ki information set karo.
    newBlock.index = index;
    newBlock.timestamp = time(NULL);
    newBlock.data = data;
    strcpy(newBlock.previousHash, previousHash);

    // Block ka hash calculate karo.
    calculateHash(&newBlock, newBlock.hash);

    return newBlock;
}

// Yahan ek block ko blockchain mein add karne ka function hai.
void addBlock(Block newBlock, Block *blockchain, int *blockchainSize) {
    blockchain[*blockchainSize] = newBlock;
    (*blockchainSize)++;
}

// Yahan blockchain ko display karne ka function hai.
void displayBlockchain(Block *blockchain, int blockchainSize) {
    for (int i = 0; i < blockchainSize; ++i) {
        printf("\nBlock #%d\n", blockchain[i].index);
        printf("Timestamp: %s", asctime(localtime(&blockchain[i].timestamp)));
        printf("Sender: %s\n", blockchain[i].data.sender);
        printf("Receiver: %s\n", blockchain[i].data.receiver);
        printf("Amount: %.2lf\n", blockchain[i].data.amount);
        printf("Previous Hash: %s\n", blockchain[i].previousHash);
        printf("Hash: %s\n", blockchain[i].hash);
        printf("---------------------------");
    }
    printf("\n");
}

// Yahan user se transaction input lene ka function hai.
Transaction getTransactionInput() {
    Transaction transaction;
    printf("Sender ka naam enter karein: ");
    scanf("%s", transaction.sender);
    printf("Receiver ka naam enter karein: ");
    scanf("%s", transaction.receiver);
    printf("Amount enter karein: ");
    scanf("%lf", &transaction.amount);

    return transaction;
}

int block() {
    // Blockchain ko initialize karo.
    Block blockchain[100];  // Assumed maximum of 100 blocks
    int blockchainSize = 0;

    int choice = -1;  // Initialize choice to a non-zero value to enter the loop

    while (choice != 0) {
        printf("\n1. Transaction add karein\n");
        printf("2. Blockchain display karein\n");
        printf("0. Exit\n");
        printf("Apna choice enter karein: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Transaction newTransaction = getTransactionInput();
                Block newBlock = createBlock(blockchainSize, newTransaction, blockchain[blockchainSize - 1].hash);
                addBlock(newBlock, blockchain, &blockchainSize);
                printf("Transaction blockchain mein add ho gayi hai.\n");
                break;
            }
            case 2:
                displayBlockchain(blockchain, blockchainSize);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Dobarah koshish karein.\n");
        }
    }

    return 0;
}
