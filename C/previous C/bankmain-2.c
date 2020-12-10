#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bankstuff.h"

//Hung Nguyen
//1001721494

int main(int argc,char**argv)
{
        int i;
        char firstname_transfer[20];
        char lastname_transfer[20];
        char user_firstname[20];
        char user_lastname[20];
        char *token;
        char answer[20];
        char money[10];
        Account *list_h = read_file(7,"bankaccounts.txt");
        //print_list(list_h);
        char line[100];
        char account[20];
        Account* transfer = malloc(sizeof(Account));
        Account* user = malloc(sizeof(Account));
    while (i = 1)
            {
                printf("***********************************************\n");
                printf("Welcome to Money Transfer-Voted the best 10 Years in a Row! ***\n");
                printf("***********************************************\n");
                printf("Enter your first and last name: ");
                fgets(line,100,stdin);
                token = strtok(line," ");
                strcpy(user_firstname,token);
                token = strtok(NULL,"\n");
                strcpy(user_lastname,token);

                user = search(user_firstname,user_lastname,list_h);

                if(strcmp(user_firstname,"exit")==0 && strcmp(user_lastname,"program")==0)
                {
                    printf("Exiting......");
                    break;
                }

        if(user!=NULL)
        {
                printf("Who do you want to transfer to? ");
                fgets(line,100,stdin);
                token = strtok(line," ");
                strcpy(firstname_transfer,token);
                token = strtok(NULL,"\n");
                strcpy(lastname_transfer,token);

                transfer = search(firstname_transfer,lastname_transfer,list_h);
                printf("How much money do you want to transfer? $");
                fgets(money,10,stdin);
                strtok(money,"\n");
        if(user->num_account==2)
                {
                    printf("From which account? ");
                    fgets(account,20,stdin);
                    strtok(account,"\n");


           if(strcmp(account,"savings")==0)
            {
                if(*(user->total_in_account[1]) < (atof(money)))
                {
                    printf("sorry you do not have sufficient funds to make this transfer. Ending session....");
                }
                else if (strcmp(user->bank_name,transfer->bank_name)!=0)
                {
                    printf("Recipient is in a different bank. You will be charge a 5% transaction fee. Continue? y or n\n");
                    fgets(answer,20,stdin);
                    strtok(answer,"\n");

                    if(strcmp(answer,"y")==0)
                    {
                        printf("Before transfer: $%.2f\n",*(user->total_in_account[1]));
                        printf("After transfer: $%.2f\n",*(user->total_in_account[1])-atof(money)-atof(money)*5/100);
                        printf("Transaction successfully completed\n\n");
                        printf("****************************************\n");
                    }


                    else if(strcmp(answer,"n")==0)
                    {
                        printf("Transaction canceled\n");
                    }
                }
                else
                    {
                        printf("Before transfer: $%.2f\n",*user->total_in_account[1]);
                        float left = *(user->total_in_account[1])-atof(money)-atof(money);
                        printf("After transfer: $%.2f\n",left);
                        printf("Transaction successfully completed\n\n");
                        printf("****************************************\n");
                    }
            }
            else if(strcmp(account,"checking")==0)
                {
                if(*(user->total_in_account[1]) < (atof(money)))
                {
                    printf("sorry you do not have sufficient funds to make this transfer. Ending session....");
                }
                else if (strcmp(user->bank_name,transfer->bank_name)!=0)
                {
                    printf("Recipient is in a different bank. You will be charge a 5% transaction fee. Continue? y or n\n");
                    fgets(answer,20,stdin);
                    strtok(answer,"\n");

                    if(strcmp(answer,"y")==0)
                    {
                        printf("Before transfer: $%.2f\n",*user->total_in_account[0]);
                        printf("After transfer: $%.2f\n",(*(user->total_in_account[0])-atof(money)-atof(money)*5/100));
                        printf("Transaction successfully completed\n\n");
                        printf("****************************************\n");
                    }
                    else if(strcmp(answer,"n")==0)
                    {
                        printf("Transaction canceled\n");
                    }
                }
                else
                    {
                        printf("Before transfer: $%.2f\n",*user->total_in_account[0]);
                        printf("After transfer: $%.2f\n",(*(user->total_in_account[0])-atof(money))-atof(money));
                        printf("Transaction successfully completed\n\n");
                        printf("****************************************\n");
                    }
            }



        }
        if(user->num_account==1)
        {
            {
                if(*(user->total_in_account[0]) < (atof(money)))
                {
                    printf("sorry you do not have sufficient funds to make this transfer. Ending session....");
                }
                else if (strcmp(user->bank_name,transfer->bank_name)!=0)
                {
                    printf("Recipient is in a different bank. You will be charge a 5% transaction fee. Continue? y or n\n");
                    fgets(answer,20,stdin);
                    strtok(answer,"\n");

                    if(strcmp(answer,"y")==0)
                    {
                        printf("Before transfer: $%.2f\n",*user->total_in_account[0]);
                        printf("After transfer: $%.2f\n",(*(user->total_in_account[0])-atof(money)-atof(money)*5/100));
                        printf("Transaction successfully completed\n\n");
                        printf("****************************************\n");
                    }
                    else if(strcmp(answer,"n")==0)
                    {
                        printf("Transaction canceled\n");
                    }
                }
                else
                    {
                        printf("Before transfer: $%.2f\n",*user->total_in_account[0]);
                        printf("After transfer: $%.2f\n",(*(user->total_in_account[0])-atof(money)));
                        printf("Transaction successfully completed\n\n");
                        printf("****************************************\n");
                    }
            }
        }

    }
  }

                    free_list(user);
                    free_list(transfer);
                    free_list(list_h);



}
