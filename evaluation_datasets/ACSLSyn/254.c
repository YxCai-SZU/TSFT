#include <stddef.h>
#include <stdbool.h>

/* ACSL predicates and lemmas from original snippets */

/*@
    predicate non_negative(integer x) = x >= 0;
    predicate within_fifty(integer x) = 0 <= x <= 50;
    predicate result_range(integer r) = 0 <= r <= 2;
*/

/*@
    logic integer total_sum(integer a, integer b, integer c) = a + b + c;
*/

/*@
    lemma sum_non_negative:
        \forall integer a, b, c;
            within_fifty(a) && within_fifty(b) && within_fifty(c) ==>
            non_negative(total_sum(a, b, c));
*/

size_t func1(size_t a, size_t b, size_t c)
{
    size_t sum;
    size_t result;

    sum = a + b + c;

    if (sum >= 2 * b || sum >= 2 * a || sum >= 2 * c)
    {
        //@ assert result_range(1);
        return 1;
    }

    //@ assert sum < 2 * b && sum < 2 * a && sum < 2 * c;
    //@ assert result_range(2);
    return 2;
}

/*@ predicate in_range(integer x) = 1 <= x <= 100; */

bool func2(long A, long B, long C) {
    bool flag = false;
    long value = C - (B - A);
    
    //@ assert value == C - (B - A);
    
    if (value > 0) {
        flag = true;
    }
    
    //@ assert flag == (value > 0);
    
    return flag;
}

/*@
    predicate valid_input(integer a, integer b) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100;

    logic integer sum_val(integer a, integer b) = a + b;

    lemma sum_nonnegative:
        \forall integer a, b; valid_input(a, b) ==> sum_val(a, b) >= 0;
*/

int func3(unsigned int a, unsigned int b)
{
    unsigned int sum;
    int result;
    bool is_even;
    unsigned int temp_sum;

    //@ assert valid_input(a, b);
    sum = a + b;
    //@ assert sum == sum_val(a, b);
    result = 0;
    is_even = true;
    temp_sum = sum;

    while (temp_sum > 0)
    {
        if (temp_sum == 1)
        {
            is_even = false;
            break;
        }
        temp_sum -= 2;
    }

    if (is_even)
    {
        result = (int)(sum / 2);
    }
    else
    {
        result = (int)(sum / 2 + 1);
    }

    //@ assert result >= 0;
    return result;
}

/* Synthesized function: network packet priority classifier
 * Scenario: A network switch classifies incoming packets based on three fields:
 * - priority_level (0-50), packet_size (0-50), destination_port (0-50)
 * - The switch determines a base priority class (1 or 2) using func1
 * - Then checks if the packet is "expedited" using func2 with transformed values
 * - Finally computes a load factor using func3
 * The synthesized function ensures the final classification is consistent.
 */

/*@
    predicate valid_packet(integer a, integer b, integer c) =
        within_fifty(a) && within_fifty(b) && within_fifty(c);
    
    predicate valid_transformed(integer x) = 1 <= x <= 100;
*/

int classify_packet(size_t priority, size_t size, size_t port)
{
    size_t base_class;
    bool expedited;
    int load_factor;
    
    /* Step 1: Determine base priority class */
    base_class = func1(priority, size, port);
    //@ assert result_range(base_class);
    
    /* Step 2: Check expedited status using transformed values (ensuring in_range) */
    /* Transform fields to ensure they are in 1..100 range for func2 */
    long A = (long)(priority + 1);
    long B = (long)(size + 1);
    long C = (long)(port + 1);
    //@ assert in_range(A) && in_range(B) && in_range(C);
    
    expedited = func2(A, B, C);
    
    /* Step 3: Compute load factor using func3 with adapted inputs */
    unsigned int a = (unsigned int)(priority + 1);
    unsigned int b = (unsigned int)(size + 1);
    //@ assert valid_input(a, b);
    
    load_factor = func3(a, b);
    
    /* High-level property: The final load factor is non-negative,
     * which is a key invariant for the packet classification system */
    //@ assert load_factor >= 0;
    
    return load_factor;
}
