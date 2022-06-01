#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
//respective header files are included for the program

#define n 10
//Number of entries for the loop
#define cust 20
//Number of vertices
#define edge 100
//Number of edges
//Global variable
int f=5;


//Structure name   : food
//Structure members: fname, price, rating

struct food
{
    char fname[50];
    int price;
    float rating;
};
typedef struct food FOOD;

//Structure type   : nested
//Structure name   : hotel
//Structure members: hname, rating, offer
//                   f - derived from another structure
//                   next - pointer variable

struct hotel
{
   char hname[20];
   int rating;
   int offer;
   int hid;
   FOOD f[10];
   struct hotel *next;
};
typedef struct hotel *HOTEL;


//Structure name   : sort_rating
//Structure members: hname, rating

struct sort_rating
{
    char hname[20];
    int rating;
};
typedef struct sort_rating ST;


//Structure name   : sort_foodprice
//Structure members: fname, price

struct sort_foodprice
{
    char fname[50];
    int price;
};
typedef struct sort_foodprice SF;

//structure to find minimum distance in shortest path function
//structure members : distance ; minimum distance between two points
//                             : node ; destination
struct priority_queue
{
    int distance;
    int node;
};
typedef struct priority_queue pq;

//prototype declaration of all the functions called in the program
void start();
void load();
int login();
int signin();
HOTEL insert_rear(HOTEL);
HOTEL getnode();
int menu();
void display(HOTEL);
HOTEL insert_hotel(HOTEL head);
HOTEL insert_food(HOTEL head);
void sort_foodprice(HOTEL head);
void sort_rating(HOTEL head);
void bestseller(HOTEL head);
void search_food(HOTEL head);
void search_hotel(HOTEL head);
int pattern_search(char text[20],char pattern[20]);
void order_food(HOTEL head);
void track_delivery();
void exiting();



//Function       :  main()
//Description    :  Particular function is called according to the choice entered by the user
//Input parameter:  NULL
//Return Type    :  int

int main()
{
    //call start function
    start();
    printf("\n");

    //call load function
    load();

    //Declare head pointer of the list
    //Assign NULL value to it
    HOTEL head=NULL;

    //Local variable
    int choice;

    //Call the function to load all the data from file to linked list
    head=insert_hotel(head);
    head=insert_food(head);

    //Set up the infinite loop
    while(1)
    {
        //Read the choice from the user
        choice=menu();
        //9 cases are been given and the respective functions are called after recieving
        //input from the user

        switch(choice)
        {
          case 1:exiting();
                 break;

          case 2:display(head);
                 break;

          case 3:sort_rating(head);
                 break;

          case 4:sort_foodprice(head);
                 break;

          case 5:bestseller(head);
                 break;

          case 6:search_food(head);
                 break;

          case 7:search_hotel(head);
                 break;

          case 8:order_food(head);
                 break;

          case 9:track_delivery();
                 break;

        }
    }

    return(0);

    //end of the main function.
}


//Function       :  start()
//Description    :  Display zomato welcome page
//Input parameter:  NULL
//Return Type    :  NULL

void start()
{
    //Local variables
   int x;
   double y;
   char alphabet1[]="\n\n ZOMATO LOADING... ";
   char alphabet2[]="\n\n \t\t\t\t WELCOME TO ZOMATO ";
   char alphabet3[]="\n\n \t\t\t\t\t\t\t\t CLIMATE CONSCIOUS DELIVERY !!!";
   printf("\n\n");

   //Set up for loop to display each letter of string
    for(x=0; alphabet1[x]!=NULL; x++)
   {
     printf("%c",alphabet1[x]);
      for(y=0; y<=7777777; y++)
      {
      }
   }
   printf("\n\n");
   //Set up for loop to display next line and each letter of string
    for(x=0; alphabet2[x]!=NULL; x++)
   {
     printf("%c",alphabet2[x]);
      for(y=0; y<=7777777; y++)
      {
      }
   }
   printf("\n\n");
   //Set up for loop to display next line and each letter of string
    for(x=0; alphabet3[x]!=NULL; x++)
   {
     printf("%c",alphabet3[x]);
      for(y=0; y<=7777777; y++)
      {
      }
   }
   getch();
   //TEXT ANIMATION ENDS
}


//Function       :  load()
//Description    :  Display login and sign in page for user
//Input parameter:  NULL
//Return Type    :  NULL

