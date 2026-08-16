#include <stdbool.h>

/*@
    requires (1 <= (r) <= 9);
    requires (1 <= (g) <= 9);
    requires (1 <= (b) <= 9);
    ensures \result == ((g * 10 + b) % 4 == 0);
*/
bool func(int r, int g, int b)
{
    // Variable declarations at scope top
    int combined;
    bool result;

    //@ assert (1 <= (r) <= 9);
    //@ assert (1 <= (g) <= 9);
    //@ assert (1 <= (b) <= 9);

    combined = g * 10 + b;
    //@ assert combined == ((g) * 10 + (b));

    result = (combined % 4 == 0);
    //@ assert result == (((g) * 10 + (b)) % 4 == 0);

    return result;
}
