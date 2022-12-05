#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

struct account {
    int id;
    int pin;
    double balance;
};

/* This function clears the terminal screen
    Precondtions: Assumes a Unix/Linux terminal
    @param none
    @return none
*/

void clearTerminal() {
    #ifdef __linux__
        system("clear");
    #elif _WIN32
        system("cls");
    #endif
}

/* This function loads dummy data into the array
    Precondtions: None
    @param struct account *accounts (pointer to the array of accounts)
    @return none
*/

void load_data(struct account *accounts) {
    struct account users[] = {{9999, 234567, 1000}, {8888, 123456, 2000}, {7777, 111111, 3000}, {6666, 222222, 4000}, {5555, 333333, 5000}, {4444, 444444, 6000}, {3333, 555555, 7000}, {2222, 666666, 8000}, {1111, 777777, 9000}};
    for (int i = 0; i < SIZE; i++) {
        accounts[i] = users[i];
    }
}

/* This function prints the accounts for debugging
    Precondtions: assumes a size of 10
    @param struct account *accounts (pointer to the array of accounts)
    @return none
*/

void setDebug(struct account *accounts) {
    for (int i = 0; i < SIZE; i++) {
        printf("ID: %d, PIN: %d, BALANCE: %2lf\n", accounts[i].id, accounts[i].pin, accounts[i].balance);
    }
}

/* This function checks whether the credentials
are valid
    Precondtions: assumes a size of 10, assumes every element in struct is an integer
    @param struct account *accounts (pointer to the array of accounts)
    @param int id (the id of the input)
    @param int pin (the pin of the input)
    @return int
*/

int checkCredentials(struct account *accounts, int id, int pin) {
    for (int i = 0; i < SIZE; i++) {
        if (accounts[i].id == id && accounts[i].pin == pin) {
            return 1;
        }
    }
    return 0;
}

/* This function gives a login form 
to the user
    Precondtions: assumes a size of 10, assumes every element in struct is an integer except the balance.
    @param struct account *accounts (pointer to the array of accounts)
    @return index
*/

int displayLogin(struct account *accounts) {
    int id, pin;
    printf("Enter your ID: ");
    scanf("%d", &id);
    printf("Enter your PIN: ");
    scanf("%d", &pin);
    if (checkCredentials(accounts, id, pin)) {
        for (int i = 0; i < SIZE; i++) {
            if (accounts[i].id == id && accounts[i].pin == pin) {
                return i;
            }
        }
    } else {
        printf("Invalid credentials. Please try again.\n");
    }
    return -1;
}

/* This function determines whether the user reached the maximum number of tries
    Precondtions: assumes a size of 10, assumes every element in struct is an integer except the balance.
    @param struct account *accounts
    @param int *atm_status (pointer to the atm status)
    @return index
*/

int tryLogin(struct account *accounts, int *atm_status) {
    int index, tries = 0;
    while (tries < 3) {
        index = displayLogin(accounts);
        if (index != -1) {
            return index;
        } else {
            tries++;
        }
    } if (tries == 3) {
        printf("You have reached the maximum number of tries. Please try again later.\n");
    }
    *atm_status = 0;
    return -1;
}

/* This function is a withdrawal function used by cluster 1
    Precondtions: assumes a size of 10, assumes every element in struct is an integer except the balance.
    @param struct account *accounts
    @param int index (index of the account in accounts)
    @param int *atm_balance (atm source)
    @param int amount (amount to withdraw)
    @return none
*/

void withdrawMoney(struct account *accounts, int index, int *atm_balance, double amount) {
    if (amount > *atm_balance || amount > accounts[index].balance) {
        printf("Insufficient funds.\n");
    } else {
        accounts[index].balance -= amount;
        *atm_balance -= amount;
        printf("You have successfully withdrawn %lf from your account.\n", amount);
    }
}

/* This function is a withdrawal function.
    Precondtions: assumes a size of 10, assumes every element in struct is an integer except the balance.
    @param struct account *accounts (pointer to the array of accounts)
    @param int index (index of the account in accounts)
    @param int *atm_balance (atm source)
    @return none
*/

void withdrawal(struct account *accounts, int index, int *atm_balance) {
    double amount;
    printf("Enter the amount you want to withdraw: ");
    scanf("%lf", &amount);
    withdrawMoney(accounts, index, atm_balance, amount);
}

/* This function is a money transfer function used by cluster 2
    Precondtions: assumes a size of 10, assumes every element in struct is an integer except the balance.
    @param struct account *accounts
    @param int index (index of the account in accounts)
    @param int *atm_balance (atm source)
    @param int amount (amount to withdraw)
    @return none
*/

