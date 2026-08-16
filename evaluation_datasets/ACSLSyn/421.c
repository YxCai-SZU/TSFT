#include <stdbool.h>
#include <stdint.h>

/* ===== Underlying functions from snippets ===== */

/* First function: condition check */
/*@
    predicate is_even(integer n) = n % 2 == 0;
    predicate condition_holds(integer n, integer k) = 
        is_even(n) || n >= k * 2;
*/
bool cond_func(int n, int k)
{
    bool result;
    if (n % 2 == 0) {
        result = true;
    } else {
        if (n >= k * 2) {
            result = true;
        } else {
            result = false;
        }
    }
    //@ assert result == true <==> condition_holds(n, k);
    return result;
}

/* Second function: modulo 3 check */
/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
    logic integer mod3(integer x) = x % 3;
    lemma mod3_range: \forall integer x; 0 <= x ==> 0 <= mod3(x) <= 2;
*/
bool mod3_func(unsigned int a, unsigned int b) {
    unsigned int sum, sum_mod_3, i, a_mod_3, b_mod_3;
    sum = a + b;
    sum_mod_3 = 0;
    i = 0;
    while (i < sum) {
        sum_mod_3 += 1;
        if (sum_mod_3 == 3) sum_mod_3 = 0;
        i += 1;
    }
    a_mod_3 = 0;
    i = 0;
    while (i < a) {
        a_mod_3 += 1;
        if (a_mod_3 == 3) a_mod_3 = 0;
        i += 1;
    }
    b_mod_3 = 0;
    i = 0;
    while (i < b) {
        b_mod_3 += 1;
        if (b_mod_3 == 3) b_mod_3 = 0;
        i += 1;
    }
    //@ assert a_mod_3 == a % 3;
    //@ assert b_mod_3 == b % 3;
    //@ assert sum_mod_3 == (a + b) % 3;
    return (a_mod_3 == 0) || (b_mod_3 == 0) || (sum_mod_3 == 0);
}

/* Third function: verify multiple relations */
/*@
    predicate is_multiple(integer a, integer b) = a * 2 == b;
    logic integer half(integer x) = x / 2;
    lemma calc_example_4: \forall integer s, t; is_multiple(s, t) ==> s <= half(t);
    lemma intermediate_relations_example: 
        \forall integer a, b, c; 
        is_multiple(a, b) && b * 3 == c ==> a <= c / 6;
*/
int verify_calc_example_4(int* p, int t)
{
    int s = *p;
    //@ assert s * 2 == t;
    //@ assert s <= t / 2;
    return 1;
}

int verify_intermediate_relations_example(int* pa, int* pb, int* pc)
{
    int a = *pa, b = *pb, c = *pc;
    //@ assert a * 2 == b;
    //@ assert b * 3 == c;
    //@ assert a <= c / 6;
    return 1;
}

/* Fourth function: square computation */
/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;
    logic integer square(integer n) = n * n;
    lemma product_bound: \forall integer u, v; 
        is_valid_n(u) && is_valid_n(v) ==> u * v <= 10000;
*/
uint32_t square_func(uint32_t n)
{
    //@ assert is_valid_n(n);
    //@ assert n * n <= 10000;
    return n * n;
}

/* ===== Synthesized complex function ===== */

/* Scenario: Validate a data packet checksum and metadata consistency
   The function processes a packet with two data values (a, b) and a multiplier k,
   and verifies:
   - The squared values satisfy multiple relations (double and triple chain)
   - The condition and modulo checks pass
   - The final assertion captures the high-level property:
     "If the condition holds and modulo check passes, the multiple relations are consistent"
*/

int packet_validation(int a, int b, int k, int* pa, int* pb, int* pc)
{
    bool cond_result;
    bool mod_result;
    int verify_result1, verify_result2;
    uint32_t sq_a, sq_b;

    sq_a = square_func((uint32_t)a);
    sq_b = square_func((uint32_t)b);

    cond_result = cond_func(a, k);

    mod_result = mod3_func((unsigned int)a, (unsigned int)b);

    verify_result1 = verify_calc_example_4(pa, *pb);
    verify_result2 = verify_intermediate_relations_example(pa, pb, pc);

    //@ assert (cond_result == true && mod_result == true) ==> (*pa <= *pc / 6);

    return 1;
}
