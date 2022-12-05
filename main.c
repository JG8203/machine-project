/*


 /$$$$$$$  /$$$$$$$$  /$$$$$$  /$$$$$$$  /$$      /$$ /$$$$$$$$                           
| $$__  $$| $$_____/ /$$__  $$| $$__  $$| $$$    /$$$| $$_____/                           
| $$  \ $$| $$      | $$  \ $$| $$  \ $$| $$$$  /$$$$| $$                                 
| $$$$$$$/| $$$$$   | $$$$$$$$| $$  | $$| $$ $$/$$ $$| $$$$$                              
| $$__  $$| $$__/   | $$__  $$| $$  | $$| $$  $$$| $$| $$__/                              
| $$  \ $$| $$      | $$  | $$| $$  | $$| $$\  $ | $$| $$                                 
| $$  | $$| $$$$$$$$| $$  | $$| $$$$$$$/| $$ \/  | $$| $$$$$$$$                           
|__/  |__/|________/|__/  |__/|_______/ |__/     |__/|________/                           
                                                                                          
                                                                                          
                                                                                          
 /$$    /$$ /$$$$$$$$ /$$$$$$$  /$$     /$$                                               
| $$   | $$| $$_____/| $$__  $$|  $$   /$$/                                               
| $$   | $$| $$      | $$  \ $$ \  $$ /$$/                                                
|  $$ / $$/| $$$$$   | $$$$$$$/  \  $$$$/                                                 
 \  $$ $$/ | $$__/   | $$__  $$   \  $$/                                                  
  \  $$$/  | $$      | $$  \ $$    | $$                                                   
   \  $/   | $$$$$$$$| $$  | $$    | $$                                                   
    \_/    |________/|__/  |__/    |__/                                                   
                                                                                          
                                                                                          
                                                                                          
 /$$$$$$ /$$      /$$ /$$$$$$$   /$$$$$$  /$$$$$$$  /$$$$$$$$ /$$$$$$  /$$   /$$ /$$$$$$$$
|_  $$_/| $$$    /$$$| $$__  $$ /$$__  $$| $$__  $$|__  $$__//$$__  $$| $$$ | $$|__  $$__/
  | $$  | $$$$  /$$$$| $$  \ $$| $$  \ $$| $$  \ $$   | $$  | $$  \ $$| $$$$| $$   | $$   
  | $$  | $$ $$/$$ $$| $$$$$$$/| $$  | $$| $$$$$$$/   | $$  | $$$$$$$$| $$ $$ $$   | $$   
  | $$  | $$  $$$| $$| $$____/ | $$  | $$| $$__  $$   | $$  | $$__  $$| $$  $$$$   | $$   
  | $$  | $$\  $ | $$| $$      | $$  | $$| $$  \ $$   | $$  | $$  | $$| $$\  $$$   | $$   
 /$$$$$$| $$ \/  | $$| $$      |  $$$$$$/| $$  | $$   | $$  | $$  | $$| $$ \  $$   | $$   
|______/|__/     |__/|__/       \______/ |__/  |__/   |__/  |__/  |__/|__/  \__/   |__/   
                                                                                          
                                                                                          
                                                                                          

 
                                                                                                                                                                                                                
                                                                                                                                                                                                                
INSERT -d as a flag to the program before running to
show the debug output. This will show the values of
the variables at each step of the program.




Description: An offline banking system to be installed on various kiosks.
The system will allow customers to perform the following operations:
1. Withdraw
2. Transfer Money
3. Foreign Exchange
4. Pay Bills
5. Online Shopping
  
Programmed by: Joshua Armaine Gilo CCS-13
Last modified: 12-5-2022
Version: 0.7 (7th rewrite)
[Acknowledgements: Jonathan Leffler's padding method from https://stackoverflow.com/questions/15312482/how-to-center-text-in-c-console
GITHUB Repo: 
*/

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
    Precondtions: Assumes a UNIX-Like/MacOS or Windows terminal. Uses the macros __unix__ and _WIN32 to determine which OS is being used.
    @return none (sets the terminal to a blank screen)
*/

void clearTerminal() {
    #ifdef _WIN32
        system("cls");
    #elif __unix__
        system("clear");
    #else
        printf("Unknown OS. Cannot clear terminal.");
    #endif 
}

/* This is a function to get the current exchange rates
    Precondtions: assumes that the currency is of integer type.
    @param int currency: the currency to get the exchange rate for
    @return double: the exchange rate for the currency
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
            printf("Invalid currency. Please try again.");
            return 0;
    }
};

/* This function loads dummy data into the array
    Precondtions: Assumes that ID and PIN is an integer and balance is a double for elements {x,y,z} respectively and that the array is of size 10
    @param struct account *accounts (pointer to the struct array of accounts)
    @return none (sets the struct array to dummy data)
*/

