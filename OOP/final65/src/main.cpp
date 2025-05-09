#include <iostream>

using namespace std;
enum class e_kao_niew_color{
    WHITE,
    BLACK
};
enum class e_kai_yang_type{
    GRILLED_CHICKEN_WITH_FRESH_MILK,
    GRILLED_CHICKEN_WITH_TURMERIC,
};
class Food{
    double price;
    public:
    virtual void show_food_info() = 0;
        
};
class KaoNiew : public Food{
    e_kao_niew_color color;
    public:
        
};
class KaiYang: public Food{
    e_kai_yang_type type;
    public:
        
};
class SomTum: public Food{
    int amount_of_chili;
    public:
    virtual void show_somtum_info() = 0;
        
};
class TumPu : public SomTum{
    bool is_plara;
    public:
        
};
class TumThai: public SomTum{
    bool is_peanut;
    public:
        
};
class Order {
    FoodItem** items;
    int amount_of_items;
    int queue_number;
    public:
        
};
class  FoodItem{
    Food* food;
    int amount_of_food;
    public:
        
};
int main(){
    return 0;
}