void load()
{
    //Local variable
    int choice;

    //Display options for user
    printf("Enter 1 to login\n");
    printf("No account?..");
    printf("Press 2 to create\n");
    //Providing options to create the account and then signup

    //take input from the user
    scanf("%d",&choice);

    //If input satisfies given condition then call login function until he enters correct username and password
    if(choice==1)
    {
        int p;
        p=login();
        //If login fails due to incorrect entry by the user, 2 is returned and login function is recalled
        while(p==2)
            p=login();
         //If login is successful, load function is successfully returned back
        return;
    }

    //If given condition matches with given condition then call signin function until he gives correct username and password
     else if(choice==2)
    {
        int p;
         p=signin();
          //If sign in fails due to invalid or conflicting input, 1 is returned and sign in function is recalled
        while(p==1)
            p=signin();
         //If sign in is successful, login function is called until correct credentials are given
        if(p==2)
        {
            int m;
            //intialise m and calling login function
            m=login();
            //while loop is made run for m being 2
            while(m==2)
            m=login();
        }
        return;
        }
        //end of the function load.
    }


//Function       :  login()
//Description    :  Display  login page for user
//                  User have to enter correct username and password
//                  If it matches the user can perform further operations
//Input parameter:  NULL
//Return Type    :  int

int login()
{
       //Local variables
       char user[10], password[10];
       char name[10],pass[10];
       int flag=0;

       //Tell user to enter username
       //Read username
       printf("\nEnter\n user name: ");
       scanf("%s",user);

       //Tell user to enter password
       //Read password
       printf("\npassword: ");
       scanf("%s",password);

       //Declare file pointer
       //Open file
       FILE *fp;
       fp=fopen("login.txt","r");

       //If unable to open the file display error message
       //exit from the function
        if(fp==NULL)
        {
            printf("File not found\n");
            return 0;
        }

        //Move file pointer till end of the file
        while(!feof(fp))
       {
           //Read each line from the file
           fscanf(fp,"%s %s\n",name,pass);
           //compare user name in the file with user entered name
           if(strcmp(name,user)==0)
           {
            //Check whether password matches or not
             if(strcmp(pass,password)==0)
                {
                   //Set flag to one
                   flag=1;

                   //Display message
                   printf("You have successfully logged in\n");

                   //Close the file
                   fclose(fp);
                    //return 1 for successful execution of login function
                   return 1;
                }
            }
       }

       //If entered data is invalid tell the user to enter data correctly
       if(flag==0)
            {
                printf("Invalid username or password. Enter valid name\n");
                fclose(fp);
                 //if login fails return 2
                return 2;
            }

            //end of the function login.
}


//Function       :  signin()
//Description    :  Display  signin page for user
//                  User have to enter username and password
//                  If it matches with given condition then store the data in the file
//                  Load login page for user
//Input parameter:  NULL
//Return Type    :  int
int signin()
{
    //Local variables
    int flag=0;
    char user[10], password[10];
    char name[10], pass[10];

    //tell user to enter username
    //Read username
    printf("Enter your name: ");
    scanf("%s",user);

    //Display message regarding how password should be
    //Tell user to enter password
    //Read password
    printf("Hint: password is not more than 5 characters\n");
    printf("\nEnter your password: ");
    scanf("%s",password);

    //Check given password is valid or not
    //If condition does not satisfied then tell user to re enter password
    if(strlen(password)>5)
    {
        printf("!!!Password has more than 5 characters!!!\nPlease check once\n");
        return(1);
    }

    //Declare file pointer
    //Open file
    //login.txt file contains user name and corresponding password
    FILE *fp;
    fp=fopen("login.txt","r");

    //If unable to open the file display error message
    //exit from the function
    if(fp==NULL)
      {
         printf("File not found\n");
         return 0;
      }

    //Traverse file pointer till end of the file
    while(!feof(fp))
      {
        //Read each line from the file
        fscanf(fp,"%s %s\n",name,pass);
        if(strcmp(name,user)==0 || strcmp(pass,password)==0)
        {
            //Set flag to one
            flag=1;

            //If new username is already exist in the file tell user to give some other username
            if(strcmp(name,user)==0)
            {
                printf("Username already exists. Enter new name\n");
                fclose(fp);
                return 1;
            }

            //If new password is already exist in the file tell user to give some other password
            else if(strcmp(pass,password)==0)
            {
                printf("Password already exists.enter new password\n");
                fclose(fp);
                return 1;
            }

            //If both username and password already exist in the file tell user to give some other username and password
            else
                {
                    printf("Both username and password already exist. Enter new value\n");
                    fclose(fp);
                    return 1;
                 }
           }

        }

        //If given username and password is valid then write that data into the file
        if(flag==0)
        {
            printf("You have successfully signed in with us.\n");
            fclose(fp);

             //reopening file for adding new user and password to the file
            fp=fopen("login.txt","a");

             //If unable to open the file display error message
            //exit from the function
            if(fp==NULL)
            {
                printf("File not found\n");
                return 0;
            }

            //Write data into the file
            fprintf(fp,"%s %s\n", user, password);

            //Close file
            fclose(fp);
            //returning 2 to indicate successful signing in
            return 2;
        }

        //end of the function signin.
}

