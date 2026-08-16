#include <stdint.h>

/*@
    predicate in_range(integer v) = 0 <= v <= 9;

    // Verification lemmas
    lemma case_split: \forall integer x, a; in_range(x) && in_range(a) ==> x < a || x >= a;
    lemma case1_implies: \forall integer x, a; in_range(x) && in_range(a) && x < a ==> x < a;
    lemma case2_implies: \forall integer x, a; in_range(x) && in_range(a) && x >= a ==> x >= a;
*/

/*@
    requires 0 <= x <= 9;
    requires 0 <= a <= 9;
    ensures (x < a ==> \result == 0);
    ensures (x >= a ==> \result == 10);
*/
int64_t func(int64_t x, int64_t a)
{
    //@ assert in_range(x);
    //@ assert in_range(a);
    
    int64_t res;
    
    if (x < a) {
        res = 0;
    } else {
        res = 10;
    }
    
    return res;
}

/*@
    requires 0 <= x <= 9;
    requires 0 <= a <= 9;
    ensures (x < a ==> \result == 0);
    ensures (x >= a ==> \result == 10);
*/
int64_t func_noopt(int64_t x, int64_t a)
{
    //@ assert in_range(x);
    //@ assert in_range(a);
    
    //@ assert x < a || x >= a;
    //@ assert x < a ==> (x < a) && (0 <= x <= 9) && (0 <= a <= 9);
    //@ assert x >= a ==> (x >= a) && (0 <= x <= 9) && (0 <= a <= 9);
    
    int64_t res;
    
    if (x < a) {
        res = 0;
    } else {
        res = 10;
    }
    
    return res;
}
