#ifndef BANK_STUFF_H
#define BANK_STUFF_H
typedef struct account
{
    char ** user_name;
    char *bank_name;
    int num_account;
    int ** account_numbers;
    float **total_in_account;
    struct account *next;
}Account;

Account *read_file(int size, char *filename);

void print_list(Account* head);

Account* search(char* first, char*last, Account*head);

void free_list(Account *head);

#endif
