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

class s_size
{
    int width, lenght, height;

public:
    s_size() : width(60), lenght(80), height(180) {}
    s_size(int width, int lenght, int height) : width(width), lenght(lenght), height(height) {}
    int get_width() { return width; }
    int get_lenght() { return lenght; }
    int get_height() { return height; }
};
class Clothes
{
    double price;
    e_clothes_size size;

public:
    Clothes() : price(99.00), size(e_clothes_size::MEDIUM) {}
    Clothes(double price, e_clothes_size size) : price(price), size(size) {}
    void set_price(double price) { this->price = price; }
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
    Tops() : Clothes(199.00, e_clothes_size::MEDIUM), type(e_tops_type::T_SHIRT) {}
    Tops(double price, e_clothes_size size, e_tops_type type) : Clothes(price, size), type(type) {}
    
    void show_tops_info()
    {
        Clothes::show_clothes_info();
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
    e_pants_type lenght;

public:
    Pants() : Clothes(259.00, e_clothes_size::LARGE), lenght(e_pants_type::SHORTS) {}
    Pants(double price, e_clothes_size size, e_pants_type lenght) : Clothes(price, size), lenght(lenght) {}
    void show_pants_info()
    {
        Clothes::show_clothes_info();
        switch (lenght)
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
class Wardrobe
{
    s_size size;
    Tops *tops;
    int amount_of_tops;
    Pants *pants;
    int amount_of_pants;

public:
    Wardrobe() : size(s_size(60, 80, 180)), tops(new Tops), pants(new Pants()) {}
    Wardrobe(s_size size, Tops *tops, int amount_of_tops, Pants *pants, int amount_of_pants) : size(size), tops(tops), amount_of_tops(amount_of_tops), pants(pants), amount_of_pants(amount_of_pants) {}
    void show_wardrobe_info()
    {
        cout << "Wardrobe size: " << size.get_width() << "x" << size.get_lenght() << "x" << size.get_height() << endl;
        cout << "Tops:" << endl;
        for (int i = 0; i < amount_of_tops; i++)
        {
            tops[i].show_tops_info();
        }
        cout << endl;
        cout << "Pants:" << endl;
        for (int i = 0; i < amount_of_pants; i++)
        {
            pants[i].show_pants_info();
        }
    }
};
int main()
{
    Wardrobe wardrobe(
        s_size(60, 80, 180),
        new Tops[2]{Tops(199.00, e_clothes_size::MEDIUM, e_tops_type::T_SHIRT), Tops(299.00, e_clothes_size::LARGE, e_tops_type::SHIRT)},
        2,
        new Pants[2]{Pants(259.00, e_clothes_size::LARGE, e_pants_type::SHORTS), Pants(359.00, e_clothes_size::XLARGE, e_pants_type::TROUSERS)},
        2);
    wardrobe.show_wardrobe_info();
    return 0;
}