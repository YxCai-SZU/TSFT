#include <stdbool.h>

/*@
    requires (0 <= (x) <= 9) && (0 <= (y) <= 9) && (0 <= (z) <= 9);
    ensures \result == (x * y <= 81 && y * z <= 81 && x * z <= 81);
    assigns \nothing;
*/
bool func(int x, int y, int z)
{
    //@ assert (0 <= (x) <= 9);
    //@ assert (0 <= (y) <= 9);
    //@ assert (0 <= (z) <= 9);
    //@ assert 0 <= x * y <= 81;
    //@ assert 0 <= y * z <= 81;
    //@ assert 0 <= x * z <= 81;
    return x * y <= 81 && y * z <= 81 && x * z <= 81;
}
