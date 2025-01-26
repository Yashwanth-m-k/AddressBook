#include "contactfile.h"

int main()
{
    //all function calls should be inside the main 
    //creating structure varible for Addreass Book
    AddressBook addressbook_var;
    //initialize addressbook
    initialize(&addressbook_var);
    


    
    int choice=0,i;
    
    do{
        choice=0;
        printf("\n");
         for(i=0;i<20;i++)
    {
        printf("--");
    }
    printf("\nMenue:\n");
   
    printf("1. Add contact\n2. DeleteContact\n3. SearchContact\n4. Edit Contact\n5. Save Contact\n6. List contact\n7. Exit ");
    printf("\nEnter the choice between 1-7 : ");
    scanf("%d",&choice);
   
     
  
    switch (choice)
    {
        //wrint the cases
        case 1 :
        createContact(&addressbook_var);
        break;
        case 2 :
        deleteContact(&addressbook_var);
        break;
        case 3 :
        searchContact(&addressbook_var);
        break;
        case 4 :
        editContact(&addressbook_var) ;
        break;
        case 5 :
        savecontact(&addressbook_var);
        break;
        case 6 :
        listContacts(&addressbook_var);
        break;
        case 7:
        return 0;
        break;
        default :
        printf("Invalid!!, choose between 1-7\n");
    }
    }while(choice >0 && choice <8);
    return 0;

}
 

