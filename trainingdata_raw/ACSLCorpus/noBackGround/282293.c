#include <stdbool.h>

/*@
    requires (1 <= (r) && (r) <= 9);
    requires (1 <= (g) && (g) <= 9);
    requires (1 <= (b) && (b) <= 9);
    ensures \result == ((((g) * 10 + (b)) % 4) == 0 || ((r) % 4) == 0);
*/
bool func(unsigned int r, unsigned int g, unsigned int b)
{
    unsigned int x;
    unsigned int y;
    bool result;

    //@ assert (1 <= (r) && (r) <= 9);
    //@ assert (1 <= (g) && (g) <= 9);
    //@ assert (1 <= (b) && (b) <= 9);

    x = (g * 10 + b) % 4;
    //@ assert x == (((g) * 10 + (b)) % 4);

    y = r % 4;
    //@ assert y == ((r) % 4);

    result = (x == 0) || (y == 0);
    //@ assert result == ((((g) * 10 + (b)) % 4) == 0 || ((r) % 4) == 0);

    return result;
}
