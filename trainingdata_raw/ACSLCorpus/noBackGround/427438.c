#include <stdbool.h>

/*@
    requires (1 <= (x) && (x) < (y) && (y) <= 12);
    ensures \result == ((((x) - 1) / 2) == (((y) - 1) / 2));
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y)
{
    unsigned int g1;
    unsigned int g2;
    bool result;

    //@ assert 1 <= x && x <= 12;
    //@ assert 1 <= y && y <= 12;
    //@ assert x < y;

    g1 = (x - 1) / 2;
    g2 = (y - 1) / 2;
    result = (g1 == g2);

    //@ assert result == ((((x) - 1) / 2) == (((y) - 1) / 2));
    return result;
}
