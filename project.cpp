#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class representing a food item
class FoodItem
{
public:
    string name;
    float price;
    int quantity;

    FoodItem(string n, float p, int q) : name(n), price(p), quantity(q) {}

    void updateQuantity(int q)
    {
        quantity += q;
    }
};

// Class representing the canteen, handling the menu and transactions
class Canteen
{
private:
    vector<FoodItem> menu;

public:
    // Add a food item to the menu
    void addFoodItem(string name, float price, int quantity)
    {
        menu.push_back(FoodItem(name, price, quantity));
    }

    // Display the menu
    void displayMenu()
    {
        cout << "Canteen Menu of Hostal4:\n";
        cout << "------------------------------\n";
        for (int i = 0; i < menu.size(); i++)
        {
            cout << i + 1 << ". " << menu[i].name << " - Rs." << menu[i].price << " (Stock: " << menu[i].quantity << ")\n";
        }
        cout << "------------------------------\n";
    }

    // Place an order
    void placeOrder()
    {
        int choice, quantity;
        float total = 0;

        while (true)
        {
            displayMenu();
            cout << "Enter the food item number (or 0 for finish): ";
            cin >> choice;

            if (choice == 0)
                break;

            cout << "Enter quantity: ";
            cin >> quantity;

            if (choice > 0 && choice <= menu.size())
            {
                if (menu[choice - 1].quantity >= quantity)
                {
                    total += menu[choice - 1].price * quantity;
                    menu[choice - 1].updateQuantity(-quantity); // Decrease the stock
                    cout << "Added " << quantity << " " << menu[choice - 1].name << "(s) to your order.\n";
                }
                else
                {
                    cout << "Insufficient stock for " << menu[choice - 1].name << "\n";
                }
            }
            else
            {
                cout << "Invalid choice! Please select a valid food item.\n";
            }





        }

        cout << "\nTotal Bill: Rs." << total << "\n";
    }

    // Update stock of a food item
    void updateStock(int itemNumber, int quantity)
    {
        if (itemNumber > 0 && itemNumber <= menu.size())
        {
            menu[itemNumber - 1].updateQuantity(quantity);
            cout << "Stock updated successfully for " << menu[itemNumber - 1].name << "\n";
        }
        else
        {
            cout << "Invalid item number.\n";
        }
    }

    // Show the current stock of all food items
    void showStock()
    {
        cout << "\nCurrent stock of food items:\n";
        for (size_t i = 0; i < menu.size(); i++)
        {
            cout << menu[i].name << ": " << menu[i].quantity << " units\n";
        }
        cout << "\n";
    }
};

// Main function to run the Canteen Management System
int main()
{
    Canteen canteen;

    // Add food items to the menu
    canteen.addFoodItem("Burger", 50, 100);
    canteen.addFoodItem("Pizza", 150, 5);
    canteen.addFoodItem("Pasta", 100, 70);
    canteen.addFoodItem("choclate", 10, 200);
    canteen.addFoodItem("smosa", 15, 400);
    canteen.addFoodItem("lays", 10, 100);
    canteen.addFoodItem("bread", 12, 20);
    canteen.addFoodItem("namkeen", 25, 100);
    canteen.addFoodItem("Coke", 30, 200);
    canteen.addFoodItem("limca", 30, 200);
    int choice;
    do
    {
        cout << "\n*** Welcome to the Canteen of HOSTAL:4***\n";
        cout << "1. View Menu\n";
        cout << "2. Place Order\n";
        cout << "3. Update Food Stock\n";
        cout << "4. Show Current Stock\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            canteen.displayMenu();
            break;
        case 2:
            canteen.placeOrder();
            break;
        case 3:
        {
            int itemNumber, quantity;
            cout << "Enter food item number to update stock: ";
            cin >> itemNumber;
            cout << "Enter quantity to add: ";
            cin >> quantity;
            canteen.updateStock(itemNumber, quantity);
            break;
        }
        case 4:
            canteen.showStock();
            break;
        case 5:
            cout << "Exiting the canteen menu of hostal 4. \n";
            break;
        default:
            cout << "please enter right choice\n";
        }
    } while (choice != 5);

    return 0;
}