void load_data(struct account *accounts) {
    struct account users[] = {{1800, 234567, 1000}, {6765, 123456, 1000}, {2584, 111111, 1000}, {1009, 222222, 1000}, {5555, 333333, 1000}, {4444, 444444, 1000}, {3333, 555555, 1000}, {2222, 666666, 1000}, {1111, 777777, 1000}, {8203, 888888, 1000}};
    for (int i = 0; i < SIZE; i++) {
        accounts[i] = users[i];
    }
}

/* This function prints the accounts for debugging
    Precondtions: assumes a size given by the macro SIZE. Assumes that ID and PIN is an integer and balance is a double for elements {x,y,z} respectively and that each element of the array is a struct account.
    @param struct account *accounts (pointer to the struct array of accounts)
    @return none (prints the accounts to the terminal for debugging)
*/

void setDebug(struct account *accounts) {
    for (int i = 0; i < SIZE; i++) {
        printf("ID: %d, PIN: %d, BALANCE: %2lf\n", accounts[i].id, accounts[i].pin, accounts[i].balance);
    }
}

/* This function checks whether the credentials
are valid
    Precondtions: assumes a size by the macro SIZE. Assumes that ID and PIN is an integer and balance is a double for elements {x,y,z} respectively and that each element of the array is a struct account.
    Preconditions 2: Also assumes that both id and pin are integers.
    @param struct account *accounts (pointer to the struct array of accounts)
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

/* This function gives a login form to the user
    Precondtions: assumes a size by the macro SIZE. Assumes that ID and PIN is an integer and balance is a double for elements {x,y,z} respectively and that each element of the array is a struct account.
    @param struct account *accounts (pointer to the array of accounts)
    @return index (the index of the account in the array)
*/

int displayLogin(struct account *accounts) {
    clearTerminal();
    int id, pin;
    printf("\t\t--------------------------------------------\n");
    printf("\t\t\tBank X Digital Banking System\n");
    printf("\t\t--------------------------------------------\n");
    printf("\n\t\t\t\tLOGIN\n");
    printf("\t\t\t   Enter your ID: ");
    scanf("%d", &id);
    printf("\t\t\t  Enter your PIN: ");
    scanf("%d", &pin);
    if (checkCredentials(accounts, id, pin)) {
        for (int i = 0; i < SIZE; i++) {
            if (accounts[i].id == id && accounts[i].pin == pin) {
                return i;
            }
        }
    } else {
        printf("Invalid credentials. Press [Enter] to continue.\n");
        getchar();
        getchar();
    }
    return -1;
}

/* This function determines whether the user reached the maximum number of tries
    Precondtions: assumes a size by the macro SIZE. Assumes that ID and PIN is an integer and balance is a double for elements {x,y,z} respectively and that each element of the array is a struct account.
    Preconditions 2: Also assumes that atm status is a "boolean" integer.
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
        clearTerminal();
        printf("Stolen credit card reported! ATM would now be disabled.\n");
    }
    *atm_status = 0;
    return -1;
}

/* This function is a withdrawal function used by cluster 1
    Precondtions: assumes a size of 10, assumes every element in struct is an integer except the balance which is a positive double which is a positive double which is a positive double which is a positive double.
    @param struct account *accounts
    @param int index (index of the account in accounts)
    @param int *atm_balance (atm source)
    @param int amount (amount to withdraw)
    @return none
*/

void withdrawMoney(struct account *accounts, int index, double *atm_balance, double amount) {
    if (amount > 0){
        if (amount > *atm_balance || amount > accounts[index].balance) {
            printf("Insufficient funds.\n");
        } else {
            accounts[index].balance -= amount;
            *atm_balance -= amount;
            printf("You have successfully withdrawn %lf from your account.\n", amount);
            // flushes the input buffer without complicated stuff.
        }
    } else {
        printf("Invalid amount.\n");
    }
    printf("Press [Enter] key to continue.\n");
    getchar();
    getchar();
}

/* This function is a withdrawal function.
    Precondtions: assumes a size of 10, assumes every element in struct is an integer except the balance which is a positive double which is a positive double which is a positive double which is a positive double.
    @param struct account *accounts (pointer to the array of accounts)
    @param int index (index of the account in accounts)
    @param int *atm_balance (atm source)
    @return none
*/

void withdrawal(struct account *accounts, int index, double *atm_balance) {
    clearTerminal();
    int pin;
    double amount;
    printf("Enter the amount you want to withdraw: ");
    scanf("%lf", &amount);
    printf("Enter your PIN: ");
    scanf("%d", &pin);
    if (pin == accounts[index].pin) {
        withdrawMoney(accounts, index, atm_balance, amount);
    } else {
        printf("Invalid PIN.\n");
        printf("Press [Enter] key to continue.\n");
        getchar();
        getchar();
    }
}

