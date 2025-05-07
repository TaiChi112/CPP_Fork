#include <iostream>

using namespace std;
enum class e_clothes_size
{
    SMALL = 'S',
    MEDIUM = 'M',
    LARGE = 'L',
    XLARGE = 'X'
};
enum class e_tops_type
{
    T_SHIRT,
    SHIRT,
    POLO_SHIRT,
};
enum class e_pants_type
{
    SHORTS,
    THREE_QUARTER_PANTS,
    CROPPED_PANTS,
    TROUSERS,
};
class Clothes
{
    double price;
    e_clothes_size size;

public:
    Clothes() : price(0.0), size(e_clothes_size::SMALL) {}
    Clothes(double price, e_clothes_size size) : price(price), size(size) {}
    void show_clothes_info()
    {
        cout << "Price: " << price << endl;
        switch (size)
        {
        case e_clothes_size::SMALL:
            cout << "Size S" << endl;
            break;
        case e_clothes_size::MEDIUM:
            cout << "Size M" << endl;
            break;
        case e_clothes_size::LARGE:
            cout << "Size L" << endl;
            break;
        case e_clothes_size::XLARGE:
            cout << "Size XL" << endl;
            break;
        }
    }
};
class Tops : public Clothes
{
    e_tops_type type;

public:
    Tops() : Clothes(), type(e_tops_type::T_SHIRT) {}
    Tops(double price, e_clothes_size size, e_tops_type type) : Clothes(price, size), type(type) {}
    void show_tops_info()
    {
        show_clothes_info();
        switch (type)
        {
        case e_tops_type::T_SHIRT:
            cout << "Type: T-Shirt" << endl;
            break;
        case e_tops_type::SHIRT:
            cout << "Type: Shirt" << endl;
            break;
        case e_tops_type::POLO_SHIRT:
            cout << "Type: Polo Shirt" << endl;
            break;
        }
    }
};
class Pants : public Clothes
{
    e_pants_type type;
public:
    Pants() : Clothes(), type(e_pants_type::SHORTS) {}
    Pants(double price, e_clothes_size size, e_pants_type type) : Clothes(price, size), type(type) {}
    void show_pants_info()
    {
        show_clothes_info();
        switch (type)
        {
        case e_pants_type::SHORTS:
            cout << "Type: Shorts" << endl;
            break;
        case e_pants_type::THREE_QUARTER_PANTS:
            cout << "Type: Three Quarter Pants" << endl;
            break;
        case e_pants_type::CROPPED_PANTS:
            cout << "Type: Cropped Pants" << endl;
            break;
        case e_pants_type::TROUSERS:
            cout << "Type: Trousers" << endl;
            break;
        }
    }
};
int main()
{
    return 0;
}