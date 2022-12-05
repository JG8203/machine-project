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
    struct user accounts[] = {{60,123456,2000},{9998,123456,2000},{9997,123456,2000},{9996,123456,2000},{9995,123456,2000},{9994,123456,2000},{9993,123456,2000},{9992,123456,2000},{9991,123456,2000},{9990,123456,2000}};
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

int isPrime(int id){
    // function to check if id is prime
    int i, flag = 0;
    for(i = 2; i <= id/2; ++i){
        if(id % i == 0){
            flag = 1;
            break;
        }
    }
    if (flag == 0){
        return 1;
    } else {
        return 0;
    }
};

int isFibonacci(int id){
    // function to check if id is fibonacci
    int first = 0, second = 1, next, c;
    for (c = 0; c <= id; c++){
        if (first == id){
            return 1;
        }
        next = first + second;
        first = second;
        second = next;
    }
    return 0;
};



void getAvailablePayments(int *index, struct user * user, char *options[]){
/* payments to Loyola Plans and ICC-Bayantel are available if user id is divisible by 15
     Toyota Financial Services, Bankard/RCBC-JCB/Mastercard/Visa, and City Loft: User IDs that are prime numbers
    ○ Unionbank Credit Cards and Unistar: User IDs that are composite and divisible by 4 ○ HSBC Personal Loans, Easytrip, PSBank Loans, and PLDT: Numbers included in the Fibonacci sequence (0,1,1,2,3,5,8,13,21, …)

○ Cebu Pacific, Philcare (Philhealthcare Inc.) and Paramount Life: Available for all users
*/
    int id = user[*index].id;
    int i = 0;
    if (1==1){
        options[i] = "Cebu Pacific";
        i++;
        options[i] = "Philcare (Philhealthcare Inc.)";
        i++;
        options[i] = "Paramount Life";
    }
    if (id % 15 == 0){
        options[i] = "Loyola Plans";
        i++;
        options[i] = "ICC-Bayantel";
        i++;
    }
    if (isPrime(id)){
        options[i] = "Toyota Financial Services";
        i++;
        options[i] = "Bankard/RCBC-JCB/Mastercard/Visa";
        i++;
        options[i] = "City Loft";
        i++;
    }
    if (id % 4 == 0){
        options[i] = "Unionbank Credit Cards";
        i++;
        options[i] = "Unistar";
        i++;
    }
    if (isFibonacci(id)){
        options[i] = "HSBC Personal Loans";
        i++;
        options[i] = "Easytrip";
        i++;
        options[i] = "PSBank Loans";
        i++;
        options[i] = "PLDT";
        i++;
    }

};

void printAvailablePayments(char *options[]){
    int choice;
    int i = 0;
    while (options[i] != NULL){
        printf("[%d]. %s\n", i+1, options[i]);
        i++;
    }
};

void genericBill(char action[], int *index, struct user * user){
    float amount;
    printf("Enter the amount of the bill: ");
    scanf("%f", &amount);
    if (amount > user[*index].balance){
        printf("Transaction cannot proceed. Exiting...");
        getchar();
    } else {
        user[*index].balance -= amount;
        printf("Transaction to %s successful. You have withdrawn %f Php.\n", action, amount);
    }
};

void checkAction(int choice, char *options[], int * index, struct user *user, int size){
    //check action based on the options within the array
    char action[50];
    strcpy(action, options[choice-1]);
    if (strcmp(action, "Cebu Pacific") == 0){
        genericBill(action, index, user);
    } else if (strcmp(action, "Philcare (Philhealthcare Inc.)") == 0){
        printf("Philcare (Philhealthcare Inc.)");
    } else if (strcmp(action, "Paramount Life") == 0){
        printf("Paramount Life");
    } else if (strcmp(action, "Loyola Plans") == 0){
        printf("Loyola Plans");
    } else if (strcmp(action, "ICC-Bayantel") == 0){
        printf("ICC-Bayantel");
    } else if (strcmp(action, "Toyota Financial Services") == 0){
        printf("Toyota Financial Services");
    } else if (strcmp(action, "Bankard/RCBC-JCB/Mastercard/Visa") == 0){
        printf("Bankard/RCBC-JCB/Mastercard/Visa");
    } else if (strcmp(action, "City Loft") == 0){
        printf("City Loft");
    } else if (strcmp(action, "Unionbank Credit Cards") == 0){
        printf("Unionbank Credit Cards");
    } else if (strcmp(action, "Unistar") == 0){
        printf("Unistar");
    } else if (strcmp(action, "HSBC Personal Loans") == 0){
        printf("HSBC Personal Loans");
    } else if (strcmp(action, "Easytrip") == 0){
        printf("Easytrip");
    } else if (strcmp(action, "PSBank Loans") == 0){
        printf("PSBank Loans");
    } else if (strcmp(action, "PLDT") == 0){
        printf("PLDT");
    } else {
        printf("Invalid choice. Exiting...");
        getchar();
    }
};

void payBills(int *index, struct user *user, int size){
    char * billers[14] = {};
    getAvailablePayments(index, user, billers);
    printAvailablePayments(billers);
    int choice;
    printf("Enter the number of the biller you'd like to pay: ");
    scanf("%d", &choice);
    checkAction(choice, billers, index, user, size);
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
        payBills(index, user, *size);
    } else if (choice == 5) {
        //onlineShop()
    } else if (choice == 6){
        *index = -1;
    }
};

int tryLogin(struct user *user, int *size, int *atm_status){
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
        printf("\nStolen credit card reported! ATM is now disabled.");
    }
    *atm_status = 0;
    return -1;
};


int main()
{
    int available_forex = 5000;
    int available_withdrawal = 3000;
    int atm_status = 1;
    const int size = 10;
    struct user accounts[size];
    load_data(accounts, &size);
    debugMode(accounts, &size);
    while (atm_status == 1){
        int index = tryLogin(accounts, &size, &atm_status);
        while (index != -1){
            printf("atm_status: %d", atm_status);
            loggedIn(&index, accounts, &size, &available_forex, &available_withdrawal);
        }
    }
    return 0;
}

