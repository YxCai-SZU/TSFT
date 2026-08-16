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

struct Beverage {
    enum BeverageTag tag;
    union {
        struct {
            unsigned int creamers;
            bool sugar;
        } coffee;
        struct {
            enum Syrup flavor;
        } soda;
        struct {
            bool ice;
        } water;
    };
};

/*@
    requires ((bev).tag == Soda);
    ensures \result.tag == Soda;
    assigns \nothing;
*/
struct Beverage make_float(struct Beverage bev)
{
    //@ assert bev.tag == Soda;
    return bev;
}

/*@
    requires ((bev).tag == Coffee);
    ensures \result == (bev.coffee.creamers >= 2);
    assigns \nothing;
*/
bool sufficiently_creamy(struct Beverage bev)
{
    //@ assert bev.tag == Coffee;
    return bev.coffee.creamers >= 2;
}
