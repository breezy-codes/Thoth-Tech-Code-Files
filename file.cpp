#include "splashkit.h"
#include <iomanip>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>
#include <vector>
#include <numeric> // Include numeric for std::accumulate
using namespace std;

struct Transaction
{
    string date;
    string type;
    double amount;
    string category;
};

// Function prototypes
void draw_pie_chart(const std::map<string, double> &category_totals);
void fill_sector(color clr, int cx, int cy, int radius, double start_angle, double end_angle);
double predict_future_expense(int future_months);

// Dynamically allocated array and pointer to keep track of transactions
Transaction *transactions = nullptr;
int transaction_count = 0;  // Number of transactions

// Function to dynamically resize the transactions array
void resize_transactions(int new_size)
{
    Transaction *new_transactions = new Transaction[new_size];
    for (int i = 0; i < transaction_count; ++i)
    {
        new_transactions[i] = transactions[i];
    }
    delete[] transactions;
    transactions = new_transactions;
}

// Function to show a message using SplashKit (terminal version)
void show_message(string message)
{
    write_line(message);
}

// Function to get user input using SplashKit (terminal version)
string get_input(string prompt)
{
    write_line(prompt);
    return read_line();
}

// Function to add a transaction
void add_transaction()
{
    resize_transactions(transaction_count + 1);
    Transaction *new_transaction = &transactions[transaction_count];

    new_transaction->date = get_input("Enter date (YYYY-MM-DD): ");
    new_transaction->type = get_input("Enter type (income/expense): ");
    new_transaction->amount = convert_to_double(get_input("Enter amount: "));
    new_transaction->category = get_input("Enter category (e.g., food, rent, utilities): ");

    transaction_count++;
    show_message("Transaction added successfully!");
}

// Function to modify a transaction
void modify_transaction()
{
    int index = convert_to_integer(get_input("Enter the transaction index to modify: "));

    if (index < 0 || index >= transaction_count)
    {
        show_message("Invalid transaction index.");
        return;
    }

    Transaction *transaction = &transactions[index];

    transaction->date = get_input("Enter new date (YYYY-MM-DD): ");
    transaction->type = get_input("Enter new type (income/expense): ");
    transaction->amount = convert_to_double(get_input("Enter new amount: "));
    transaction->category = get_input("Enter new category: ");

    show_message("Transaction modified successfully!");
}

// Function to remove a transaction
void remove_transaction()
{
    int index = convert_to_integer(get_input("Enter the transaction index to remove: "));

    if (index < 0 || index >= transaction_count)
    {
        show_message("Invalid transaction index.");
        return;
    }

    for (int i = index; i < transaction_count - 1; ++i)
    {
        transactions[i] = transactions[i + 1];
    }
    resize_transactions(--transaction_count);
    show_message("Transaction removed successfully!");
}

// Function to generate category-based reports
void category_report()
{
    double total_income = 0, total_expense = 0;
    std::map<string, double> category_totals;

    for (int i = 0; i < transaction_count; ++i)
    {
        if (transactions[i].type == "income")
            total_income += transactions[i].amount;
        else
            total_expense += transactions[i].amount;

        category_totals[transactions[i].category] += transactions[i].amount;
    }

    show_message("Category-based spending:");
    for (const auto &pair : category_totals)
    {
        write_line(pair.first + ": $" + std::to_string(pair.second));
    }

    write_line("Total Income: $" + std::to_string(total_income));
    write_line("Total Expenses: $" + std::to_string(total_expense));

    // Draw pie chart for category-based spending
    draw_pie_chart(category_totals);
}

// Function to fill a sector of the pie chart
void fill_sector(color clr, int cx, int cy, int radius, double start_angle, double end_angle)
{
    fill_circle(clr, cx, cy, radius);  // Filling the sector in a rough manner (simplified)
}

// Function to draw a pie chart using SplashKit
void draw_pie_chart(const std::map<string, double> &category_totals)
{
    open_window("Category-wise Spending", 800, 600);
    clear_screen(COLOR_WHITE);

    double total = 0;
    for (const auto &pair : category_totals)
    {
        total += pair.second;
    }

    int center_x = 400, center_y = 300, radius = 200;
    double start_angle = 0.0;

    for (const auto &pair : category_totals)
    {
        double percentage = pair.second / total;
        double sweep_angle = percentage * 360.0;

        // Use random color for each category
        fill_sector(random_color(), center_x, center_y, radius, start_angle, start_angle + sweep_angle);
        draw_text(pair.first + ": $" + std::to_string(pair.second), COLOR_BLACK, "arial.ttf", 20, center_x + 250, center_y);

        start_angle += sweep_angle;
    }

    refresh_screen();
    delay(5000);
    close_window("Category-wise Spending");
}

