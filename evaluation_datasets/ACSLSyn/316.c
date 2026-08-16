#include <stdint.h>
#include <stdbool.h>

/* First function: product selection */
/*@
    predicate in_range(integer x) = 1 <= x <= 100;
    
    logic integer product(integer x, integer y) = x * y;
    
    lemma product_bound:
        \forall integer x, y;
            in_range(x) && in_range(y) ==> product(x, y) <= 10000;
*/

uint32_t func1(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t ans;
    
    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    
    if (a > b)
    {
        //@ assert product(a, c) <= 10000;
        //@ assert product(b, 100 - a) <= 10000;
        
        if (c * a > b * (100 - a))
        {
            ans = c * a;
        }
        else
        {
            ans = b * (100 - a);
        }
    }
    else
    {
        //@ assert product(a, c) <= 10000;
        //@ assert product(b, 100 - a) <= 10000;
        
        if (b * (100 - a) > c * a)
        {
            ans = b * (100 - a);
        }
        else
        {
            ans = c * a;
        }
    }
    
    //@ assert ans == product(c, a) || ans == product(b, 100 - a);
    return ans;
}

/* Second function: range computation */
/*@
    predicate valid_range(integer n, integer m) =
        1 <= n <= 20 && 1 <= m <= 20;

    logic integer compute_result(integer n, integer m) =
        n > m ? 0 : (m - n) / 2;

    lemma result_nonnegative:
        \forall integer n, m; valid_range(n, m) ==> compute_result(n, m) >= 0;
*/

int32_t func2(uint32_t n, uint32_t m) {
    int32_t result;
    uint32_t d;

    if (n > m) {
        result = 0;
        //@ assert result == 0;
        return result;
    } else {
        d = m - n;
        //@ assert d == m - n;
        result = (int32_t)(d / 2);
        //@ assert result == (m - n) / 2;
        return result;
    }
}

/* Third function: even check */
/*@ predicate is_even_result(integer test_value, bool result) =
      result == (test_value % 2 == 0);
*/

bool is_even(unsigned int test_value)
{
    unsigned int temp_value;
    bool result;
    
    temp_value = test_value;
    
    while (temp_value >= 2)
    {
        //@ assert temp_value >= 2;
        temp_value -= 2;
    }
    
    result = (temp_value == 0);
    //@ assert result == (test_value % 2 == 0);
    return result;
}

/* Scenario: Data packet processing in a network protocol.
 * The function processes a packet's header fields:
 * - a: packet priority (1-100)
 * - b: buffer size (1-100)
 * - c: payload size (1-100)
 * - n: segment index (1-20)
 * - m: total segments (1-20)
 * - test_value: checksum seed
 * 
 * It computes a selection value, a segment offset, and validates parity.
 * The final assertion verifies that the output is consistent with the
 * protocol's invariant: the selection value is bounded and parity is valid.
 */

int process_packet(uint32_t a, uint32_t b, uint32_t c, 
                   uint32_t n, uint32_t m, unsigned int test_value)
{
    uint32_t selection = func1(a, b, c);
    int32_t offset = func2(n, m);
    bool parity_ok = is_even(test_value);
    
    //@ assert (selection == c * a || selection == b * (100 - a)) && (parity_ok == (test_value % 2 == 0));
    
    if (parity_ok && offset >= 0)
    {
        return 0; // Packet valid
    }
    else
    {
        return 1; // Packet invalid
    }
}

int main(void)
{
    return 0;
}
