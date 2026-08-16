#include <limits.h>

/*@
    requires (1 <= (a) <= 10000 && 1 <= (b) <= 10000);
    ensures \result == (((a) * (b)) % 2 != 0);
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at scope top
    int total;
    int is_odd;
    int abs_total;
    int remainder;

    //@ assert (1 <= (a) <= 10000 && 1 <= (b) <= 10000);
    
    total = a * b;
    //@ assert total == ((a) * (b));
    
    is_odd = 0;
    abs_total = total;
    
    if (total < 0)
    {
        abs_total = -total;
    }
    
    remainder = abs_total;
    
    /*@
        loop invariant 0 <= remainder <= abs_total;
        loop invariant remainder % 2 == abs_total % 2;
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 2)
    {
        remainder -= 2;
    }
    
    if (remainder == 1)
    {
        is_odd = 1;
    }
    
    //@ assert is_odd == (((a) * (b)) % 2 != 0);
    return is_odd;
}
