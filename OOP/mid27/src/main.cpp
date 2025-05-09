#include <iostream>

using namespace std;
enum class e_made_from
{
    GOLD,
    SILVER,
    PLATINUM,
};
enum class e_gem_type
{
    DIAMOND,
    POMEGRANATE,
    JADE,
    SPAPHIRE,
    PEARL,
};
class Gem
{
    e_gem_type type;

public:
    Gem() : type(e_gem_type::PEARL) {}
    Gem(e_gem_type type) : type(type) {}
    void show_gem_info()
    {
        cout << "Gem type: ";
        switch (type)
        {
        case e_gem_type::DIAMOND:
            cout << "Diamond" << endl;
            break;
        case e_gem_type::POMEGRANATE:
            cout << "Pomegranate" << endl;
            break;
        case e_gem_type::JADE:
            cout << "Jade" << endl;
            break;
        case e_gem_type::SPAPHIRE:
            cout << "Sapphire" << endl;
            break;
        case e_gem_type::PEARL:
            cout << "Pearl" << endl;
            break;
        }
    }
};
class Jewelry
{
    double price;
    e_made_from made_from;

public:
    Jewelry() : price(990.00), made_from(e_made_from::SILVER) {}
    Jewelry(double price, e_made_from made_from) : price(price), made_from(made_from) {}
    void show_jewelry_info()
    {
        cout << "Price: " << price << endl;
        cout << "Made from: ";
        switch (made_from)
        {
        case e_made_from::GOLD:
            cout << "Gold" << endl;
            break;
        case e_made_from::SILVER:
            cout << "Silver" << endl;
            break;
        case e_made_from::PLATINUM:
            cout << "Platinum" << endl;
            break;
        }
    }
};
class Ring : public Jewelry
{
    Gem **gems;
    int amount_of_gems;

public:
    Ring() : Jewelry(3000.00, e_made_from::PLATINUM), gems(nullptr), amount_of_gems(1) {}
    Ring(double price, e_made_from made_from, Gem **gems, int amount_of_gems) : Jewelry(price, made_from), gems(gems), amount_of_gems(amount_of_gems) {}
    void show_ring_info()
    {
        show_jewelry_info();
        for (int i = 0; i < amount_of_gems; i++)
        {
            gems[i]->show_gem_info();
        }
    }
};
class Necklace : public Jewelry
{
    bool is_pendant;

public:
    Necklace() : Jewelry(22000.00, e_made_from::GOLD), is_pendant(true) {}
    Necklace(double price, e_made_from made_from, bool is_pendant) : Jewelry(price, made_from), is_pendant(is_pendant) {}
    void show_necklace_info()
    {
        show_jewelry_info();
        cout << "Is pendant: " << (is_pendant ? "true" : "false") << endl;
    }
};
int main()
{
    Ring ring(1000, e_made_from::GOLD, new Gem *[2]{new Gem(e_gem_type::DIAMOND), new Gem(e_gem_type::POMEGRANATE)}, 1);
    ring.show_ring_info();
    Necklace necklace(500, e_made_from::SILVER, true);
    necklace.show_necklace_info();

    Ring ring2;
    ring2.show_ring_info();
    Necklace necklace2;
    necklace2.show_necklace_info();
    return 0;
}