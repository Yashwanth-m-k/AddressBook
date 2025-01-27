#include "contactfile.h"
#include<stdio.h>
#include<string.h>

void listContacts(AddressBook *addressBook) 
{ 
  //print all data from the address book 
    
            printf("Name\t\t\tphone\t\t\tEmail\n");
    for(int i=0; i<addressBook->contactCount; i++)
    {
        printf("%d.%-20s%-20s%-20s\n",i+1,addressBook->contacts [i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }  
}

void initialize(AddressBook *addressBook) 
{
    //fatch data from dummycontact to load into addressbook
    addressBook -> contactCount=0;
     storcontact(addressBook);
     //listContacts(addressBook);
}
void storcontact(AddressBook *addressBook)
{   
    FILE *fptr;
    int i;
    fptr = fopen("contact.csv","r");
    if(fptr==NULL)
    {
    perror("ERROR");
    return ;
    }
     fscanf(fptr,"#%d#\n",&addressBook->contactCount);
     for(i=0;i<addressBook->contactCount;i++)
     {
     
    fscanf(fptr,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
     }
     fclose(fptr);
}
void savecontact(AddressBook *addressBook)
{
    FILE *fptr;
    int i;
    fptr = fopen("contact.csv","w");
    if(fptr==NULL)
    {
    perror("ERROR");
    return ;
    }
     fprintf(fptr,"#%d#\n",addressBook->contactCount);
     for(i=0;i<addressBook->contactCount;i++)
     {
     
    fprintf(fptr," %s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
     }
     printf("\n   Contact Saved   \n");
     fclose(fptr);
}

void createContact(AddressBook *addressBook) 
{
    char temp[30];
    char str[20];
    char str1[20];
    int i,count=0;
          for(i=0;i<20;i++)
    {
        printf("--");
    }
        printf("\nEnter the name :");
        scanf(" %s",addressBook->contacts[addressBook->contactCount].name);
  
L1:     numvalid(temp);
        
    for( i=0; i<addressBook->contactCount; i++)
                        {
                             if( strcmp(temp,addressBook->contacts[i].phone)==0)
                             {
                                 printf("Number is already in the list!!");
                                 goto L1;
                                
                             }
                        }
              strcpy(addressBook->contacts[addressBook->contactCount].phone,temp);

 L2:       is_emailvalid(str);
        
    for( i=0; i<addressBook->contactCount; i++)
                        {
                             if( strcmp(str,addressBook->contacts[i].email)==0)
                             {
                                 printf("Email is already in the list!!");
                                 goto L2;
                                
                             }
                        } 
              strcpy(addressBook->contacts[addressBook->contactCount].email,str);
              addressBook-> contactCount++;
}
int searchContact(AddressBook *addressBook) 
{
int choice;
char str[50];
int i,count =0;
char ptr1;
       for(i=0;i<20;i++)
    {
        printf("--");
    }
printf("\n1. Search by name\n2. Search by phone number\n3. Search by email address");
printf("\nEntre the choice : ");
scanf("%d",&choice);
switch(choice)
  {
    case 1:
            printf("\nEnter name : ");
            scanf(" %[^\n]",str);
    for(i=0;i<20;i++)
    {
        printf("--");
    }
            namesreach(addressBook,str,&count);     
    break;
    case 2:
            for(i=0;i<20;i++)
            {
                printf("--");
            }
              
            numbersearch(addressBook,str);
    break;
    case 3:
             for(i=0;i<20;i++)
            {
                printf("--");
            }
              
            searchemail(addressBook,str);
    break;
    default:
            printf("Invalid Choice!!");
    }
}

void editContact(AddressBook *addressBook) 
{
    char strname[50];
    char str1[50];
    char str[50];
    int i,count=0;
    int choice;
            for(i=0;i<20;i++)
            {
                printf("--");
            }    
printf("\n1. Edit name\n2. Edit phone number\n3. Edit email address");
printf("\nEntre the choice : ");
scanf("%d",&choice);
switch(choice)
{
    case 1:
          printf("\nEnter NAME :");
            scanf(" %[^\n]",strname);

          i=namesreach(addressBook,strname,&count);
          
          if(count == 0)
          {
            goto L1;
          }

          if(count > 1)
          {
             for(i=0;i<20;i++)
            {
                printf("--");
            }
                    printf("\n1. Edit By number \n2. Edit by email :");
                    printf("\nEnter the choice to confirm Which contact name to Edit :");
                    scanf("%d",&choice);
                    if(choice ==1)
                    {
                        i=numbersearch(addressBook,str);
                    
                        printf("\nEnter Name to Edit :");
                        scanf(" %[^\n]",str1);
                        strcpy(addressBook->contacts[i].name,str1);
                       printf(" Name Edited successfully  \n");

                    }
                    else if(choice ==2)
                    {
                        i=searchemail(addressBook,str);
                        printf("\nEnter Name to Edit:");
                        scanf(" %[^\n]",str1);
                        strcpy(addressBook->contacts[i].name,str1);
                        printf(" Name Edited successfully  \n");

                    }
                    else{
                        printf("Invalid choice!! Enter 1 or 2");
                    }
            }
          else{
                    printf("\nEnter name a to edit :");
                    scanf(" %[^\n]",str1);
                    strcpy(addressBook->contacts[i].name,str1);
                    printf(" Name Edited successfully  \n");
              }
    L1:
                       
   break;
   case 2:
           i=numbersearch(addressBook,str); 
                numvalid(str1);
                for( i=0; i<addressBook->contactCount; i++)
                        {
                             if( strcmp(str,addressBook->contacts[i].phone)==0)
                             {
                                 printf("Number is already in the list!!");
                                goto back;
                             }
                        }
                strcpy(addressBook->contacts[i].phone,str1);
                printf("\nPhone number Edited Successfully\n");
                 back: 
     break;
     case 3:
                 i=searchemail(addressBook,str);
                
                is_emailvalid(str1);
            for( i=0; i<addressBook->contactCount; i++)
                {
                if( strcmp(str,addressBook->contacts[i].email)==0)
                        {
                        printf("This Email is already in the list!!");
                        goto Next;
                        }
                }
                strcpy(addressBook->contacts[i].email,str1);
               printf("\nEmail  Edited Successfully\n");
               Next:
     break;
     default :
            printf("Invalid choice !!");
}
}
void deleteContact(AddressBook *addressBook) 
{
    char strname[50];
    char str1[50];
    char str[50];
    int i,count= 0;
    int choice;
    for(i=0;i<20;i++)
    {
        printf("--");
    }
   
printf("\n1. Delete by name\n2. Delete by phone number\n3. Delete by email address\n");
printf("\nEntre the choice : ");
scanf("%d",&choice);
switch(choice)
{
    case 1:
          printf("\nEnter NAME :");
            scanf(" %[^\n]",strname);

          i=namesreach(addressBook,strname,&count);
         
          if(count == 1)
          {
            for(int j=i;j<addressBook->contactCount;j++)
             {
            addressBook->contacts[j]=addressBook->contacts[j+1];
             }
            addressBook->contactCount--;
            printf("\nContact Deleted!!\n");
          }
          else if(count == 0)
          {
            goto L1;
          }
          
        if(count>1){
            for(i=0;i<20;i++)
            {
                printf("--");
            }
            printf("\n1 Delete by number \n2 Delete by email :");
            printf("\nEnter the choice to confirm Which contact to Delete :");
        scanf("%d",&choice);
        if(choice == 1)
        {
              i =  numbersearch(addressBook,str);

         for(int j=i;j<addressBook->contactCount;j++)
        {
            addressBook->contacts[j]=addressBook->contacts[j+1];
        }
        addressBook->contactCount--;
        printf("\nContact Deleted!!\n");
        }
        else if(choice == 2)
        {
            i=searchemail(addressBook,str);
      
        for(int j=i;j<addressBook->contactCount;j++)
        {
            addressBook->contacts[j]=addressBook->contacts[j+1];
        }
        addressBook->contactCount--;
        printf("\nContact Deleted!!\n");
        }
        else if(!(choice ==1 || choice ==2))
        {
            printf("Worng choice\n");
        }
        }    
L1:                   
   break;
   case 2:
             i=numbersearch(addressBook,str);
    
             for(int j=i;j<addressBook->contactCount;j++)
        {
            addressBook->contacts[j]=addressBook->contacts[j+1];
        }
        addressBook->contactCount--;
        printf("\nContact Deleted!!");
                  
     break;
     case 3:
                
            i=searchemail(addressBook,str);
                 for(int j=i;j<addressBook->contactCount;j++)
                {
                     addressBook->contacts[j]=addressBook->contacts[j+1];
                     
                }
                 addressBook->contactCount--;
                 printf("\nContact Deleted!!");
     break;
     default :
            printf("Invalid choice !!");
     }
}
void numvalid(char temp[])
{
    int i;
    L1:     printf("\nEnter the phone number :");
            scanf(" %[^\n]",temp);
    
                for(i=0;i<10;i++)
                {
                    if(!(temp[i]>='0'&&temp[i]<='9'))
                    {
                        printf("invalid number!!\n");
                        goto L1;
                    }
                }
         int len= strlen(temp);
                if(len!=10)
                {
                printf("\nInvalid number !!\n");
                goto L1;
                }
                
}
void is_emailvalid(char str[])
{
   int i,count=0;
L2:     printf("\nEnter email address :");
        scanf(" %s",str);
            for( i=0;str[i]!='\0';i++)
            {
             if(str[0]=='@'||str[0]==' ')
                {
                    printf("Invalid email!!\n");
                    goto L2;
                }
            }
             if(strstr(str,".com")==NULL)
                {
                     printf("Invalid email!!\n");
                     goto L2;
                 }
            if(strstr(str,"@")==NULL)
                {
                    printf("Invalid email!!\n");
                    goto L2;
                }
   
   int len=strlen(str);
  
                for(i=0;str[i]!='\0';i++)
                {
                    if(str[len-1]=='m'&&str[len-2]=='o')
                    {
                        count++;
                        break;
                    }
                }
               
                if(count!=1)
                {
                    printf("invalid Email !!");
                    goto L2;
                } 
}
int  namesreach(AddressBook *addressBook,char str[],int *count)
{
      int i,flag=0,n=0,m;
            char ptr1;
             for( i=0;i<addressBook->contactCount;i++)
            {
             ptr1=strcmp(addressBook->contacts[i].name,str);
                if(ptr1==0&&n==0)
                {

                    printf("\nName :%s\nPhone No : %s\nEmail :%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    flag =  1;
                    *count=*count+1;
                    n++;
                    m=i;
                    
                }
                else if(n>=1&&ptr1==0)
                {
                    printf("\nName :%s\nPhone No : %s\nEmail :%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    flag =  1;
                    *count=*count+1;
                }
                
            }
           
            if(flag ==0)
            {
            printf("\nContact not found !!");
                
             }
            return m;
}
int numbersearch(AddressBook *addressBook,char str[])
{
    L1:       numvalid(str);
            int i;
            int ptr2;
            for( i=0;i<addressBook->contactCount;i++)
            {
             ptr2=strcmp(addressBook->contacts[i].phone,str);
               if(ptr2==0)
                {
                    break;
                }
            }
        if(ptr2==0)
            {
                 printf("\nName : %s\nPhone No :%s\nEmail :%s",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            }
        else
            {
            printf("\nContact not found !!");    
                goto L1;   
            }
            return i;
          
}
int searchemail(AddressBook *addressBook,char str[])
{
   L1:  is_emailvalid(str);
    int ptr3,i;
             for( i=0;i<addressBook->contactCount;i++)
            {
             ptr3=strcmp(addressBook->contacts[i].email,str);
               if(ptr3==0)
                {    
                    break;
                }
            }
        if(ptr3==0)
            { 
                printf("\nName : %s\nPhone No :%s\nEmail :%s",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            }
        else
            {
            printf("Contact not found !!");
                goto L1;   
            }
            return i;
}
void numrepeat(char str[],AddressBook *addressBook)
{
    int i;
    for( i=0; i<addressBook->contactCount; i++)
                        {
                             if( strcmp(str,addressBook->contacts[i].phone)==0)
                             {
                                 printf("This Number is already in the list!!");
                                
                             }
                        }

}
void emailrepeat(char str[],AddressBook *addressBook)
{
    int i;
    for( i=0; i<addressBook->contactCount; i++)
           {
           if( strcmp(str,addressBook->contacts[i].email)==0)
                 {
                  printf("This Email is already in the list!!");
                 }
           }

}