/* This function is a money transfer function used by cluster 2
    Precondtions: assumes a size of 10, assumes every element in struct is an integer except the balance which is a positive double which is a positive double which is a positive double which is a positive double.
    @param struct account *accounts
    @param int index (index of the account in accounts)
    @param int *atm_balance (atm source)
    @param int amount (amount to withdraw)
    @return none
*/

void transferMoney(struct account *accounts, int index) {
    clearTerminal();
    int id, pin;
    double amount;
    printf("Enter the ID of the account you want to transfer to: ");
    scanf("%d", &id);
    printf("Enter the amount you want to transfer: ");
    scanf("%lf", &amount);
    printf("Enter your PIN: ");
    scanf("%d", &pin);
    if (checkCredentials(accounts, accounts[index].id, pin)) {
        if (amount > 0) {
            if (id != accounts[index].id) {
                if (amount > accounts[index].balance) {
                    printf("Insufficient funds.\n");
                } else {
                    for (int i = 0; i < SIZE; i++) {
                        if (accounts[i].id == id) {
                            accounts[index].balance -= amount;
                            accounts[i].balance += amount;
                            printf("You have successfully transferred %lf to account %d.\n", amount, id);
                            break;
                        }
                    }
                }
            } else {
                printf("You cannot transfer to your own account.\n");
            }
        } else {
            printf("Invalid amount.\n");
        }
    } else {
        printf("Invalid credentials.\n");
    }
    printf("Press [Enter] key to continue.\n");
    getchar();
    getchar();
}

/* This function is a foreign currency exchange function used by cluster 3
    Precondtions: assumes a size of 10, assumes every element in struct is an positive integer except the balance which is a positive double which is a positive double which is a positive double which is a positive double.
    @param struct account *accounts
    @param int index (index of the account in accounts)
    @param int *atm_balance (atm source)
    @param int amount (amount to withdraw)
    @return none
*/

void exchangeForex(struct account *accounts, int index, double *atm_balance) {
    int currency, pin;
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
    printf("Enter your PIN: ");
    scanf("%d", &pin);
    if (checkCredentials(accounts, accounts[index].id, pin)){
        float exchange_rate = getExchangeRates(currency);
        if (exchange_rate == 0) {
            printf("Invalid currency.\n");
        } else {
            amount = amount * exchange_rate * (1 + tax);
            if (amount > accounts[index].balance || amount > *atm_balance) {
                printf("Insufficient funds.\n");
            } else {
                accounts[index].balance -= amount;
                *atm_balance -= amount / (1 + tax);
                printf("You have successfully converted %lf to the specified currency.\n", amount);
            }
        }
    } else {
        printf("Invalid credentials.\n");
    }
    printf("Press [Enter] key to continue.\n");
    getchar();
    getchar();
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

/* This function checks the available billers for a certain id by iterating through the various conditions then adding them to a string array.
    Preconditions: assumes a size of 10, assumes every element in struct is an integer except the balance which is a positive double which is a positive double which is a positive double which is a positive double which is a positive double. assumes that the index is a pointer to a valid integer. and that the currentBillers is a pointer to a string array.
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
        i++;
    } if (isFizzBuzz(accounts[*index].id)) { //easter egg hi
        currentBillers[i] = "Loyola Plans";
        i++;
        currentBillers[i] = "ICC-Bayantel";
        i++;
    } if (isPrime(accounts[*index].id)) {
        currentBillers[i] = "Toyota Financial Services";
        i++;
        currentBillers[i] = "Bankard/RCBC-JCB/Mastercard/Visa";
        i++;
        currentBillers[i] = "City Loft";
        i++;
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
/* A function to print available payments from a string array of billers also uses paddding to center text. Uses a ternary operator to check if the length of the string is greater than the specified width. If it is, it will print the string as is. If it is not, it will print the string with padding.
    @credits: Adaptation of Jonathan Leffler's padding method from https://stackoverflow.com/questions/15312482/how-to-center-text-in-c-console
    Precondtions: assumes input is a string array. Assumes that there is a single NULL element at the end of the array. The array must be at least 1 element long.
    @param char *currentBillers (pointer to the array of billers)
*/

void printAvailablePayments(char *currentBillers[]) {
    int i = 0;
    int width = 75;
    while (currentBillers[i] != NULL) {
        int len = strlen(currentBillers[i]) + 2;
        int pad = (len >= width) ? 0 : (width - len) / 2;

        printf("%*s[%d]%s%*s\n", pad, "", i+1, currentBillers[i], pad, "");
        i++;
    }
};

/* A generic bill function as a placeholder for the bill functions
    Precondtions: assumes that the struct account *accounts is not null and set by the macro SIZE. also assumes that the function args has the same type as the specified parameters   .
    @param char action[] (where to send the bill)
    @param int *index (index of the user account) 
    @param struct account *accounts (account pointer)
*/

void genericBill(struct account *accounts, int *index, char action[]) {
    int amount, id;
    printf("Enter the account number for %s: ", action);
    scanf("%d", &id);
    printf("Enter the amount you want to pay: ");
    scanf("%d", &amount);
    if (amount > accounts[*index].balance) {
        printf("Insufficient funds.\n");
    } else {
        accounts[*index].balance -= amount;
        printf("Payment of %d to %s successful.\n", amount, action);
    }
    printf("Press [Enter] key to continue.\n");
    // flushes the input buffer without complicated stuff.
    getchar();
    getchar();
};

/* This function checks the value of the current option or biller or action. The function genericBill is used as a placeholder for the bill functions. Improves modularity and lessens code duplication.
    Precondtions: assumes that the struct account *accounts is not null and set by the macro SIZE. also assumes that the function args has the same type as the specified parameters   .
    @param int choice (choice of biller)
    @param struct account *accounts (pointer to the array of accounts)
    @param char *currentBillers string which contains the biller chosen
    @return 0 if done. (runs the function based on which biller is chosen)
    */

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
    } return 0;
};

