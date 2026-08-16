#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    // Logical computation for result classification
    logic integer classify(integer a, integer b, integer c) =
        (a == b && b == c) ? 1 :
        (a != b && b != c && a != c) ? 3 :
        2;

    // Proof lemma for result bounds
    lemma result_bounds: \forall integer a,b,c;
        valid_range(a) && valid_range(b) && valid_range(c) ==>
        1 <= classify(a,b,c) <= 3;

    // Proof lemma for case 1
    lemma case1_lemma: \forall integer a,b,c;
        valid_range(a) && valid_range(b) && valid_range(c) ==>
        (classify(a,b,c) == 1) ==> (a == b && b == c);

    // Proof lemma for case 2
    lemma case2_lemma: \forall integer a,b,c;
        valid_range(a) && valid_range(b) && valid_range(c) ==>
        (classify(a,b,c) == 2) ==> 
        ((a == b && a != c) || (a == c && a != b) || (b == c && b != a));

    // Proof lemma for case 3
    lemma case3_lemma: \forall integer a,b,c;
        valid_range(a) && valid_range(b) && valid_range(c) ==>
        (classify(a,b,c) == 3) ==> (a != b && b != c && a != c);
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result >= 1 && \result <= 3;
    ensures \result == 1 ==> (a == b && b == c);
    ensures \result == 2 ==> ((a == b && a != c) || (a == c && a != b) || (b == c && b != a));
    ensures \result == 3 ==> (a != b && b != c && a != c);
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    int32_t ans;
    
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    
    if (a == b && b == c) {
        ans = 1;
    } else if (a != b && b != c && c != a) {
        ans = 3;
    } else {
        ans = 2;
    }
    
    //@ assert ans >= 1 && ans <= 3;
    //@ assert 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100;
    
    return ans;
}