//Function       :  menu()
//Description    :  Display available choices and takes input from the user
//Input parameter:  NULL
//Return Type    :  int

int menu()
{
    int choice;
    //Display all available choices
    printf("\nEnter your choice\n");
    printf("1-Exit from the app.\n");
    printf("2-Display all hotel and food availability\n");
    printf("3-Display hotel name based on rating\n");
    printf("4-Display sorted menu of particular hotel\n");
    printf("5-Display bestseller of each hotel\n");
    printf("6-Search for particular food\n");
    printf("7-Search for hotel\n");
    printf("8-Order food\n");
    printf("9-Track delivery\n");
    //Take input from the user
    //store it in the variable 'choice'
    scanf("%d",&choice);

    //Return 'choice' to main function
    return(choice);
}


//Function       :  insert_hotel()
//Description    :  Read all hotel details from the file and store it in the linked list
//Input parameter:  head pointer which is the starting address of linked list
//Return Type    :  Starting address of linked list of type struct hotel

HOTEL insert_hotel(HOTEL head)
{
    //Declare two nodes of type Hotel
    HOTEL t,c;

    //Declare file pointer
    FILE *fp;

    //Open the file
    fp=fopen("hotel.txt","r");

    //If unable to open the file display error message
    //exit from the function
    if(fp==NULL)
    {
        printf("File not found\n");
        return 0;
    }

    //Traverse file pointer from beginning to end of the file
    while(!feof(fp))
    {
        //Create new node
        t=getnode();

        //Read data from the file
        //store it in the newly created node
        fscanf(fp,"%s %d %d %d\n",t->hname,&t->rating,&t->offer,&t->hid);

        //Check whether linked list is empty or not
        //If it is empty then return newly created node as head pointer
        if(head==NULL)
            head=t;

        //If there are already some nodes present then traverse through end of the list
        //attach new node to the last node
        else
        {
            c=head;
            while(c->next!=NULL)
           {
              c=c->next;
           }
            c->next=t;
        }

    }

    //Close the file
    fclose(fp);

    //Return head pointer to the main function
    return(head);
}


//Function       :  insert_food()
//Description    :  Read all food details from the file and store it in the respective nodes of the  linked list
//Input parameter:  head pointer which is the starting address of linked list
//Return Type    :  Starting address of linked list of type struct hotel

HOTEL insert_food(HOTEL head)
{
    //Declare file pointer
    FILE *fp;

    //Local variable
    int i=0;

    //declare two nodes of type HOTEL
    //assign head pointer to one of the node
    HOTEL t,c;
    c=head;

    //Open the file
    fp=fopen("food.txt","r");

    //If unable to open the file display error message
    //exit from the function
    if(fp==NULL)
    {
        printf("File not found\n");
        return 0;
    }

    //Traverse file pointer from beginning to end of the file
    while(!feof(fp)&&i<f)
    {
        //Read data from the file
        //store it in the node
        fscanf(fp,"%s %d %f\n",c->f[i].fname,&c->f[i].price,&c->f[i].rating);
        i++;

        //When all the food items assigned to particular hotel is stored in the first node, move pointer to next node
        if(i==f)
        {
            i=0;
            c=c->next;
        }
     }

     //Close the file
     fclose(fp);

     //Return head pointer to the main function
     return(head);
}


//Function       :  getnode()
//Description    :  dynamically allocates the memory to linked list by creating new node
//Input parameter:  NULL
//Return Type    :  Address of newly created node of type HOTEL

HOTEL getnode()
{
    HOTEL t;


    //Create new node dynamically using malloc function
    t=(HOTEL)malloc(sizeof(struct hotel));

    //If unable to allocate memory display error message
    //exit from function
    if(t==NULL)
    {
        printf("memory is not allocated\n");
        exit(0);
    }

    //Assign NULL to address part of newly created node
    t->next=NULL;

    //Return address of newly created node
    return(t);
    //end of getnode function
}


