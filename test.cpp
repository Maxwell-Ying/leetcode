#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int Max = 2;

struct Node{
    char entry[4];
    struct Node* next;
};

char * data[9] = {"rat", "mop", "cat", "map", "car", "top", "cot", "tar", "rap"};

struct Node* init_list()
{
    struct Node * head, *p;
    head = (struct Node *)malloc(sizeof(struct Node));
    strcpy(head -> entry, "rat");
    head->next = NULL;
    p = head;
    int i;
    for (i=1; i<9; i++) {
        p->next = (struct Node*) malloc(sizeof(struct Node));
        strcpy(p ->next -> entry, data[i]);
        p = p->next;
    }
    p->next = NULL;
    return head;
};

// need a return for new head of chain. the before head may be now just a node
struct Node * sort(struct Node* head)
{
    // p1 always points to prev-> next during loop, unless in mid-swap step;
    struct Node* p1, *prev;
    // beforehead is used for operate head and non-head equally
    struct Node * beforehead = (struct Node*) malloc(sizeof(struct Node));
    beforehead->next = head;
    prev = beforehead;
    p1 = prev->next;
    int length = Max;
    while(length >= 0)
    {
        while(p1 != NULL && p1->next!= NULL)
        {
            //非首结点
            if (p1->entry[length] > p1->next->entry[length]) {
                prev->next = p1->next;
                p1->next = p1->next->next;
                prev->next->next = p1;
                // after a swap, reset p1 to head for upper check.
                prev = beforehead;
                p1 = prev->next;
                continue;
            }
            prev = prev->next;
            p1 = prev->next;
        }
        length--;
        prev = beforehead;
        p1 = prev->next;
    }
    head = beforehead->next;
    free(beforehead);
    return head;
}

int main()
{
    struct Node* head, * p;

    p = head = init_list();

    //  打印初始列表
    printf("The list is:\n");
    while(p)
    {
        printf("%s  ", p->entry);
        p = p->next;
    }
    printf("\n");

    head = p = sort(head);
    printf("Use radix_sort Method:\n");
    while(p)
    {
        printf("%s  ", p->entry);
        p = p->next;
    }
    return 0;
}
