#include <stdbool.h>

/*@
    requires (1 <= (k) <= 1000 &&
      1 <= (a) <= (b) <= 1000);
    ensures \result == (a + (((k) - 1) / 2) <= b);
*/
bool func(unsigned int k, unsigned int a, unsigned int b)
{
    unsigned int a_with_borrow;
    unsigned int remaining_k;
    unsigned int quotient;
    
    a_with_borrow = a;
    remaining_k = k - 1;
    quotient = 0;
    
    /*@ loop invariant 0 <= quotient <= (((k) - 1) / 2);
        loop invariant remaining_k == k - 1 - 2 * quotient;
        loop invariant 1 <= k <= 1000;
        loop invariant 1 <= a <= b <= 1000;
        loop invariant a_with_borrow == a + quotient;
        loop assigns quotient, remaining_k, a_with_borrow;
        loop variant remaining_k;
    */
    while (remaining_k >= 2)
    {
        //@ assert remaining_k >= 2;
        quotient = quotient + 1;
        //@ assert quotient <= (((k) - 1) / 2);
        remaining_k = remaining_k - 2;
        a_with_borrow = a_with_borrow + 1;
        //@ assert a_with_borrow == a + quotient;
    }
    
    //@ assert quotient == (((k) - 1) / 2);
    //@ assert a_with_borrow == a + (((k) - 1) / 2);
    return a_with_borrow <= b;
}
