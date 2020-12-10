#ifndef hw7_h
#define hw7_7

typedef struct stack
{
    float stk [8];
    int top;
}Stack;

typedef struct Qnode
{
    char **full_name;
    int num;
    int capacity;
    struct Qnode *next;

}Node;


void read_file(struct Queue *Q,char *f);
void Search ( struct Queue* h, int ans);
Stack *update(Stack*s,float 
void Display_Stack (Stack *s, int count);
Stack *Enter_tip (Stack* s);
#endiff