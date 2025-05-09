#include <iostream>

using namespace std;
enum class e_kaoniew_color
{
    WHITE,
    BLACK
};
enum class e_kaiyang_type
{
    GRILLED_CHICKEN_WITH_FRESH_MILK,
    GRILLED_CHICKEN_WITH_TURMERIC,
};
class Food
{
    double price;
    static int amount_of_food;

public:
    Food() : price(40.00) {}
    Food(double p) : price((p >= 0 ? p : 0)) {}
    virtual void show_food_info() = 0;
    int get_price() { return price; };
    static int get_amount_of_food() { return amount_of_food; };
};
int Food::amount_of_food = 0;
class KaoNiew : public Food
{
    e_kaoniew_color color;

public:
    KaoNiew() : Food(5.00), color(e_kaoniew_color::WHITE) {}
    KaoNiew(double p, e_kaoniew_color e) : Food(p), color((e >= e_kaoniew_color::WHITE && e <= e_kaoniew_color::WHITE ? e : e_kaoniew_color::BLACK)) {};
    void show_food_info() override
    {
        cout << "Kao Niew price: " << this->get_price() << endl;
        cout << "Kao Niew color: " << (color == e_kaoniew_color::WHITE ? "White" : "Black") << endl;
    }
};
class KaiYang : public Food
{
    e_kaiyang_type type;

public:
    KaiYang() : Food(80.00), type(e_kaiyang_type::GRILLED_CHICKEN_WITH_FRESH_MILK) {}
    KaiYang(double p, e_kaiyang_type e) : Food(p), type((e >= e_kaiyang_type::GRILLED_CHICKEN_WITH_FRESH_MILK && e <= e_kaiyang_type::GRILLED_CHICKEN_WITH_TURMERIC ? e : e_kaiyang_type::GRILLED_CHICKEN_WITH_TURMERIC)) {};
    void show_food_info() override
    {
        cout << "Kai Yang price: " << this->get_price() << endl;
        cout << "Kai Yang type: " << (type == e_kaiyang_type::GRILLED_CHICKEN_WITH_FRESH_MILK ? "Grilled Chicken with Fresh Milk" : "Grilled Chicken with Turmeric") << endl;
    }
};
class SomTum : public Food
{
    int amount_of_chili;

public:
    SomTum() : Food(50.00), amount_of_chili(3) {}
    SomTum(double p, int amount_ch) : Food(p), amount_of_chili((amount_ch >= 0 ? amount_ch : 0)) {}
    virtual void show_somtum_info() = 0;
    int get_amount_of_chili() { return amount_of_chili; };
    void show_food_info() override
    {
        cout << "Som Tum price: " << this->get_price() << endl;
        cout << "Som Tum amount of chili: " << amount_of_chili << endl;
    }
};
class TumPu : public SomTum
{
    bool is_plara;

public:
    TumPu() : SomTum(50.00, 4), is_plara(false) {}
    TumPu(double p, int amount_ch, bool plara) : SomTum(p, amount_ch), is_plara(plara) {}
    void show_somtum_info() override
    {
        cout << "Tum Pu price: " << this->get_price() << endl;
        cout << "Tum Pu amount of chili: " << this->get_amount_of_chili() << endl;
        cout << "Tum Pu is plara: " << (is_plara ? "Yes" : "No") << endl;
    }
};
class TumThai : public SomTum
{
    bool is_peanut;

public:
    TumThai() : SomTum(55.00, 4), is_peanut(true) {}
    TumThai(double p, int amount_ch, bool peanut) : SomTum(p, amount_ch), is_peanut(peanut) {}
    void show_somtum_info() override
    {
        cout << "Tum Thai price: " << this->get_price() << endl;
        cout << "Tum Thai amount of chili: " << this->get_amount_of_chili() << endl;
        cout << "Tum Thai is peanut: " << (is_peanut ? "Yes" : "No") << endl;
    }
};
class FoodItem
{
    Food *food;
    int amount_of_food;

public:
};
class Order
{
    FoodItem **items;
    int amount_of_items;
    int queue_number;

public:
};
int main()
{
    return 0;
}