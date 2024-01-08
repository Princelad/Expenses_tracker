/*This program is created by 23CS037 Prince Lad*/

/*
Create an advanced C++ program for tracking daily expenses. The program should allow the user to
input details of expenses. It should display a running total of expenses.
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    FILE *expense, *recent;

    expense = fopen("Expense.txt", "r");
    if (expense == NULL)
    {
        cout << "Error in opening the file." << endl;
        return 1;
    }

    recent = fopen("Recent.txt", "r");
    if (recent == NULL)
    {
        cout << "Error in opening the file." << endl;
        fclose(expense);
        return 2;
    }

    char name1[50];
    int cost, balance, type;

    fscanf(expense, "%d", &balance);

    cout << "Hello, Greetings" << endl
         << "Your current account balance is Rs." << balance << "." << endl;

    fscanf(recent, "%s : %d", name1, &cost);

    cout << "Your last transaction is," << endl;
    cout << "Name : " << name1 << " and cost : " << cost << endl;

    fclose(expense);
    fclose(recent);

    do
    {
        cout << "Enter '1' if you want to add an expense or '0' to enter gain and 2 to exit : " << endl;
        cin >> type;

        if (type < 2)
        {
            expense = fopen("Expense.txt", "w");
            if (expense == NULL)
            {
                cout << "Error in opening the file." << endl;
                return 1;
            }

            recent = fopen("Recent.txt", "w");
            if (recent == NULL)
            {
                cout << "Error in opening the file." << endl;
                fclose(expense);
                return 2;
            }
            
            if (type)
            {
                cout << "Enter the expense name : " << endl;
                cin >> name1;

                cout << "Enter the cost : " << endl;
                cin >> cost;

                balance -= cost;
            }
            else
            {
                cout << "Enter the profit name : " << endl;
                cin >> name1;

                cout << "Enter the gain : " << endl;
                cin >> cost;

                balance += cost;
            }

            fprintf(recent, "%s : %d", name1, cost);
            fprintf(expense, "%d", balance);
        }
    } while (type != 2);

    fclose(expense);
    fclose(recent);

    return 0;
}