#include <stdbool.h>

/*@
    predicate k_in_range(integer k) = 1 <= k <= 100;
    predicate x_in_range(integer x) = 1 <= x <= 100000;
    
    logic integer threshold(integer k) = k * 500;
    
    lemma ans_true_property:
        \forall integer k, x;
        k_in_range(k) && x_in_range(x) && threshold(k) >= x ==>
        threshold(k) >= x;
    
    lemma ans_false_property:
        \forall integer k, x;
        k_in_range(k) && x_in_range(x) && threshold(k) < x ==>
        threshold(k) < x;
*/

/*@
    requires k_in_range(k);
    requires x_in_range(x);
    ensures \result == true ==> threshold(k) >= x;
    ensures \result == false ==> threshold(k) < x;
*/
bool func(int k, int x)
{
    bool ans;
    
    //@ assert k_in_range(k);
    //@ assert x_in_range(x);
    
    if (k * 500 >= x) {
        ans = true;
        //@ assert ans == true;
    } else {
        ans = false;
        //@ assert ans == false;
    }
    
    return ans;
}
