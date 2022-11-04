/**
 * @author      : joshuaarmainegilo (joshuaarmainegilo@$HOSTNAME)
 * @file        : login
 * @created     : Friday Nov 04, 2022 11:54:51 PST
 */
#include <stdio.h>
#include <stdlib.h>

void writeAccounts(int * id1,
 int * pin1,
 int * balance1,
 int * id2,
 int * pin2,
 int * balance2,
 int * id3,
 int * pin3,
 int * balance3,
 int * id4,
 int * pin4,
 int * balance4,
 int * id5,
 int * pin5,
 int * balance5,
 int * id6,
 int * pin6,
 int * balance6,
 int * id7,
 int * pin7,
 int * balance7,
 int * id8,
 int * pin8,
 int * balance8,
 int * id9,
 int * pin9,
 int * balance9,
 int * id10,
 int * pin10,
 int * balance10) {
    *id1 = 1234;
    *pin1 = 123456;
    *balance1 = 2000;
    *id2 = 2345;
    *pin2 = 234567;
    *balance2 = 3000;
    *id3 = 3456;
    *pin3 = 345678;
    *balance3 = 4000;
    *id4 = 4567;
    *pin4 = 456789;
    *balance4 = 5000;
    *id5 = 5678;
    *pin5 = 567890;
    *balance5 = 6000;
    *id6 = 6789;
    *pin6 = 678901;
    *balance6 = 7000;
    *id7 = 7890;
    *pin7 = 789012;
    *balance7 = 8000;
    *id8 = 8901;
    *pin8 = 890123;
    *balance8 = 9000;
    *id9 = 9012;
    *pin9 = 901234;
    *balance9 = 10000;
    *id10 = 123;
    *pin10 = 12345;
    *balance10 = 11000;
}


void login(int * id1,
 int * pin1,
 int * balance1,
 int * id2,
 int * pin2,
 int * balance2,
 int * id3,
 int * pin3,
 int * balance3,
 int * id4,
 int * pin4,
 int * balance4,
 int * id5,
 int * pin5,
 int * balance5,
 int * id6,
 int * pin6,
 int * balance6,
 int * id7,
 int * pin7,
 int * balance7,
 int * id8,
 int * pin8,
 int * balance8,
 int * id9,
 int * pin9,
 int * balance9,
 int * id10,
 int * pin10,
 int * balance10,
 int * current_id,
 int * current_balance) {
    int id, pin, i;
    printf("Enter your ID: ");
    scanf("%d", &id);
    printf("Enter your PIN: ");
    scanf("%d", &pin);
    if (id == *id1 && pin == *pin1) {
        printf("Welcome %d", *id1);
        *current_id = *id1;
        *current_balance = *balance1;
    } else if (id == *id2 && pin == *pin2) {
        printf("Welcome %d", *id2);
        *current_id = *id2;
        *current_balance = *balance2;
    } else if (id == *id3 && pin == *pin3) {
        printf("Welcome %d", *id3);
        *current_id = *id3;
        *current_balance = *balance3;
    } else if (id == *id4 && pin == *pin4) {
        printf("Welcome %d", *id4);
        *current_id = *id4;
        *current_balance = *balance4;
    } else if (id == *id5 && pin == *pin5) {
        printf("Welcome %d", *id5);
        *current_id = *id5;
        *current_balance = *balance5;
    } else if (id == *id6 && pin == *pin6) {
        printf("Welcome %d", *id6);
        *current_id = *id6;
        *current_balance = *balance6;
    } else if (id == *id7 && pin == *pin7) {
        printf("Welcome %d", *id7);
        *current_id = *id7;
        *current_balance = *balance7;
    } else if (id == *id8 && pin == *pin8) {
        printf("Welcome %d", *id8);
        *current_id = *id8;
        *current_balance = *balance8;
    } else if (id == *id9 && pin == *pin9) {
        printf("Welcome %d", *id9);
        *current_id = *id9;
        *current_balance = *balance9;
    } else if (id == *id10 && pin == *pin10) {
        printf("Welcome %d", *id10);
        *current_id = *id10;
        *current_balance = *balance10;
    } else {
        printf("Invalid ID or PIN");
        *current_id = -1;
    }
}

