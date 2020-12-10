#ifndef HW8_H
#define HW8_H

typedef struct node {
    char *word;
    struct node*left;
    struct node *right;
    int SpaceCount;
}Node;

void read_file(Node* n,char*filename);

#endif
