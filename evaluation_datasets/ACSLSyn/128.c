#include <stdbool.h>

/* First function: validates range and computes floor to nearest hundred */
/*@
    predicate is_valid_range(integer x) = 1 <= x <= 1000000000000;
    
    logic integer calculate_val(integer x) = (x / 100) * 100;
    
    lemma val_calculation: \forall integer x; is_valid_range(x) ==> calculate_val(x) == (x / 100) * 100;
*/

bool func(unsigned long long x)
{
    unsigned long long val;
    
    //@ assert is_valid_range(x);
    
    val = (x / 100) * 100;
    
    //@ assert val == (x / 100) * 100;
    
    return val <= x;
}

/* Second function: finds maximum of three integers */
/*@
    predicate is_in_range(integer x) = 1 <= x <= 100;

    logic integer max_of_three(integer a, integer b, integer c) =
        (a >= b && a >= c) ? a : ((b >= a && b >= c) ? b : c);

    lemma max_is_one_of:
        \forall integer a, b, c;
        is_in_range(a) && is_in_range(b) && is_in_range(c) ==>
        (max_of_three(a, b, c) == a || max_of_three(a, b, c) == b || max_of_three(a, b, c) == c);
*/

int max_of_three(int a, int b, int c)
{
    int max = a;
    //@ assert max == a;
    //@ assert is_in_range(max);

    if (b > max)
    {
        max = b;
        //@ assert max == b;
    }
    //@ assert max == a || max == b;
    //@ assert max >= a && max >= b;

    if (c > max)
    {
        max = c;
        //@ assert max == c;
    }
    //@ assert max == a || max == b || max == c;
    //@ assert max >= a && max >= b && max >= c;

    int ret = max;
    //@ assert ret == max_of_three(a, b, c);
    //@ assert ret == a || ret == b || ret == c;

    return ret;
}

/* Synthesized function: Validates a data packet by checking range and extracting metadata
 * Scenario: In a network protocol, a packet's length field (x) must be in valid range,
 * and three metadata bytes (a, b, c) must be valid. The function ensures the packet
 * is valid (length is floor-rounded) and returns the maximum metadata byte.
 */
int process_packet(unsigned long long x, int a, int b, int c)
{
    bool valid_length = func(x);
    
    int max_meta = max_of_three(a, b, c);
    
    //@ assert (valid_length == ((x / 100) * 100 <= x)) && (max_meta == a || max_meta == b || max_meta == c);
    
    return max_meta;
}
