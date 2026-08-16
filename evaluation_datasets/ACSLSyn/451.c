#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* Predicates from original functions */
/*@ predicate is_valid_array(integer n, int *a) =
      n > 0 && n <= 200000 &&
      \valid(a + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> 1 <= a[i] <= n;
*/

/*@ predicate is_valid_range(integer a, integer b, integer x) =
      x >= a && x <= a + b;
*/

/*@ predicate within_range(integer x) = -16 <= x < 16; */

/*@ predicate valid_input(integer a, integer b, integer c) =
      0 <= a && a <= 50 &&
      0 <= b && b <= 50 &&
      0 <= c && c <= 50;
*/

/* Logic functions from original functions */
/*@ logic integer octuple_val(integer x) = 8 * x; */

/*@ logic integer max_of(integer a, integer b, integer c) =
      (a >= b && a >= c) ? a :
      (b >= a && b >= c) ? b :
      c;
*/

/*@ logic integer sum(integer a, integer b, integer c) = a + b + c; */

/* Lemmas */
/*@ lemma range_implies_valid:
      \forall integer a, b, x;
        1 <= a <= 100 && 1 <= b <= 100 && 1 <= x <= 200 &&
        x >= a && x <= a + b ==> is_valid_range(a, b, x);
*/

/*@ lemma not_range_implies_not_valid:
      \forall integer a, b, x;
        1 <= a <= 100 && 1 <= b <= 100 && 1 <= x <= 200 &&
        !(x >= a && x <= a + b) ==> !is_valid_range(a, b, x);
*/

/*@ lemma octuple_lemma:
    \forall integer x; within_range(x) ==> octuple_val(x) == 8 * x;
*/

/*@ lemma max_non_negative:
        \forall integer a, b, c;
        valid_input(a, b, c) ==> max_of(a, b, c) >= 0;
*/

/*@ lemma sum_bounds:
        \forall integer a, b, c;
        valid_input(a, b, c) ==> 0 <= sum(a, b, c) <= 150;
*/

/* Original function 1: count breaks in array */
int func1(size_t n, int *a) {
    int breaks = 0;
    size_t i = 1;
    
    while (i < n) {
        //@ assert 0 <= i-1 < n;
        if ((int)i == a[i - 1]) {
            breaks += 1;
        }
        i += 1;
    }
    
    return (breaks > 0) ? (int)n - breaks : -1;
}

/* Original function 2: range check */
bool func2(unsigned long a, unsigned long b, unsigned long x)
{
    bool is_valid = false;
    //@ assert 1 <= a <= 100 && 1 <= b <= 100 && 1 <= x <= 200;
    
    if (x >= a) {
        if (x <= a + b) {
            is_valid = true;
        }
    }
    
    unsigned long i = 0;
    while (i < 10) {
        i = i + 1;
    }
    
    if (is_valid) {
        //@ assert x >= a && x <= a + b;
        return true;
    } else {
        //@ assert !(x >= a && x <= a + b);
        return false;
    }
}

/* Original function 3: range check and octuple */
bool is_within_range(signed char n) {
    bool b;
    //@ assert -100 <= n <= 100;
    b = (n >= -16 && n < 16);
    //@ assert b == true <==> within_range(n);
    return b;
}

signed char octuple(signed char x1) {
    signed char x2;
    signed char x4;
    signed char x8;
    
    //@ assert within_range(x1);
    x2 = x1 + x1;
    //@ assert x2 == 2 * x1;
    x4 = x2 + x2;
    //@ assert x4 == 4 * x1;
    x8 = x4 + x4;
    //@ assert x8 == 8 * x1;
    //@ assert x8 == octuple_val(x1);
    return x8;
}

/* Original function 4: compute score based on max and sum */
uint32_t func4(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t max;
    uint32_t l;

    //@ assert valid_input(a, b, c);

    if (a >= b && a >= c)
    {
        max = a;
    }
    else if (b >= a && b >= c)
    {
        max = b;
    }
    else
    {
        max = c;
    }

    l = a + b + c;

    //@ assert max == max_of(a, b, c);
    //@ assert l == sum(a, b, c);

    if (l % 3 == 0)
    {
        if (max * 2 < l / 3)
        {
            //@ assert max * 2 < l / 3;
            return 0;
        }
        else
        {
            //@ assert max * 2 >= l / 3;
            return 2;
        }
    }
    else if (max * 2 < (l / 3) + 1)
    {
        //@ assert max * 2 < (l / 3) + 1;
        return 1;
    }
    else
    {
        //@ assert max * 2 >= (l / 3) + 1;
        return 0;
    }
}

/* Synthesized function: Data Packet Integrity Validator
 * 
 * Real-world scenario: A network packet validator that checks packet array integrity,
 * validates packet range, checks payload size, and computes a quality score.
 * 
 * Data flow:
 * 1. Check if packet indices in array are valid (func1)
 * 2. Validate packet range (func2)
 * 3. Check and transform payload size (is_within_range, octuple)
 * 4. Compute final quality score (func4)
 */

uint32_t validate_packet(size_t n, int *a, 
                         unsigned long pkt_start, unsigned long pkt_len, unsigned long pkt_id,
                         signed char payload_size,
                         uint32_t score_a, uint32_t score_b, uint32_t score_c)
{
    int array_status;
    bool range_valid;
    bool size_valid;
    signed char transformed_size;
    uint32_t final_score;
    
    array_status = func1(n, a);
    //@ assert array_status >= -1 && array_status <= (int)n - 1;
    
    range_valid = func2(pkt_start, pkt_len, pkt_id);
    
    size_valid = is_within_range(payload_size);
    
    if (size_valid) {
        //@ assert within_range(payload_size);
        transformed_size = octuple(payload_size);
        //@ assert transformed_size == octuple_val(payload_size);
    } else {
        transformed_size = 0;
    }
    
    final_score = func4(score_a, score_b, score_c);
    
    //@ assert final_score >= 0 && final_score <= 2;
    
    /* Core high-level property: The final score is always between 0 and 2,
     * representing a valid quality assessment regardless of all intermediate
     * validation steps. This ensures the packet validator always produces
     * a meaningful output.
     */
    
    return final_score;
}
