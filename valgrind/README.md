
Q1)

The code used (return 0; and exit(0); give different outputs on valgrind for some reason): 
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void insert(node *L, int n)
{
    node *t = (node *)malloc(sizeof(node));
    t->data = n;
    node *h = L;
    while (h->next && h->next->data < n)
    {
        h = h->next;
    }
    t->next = h->next;
    h->next = t;
    printf("insert %d: ", n);
    h = L;
    while (h->next)
    {
        printf("%d  ", h->next->data);
        h = h->next;
    }
    printf("\n");
}

node *ldel(node *L, int x)
{
    node *p;
    p = L;
    while (p->next)
    {
        if (p->next->data == x)
        {
            p->next = p->next->next;
            printf("delete %d: ", x);
            node *h = L;
            while (h->next)
            {
                printf("%d  ", h->next->data);
                h = h->next;
            }
            printf("\n");
            return L;
        }
        if (p->next->data > x)
            break;
        p = p->next;
    }
    return L;
}

int main()
{
    node *L = (node *)malloc(sizeof(node));
    L->data = -1;
    L->next = NULL;
    insert(L, 5);
    insert(L, 14);
    insert(L, 18);
    insert(L, 4);
    insert(L, 13);
    insert(L, 20);
    insert(L, 8);
    insert(L, 9);
    exit(0);
}
```

(a) Delete in increasing order.
```valgrind
==96756== HEAP SUMMARY:
==96756==     in use at exit: 144 bytes in 9 blocks
==96756==   total heap usage: 10 allocs, 1 frees, 1,168 bytes allocated
==96756== 
==96756== LEAK SUMMARY:
==96756==    definitely lost: 16 bytes in 1 blocks
==96756==    indirectly lost: 112 bytes in 7 blocks
==96756==      possibly lost: 0 bytes in 0 blocks
==96756==    still reachable: 16 bytes in 1 blocks
==96756==         suppressed: 0 bytes in 0 blocks
```
(b) Delete in descending order.
```valgrind
==96672== HEAP SUMMARY:
==96672==     in use at exit: 144 bytes in 9 blocks
==96672==   total heap usage: 10 allocs, 1 frees, 1,168 bytes allocated
==96672== 
==96672== LEAK SUMMARY:
==96672==    definitely lost: 128 bytes in 8 blocks
==96672==    indirectly lost: 0 bytes in 0 blocks
==96672==      possibly lost: 0 bytes in 0 blocks
==96672==    still reachable: 16 bytes in 1 blocks
==96672==         suppressed: 0 bytes in 0 blocks
```

Q2)

To get a circular linked list as required by the question, add the following to Q1 code and call the function:
```c
void makeCircular(node* L)
{
    node *h=L;
    while(h->next){
        h=h->next;
    }
    h->next=L->next;
}
```

(a)???
```valgrind
==97437== HEAP SUMMARY:
==97437==     in use at exit: 144 bytes in 9 blocks
==97437==   total heap usage: 10 allocs, 1 frees, 1,168 bytes allocated
==97437== 
==97437== LEAK SUMMARY:
==97437==    definitely lost: 16 bytes in 1 blocks
==97437==    indirectly lost: 0 bytes in 0 blocks
==97437==      possibly lost: 0 bytes in 0 blocks
==97437==    still reachable: 128 bytes in 8 blocks
==97437==         suppressed: 0 bytes in 0 blocks
```

(b) L is still reachable, node containing 4 is definitely lost, and the rest are indirectly lost.
```valgrind
==98326== LEAK SUMMARY:
==98326==    definitely lost: 16 bytes in 1 blocks
==98326==    indirectly lost: 112 bytes in 7 blocks
==98326==      possibly lost: 0 bytes in 0 blocks
==98326==    still reachable: 16 bytes in 1 blocks
==98326==         suppressed: 0 bytes in 0 blocks
```

(c) Node containing 4 is definitely lost, and the rest are indirectly lost.
```valgrind
==98394== LEAK SUMMARY:
==98394==    definitely lost: 16 bytes in 1 blocks
==98394==    indirectly lost: 112 bytes in 7 blocks
==98394==      possibly lost: 0 bytes in 0 blocks
==98394==    still reachable: 0 bytes in 0 blocks
==98394==         suppressed: 0 bytes in 0 blocks
```

(d) L is still reachable, node containing 5 is definitely lost, and the rest are indirectly lost.
```valgrind
==98459== LEAK SUMMARY:
==98459==    definitely lost: 16 bytes in 1 blocks
==98459==    indirectly lost: 96 bytes in 6 blocks
==98459==      possibly lost: 0 bytes in 0 blocks
==98459==    still reachable: 16 bytes in 1 blocks
==98459==         suppressed: 0 bytes in 0 blocks
```

(e) The external head pointer is definitely lost, while all the elements of the circular linked list are still reachable.
```valgrind
==98564== LEAK SUMMARY:
==98564==    definitely lost: 16 bytes in 1 blocks
==98564==    indirectly lost: 0 bytes in 0 blocks
==98564==      possibly lost: 0 bytes in 0 blocks
==98564==    still reachable: 128 bytes in 8 blocks
==98564==         suppressed: 0 bytes in 0 blocks
```

Q3)

The code for our BST:
```c
#include<stdio.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

