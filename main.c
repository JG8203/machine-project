/**
 * @author      : joshuaarmainegilo (joshuaarmainegilo@$HOSTNAME)
 * @file        : main
 * @created     : Tuesday Nov 01, 2022 22:45:00 PST
 */
// a modular banking system which implements functions.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

// function prototypes
// function to load accounts from struct
// function to save accounts details to struct
// functions to transfer money
// function to check balance
struct user {
    int id;
    int pin;
    int balance;
};

void load_data(struct user *user, int *size){
    //function to load random data into struct
    struct user accounts[] = {{9999,123456,2000},{9998,123456,2000},{9997,123456,2000},{9996,123456,2000},{9995,123456,2000},{9994,123456,2000},{9993,123456,2000},{9992,123456,2000},{9991,123456,2000},{9990,123456,2000}};
    *size = sizeof(accounts)/sizeof(accounts[0]);
    for(int i = 0; i < *size; i++){
        user[i] = accounts[i];
    }
}

int credentialsCheck(int id, int pin,struct user *user, int *size){
    // function to check credentials
    for (int i = 0; i < *size; i++){
        if (id == user[i].id && pin == user[i].pin){
            return i;
        }
    }
    return -1;
};

int loginForm(struct user *user, int *size){
    int id, pin, tries = 0;
    // limit attempts to 3 tries.
    printf("Enter your id: ");
    scanf("%d", &id);
    printf("Enter your pin: ");
    scanf("%d", &pin);
    return credentialsCheck(id, pin, user, size);
};

void loggedIn(int index, struct user *user, int *size){
    // function to display menu
    int choice;
    printf("1. Check Balance\n 2. Transfer Money\n 3. Exit");
    scanf("%d", &choice);
    switch (choice){
        case 1:
            printf("Your balance is %d", user[index].balance);
            break;
        case 2:
            //transferMoney(index, user, size);
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid choice");
            break;
    }
};

int tryLogin(struct user *user, int *size){
    int id, pin, tries = 0;
    // limit attempts to 3 tries.
    while (tries < 3){
        int index = loginForm(user, size);
        if (index != -1){
            printf("Login successful");
            return index;
        }
        else{
            printf("Login failed. Try again");
            tries++;
        }
    }
    if (tries == 3){
        printf("You have exceeded the number of tries. Try again later");
    }
    return -1;
};

void printAllCredentials(struct user *user, int *size){
    for (int i = 0; i < *size; i++){
        printf("id: %d, pin: %d, balance: %d", user[i].id, user[i].pin, user[i].balance);
    }
};

int main()
{

    int size = 10;
    struct user accounts[size];
    load_data(accounts, &size);
    printAllCredentials(accounts, &size);
    int index = tryLogin(accounts, &size);
    while (index != -1){
        loggedIn(index, accounts, &size);
    }

    return 0;
}

