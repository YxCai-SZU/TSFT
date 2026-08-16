#include <stdbool.h>

/*@
    requires (1 <= (n) <= 10000);
    ensures \result == (1000 * (((n) + 999) / 1000));
    assigns \nothing;
*/
int func(int n)
{
    int quotient = 0;
    int temp_n = n + 999;
    int count = 0;
    
    //@ assert 1 <= n <= 10000;
    //@ assert 0 <= quotient;
    //@ assert 0 <= temp_n <= n + 999;
    //@ assert temp_n == n + 999 - 1000 * quotient;
    //@ assert count == quotient;
    //@ assert count <= (n + 999) / 1000;
    
    /*@
        loop invariant 0 <= quotient;
        loop invariant 0 <= temp_n <= n + 999;
        loop invariant temp_n == n + 999 - 1000 * quotient;
        loop invariant count == quotient;
        loop invariant count <= (n + 999) / 1000;
        loop assigns temp_n, quotient, count;
        loop variant temp_n;
    */
    while (temp_n >= 1000)
    {
        temp_n -= 1000;
        quotient += 1;
        count += 1;
        
        //@ assert temp_n == n + 999 - 1000 * quotient;
        //@ assert count == quotient;
    }
    
    //@ assert quotient == (n + 999) / 1000;
    //@ assert 1000 * quotient == (1000 * (((n) + 999) / 1000));
    
    return 1000 * quotient;
}
