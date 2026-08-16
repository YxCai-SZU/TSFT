#include <limits.h>

/*@
    predicate positive(integer x) = x > 0;
    predicate nonnegative(integer x) = x >= 0;
    predicate within_bounds(integer ret, integer a, integer b, integer c) = 
        nonnegative(ret) && ret <= a * b * c;
*/

/*@
    logic integer product(integer a, integer b, integer c) = a * b * c;
*/

/*@
    lemma product_nonnegative: 
        \forall integer a, b, c; positive(a) && positive(b) && positive(c) ==> nonnegative(product(a, b, c));
    lemma product_positive: 
        \forall integer a, b, c; positive(a) && positive(b) && positive(c) && a >= 1 && b >= 1 && c >= 1 ==> product(a, b, c) >= 1;
    lemma product_self_bound: 
        \forall integer a, b, c; product(a, b, c) <= product(a, b, c);
*/

/*@
    requires positive(a) && positive(b) && positive(c);
    ensures within_bounds(\result, a, b, c);
*/
int func(int a, int b, int c) {
    int ret;
    
    //@ assert positive(a) && positive(b) && positive(c);
    //@ assert nonnegative(a * b * c);
    
    //@ assert a >= 1 && b >= 1 && c >= 1;
    //@ assert a * b * c >= 1;
    
    //@ assert a * b * c <= a * b * c;
    
    ret = a * b * c;
    
    //@ assert within_bounds(ret, a, b, c);
    return ret;
}
