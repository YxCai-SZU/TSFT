#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result >= 0;
    ensures \result <= (((a) + (c)) + ((b) + (d)));
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int result;
    int tmp1;
    int tmp2;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    
    tmp1 = (a < b) ? a : b;
    tmp2 = (c < d) ? c : d;
    result = tmp1 + tmp2;

    //@ assert result == (((a) < (b)) ? (a) : (b)) + (((c) < (d)) ? (c) : (d));
    //@ assert result >= 0;
    //@ assert result <= (((a) + (c)) + ((b) + (d)));

    return result;
}
