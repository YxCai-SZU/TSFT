#include <stdbool.h>

/*@
    predicate in_range(integer x) = 1 <= x <= 100;
    
    logic integer safe_sum(integer a, integer b) = a + b;
    
    lemma sum_bound: \forall integer a, b; 
        in_range(a) && in_range(b) ==> safe_sum(a, b) <= 200;
*/

/*@
    requires in_range(A) && in_range(B) && in_range(C);
    ensures \result == true <==> (C >= A && C <= A + B);
    assigns \nothing;
*/
bool func(unsigned int A, unsigned int B, unsigned int C)
{
    // Variable declarations at scope top
    unsigned int sum;
    bool result;
    
    //@ assert in_range(A);
    //@ assert in_range(B);
    //@ assert in_range(C);
    
    // Proof of no overflow
    //@ assert safe_sum(A, B) <= 200;
    
    sum = A + B;
    
    if (C > sum)
    {
        result = false;
        return result;
    }
    
    if (C < A)
    {
        result = false;
        return result;
    }
    
    result = true;
    return result;
}