void insert(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node *current = root;
        struct node *parent = NULL;
        while(1)
        {
            parent = current;
            if(data < parent->data)
            {
                current = current->left;
                if(current == NULL)
                {
                    parent->left = temp;
                    return;
                }
            }
            else
            {
                current = current->right;
                if(current == NULL)
                {
                    parent->right = temp;
                    return;
                }
            }
        }
    }
}

int main()
{
    insert(6);
    insert(9);
    insert(3);
    insert(2);
    insert(10);
    insert(7);
    insert(5);
    insert(8);
    insert(4);
    return 0;
}
```

(a) The root (6) is definitely lost.
```valgrind
==103527== HEAP SUMMARY:
==103527==     in use at exit: 216 bytes in 9 blocks
==103527==   total heap usage: 10 allocs, 1 frees, 8,824 bytes allocated
==103527== 
==103527== LEAK SUMMARY:
==103527==    definitely lost: 24 bytes in 1 blocks
==103527==    indirectly lost: 192 bytes in 8 blocks
==103527==      possibly lost: 0 bytes in 0 blocks
==103527==    still reachable: 0 bytes in 0 blocks
==103527==         suppressed: 0 bytes in 0 blocks
```

(b) need to complete
```valgrind
==103733== HEAP SUMMARY:
==103733==     in use at exit: 192 bytes in 8 blocks
==103733==   total heap usage: 10 allocs, 2 frees, 8,880 bytes allocated
==103733== 
==103733== LEAK SUMMARY:
==103733==    definitely lost: 48 bytes in 2 blocks
==103733==    indirectly lost: 144 bytes in 6 blocks
==103733==      possibly lost: 0 bytes in 0 blocks
==103733==    still reachable: 0 bytes in 0 blocks
==103733==         suppressed: 0 bytes in 0 blocks
```

(c) need to complete
```valgrind
==103869== HEAP SUMMARY:
==103869==     in use at exit: 216 bytes in 9 blocks
==103869==   total heap usage: 10 allocs, 1 frees, 8,840 bytes allocated
==103869== 
==103869== LEAK SUMMARY:
==103869==    definitely lost: 48 bytes in 2 blocks
==103869==    indirectly lost: 144 bytes in 6 blocks
==103869==      possibly lost: 0 bytes in 0 blocks
==103869==    still reachable: 24 bytes in 1 blocks
==103869==         suppressed: 0 bytes in 0 blocks
```

(d) need to complete
```valgrind
==104022== HEAP SUMMARY:
==104022==     in use at exit: 168 bytes in 7 blocks
==104022==   total heap usage: 10 allocs, 3 frees, 8,936 bytes allocated
==104022== 
==104022== LEAK SUMMARY:
==104022==    definitely lost: 96 bytes in 4 blocks
==104022==    indirectly lost: 48 bytes in 2 blocks
==104022==      possibly lost: 0 bytes in 0 blocks
==104022==    still reachable: 24 bytes in 1 blocks
==104022==         suppressed: 0 bytes in 0 blocks
```

(e) need to complete
```valgrind
==104113== HEAP SUMMARY:
==104113==     in use at exit: 144 bytes in 6 blocks
==104113==   total heap usage: 10 allocs, 4 frees, 8,952 bytes allocated
==104113== 
==104113== LEAK SUMMARY:
==104113==    definitely lost: 96 bytes in 4 blocks
==104113==    indirectly lost: 48 bytes in 2 blocks
==104113==      possibly lost: 0 bytes in 0 blocks
==104113==    still reachable: 0 bytes in 0 blocks
==104113==         suppressed: 0 bytes in 0 blocks
```
