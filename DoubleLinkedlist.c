#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;

// Function to create a new node
struct Node* createNode(int item) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Memory insufficient\n");
        return NULL;
    }
    newnode->data = item;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

// Insert at the beginning
void Insert_Beg(int item) {
    struct Node* newnode = createNode(item);
    if (newnode == NULL) return;

    if (head == NULL) {
        head = tail = newnode;
    } else {
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
}

// Insert at the end
void Insert_End(int item) {
    struct Node* newnode = createNode(item);
    if (newnode == NULL) return;

    if (head == NULL) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

// Insert at a specific position
void Insert_Any_P(int item, int pos) {
    struct Node* newnode = createNode(item);
    if (newnode == NULL) return;

    int count = 0;
    struct Node* temp = head;
    
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    if (pos > count + 1 || pos < 1) {
        printf("Invalid position\n");
        free(newnode);
        return;
    }

    if (pos == 1) {
        Insert_Beg(item);
    } else if (pos == count + 1) {
        Insert_End(item);
    } else {
        temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newnode;
        }
        temp->next = newnode;
    }
}

// Delete from the beginning
void Delete_Begin() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    free(temp);
}

// Delete from the end
void Delete_End() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = tail;
    if (head == tail) {
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    free(temp);
}

// Delete from a specific position
void Delete_Pos(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    int count = 0;
    struct Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    if (pos > count || pos < 1) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        Delete_Begin();
    } else if (pos == count) {
        Delete_End();
    } else {
        temp = head;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        free(temp);
    }
}

// Function to display the list
void display() {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Insert_Beg(10);
    Insert_End(20);
    Insert_End(30);
    Insert_Any_P(15, 2);

    display();

    Delete_Begin();
    display();

    Delete_End();
    display();

    Delete_Pos(2);
    display();

    return 0;
}
