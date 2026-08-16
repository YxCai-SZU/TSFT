#include <stdbool.h>

enum Syrup {
    Cola,
    RootBeer,
    Orange,
    LemonLime
};

enum Beverage {
    Coffee,
    Soda,
    Water
};


enum Beverage make_float(enum Beverage bev)
{
    //@ assert ((bev) == Soda);
    return bev;
}


bool sufficiently_creamy(enum Beverage bev)
{
    return true;
}

int main()
{
    return 0;
}
