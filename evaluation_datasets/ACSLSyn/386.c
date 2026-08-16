#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

/* Original function 1: binary input processor */
/*@
    predicate is_valid_input(unsigned int x) = x <= 1;
    
    logic integer func_result(unsigned int x) = 
        (x == 0) ? 1 : 0;
*/

int32_t func1(unsigned int x)
{
    int32_t y;
    unsigned int i;
    
    //@ assert x <= 1;
    
    if (x == 0) {
        y = 1;
    } else {
        y = 0;
    }
    
    //@ assert y == 1 || y == 0;
    //@ assert (x == 0 ==> y == 1) && (x == 1 ==> y == 0);
    
    i = 0;
    while (i < 10000) {
        //@ assert y == 1 || y == 0;
        i++;
    }
    
    //@ assert y == 1 || y == 0;
    return y;
}

/* Original function 2: range-based min calculator */
/*@
    predicate is_valid_range(integer a, integer b, integer c) =
        0 <= a <= 100 && 0 <= b <= 100 && 0 <= c <= 100;

    logic integer min_three(integer a, integer b, integer c) =
        (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);

    logic integer half_plus_one(integer sum) = (sum / 2) + 1;
*/

int func2(int a, int b, int c)
{
    int result = 0;
    int a_temp = a;
    int b_temp = b;
    int c_temp = c;
    int min_ab = 0;
    int min_abc = 0;
    int quotient = 0;
    int remainder = 0;

    //@ assert is_valid_range(a, b, c);

    if (a_temp < b_temp) {
        min_ab = a_temp;
    } else {
        min_ab = b_temp;
    }
    //@ assert min_ab == ((a < b) ? a : b);

    if (min_ab < c_temp) {
        min_abc = min_ab;
    } else {
        min_abc = c_temp;
    }
    //@ assert min_abc == min_three(a, b, c);

    result += min_abc;
    //@ assert result == min_three(a, b, c);

    remainder = min_abc;
    while (remainder >= 2)
    {
        quotient += 1;
        remainder -= 2;
        //@ assert remainder == min_abc - 2 * quotient;
    }

    result += quotient;
    //@ assert result == min_three(a, b, c) + (min_three(a, b, c) / 2);

    //@ assert result >= 0;
    //@ assert result <= (a + b + c) / 2 + 1;

    return result;
}

/* Original function 3: sum-based validator */
/*@
    predicate total_sum(integer a, integer b, integer c, integer d, integer s) =
        s == a + b + c + d;
*/

bool func3(int a, int b, int c, int d, int e)
{
    int total;
    total = a + b + c + d;
    
    //@ assert total_sum(a, b, c, d, total);
    
    return a <= e && total <= e + 1;
}

/* Original function 4: radius-based square calculator */
/*@
    predicate r_in_range(integer r) = 1 <= r && r <= 100;
    
    logic integer square(integer r) = r * r;
    
    lemma square_bound: \forall integer r; r_in_range(r) ==> square(r) <= 10000;
    lemma result_bound: \forall integer r; r_in_range(r) ==> 3 * square(r) <= 30000;
*/

long func4(long r) {
    long result;
    long i;
    
    result = 0;
    i = 0;
    
    while (i < r) {
        i = i + 1;
    }
    
    //@ assert 1 <= r && r <= 100;
    //@ assert r * r <= 10000;
    //@ assert 3 * (r * r) <= 30000;
    
    result = 3 * (r * r);
    return result;
}

/* 
 * Synthesized function: Network Packet Priority Calculator
 * 
 * Scenario: This function calculates the priority level of a network packet based on:
 *   - flag: binary flag indicating packet type (0 = control, 1 = data)
 *   - a, b, c: three quality of service metrics (each 0-100)
 *   - d: packet size factor (0-100)
 *   - e: buffer capacity (0-100)
 *   - r: signal strength radius (1-100)
 * 
 * The function determines if a packet should be given high priority based on:
 *   1. The binary flag inversion (control packets get higher base priority)
 *   2. The minimum QoS metric plus half of it (as a stability factor)
 *   3. Whether the packet fits within buffer constraints
 *   4. A signal strength multiplier
 * 
 * Control flow: The functions are called in sequence, with the results combined
 * to determine the final priority decision.
 */

int synthesized_packet_priority(
    unsigned int flag,
    int a, int b, int c,
    int d, int e,
    long r
)
{
    int32_t base_priority;
    int stability_factor;
    bool buffer_check;
    long strength_multiplier;
    int final_priority;
    
    base_priority = func1(flag);
    //@ assert base_priority == 1 || base_priority == 0;
    //@ assert (flag == 0 ==> base_priority == 1) && (flag == 1 ==> base_priority == 0);
    
    stability_factor = func2(a, b, c);
    //@ assert stability_factor >= 0;
    //@ assert stability_factor <= (a + b + c) / 2 + 1;
    
    buffer_check = func3(a, b, c, d, e);
    //@ assert buffer_check == (a <= e && (a + b + c + d) <= e + 1);
    
    strength_multiplier = func4(r);
    //@ assert strength_multiplier == 3 * (r * r);
    //@ assert strength_multiplier <= 30000;
    
    if (base_priority == 1 && buffer_check && stability_factor > 0 && strength_multiplier > 0) {
        final_priority = 1;
    } else {
        final_priority = 0;
    }
    
    //@ assert final_priority == 1 || final_priority == 0;
    //@ assert (flag == 0 && a <= e && (a + b + c + d) <= e + 1 && stability_factor > 0) ==> final_priority == 1;
    //@ assert (flag == 1 || !(a <= e && (a + b + c + d) <= e + 1) || stability_factor == 0) ==> final_priority == 0;
    
    return final_priority;
}
