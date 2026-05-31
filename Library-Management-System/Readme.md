# Library Management System (C++)

A simple Library Management System built in C++ using file handling.

This project was created to practice C++ concepts such as structures, functions, file handling, string streams, and data management.

## Features

 Add new books
 Prevent duplicate Book IDs
 Display all books in a formatted table
 Issue books
 Return books
 Store data permanently using text files

## Book Information Stored

Each book record contains

 Book ID
 Book Title
 Author Name
 Quantity Available

## Technologies Used

 C++
 File Handling (fstream)
 String Streams (stringstream)
 Structures (struct)
 Functions

## How It Works

### Add Book

Allows the user to enter a book's

 ID
 Title
 Author
 Quantity

The record is saved to `Books.txt`.

### Display Books

Reads all records from the file and displays them in a formatted table.

### Issue Book

 User enters a Book ID.
 The system checks if the book exists.
 If available, quantity is reduced by 1.
 Data is updated using a temporary file.

### Return Book

 User enters a Book ID.
 Quantity is increased by 1.
 Updated data is saved back to the file.

## What I Learned

While building this project, I learned

 Reading and writing files
 Using append mode
 Parsing data using stringstream
 Updating records using temporary files
 Input validation basics
 Organizing programs using functions


## Author

Sid

Built as a learning project while studying C++.
