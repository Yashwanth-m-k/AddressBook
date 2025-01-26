# AddressBook in C

A simple Address Book application implemented in C. It allows users to store, search, update, and delete contact information (name, phone number, email). The data is stored in a CSV file, and the application can load, save, and modify the contacts.

## Features

- Add new contacts with a name, phone number, and email address.
- Search contacts by name, phone number, or email address.
- Edit existing contact details (name, phone number, email).
- Delete contacts by name, phone number, or email.
- Save and load contact data from a CSV file.
- Display all saved contacts.

## Requirements

- A C compiler (e.g., GCC).
- A text editor or IDE for C development (e.g., Visual Studio Code, Code::Blocks, etc.).

## Files

- `addressbook.c`: The main source code of the AddressBook application.
- `contactfile.h`: Header file defining the `AddressBook` structure and function prototypes.
- `contact.csv`: A CSV file where the contacts are saved and loaded from.

## Compilation and Execution

1. Clone or download the repository to your local machine.
2. Open the project folder in your terminal/command prompt.
3. Compile the code using the following command (if you're using GCC):
   ```bash
   gcc addressbook.c -o addressbook
Add Contact: Allows you to add a new contact.
Delete Contact: Allows you to delete a contact by name, phone, or email.
Search Contact: Allows you to search for a contact by name, phone number, or email.
Edit Contact: Allows you to edit a contact's information.
Save Contacts: Saves the current list of contacts to the CSV file.
List Contacts: Displays all contacts currently saved in the AddressBook.
Exit: Exits the program.
