/*@
    predicate is_odd(integer x) = x % 2 == 1;
    predicate is_even(integer x) = x % 2 == 0;
    
    lemma product_bound: \forall integer a, b; 1 <= a <= 10000 && 1 <= b <= 10000 ==> a * b <= 100000000;
    lemma mod_preserved: \forall integer x, y; x >= 0 && y >= 0 && x <= y ==> (y - 2) % 2 == y % 2;
*/

#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == (a * b % 2 != 0);
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at the top
    unsigned int product;
    bool is_odd = false;
    unsigned int temp;
    
    //@ assert 1 <= a <= 10000;
    //@ assert 1 <= b <= 10000;
    
    product = a * b;
    temp = product;
    
    /*@
        loop invariant 0 <= temp <= product;
        loop invariant temp % 2 == product % 2;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        //@ assert temp % 2 == product % 2;
        temp -= 2;
    }
    
    if (temp == 1)
    {
        is_odd = true;
    }
    
    //@ assert is_odd == (product % 2 == 1);
    return is_odd;
}