void withdrawal(int * current_id, int * current_balance, int * available_withdrawal , int * id1, int * balance1, int * id2, int * balance2, int * id3, int * balance3, int * id4, int * balance4, int * id5, int * balance5, int * id6, int * balance6, int * id7, int * balance7, int * id8, int * balance8, int * id9, int * balance9, int * id10, int * balance10) {
    int amount;
    printf("Enter amount to withdraw: ");
    scanf("%d", &amount);
    if (amount > *available_withdrawal || amount > *current_balance) {
        printf("Insufficient funds");
    } else {
        *available_withdrawal -= amount;
        *current_balance -= amount;
        if (*current_id == *id1) {
            *balance1 = *current_balance;
        } else if (*current_id == *id2) {
            *balance2 = *current_balance;
        } else if (*current_id == *id3) {
            *balance3 = *current_balance;
        } else if (*current_id == *id4) {
            *balance4 = *current_balance;
        } else if (*current_id == *id5) {
            *balance5 = *current_balance;
        } else if (*current_id == *id6) {
            *balance6 = *current_balance;
        } else if (*current_id == *id7) {
            *balance7 = *current_balance;
        } else if (*current_id == *id8) {
            *balance8 = *current_balance;
        } else if (*current_id == *id9) {
            *balance9 = *current_balance;
        } else if (*current_id == *id10) {
            *balance10 = *current_balance;
        }
    }
}

void moneyTransfer(int * current_id,
 int * current_balance,
 int * id1,
 int * balance1,
 int * id2,
 int * balance2,
 int * id3,
 int * balance3,
 int * id4,
 int * balance4,
 int * id5,
 int * balance5,
 int * id6,
 int * balance6,
 int * id7,
 int * balance7,
 int * id8,
 int * balance8,
 int * id9,
 int * balance9,
 int * id10,
 int * balance10) {
    int amount, id;
    printf("Enter amount to transfer: ");
    scanf("%d", &amount);
    printf("Enter ID to transfer to: ");
    scanf("%d", &id);
    if (amount > *current_balance) {
        printf("Insufficient balance");
    } else {
        if (id == *id1) {
            *balance1 += amount;
            *current_balance -= amount;
            printf("Transfer successful");
        } else if (id == *id2) {
            *balance2 += amount;
            *current_balance -= amount;
            printf("Transfer successful");
        } else if (id == *id3) {
            *balance3 += amount;
            *current_balance -= amount;
            printf("Transfer successful");
        } else if (id == *id4) {
            *balance4 += amount;
            *current_balance -= amount;
            printf("Transfer successful");
        } else if (id == *id5) {
            *balance5 += amount;
            *current_balance -= amount;
            printf("Transfer successful");
        } else if (id == *id6) {
            *balance6 += amount;
            *current_balance -= amount;
            printf("Transfer successful");
        } else if (id == *id7) {
            *balance7 += amount;
            *current_balance -= amount;
            printf("Transfer successful");
        } else if (id == *id8) {
            *balance8 += amount;
            *current_balance -= amount;
            printf("Transfer successful");
        } else if (id == *id9) {
            *balance9 += amount;
            *current_balance -= amount;
            printf("Transfer successful");
        } else if (id == *id10) {
            *balance10 += amount;
            *current_balance -= amount;
            printf("Transfer successful");
        } else {
            printf("Invalid ID");
        }
    }
}

void showDebug(int * id1, int * balance1, int * id2, int * balance2, int * id3, int * balance3, int * id4, int * balance4, int * id5, int * balance5, int * id6, int * balance6, int * id7, int * balance7, int * id8, int * balance8, int * id9, int * balance9, int * id10, int * balance10) {
    printf("\nID: %d Balance: %d\n", *id1, *balance1);
    printf("ID: %d Balance: %d\n", *id2, *balance2);
    printf("ID: %d Balance: %d\n", *id3, *balance3);
    printf("ID: %d Balance: %d\n", *id4, *balance4);
    printf("ID: %d Balance: %d\n", *id5, *balance5);
    printf("ID: %d Balance: %d\n", *id6, *balance6);
    printf("ID: %d Balance: %d\n", *id7, *balance7);
    printf("ID: %d Balance: %d\n", *id8, *balance8);
    printf("ID: %d Balance: %d\n", *id9, *balance9);
    printf("ID: %d Balance: %d\n", *id10, *balance10);
}

