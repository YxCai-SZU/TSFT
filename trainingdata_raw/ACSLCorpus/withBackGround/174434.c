#include <limits.h>

/*@
    predicate is_valid_range(integer v) = 1 <= v <= 100;
*/

/*@
    requires is_valid_range(A) && is_valid_range(B) && 
             is_valid_range(C) && is_valid_range(D);
    ensures \result >= A + C && \result >= A + D &&
            \result >= B + C && \result >= B + D;
*/
int func(int A, int B, int C, int D)
{
    int max1;
    int max2;
    int result;
    
    //@ assert is_valid_range(A) && is_valid_range(B);
    //@ assert is_valid_range(C) && is_valid_range(D);
    
    if (A > B) {
        max1 = A;
    } else {
        max1 = B;
    }
    
    //@ assert max1 >= A && max1 >= B;
    
    if (C > D) {
        max2 = C;
    } else {
        max2 = D;
    }
    
    //@ assert max2 >= C && max2 >= D;
    
    result = max1 + max2;
    
    //@ assert result >= A + C;
    //@ assert result >= A + D;
    //@ assert result >= B + C;
    //@ assert result >= B + D;
    
    return result;
}
