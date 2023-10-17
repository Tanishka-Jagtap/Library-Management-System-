#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int quantity = 0;
int generateBookID(char* str);
int generateAlphabetID(char c);
int queue_array[20];
struct BST* rack[10][5];
struct User* start = NULL;

struct Queue {
    int queue_array[20];
    int top;
};
void initializeQueue(struct Queue *queue) {
    queue->top = -1;
}

int isFull(struct Queue *queue) {
    return queue->top == 19;
}

int isEmpty(struct Queue *queue) {
    return queue->top == -1;
}

void enQueue(struct Queue *queue, int value) {
    if (!isFull(queue)) {
        queue->top++;
        queue->queue_array[queue->top] = value;
    } else {
        printf("Queue is full!\n");
    }
}

int deQueue(struct Queue *queue) {
    int value = queue->queue_array[0];
    for (int i = 0; i < queue->top; ++i) {
        queue->queue_array[i] = queue->queue_array[i + 1];
    }
    queue->top--;
    return value;
}

void resetQueue(struct Queue *queue) {
    queue->top = -1;
}

int getTop(struct Queue *queue) {
    return queue->top;
}

struct Book {
    char* name;
    char* author;
    int id, amount;
    int rack;
    struct Book* next;
};

struct Book* createBook(const char* new_name, const char* new_author, int new_id, int new_rack) {
    struct Book* book = (struct Book*)malloc(sizeof(struct Book));

    if (book != NULL) {
        // Allocate memory for name and author strings
        book->name = strdup(new_name); // Uses strdup to allocate and copy string
        book->author = strdup(new_author); // Uses strdup to allocate and copy string

        book->id = new_id;
        book->rack = new_rack;
        book->amount = 1;
        book->next = NULL;
    } else {
        fprintf(stderr, "Memory allocation failed for Book\n");
    }

    return book;
}

struct BST {
    int id;
    struct BST* left;
    struct BST* right;
    struct BST* next;
};

struct User {
    char name[100];
    struct Book* book;
    struct User* next;
};
struct User* createUser(char* new_name) {
    struct User* user = (struct User*)malloc(sizeof(struct User));
    strcpy(user->name, new_name);
    user->next = NULL;
    user->book = NULL;
    return user;
}

struct BST* searchBST(struct BST* root, int id);
void displayIssuedBooks();
int returnBook(char* user_name, char* book_name);
struct Book* searchPreviousBook(struct BST* root, char* name, char* author_name);
int searchBookcheck(struct BST* root, char* name, char* author_name);
int issueBook(char* username, char* bookname, char* author_name);
int deleteBook(char* name, char* author_name);
struct Book* searchBook(struct BST* bst, char* name, char* author_name);
int SearchingsearchBook(struct BST* bst, char* name, int rack, int shelve);
void generateLibraryData();
struct Book* searchBookmain(struct BST* root, char* name, char* author_name);
void addBook(int shelve, char* book_name, char* author_name);
struct BST* createBST(int id, struct BST* root);
void displayLibrary(struct BST* root);
struct Queue queue;