void loggedIn(int * current_id,
 int * current_balance,
 int * available_withdrawal,
 int * available_forex,
 int * id1,
 int * balance1,
 int * id2,
 int * balance2,
 int * id3,
 int * balance3,
 int * id4,
 int * balance4,
 int * id5,
 int * balance5,
 int * id6,
 int * balance6,
 int * id7,
 int * balance7,
 int * id8,
 int * balance8,
 int * id9,
 int * balance9,
 int * id10,
 int * balance10) {
        int choice;
        showDebug(id1, balance1, id2, balance2, id3, balance3, id4, balance4, id5, balance5, id6, balance6, id7, balance7, id8, balance8, id9, balance9, id10, balance10);
        printf("Welcome to the ATM %d. What would you like to do?\n ", *current_id);
        printf("1. Withdrawal\n");
        printf("2. Money Transfer\n");
        printf("3. Foreign Currency Exchange\n");
        printf("4. Bills Payment\n");
        printf("5. Online Shop\n");
        printf("6. Logout \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
               withdrawal(current_id, current_balance, available_withdrawal, id1, balance1, id2, balance2, id3, balance3, id4, balance4, id5, balance5, id6, balance6, id7, balance7, id8, balance8, id9, balance9, id10, balance10);
                break;
            case 2:
                moneyTransfer(current_id, current_balance, id1, balance1, id2, balance2, id3, balance3, id4, balance4, id5, balance5, id6, balance6, id7, balance7, id8, balance8, id9, balance9, id10, balance10);
                break;
            case 3:
                //forex(current_balance, available_forex);
                break;
            case 4:
                //billsPayment(current_balance);
                break;
            case 5:
                //onlineShop(current_balance);
                break;
            case 6:
                *current_id = -1;
                break;
            default:
                printf("Invalid choice");
                break;
        }
}

int main(){
    //login system without using ints
    //10 accounts
    int available_withdrawal = 3000;
    int available_forex = 5000;
    int current_id;
    int current_balance;
    int id1;
    int pin1;
    int balance1;
    int id2;
    int pin2;
    int balance2;
    int id3;
    int pin3;
    int balance3;
    int id4;
    int pin4;
    int balance4;
    int id5;
    int pin5;
    int balance5;
    int id6;
    int pin6;
    int balance6;
    int id7;
    int pin7;
    int balance7;
    int id8;
    int pin8;
    int balance8;
    int id9;
    int pin9;
    int balance9;
    int id10;
    int pin10;
    int balance10;

    writeAccounts(&id1, &pin1, &balance1, &id2, &pin2, &balance2, &id3, &pin3, &balance3, &id4, &pin4, &balance4, &id5, &pin5, &balance5, &id6, &pin6, &balance6, &id7, &pin7, &balance7, &id8, &pin8, &balance8, &id9, &pin9, &balance9, &id10, &pin10, &balance10);

   login(&id1, &pin1, &balance1, &id2, &pin2, &balance2, &id3, &pin3, &balance3, &id4, &pin4, &balance4, &id5, &pin5, &balance5, &id6, &pin6, &balance6, &id7, &pin7, &balance7, &id8, &pin8, &balance8, &id9, &pin9, &balance9, &id10, &pin10, &balance10, &current_id, &current_balance);


   while (current_id != -1) {
        loggedIn(&current_id, &current_balance, &available_withdrawal, &available_forex, &id1, &balance1, &id2, &balance2, &id3, &balance3, &id4, &balance4, &id5, &balance5, &id6, &balance6, &id7, &balance7, &id8, &balance8, &id9, &balance9, &id10, &balance10);
   }
    return 0;
}

