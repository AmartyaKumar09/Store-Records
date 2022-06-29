#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Store_Details
{
    char name[50], price[20];
    int id_num;
}s;

void optionSelecter(int number);
void inputData();
void checkprices();
void editprices();
void deleteData();
void delay(unsigned int mseconds);
int main()
{
    int select;
    system("cls");
    while (1)
    {
        printf("\t\tWELCOME TO STORE DATABASE\n\n");
        printf("\tSELECT ONE OF THE OPTION FROM THIS [1-5]\n");
        printf("\t[1] Input Product Data\n");
        printf("\t[2] Check prices\n");
        printf("\t[3] Edit price\n");
        printf("\t[4] Delete Data\n");
        printf("\t[5] Exit\n\n");
        printf("\t Select one of the option provided above : ");
        scanf("%d", &select);
        optionSelecter(select);
    }
    return 0;
}

void inputData()
{
    system("cls");
    
    FILE *fp = fopen("database.csv", "a+");

    if (!fp)
    {
        printf("Can't open file\n");
    }

    

    printf("\tProduct Name : ");
    scanf("%s", s.name);
    printf("\tProduct ID Number : ");
    scanf("%d",&s.id_num);
    printf("\tProduct price: ");
    scanf("%s", &s.price);
    

    fprintf(fp, "%s, %s, %d\n", s.name,s.price,s.id_num);
    system("cls");
    printf("\tSuccessfully saved data!");
    fclose(fp);
    delay(2000);
    system("cls");
}

void checkprices()
{
    system("cls");
    FILE *fp = fopen("database.csv", "a+");

    if (!fp)
    {
        printf("Can't open file\n");
    }

    printf("\tEnter Product ID Number to view the price : ");
    scanf("%d",&s.id_num);

    char buffer[1024];

    int row = 0;
    int column = 0;
    int flag = 0;

    while (fgets(buffer, 1024, fp))
    {
        column = 0;
        row++;

        if (row == 0)
        {
            continue;
        }

        char *value = strtok(buffer, ", ");
        char nameStore[50];
        char priceStore[20];
        int idStore;
        while (value)
        {

            if (column == 0)
            {
                strcpy(nameStore, value);
            }
            if (column == 1)
            {
                strcpy(priceStore, value);
            }
            if (column == 2)
            {
                idStore = atoi(value);
                if (idStore == s.id_num)
                {
                    flag = 1;
                    printf("\n\tProduct Name : %s\n",nameStore);
                    printf("\tProduct price : %s\n\n",priceStore);
                    break;
                    break;
                }
            }
            value = strtok(NULL, ", ");
            column++;
        }
    }
    if (flag != 1)
    {
        printf("\tData not found!\n\n");
    }
    fclose(fp);
    delay(2000);
}

void editprices()
{
    system("cls");
    FILE *fp = fopen("database.csv", "a+");
    FILE *fp1 = fopen("temp.csv","a+");

    if (!fp)
    {
        printf("Can't open file\n");
    }

    printf("\tEnter product ID number to edit price: ");
    scanf("%d", &s.id_num);

    char buffer[1024];

    int row = 0;
    int column = 0;
    int flag = 0;
    while (fgets(buffer, 1024, fp))
    {
        column = 0;
        row++;

        if (row == 0)
        {
            continue;
        }

        char *value = strtok(buffer, ", ");
        char nameStore[50];
        char priceStore[20];
        int idStore;
        while (value)
        {
            if (column == 0)
            {
                strcpy(nameStore, value);
            }

            if (column == 1)
            {
                strcpy(priceStore, value);
            }

            if (column == 2)
            {
                idStore = atoi(value);
                if (idStore==s.id_num)
                {
                    flag = 1;
                    printf("\tEnter New price: ");
                    char newprice[20];
                    scanf("%s",newprice);
                    fprintf(fp1, "%s, %s, %s",nameStore,newprice,value);
                    printf("\tEdited Succesfully!\n\n");
                }
                else
                {
                    fprintf(fp1, "%s, %s, %s", nameStore,priceStore,value);
                }
            }
            value = strtok(NULL, ", ");
            column++;
        }
    }
    if (flag != 1)
    {
        printf("\tData not found!\n\n");
    }
    fclose(fp);
    fclose(fp1);
    remove("database.csv");
    rename("temp.csv","database.csv");
    delay(2000);
    
}

void deleteData()
{
    system("cls");
    printf("\t*THIS CANNOT BE UNDONE!!!*\n\n");
    FILE *fp = fopen("database.csv", "a+");
    FILE *fp1 = fopen("temp.csv","a+");

    if (!fp)
    {
        printf("Can't open file\n");
    }

    printf("\tEnter product ID number to delete data: ");
    scanf("%d", &s.id_num);

    char buffer[1024];

    int row = 0;
    int column = 0;
    int flag = 0;
    while (fgets(buffer, 1024, fp))
    {
        column = 0;
        row++;

        if (row == 0)
        {
            continue;
        }

        char *value = strtok(buffer, ", ");
        char nameStore[50];
        char priceStore[20];
        int idStore;
        while (value)
        {
            if (column == 0)
            {
                strcpy(nameStore, value);
            }

            if (column == 1)
            {
                strcpy(priceStore, value);
            }

            if (column == 2)
            {
                idStore = atoi(value);
                if (idStore==s.id_num)
                {
                    flag = 1;
                    printf("\tDeleted Succesfully!\n\n");
                    delay(2500);
                }
                else
                {
                    fprintf(fp1, "%s, %s, %s", nameStore,priceStore,value);
                }
            }
            value = strtok(NULL, ", ");
            column++;
        }
    }
    if (flag != 1)
    {
        printf("\n\tData not Found!");
    }
    fclose(fp);
    fclose(fp1);
    remove("database.csv");
    rename("temp.csv","database.csv");
    delay(2000);
    
}

void optionSelecter(int number)
{
    switch (number)
    {
    case 1:
        inputData();
        break;
    case 2:
        checkprices();
        break;
    case 3:
        editprices();
        break;
    case 4:
        deleteData();
        break;
    case 5:
        system("cls");
        printf("\n\tHave a Nice Day!!");
        delay(3000);
        system("cls");
        exit(0);
    default:
        printf("\tPlease select the correct number [1-5]\n");
        delay(2000);
        system("cls");
        break;
    }
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
