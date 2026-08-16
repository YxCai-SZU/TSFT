/*============================================================================
  Scenario: Resource Allocation Bound Checker
  Description: This function checks whether a resource allocation request
               (represented by x) fits within the available capacity (y)
               and whether after allocating twice the requested amount,
               the remaining capacity still satisfies a positive reserve.
  Data flow: 
    1. First, func1 compares request (x) against capacity (y) to ensure
       the request does not exceed capacity (x <= y).
    2. Then, func2 verifies that after allocating 2*x, the remaining
       capacity (y - 2*x - 1) is non-negative, ensuring a reserve of 1.
  High-level property: The combined operation ensures that the request
       is not only within capacity but also leaves a positive reserve.
============================================================================*/

/*@
    predicate x_in_range(integer x) = 1 <= x <= 100;
    predicate y_in_range(integer y) = 1 <= y <= 100;
    logic integer compare(integer x, integer y) = x > y ? 1 : 0;
*/

int func1(int x, int y)
{
    //@ assert x_in_range(x);
    //@ assert y_in_range(y);
    //@ assert (x > y) ==> (x > y);
    return x > y ? 1 : 0;
}

#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 100;
    predicate b_in_range(integer b) = 1 <= b && b <= 100;
    predicate non_negative(integer x) = x >= 0;
*/

bool func2(long a, long b)
{
    long c;
    //@ assert a_in_range(a) && b_in_range(b);
    //@ assert non_negative(a) && non_negative(b);
    
    c = b - (a * 2) - 1;
    
    if (c < 0)
    {
        //@ assert c < 0;
        return false;
    }
    else
    {
        //@ assert c >= 0;
        return true;
    }
}

bool resource_allocation_check(int x, int y)
{
    int cmp_result;
    bool final_result;
    
    cmp_result = func1(x, y);
    
    if (cmp_result == 1)
    {
        //@ assert x > y;
        final_result = false;
    }
    else
    {
        //@ assert x <= y;
        final_result = func2((long)x, (long)y);
    }
    
    //@ assert final_result == ((x <= y) && (y - 2*x - 1 >= 0));
    return final_result;
}
