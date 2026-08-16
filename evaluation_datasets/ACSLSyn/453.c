/* 
 * Scenario: Packet validation system for a network protocol
 * Data flow: 
 *   1. Validate packet size (func1) - checks all elements positive
 *   2. Compute packet checksum (func2) - calculates half sum of A*3+P
 *   3. Apply transformation (func3) - computes A - B*2 if condition holds
 *   4. Validate transformation result (func4) - checks evenness and half range
 *
 * The synthesized function validates a packet processing pipeline:
 * - Input: array v (positive values), A, P, B, x, y
 * - Output: boolean indicating if the entire pipeline produced valid results
 */

/*@
    predicate contains_element{L}(int *s, integer len, integer elem) =
        \exists integer i; 0 <= i < len && s[i] == elem;

    predicate all_positive{L}(int *s, integer len) =
        \forall integer i; 0 <= i < len ==> s[i] > 0;

    lemma all_positive_implies_contains:
        \forall int *s, integer len, integer elem;
        all_positive(s, len) && 0 <= elem < len ==> s[elem] > 0;
*/

#include <stdbool.h>
#include <stdint.h>

bool func1(int *v, int len) {
    int i = 0;
    while (i < len) {
        //@ assert 0 <= i < len;
        if (v[i] <= 0) {
            return false;
        }
        i++;
    }
    return true;
}

/*@
    predicate sum_formula(integer A, integer P, integer s) =
        s == A * 3 + P;

    logic integer half_sum(integer s) = s / 2;

    lemma sum_bounds:
        \forall integer A, integer P, integer s;
            0 <= A <= 100 && 0 <= P <= 100 && sum_formula(A, P, s) ==>
            0 <= s <= 400;
*/

unsigned int func2(unsigned int A, unsigned int P)
{
    unsigned int sum;
    unsigned int res;
    unsigned int count;
    unsigned int temp_sum;

    sum = A * 3 + P;
    res = 0;
    count = 0;
    temp_sum = sum;

    //@ assert sum_formula(A, P, sum);

    while (temp_sum >= 2)
    {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
        count += 1;
    }

    res = count;

    //@ assert res >= 0;
    //@ assert res <= (A + P) * 3 / 2;

    return res;
}

/*@ predicate A_in_range(integer a) = 1 <= a <= 10000;
    predicate B_in_range(integer b) = 1 <= b <= 10000;
    predicate condition_holds(integer a, integer b) = a > b * 2;
    predicate result_non_negative(integer r) = r >= 0;
 */

/*@ logic integer compute_result(integer a, integer b) =
        a > b * 2 ? a - b * 2 : 0;
 */

/*@ lemma result_non_negative_lemma:
        \forall integer a, b;
        A_in_range(a) && B_in_range(b) ==>
        result_non_negative(compute_result(a, b));
 */

int32_t func3(uint32_t A, uint32_t B)
{
    int32_t result;
    uint32_t temp;

    //@ assert 1 <= A <= 10000;
    
    if (A > B * 2)
    {
        temp = A - B * 2;
        result = (int32_t)temp;
        //@ assert result == A - B * 2;
    }
    else
    {
        result = 0;
        //@ assert result == 0;
    }
    
    //@ assert result >= 0;
    return result;
}

/*@
    predicate is_even(integer val) = val % 2 == 0;
    predicate half_within_range(integer x, integer y) = y / 2 <= x;
*/

bool func4(unsigned int x, unsigned int y)
{
    bool result;
    //@ assert y % 2 == 0 && y / 2 <= x ==> (y % 2 == 0 && y / 2 <= x);
    result = (y % 2 == 0) && (y / 2 <= x);
    return result;
}

int validate_packet_pipeline(int *v, int len, unsigned int A, unsigned int P, 
                             uint32_t B, unsigned int x, unsigned int y)
{
    bool step1_valid = func1(v, len);
    if (!step1_valid) {
        return 0;
    }
    
    unsigned int checksum_half = func2(A, P);
    
    int32_t transformed = func3(A, B);
    
    bool step4_valid = func4(x, y);
    
    //@ assert (step1_valid == 1) ==> all_positive(v, len);
    //@ assert checksum_half >= 0;
    //@ assert transformed >= 0;
    //@ assert step4_valid <==> (y % 2 == 0 && y / 2 <= x);
    
    return step1_valid && step4_valid ? 1 : 0;
}
