#ifndef CONTACTFILE_H
#define CONTACTFILE_H

#define MAX_CONTACTS 100

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

//addressBook is structure pointer
void createContact(AddressBook *addressBook);
int searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void storcontact(AddressBook *addressBook);
void savecontact(AddressBook *addressBook);
void numrepeat(char str[],AddressBook *addressBook);
void emailrepeat(char str[],AddressBook *addressBook);
int  namesreach(AddressBook *addressBook,char str[],int *count);
int numbersearch(AddressBook *addressBook,char str[]);
int searchemail(AddressBook *addressBook,char str[]);
void numvalid(char temp[]);
void is_emailvalid(char str[]);

#endif
