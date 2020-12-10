#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bankstuff.h"
//Hung Nguyen
//1001721494

Account *read_file(int size, char *filename)
{
    Account*temp=NULL;
    Account *head=NULL;
    char *token;
    char line[200];
    FILE *fp = fopen(filename,"r+");
    int i;
    if (fp==NULL)
    {
        printf("No File found");
    }
    else
    {
    for (i=0; i<size;i++)
    {   head = (Account*)malloc(sizeof(Account));
        head->user_name = (char**)malloc(2 * sizeof(char*));
        head->user_name[0]= malloc(50);
        head->user_name[1] = malloc(50);
        head->bank_name = malloc(20);
        fgets(line, 200,fp);
        token=strtok(line," ");
        strcpy(head->user_name[0],token); // read in first name
        token=strtok(NULL,",");
        strcpy(head->user_name[1],token); // read in last name
        token=strtok(NULL,","); // bank name
        strcpy(head->bank_name,token);
        token=strtok(NULL,",");
        head->num_account=atoi(token);
        if(atoi(token) == 2 )
        {
            head->account_numbers = (int**)malloc(2*sizeof(int*));
            head->account_numbers[0]= (int*)malloc(sizeof(int));
            head->account_numbers[1] = (int*)malloc(sizeof(int));
            head->total_in_account = (float**)malloc(2*sizeof(float*));
            head->total_in_account[0]= (float*)malloc(sizeof(float));
            head->total_in_account[1] = (float*)malloc(sizeof(float));

            token=strtok(NULL,",");
            int x = atoi(token);
            *(head->account_numbers[0]) = x; // ac num checking
            token=strtok(NULL,",");

            int y = atoi(token);
            *(head->account_numbers[1]) = y; //ac num saving
            token=strtok(NULL,",");

            float z = atof(token);
            *(head->total_in_account[0]) = z; // checking amount
            token=strtok(NULL,"\n");

            float k = atof(token);
            *(head->total_in_account[1]) = k; //saving amount


        }
        else
        {
            head->account_numbers = (int**)malloc(1*sizeof(int*));
            head->account_numbers[0]= (int*)malloc(sizeof(int));

            head->total_in_account = (float**)malloc(1*sizeof(float*));
            head->total_in_account[0] = (float*)malloc(sizeof(float));

            token=strtok(NULL,",");
            int x = atoi(token);
            *(head->account_numbers[0]) = x; // ac num checking

            token=strtok(NULL,"\n");
            float z = atof(token);
            *(head->total_in_account[0]) = z; // checking amount


        }
            head->next = temp;
            temp = head;

    }
    }
    free(temp);
    fclose(fp);

    return head;
}

void print_list(Account* head)
{

    while(head != NULL)
    {
        printf("%s %s\n",head->user_name[0], head->user_name[1]);
        head=head->next;
    }
}


Account* search(char* first, char*last, Account*head)
{
    while(head!=NULL)
            {
                if(strcmp(first,head->user_name[0])==0 && strcmp(last,head->user_name[1])==0)
                    {
                        Account* temp = NULL;
                        temp = head;
                        free(head);

                        return temp;
                    }
                head = head->next;
            }
            free(head);
            return NULL;
}
void free_list(Account *head)
{
    Account *tmp = NULL;
    while (head!=NULL)
    {

        tmp = head;
        head = head->next;
        free(tmp);

    }
}
