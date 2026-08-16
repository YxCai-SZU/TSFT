#include <stdbool.h>

/*@ predicate x_in_range(integer x) = 1 <= x <= 10; */

/*@
    predicate is_valid_range(integer a) =
        1 <= a && a <= 1000000000;

    logic integer safe_sum(integer a, integer b) =
        a + b;

    lemma sum_in_range:
        \forall integer a, b;
        is_valid_range(a) && is_valid_range(b) ==>
        safe_sum(a, b) <= 9223372036854775807 &&
        safe_sum(a, b) >= -9223372036854775808;
*/

bool func(int x, long long a, long long b, long long c)
{
    //@ assert 1 <= x && x <= 10;
    //@ assert x * x >= 0 && x * x <= 100;
    //@ assert 3 * x >= 0 && 3 * x <= 30;
    
    bool result1 = x * x >= 3 * x;

    //@ assert is_valid_range(a);
    //@ assert is_valid_range(b);
    //@ assert is_valid_range(c);
    
    //@ assert safe_sum(a, b) <= 9223372036854775807;
    //@ assert safe_sum(a, b) >= -9223372036854775808;
    
    long long sum = a + b;
    bool result2 = (sum >= c);
    
    //@ assert result2 == (safe_sum(a, b) >= c);
    
    bool final_result = result1 && result2;
    
    //@ assert final_result == ((x * x >= 3 * x) && (a + b >= c));
    return final_result;
}