//Function       :  display()
//Description    :  Display all data stored in linked list
//Input parameter:  head pointer which is the starting address of linked list
//Return Type    :  NULL

void display(HOTEL head)
{
    //Declare node of type HOTEL
    //assign head pointer to that node
    HOTEL t=head;

    //If list is empty display some error message
    //exit from the function
    if(head==NULL)
    {
        printf("list is empty\n");
        exit(0);
    }

    //Traverse the list till end
    // display data stored in each node
    while(t!=NULL)
    {
       printf("**************Hotel %s*************\n",t->hname);
       printf("Hotel rating:%d\n",t->rating);
       printf("Offer:%d\n",t->offer);
       printf("Hotel_id\n\n",t->hid);
       for(int i=0;i<5;i++)
       {
           printf("%d-food name:%s\tprice:%d\trating:%f\n",i+1,t->f[i].fname,t->f[i].price,t->f[i].rating);
       }
       printf("\n");

       //After printing data stored in the node move pointer to next node
       t=t->next;
    }
    //end of the display function.
}


//Function       :  sort_rating()
//Description    :  Sort the hotel deatails based on rating of each hotel using bubble sort.
//                  Display sorted list.
//Input parameter:  head pointer which is the starting address of linked list
//Return Type    :  NULL

void sort_rating(HOTEL head)
{
    // Declare array of type struct sort_rating
    ST a[n],k;

    //Local variable
    int i=0;

    //Declare node of type HOTEL
    // assign head pointer to that node
    HOTEL t=head;

    //If list is empty display some error message
    // exit from the function
    if(head==NULL)
    {
        printf("No hotels in the list\n");
        exit(0);
    }

    //Traverse the list till end
    //Read hotel rating and hotel name from each node and store it in array
    //After storing data from each node increment array index
    //move node pointer to next node
    while(t!=NULL)
    {
      a[i].rating=t->rating;
      strcpy(a[i].hname,t->hname);
      i++;
      t=t->next;
    }

    //Sort the array elements based on rating using bubble sort
    for(i=0;i<=n-2;i++)
    {
       for(int j=0;j<=n-2-i;j++)
            if(a[j].rating<a[j+1].rating)
               {
                 k=a[j];
                 a[j]=a[j+1];
                 a[j+1]=k;
                }
    }

    //Print sorted list of hotel names along with their ratings
    printf("Sorted Hotel names based on rating\n");
    for(i=0;i<n;i++)
    {
        printf("Hotel name: %s\t Rating: %d\n",a[i].hname,a[i].rating);
    }
}


//Function       :  sort_foodprice()
//Description    :  Takes one hotel name from the user
//                  Sort the food list of that hotel based on food price using selection sort
//                  Display sorted list.
//Input parameter:  head pointer which is the starting address of linked list
//Return Type    :  NULL

void sort_foodprice(HOTEL head)
{
    //Declare node of type HOTEL
    // assign head pointer to that node
    HOTEL t=head;

    //Local variable
    char hotel_name[20];
    int i,j,min;
    int l1,l2;

    // Declare array of type struct sort_foodprice
    SF food[5],c;

    //If list is empty display some error message
    //exit from the function
    if(head==NULL)
    {
        printf("No hotel lists in zomato\n");
        return;
    }

    //Tell user to enter hotel name
    //read hotel name
    //store it in the variable
    //Find length of the string
    printf("Enter hotel name\n");
    scanf("%s",hotel_name);
    l1=strlen(hotel_name);

    //Traverse the list till end
    //Search whether user entered hotel name is present in the list or not
    while(t!=NULL)
    {
        //Find length of the string
          l2=strlen(t->hname);

          //Check whether both string length is same
          if(l1==l2)
          {
              i=0;
              while(i<l1)
              {
                  //Convert each letter of both the strings into lower case
                  //Check whether they are equal
                  //If it is equal increment i
                  //Otherwise come out from the while loop
                  if(tolower(t->hname[i])==tolower(hotel_name[i]))
                    i++;
                  else
                    break;
              }
          }

          //If all letters are matching then come out from the for loop
          //Otherwise move pointer to next node
          if(i==l1)
            break;
          t=t->next;
    }

    //If entered hotel name is not found display some error message
    //exit from the function
    if(t==NULL)
    {
        printf("Entered hotel name not found\n");
        return;
    }

    //If hotel name is found, store each food name and its price in the array
    for(i=0;i<f;i++)
    {
       strcpy(food[i].fname,t->f[i].fname);
       food[i].price=t->f[i].price;
    }

    //Sort the array elements based on food price using selection sort
    for(i=0;i<=f-2;i++)
    {
        min=i;
        //initialise i to minimum
        //comparing food price of each with others and sorting
        for(j=i+1;j<f;j++)
        {
            if(food[j].price<food[min].price)
                min=j;
        }
        //swap the variables
        c=food[i];
        food[i]=food[min];
        food[min]=c;
    }

    //print sorted array elements
    printf("------Sorted menu of Hotel %s------\n\n",t->hname);

    for(i=0;i<f;i++)
        printf("Food name:%s\tPrice:%d\n",food[i].fname,food[i].price);
    printf("\n");
    //end of the sorting function.
}


