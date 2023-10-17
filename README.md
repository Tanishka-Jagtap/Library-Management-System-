# Library Management System Using Binary Search Tree

  This C program presents a Library Management System (LMS) that effectively manages a library's book collections and user interactions. The project leverages various data structures, including arrays for book IDs and racks, as well as structs for Book, BST (Binary Search Tree), and User. Functionality encompasses adding and deleting books, issuing and returning books to users, and displaying issued books. The system efficiently organizes books using a BST and allows users to perform actions such as adding, deleting, searching for books, and managing user accounts. Additionally, it includes functionalities to load initial library data from a file and to handle book IDs and rack allocation using suitable algorithms.

# Features 

- **Display All Books** - Display all books in the library organized by racks and shelves.
- **Insert a Book** - Add a new book to the library, specifying the book's name, author, and category.
- **Delete a Book** - Remove a book from the library based on its name and author.
- **Search Book By Name** - Search for a book in the library based on its name and display relevant information.
- **Issue Book** - Allow users to borrow a book by specifying their username and the book's name and author.
- **Return Book** - Enable users to return a borrowed book by specifying their username and the book's name.
- **Display Issued Books** - Display a list of books that have been issued to users.
- **Auto-Generated Book IDs** - Automatically generate unique book IDs based on book names.
- **Book Categorization** - Categorize books into different genres or categories for easier organization.
- **User Management** - Create and manage user accounts, associating each user with their borrowed books.
- **Library Data Initialization** - Load initial library data from a file to populate the system with book information.
- **Efficient Data Structures** - Utilize data structures like Binary Search Trees (BSTs) and Queues to optimize data storage and retrieval.

# Usage

1. Compile the program using a C compiler (e.g., GCC):

   ```bash
   gcc library_system.c -o library_system.exe
   ```

2. Run the program:

   ```bash
   ./library_system.exe
   ```

3. Follow the on-screen menu to perform various operations.

# Menu Options

1. **Display All Books** - Allows the user to display all books stored in the library, organized by racks and shelves.
2. **Insert a Book** - Enables the user to add a new book to the library by providing the book's name, author, and selecting the appropriate category.
3. **Delete a Book** - Allows the user to remove a book from the library by providing the book's name and author.
4. **Search Book By Name** - Enables the user to search for a book by providing its name. It displays book information if found.
5. **Issue Book** - Allows the user to borrow a book by providing their name, the book's name, and the author's name.
6. **Return Book** - Allows the user to return a previously borrowed book by providing their name and the book's name.
7. **Display Issued Books** - Displays a list of issued books along with the corresponding user information.
8. **Exit** - Allows the user to exit the program and close the application.

# Usage

