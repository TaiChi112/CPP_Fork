#include <iostream>

using namespace std;
enum class e_meat_type
{
    FRESH,
    GRILLED,
    FRIED,
};
enum class e_chicken_type
{
    BROILER_CHICKEN,
    COUNTRY_CHICKEN,
};
enum class e_thaifood_spicy_level
{
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE
};
class Meat
{
    e_meat_type type;

public:
    virtual void show_meat_info() = 0;
    e_meat_type get_meat_type()
    {
        return type;
    }
};
class Fish : public Meat
{
    string name;

public:
    void show_meat_info() override
    {
        cout << "Fish name: " << name << endl;
        cout << "Fish type: ";
        switch (Meat::get_meat_type())
        {
        case e_meat_type::FRESH:
            cout << "Fresh";
            break;
        case e_meat_type::GRILLED:
            cout << "Grilled";
            break;
        case e_meat_type::FRIED:
            cout << "Fried";
            break;
        }
    }
};

class Chicken : public Meat
{
    e_chicken_type type;

public:
    void show_meat_info() override
    {
        cout << "Chicken type: ";
        switch (type)
        {
        case e_chicken_type::BROILER_CHICKEN:
            cout << "Broiler Chicken";
            break;
        case e_chicken_type::COUNTRY_CHICKEN:
            cout << "Country Chicken";
            break;
        }
        cout << endl;
        cout << "Chicken meat type: ";
        switch (Meat::get_meat_type())
        {
        case e_meat_type::FRESH:
            cout << "Fresh";
            break;
        case e_meat_type::GRILLED:
            cout << "Grilled";
            break;
        case e_meat_type::FRIED:
            cout << "Fried";
            break;
        }
    }
};
class ThaiFood
{
    double price;
    e_thaifood_spicy_level spicy_level;
    Meat *meat;

public:
    virtual void show_thaifood_info() = 0;
    e_thaifood_spicy_level get_spicy_level()
    {
        return spicy_level;
    }
    double get_price()
    {
        return price;
    }
};
class Larb : public ThaiFood
{
    bool is_shallot;

public:
    void show_thaifood_info() override
    {
        switch (ThaiFood::get_spicy_level())
        {
        case e_thaifood_spicy_level::ONE:
            cout << "Spicy level: 1" << endl;
            break;
        case e_thaifood_spicy_level::TWO:
            cout << "Spicy level: 2" << endl;
            break;
        case e_thaifood_spicy_level::THREE:
            cout << "Spicy level: 3" << endl;
            break;
        case e_thaifood_spicy_level::FOUR:
            cout << "Spicy level: 4" << endl;
            break;
        case e_thaifood_spicy_level::FIVE:
            cout << "Spicy level: 5" << endl;
            break;
        }
        cout << "Price: " << get_price() << endl;
        cout << "Larb info"
             << "Is shallot: " << (is_shallot ? "Yes" : "No") << endl;
    }
};
class Soup : public ThaiFood
{
    bool is_hot_pot;

public:
    void show_thaifood_info() override
    {
        cout << "Soup info"
             << "Is hot pot: " << (is_hot_pot ? "Yes" : "No") << endl;
        switch (ThaiFood::get_spicy_level())
        {
        case e_thaifood_spicy_level::ONE:
            cout << "Spicy level: 1" << endl;
            break;
        case e_thaifood_spicy_level::TWO:
            cout << "Spicy level: 2" << endl;
            break;
        case e_thaifood_spicy_level::THREE:
            cout << "Spicy level: 3" << endl;
            break;
        case e_thaifood_spicy_level::FOUR:
            cout << "Spicy level: 4" << endl;
            break;
        case e_thaifood_spicy_level::FIVE:
            cout << "Spicy level: 5" << endl;
            break;
        }
        cout << "Price: " << get_price() << endl;
    }
};
class Tom_Yam : public Soup
{
    bool is_clear;

public:
    void show_thaifood_info() override
    {
        cout << "Tom Yam info"
             << "Is clear: " << (is_clear ? "Yes" : "No") << endl;
        Soup::show_thaifood_info();
    }
};
class Tom_Klong : public Soup
{
    bool is_tomato;

public:
    void show_thaifood_info() override
    {
        cout << "Tom Klong info"
             << "Is tomato: " << (is_tomato ? "Yes" : "No") << endl;
        Soup::show_thaifood_info();
    }
};

int main()
{
    return 0;
}