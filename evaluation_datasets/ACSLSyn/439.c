#include <stdbool.h>
#include <stddef.h>

/* ========== Original functions (adapted only for naming, semantics preserved) ========== */

/* Function 1: triangle sum check */
/*@
    predicate valid_triple(int *a) =
        1 <= a[0] <= 100 && 1 <= a[1] <= 100 && 1 <= a[2] <= 100;

    predicate is_triangle_sum(int *a) =
        a[0] + a[1] == a[2] ||
        a[1] + a[2] == a[0] ||
        a[2] + a[0] == a[1];
*/

bool check_triangle_sum(int *a)
{
    bool result = false;
    int a0 = a[0];
    int a1 = a[1];
    int a2 = a[2];

    //@ assert a0 + a1 <= 200;
    if (a0 + a1 == a2)
    {
        result = true;
    }
    else
    {
        //@ assert a1 + a2 <= 200;
        if (a1 + a2 == a0)
        {
            result = true;
        }
        else
        {
            //@ assert a2 + a0 <= 200;
            if (a2 + a0 == a1)
            {
                result = true;
            }
        }
    }
    return result;
}

/* Function 2: count odd groups */
/*@ predicate valid_array(integer n, int *a) =
      n >= 1 && n <= 100000 &&
      \valid(a + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> 1 <= a[i] && a[i] <= 1000000;
*/

int count_odd_groups(size_t n, int *a) {
    int result = 0;
    size_t count = 0;
    size_t i = 0;
    
    while (i < n) {
        //@ assert i < n;
        if (a[i] & 1) {
            count++;
            if (count == 3) {
                result++;
                count = 0;
            }
        } else {
            count = 0;
        }
        i++;
    }
    
    if (result == 0) {
        result = -1;
    }
    
    //@ assert result >= -1 && result <= (int)n;
    return result;
}

/* Function 3: arithmetic sequence check */
/*@ predicate is_arithmetic_sequence(integer a, integer b, integer c) =
      b - a == c - b;
*/

bool check_arithmetic(int a, int b, int c) {
    bool ans;
    ans = (b - a == c - b);
    //@ assert ans == (b - a == c - b);
    return ans;
}

/* Function 4: minimum weighted sum */
/*@
    predicate valid_digit(integer x) = 1 <= x <= 9;

    logic integer compute_ans(integer a, integer b, integer c, integer i) =
        i == 0 ? a * 10 + b + c :
        i == 1 ? a + b * 10 + c :
                 a + b + c * 10;

    predicate ans_candidate(integer ans, integer a, integer b, integer c) =
        ans == compute_ans(a, b, c, 0) ||
        ans == compute_ans(a, b, c, 1) ||
        ans == compute_ans(a, b, c, 2);
*/

int min_weighted_sum(int a, int b, int c)
{
    int ans = -1;
    int i = 0;

    while (i < 3)
    {
        int ans_t;
        if (i == 0)
        {
            ans_t = a * 10 + b + c;
        }
        else if (i == 1)
        {
            ans_t = a + b * 10 + c;
        }
        else
        {
            ans_t = a + b + c * 10;
        }

        //@ assert ans_t == compute_ans(a, b, c, i);
        //@ assert ans_t >= 0;

        if (ans == -1 || ans_t < ans)
        {
            ans = ans_t;
        }

        i = i + 1;
    }

    //@ assert ans_candidate(ans, a, b, c);
    //@ assert ans >= 0;
    return ans;
}

/* ========== Synthesized complex function: Data packet validator ========== */

/* Scenario: Network packet header validation.
 * A packet consists of a header with three fields (a0, a1, a2) forming a triangle sum,
 * followed by a payload array of odd-group counts, and a trailer with three digits
 * that must form an arithmetic sequence and have a minimum weighted sum constraint.
 *
 * Data flow:
 * 1. Check header triangle sum property
 * 2. Count odd groups in payload
 * 3. Validate trailer arithmetic sequence
 * 4. Compute minimum weighted sum of trailer digits
 * 5. High-level property: if packet is valid, then the minimum weighted sum 
 *    is consistent with the odd group count (both non-negative and bounded)
 */

int validate_packet(int *header, size_t payload_len, int *payload, 
                    int trailer_a, int trailer_b, int trailer_c)
{
    int valid = 0;
    
    bool header_ok = check_triangle_sum(header);
    
    int odd_groups = count_odd_groups(payload_len, payload);
    
    bool trailer_arith = check_arithmetic(trailer_a, trailer_b, trailer_c);
    
    int min_sum = min_weighted_sum(trailer_a, trailer_b, trailer_c);
    
    if (header_ok && odd_groups >= 0 && trailer_arith && min_sum >= 0) {
        valid = 1;
    }
    
    //@ assert (valid == 1) ==> (odd_groups >= 0 && min_sum >= 0);
    
    return valid;
}