```plaintext
++++++++++     M E N U     ++++++++++
0. Exit
1. Display All Books
2. Insert a Book
3. Delete a Book
4. Search Book By Name
5. Issue Book
6. Return Book
7. Display Issued Books

Select an option : 1



++++++++++     D I S P L A Y     ++++++++++

+++++   R A C K - 1   +++++

+++ S H E L V E - 1 +++

+++ S H E L V E - 2 +++
Book ID = 104109121  Amount = 1          Book Name = Ordinary Differential Equations Author Name = Qamar Hussain
Book ID = 104109121  Amount = 1          Book Name = Ordinary Differential Equations Author Name = Mubarak Ali

+++ S H E L V E - 3 +++
Book ID = 92         Amount = 1          Book Name = Calculus                       Author Name = Mubarak Ali
Book ID = 112        Amount = 1          Book Name = Mathematics                    Author Name = Shahid Mehmood
Book ID = 112        Amount = 4          Book Name = Mathematics                    Author Name = Qamar Hussain
Book ID = 7592       Amount = 1          Book Name = Multi Calculus                 Author Name = Mubarak Ali
Book ID = 16235112   Amount = 1          Book Name = Introduction to Mathematics    Author Name = Shahid Mehmood

+++ S H E L V E - 4 +++

+++ S H E L V E - 5 +++

+++ S H E L V E - 6 +++

+++ S H E L V E - 7 +++
Book ID = 5946       Amount = 3          Book Name = Linear Algebra                 Author Name = Shahid Mehmood

+++ S H E L V E - 8 +++

+++ S H E L V E - 9 +++
Book ID = 34108      Amount = 1          Book Name = Basic Geometry                 Author Name = Shahid Mehmood

+++ S H E L V E - 10 +++
Book ID = 139        Amount = 1          Book Name = Statistics                     Author Name = Shahid Mehmood

+++++   R A C K - 2   +++++

+++ S H E L V E - 1 +++
Book ID = -944758060 Amount = 1          Book Name = Introduction to Computer Technology Author Name = Shahid Mehmood
Book ID = 131130     Amount = 4          Book Name = Programming Fundamentals       Author Name = Shahid Mehmood

+++ S H E L V E - 2 +++
Book ID = 9090131    Amount = 2          Book Name = Oriented Oriented Programming  Author Name = Shahid Mehmood
Book ID = 16235111   Amount = 3          Book Name = Introduction to Computer       Author Name = Shahid Mehmood

+++ S H E L V E - 3 +++

+++ S H E L V E - 4 +++

+++ S H E L V E - 5 +++

+++ S H E L V E - 6 +++

+++ S H E L V E - 7 +++

+++ S H E L V E - 8 +++

+++ S H E L V E - 9 +++

+++ S H E L V E - 10 +++

+++++   R A C K - 3   +++++

+++ S H E L V E - 1 +++

+++ S H E L V E - 2 +++

+++ S H E L V E - 3 +++

+++ S H E L V E - 4 +++

+++ S H E L V E - 5 +++

+++ S H E L V E - 6 +++

+++ S H E L V E - 7 +++

+++ S H E L V E - 8 +++

+++ S H E L V E - 9 +++

+++ S H E L V E - 10 +++

+++++   R A C K - 4   +++++

+++ S H E L V E - 1 +++

+++ S H E L V E - 2 +++

+++ S H E L V E - 3 +++

+++ S H E L V E - 4 +++

+++ S H E L V E - 5 +++

+++ S H E L V E - 6 +++

+++ S H E L V E - 7 +++

+++ S H E L V E - 8 +++

+++ S H E L V E - 9 +++

+++ S H E L V E - 10 +++

+++++   R A C K - 5   +++++

+++ S H E L V E - 1 +++

+++ S H E L V E - 2 +++

+++ S H E L V E - 3 +++

+++ S H E L V E - 4 +++

+++ S H E L V E - 5 +++

+++ S H E L V E - 6 +++

+++ S H E L V E - 7 +++

+++ S H E L V E - 8 +++

+++ S H E L V E - 9 +++

+++ S H E L V E - 10 +++



++++++++++     M E N U     ++++++++++
0. Exit
1. Display All Books
2. Insert a Book
3. Delete a Book
4. Search Book By Name
5. Issue Book
6. Return Book
7. Display Issued Books

Select an option : 2



++++++++++     I N S E R T     ++++++++++
0. Back
1. Mathematics
2. Computer
3. Physics
4. Islamiat
5. Others

Select an option : 3

Book Name : Atomic Theory

Author Name : Dalton



++++++++++     M E N U     ++++++++++
0. Exit
1. Display All Books
2. Insert a Book
3. Delete a Book
4. Search Book By Name
5. Issue Book
6. Return Book
7. Display Issued Books

Select an option : 1



++++++++++     D I S P L A Y     ++++++++++

+++++   R A C K - 1   +++++

+++ S H E L V E - 1 +++

+++ S H E L V E - 2 +++
Book ID = 104109121  Amount = 1          Book Name = Ordinary Differential Equations Author Name = Qamar Hussain
Book ID = 104109121  Amount = 1          Book Name = Ordinary Differential Equations Author Name = Mubarak Ali

+++ S H E L V E - 3 +++
Book ID = 92         Amount = 1          Book Name = Calculus                       Author Name = Mubarak Ali
Book ID = 112        Amount = 1          Book Name = Mathematics                    Author Name = Shahid Mehmood
Book ID = 112        Amount = 4          Book Name = Mathematics                    Author Name = Qamar Hussain
Book ID = 7592       Amount = 1          Book Name = Multi Calculus                 Author Name = Mubarak Ali
Book ID = 16235112   Amount = 1          Book Name = Introduction to Mathematics    Author Name = Shahid Mehmood

+++ S H E L V E - 4 +++

+++ S H E L V E - 5 +++

+++ S H E L V E - 6 +++

+++ S H E L V E - 7 +++
Book ID = 5946       Amount = 3          Book Name = Linear Algebra                 Author Name = Shahid Mehmood

+++ S H E L V E - 8 +++

+++ S H E L V E - 9 +++
Book ID = 34108      Amount = 1          Book Name = Basic Geometry                 Author Name = Shahid Mehmood

+++ S H E L V E - 10 +++
Book ID = 139        Amount = 1          Book Name = Statistics                     Author Name = Shahid Mehmood

+++++   R A C K - 2   +++++

+++ S H E L V E - 1 +++
Book ID = -944758060 Amount = 1          Book Name = Introduction to Computer Technology Author Name = Shahid Mehmood
Book ID = 131130     Amount = 4          Book Name = Programming Fundamentals       Author Name = Shahid Mehmood

+++ S H E L V E - 2 +++
Book ID = 9090131    Amount = 2          Book Name = Oriented Oriented Programming  Author Name = Shahid Mehmood
Book ID = 16235111   Amount = 3          Book Name = Introduction to Computer       Author Name = Shahid Mehmood

+++ S H E L V E - 3 +++

+++ S H E L V E - 4 +++

+++ S H E L V E - 5 +++

+++ S H E L V E - 6 +++

+++ S H E L V E - 7 +++

+++ S H E L V E - 8 +++

+++ S H E L V E - 9 +++

+++ S H E L V E - 10 +++

+++++   R A C K - 3   +++++

+++ S H E L V E - 1 +++

+++ S H E L V E - 2 +++
Book ID = 6191       Amount = 1          Book Name = Atomic Theory                  Author Name =     Dalton

+++ S H E L V E - 3 +++

+++ S H E L V E - 4 +++

+++ S H E L V E - 5 +++

+++ S H E L V E - 6 +++

+++ S H E L V E - 7 +++

+++ S H E L V E - 8 +++

+++ S H E L V E - 9 +++

+++ S H E L V E - 10 +++

+++++   R A C K - 4   +++++

+++ S H E L V E - 1 +++

+++ S H E L V E - 2 +++

+++ S H E L V E - 3 +++

+++ S H E L V E - 4 +++

+++ S H E L V E - 5 +++

+++ S H E L V E - 6 +++

+++ S H E L V E - 7 +++

+++ S H E L V E - 8 +++

+++ S H E L V E - 9 +++

+++ S H E L V E - 10 +++

+++++   R A C K - 5   +++++

+++ S H E L V E - 1 +++

+++ S H E L V E - 2 +++

+++ S H E L V E - 3 +++

+++ S H E L V E - 4 +++

+++ S H E L V E - 5 +++

+++ S H E L V E - 6 +++

+++ S H E L V E - 7 +++

+++ S H E L V E - 8 +++

+++ S H E L V E - 9 +++

+++ S H E L V E - 10 +++



++++++++++     M E N U     ++++++++++
0. Exit
1. Display All Books
2. Insert a Book
3. Delete a Book
4. Search Book By Name
5. Issue Book
6. Return Book
7. Display Issued Books

Select an option : 3



++++++++++     D E L E T E     ++++++++++

Enter Book Name : Atomic Theory

Enter Author Name : Dalton        


Successfully Deleted


++++++++++     M E N U     ++++++++++
0. Exit
1. Display All Books
2. Insert a Book
3. Delete a Book
4. Search Book By Name
5. Issue Book
6. Return Book
7. Display Issued Books

Select an option : 1



++++++++++     D I S P L A Y     ++++++++++

+++++   R A C K - 1   +++++

+++ S H E L V E - 1 +++

+++ S H E L V E - 2 +++
Book ID = 104109121  Amount = 1          Book Name = Ordinary Differential Equations Author Name = Qamar Hussain
Book ID = 104109121  Amount = 1          Book Name = Ordinary Differential Equations Author Name = Mubarak Ali

+++ S H E L V E - 3 +++
Book ID = 92         Amount = 1          Book Name = Calculus                       Author Name = Mubarak Ali
Book ID = 112        Amount = 1          Book Name = Mathematics                    Author Name = Shahid Mehmood
Book ID = 112        Amount = 4          Book Name = Mathematics                    Author Name = Qamar Hussain
Book ID = 7592       Amount = 1          Book Name = Multi Calculus                 Author Name = Mubarak Ali
Book ID = 16235112   Amount = 1          Book Name = Introduction to Mathematics    Author Name = Shahid Mehmood

+++ S H E L V E - 4 +++

+++ S H E L V E - 5 +++

+++ S H E L V E - 6 +++

+++ S H E L V E - 7 +++
Book ID = 5946       Amount = 3          Book Name = Linear Algebra                 Author Name = Shahid Mehmood

+++ S H E L V E - 8 +++

+++ S H E L V E - 9 +++
Book ID = 34108      Amount = 1          Book Name = Basic Geometry                 Author Name = Shahid Mehmood

+++ S H E L V E - 10 +++
Book ID = 139        Amount = 1          Book Name = Statistics                     Author Name = Shahid Mehmood

+++++   R A C K - 2   +++++

+++ S H E L V E - 1 +++
Book ID = -944758060 Amount = 1          Book Name = Introduction to Computer Technology Author Name = Shahid Mehmood
Book ID = 131130     Amount = 4          Book Name = Programming Fundamentals       Author Name = Shahid Mehmood

+++ S H E L V E - 2 +++
Book ID = 9090131    Amount = 2          Book Name = Oriented Oriented Programming  Author Name = Shahid Mehmood
Book ID = 16235111   Amount = 3          Book Name = Introduction to Computer       Author Name = Shahid Mehmood

+++ S H E L V E - 3 +++

+++ S H E L V E - 4 +++

+++ S H E L V E - 5 +++

+++ S H E L V E - 6 +++

+++ S H E L V E - 7 +++

+++ S H E L V E - 8 +++

+++ S H E L V E - 9 +++

+++ S H E L V E - 10 +++

+++++   R A C K - 3   +++++

+++ S H E L V E - 1 +++

+++ S H E L V E - 2 +++

+++ S H E L V E - 3 +++

+++ S H E L V E - 4 +++

+++ S H E L V E - 5 +++

+++ S H E L V E - 6 +++

+++ S H E L V E - 7 +++

+++ S H E L V E - 8 +++

+++ S H E L V E - 9 +++

+++ S H E L V E - 10 +++

+++++   R A C K - 4   +++++

+++ S H E L V E - 1 +++

+++ S H E L V E - 2 +++

+++ S H E L V E - 3 +++

+++ S H E L V E - 4 +++

+++ S H E L V E - 5 +++

+++ S H E L V E - 6 +++

+++ S H E L V E - 7 +++

+++ S H E L V E - 8 +++

+++ S H E L V E - 9 +++

+++ S H E L V E - 10 +++

+++++   R A C K - 5   +++++

+++ S H E L V E - 1 +++

+++ S H E L V E - 2 +++

+++ S H E L V E - 3 +++

+++ S H E L V E - 4 +++

+++ S H E L V E - 5 +++

+++ S H E L V E - 6 +++

+++ S H E L V E - 7 +++

+++ S H E L V E - 8 +++

+++ S H E L V E - 9 +++

+++ S H E L V E - 10 +++



++++++++++     M E N U     ++++++++++
0. Exit
1. Display All Books
2. Insert a Book
3. Delete a Book
4. Search Book By Name
5. Issue Book
6. Return Book
7. Display Issued Books

Select an option : 4



++++++++++     S E A R C H     ++++++++++

Enter Book Name : Linear Algebra

Book name : Linear Algebra       ID : 5946   Rack: 1  Shelve: 7  Author Name: Shahid Mehmood


++++++++++     M E N U     ++++++++++
0. Exit
1. Display All Books
2. Insert a Book
3. Delete a Book
4. Search Book By Name
5. Issue Book
6. Return Book
7. Display Issued Books

Select an option : 5



++++++++++     I S S U E     ++++++++++

Enter User Name : Shruti

Enter Book Name : Linear Algebra

Enter Author Name : Shahid Mehmood


Book issued successfully!



++++++++++     M E N U     ++++++++++
0. Exit
1. Display All Books
2. Insert a Book
3. Delete a Book
4. Search Book By Name
5. Issue Book
6. Return Book
7. Display Issued Books

Select an option : 7



++++++++++     I S S U E D   B O O K S     ++++++++++
Username : Shruti         Book name : Linear Algebra  Author Name : Shahid Mehmood



++++++++++     M E N U     ++++++++++
0. Exit
1. Display All Books
2. Insert a Book
3. Delete a Book
4. Search Book By Name
5. Issue Book
6. Return Book
7. Display Issued Books

Select an option : 6



++++++++++     R E T U R N     ++++++++++

Enter User Name : Shruti

Enter Book Name : Linear Algebra


Book returned successfully!



++++++++++     M E N U     ++++++++++
0. Exit
1. Display All Books
2. Insert a Book
3. Delete a Book
4. Search Book By Name
5. Issue Book
6. Return Book
7. Display Issued Books

Select an option : 0
```