//Function       :  bestseller()
//Description    :  In each node find the food having highest rating
//                  Display that food as bestseller
//Input parameter:  head pointer which is the starting address of linked list
//Return Type    :  NULL

void bestseller(HOTEL head)
{
    //Declare node of type HOTEL
    // assign head pointer to that node
    HOTEL t=head;

    //Local variable
    int max,i;

    //If list is empty display some error message
    //exit from the function
    if(head==NULL)
    {
        printf("No hotels list in zomato\n");
        return;
    }

    printf("\nBestseller of each hotel\n\n");

    //Traverse the list till end
    //In each node find the food having highest rating
    //Display that food name as bestseller of that particular hotel
    //Once the food name is displayed move pointer to next node
    while(t!=NULL)
    {
        max=0;
        for(i=1;i<f;i++)
        {
            if(t->f[i].rating>t->f[max].rating)
                max=i;
        }
        printf("Hotel %s --> %s\t",t->hname,t->f[max].fname);
        for(i=0;i<f;i++)
        {
            if(t->f[i].rating==t->f[max].rating&&i!=max)
                 printf("and %s\t",t->f[i].fname);

        }
        printf("\n");
        t=t->next;
    }

    printf("\n");
    //end of the bestseller function
}


//Function       :  search_food()
//Description    :  User will enter the food name he want to search
//                  Function will search for that food in each node
//                  If food was found in any of the node, display that hotel name and food details
//Input parameter:  head pointer which is the starting address of linked list
//Return Type    :  NULL

void search_food(HOTEL head)
{

    //Declare node of type HOTEL
    // assign head pointer to that node
    HOTEL t=head;

    //Local variables
    char food[50];
    int i,j,count=0,k,l1,l2;

     //If list is empty display some error message
     //exit from the function
    if(head==NULL)
    {
        printf("No hotels list in zomato\n");
        return;
    }

    //Tell user to enter food name he want to search
    //Read the input
    //Find string length
    printf("Enter food name you want to search\n");
    scanf("%s",food);
    l1=strlen(food);

    //Traverse the list till end
    //If the food was found, check whether that was the food having highest rating in that node
    //Display that food name as bestseller of that particular hotel
    //Once the food name is displayed move pointer to next node
    while(t!=NULL)
    {
        //In each node search for the user entered food name
        for(i=0;i<f;i++)
        {
            //Find string length
            l2=strlen(t->f[i].fname);

            //Check whether both string length is same
            if(l1==l2)
            {
                k=0;
                while(k<l1)
                {
                    //Convert each letter of both the strings into lower case
                    //Check whether they are equal
                    //If it is equal increment k
                    //Otherwise come out from the while loop
                    if(tolower(food[k])==tolower(t->f[i].fname[k]))
                        k++;
                     else
                         break;
                }

                //If all letters are matching then check whether that food also has maximum rating or not1xcd
                if(k==l1)
                {
                    count=1;
                    for(j=0;j<f;j++)
                   {
                    if(t->f[i].rating<t->f[j].rating&&j!=i)
                        break;
                   }

                //If the food was found and that also has maximum rating,
                //then display food details along with the tag "BESTSELLER"
                //Otherwise only display food details
                   if(j==f)
                       printf("---Hotel %s---\n%s **BESTSELLER**\nPrice:%d\nRating:%f\n\n",t->hname,t->f[i].fname,t->f[i].price,t->f[i].rating);
                   else
                       printf("---Hotel %s---\n%s\nPrice:%d\nRating:%f\n\n",t->hname,t->f[i].fname,t->f[i].price,t->f[i].rating);
                }
            }
        }
        //Move pointer to next node
        t=t->next;

   }

    //If the entered food name was not found then display some error message
    if(count==0)
        printf("\nEntered food name not found\n");

}


