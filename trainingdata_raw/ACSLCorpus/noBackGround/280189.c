#include <stdbool.h>

/*@
    requires (1 <= (r) <= 9);
    requires (1 <= (g) <= 9);
    requires (1 <= (b) <= 9);
    ensures \result <==> ((((((g)) * 10 + ((b)))) % 4 == 0) ||
        (((((r)) * 10 + ((b)))) % 4 == 0) ||
        (((((g)) * 10 + ((r)))) % 4 == 0));
*/
bool func(int r, int g, int b)
{
    unsigned int ur;
    unsigned int ug;
    unsigned int ub;
    bool g_and_b;
    bool r_and_b;
    bool g_and_r;
    bool result;

    ur = (unsigned int)r;
    ug = (unsigned int)g;
    ub = (unsigned int)b;

    //@ assert ug * 10 <= 90;
    g_and_b = ((ug * 10 + ub) % 4 == 0);

    //@ assert ur * 10 <= 90;
    r_and_b = ((ur * 10 + ub) % 4 == 0);

    //@ assert ug * 10 <= 90;
    g_and_r = ((ug * 10 + ur) % 4 == 0);

    result = g_and_b || r_and_b || g_and_r;
    return result;
}
