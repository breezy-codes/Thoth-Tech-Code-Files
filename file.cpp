#include "splashkit.h"
using std::to_string;

const int MAX_PRODUCTS = 5;  // Maximum number of products

// Define a struct for Product
struct Product
{
    string name;    // Product name
    double price;   // Product price
    int quantity;   // Product quantity
};

// Function to input product data
void input_product(Product &product)
{
    write("Enter product name: ");
    product.name = read_line();  // Input product name
    
    write("Enter product price: ");
    product.price = convert_to_double(read_line());  // Input product price
    
    write("Enter product quantity: ");
    product.quantity = convert_to_integer(read_line());  // Input product quantity
}

// Function to display product data
void display_product(const Product &product)
{
    write_line("Product: " + product.name);
    write_line("Price: $" + to_string(product.price));
    write_line("Quantity: " + to_string(product.quantity));
    write_line("------------------------------");
}

// Function to input multiple products into an array
void input_products(Product products[], int count)
{
    for (int i = 0; i < count; i++)
    {
        write_line("Enter details for product " + to_string(i + 1) + ":");
        input_product(products[i]);  // Input data for each product
    }
}

// Function to display all products
void display_products(const Product products[], int count)
{
    write_line("Product Database:");
    for (int i = 0; i < count; i++)
    {
        display_product(products[i]);  // Display each product
    }
}

int main()
{
    int product_count;  // Variable to store the number of products
    Product products[MAX_PRODUCTS];  // Array to store products

    // Ask user for the number of products to input (max 5)
    write("How many products do you want to enter (max " + to_string(MAX_PRODUCTS) + ")? ");
    product_count = convert_to_integer(read_line());

    // Limit the input to a maximum of 5 products
    if (product_count > MAX_PRODUCTS)
    {
        product_count = MAX_PRODUCTS;
    }

    // Input product data
    input_products(products, product_count);

    // Display all the products
    display_products(products, product_count);

    return 0;
}