/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "bank.h"
#include <stdio.h>

int process, operation;
int accountID;

void bank_prog_1(char *host) {
    CLIENT *clnt;
    int  *result_1;
    int  openaccount_1_arg;
    int  *result_2;
    int  closeaccount_1_arg;
    int  *result_3;
    int  authaccount_1_arg;
    int  *result_4;
    aux_struct  deposit_1_arg;
    int  *result_5;
    aux_struct  withdraw_1_arg;
    float  *result_6;
    int  checkbalance_1_arg;

    process = 0;
    operation = 0;

#ifndef DEBUG
    clnt = clnt_create (host, BANK_PROG, BANK_VERS, "udp");
    if (clnt == NULL) {
        clnt_pcreateerror (host);
        exit (1);
    }
#endif  /* DEBUG */

    while(1) {
        printf("\nInform which process to access:\n");
        printf(" 1 - Agency\n");
        printf(" 2 - ATM Machine\n");
        scanf("%d", &process);

        switch (process) {
            // Administration
            case 1:
                printf("\nSelect an Agency operation:\n");
                printf(" 1 - Open an Account\n");
                printf(" 2 - Close an Account\n");
                printf(" 3 - Authenticate an Account\n");
                printf(" 4 - Withdraw money from Account\n");
                printf(" 5 - Deposit money into Account\n");
                printf(" 6 - Statement from Account\n");
                scanf("%d", &operation);
                switch (operation) {
                    // Open Account
                    case 1:
                        printf("\nTo open an account, please enter an ID: ");
                        scanf("%d", &openaccount_1_arg);
                        result_1 = openaccount_1(&openaccount_1_arg, clnt);
                        if (result_1 == (int *) NULL) {
                            clnt_perror (clnt, "call failed");
                        }
                        else { // CALL SUCCESSFULL
                            if (*result_1 == -1) {
                                printf("Account %d was not created - it already exists.\n", openaccount_1_arg);
                            }
                            else {
                                printf("Account %d was created.\n", openaccount_1_arg);
                            }
                        }
                        break;
                    // Close Account
                    case 2:
                        printf("\nTo close an account, please enter an ID: ");
                        scanf("%d", &closeaccount_1_arg);
                        result_2 = closeaccount_1(&closeaccount_1_arg, clnt);
                        if (result_2 == (int *) NULL) {
                            clnt_perror (clnt, "call failed");
                        }
                        else { // CALL SUCCESSFULL
                            if (*result_2 == 0) {
                                printf("Account %d was closed.\n", closeaccount_1_arg);
                            }
                            else {
                                printf("Account %d was not closed - it does not exist.\n", closeaccount_1_arg);
                            }
                        }
                        break;
                    // Authenticate Account
                    case 3:
                        printf("\nTo authenticate an account, please enter an ID: ");
                        scanf("%d", &authaccount_1_arg);

                        result_3 = authaccount_1(&authaccount_1_arg, clnt);
                        if (result_3 == (int *) NULL) {
                            clnt_perror (clnt, "call failed");
                        }
                        else { // CALL SUCCESSFULL
                            if (*result_3 == -1) {
                                printf("Account %d was authenticated.\n", authaccount_1_arg);
                            }
                            else {
                                printf("Account %d was not authenticated.\n", authaccount_1_arg);
                            }
                        }
                        break;
                    case 4:
                        printf("\nTo withdraw from an account, plese enter the ID and the amount: ");
                        scanf("%d %f", &withdraw_1_arg.id, &withdraw_1_arg.sum);

                        result_4 = withdraw_1(&withdraw_1_arg, clnt);
                        if (result_4 == (int *) NULL) {
                            clnt_perror (clnt, "call failed");
                        }
                        else { // CALL SUCCESSFULL
                            if (*result_5 == 0) {
                                printf("The amount of %f was withdrawn from the account %d.\n", withdraw_1_arg.sum, withdraw_1_arg.id);
                            }
                            else {
                                printf("ERROR! The amount of %f was NOT taken from account %d.\n", withdraw_1_arg.sum, withdraw_1_arg.id);
                            }
                        }
                        break;
                    case 5:
                        printf("\nTo deposit into an account, plese enter the ID and the amount: ");
                        scanf("%d %f", &deposit_1_arg.id, &deposit_1_arg.sum);

                        result_5 = deposit_1(&deposit_1_arg, clnt);
                        if (result_5 == (int *) NULL) {
                            clnt_perror (clnt, "call failed");
                        }
                        else { // CALL SUCCESSFULL
                            if (*result_5 == 0) {
                                printf("The amount of %f was added to account %d.\n", deposit_1_arg.sum, deposit_1_arg.id);
                            }
                            else {
                                printf("ERROR! The amount of %f was NOT added to account %d.\n", deposit_1_arg.sum, deposit_1_arg.id);
                            }
                        }
                        break;
                    case 6:
                        printf("\nEnter the ID of the account to check its balance: ");
                        scanf("%d", &checkbalance_1_arg);

                        result_6 = checkbalance_1(&checkbalance_1_arg, clnt);
                        if (result_6 == (float *) NULL) {
                            clnt_perror (clnt, "call failed");
                        }
                        else { // CALL SUCCESSFULL
                            if (*result_6 != -9999) {
                                printf("Account %d has a balance of %f.\n", checkbalance_1_arg, *result_6);
                            }
                            else {
                                printf("ERROR! Account %d does not exist!\n", checkbalance_1_arg);
                            }
                        }
                        break;

                    default:
                        printf("You informed an invalid operation number!");
                        break;
                }
                break;

            case 2:
                printf("\nSelect an ATM operation:\n");
                printf(" 1 - Withdraw money from Account\n");
                printf(" 2 - Deposit money into Account\n");
                printf(" 3 - Statement from Account\n");
                scanf("%d", &operation);

                switch (operation) {
                    case 1:
                        result_5 = withdraw_1(&withdraw_1_arg, clnt);
                        if (result_5 == (int *) NULL) {
                            clnt_perror (clnt, "call failed");
                        }
                    case 2:
                        result_4 = deposit_1(&deposit_1_arg, clnt);
                        if (result_4 == (int *) NULL) {
                            clnt_perror (clnt, "call failed");
                        }
                    case 3:
                        result_6 = checkbalance_1(&checkbalance_1_arg, clnt);
                        if (result_6 == (float *) NULL) {
                            clnt_perror (clnt, "call failed");
                        }
                    default:
                        printf("You informed an invalid operation number!");
                        break;
                }
                break;

            default:
                printf("You informed an invalid process number!");
                break;
        }
    }

#ifndef DEBUG
    clnt_destroy (clnt);
#endif   /* DEBUG */
}


int main (int argc, char *argv[]) {
    char *host;

    if (argc < 2) {
        printf ("usage: %s server_host\n", argv[0]);
        exit (1);
    }
    host = argv[1];
    bank_prog_1 (host);
    exit (0);
}
