#include <stdio.h>
#include <stdlib.h>

#define SIZE 100 // Max memory locations (m)

// Requirement: "File of Employee Records"
// We use a struct to represent a record, even if it only holds a key for now.
typedef struct
{
    int key; // 4-digit Key (K)
    char name[50];
} Employee;

// Calculate Address: H(K) = (K + i) mod m
int getHashAddress(int k, int probe)
{
    return (k + probe) % SIZE;
}

void insertRecord(Employee hashTable[SIZE])
{
    int k;
    char n[50];
    printf("\nEnter 4-digit employee key (K): ");
    scanf("%d", &k);
    printf("Enter employee name: ");
    scanf("%s", &n);

    int insFlag = 0;

    // Logic: Linear Probing
    // We attempt to place K at address H(K), then H(K)+1, etc.
    for (int probe = 0; probe < SIZE && insFlag == 0; probe++)
    {
        int address = getHashAddress(k, probe); // Calculate Address (L)

        if (hashTable[address].key == -1)
        { // If address is empty
            hashTable[address].key = k;
            insFlag = 1;
            printf("\nInsert successful. \nKey K = %d | Address L = [%d] | (Probe step: %d)\n", k, address, probe);
        }
    }

    if (insFlag == 0)
        printf("\nHash Table is full. Cannot add key %d.\n", k);
}

void deleteRecord(Employee hashTable[SIZE])
{
    int k;
    printf("\nEnter employee key to be deleted: ");
    scanf("%d", &k);

    int delFlag = 0;

    for (int probe = 0; probe < SIZE && delFlag == 0; probe++)
    {
        int address = getHashAddress(k, probe);

        if (hashTable[address].key == k)
        {
            hashTable[address].key = -1; // Mark as empty
            delFlag = 1;
            printf("\nDelete successful. Key %d removed from Address [%d].\n", k, address);
        }

        // Optimization: If we hit an empty slot (-1) that was NEVER used,
        // we could stop searching. But since -1 is used for deleted items too,
        // we must continue the probe loop in this simple implementation.
    }

    if (delFlag == 0)
        printf("\nKey %d not found in Hash Table.\n", k);
}

void displayHashTable(Employee hashTable[SIZE])
{
    printf("\n--- Hash Table (L: Address, K: Key) ---\n");
    for (int i = 0; i < SIZE; i++)
    {
        // Only print occupied slots to reduce clutter (optional)
        if (hashTable[i].key != -1)
            printf("L[%02d] : K(%d)\n", i, hashTable[i].key);
    }
    printf("---------------------------------------\n");
}

int main()
{
    Employee hashTable[SIZE];

    // Initialize table: Set all keys to -1 (indicating empty)
    for (int i = 0; i < SIZE; i++)
        hashTable[i].key = -1;

    while (1)
    {
        int input = 0;
        printf("\nOperations: \n1: Insert Record \n2: Delete Record \n3: Display Table \n0: Exit\n");
        printf("Enter choice: ");
        scanf("%d", &input);

        switch (input)
        {
        case 0:
            exit(0);
        case 1:
            insertRecord(hashTable);
            break;
        case 2:
            deleteRecord(hashTable);
            break;
        case 3:
            displayHashTable(hashTable);
            break;
        default:
            printf("\nInvalid option.\n");
            break;
        }
    }
    return 0;
}