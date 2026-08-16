#include <limits.h>

/*@
    requires (1 <= (k) && (k) <= 1000 &&
        1 <= (a) && (a) <= (b) && (b) <= 1000);
    ensures \result == 1 || \result == 2;
    assigns \nothing;
*/
int find_min_arrows(int k, int a, int b)
{
    // Variable declarations at scope top
    int min_arrows;

    if (a == b)
    {
        //@ assert a == b;
        min_arrows = 1;
    }
    else if (a + (k - 1) >= b)
    {
        //@ assert a + (k - 1) >= b;
        min_arrows = 1;
    }
    else
    {
        //@ assert a + (k - 1) < b;
        min_arrows = 2;
    }

    //@ assert min_arrows == 1 || min_arrows == 2;
    return min_arrows;
}
