#include <limits.h>

/*@
    predicate in_range(integer v) = -100 <= v <= 100;
    predicate ordered(integer a, integer b) = a <= b;
    
    logic integer product(integer x, integer y) = x * y;
    
    lemma product_bounds:
        \forall integer x, y;
            in_range(x) && in_range(y) ==> -10000 <= product(x, y) <= 10000;
*/

/*@
    requires in_range(A) && in_range(B) && in_range(C) && in_range(D);
    requires ordered(A, B) && ordered(C, D);
    ensures \result == product(B, D) || \result == product(A, C) || 
            \result == product(A, D) || \result == product(B, C);
*/
long func(long A, long B, long C, long D)
{
    long max1;
    long max2;
    long result;
    
    //@ assert in_range(A);
    //@ assert in_range(B);
    //@ assert in_range(C);
    //@ assert in_range(D);
    
    //@ assert -10000 <= A * C <= 10000;
    //@ assert -10000 <= A * D <= 10000;
    //@ assert -10000 <= B * C <= 10000;
    //@ assert -10000 <= B * D <= 10000;
    
    if (A * C > A * D) {
        max1 = A * C;
    } else {
        max1 = A * D;
    }
    
    if (B * C > B * D) {
        max2 = B * C;
    } else {
        max2 = B * D;
    }
    
    if (max1 > max2) {
        result = max1;
    } else {
        result = max2;
    }
    
    //@ assert result == product(B, D) || result == product(A, C) || result == product(A, D) || result == product(B, C);
    
    return result;
}
