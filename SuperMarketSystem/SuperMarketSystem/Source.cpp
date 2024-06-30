// This Our Project and this for SuperMarkets With OOP
// Credits :
//  Mohab Nasser Abdelkader 
// Sara Ahmed Abdelaziz
// Let's Start
//----------------------------------------------------------------------
#include <iostream>
#include <sstream>
#include <fstream>
#include <Windows.h>
#include <math.h>
#include <vector>

using namespace std;

class Bill
{
private:
    // Private Attributes
    string Item;
    float quantity, price;
public:
    // Empty Constructor
    Bill() :Item("Unknown"), quantity(0), price(0) {}

    // Set Functions
    void SetItem(string it)
    {
        Item = it;
    }
    void SetQuantity(float q)
    {
        quantity = q;
    }
    void SetPrice(float p)
    {
        price = p;
    }

    // Get Functions
    string GetItem()
    {
        return Item;
    }
    float GetQuantity()
    {
        return quantity;
    }
    float GetPrice()
    {
        return price;
    }
};

void setConsoleColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void additem(Bill b)
{
    bool close = false;
    while (!close) {
        int choice;
        setConsoleColor(11); // Light Cyan
        cout << "\n\t1. Add." << endl;
        cout << "\t2. Close." << endl;
        setConsoleColor(7); // White
        cout << "\tEnter Choice: ";
        cin >> choice;
        // If He Choossed The Add Item Choice 
        if (choice == 1)
        {
            // For Clear The Screen
            system("cls");
            string Item;
            float quantity, price;
            setConsoleColor(14); // Yellow
            cout << "\n\t Enter Product Name : ";
            setConsoleColor(7); // White
            cin >> Item;
            b.SetItem(Item);
            setConsoleColor(14); // Yellow
            cout << "\t Enter Product Quantity : ";
            setConsoleColor(7); // White
            cin >> quantity;
            b.SetQuantity(quantity);
            setConsoleColor(14); // Yellow
            cout << "\t Enter Product Price : ";
            setConsoleColor(7); // White
            cin >> price;
            b.SetPrice(price);

            ofstream out("D:/Bill.txt", ios::app);
            if (!out)
            {
                setConsoleColor(12); // Light Red
                cout << "\tError : File Can't Open !" << endl;
                setConsoleColor(7); // White
            }
            else
            {
                out << b.GetItem() << " " << b.GetQuantity() << " " << b.GetPrice() << "\n";
            }
            out.close();
            setConsoleColor(10); // Light Green
            cout << "\nProduct Has Been Added Successfully" << endl;
            setConsoleColor(7); // White
            // For Delay (Waiting)
            Sleep(1000);
        }
        else if (choice == 2)
        {
            system("cls");
            close = true;
            setConsoleColor(10); // Light Green
            cout << "\nBack To The Main Menu" << endl;
            setConsoleColor(7); // White
            Sleep(1000);
        }
    }
}

void printBill(Bill bb)
{
    // Sara's Part TT^TT
    system("cls");
    int count = 0;
    vector<pair<string, pair<float, float>>> purchasedItems;
    bool close = false;
    while (!close) {
        system("cls");
        int choice;
        setConsoleColor(11); // Light Cyan
        cout << "\n\t1. Add Bill." << endl;
        cout << "\t2. Close Session." << endl;
        setConsoleColor(7); // White
        cout << "\tEnter Choice: ";
        cin >> choice;
        if (choice == 1) {
            string Item;
            float quantity;
            setConsoleColor(14); // Yellow
            cout << "\n\t Enter Product Name : ";
            setConsoleColor(7); // White
            cin >> Item;
            setConsoleColor(14); // Yellow
            cout << "\t Enter Product Quantity : ";
            setConsoleColor(7); // White
            cin >> quantity;

            ifstream in("D:/Bill.txt");
            ofstream out("D:/BillTemp.txt");
            string line;
            bool found = false;
            while (getline(in, line)) {
                stringstream ss(line);
                string itemName;
                float itemQuantity, itemPrice;
                ss >> itemName >> itemQuantity >> itemPrice;

                if (Item == itemName) {
                    found = true;
                    if (quantity <= itemQuantity) {
                        int amount = itemPrice * quantity;
                        setConsoleColor(14); // Yellow
                        cout << "\n\t Item | Price | Quantity | Amount" << endl;
                        setConsoleColor(7); // White
                        cout << "\t" << itemName << "\t" << itemPrice << "\t" << quantity << "\t" << amount << endl;
                        float newQuantity = itemQuantity - quantity;
                        count += amount;
                        out << itemName << " " << newQuantity << " " << itemPrice << endl;
                        purchasedItems.push_back({ itemName, {quantity, amount} });
                    }
                    else {
                        setConsoleColor(12); // Light Red
                        cout << "\n\tSorry, " << Item << " Ended!" << endl;
                        setConsoleColor(7); // White
                        out << line << endl;
                    }
                }
                else {
                    out << line << endl;
                }
            }
            if (!found) {
                setConsoleColor(12); // Light Red
                cout << "\n\tItem Not Available!" << endl;
                setConsoleColor(7); // White
            }
            out.close();
            in.close();
            remove("D:/Bill.txt");
            rename("D:/BillTemp.txt", "D:/Bill.txt");
        }
        else if (choice == 2) {
            close = true;
            setConsoleColor(10); // Light Green
            cout << "\nCounting Total Bill" << endl;
            setConsoleColor(7); // White
        }
        Sleep(3000);
    }
    system("cls");
    setConsoleColor(10); // Light Green
    cout << "\n\n\t Total Bill ----------------- : " << count << endl << endl;
    setConsoleColor(7); // White
    cout << "\tPurchased Items:" << endl;
    setConsoleColor(14); // Yellow
    cout << "\tItem\tQuantity\tAmount" << endl;
    setConsoleColor(7); // White
    for (auto& item : purchasedItems) {
        cout << "\t" << item.first << "\t" << item.second.first << "\t\t" << item.second.second << endl;
    }
    setConsoleColor(10); // Light Green
    cout << "\n\tThanks For Shopping!" << endl;
    setConsoleColor(7); // White
    Sleep(5000);
}

int main()
{
    Bill b1;
    bool exit = false;
    while (!exit) // == While(exit==false)
    {
        system("cls");
        int val;
        setConsoleColor(11); // Light Cyan
        cout << "\n\t======================================" << endl;
        cout << "\t  Welcome To Daredevil Market System" << endl;
        cout << "\t======================================" << endl;
        setConsoleColor(14); // Yellow
        cout << "\t1. Add Item." << endl;
        cout << "\t2. Print Bill." << endl;
        cout << "\t3. Exit." << endl;
        setConsoleColor(7); // White
        cout << "\n\tEnter Choice: ";
        cin >> val;
        // If He Choosed To Add Item 
        if (val == 1)
        {
            system("cls");
            additem(b1);
            Sleep(2000);
        }

        else if (val == 2)
        {
            // Sara's Part
            printBill(b1);
        }
        else if (val == 3) {
            system("cls");
            exit = true;
            setConsoleColor(10); // Light Green
            cout << "\n\tThank You For Using Daredevil Super Market System :) <3 !" << endl;
            setConsoleColor(7); // White
            Sleep(3000);
        }

    }

    return 0;
}