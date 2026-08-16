/*@
    predicate k_in_range(integer k) = 1 <= k && k <= 100;
    predicate x_in_range(integer x) = 1 <= x && x <= 100000;
    predicate k_500_eq(integer k_500, integer i) = k_500 == 500 * i;
    
    logic integer five_hundred_k(integer k) = 500 * k;
    
    lemma loop_completes: \forall integer k, i; 0 <= i && i <= k ==> five_hundred_k(k) >= 500 * i;
*/

#include <stdbool.h>

/*@
    requires k_in_range(k);
    requires x_in_range(x);
    ensures \result == (500 * k >= x);
*/
bool func(int k, int x)
{
    int k_500;
    int i;
    
    //@ assert k_in_range(k);
    //@ assert x_in_range(x);
    
    k_500 = 0;
    i = 0;
    
    /*@
        loop invariant 0 <= i;
        loop invariant i <= k;
        loop invariant k_500_eq(k_500, i);
        loop invariant k_500 <= five_hundred_k(k);
        loop assigns k_500, i;
        loop variant k - i;
    */
    while (i < k)
    {
        //@ assert k_500 == 500 * i;
        k_500 = k_500 + 500;
        i = i + 1;
        //@ assert k_500 == 500 * i;
    }
    
    //@ assert k_500 == five_hundred_k(k);
    
    return k_500 >= x;
}
