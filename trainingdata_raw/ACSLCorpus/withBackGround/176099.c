#include <stdint.h>

/*@
    predicate in_range(integer v) = 0 <= v <= 9;

    // Verification lemma for the function's postcondition
    lemma func_post_lemma:
        \forall integer x, a, result;
        in_range(x) && in_range(a) &&
        (x < a ==> result == 0) &&
        (x >= a ==> result == 10) ==>
        (result == 0 || result == 10);
*/

/*@
    requires 0 <= x <= 9;
    requires 0 <= a <= 9;
    ensures (x < a ==> \result == 0);
    ensures (x >= a ==> \result == 10);
    assigns \nothing;
*/
int32_t func(uint32_t x, uint32_t a)
{
    int32_t ans;
    
    // Variable declarations at scope top
    ans = 0;
    
    //@ assert 0 <= x <= 9;
    //@ assert 0 <= a <= 9;
    
    if (x < a) {
        ans = 0;
    } else {
        ans = 10;
    }
    
    //@ assert (x < a ==> ans == 0);
    //@ assert (x >= a ==> ans == 10);
    
    return ans;
}

int main(void)
{
    return 0;
}