//Function       :  search_hotel()
//Description    :  Search whether there is any hotel name which has user entered pattern using brute force algorithm
//Input parameter:  head pointer which is the starting address of linked list
//Return Type    :  NULL

void search_hotel(HOTEL head)
{
    //Declare node of type HOTEL
    // assign head pointer to that node
    HOTEL t=head;

    //Local variables
    char pattern[20];
    int flag,count=0;

    //If list is empty display some error message
    //exit from the function
    if(head==NULL)
    {
        printf("No hotels list in zomato\n");
        return;
    }

    //Tell user to enter pattern
    //Read the input
    printf("Search or type hotel name here\n");
    scanf("%s",pattern);

    //Traverse till end of the linked list
    printf("***Here is some hotel names matching with your search***\n\n");
    while(t!=NULL)
    {
        //For each hotel name call the function pattern_search
        flag=pattern_search(t->hname,pattern);

        //if flag is one, then display hotel name
        if(flag==1)
            {
                printf("Hotel %s\n",t->hname);
                count=1;
            }

        //Move pointer to next node
        t=t->next;
    }

    //If pattern is not matching with any of the hotel name, then display some error message
    if(count==0)
        printf("Oops!!! No results found :(\n");
}


//Function       :  pattern_search()
//Description    :  Search for the given pattern in the string using brute force alorithm
//Input parameter:  text and pattern to be search
//                  Both are strings
//Return Type    :  integer
//                  returns 1 if pattern is found in the text
//                  otherwise returns -1

int pattern_search(char text[20],char pattern[20])
{
    //Local variables
    int p,q;
    int i,j;

    //Find length of the text and pattern
    p=strlen(text);
    q=strlen(pattern);

    //Search for the pattern in the given text using brute force alorithm
    for(i=0;i<=p-q;i++)
    {
        j=0;
        while(j<q&&tolower(pattern[j])==tolower(text[i+j]))
            j++;

        //Return 1 if pattern is found
        if(j==q)
            return(1);
    }

    //Return -1 if pattern is not found
    return(-1);
}


//Function       :  order_food()
//Description    :  takes input from the user and display final amount to be paid
//Input parameter:  head pointer which is the starting address of linked list
//Return Type    :  NULL

void order_food(HOTEL head)
{
     //Create node of type HOTEL
     //Assign starting address to that node
     HOTEL t=head;

     //Local variables
     int i,k,q,j,id,cid,num;
     char user[20];
     int flag=0,count=0,total_price=0;
     int hl1,hl2,f1,f2,order_no;
     char hotel[20],food[50];

     //Print hotels available in zomato
     printf("Hotels available in zomato:\n");
     sort_rating(head);

     //Tell user to enter hotel name from where he want to order
     //Read hotel name
     //Find length of the string
     printf("Enter hotel name from where you want to order\n");
     scanf("%s",hotel);
     hl1=strlen(hotel);

     //Traverse the list till end to check whether hotel name is present or not
     while(t!=NULL)
     {
           //Find the length of the string
           hl2=strlen(t->hname);

           //Check whether both string length is same
           if(hl1==hl2)
           {
               k=0;

               //Convert each letter of both the strings into lower case
               //Check whether they are equal
               //If it is equal increment k
               //Otherwise come out from the while loop
               while(k<hl1)
               {
                   if(tolower(hotel[k])==tolower(t->hname[k]))
                    k++;
                   else
                    break;
               }

               //If hotel is present then print foods available in that hotel
               //After displaying come out from the list traversal
               //otherwise move pointer to next node
               if(k==hl1)
               {
                   //Set count to one
                   count=1;
                   id=t->hid;
                   printf("\nfoods available in hotel %s\n",t->hname);
                   for(i=0;i<f;i++)
                   {
                     printf("%s\tprice:%d\n",t->f[i].fname,t->f[i].price);
                   }
                   break;
               }
            }
            t=t->next;
     }

     //If hotel is not found, display some message
     //come out from the function
     if(count==0)
     {
         printf("\nHotel %s not found\n",hotel);
         return;
     }

     //If hotel is present then ask user that how many items he wants to order
     //Read the number
     printf("Enter number of Items you want to order\n");
     scanf("%d",&order_no);

     //Check whether the entered number is invalid or not
     if(order_no<=0)
     {
         printf("\n!!!!No items added to your cart!!!!\n");
         return;
     }

     //Otherwise read food name he want to order
     //read the quantity for each food

     for(j=0;j<order_no;j++)
     {
         printf("\nEnter food %d: ",j+1);
         scanf("%s",food);
         printf("\nQuantity: ");
         scanf("%d",&q);

         //Find length of the string
         f1=strlen(food);

         for(i=0;i<f;i++)
         {
             //Find the length of the string
             f2=strlen(t->f[i].fname);

             //If both string length are matching compare each letter of both strings
             if(f1==f2)
             {
                 k=0;

                 //Convert each letter of both the strings into lower case
                 //Check whether they are equal
                 //If it is equal increment k
                 //Otherwise come out from the while loop
                 while(k<f1)
                 {
                     if(tolower(food[k])==tolower(t->f[i].fname[k]))
                        k++;
                     else
                        break;
                 }

                 //If both strings are matching then calculate total price
                 if(k==f1)
                 {
                     total_price=total_price+(q * t->f[i].price);
                 }
                 break;
             }
         }

         //If food is not found print some message
         //Increment flag pointer
         if(i==f)
         {
             printf("\n%s not found\n",food);
             flag++;
         }
     }

     //If flag value matches with no of items ordered then entered items are found
     //Display message which conveys user that no items are added to the cart
     //Then exit from the function
     //Otherwise display total amount to be paid
     if(flag==order_no)
     {
         printf("\nOopss!!! No items added to your cart\n");
         return;
     }
     printf("\n%d items added to your cart\n",order_no);
     printf("\nTotal price= %d\n",total_price);
     printf("Press 1 to confirm your order\n");
     scanf("%d",&num);
     if(num==1)
        {
            printf("Order placed successfully.\n");
            FILE *fp;
            fp=fopen("orders.txt","a");
            printf("Enter username and customer_id\n(customer_id is even number ranging from 0 to 10)\n");
            scanf("%s %d",user,&cid);
            printf("\t\t***************Thankyou for ordering***************\n");
            fprintf(fp,"%s %d %d\n",user, id, cid);
        }

}


