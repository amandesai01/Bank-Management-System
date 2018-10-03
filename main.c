/*
Author's Name: Tejaswini Ramnath Jagatp
Project Name: Bank Management System
Programming Language: C (ubuntu)
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void menu();

struct date
{
    int month,day,year;
};

struct
{
    char name[40];
    int acc_no, age;
    char address[100], citizenship[50], acc_type[15];
    float amount;
    long int phone;
    struct date dob;
    struct date deposit;
    struct date withdraw;
}add, upd, check, trans, rem;

float interest(float amount, int rate, float time)
{
    float si;
    si = (rate*time*amount)/100;
    return si;
}

void create_acc()
{
    FILE *fp;
    int exit_no;
    fp = fopen("bank_accounts.txt", "a+");
    acc_no:
    printf("*******ADD RECORDS*******\n");
    printf("\nEnter account number: ");
    scanf("%d",&check.acc_no);
    while(fscanf(fp, "%d %s %d/%d/%d %d %s %s %ld %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amount, &add.deposit.month, &add.deposit.day, &add.deposit.year)!=EOF)
    {
        if (check.acc_no == add.acc_no)
        {
            printf("This account number is already in use. Please try a different one.");
            goto acc_no;
        }
    }
    add.acc_no = check.acc_no;
    printf("\nEnter today's date(month day year): ");
    scanf("%d%d%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    printf("\nEnter your name: ");
    scanf("%s", add.name);
    printf("\nEnter date of birth(month day year): ");
    scanf("%d%d%d", &add.dob.month, &add.dob.day, &add.dob.year);
    printf("\nEnter your address: ");
    scanf("%s", add.address);
    printf("\nEnter your age: ");
    scanf("%d", &add.age);
    printf("\nEnter country of your citizenship: ");
    scanf("%s", add.citizenship);
    printf("\nEnter your phone number: ");
    scanf("%ld", &add.phone);
    printf("\nEnter type of account(saving, current, fixed1(for 1 year), fixed2(for 2 year) or fixed3(for 3 year)): ");
    scanf("%s", add.acc_type);
    printf("\nEnter amount to deposit: ");
    scanf("%f", &add.amount);

    fprintf(fp, "%d %s %d/%d/%d %d %s %s %ld %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amount, add.deposit.month, add.deposit.day, add.deposit.year);

    fclose(fp);
    printf("\nAccount created successfully!");
    exit1:
    printf("\nEnter 1 to go back to main menu, 0 to exit: ");
    scanf("%d", &exit_no);
    if (exit_no == 1)
    {
        menu();
    }
    else if(exit_no == 0)
    {
        exit(0);
    }
    else
    {
        printf("\nInvalid");
        goto exit1;
    }
}

void update()
{
    int flag = 0, choice, up_in, exit_no;
    FILE *old_file, *new_file;
    old_file = fopen("bank_accounts.txt", "r");
    new_file = fopen("bank_accounts_new.txt", "w");

    printf("\nEnter account number in which you wish to update information: ");
    scanf("%d", &check.acc_no);

    while(fscanf(old_file, "%d %s %d/%d/%d %d %s %s %ld %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amount, &add.deposit.month, &add.deposit.day, &add.deposit.year)!=EOF)
    {
        if (check.acc_no == add.acc_no)
        {
            flag++;
            printf("What do you want to update:\n1.Address\n2.Phone\nEnter your choice: ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("\nEnter the updated address: ");
                scanf("%s", add.address);
                fprintf(new_file, "%d %s %d/%d/%d %d %s %s %ld %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amount, add.deposit.month, add.deposit.day, add.deposit.year);
            }
            else if (choice == 2)
            {
                printf("\nEnter the updated phone number: ");
                scanf("%ld", &add.phone);
                fprintf(new_file, "%d %s %d/%d/%d %d %s %s %ld %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amount, add.deposit.month, add.deposit.day, add.deposit.year);
            }
            else
            {
                printf("\nInvalid");
                menu();
            }
        }
        else
        {
            fprintf(new_file, "%d %s %d/%d/%d %d %s %s %ld %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amount, add.deposit.month, add.deposit.day, add.deposit.year);
        }
    }
    fclose(old_file);
    fclose(new_file);
    remove("old_file.txt");
    rename("bank_accounts_new.txt", "bank_accounts.txt");

    if(flag!=1)
    {
        printf("\nNo such record found.");
        update_invalid:
        printf("\nEnter 1 to try again, 2 to go back to main menu, 3 to exit: ");
        scanf("%d", &up_in);
        if(up_in == 1)
        {
            update();
        }
        else if(up_in == 2)
        {
            menu();
        }
        else if(up_in == 3)
        {
            exit(0);
        }
        else
        {
            goto update_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go back to main menu, 0 to exit: ");
        scanf("%d", &exit_no);
        if(exit_no == 1)
        {
            menu();
        }
        else
        {
            exit(0);
        }
    }
}

void transaction()
{
    int flag = 0, choice, up_in, exit_no;
    FILE *old_file, *new_file;
    old_file = fopen("bank_accounts.txt", "r");
    new_file = fopen("bank_accounts_new.txt", "w");

    printf("\nEnter account number from which you wish to transact money: ");
    scanf("%d", &check.acc_no);

    while(fscanf(old_file, "%d %s %d/%d/%d %d %s %s %ld %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amount, &add.deposit.month, &add.deposit.day, &add.deposit.year)!=EOF)
    {
        if (check.acc_no == add.acc_no)
        {
            if(strcmp(add.acc_type,"fixed1")==0 || strcmp(add.acc_type, "fixed2")==0 || strcmp(add.acc_type, "fixed3")==0)
            {
                printf("\nNo transactions can be done from fixed accounts.");
                menu();
            }
            else{
                flag++;
                printf("What do you want to do:\n1.Deposit\n2.Withdraw\nEnter your choice: ");
                scanf("%d", &choice);
                if (choice == 1)
                {
                    printf("\nEnter the amount of money you want to deposit: ");
                    scanf("%f", &trans.amount);
                    add.amount += trans.amount;
                    fprintf(new_file, "%d %s %d/%d/%d %d %s %s %ld %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amount, add.deposit.month, add.deposit.day, add.deposit.year);
                }
                else if (choice == 2)
                {
                    printf("\nEnter the amount of money you want to withdraw: ");
                    scanf("%f", &trans.amount);
                    add.amount -= trans.amount;
                    fprintf(new_file, "%d %s %d/%d/%d %d %s %s %ld %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amount, add.deposit.month, add.deposit.day, add.deposit.year);
                }
                else
                {
                    printf("\nInvalid");
                    menu();
                }
            }
        }
        else
        {
            fprintf(new_file, "%d %s %d/%d/%d %d %s %s %ld %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amount, add.deposit.month, add.deposit.day, add.deposit.year);
        }
    }
    fclose(old_file);
    fclose(new_file);
    remove("old_file.txt");
    rename("bank_accounts_new.txt", "bank_accounts.txt");

    if(flag!=1)
    {
        printf("\nNo such record found.");
        update_invalid:
        printf("\nEnter 1 to try again, 2 to go back to main menu, 3 to exit: ");
        scanf("%d", &up_in);
        if(up_in == 1)
        {
            transaction();
        }
        else if(up_in == 2)
        {
            menu();
        }
        else if(up_in == 3)
        {
            exit(0);
        }
        else
        {
            goto update_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go back to main menu, 0 to exit: ");
        scanf("%d", &exit_no);
        if(exit_no == 1)
        {
            menu();
        }
        else
        {
            exit(0);
        }
    }
}

void remove()
{
    int flag = 0, choice, up_in, exit_no;
    FILE *old_file, *new_file;
    old_file = fopen("bank_accounts.txt", "r");
    new_file = fopen("bank_accounts_new.txt", "w");

    printf("\nEnter account number which you wish to remove: ");
    scanf("%d", &rem.acc_no);

    while(fscanf(old_file, "%d %s %d/%d/%d %d %s %s %ld %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amount, &add.deposit.month, &add.deposit.day, &add.deposit.year)!=EOF)
    {
        if (rem.acc_no != add.acc_no)
        {
            fprintf(new_file, "%d %s %d/%d/%d %d %s %s %ld %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amount, add.deposit.month, add.deposit.day, add.deposit.year);
        }
        else
        {
            flag ++;
            printf("\nAccount deleted successfully");
        }
    }
    fclose(old_file);
    fclose(new_file);
    remove("old_file.txt");
    rename("bank_accounts_new.txt", "bank_accounts.txt");

    if(flag==0)
    {
        printf("\nNo such record found.");
        update_invalid:
        printf("\nEnter 1 to try again, 2 to go back to main menu, 3 to exit: ");
        scanf("%d", &up_in);
        if(up_in == 1)
        {
            remove();
        }
        else if(up_in == 2)
        {
            menu();
        }
        else if(up_in == 3)
        {
            exit(0);
        }
        else
        {
            goto update_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go back to main menu, 0 to exit: ");
        scanf("%d", &exit_no);
        if(exit_no == 1)
        {
            menu();
        }
        else
        {
            exit(0);
        }
    }
}

void view_list()
{
    FILE *fp;
    int flag = 0, up_in, exit_no;
    fp = fopen("bank_accounts.txt", "r");
    printf("Account no.\tName\t\tAddress\t\tPhone");
    while(fscanf(fp, "%d %s %d/%d/%d %d %s %s %ld %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amount, &add.deposit.month, &add.deposit.day, &add.deposit.year)!=EOF)
    {
        printf("\n%d\t\t%s\t\t%s\t\t%ld", add.acc_no, add.name, add.address, add.phone);
        flag ++;
    }
    fclose(fp);
    if (flag == 0)
    {
        printf("\nNo records found.");
        update_invalid:
        printf("\nEnter 1 to go back to main menu, 2 to exit: ");
        scanf("%d", &up_in);
        if(up_in == 1)
        {
            menu();
        }
        else if(up_in == 2)
        {
            exit(0);
        }
        else
        {
            goto update_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go back to main menu, 0 to exit: ");
        scanf("%d", &exit_no);
        if(exit_no == 1)
        {
            menu();
        }
        else
        {
            exit(0);
        }
    }
}

void view_one()
{
    FILE *fp;
    int flag, rate, up_in, exit_no;
    float time, intrest;
    fp = fopen("bank_accounts.txt", "r");
    printf("\nEnter the account number of the customer: ");
    scanf("%d", &check.acc_no);
    while(fscanf(fp, "%d %s %d/%d/%d %d %s %s %ld %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amount, &add.deposit.month, &add.deposit.day, &add.deposit.year)!=EOF)
    {
        if(check.acc_no == add.acc_no)
        {
            flag++;
            printf("\nAccount number: %d\nName: %s\nDOB: %d/%d/%d\nAge: %d\nAddress: %s\nCitizenship: %s\nPhone: %ld\nType of account: %s\nAmount deposited: %f\nDate of deposit: %d/%d/%d", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amount,add.deposit.month, add.deposit.day, add.deposit.year);
            if (strcmp(add.acc_type, "fixed1") == 0)
            {
                time = 1;
                rate = 9;
                intrest = interest(add.amount, rate, time);
                printf("\nYou will get $%f as interest on %d/%d/%d", intrest, add.deposit.month, add.deposit.day, add.deposit.year+1);
            }
            else if(strcmp(add.acc_type, "fixed2") == 0)
            {
                time = 2;
                rate = 11;
                intrest = interest(add.amount, rate, time);
                printf("\nYou will get $%f as interest on %d/%d/%d", intrest, add.deposit.month, add.deposit.day, add.deposit.year+2);
            }
            else if(strcmp(add.acc_type, "fixed3") == 0)
            {
                time = 3;
                rate = 13;
                intrest = interest(add.amount, rate, time);
                printf("\nYou will get $%f as interest on %d/%d/%d", intrest, add.deposit.month, add.deposit.day, add.deposit.year+3);
            }
            else if(strcmp(add.acc_type, "saving") == 0)
            {
                time = (1/12);
                rate = 8;
                intrest = interest(add.amount, rate, time);
                printf("\nYou will get $%f as interest on %d of every month", intrest, add.deposit.day);
            }
            else if(strcmp(add.acc_type, "current") == 0)
            {
                printf("\nYou will get no interest");
            }
        }
    }
    fclose(fp);
    if(flag==0)
    {
        printf("\nNo such record found.");
        update_invalid:
        printf("\nEnter 1 to try again, 2 to go back to main menu, 3 to exit: ");
        scanf("%d", &up_in);
        if(up_in == 1)
        {
            view_one();
        }
        else if(up_in == 2)
        {
            menu();
        }
        else if(up_in == 3)
        {
            exit(0);
        }
        else
        {
            goto update_invalid;
        }
    }
    else
    {
        printf("\n\nEnter 1 to go back to main menu, 0 to exit: ");
        scanf("%d", &exit_no);
        if(exit_no == 1)
        {
            menu();
        }
        else
        {
            exit(0);
        }
    }
}

void menu()
{
    int choice;
    printf("\n\n\t\t\t\tWELCOME TO RIT BANK\t\t\t\t\n");
    printf("\nTHIS IS MAIN MENU\n");
    printf("\n1.Create new account\n2.Update information\n3.Transactions\n4.Remove accounts\n5.View individual customer information\n6.View all customer's information\n7.Exit\n\nEnter your choice\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: create_acc();
            break;
        case 2: update();
            break;
        case 3: transaction();
            break;
        case 4: remove();
            break;
        case 5: view_one();
            break;
        case 6: view_list();
            break;
        case 7: exit(0);
            break;
    }
}

int main()
{
    char try_pass[10], password[10] = "ritbank";
    int exit_no;
    printf("\n\nEnter the password to login: ");
    scanf("%s", try_pass);
    if (strcmp(password, try_pass) == 0)
    {
        printf("\nPassword match!");
        menu();
    }
    else
    {
        printf("\n\nWrong password!");
        login_invalid:
        printf("\nEnter 1 to try again and 0 to exit: ");
        scanf("%d", &exit_no);
        if (exit_no == 1)
        {
            main();
        }
        else if (exit_no == 0)
        {
            exit(0);
        }
        else
        {
            printf("\nInvalid");
            goto login_invalid;
        }
    }
}