int main(){
    // Generating auto library data from file
    generateLibraryData();
    int choice;

    while(1){
        printf("\n\n\n++++++++++     M E N U     ++++++++++\n");
        printf("0. Exit\n");
        printf("1. Display All Books\n");
        printf("2. Insert a Book\n");
        printf("3. Delete a Book\n");
        printf("4. Search Book By Name\n");
        printf("5. Issue Book\n");
        printf("6. Return Book\n");
        printf("7. Display Issued Books\n");
        printf("\nSelect an option : ");
        scanf("%d", &choice);
        switch(choice){
            case 0:
                exit(0);
            case 1:
                printf("\n\n\n++++++++++     D I S P L A Y     ++++++++++\n");
                for (int c = 0; c < 5; ++c) {
                    printf("\n+++++   R A C K - %d   +++++\n", c + 1);
                    for (int r = 0; r < 10; ++r) {
                        printf("\n+++ S H E L V E - %d +++\n", r + 1);
                        displayLibrary(rack[r][c]);
                    }
                }
                break;
            case 2: {
                int option;
                char book_name[256];
                char author_name[256];
                printf("\n\n\n++++++++++     I N S E R T     ++++++++++\n");
                printf("0. Back\n");
                printf("1. Mathematics\n");
                printf("2. Computer\n");
                printf("3. Physics\n");
                printf("4. Islamiat\n");
                printf("5. Others\n");
                printf("\nSelect an option : ");
                scanf("%d", &option);
                if (option == 0) break;
                else {
                    printf("\nBook Name : ");
                    scanf(" %[^\n]s", book_name);
                    printf("\nAuthor Name : ");
                    scanf(" %[^\n]s", author_name);
                    addBook(option - 1, book_name, author_name);
                }
                break;
            }
            case 3: {
                char name[256];
                char author_name[256];
                printf("\n\n\n++++++++++     D E L E T E     ++++++++++\n");
                printf("\nEnter Book Name : ");
                scanf(" %[^\n]s", name);
                printf("\nEnter Author Name : ");
                scanf(" %[^\n]s", author_name);
                int deleted = deleteBook(name, author_name);
                if (deleted) {
                    printf("\n\nSuccessfully Deleted");
                } else {
                    printf("\n\nBook not found");
                }
                break;
            }
            case 4: {
                char name[256];
                int found = 0;
                printf("\n\n\n++++++++++     S E A R C H     ++++++++++\n");
                printf("\nEnter Book Name : ");
                scanf(" %[^\n]s", name);
                int id = generateBookID(name);
                // For each rack
                for (int c = 0; c < 5; ++c) {
                    // For shelve
                    int shelve = id % 10;

                    // search BST
                    struct BST *bst = searchBST(rack[shelve][c], id);

                    // If BST found
                    if (bst != NULL) {
                        found = SearchingsearchBook(bst, name, c, shelve);
                        if (found) {
                            break;
                        }
                    }
                }
                if (!found) {
                    printf("\n\nBook not found");
                }
                break;
            }
            case 5: {
                char book_name[256];
                char author_name[256];
                char username[256];
                printf("\n\n\n++++++++++     I S S U E     ++++++++++\n");
                printf("\nEnter User Name : ");
                scanf(" %[^\n]s", username);
                printf("\nEnter Book Name : ");
                scanf(" %[^\n]s", book_name);
                printf("\nEnter Author Name : ");
                scanf(" %[^\n]s", author_name);
                int issue = issueBook(username, book_name, author_name);
                if (issue) {
                printf("\n\nBook issued successfully!\n");
                }
                break;
            }
            case 6: {
                char book_name[256];
                char username[256];
                printf("\n\n\n++++++++++     R E T U R N     ++++++++++\n");
                printf("\nEnter User Name : ");
                scanf(" %[^\n]s", username);
                printf("\nEnter Book Name : ");
                scanf(" %[^\n]s", book_name);
                int issue = returnBook(username, book_name);
                if (issue) {
                    printf("\n\nBook returned successfully!\n");
                }
                break;
            }
            case 7: {
                printf("\n\n\n++++++++++     I S S U E D   B O O K S     ++++++++++\n");
                displayIssuedBooks();
                break;
            }
            default:{
                printf("\nInvalid input!");
            }
        }       
    }
    return 0;
}

int generateBookID(char *str) {
    struct Queue queue;
    initializeQueue(&queue);
    int value = 0;

    // Check for each character in str
    for (int i = 0; i < strlen(str); ++i) {
        // If str[i] is a space
        if (str[i] == ' ') {
            enQueue(&queue, value);
            value = 0;
        } else {
            value += generateAlphabetID(str[i]);
        }
    }
    enQueue(&queue, value);
    value = 0;

    // Combining different parts
    char combining_values[256];
    strcpy(combining_values, "");
    while (!isEmpty(&queue)) {
        char num[5];
        sprintf(num, "%d", deQueue(&queue));
        strcat(combining_values, num);
    }

    sscanf(combining_values, "%d", &value);

    return value;
}

int generateAlphabetID(char c) {
    char alphabets[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
                        't', 'u', 'v', 'w', 'x', 'y', 'z'};
    c = tolower(c);
    for (int i = 0; i < 26; ++i) {
        if (c == alphabets[i])
            return i + 1;
    }
    return -1;
}

struct BST *searchBST(struct BST *root, int id) {
    if (root == NULL) {
        return NULL;
    } else {
        while (root != NULL) {
            if (root->id > id) root = root->left;
            else if (root->id < id) root = root->right;
            else return root;
        }
        return NULL;
    }
}

