#include <stdbool.h>

/*@ predicate is_strictly_increasing(integer a, integer b, integer c) =
      a < b && b < c;
    predicate is_strictly_decreasing(integer a, integer b, integer c) =
      a > b && b > c;
    predicate is_monotonic_chain(integer a, integer b, integer c) =
      is_strictly_increasing(a, b, c) || is_strictly_decreasing(a, b, c);
*/

bool func_monotonic(unsigned int A, unsigned int B, unsigned int C)
{
    bool result;
    
    //@ assert 1 <= A <= 100 && 1 <= B <= 100 && 1 <= C <= 100;
    
    if (A == B)
    {
        result = false;
    }
    else if ((A < B && B < C) || (A > B && B > C))
    {
        //@ assert is_monotonic_chain(A, B, C);
        result = true;
    }
    else
    {
        result = false;
    }
    
    return result;
}

/*@ predicate condition_holds(integer a, integer b, integer c, integer k) =
      a >= k || (a + b) >= k || (a + b + c) >= k;
*/

bool func_threshold(int a, int b, int c, int k)
{
    bool result;

    if (a >= k)
    {
        //@ assert condition_holds(a, b, c, k);
        return true;
    }
    
    if (a + b >= k)
    {
        //@ assert condition_holds(a, b, c, k);
        return true;
    }
    
    if (a + b + c >= k)
    {
        //@ assert condition_holds(a, b, c, k);
        return true;
    }
    
    result = false;
    //@ assert !condition_holds(a, b, c, k);
    return result;
}

bool detect_overflow_pattern(unsigned int A, unsigned int B, unsigned int C, int k)
{
    bool is_monotonic;
    bool threshold_reached;
    
    is_monotonic = func_monotonic(A, B, C);
    threshold_reached = func_threshold((int)A, (int)B, (int)C, k);
    
    //@ assert (is_monotonic && threshold_reached) ==> (is_monotonic_chain(A, B, C) && condition_holds(A, B, C, k));
    
    return is_monotonic && threshold_reached;
}
