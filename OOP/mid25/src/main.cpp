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
class Streaming_pot : public Pot
{
    int layer;

public:
    Streaming_pot() : Pot(0.0, 0, 0, 0), layer(0) {}
    Streaming_pot(double p, int w, int h, int a, int l) : Pot(p, w, h, a), layer(l) {}
    ~Streaming_pot() {}
    void set_layer(int l) { layer = l; }
    int get_layer() { return layer; }
    void show_streaming_pot_info()
    {
        Pot::show_pot_info();
        cout << "Layer: " << layer << endl;
    }
};
class Noodle_pot : public Pot
{
    int compartment;

public:
    Noodle_pot() : Pot(0.0, 0, 0, 0), compartment(0) {}
    Noodle_pot(double p, int w, int h, int a, int c) : Pot(p, w, h, a), compartment(c) {}
    ~Noodle_pot() {}
    void set_compartment(int c) { compartment = c; }
    int get_compartment() { return compartment; }
    void show_noodle_pot_info()
    {
        Pot::show_pot_info();
        cout << "Compartment: " << compartment << endl;
    }
};
int main()
{
    vector<Stove> stove_vector = {Stove(E_Stove_Type::Gas), Stove(E_Stove_Type::Electric), Stove(E_Stove_Type::Induction)};

    vector<Pot> pot_vector = {Pot(100.0, 10, 20, 2), Pot(150.0, 15, 25, 1), Pot(200.0, 20, 30, 1)};
    pot_vector[0].set_stove_type(0, E_Stove_Type::Gas);
    pot_vector[0].set_stove_type(1, E_Stove_Type::Gas);
    pot_vector[1].set_stove_type(1, E_Stove_Type::Electric);
    pot_vector[2].set_stove_type(2, E_Stove_Type::Induction);

    for (int i = 0; i < pot_vector.size(); i++)
    {
        cout << "Pot " << i + 1 << ":" << endl;
        pot_vector[i].show_pot_info();
        cout << endl;
    }
    cout << endl;
    return 0;
}