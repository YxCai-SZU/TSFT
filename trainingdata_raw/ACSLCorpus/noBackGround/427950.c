#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10);
    requires (1 <= (b) <= 10);
    requires (1 <= (c) <= 10);
    requires (1 <= (d) <= 10);
    ensures \result == (((a) * (c)) <= ((b) * (d)));
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    // Variable declarations at scope top
    bool result;
    unsigned int ac;
    unsigned int bd;

    //@ assert (1 <= (a) <= 10) && (1 <= (c) <= 10);
    //@ assert ((a) * (c)) <= 100;

    //@ assert (1 <= (b) <= 10) && (1 <= (d) <= 10);
    //@ assert ((b) * (d)) <= 100;

    ac = a * c;
    bd = b * d;
    result = (ac <= bd);

    return result;
}
