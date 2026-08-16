#include <stdbool.h>

/*@
requires a && b && c;
ensures \result == ((a && b) == (b && c));
assigns \nothing;
*/
bool calc_example_logical_layers_impl(bool a, bool b, bool c)
{
    //@ assert a && b == true;
    return (a && b) == (b && c);
}

/*@
requires x == 2 && y == 5 && z == 2;
ensures \result == ((x + y) - z == (y - z) + x);
assigns \nothing;
*/
bool calc_example_integer_arith_impl(int x, int y, int z)
{
    //@ assert (x + y) - z == (y - z) + x;
    return (x + y) - z == (y - z) + x;
}

int main()
{
    return 0;
}
