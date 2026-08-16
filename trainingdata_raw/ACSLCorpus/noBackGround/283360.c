#include <stdbool.h>

/*@
    requires (1 <= (n) <= 10000 && 0 <= (a) <= 1000);
    ensures \result == (n % 500 <= a);
    assigns \nothing;
*/
bool func(long n, long a)
{
    long value = n;
    
    /*@
        loop invariant 0 <= value <= n;
        loop invariant value % 500 == n % 500;
        loop assigns value;
        loop variant value;
    */
    while (value >= 500)
    {
        //@ assert value % 500 == n % 500;
        value -= 500;
        //@ assert value % 500 == n % 500;
    }
    
    //@ assert value == n % 500;
    return value <= a;
}
