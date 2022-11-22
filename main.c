xdddd // banking thingy. last before last rewrite xd

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

int main(){
    int id;
    struct user accounts[SIZE];
    loadUsers(accounts);
    printUsers(accounts);
    if (login(accounts, &id)) {
        printf("Logged in as %d", id);
    } else {
        printf("Too many tries. Exiting.");
    }
    return 0;
}
