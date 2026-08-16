#include <stdbool.h>

enum Syrup {
    Cola,
    RootBeer,
    Orange,
    LemonLime
};

enum BeverageTag {
    Coffee,
    Soda,
    Water
};

struct CoffeeFields {
    unsigned int creamers;
    bool sugar;
};

struct SodaFields {
    enum Syrup flavor;
};

struct WaterFields {
    bool ice;
};

union BeverageUnion {
    struct CoffeeFields Coffee;
    struct SodaFields Soda;
    struct WaterFields Water;
};

struct Beverage {
    enum BeverageTag tag;
    union BeverageUnion fields;
};

enum Dessert {
    None
};

/*@
    requires ((bev).tag == Soda);
    requires ((((bev)).tag == Soda) && (bev).fields.Soda.flavor == Cola);
    requires ((bev).tag != Water);
    requires ((bev).tag != Coffee);
    ensures \result == None;
*/
enum Dessert make_float(struct Beverage bev)
{
    //@ assert ((bev).tag == Soda);
    
    enum Dessert result;
    result = None;
    
    return result;
}
