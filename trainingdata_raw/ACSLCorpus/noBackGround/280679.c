#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100);
    requires (1 <= (y) <= 100);
    ensures \result == ((x * 2 + y) / 4 <= y);
    assigns \nothing;
*/
bool func(int x, int y)
{
    int m;
    int n;
    int temp_m;

    //@ assert (1 <= (x) <= 100);
    //@ assert (1 <= (y) <= 100);
    
    m = x * 2 + y;
    n = 0;
    temp_m = m;

    /*@
        loop invariant 1 <= x <= 100;
        loop invariant 1 <= y <= 100;
        loop invariant temp_m >= 0;
        loop invariant n >= 0;
        loop invariant temp_m + 4 * n == m;
        loop assigns temp_m, n;
    */
    while (temp_m >= 4)
    {
        //@ assert temp_m >= 4;
        temp_m = temp_m - 4;
        n = n + 1;
        //@ assert temp_m + 4 * n == m;
    }

    //@ assert temp_m < 4;
    //@ assert n == m / 4;
    return n <= y;
}
