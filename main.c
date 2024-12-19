#include <stdio.h>                                                      //Preprocessor directive for standard input/output
#include <stdlib.h>                                                     //Used for standard library functions like exit()
#include <time.h>                                                       //Used for functions related to date and time
#include <string.h>                                                     //For using strcpy()

char movieName[250] , ask;                                              //global variable for char movieName with 250 characters
int c, s, sc, a, price, movieNo;                                        //global variable for int
int totalTiket = 0, discount = 0;                                       //global variable for int with value
float totalPrice = 0 , pricediscount = 0 , totlpricediscount = 0;       //global variable for float with value

// 2D array for movie and price list
char table[5][3][250] =                                                 //global variable in 2D array with 4 row 3 column and 250 characters
{
    {"NUM", "\tTITLE", "\t\tPRICE"},                                    //1st row in array
    {"1", "KAHAR KAPLA HIGH COUNCIL", "RM14"},                          //2nd row in array
    {"2", "JANGAN PANDANG BELAKANG 2", "RM16"},                         //3rd row in array
    {"3", "DONGENG SANG KANCIL", "\tRM13"},                             //4th row in array
    {"4", "EJEN ALI THE MOVIE 2", "\tRM11"}                             //5th row in array
};

// 2D array for tiket type
char tiket[5][3][250] =                                                 //global variable in 2D array with 4 row 3 column and 250 characters
{
    {"TYPE", "\tDISCOUNT"},                                             //1st row in array
    {"CHILDREN", "15%"},                                                //2nd row in array
    {"STUDENT", "\t10%"},                                               //3rd row in array
    {"SENIOR CITIZEN", "20%"},                                          //4th row in array
    {"ADULT", "\t0%"}                                                   //5th row in array
};

void clearscreen()                                                      //clearscreen function
{
    system("cls");                                                      //Clears the screen on Windows
}

void pause()                                                            //Pause function
{
    system("pause");                                                    //Pause the system
}

void display()                                                          //display function
{
    printf("---------------------------------------------\n");          //Print separator line
    printf("      WELCOME TO CINEMA BOOKING TICKETS\n");                //print the header
    // Display the current date
    time_t t;                                                           //Variable to store the current time
    struct tm *lt;                                                      //Pointer to structure for local time
    char date[20];                                                      //String to store formatted date
    time(&t);                                                           //Get the current time
    lt = localtime(&t);                                                 //Convert time to local time structure
    strftime(date, 20, "%d/%m/%Y", lt);                                 //Format the date as DD/MM/YYYY
    printf("\t          %s\n", date);                                   //Print the current date
    printf("                TICKET PRICING\n");                         //Print section header
    printf("---------------------------------------------\n");          //Print separator line
    // Display content in array
    for (int row = 0; row < 5; row++)                                   //count row use for loop
    {
        for (int col = 0; col < 3; col++)                               //count col use for loop
        {
            printf("%s\t", table[row][col]);                            //Print the array in table format
        }
        if(row==0)                                                      //if row = 0 , do
        {
            printf("\n---------------------------------------------");  //Print separator line
        }
        printf("\n");                                                   //Print new line
    }
    printf("---------------------------------------------\n");          //Print separator line
}

void invalid_choice()                                                   //invalid_choice function
{
    clearscreen();                                                      //Call clearscreen function
    printf("---------------------------------------------\n");          //Print separator line
    printf("                 INVALID INPUT");                           //print invalid statement
    printf("\n---------------------------------------------\n");        //Print separator line
    askcontinue();                                                      //call askcontinue function
}

