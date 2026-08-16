#include <limits.h>

/*@
    predicate in_range(integer a) = -1000 <= a <= 1000;
    
    logic integer sum(integer a, integer b) = a + b;
    logic integer diff(integer a, integer b) = a - b;
    logic integer prod(integer a, integer b) = a * b;
    
    lemma prod_bounds:
        \forall integer a, b;
            in_range(a) && in_range(b) ==>
            -1000000 <= prod(a, b) <= 1000000;
    
    lemma max_property:
        \forall integer a, b, m;
            in_range(a) && in_range(b) &&
            (m == sum(a, b) || m == diff(a, b) || m == prod(a, b)) &&
            m >= sum(a, b) && m >= diff(a, b) && m >= prod(a, b) ==>
            -1000000 <= m <= 1000000;
*/

/*@
    requires -1000 <= A <= 1000;
    requires -1000 <= B <= 1000;
    ensures \result == A + B || \result == A - B || \result == A * B;
    ensures \result >= A + B;
    ensures \result >= A - B;
    ensures \result >= A * B;
*/
int func(int A, int B)
{
    int sum;
    int diff;
    int prod;
    int max_val;
    
    sum = A + B;
    diff = A - B;
    
    //@ assert -1000000 <= A * B <= 1000000;
    
    prod = A * B;
    max_val = sum;
    
    if (diff > max_val)
    {
        max_val = diff;
    }
    
    if (prod > max_val)
    {
        max_val = prod;
    }
    
    //@ assert max_val >= A + B;
    //@ assert max_val >= A - B;
    //@ assert max_val >= A * B;
    //@ assert max_val == A + B || max_val == A - B || max_val == A * B;
    
    return max_val;
}
