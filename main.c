// banking thingy. last before last rewrite xd

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 10

struct user {
    int id;
    int pin;
    int balance;
};

void clearTerminal() {
    system("clear");
};

void loadUsers(struct user *users) {
    struct user accounts[]={{9999,123456,10000},{9998,123456,10000},{9997,123456,10000},{9996,123456,10000},{9995,123456,10000},{9994,123456,10000},{9993,123456,10000},{9992,123456,10000},{9991,123456,10000},{9990,123456,10000}};
    for (int i=0; i<SIZE; i++) {
        users[i]=accounts[i];
    }
};

void printUsers(struct user *users) {
    for (int i=0; i<SIZE; i++) {
        printf("id: %d, pin: %d, balance: %d\n", users[i].id, users[i].pin, users[i].balance);
    }
};

int verifyCredentials(struct user *users, int id, int pin) {
    for (int i=0; i<SIZE; i++) {
        if (users[i].id==id && users[i].pin==pin) {
            return i;
        }
    }
    return -1;
};

int login(struct user *users, int *id) {
    int scan_id, scan_pin, tries = 0;
    while (tries < 3) {
        printf("Enter your id: ");
        scanf(" %d", &scan_id);
        printf("Enter your pin: ");
        scanf(" %d", &scan_pin);
        if (verifyCredentials(users, scan_id, scan_pin) != -1) {
            *id = scan_id;
            return 1;
        } else {
            printf("Wrong credentials. Try again.\n");
            tries++;
        }
    }
    return 0;
};


void logout(struct user *users, int (*id)) {
    *id = -1;
    login(users, id);
};

void loggedIn(struct user *users, int *id) {
    int choice;
    printf("Welcome to bank!\n");
    printf("1. Check balance\n");
    printf("2. Withdraw\n");
    printf("3. Logout\n");
    printf("Enter your choice: ");
    scanf(" %d", &choice);
    if (choice == 1) {
        // checkBalance(users, *id);
    } else if (choice == 2) {
        // withdraw(users, *id);
    } else if (choice == 3) {
        logout(users, id);
    } else {
        printf("Invalid choice. Try again.\n");
    }

};


int main(){
    int id;
    struct user accounts[SIZE];
    loadUsers(accounts);
    printUsers(accounts);
    int current_id = login(accounts, &id);
    while (current_id) {
        if (current_id != -1) {
            loggedIn(accounts, &id);
        }
        else if (current_id == -1) {
            printf("You have been logged out.\n");

        }
    }
    return 0;
}
