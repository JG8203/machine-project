// banking thingy. last before last rewrite xd

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 10

struct user {
    int id;
    int pin;
    float balance;
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
        printf("id: %d, pin: %d, balance: %f\n", users[i].id, users[i].pin, users[i].balance);
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
    if (tries == 3) {
        printf("You have exceeded the number of tries. Exiting...\n");
        exit(0);
    }
    return 0;
};


void logoutUser(struct user *users, int (*id)) {
    *id = -1;
    login(users, id);
};

void withdrawMoney(struct user *users, int *id, float *atm_balance, float amount) {
    if (amount > *atm_balance || amount > users[*id].balance) {
        printf("Insufficient funds. Exiting...\n");
        exit(0);
    } else {
        *atm_balance -= amount;
        users[*id].balance -= amount;
    }
};

void cashWithdrawal(struct user *users, int *id, float *atm_balance) {
    float amount;
    printf("Enter the amount you want to withdraw: ");
    scanf(" %f", &amount);
    withdrawMoney(users, id, atm_balance, amount);
};

int getExchangeRates(currency) {
    float usd = 58.4060;
    float jpy = 0.4104;
    float gbp = 65.7418;
    float hkd = 7.4413;
    float chf = 59.7809;
    switch (currency) {
        case 1:
            return usd;
        case 2:
            return jpy;
        case 3:
            return gbp;
        case 4:
            return hkd;
        case 5:
            return chf;
        default:
            return 0;
    }
};

void exchangeForex(struct user *users, int *id, float *atm_balance) {
    int currency;
    float amount;
    float withdrawal;
    float tax = 0.12;
    printf("Enter the currency you want to exchange:\n1. USD\n2. JPY\n3. GBP\n4. HKD\n5. CHF\n");
    scanf(" %d", &currency);
    printf("Enter the amount you want to exchange: ");
    scanf(" %f", &amount);
    
    withdrawal = amount * getExchangeRates(currency) * (1 + tax);
    withdrawMoney(users, id, atm_balance, withdrawal);
};

void loggedIn(struct user *users, int *id, float *withdrawal_balance, float *forex_balance) {
    printf("Welcome, user %d. You have %f in your account.\n", *id, users[*id].balance);
    int choice;
    printf("Welcome to bank!\n");
    printf("1. Withdrawal\n");
    printf("2. Money Transfer\n");
    printf("3. Foreign Currency Exchange\n");
    printf("4. Bills Payment\n");
    printf("5. Online Shop\n");
    printf("6. Logout\n");
    printf("Enter your choice: ");
    scanf(" %d", &choice);
    if (choice == 1) {
        cashWithdrawal(users, id, withdrawal_balance);
    } else if (choice == 2) {
        //moneyTransfer(users, id);
    } else if (choice == 3) {
        exchangeForex(users, id, forex_balance);
    } else if (choice == 4) {
        //billsPayment(users, id);
    } else if (choice == 5) {
        //onlineShop(users, id);
    } else if (choice == 6) {
        logoutUser(users, id);
    } else {
        printf("Invalid choice. Try again.\n");
    }

};

int main(){
    int id, atm_status = 1;
    float withdrawal_balance = 5000, forex_balance = 3000;
    struct user accounts[SIZE];
    loadUsers(accounts);
    printUsers(accounts);
    while (atm_status == 1) {
        int current_id = login(accounts, &id);
        while (current_id) {
            if (current_id != -1) {
                loggedIn(accounts, &id, &withdrawal_balance, &forex_balance);
            }
            else if (current_id == -1) {
                atm_status = 0;
            }
        }
    }
    return 0;
}
