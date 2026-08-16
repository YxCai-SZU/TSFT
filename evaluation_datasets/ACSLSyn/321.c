#include <stdbool.h>
#include <stdint.h>

/* Original function 1: condition_holds check */
/*@
    predicate valid_range_16(integer n, integer m) =
        1 <= n <= 16 &&
        1 <= m <= 16 &&
        n + m <= 16;

    logic integer double_val(integer x) = x * 2;
    logic integer triple_val(integer x) = x * 3;

    predicate condition_holds(integer n, integer m) =
        n == 0 || m == 0 || n == 1 || m == 1 ||
        (double_val(n) <= m && m <= triple_val(n)) ||
        (double_val(m) <= n && n <= triple_val(m));
*/

bool func(unsigned int n, unsigned int m)
{
    bool result;

    if (n == 0 || m == 0 || n == 1 || m == 1) {
        result = true;
    } else {
        result = (n * 2 <= m && m <= n * 3) || (m * 2 <= n && n <= m * 3);
    }

    //@ assert result == (n == 0 || m == 0 || n == 1 || m == 1 || (n * 2 <= m && m <= n * 3) || (m * 2 <= n && n <= m * 3));
    return result;
}

/* Original function 2: even_and_less_than check */
bool even_and_less_than(unsigned int x, unsigned int y)
{
    return (x % 2 == 0) && (x < y);
}

/* Original function 3: midpoint adjustment */
/*@
    predicate valid_range_100(integer x) = 1 <= x <= 100;

    logic integer midpoint(integer a, integer b) = (a + b + 1) / 2;
*/

int64_t func2(uint64_t a, uint64_t b)
{
    uint64_t sum;
    uint64_t result;
    
    sum = a + b;
    result = (sum + 1) / 2;
    
    if (result > a) {
        //@ assert result > a;
        return -1;
    } else {
        //@ assert result == midpoint(a, b);
        return (int64_t)result - 1;
    }
}

/* 
 * Scenario: Network packet buffer validation system
 * Given a buffer descriptor with parameters (n, m) representing two segment sizes,
 * and a data payload (a, b) representing two data blocks,
 * verify that the buffer configuration is valid and the payload can be stored
 * with proper alignment constraints.
 *
 * Data flow:
 * 1. Check if buffer segment sizes (n, m) satisfy the condition_holds property
 *    (ensuring they can accommodate data in a valid ratio)
 * 2. Verify that the payload block sizes (a, b) satisfy even_and_less_than
 *    (ensuring proper alignment and ordering)
 * 3. Compute the adjusted midpoint for buffer placement
 *
 * The synthesized function returns:
 *   -1 if any validation fails or midpoint adjustment fails
 *    A non-negative valid offset value otherwise
 */

int64_t buffer_validation_system(unsigned int n, unsigned int m, 
                                  unsigned int a, unsigned int b,
                                  unsigned int x, unsigned int y)
{
    bool cond_valid;
    bool alignment_ok;
    int64_t offset;

    cond_valid = func(n, m);
    
    alignment_ok = even_and_less_than(a, b);
    
    if (cond_valid && alignment_ok) {
        offset = func2(a, b);
    } else {
        offset = -1;
    }

    //@ assert offset == -1 || (offset >= 0 && offset == midpoint(a, b) - 1);
    
    return offset;
}
