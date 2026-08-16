#include <stdbool.h>

/*@
    predicate in_range(integer x) = 1 <= x <= 100;
    
    lemma a_in_range: \forall integer a; in_range(a) ==> 1 <= a <= 100;
    lemma b_in_range: \forall integer b; in_range(b) ==> 1 <= b <= 100;
    lemma c_in_range: \forall integer c; in_range(c) ==> 1 <= c <= 100;
    lemma sum_in_range: \forall integer a, b; in_range(a) && in_range(b) ==> 1 <= a + b <= 200;
*/

/*@
    requires in_range(a);
    requires in_range(b);
    requires in_range(c);
    ensures \result == (c > (a + b));
*/
bool func(unsigned int a, unsigned int b, unsigned int c) {
    // Variable declarations at scope top
    bool result;
    
    //@ assert 1 <= c <= 100;
    //@ assert 1 <= a + b <= 200;
    
    result = c > (a + b);
    return result;
}