void addBook(int shelve, char* book_name, char* author_name) {
    int id = generateBookID(book_name);
    int row = id % 10;

    // Create a new book node
    struct Book* new_book = createBook(book_name, author_name, id, row);

    // Checking if BST already exists then work on it
    if (rack[row][shelve] != NULL) {

        // Create it root and search if any BST already exists
        struct BST* root = rack[row][shelve];
        struct BST* searched = searchBST(root, id);

        // If no BST with such ID exists
        if (searched == NULL) {
            struct BST* new_BST = createBST(id, root);

            // Adding new book to BST
            new_BST->next = (struct BST*)new_book;
        }

        // If BST exists with the same ID
        else {

            // Search if book with the same name exists
            struct Book* searched_book = searchBook(searched, book_name, author_name);

            // If the same book is already present
            if (searched_book != NULL)
                searched_book->amount++;
            else {
                new_book->next = (struct Book*)searched->next;
                searched->next = (struct BST*)new_book;
            }
        }
    }

    // If BST does not exist in the shelve array
    else {
        rack[row][shelve] = createBST(id, NULL);
        rack[row][shelve]->next = (struct BST*)new_book;
    }
}


struct BST* createBST(int id, struct BST* root){
    struct BST* current = (struct BST*)malloc(sizeof(struct BST));
    current->id = id;
    current->left = NULL;
    current->right = NULL;
    current->next = NULL;

    struct BST* p = root;
    struct BST* k = p;

    if (p == NULL) {
        root = current;
    } else {
        while (p != NULL) {
            k = p;
            if (p->id > id) p = p->left;
            else p = p->right;
        }

        if (k->id > id) k->left = current;
        else k->right = current;
    }
    return current;
}

void displayLibrary(struct BST* root) {
    if (root != NULL) {
        displayLibrary(root->left);

        // Displaying book linked list
        struct Book* book = (struct Book*)root->next;
        while (book != NULL) {
            printf("Book ID = %-10d Amount = %-10d Book Name = %-30s Author Name = %10s\n", book->id, book->amount,
                   book->name, book->author);
            book = book->next;
        }

        displayLibrary(root->right);
    }
}

struct Book* searchBook(struct BST* bst, char* name, char* author_name) {
    int id = generateBookID(name);
    struct Book* book = (struct Book*)bst->next;

    while (book != NULL) {
        if (strcmp(book->name, name) == 0 && strcmp(book->author, author_name) == 0){
            return book;
        }
        book = book->next;
    }

    return NULL;
}

int SearchingsearchBook(struct BST* bst, char* name, int rack, int shelve) {
    int id = generateBookID(name);
    struct Book* book = (struct Book*)bst->next;
    int found = 0;

    while (book != NULL) {
        if (strcmp(book->name, name) == 0) {
            found = 1;
            printf("\nBook name : %s       ID : %d   Rack: %d  Shelve: %d  Author Name: %s",
                   book->name, book->id, rack + 1, shelve + 1, book->author);
        }
        book = book->next;
    }

    return found;
}

int deleteBook(char* name, char* author_name) {
    int id = generateBookID(name);
    // For each rack
    for (int c = 0; c < 5; ++c) {
        // For shelve
        int shelve = id % 10;

        // search BST
        struct BST* bst = searchBST(rack[shelve][c], id);

        // If BST found
        if (bst != NULL) {
            // Searching book
            if (searchBookcheck(bst, name, author_name)) {
                struct Book* book = searchBookmain(bst, name, author_name);
                struct Book* prevbook = searchPreviousBook(bst, name, author_name);
                if (strcmp(book->name, name) == 0 && strcmp(book->author, author_name) == 0) {
                    if (book->amount > 1) {
                        book->amount--;
                    } else {
                        if (book->next == NULL) {
                            bst->next = NULL;
                            free(book);
                        } else {
                            bst->next = (struct BST*)book->next;
                            free(book);
                        }
                    }
                    return 1;
                } else if (prevbook != NULL) {
                    if (strcmp(book->next->name, name) == 0 && strcmp(book->next->author, author_name) == 0) {
                        // If amount is greater than 1
                        if (book->next->amount > 1) {
                            book->next->amount--;
                            return 1;
                        }
                        if (book->next->next != NULL) {
                            book->next = book->next->next;
                            free(book->next);
                        } else {
                            book->next = NULL;
                            free(book->next);
                        }
                        return 1;
                    }
                }
            }
        }
    }

    return 0;
}

struct Book* searchPreviousBook(struct BST* root, char* name, char* author_name) {
    int id = generateBookID(name);
    struct Book* book = (struct Book*)root->next;
    struct Book* prev_book = book;

    while (book != NULL) {
        if (strcmp(book->name, name) == 0 && strcmp(book->author, author_name) == 0)
            return prev_book;
        prev_book = book;
        book = book->next;
    }
    return NULL;
}

