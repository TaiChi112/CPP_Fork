#include <iostream>

using namespace std;
enum class e_meat_type
{
    PORK,
    CHICKEN,
    FISH,
    SHRIMP,
    SQUID,
    SHELLFISH,
};
enum class e_soup_spicy_level
{
    NOT_SPICY,
    MILDLY_SPICY,
    MEDIUM_SPICY,
    VERY_SPICY,
};
enum class e_soup_type
{
    TOM_YUM,
    SOUR_CURRY,
    TOM_KHLONG,
    PO_TAEK,
};
enum class e_kaopad_type
{
    SMALL_PLATE,
    LARGE_PLATE,
};
class Meat
{
    e_meat_type type;

public:
    Meat() : type(e_meat_type::PORK) {}
    Meat(e_meat_type t) : type(t) {}
    void show_meat_infog()
    {
        switch (type)
        {
        case e_meat_type::PORK:
            cout << "Meat: Pork" << endl;
            break;
        case e_meat_type::CHICKEN:
            cout << "Meat: Chicken" << endl;
            break;
        case e_meat_type::FISH:
            cout << "Meat: Fish" << endl;
            break;
        case e_meat_type::SHRIMP:
            cout << "Meat: Shrimp" << endl;
            break;
        case e_meat_type::SQUID:
            cout << "Meat: Squid" << endl;
            break;
        case e_meat_type::SHELLFISH:
            cout << "Meat: Shellfish" << endl;
            break;
        default:
            cout << "Unknown meat type" << endl;
            break;
        }
    }
};
class Vegetable
{
    string name;

public:
    Vegetable() : name("Unknown") {}
    Vegetable(string n) : name(n) {}
    void show_vegetable_info()
    {
        cout << "Vegetable: " << name << endl;
    }
};
class Food
{
    double price;
    Meat *meat;
    Vegetable *vegetable;
    int amount_of_meat, amount_of_vegetable;

public:
    Food() : price(99.00), amount_of_meat(0), amount_of_vegetable(0), meat(nullptr), vegetable(nullptr) {}
    Food(double p, Meat *m, Vegetable *v, int amount_m, int amount_v)
        : price((p >= 0 ? p : 0)), meat((m > 0 ? new Meat[amount_m] : nullptr)), vegetable((v > 0 ? new Vegetable[amount_v] : nullptr)), amount_of_meat((amount_m > 0 ? amount_m : 1)), amount_of_vegetable((amount_v > 0 ? amount_v : 1)) {}
    void show_food_info()
    {
        cout << "Price: " << price << endl;
        meat->show_meat_infog();
        vegetable->show_vegetable_info();
    }
};
class Soup : public Food
{
    e_soup_type type;
    e_soup_spicy_level spicy_level;

public:
    // Soup(double p, Meat *m, Vegetable *v, int amount_m, int amount_v, e_soup_type t, e_soup_spicy_level s)
    //     : Food((p >= 0 ? p : 0), m, v, (amount_m > 0 ? amount_m : 1), (amount_v > 0 ? amount_v : 1)),
    //     type(
    //           (t == e_soup_type::TOM_YUM) ? e_soup_type::TOM_YUM :
    //           (t == e_soup_type::SOUR_CURRY) ? e_soup_type::SOUR_CURRY :
    //           (t == e_soup_type::TOM_KHLONG) ? e_soup_type::TOM_KHLONG :
    //           e_soup_type::PO_TAEK),
    //     spicy_level(
    //           (s == e_soup_spicy_level::NOT_SPICY) ? e_soup_spicy_level::NOT_SPICY :
    //           (s == e_soup_spicy_level::MILDLY_SPICY) ? e_soup_spicy_level::MILDLY_SPICY :
    //           (s == e_soup_spicy_level::MEDIUM_SPICY) ? e_soup_spicy_level::MEDIUM_SPICY :
    //           e_soup_spicy_level::VERY_SPICY) {}
    Soup(double p, Meat *m, Vegetable *v, int amount_m, int amount_v, e_soup_type t, e_soup_spicy_level s)
        : Food((p >= 0 ? p : 0), ((m > 0 ? new Meat[amount_m] : nullptr)), ((v > 0 ? new Vegetable[amount_v] : nullptr)), (amount_m > 0 ? amount_m : 1), (amount_v > 0 ? amount_v : 1)),
          type((t >= e_soup_type::TOM_YUM && t <= e_soup_type::PO_TAEK) ? t : e_soup_type::PO_TAEK), spicy_level((s >= e_soup_spicy_level::NOT_SPICY && s <= e_soup_spicy_level::VERY_SPICY) ? s : e_soup_spicy_level::NOT_SPICY) {}
    void show_soup_info()
    {
        Food::show_food_info();
        cout << "Soup Type: ";
        switch (type)
        {
        case e_soup_type::TOM_YUM:
            cout << "Tom Yum" << endl;
            break;
        case e_soup_type::SOUR_CURRY:
            cout << "Sour Curry" << endl;
            break;
        case e_soup_type::TOM_KHLONG:
            cout << "Tom Khlong" << endl;
            break;
        case e_soup_type::PO_TAEK:
            cout << "Po Taek" << endl;
            break;
        default:
            cout << "Unknown soup type" << endl;
            break;
        }
        cout << "Spicy Level: ";
        switch (spicy_level)
        {
        case e_soup_spicy_level::NOT_SPICY:
            cout << "Not Spicy" << endl;
            break;
        case e_soup_spicy_level::MILDLY_SPICY:
            cout << "Mildly Spicy" << endl;
            break;
        case e_soup_spicy_level::MEDIUM_SPICY:
            cout << "Medium Spicy" << endl;
            break;
        case e_soup_spicy_level::VERY_SPICY:
            cout << "Very Spicy" << endl;
            break;
        default:
            cout << "Unknown spicy level" << endl;
            break;
        }
    }
};
class Kaopad : public Food
{
    e_kaopad_type type;

public:
    Kaopad(double p, Meat *m, Vegetable *v, int amount_m, int amount_v, e_kaopad_type t)
        : Food(p, m, v, amount_m, amount_v), type(t) {}
    void show_kaopad_info()
    {
        Food::show_food_info();
        cout << "Kaopad Type: ";
        switch (type)
        {
        case e_kaopad_type::SMALL_PLATE:
            cout << "Small Plate" << endl;
            break;
        case e_kaopad_type::LARGE_PLATE:
            cout << "Large Plate" << endl;
            break;
        default:
            cout << "Unknown kaopad type" << endl;
            break;
        }
    }
};
int main()
{
    Meat m(e_meat_type::PORK);
    Vegetable v("Carrot");

    Soup s(12.99, &m, &v, 2, 3, e_soup_type::TOM_YUM, e_soup_spicy_level::MEDIUM_SPICY);
    s.show_soup_info();

    cout << endl;
    Kaopad k(15.99, &m, &v, 1, 2, e_kaopad_type::LARGE_PLATE);
    k.show_kaopad_info();
    return 0;
}