#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 13;
    logic integer total_sum(integer a, integer b, integer c) = a + b + c;
    lemma sum_bounds: \forall integer a, b, c; 
        valid_range(a) && valid_range(b) && valid_range(c) ==> 
        3 <= total_sum(a, b, c) <= 39;
*/

/*@
    requires 1 <= a <= 13;
    requires 1 <= b <= 13;
    requires 1 <= c <= 13;
    ensures \result == true <==> a + b + c < 22;
    ensures \result == false <==> a + b + c >= 22;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int sum;
    
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    
    sum = a + b + c;
    //@ assert 3 <= sum <= 39;
    
    if (sum < 22)
    {
        return true;
    }
    else
    {
        return false;
    }
}