struct Book* searchBookmain(struct BST* root, char* name, char* author_name) {
    int id = generateBookID(name);
    struct Book* book = (struct Book*)root->next;

    while (book != NULL) {
        if (strcmp(book->name, name) == 0 && strcmp(book->author, author_name) == 0)
            return book;

        book = book->next;
    }
    return NULL;
}


int searchBookcheck(struct BST* root, char* name, char* author_name) {
    int id = generateBookID(name);
    void* book = root->next;

    while (book != NULL) {
        struct Book* current_book = (struct Book*)book;
        if (strcmp(current_book->name, name) == 0 && strcmp(current_book->author, author_name) == 0)
            return 1;

        book = current_book->next;
    }
    return 0;
}


void generateLibraryData() {
    FILE* inFile;
    inFile = fopen("C:\\Users\\HP\\OneDrive\\Desktop\\BTech\\Semester 3\\ADS\\CP\\datafile.txt", "r");
    if (!inFile) {
        printf("Unable to open file datafile.txt");
        exit(EXIT_FAILURE);   // call system to stop
    }

    // Variables that will collect data
    int shelve;
    char shelve_str[512];
    char book_name[512];
    char author_name[512];
    while (fgets(shelve_str, sizeof(shelve_str), inFile) != NULL) {
        // converting shelve_str to int
        shelve = atoi(shelve_str);

        if (fgets(book_name, sizeof(book_name), inFile) == NULL) {
            printf("Invalid file format: missing book name");
            exit(EXIT_FAILURE);
        }
        book_name[strcspn(book_name, "\n")] = 0;  // Remove newline character

        if (fgets(author_name, sizeof(author_name), inFile) == NULL) {
            printf("Invalid file format: missing author name");
            exit(EXIT_FAILURE);
        }
        author_name[strcspn(author_name, "\n")] = 0;  // Remove newline character

        addBook(shelve, book_name, author_name);
    }
    fclose(inFile);
}

int issueBook(char* user_name, char* book_name, char* author_name) {
    // Search if the user already exists
    struct User* user = start;
    while (user != NULL) {
        if (strcmp(user->name, user_name) == 0) {
            printf("\nUser already exists. Cannot issue another book.");
            return 0;
        }
        user = user->next;
    }

    // Search for the book
    int id = generateBookID(book_name);
    int shelve = id % 10;
    struct Book* book = NULL;

    for (int i = 0; i < 5; ++i) {
        struct BST* bst = searchBST(rack[shelve][i], id);
        if (bst != NULL) {
            book = searchBook(bst, book_name, author_name);
            if (book != NULL) {
                // Allocate memory for the new user
                struct User* new_user = createUser(user_name);

                // Create a new book node for the user
                struct Book* new_book = createBook(book_name, author_name, id, shelve);
                new_user->book = new_book;

                // Add the user to the user list
                if (start == NULL) {
                    start = new_user;
                } else {
                    struct User* temp = start;
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = new_user;
                }

                // Delete the book from the library
                deleteBook(book_name, author_name);
                
                return 1;
            }
        }
    }

    printf("Book Not Found");
    return 0;
}

int returnBook(char* user_name, char* book_name) {
    // searching username in list
    struct User* user = start;
    struct User* prev_user = start;
    while (user != NULL) {
        prev_user = user;
        if (strcmp(user->name, user_name) == 0) break;
        user = user->next;
    }

    // If user exists
    if (user != NULL) {
        // Searching book
        struct Book* book = user->book;

        // If book exists
        if (book != NULL && strcmp(book->name, book_name) == 0) {

            // If there is only one book in user
            if (user->book == book) {
                addBook(book->rack, book_name, book->author);
                user->book = NULL;
                free(book);

                // If the user is the root
                if (user == start) {
                    if (start->next != NULL) {
                        start = start->next;
                    } else {
                        start = NULL;
                    }
                } else {
                    prev_user->next = user->next;
                    free(user);
                }
                return 1;
            }
        } else {
            printf("\nBook not Found");
        }
    } else {
        printf("User Doesn't Exist");
    }
    return 0;
}


void displayIssuedBooks() {
    struct User* user = start;
    while (user != NULL) {
        struct Book* book = user->book;

        // Books
        while (book != NULL) {
            printf("Username : %-15sBook name : %-15s Author Name : %-15s \n", user->name, book->name, book->author);
            book = book->next;
        }

        user = user->next;
    }
}