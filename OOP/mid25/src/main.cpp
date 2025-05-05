#include <iostream>

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
    Stove(E_Stove_Type t) : type(t) {}
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
int main()
{
    Stove stove(E_Stove_Type::Gas);
    stove.show_stove_type(); 

    Stove array_stove[3] = {E_Stove_Type::Gas, E_Stove_Type::Electric, E_Stove_Type::Induction};
    for (int i = 0; i < 3; i++)
    {
        array_stove[i].show_stove_type();
    }
    return 0;
}