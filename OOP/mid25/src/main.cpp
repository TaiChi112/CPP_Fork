#include <iostream>
#include <vector>

using namespace std;
enum class E_Stove_Type
{
    Gas,
    Electric,
    Induction
};
class Stove
{
    E_Stove_Type type;

public:
    Stove() : type(E_Stove_Type::Gas) {}
    Stove(E_Stove_Type t) : type(t) {}
    ~Stove() {}
    void set_stove_type(E_Stove_Type t) { type = t; }
    E_Stove_Type get_stove_type() { return type; }
    void show_stove_type()
    {
        switch (type)
        {
        case E_Stove_Type::Gas:
            cout << "Gas Stove" << endl;
            break;
        case E_Stove_Type::Electric:
            cout << "Electric Stove" << endl;
            break;
        case E_Stove_Type::Induction:
            cout << "Induction Stove" << endl;
            break;
        }
    }
};
class Pot
{
    double price;
    int width, height, amount_of_stove;
    Stove *stove;

public:
    Pot(double p, int w, int h, int a) : price(p), width(w), height(h), amount_of_stove(a)
    {
        stove = new Stove[amount_of_stove];
    }
    ~Pot()
    {
        delete[] stove;
    }
    void set_price(double p) { price = p; }
    double get_price() { return price; }
    void set_width(int w) { width = w; }
    int get_width() { return width; }
    void set_height(int h) { height = h; }
    int get_height() { return height; }
    void set_amount_of_stove(int a) { amount_of_stove = a; }
    int get_amount_of_stove() { return amount_of_stove; }
    void set_stove_type(int index, E_Stove_Type t)
    {
        if (amount_of_stove <= 0)
        {
            cout << "No stoves available." << endl;
            return;
        }
        if (index >= 0 && index < amount_of_stove)
        {
            stove[index].set_stove_type(t);
        }
    }
    void show_pot_info()
    {
        cout << "Pot Price: " << price << endl;
        cout << "Pot Width: " << width << endl;
        cout << "Pot Height: " << height << endl;
        cout << "Amount of Stoves: " << amount_of_stove << endl;
        for (int i = 0; i < amount_of_stove; i++)
        {
            cout << "Stove " << i + 1 << ": ";
            stove[i].show_stove_type();
        }
    }
};
int main()
{
    Stove stove(E_Stove_Type::Gas);
    stove.show_stove_type();

    Stove array_stove[3] = {E_Stove_Type::Gas, E_Stove_Type::Electric, E_Stove_Type::Induction};
    for (int i = 0; i < 3; i++)
    {
        array_stove[i].show_stove_type();
    }

    vector<Stove> vector_stove = {E_Stove_Type::Gas, E_Stove_Type::Electric, E_Stove_Type::Induction};
    for (int i = 0; i < vector_stove.size(); i++)
    {
        vector_stove[i].show_stove_type();
    }

    cout << endl;

    Pot pot(100.0, 20, 10, 2);
    pot.set_stove_type(0, E_Stove_Type::Electric);
    pot.set_stove_type(1, E_Stove_Type::Induction);
    pot.show_pot_info();
    cout << endl;

    Pot array_pot[2] = {Pot(50.0, 15, 8, 1), Pot(75.0, 18, 9, 2)};
    array_pot[0].set_stove_type(0, E_Stove_Type::Gas);
    array_pot[1].set_stove_type(0, E_Stove_Type::Electric);
    array_pot[1].set_stove_type(1, E_Stove_Type::Induction);
    for (int i = 0; i < 2; i++)
    {
        array_pot[i].show_pot_info();
        cout << endl;
    }

    vector<Pot> vector_pot = {Pot(60.0, 12, 6, 1), Pot(80.0, 22, 11, 2)};
    vector_pot[0].set_stove_type(0, E_Stove_Type::Induction);
    vector_pot[1].set_stove_type(0, E_Stove_Type::Electric);
    vector_pot[1].set_stove_type(1, E_Stove_Type::Induction);
    for (int i = 0; i < vector_pot.size(); i++)
    {
        vector_pot[i].show_pot_info();
        cout << endl;
    }
    return 0;
}