void transferMoney(struct account *accounts, int index) {
    int id;
    double amount;
    printf("Enter the ID of the account you want to transfer to: ");
    scanf("%d", &id);
    printf("Enter the amount you want to transfer: ");
    scanf("%lf", &amount);
    if (amount > accounts[index].balance) {
        printf("Insufficient funds.\n");
    } else {
        for (int i = 0; i < SIZE; i++) {
            if (accounts[i].id == id) {
                accounts[index].balance -= amount;
                accounts[i].balance += amount;
                printf("You have successfully transferred %lf to account %d.\n", amount, id);
                return;
            }
        }
        printf("Invalid ID.\n");
    }
}

/* This is a function to get the current exchange rates
    Precondtions: assumes a size of 10, assumes every element in struct is an integer except the balance.
    @param struct account *accounts (pointer to the array of accounts)
    @param int currency (currency to convert to)
    @return none
*/

double getExchangeRates(int currency) {
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


/* This function is a foreign currency exchange function used by cluster 3
    Precondtions: assumes a size of 10, assumes every element in struct is an integer except the balance.
    @param struct account *accounts
    @param int index (index of the account in accounts)
    @param int *atm_balance (atm source)
    @param int amount (amount to withdraw)
    @return none
*/

void exchangeForex(struct account *accounts, int index, int *atm_balance) {
    int currency;
    double amount, tax = 0.12;
    printf("Enter the currency you want to convert to: \n");
    printf("1. USD\n");
    printf("2. JPY\n");
    printf("3. GBP\n");
    printf("4. HKD\n");
    printf("5. CHF\n");
    scanf("%d", &currency);
    printf("Enter the amount you want to convert: ");
    scanf("%lf", &amount);
    float exchange_rate = getExchangeRates(currency);
    if (exchange_rate == 0) {
        printf("Invalid currency.\n");
    } else {
        amount = amount * exchange_rate * (1 + tax);
        withdrawMoney(accounts, index, atm_balance, amount);
    }
}

/* This function is a function which checks if an integer is prime
    Precondtions: assumes input is an integer
    @param int id (number to check)
    @return true or false (boolean) 
*/

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

/* This function is a function which checks if an integer is part of the fibonacci sequence
    Precondtions: assumes input is an integer
    @param int id (number to check)
    @return true or false (boolean) 
*/

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

/* This function is a function which checks if an integer is divisible by 3 and 5
    Precondtions: assumes input is an integer
    @param int id (number to check)
    @return true or false (boolean) 
*/

int isFizzBuzz(int id){ //easter egg lol
    // function to check if id is fizzbuzz
    if (id % 3 == 0 && id % 5 == 0){
        return 1;
    } else {
        return 0;
    }
};

/* This function is a function which checks the available billers for a certain id. 
    Precondtions: assumes input is an integer
    @param struct account *accounts (pointer to the array of accounts)
    @param int index (index of the account in accounts)
    @param char *currentBillers (pointer to the array of billers)
*/

void getAvailableBillers(struct account *accounts, int *index, char *currentBillers[]) {
    int i = 0;
    if (1){
        currentBillers[i] = "Cebu Pacific";
        i++;
        currentBillers[i] = "Philcare (Philhealthcare Inc.)";
        i++;
        currentBillers[i] = "Paramount Life";
    } if (isFizzBuzz(accounts[*index].id)) {
        currentBillers[i] = "Loyola Plans";
        i++;
        currentBillers[i] = "ICC-Bayantel";
    } if (isPrime(accounts[*index].id)) {
        currentBillers[i] = "Toyota Financial Services";
        i++;
        currentBillers[i] = "Bankard/RCBC-JCB/Mastercard/Visa";
        i++;
        currentBillers[i] = "City Loft";
    } if ((accounts[*index].id) % 4 == 0) {
        currentBillers[i] = "Unionbank Credit Cards";
        i++;
        currentBillers[i] = "Unistar";
        i++;
    } if (isFibonacci(accounts[*index].id)){
        currentBillers[i] = "HSBC Personal Loans";
        i++;
        currentBillers[i] = "Easytrip";
        i++;
        currentBillers[i] = "PSBank Loans";
        i++;
        currentBillers[i] = "PLDT";
        i++;
    } if (1) {
        currentBillers[i] = "Back";
        i++;
    }
}
/* A function to print available payments from a string array of billers
    Precondtions: assumes input is a string array
    @param char *currentBillers (pointer to the array of billers)
*/

void printAvailablePayments(char *currentBillers[]) {
    int i = 0;
    while (currentBillers[i] != NULL){
        printf("[%d]. %s\n", i+1, currentBillers[i]);
        i++;
    }
};

/* A generic bill function
    @param char action[] (where to send the bill)
    @param int *index (index of the user account) 
    @param struct account *accounts (account pointer)
*/

void genericBill(struct account *accounts, int *index, char action[]) {
    int amount, id;
    printf("Enter the account number of %s", action);
    scanf("%d", &id);
    printf("Enter the amount you want to pay: ");
    scanf("%d", &amount);
    if (amount > accounts[*index].balance) {
        printf("Insufficient funds.\n");
    } else {
        accounts[*index].balance -= amount;
        printf("Payment of %d to %s successful.\n", amount, action);
    }
};

/* This function checks the value of the current option or biller or action
    @param int choice (choice of biller)
    @param struct account *accounts (pointer to the array of accounts)
    @param char *currentBillers string which contains the biller chosen*/

int checkAction(struct account *accounts, int *index, char *currentBillers[], int choice) {
    //check action based on the options within the array
    char action[50];
    strcpy(action, currentBillers[choice-1]);
    if (strcmp(action, "Cebu Pacific") == 0){
        genericBill(accounts, index, action);
    } else if (strcmp(action, "Philcare (Philhealthcare Inc.)") == 0){
        genericBill(accounts, index, action);
    } else if (strcmp(action, "Paramount Life") == 0){
        genericBill(accounts, index, action);
    } else if (strcmp(action, "Loyola Plans") == 0){
        genericBill(accounts, index, action);
    } else if (strcmp(action, "ICC-Bayantel") == 0){
        genericBill(accounts, index, action);
    } else if (strcmp(action, "Toyota Financial Services") == 0){
        genericBill(accounts, index, action);
    } else if (strcmp(action, "Bankard/RCBC-JCB/Mastercard/Visa") == 0){
        genericBill(accounts, index, action);
    } else if (strcmp(action, "City Loft") == 0){
        genericBill(accounts, index, action);
    } else if (strcmp(action, "Unionbank Credit Cards") == 0){
        genericBill(accounts, index, action);
    } else if (strcmp(action, "Unistar") == 0){
        genericBill(accounts, index, action);
    } else if (strcmp(action, "HSBC Personal Loans") == 0){
        genericBill(accounts, index, action);
    } else if (strcmp(action, "Easytrip") == 0){
        genericBill(accounts, index, action);
    } else if (strcmp(action, "PSBank Loans") == 0){
        genericBill(accounts, index, action);
    } else if (strcmp(action, "PLDT") == 0){
        genericBill(accounts, index, action);
    } else if (strcmp(action, "Back") == 0){
        return 0;
    } else {
        printf("Invalid choice.\n");
    } return 1;
};

/* This function serves as the menu for the payBill function.\n
    Precondtions: assumes input is an integer
    @param struct account *accounts (pointer to the array of accounts)
    @param int index (index of the account in accounts)
*/

void payBills(struct account *accounts, int *index){
    char * currentBillers[14] = {};
    getAvailableBillers(accounts, index, currentBillers);
    printAvailablePayments(currentBillers);
    int choice, checkBiller = 1;
    printf("Enter the number of the biller you want to pay: ");
    scanf("%d", &choice);
    while (checkBiller != 0){
        checkBiller = checkAction(accounts, index, currentBillers, choice);
    }
};

/* This function gives the user various options to choose from
    Precondtions: assumes a size of 10, assumes every element in struct is an integer except the balance.
    @param struct account *accounts
    @param int index (index of the account in accounts)
    @return none
*/

void onlineShop(struct account *accounts, int *index){
    printf("Coming soon!");
};

void loggedIn(struct account *accounts, int *index, int *available_withdrawal, int *available_forex) {
    clearTerminal();
    //print pointer index address
    setDebug(accounts);
    printf("%d", accounts[*index].id);
    int choice;
    printf("\n1. Withdrawal\n 2. Money Transfer\n 3. Foreign Currency Exchange\n 4. Bills Payment \n 5. Online Shop\n 6. Logout");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            withdrawal(accounts, *index, available_withdrawal);
            break;
        case 2:
            transferMoney(accounts, *index);
            break;
        case 3:
            exchangeForex(accounts, *index, available_forex);
            break;
        case 4:
            payBills(accounts, index);
            break;
        case 5:
            onlineShop(accounts, index);
            break;
        case 6:
            *index = -1;
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}

int main() {
    int atm_status = 1;
    int available_forex = 5000;
    int available_withdrawal = 3000;
    struct account accounts[SIZE];
    load_data(accounts);
    setDebug(accounts);
    while (atm_status == 1) {
        int index = tryLogin(accounts, &atm_status);
        while (index != -1){
            loggedIn(accounts, &index, &available_withdrawal, &available_forex); 
        }
    }
}