//Function       :  track_delivery()
//Description    :  Finds shortest distance from the hotel to customer
//assumption    :   delivery man always follows shortest path
//Input parameter:  NULL
//Return Type    :  NULL
void dijkstra(int **arr,int dist[],int source);
void track_delivery()
{

    char name[20], user[20];
    int hid=0,cid=0,k=0;
    int orderss[100]; //max orders to a hotel should be a constraint
    //Tracking path of the order by taking username as input
    printf("enter your user name to track your delivery\n");
    scanf("%s",name);

    //obtaining 'from' and 'to' points from the orders file with the user name
    FILE *fp;
    fp=fopen("orders.txt","r");
    //open the file
    if(fp==NULL)
    {
        printf("File not found\n");
        return;
    }
    int flag=0,num=0;
    //read the contents from the file
    while(!feof(fp))
    {
        fscanf(fp,"%s %d %d\n",user,&hid,&cid);
        //searching orders of the user and adding hotel_id and customer-id to array
        if(strcmp(user,name)==0)
            {
                flag=1;
                num++;
                orderss[k++]=hid;
                orderss[k++]=cid;}
            }
    fclose(fp);
    //close the file
    //if user not found in the file
    if(flag==0)
    {
        printf("No orders found in this name. Please recheck the name you entered\n");
        return;
    }
    //dynamically allocated memory for adjacency matrix
    int **arr=(int **)malloc(sizeof(int *)*cust);
    for(int i=0;i<cust;i++)
    {
        arr[i]=(int *)malloc(sizeof(int)*cust);
        for(int j=0;j<cust;j++)
            {arr[i][j]=0;}
    }

    //initialize matrix with contents from distance file.
    //file contains values of 'from', 'to' and 'distance' between two points
    int u,v,w;
    //open the file
    fp=fopen("distance.txt","r");
    if(fp==NULL)
    {
        printf("File not found\n");
        return;
    }
    //read the data from the file and store it
    while(!feof(fp))
        {
            fscanf(fp,"%d %d %d\n",&u,&v,&w);
            arr[u][v]=w;
            arr[v][u]=w;
        }
        fclose(fp);
        //close the file

        //initializing distance array
     int dist[cust];
     for(int i=0;i<cust;i++)
        dist[i]=999999;//this large value shows infinity
     int source;

     //printing number of orders under the username
     printf("You have %d order/s\n",num);
     //calling dijkstra function for all the orders of the customers
     int o=1;
     //initialise o to 1
     for(int i=0; i<k-1; i++)
     {
         dijkstra(arr, dist, orderss[i]);
         printf("For order %d",o++);
         printf("\nTotal distance from %d to %d = %d\n",orderss[i], orderss[i+1], dist[orderss[i+1]]);
         i++;
     }
  //end of track_delivery function
}

