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
};
class Fish : public Meat
{
    string name;

public:
};

class Chicken : public Meat
{
    e_chicken_type type;

public:
};
class ThaiFood
{
    double price;
    e_thaifood_spicy_level spicy_level;
    Meat *meat;

public:
};
class Larb : public ThaiFood
{
    bool is_shallot;

public:
};
class Soup : public ThaiFood
{
    bool is_hot_pot;
public:
};
class Tom_Yam : public Soup
{
    bool is_clear;
public:
};
class Tom_Klong : public Soup
{
    bool is_tomato;
public:
};

int main()
{
    return 0;
}