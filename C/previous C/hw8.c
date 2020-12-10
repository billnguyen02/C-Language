#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HW8.h"
// Hung Nguyen 1001721494
void read_file(Node* n,char*filename)
{
    FILE* fp;
    fp = fopen(filename,"r");
    char ch;
    char letter[20];
    int i=0;
    int j = 1;
    int SpaceCount=0;
    char* token;
    char textName [40];
    char ans[5];

    while (j)
    {
        printf("-----Reading in\n");
        printf("-----Translating\n");
        printf("-----What file to save to? \n");
        fgets(textName,40,stdin);
        strtok(textName,"\n");
        FILE* fp2;
        fp2 = fopen(textName,"w");
        printf("Saved to file ^__^\n");

        while(!feof(fp))
        {
            ch = fgetc(fp);
             if(ch == ' ')
                {
                    SpaceCount ++;
                    if (SpaceCount == 1)
                    {
                        letter [i] = '\0';
                       //printf("\nletter:\n %s     ",letter);
                        decode_morse(n,letter,fp2);
                        //printf("i= %d",i);
                        i=0;
                    }
                    else if(SpaceCount == 2)
                    {
                        //printf("AAA");
                        letter [i] = '\0';
                        i=0;
                    }
                    else if (SpaceCount == 3)
                    {
                        fprintf(fp2," ");
                        letter [i] = '\0';
                        i=0;
                        SpaceCount = 0;
                    }
                }


            else if (ch == '.'|| ch == '-')
            {
                SpaceCount = 0;
                letter[i] = ch;
                i++;
            }
            else if(ch == '#')
            {
                SpaceCount = 0;
                fprintf(fp2,". ");
                letter [i] = '\0';
                i=0;
                //fgetc(fp);
            }
        }

                printf("Would you like to read in another file? y or n\n");
                fgets(ans,40,stdin);
                strtok(ans,"\n");
                if(strcmp(ans,"n")==0)
                {
                    j=0;
                    fclose(fp2);
                }
                else if(strcmp(ans,"y")==0)
                {
                    j=1;
                }
                else
                {
                    printf("Wrong input\n");
                }

    }
        fclose(fp);

}