void book_ticket()                                                      //book_ticket function
{
    printf("Choose Movie [1-4]: ");                                     //print the instructions
    scanf("%d", &movieNo);                                              //get input int movieNo
    switch (movieNo)                                                    //use case logic for movieNo
    {
        case 1:                                                         //If movie 1 is selected
            price = 14;                                                 //set price = RM14
            strcpy(movieName, table[1][1]);                             //set movieName = get movieName from array table content
            break;                                                      //exit case
        case 2:                                                         //If movie 2 is selected
            price = 16;                                                 //set price = RM14
            strcpy(movieName, table[2][1]);                             //set movieName = get movieName from array table content
            break;                                                      //exit case
        case 3:                                                         //If movie 3 is selected
            price = 13;                                                 //set price = RM14
            strcpy(movieName, table[3][1]);                             //set movieName = get movieName from array table content
            break;                                                      //exit case
        case 4:                                                         //If movie 4 is selected
            price = 11;                                                 //set price = RM14
            strcpy(movieName, table[4][1]);                             //set movieName = get movieName from array table content
            break;                                                      //exit case
        default:                                                        //If any invalid choice is entered
            invalid_choice();                                           //Call invalid_choice function
            return;                                                     //return statement
    }
    clearscreen();                                                      //Call clearscreen function
    printf("\nYou have selected movie: %s ", movieName);                //Print the selected movie
    printf("\n\n---------------------------------------------\n");      //Print separator line
    // Display content in array
    for (int row = 0; row < 5; row++)                                   //count row use for loop
    {
        for (int col = 0; col < 3; col++)                               //count col use for loop
        {
            printf("%s\t", tiket[row][col]);                            //Print the array in table format
        }
        if(row==0)                                                      //if row = 0 , do
        {
            printf("\n---------------------------------------------");  //Print separator line
        }
        printf("\n");                                                   //Print new line
    }
    printf("---------------------------------------------\n");          //Print separator line
    printf("How many %s tickets ? : ",tiket[1][0]);                     //print the instructions To ask how many tiket for children
    scanf("%d", &c);                                                    //get input int children
    totalTiket = totalTiket + c;                                        //calc totalTiket
    printf("How many %s tickets ? : ",tiket[2][0]);                     //print the instructions To ask how many tiket for student
    scanf("%d", &s);                                                    //get input int student
    totalTiket = totalTiket + s;                                        //calc totalTiket
    printf("How many %s tickets ? : ",tiket[3][0]);                     //print the instructions To ask how many tiket for senior citizen
    scanf("%d", &sc);                                                   //get input int senior citizen
    totalTiket = totalTiket + sc;                                       //calc totalTiket
    printf("How many %s tickets ? : ",tiket[4][0]);                     //print the instructions To ask how many tiket for adult
    scanf("%d", &a);                                                    //get input int adult
    totalTiket = totalTiket + a;                                        //calc totalTiket
    if(c>0)                                                             //if children tiket > 0 do
    {
        pricediscount = (price * 15/100) * c;                           //calc pricediscount
        totlpricediscount += pricediscount;                             //calc totlpricediscount
    }
    if(s>0)                                                             //if student tiket > 0 do
    {
        pricediscount = (price * 10/100) * s;                           //calc pricediscount
        totlpricediscount += pricediscount;                             //calc totlpricediscount
    }
    if(sc>0)                                                            //if senior citizen tiket > 0 do
    {
        pricediscount = (price * 20/100) * sc;                          //calc pricediscount
        totlpricediscount += pricediscount;                             //calc totlpricediscount
    }
    if(a>0)                                                             //if adult tiket > 0 do
    {
        pricediscount = (price * 20/100) * a;                           //calc pricediscount
        totlpricediscount += pricediscount;                             //calc totlpricediscount
    }
    totalPrice = (price * totalTiket) - totlpricediscount;              //calc totalPrice
}

void print_output()                                                     //print_output function
{
    printf("---------------------------------------------\n");          //Print separator line
    printf("               CINEMA TICKET\n");                           //Print header
    printf("---------------------------------------------\n");          //Print separator line
    printf("MOVIE: %s\n", movieName);                                   //Print movie name
    printf("---------------------------------------------\n");          //Print separator line
    if(c>0)                                                             //if children tiket > 0 do
    {
       printf("CHILDREN :\t\t%d\n", c);                                 //Print number of children tickets
    }
    if(s>0)                                                             //if student tiket > 0 do
    {
      printf("STUDENT :\t\t%d\n", s);                                   //Print number of student tickets
    }
    if(sc>0)                                                            //if senior citizen tiket > 0 do
    {
        printf("SENIOR CITIZEN :\t%d\n", sc);                           //Print number of senior citizen tickets
    }
    if(a>0)                                                             //if adult tiket > 0 do
    {
        printf("ADULT :\t\t\t%d\n", a);                                 //Print number of adult tickets
    }
    printf("---------------------------------------------\n");          //Print separator line
    printf("TOTAL TIKCET = %d\n", totalTiket);                          //Print total tickets
    printf("---------------------------------------------\n");          //Print separator line
    printf("PRICE PER TIKCET = RM%d\n", price);                         //Print price per ticket
    printf("DISCOUNT = RM%.2f\n", totlpricediscount);                   //Print total discount
    printf("TOTAL PRICE = RM%.2f\n", totalPrice);                       //Print total price after discount
    printf("---------------------------------------------\n\n\n");      //Print separator line
}

void runall()                                                           //runall function
{
    display();                                                          //Call display function
    book_ticket();                                                      //call book_ticket function
    clearscreen();                                                      //call clearscreen function
    print_output();                                                     //call print_output function
}

void askcontinue()                                                      //askcontinue function
{
    do                                                                  //repeat/until loop
    {
        pause();                                                        //call pause function
        clearscreen();                                                  //call clearscreen function
        printf("ENTER Y TO CONTINUE OR ANYKEY TO EXIT :");              //print the instructions To ask
        scanf(" %c",&ask);                                              //get output char ask
        ask = toupper(ask);                                             //change ask to uppercase
        clearscreen();                                                  //call clearscreen function
        if(ask == 'Y')
        {
            runall();                                                   //call runall function
        }
    }
    while(ask=='Y');                                                    //repeat if ask == 'Y'
    return;                                                             //If ask != 'Y' , return
}

int main()                                                              // Main function
{
    runall();                                                           //Call runall function
    askcontinue();                                                      //call askcontinue function
}
