/**
 * @author      : joshuaarmainegilo (joshuaarmainegilo@$HOSTNAME)
 * @file        : main
 * @created     : Monday Oct 31, 2022 20:36:52 PST
 */

#include <stdio.h>
#include <stdbool.h>
struct user{
    int id;
    int pin;
    int balance;
};



int main()
{
    //struct user user1 = {9999, 123456}, user2 = {8888, 654321}, user3 = {7777, 987654}, user4 = {6666, 456789}, user5 = {5555, 789456}, user6 = {4444, 321987}, user7 = {3333, 147258}, user8 = {2222, 852741}, user9 = {1111, 369852}, user10 = {0000, 258963};
    struct user accounts[] = {{9999, 123456, 2000}, {8888, 654321, 1000}, {7777, 987654, 1000}, {6666, 456789, 1000}, {5555, 789456, 1000}, {4444, 321987, 1000}, {3333, 147258, 1000}, {2222, 852741, 1000}, {1111, 369852, 1000}, {0000, 258963, 1000}};
    int username;
    int pin;
    int attempts = 0;
    int withdrawal_money = 1000;
    int remaining_forex = 3000;
    while (true){
        printf("Enter your username: ");
        scanf("%d", &username);
        printf("Enter your pin: ");
        scanf("%d", &pin);
        if (attempts < 2){
            for (int i = 0; i < 10; i++){
                if (username == accounts[i].id && pin == accounts[i].pin){
                    while (true){
                        printf("Welcome %d", username);
                        int choice;
                        printf("1. Withdrawal\n");
                        printf("2. Money Transfer\n");
                        printf("3. Foreign Currency Exchange\n");
                        printf("4. Bills Payment\n");
                        printf("5. Online Shop\n");
                        printf("6. Logout\n");
                        printf("Enter your choice: ");
                        scanf("%d", &choice);
                        if (choice == 1) {
                            int withdrawal;
                            printf("Enter the amount you want to withdraw: ");
                            scanf("%d", &withdrawal);
                            if (withdrawal > withdrawal_money || withdrawal > accounts[i].balance){
                                if (withdrawal > withdrawal_money){
                                    printf("The ATM only has %d", withdrawal_money);
                                    continue;
                                }
                                else if (withdrawal > accounts[i].balance){
                                    printf("You can only withdraw up to %d", accounts[i].balance);
                                    continue;
                                }
                            }
                            else {
                                accounts[i].balance -= withdrawal;
                                withdrawal_money -= withdrawal;
                                printf("Remaining balance: %d", accounts[i].balance);
                                continue;
                            }
                        } else if (choice == 2) {
                            int transfer, account_transfer;
                            printf("Enter the account number you want to transfer: ");
                            scanf("%d", &account_transfer);
                            printf("Enter the amount you want to transfer: ");
                            scanf("%d", &transfer);
                            if (transfer > accounts[i].balance){
                                printf("You can only transfer up to %d", accounts[i].balance);
                                continue;
                            }
                            else {
                                accounts[i].balance -= transfer;
                                for (int j = 0; j < 10; j++){
                                    if (account_transfer == accounts[j].id){
                                        accounts[j].balance += transfer;
                                        printf("Remaining balance: %d", accounts[i].balance);
                                        printf("Account %d balance: %d", accounts[j].id, accounts[j].balance);
                                        continue;
                                    }
                                }
                            }
                        }
                    }
                } else if (i == 9){
                    printf("Invalid username or pin\n");
                    attempts++;
                }
            }
        } else {
            printf("Too many failed attempts");
            break;
        }
    }
    return 0;
}