//function  : front
//description  : function to obtain minimum distance and its point from priority queue
//input parameter  :  priority queue structure, size of queue
//return type  :  struct of priority queue

pq front(pq p[],int nn)
{
    pq temp;
    temp.distance=INT_MAX;

    //for loop to compare and obtain the minimum distance
    for(int i=0;i<nn;i++)
    {

        if(p[i].distance < temp.distance && p[i].distance!=-1)
        {
            temp=p[i];
        }
    }
    return temp;
    //temp structure is returned back to the calling function
}

//function  : dequeue
//description  : function to priority queue
//input parameter  :  priority queue structure, size of queue
//return type  :  NULL

void dequeue(pq p[],int nn)
{
    pq temp=front(p,nn);
    //call for loop to update the queue structure
    for(int i=0;i<nn;i++)
    {
        if(temp.distance==p[i].distance && temp.node==p[i].node)
        {
            p[i].distance=-1;
            p[i].node=-1;
        }
    }
    //end of dequeue function,no return type here
}

//function  : isEmpty
//description  : function to check if the priority queue is empty
//input parameter  :  priority queue structure, size of the queue
//return type  :  int

int isEmpty(pq p[], int nn)
{
    //for loop to check whether each node is empty or not
    for(int i=0;i<nn;i++)
    {
        if(p[i].node!=-1)
        return 0;
    }
    return 1;
    //1 is returned from the isEmpty function to calling function.
}

//function  : dijkstra
//description  : function to obtain minimum distance to all the points from the source point
//input parameter  :  adjacency weight matrix, distance array, source point
//return type  :  NULL

void dijkstra(int **arr,int dist[],int source)
{
    //declare priority queue of suitably maximum size
    pq p[100];
    //initialize queue with -1s
    for(int i=0;i<100;i++)
    {
        p[i].node=-1;
        p[i].distance=-1;
    }
    int l=0;
    //initialize source index of distance array to zero indicating minimum distance from source to itself is zero
    dist[source]=0;
    //initialize priority queue
    p[l].distance=0;
    p[l].node=source;

    //set a loop until priority queue is empty
    while(!isEmpty(p,l+1))
    {
        //call front function to obtain next minimum distance and point from the source
        pq t=front(p,l+1);
        //initialize these values to local variables
        int node=t.node;
        int d=t.distance;
        //delete the item taken from priority queue by calling dequeue function
        dequeue(p,l+1);
        //set a for loop for all the vertices
        for(int i=0;i<cust;i++)
        {
            int curr_dist=d;
            //except for checking the minimum distance from the node itself, check for all the points in the matrix
            if(arr[node][i]!=0)
            {
                //travelled distance and distance from the node are added to next_distance
                int next_distance=curr_dist+arr[node][i];
                //if this new distance is less than the already existing distance between the points
                // assign new minimum to distance array
                if(next_distance<dist[i])
                {
                    dist[i]=next_distance;
                    l=l+1;
                    //update priority queue
                    p[l].distance=next_distance;
                    p[l].node=i;
                }
            }
        }
    }
    //end of the function djisktra
}


//Function       :  exiting()
//Description    :  Display zomato closing page
//Input parameter:  NULL
//Return Type    :  NULL

void exiting()
{
    //Local variables
   int x;
   double y;
   char alphabet1[]="\n\n ZOMATO CLOSING... ";
   char alphabet2[]="\n\n \t\t\t\t THANK YOU FOR CHOOSING US!!! ";
   char alphabet3[]="\n\n \t\t\t\t\t\t\t\t CLIMATE CONSCIOUS DELIVERY !!!";
   printf("\n\n");

   //Set up for loop to display each letter of string
    for(x=0; alphabet1[x]!=NULL; x++)
   {
     printf("%c",alphabet1[x]);
      for(y=0; y<=7777777; y++)
      {
      }
   }
   printf("\n\n");
   //set up for loop to display next line and to print the string
    for(x=0; alphabet2[x]!=NULL; x++)
   {
     printf("%c",alphabet2[x]);
      for(y=0; y<=7777777; y++)
      {
      }
   }

   printf("\n\n");
    //set up for loop to display next line and to print the string
    for(x=0; alphabet3[x]!=NULL; x++)
   {
     printf("%c",alphabet3[x]);
      for(y=0; y<=7777777; y++)
      {
      }
   }
   getch();
   exit(0);
   //end of the exiting function.
}



