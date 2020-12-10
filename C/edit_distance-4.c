#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "edit_distance.h"

//////Hung Nguyen////////
//////1001721494/////////


/*  Suggestions
- When you work with 2D arrays, be careful. Either manage the memory yourself, or
work with local 2D arrays. Note C99 allows parameters as array sizes as long as 
they are declared before the array in the parameter list. See: 
https://www.geeksforgeeks.org/pass-2d-array-parameter-c/

Worst case time complexity to compute the edit distance from T test words
 to D dictionary words where all words have length MaxLen:
Student answer:  Theta((T * D) * MAX_LEN^2)
*/

/* You can write helper functions here */

void print_T(char *first_string,char *second_string, int *array)
{
    int n_str1 = strlen(first_string);
    int n_str2 = strlen(second_string);
    printf("   |   |");
    int i ,j ;
    for( i = 0; i < n_str2; i++)
    {   
         printf("%3c|", second_string[i]);
    }
    printf("\n--------");

    for(i=0; i < n_str2; i++)
    {
        printf("----");
    }
    printf("\n");
    for( i = 0; i < n_str1+1; i ++)
    {
        if (i == 0)
        {
            first_string[i-1]=' ';
        }

        printf("%3c|", first_string[i-1]);
        for(j = 0 ; j < n_str2 + 1 ; j++)
        {
            printf("%3d|", *((array+i*(n_str2+1))+j));
        }
        printf("\n");
        for(j = 0; j < n_str2 +  2 ; j++)
        {
            printf("----");
        }
        printf("\n");
    }
    printf("\n");
}
int min_cmp(int num1, int num2, int num3)
{
    if(num1 <= num2 && num1 <= num3){       return num1;}
    else if(num3 <= num1 && num3 <= num2){  return num3;}
    else{                                   return num2;}
}
int edit_distance(char * first_string, char * second_string, int print_table)
{
    int i , j;
    int nstr_1 = strlen(first_string)+1;
    int nstr_2 = strlen(second_string)+1; //+1 for the " "
    int arr[nstr_1][nstr_2];// Create a 2D int array to store the num distance
    for(i = 0; i< nstr_1; i++)
    {
        for(j = 0; j< nstr_2; j++)
        {
            if(i == 0 && j == 0)
            {// Special case for Dist(0,0)
                arr[i][j] = 0;
            }
            else if( i == 0 && j > 0)
            {// Special case for Dist(0,j)
                arr[i][j] = arr[i][j-1]+1;
            }
            else if(i > 0 && j == 0)
            {// Special case for Dist(i,0)
                arr[i][j] = arr[i - 1][j] + 1;
            }
            else if( i > 0 && j > 0)
            {// Special case for Dist(i,j)
                char first = first_string[i-1];
                char second = second_string[j-1];
                if(first == second)
                {
                    arr[i][j] = arr[i-1][j-1] + 0;  // Current = diagnol arr + 0
                }
                else
                {
                    arr[i][j]=1+min_cmp(arr[i][j-1],arr[i-1][j],arr[i-1][j-1]); // 1 + min
                }
            }
        }
    }
    if(print_table == 1)
    {
        print_T(first_string, second_string, (int*)arr);
    }
    return arr[nstr_1 - 1][nstr_2 - 1];
}

void spellcheck(char* dictname, char * testname)
{
    int MAX_LEN = 101;
    int i, c;
    FILE *T = fopen(testname,"r");
    if(T==NULL)
    {
        printf("No %s file found \n",testname);
    }
    
    FILE *D = fopen(dictname,"r");
    if(D==NULL)
    {
        printf("No %s file found\n",dictname);
    }
    printf("\nLoading dictionary file: %s\n",dictname);
    printf("Loading test file: %s\n",testname);
    int num_test;
    int num_dict;
    
    fscanf(T,"%d",&num_test); // require pointer so &int
    fscanf(D,"%d",&num_dict); // require pointer so &int
    int num_t,num_d;

    char testw[MAX_LEN];
    char dictw[MAX_LEN];
    int num[num_dict];

    int count = 0;
    int result = -1;
    int min_dist;
    for( i = 0 ; i < num_test; i++ )
    {
        fscanf(T,"%s",testw);
        printf("\n------- Current test word: %s\n",testw);
        count = 0;
        rewind(D);
        while(!feof(D))
        {
            fscanf(D,"%s",dictw);
            num[count] = edit_distance(testw,dictw,0);// Create an array of distance
            count++;
        }
        min_dist = num[0];
        for( c = 1; c < num_dict; c++)
        {
            if(num[c] < min_dist)
            {
                min_dist = num[c];//Save the min from the array
            }
        }
        printf("Minimum distance: %d\n",min_dist);
        printf("Words that give minimum distance: \n");
        rewind(D);
        while(!feof(D))
        {
            fscanf(D,"%s",dictw);
            result = edit_distance(testw,dictw,0);
            if(result == min_dist)// if equal to min distance then print
            {
                printf("%s\n",dictw);
            }
        }

    } 
    fclose(T);
    fclose(D);
}
