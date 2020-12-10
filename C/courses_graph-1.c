#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Hung Nguyen
//1001721494
struct str
{
    char name[100];
}typedef str;

int indexof(char *word, char** str, int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        if(strcmp(word,str[i]) == 0)
            return i;
    }
    return -1;
}
void DFS_visit(int V,int *count,int *u,int *time, int matrix[][V],str* color, int pred[V], int d[V], int finish[V],int *cycle)
{
    *time =*time + 1;
    d[*u] = *time;
    
        if(strcmp(color[*u].name,"WHITE") == 0)
        {  
            strcpy(color[*u].name,"GRAY"); // Make it gray for visit
            int i;
                      
            for( i = 0; i < V; i ++)
            {          
                    if(strcmp(color[i].name,"WHITE") == 0)
                    {       
                        if(matrix[*u][i] == 1)
                        {                                                                                        
                            DFS_visit(V,count,&i,time,matrix,color, pred,d,finish,cycle);
                        }                       
                    }
                    if(strcmp(color[i].name,"GRAY") == 0 && matrix[*u][i] == 1 )
                    {
                            *cycle = 100;
                    }
            }
                   
        }          
        

    pred[*count] = *u;
    *count = *count+1 ;   
    strcpy(color[*u].name,"BLACK");
    *time =*time + 1;
    finish[*u] = *time;
}
void DFS(int N, int matrix[][N],char** strr)
{
    int u = 0;
    str color[N];
    int pred[N];
    int d[N];
    int finish[N];
    int cycle = 0;
    for (u = 0; u < N ; u++)
    {
        strcpy(color[u].name,"WHITE");
        pred[u] = -1;
        d[u] = -1;
        finish[u] = -1; 
    }
    int time = 0;
    int count = 0;
    
    for( u = 0; u < N; u ++)
    {   
        
        if(strcmp(color[u].name,"WHITE") == 0)
        {
            {
                DFS_visit(N,&count,&u,&time,matrix,color, pred,d,finish,&cycle);             
            }                  
        }
        
    }
    printf("\nStart and finish times for each node, in format:\n");
    printf("node num: (start,finish)\n");
    for( u = 0; u < N; u++)
    {
        printf("node %d : (%d,%d)\n",u,d[u],finish[u]);
    }
    printf("\n");
    if (cycle == 0)
    {
        printf("Order in which to take courses\n");
        int counter = 1;

        for(u = (N-1); u >= 0;u--)
        {
            printf("%d.  - %s (corresponds to graph vertex %d)\n",counter,strr[pred[u]],pred[u]);
            counter++;
        }
    }
    else
    {
        printf("There was at least one cycle. There is no possible ordering of the courses.\n");
    }

}
void Print_matrix(int N,int E [][N],char** str)
{
    int i,j;
    printf("Number of verticles in built graph: N = %d\n",N);
    printf("Vertex - coursename correspondence\n");
    for(i = 0; i < N; i++)
    {
        printf("%d - %s\n",i,str[i]);
    }
    printf("\nAdjacency matrix\n");
    printf("     |");
    for( i = 0; i < N ; i++)
      {
             printf("%5d",i);
      }
    printf("\n-");
    for( i = 0; i < N+1 ; i++)
      {
          printf("-----");
      }

    printf("\n");
     for(i = 0; i < N; i ++)
        {   printf("%5d|",i);
        for(j = 0; j < N; j++)
            {
                printf("%5d",E[i][j]);   
            } 
               printf("\n");  
        }                     
}
int get_N(char*filename){
      FILE *F = fopen(filename,"r");
      int v = 0;
      char line[100];
       while(fgets(line,100,F)!=NULL)
            {
                v++; // the number of vertex we need 
            }
            
       rewind(F);
       fclose(F);
       return v;
}
int main()
{
    printf("\nThis program will read, from a file, a list of courses and their prerequisites and will print the list in which to take cousres.\n");
    printf("Enter the file name: ");
    char filename[100];
    scanf("%s",filename);
    FILE *F = fopen(filename,"r");
    if(F==NULL)
    {printf("Could not open file %s. Exit\n\nFailed to read from file. Program will terminate.\n\n",filename);}
    else
    {
         int N;
          N = get_N(filename);
         int arr[N][N];
         char* token;
         char* w_token;
         int i , j , v1, v2;
         for(i = 0; i < N; i ++)
            for(j = 0; j < N; j++)
                arr[i][j] = 0;
         char line[1000];       
         char **str;
         str = (char**) malloc(100*sizeof(char*));
         for( i = 0 ; i < N ; i ++)
         {
             fgets(line,100,F);
             token = strtok(line," \t\r\n\v\f");
             (str[i]) = (char*)malloc(100*sizeof(char));
             strcpy(str[i],token); // vertexs
             
         }   
         rewind(F);
         char copy[100] ;
         while(fgets(line,100,F)!=NULL)
         {
             token = strtok(line,"\n");
             w_token = strtok(token," \t\r\n\v\f");
             strcpy(copy,w_token);
             w_token = strtok(NULL," \t\r\n\v\f"); // get rid of the vertexs
             while(w_token!=NULL)
             {         
                v1 = indexof(copy,str,N);
                v2 = indexof(w_token,str,N);
                arr[v2][v1] = 1;
                w_token = strtok(NULL," \t\r\n\v\f");      
             }           
         } 
         Print_matrix(N,arr,str);

         printf("\n\nRunning DFS...\n");
         printf("Finished DFS\n");
         DFS(N,arr,str);
         printf("\n");

         for( i = 0 ; i < N; i ++)
         {
             free(str[i]);
         }
         free(str);        
         fclose(F);     
    }

    return 0;
}


