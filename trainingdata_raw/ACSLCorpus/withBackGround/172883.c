#include <limits.h>

/*@
    predicate in_range(integer a) = -1000 <= a <= 1000;
    
    logic integer sum(integer a, integer b) = a + b;
    logic integer diff(integer a, integer b) = a - b;
    logic integer prod(integer a, integer b) = a * b;
    
    lemma product_bounds: 
        \forall integer a, b; in_range(a) && in_range(b) ==> 
            -1000000 <= prod(a, b) <= 1000000;
*/

/*@
    requires in_range(A) && in_range(B);
    ensures \result == sum(A, B) || \result == diff(A, B) || \result == prod(A, B);
    ensures \result >= sum(A, B);
    ensures \result >= diff(A, B);
    ensures \result >= prod(A, B);
*/
int func(int A, int B)
{
    int sum;
    int diff;
    int prod;
    int ans;
    
    //@ assert in_range(A) && in_range(B);
    sum = A + B;
    diff = A - B;
    
    //@ assert -1000000 <= A * B <= 1000000;
    prod = A * B;
    
    ans = sum;
    
    if (diff > ans)
    {
        //@ assert diff > sum;
        ans = diff;
    }
    
    if (prod > ans)
    {
        //@ assert prod > ans;
        ans = prod;
    }
    
    //@ assert ans == sum(A, B) || ans == diff(A, B) || ans == prod(A, B);
    return ans;
}
