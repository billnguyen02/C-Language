#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw7.h"

//Hung Nguyen 1001721494

void read_file(struct Queue *Q,char *f)
{
    FILE* fp;
    char line [100];
    char *token;

    fp = fopen(f,"r");
    int i;
    Node *info = NULL;
    Node *temp = NULL;
    Node *head = NULL;

    if(fp==NULL)
    {
        printf("NO FILE FOUND SENPAI");
    }
    printf("--Adding customer info from file\n");
    for(i = 0; i < 6;i++)
    {
        fgets(line,100,fp);
        info = (Node*)malloc(sizeof(Node));
        info->full_name = malloc(2*sizeof(char *));
        info->full_name[0]= malloc(20);
        info->full_name[1] = malloc(20);
        token = strtok(line,",");
        strcpy(info->full_name[0],token);
        token = strtok(NULL,",");
        strcpy(info->full_name[1],token);
        token = strtok(NULL,"\n");
        info->num = atoi(token);
        info-> capacity ++;
        Enqueue(info,Q);
        printf("%s %s %d\n",info->full_name[0],info->full_name[1],info->num);
    }
    printf("\nAll customer info added\n\n\n");
    fclose(fp);



}
Stack *Enter_tip (Stack* s)
{
        char amount[20];
        int count = 0;
        s->top = 0;

        int i=0 ;
            printf("***Tip Jar***\n");

            while(i < 8)
            {
                printf("Enter tip: $ ");
                fgets(amount,20,stdin);
                //printf("DUME");
                strtok(amount,"\n");
                //printf("amount = %s", amount);
                if(strcmp(amount,"done")==0)
                {
                    //printf("23");
                    return s ;
                    break;
                }
                else
                {
                    //printf("12");
                    float x = atof(amount);
                    //printf("BUbba");
                    s->stk[i] = x;
                    s->top++;
                    i++;
                    //printf("asdasdas");
                }

            }


    return s  ;
}
Stack *update(Stack*s,float hour)
{
    float pay = hour * 2;
    int i = 1;
    float owe = 0;
    int count;

    while( s->stk[s->top-1] < pay )
    {
        owe = pay - s->stk[s->top-i];
        s = pop(s);
        s->stk[s->top-i] = s->stk[s->top-i] - owe;
        i++;
        return s;
    }

    if(pay < s->stk[s->top-1])
    {
        s->stk[s->top-1] = s->stk[s->top-1] - pay;
        return s;
    }

}