/* This function serves as the menu for the payBill function.
    Precondtions: assumes struct account *accounts is set by the macro SIZE, also assumes that the specified types within the function args are the same as user input.
    @param struct account *accounts (pointer to the array of accounts)
    @param int index (index of the account in accounts)
*/

void payBills(struct account *accounts, int *index, double *available_withdrawal, double *available_forex) {
    clearTerminal();
    printf("---------------------------------------------------------------------------");
    printf("\n  Bank X Digital Banking System - Remaining Balance: %.0lf PHP, %.0lf ForEx\n", *available_withdrawal, *available_forex);
    printf("---------------------------------------------------------------------------\n");
    printf("\t\t\t Bills Payment (USER: %d)\n", accounts[*index].id);
    printf("\t\t-------------------------------------------\t\n");
    char * currentBillers[14] = {};
    getAvailableBillers(accounts, index, currentBillers);
    printAvailablePayments(currentBillers);
    int choice, pin, checkBiller = 1;
    printf("Enter the number of the biller you want to pay: ");
    scanf("%d", &choice);
    printf("Enter your PIN: ");
    scanf("%d", &pin);
    if (pin != accounts[*index].pin) {
        printf("Invalid PIN.\n");
        printf("Press [Enter] key to continue.\n");
    // flushes the input buffer without complicated stuff.
        getchar();
        getchar();

    } else {
        while (checkBiller) {
            checkBiller = checkAction(accounts, index, currentBillers, choice);
        }
    }
};

/* This function gives the user various options to choose from for shopping online. Might use various APIs in the future to connect to online stores such as Lazada, Shopee, etc.
    Precondtions: assumes a size of 10, assumes every element in struct is an integer except the balance which is a positive double which is a positive double which is a positive double which is a positive double which is a positive double.
    @param struct account *accounts
    @param int index (index of the account in accounts)
    @return none
*/

void onlineShop(struct account *accounts, int *index){
    printf("Error!");
};

void loggedIn(struct account *accounts, int *index, double *available_withdrawal, double *available_forex, int isDebug) {
    clearTerminal();
    //print pointer index address
    if (isDebug == 1) {
        setDebug(accounts);
    }
    printf("---------------------------------------------------------------------------");
    printf("\n  Bank X Digital Banking System - Remaining Balance: %.0lf PHP, %.0lf ForEx\n", *available_withdrawal, *available_forex);
    printf("---------------------------------------------------------------------------");
    int choice;
    printf("\n\t\t\t    [1]Withdrawal");
    printf("\n\t\t          [2]Money Transfer");
    printf("\n\t            [3]Foreign Currency Exchange");
    printf("\n\t\t           [4]Bills Payment");
    printf("\n\t\t\t    [5]Online Shop");
    printf("\n\t\t\t      [6]Logout");
    printf("\n\n\t\t      Enter your choice: ");
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
            payBills(accounts, index, available_withdrawal, available_forex);
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

int main(int argc, char const *argv[]) {
    int atm_status = 1;
    double available_forex = 3000;
    double available_withdrawal = 5000;
    int isDebug = 0;
    struct account accounts[SIZE];
    load_data(accounts);
    if (argc > 1) {
        if (strcmp(argv[1], "-d") == 0) {
            isDebug = 1;
            setDebug(accounts);
        }
    }
    while (atm_status == 1) {
        int index = tryLogin(accounts, &atm_status);
        while (index != -1){
            loggedIn(accounts, &index, &available_withdrawal, &available_forex, isDebug); 
        }
    } return 0;
}