// Function to generate a random color
color random_color()
{
    int r = rnd(256);  // Generate a random number between 0 and 255 for red
    int g = rnd(256);  // Generate a random number between 0 and 255 for green
    int b = rnd(256);  // Generate a random number between 0 and 255 for blue
    return rgb_color(r, g, b);
}

// Function to save transactions to file
void save_to_file(const string &filename)
{
    std::ofstream file(filename);

    for (int i = 0; i < transaction_count; ++i)
    {
        file << transactions[i].date << "," << transactions[i].type << "," << transactions[i].amount << "," << transactions[i].category << "\n";
    }

    file.close();
    show_message("Transactions saved successfully!");
}

// Function to load transactions from file
void load_from_file(const string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        show_message("Unable to open file.");
        return;
    }

    transactions = new Transaction[0];
    transaction_count = 0;
    string line;
    while (getline(file, line))
    {
        resize_transactions(transaction_count + 1);
        Transaction *transaction = &transactions[transaction_count];

        std::istringstream ss(line);
        getline(ss, transaction->date, ',');
        getline(ss, transaction->type, ',');
        ss >> transaction->amount;
        ss.ignore();
        getline(ss, transaction->category);

        transaction_count++;
    }

    file.close();
    show_message("Transactions loaded successfully!");
}

// Function to sort transactions by date, amount, or category
void sort_transactions()
{
    int choice = convert_to_integer(get_input("Sort by: 1. Date 2. Amount 3. Category"));

    switch (choice)
    {
    case 1:
        std::sort(transactions, transactions + transaction_count, [](const Transaction &a, const Transaction &b) {
            return a.date < b.date;
        });
        show_message("Transactions sorted by date.");
        break;
    case 2:
        std::sort(transactions, transactions + transaction_count, [](const Transaction &a, const Transaction &b) {
            return a.amount < b.amount;
        });
        show_message("Transactions sorted by amount.");
        break;
    case 3:
        std::sort(transactions, transactions + transaction_count, [](const Transaction &a, const Transaction &b) {
            return a.category < b.category;
        });
        show_message("Transactions sorted by category.");
        break;
    default:
        show_message("Invalid choice.");
    }
}

// Function to search transactions
void search_transactions()
{
    double search_amount = convert_to_double(get_input("Enter the amount to search for: "));

    for (int i = 0; i < transaction_count; ++i)
    {
        if (transactions[i].amount == search_amount)
        {
            write_line("Transaction found at index " + std::to_string(i) + ": " + transactions[i].date + ", " + transactions[i].type + ", $" + std::to_string(transactions[i].amount) + ", " + transactions[i].category);
        }
    }
}

// Function to predict future expenses based on past data
double predict_future_expense(int future_months)
{
    std::vector<double> monthly_expenses(12, 0.0);

    // Calculate monthly expenses
    for (int i = 0; i < transaction_count; ++i)
    {
        if (transactions[i].type == "expense")
        {
            int month = stoi(transactions[i].date.substr(5, 2)) - 1;  // Month as index
            monthly_expenses[month] += transactions[i].amount;
        }
    }

    // Calculate average monthly expense
    double average_expense = std::accumulate(monthly_expenses.begin(), monthly_expenses.end(), 0.0) / 12;
    double predicted_expense = average_expense * future_months;

    show_message("Predicted expense for the next " + std::to_string(future_months) + " months: $" + std::to_string(predicted_expense));
    return predicted_expense;
}

int main()
{
    // Menu loop for user interaction
    while (true)
    {
        int choice = convert_to_integer(get_input("Choose an option:\n1. Add Transaction\n2. Modify Transaction\n3. Remove Transaction\n4. Category Report\n5. Save Transactions\n6. Load Transactions\n7. Sort Transactions\n8. Search Transactions\n9. Predict Future Expense\n10. Exit"));

        switch (choice)
        {
        case 1:
            add_transaction();
            break;
        case 2:
            modify_transaction();
            break;
        case 3:
            remove_transaction();
            break;
        case 4:
            category_report();
            break;
        case 5:
            save_to_file("transactions.txt");
            break;
        case 6:
            load_from_file("transactions.txt");
            break;
        case 7:
            sort_transactions();
            break;
        case 8:
            search_transactions();
            break;
        case 9:
        {
            int months = convert_to_integer(get_input("Enter number of months for prediction: "));
            predict_future_expense(months);
            break;
        }
        case 10:
            delete[] transactions;
            return 0;
        default:
            show_message("Invalid choice. Please try again.");
        }
    }
    return 0;
}