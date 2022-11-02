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

void clearTerminal(){
    system("clear");
};

void load_data(struct user *user, int *size){
    //function to load random data into struct
    struct user accounts[] = {{9999,123456,2000},{9998,123456,2000},{9997,123456,2000},{9996,123456,2000},{9995,123456,2000},{9994,123456,2000},{9993,123456,2000},{9992,123456,2000},{9991,123456,2000},{9990,123456,2000}};
    for(int i = 0; i < *size; i++){
        user[i] = accounts[i];
    }
}

void debugMode(struct user *user, int *size){
    for (int i = 0; i < *size; i++){
        printf("id: %d, pin: %d, balance: %d\n", user[i].id, user[i].pin, user[i].balance);
    }
};
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

int checkBalance(int index, struct user *user){
    // function to check balance
    return user[index].balance;
};

void transferMoney(int *index, struct user *user, int *size){
    int user1, user2, amount;
    user1 = *index;
    printf("Enter the id of the person you want to transfer money to: ");
    scanf("%d", &user2);
    printf("Enter the amount you want to transfer: ");
    scanf("%d", &amount);
    for (int i = 0; i < *size; i++){
        if (user2 == user[i].id){
            user[user1].balance -= amount;
            user[i].balance += amount;
            printf("Transfer successful\n");
        }
    }
};

void withdrawMoney(int *index, struct user *user, int * available_withdrawal){
    int amount;
    printf("Enter the amount you want to withdraw: ");
    scanf("%d", &amount);
    if (amount > *available_withdrawal || amount > user[*index].balance){
        printf("You can only withdraw %d\n", *available_withdrawal);
    } else {
        user[*index].balance -= amount;
        *available_withdrawal -= amount;
        printf("Withdrawal successful\n");
    }
};

void exchangeForex(int *index, struct user *user, int *available_forex){
    //exchange with 12% tax.
    float usd = 58.4060;
    float jpy = 0.4104;
    float gbp = 65.7418;
    float hkd = 7.4413;
    float chf = 59.7809;
    int currency;
    float amount;
    float withdrawal;
    float tax = 0.12;

    printf("1. USD\n 2. JPY\n 3. GBP\n 4. HKD\n 5. CHF\n");
    printf("Enter the currency you want to exchange: ");
    scanf("%d", &currency);
    printf("Enter the amount of the currency you'd like to withdraw: ");
    scanf("%f", &amount);
    if (currency == 1) {
        if (amount > *available_forex || amount > user[*index].balance) {
        printf("Transaction cannot proceed. Exiting...");
        getchar();
        } else {
            withdrawal = amount * usd;
            withdrawal = withdrawal - (withdrawal * tax);
            user[*index].balance -= withdrawal;
            *available_forex -= withdrawal;
            printf("Transaction successful. You have withdrawn %f USD, from %f Php.\n", withdrawal, amount);
        }
    } else if (currency == 2) {
        if (amount > *available_forex || amount > user[*index].balance) {
        printf("Transaction cannot proceed. Exiting...");
        getchar();
        } else {
            withdrawal = amount * jpy;
            withdrawal = withdrawal - (withdrawal * tax);
            user[*index].balance -= withdrawal;
            *available_forex -= withdrawal;
            printf("Transaction successful. You have withdrawn %f JPY, from %f Php.\n", withdrawal, amount);
        }
    } else if (currency == 3) {
        if (amount > *available_forex || amount > user[*index].balance) {
        printf("Transaction cannot proceed. Exiting...");
        getchar();
        } else {
            withdrawal = amount * gbp;
            withdrawal = withdrawal - (withdrawal * tax);
            user[*index].balance -= withdrawal;
            *available_forex -= withdrawal;
            printf("Transaction successful. You have withdrawn %f GBP, from %f Php.\n", withdrawal, amount);
        }
    } else if (currency == 4) {
        if (amount > *available_forex || amount > user[*index].balance) {
        printf("Transaction cannot proceed. Exiting...");
        getchar();
        } else {
            withdrawal = amount * hkd;
            withdrawal = withdrawal - (withdrawal * tax);
            user[*index].balance -= withdrawal;
            *available_forex -= withdrawal;
            printf("Transaction successful. You have withdrawn %f HKD, from %f Php.\n", withdrawal, amount);
        }
    } else if (currency == 5) {
        if (amount > *available_forex || amount > user[*index].balance) {
        printf("Transaction cannot proceed. Exiting...");
        getchar();
        } else {
            withdrawal = amount * chf;
            withdrawal = withdrawal - (withdrawal * tax);
            user[*index].balance -= withdrawal;
            *available_forex -= withdrawal;
            printf("Transaction successful. You have withdrawn %f CHF, from %f Php.\n", withdrawal, amount);
        }
    } else {
        printf("Invalid currency. Exiting...");
        getchar();
    }
};

void loggedIn(int *index, struct user *user, int *size, int * available_forex, int * available_withdrawal){
    clearTerminal();
    //print pointer index address
    debugMode(user, size);
    int id = *index;
    printf("%d", user[*index].id);
    int choice;
    printf("\n1. Withdrawal\n 2. Money Transfer\n 3. Foreign Currency Exchange\n 4. Bills Payment \n 5. Online Shop\n 6. Logout");
    scanf("%d", &choice);
    if (choice == 1){
        withdrawMoney(index, user, available_withdrawal);
    } else if (choice == 2){
        transferMoney(index, user, size);
    } else if (choice == 3) {
        exchangeForex(index, user, available_forex);
    } else if (choice == 4) {
        //bills()
    } else if (choice == 5) {
        //onlineShop()
    } else if (choice == 6){
        *index = -1;
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
            tries++;
        }
    }
    if (tries == 3){
        printf("\nYou have exceeded the number of tries. Try again later");
    }
    return -1;
};


int main()
{
    int available_forex = 3000;
    int available_withdrawal = 5000;
    int size = 10;
    struct user accounts[size];
    load_data(accounts, &size);
    debugMode(accounts, &size);
    int index = tryLogin(accounts, &size);
    while (index != -1){
        loggedIn(&index, accounts, &size, &available_forex, &available_withdrawal);
    }

    return 0;
}

