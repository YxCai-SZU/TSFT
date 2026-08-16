#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == true <==> (((a) < (c) && (c) < (b)) || ((a) > (c) && (c) > (b)));
    assigns \nothing;
 */
bool func(int a, int b, int c)
{
    //@ assert (((a) < (c) && (c) < (b)) || ((a) > (c) && (c) > (b))) <==> (((a) < (c) && (c) < (b)) || ((a) > (c) && (c) > (b)));
    
    if ((a < c && c < b) || (a > c && c > b))
    {
        return true;
    }
    else
    {
        return false;
    }
}
