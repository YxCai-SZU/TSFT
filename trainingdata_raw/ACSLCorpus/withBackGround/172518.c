#include <stdbool.h>

/*@
    predicate is_mod_zero(integer x) = (x % 3) == 0;
    
    logic integer manual_mod(integer x) = x % 3;
    
    lemma mod_property: \forall integer x; x >= 0 ==> manual_mod(x) >= 0 && manual_mod(x) < 3;
*/

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    ensures \result == true <==> (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
*/
bool func(unsigned int a, unsigned int b)
{
    unsigned int sum;
    unsigned int a_mod;
    unsigned int b_mod;
    unsigned int sum_mod;
    
    sum = a + b;
    a_mod = a;
    b_mod = b;
    sum_mod = sum;
    
    //@ assert sum_mod == a + b;
    
    /*@
        loop invariant 0 <= sum_mod;
        loop invariant sum_mod <= a + b;
        loop invariant sum_mod % 3 == (a + b) % 3;
        loop assigns sum_mod;
    */
    while (sum_mod >= 3)
    {
        sum_mod -= 3;
    }
    
    /*@
        loop invariant a_mod <= a;
        loop invariant a_mod % 3 == a % 3;
        loop assigns a_mod;
    */
    while (a_mod >= 3)
    {
        a_mod -= 3;
    }
    
    /*@
        loop invariant b_mod <= b;
        loop invariant b_mod % 3 == b % 3;
        loop assigns b_mod;
    */
    while (b_mod >= 3)
    {
        b_mod -= 3;
    }
    
    //@ assert sum_mod == (a + b) % 3;
    //@ assert a_mod == a % 3;
    //@ assert b_mod == b % 3;
    
    if (sum_mod == 0 || a_mod == 0 || b_mod == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
