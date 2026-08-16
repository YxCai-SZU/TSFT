#include <stdbool.h>

/*@ requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == true <==> (a * 100 + b) % 2 == 0;
    assigns \nothing;
*/
bool func(long a, long b)
{
    long total;
    long temp_total;
    
    total = a * 100 + b;
    temp_total = total;
    
    /*@ loop invariant 0 <= temp_total <= total;
        loop invariant temp_total % 2 == total % 2;
        loop assigns temp_total;
        loop variant temp_total;
    */
    while (temp_total >= 2)
    {
        temp_total -= 2;
    }
    
    if (temp_total == 0)
    {
        //@ assert total % 2 == 0;
        return true;
    }
    else
    {
        //@ assert total % 2 != 0;
        return false;
    }
}
