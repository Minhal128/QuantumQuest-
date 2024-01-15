#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char sender[50];
    char receiver[50];
    double amount;
} Transaction;

typedef struct {
    int index;
    time_t timestamp;
    Transaction data;
    char previousHash[65];
    char hash[65];
} Block;

void calculateHash(Block *block, char *hashOutput) {
    char input[150];
    snprintf(input, sizeof(input), "%d%ld%s%s%lf", block->index, block->timestamp, block->data.sender, block->data.receiver, block->data.amount);

    unsigned long hash = 5381;
    int i = 0;

    while (input[i] != '\0') {
        hash = ((hash << 5) + hash) + input[i++];
    }

    snprintf(hashOutput, 65, "%lx", hash);
}

Block createBlock(int index, Transaction data, char *previousHash) {
    Block newBlock;
    newBlock.index = index;
    newBlock.timestamp = time(NULL);
    newBlock.data = data;
    strcpy(newBlock.previousHash, previousHash);
    calculateHash(&newBlock, newBlock.hash);
    return newBlock;
}

void addBlock(Block newBlock, Block *blockchain, int *blockchainSize) {
    blockchain[*blockchainSize] = newBlock;
    (*blockchainSize)++;
}

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

double calculateTotalAmount(Block *blockchain, int blockchainSize, const char *user) {
    double totalAmount = 0.0;

    for (int i = 0; i < blockchainSize; ++i) {
        if (strcmp(blockchain[i].data.sender, user) == 0 || strcmp(blockchain[i].data.receiver, user) == 0) {
            totalAmount += blockchain[i].data.amount;
        }
    }

    return totalAmount;
}

int block() {
    Block blockchain[100];
    int blockchainSize = 0;

    int choice = -1;

    while (choice != 0) {
        printf("\n1. Transaction add karein\n");
        printf("2. Blockchain display karein\n");
        printf("3. Calculate total transactions amount for user\n");
        printf("0. Exit\n");
        printf("Apna choice enter karein: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Transaction newTransaction = getTransactionInput();
                Block newBlock;
                if (blockchainSize == 0) {
                    // Genesis block case
                    newBlock = createBlock(0, newTransaction, "0");
                } else {
                    newBlock = createBlock(blockchainSize, newTransaction, blockchain[blockchainSize - 1].hash);
                }
                addBlock(newBlock, blockchain, &blockchainSize);
                printf("Transaction blockchain mein add ho gayi hai.\n");
                break;
            }
            case 2:
                displayBlockchain(blockchain, blockchainSize);
                break;
            case 3: {
                char userName[50];
                printf("User ka naam enter karein: ");
                scanf("%s", userName);
                double totalAmount = calculateTotalAmount(blockchain, blockchainSize, userName);
                printf("Total transactions amount for user %s: %.2lf\n", userName, totalAmount);
                break;
            }
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Dobarah koshish karein.\n");
        }
    }

    return 0;
}


    // block();
    // return 0;

