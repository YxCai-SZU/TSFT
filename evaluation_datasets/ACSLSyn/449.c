#include <limits.h>
#include <stdint.h>

/* ========== Function 1: Compute excess over threshold ========== */
/*@
    predicate valid_range(integer x) = 1 <= x <= 20;
    
    logic integer contribution(integer x) = x > 10 ? x - 10 : 0;
    
    logic integer total_contribution(integer a, integer b, integer c, integer d, integer e) =
        contribution(a) + contribution(b) + contribution(c) + contribution(d) + contribution(e);
*/

int func1(int a, int b, int c, int d, int e)
{
    int res = 0;
    
    //@ assert valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) && valid_range(e);
    
    if (a > 10)
    {
        res += a - 10;
    }
    
    if (b > 10)
    {
        res += b - 10;
    }
    
    if (c > 10)
    {
        res += c - 10;
    }
    
    if (d > 10)
    {
        res += d - 10;
    }
    
    if (e > 10)
    {
        res += e - 10;
    }
    
    //@ assert res >= 0;
    //@ assert res <= a + b + c + d + e;
    //@ assert res <= 5 * 10;
    
    return res;
}

/* ========== Function 2: Compute product and difference ========== */
/*@
    predicate leibniz_precond(integer n, integer d, integer x) =
        0 <= n && n <= 10000 &&
        0 <= d && d <= 10000 &&
        0 <= x && x <= 10000 &&
        n * d <= 1000000000 &&
        x <= n * d;

    lemma leibniz_nonlinear:
        \forall integer n, d, x;
        leibniz_precond(n, d, x) ==>
        0 <= n * d - x && n * d - x <= n * d;
*/

void leibniz_nonlinear(unsigned int n, unsigned int d, unsigned int x) {
    unsigned int product;
    unsigned int diff;

    //@ assert 0 <= n && n <= 10000;
    //@ assert 0 <= d && d <= 10000;
    //@ assert 0 <= x && x <= 10000;
    //@ assert n * d <= 1000000000;
    //@ assert x <= n * d;

    product = n * d;
    diff = product - x;

    //@ assert 0 <= diff && diff <= product;
    //@ assert x <= product && product <= 1000000000;
}

/* ========== Function 3: Count occurrences of maximum ========== */
#include <limits.h>

/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= a <= 9 && 1 <= b <= 9 && 1 <= c <= 9;

    logic integer max_of_three(integer a, integer b, integer c) =
        a > b ? (a > c ? a : c) : (b > c ? b : c);

    lemma result_range:
        \forall integer a, b, c, res;
        valid_input(a, b, c) &&
        res == (a == max_of_three(a, b, c) ? 1 : 0) +
               (b == max_of_three(a, b, c) ? 1 : 0) +
               (c == max_of_three(a, b, c) ? 1 : 0)
        ==> 1 <= res <= 3;
*/

long func3(long A, long B, long C)
{
    long max_value;
    long result;

    //@ assert valid_input(A, B, C);

    if (A > B)
    {
        if (A > C)
        {
            max_value = A;
        }
        else
        {
            max_value = C;
        }
    }
    else
    {
        if (B > C)
        {
            max_value = B;
        }
        else
        {
            max_value = C;
        }
    }

    //@ assert max_value == max_of_three(A, B, C);
    //@ assert max_value == A || max_value == B || max_value == C;

    result = 0;

    if (A == max_value)
    {
        result += 1;
    }
    if (B == max_value)
    {
        result += 1;
    }
    if (C == max_value)
    {
        result += 1;
    }

    //@ assert result >= 1 && result <= 3;
    return result;
}

/* ========== Function 4: Triangle inequality feasibility check ========== */
#include <stdint.h>

/*@
    predicate ans_in_range(integer a) = a == 0 || a == 1;
 */

int32_t func4(uint32_t x)
{
    int32_t ans = 0;
    uint32_t i = 0;
    uint32_t j = 0;
    uint32_t k = 0;

    while (i < 1001)
    {
        j = 0;

        while (j < 1001)
        {
            k = 0;

            while (k < 1001)
            {
                //@ assert ans_in_range(ans);
                if (((i + j) * 2 < x) && ((j + k) * 2 < x) && ((k + i) * 2 < x) && ((i + j) * 2 + (j + k) * 2 >= x))
                {
                    ans = 1;
                    break;
                }
                k += 1;
            }
            if (ans == 1)
            {
                break;
            }
            j += 1;
        }
        if (ans == 1)
        {
            break;
        }
        i += 1;
    }
    //@ assert ans_in_range(ans);
    return ans;
}

/* ========== Synthesized Complex Function: Resource Allocation Verifier ========== */

int32_t resource_alloc_verify(
    int threshold_a, int threshold_b, int threshold_c, int threshold_d, int threshold_e,
    unsigned int n, unsigned int d, unsigned int x,
    long A, long B, long C,
    uint32_t search_x)
{
    int excess = func1(threshold_a, threshold_b, threshold_c, threshold_d, threshold_e);
    //@ assert excess >= 0 && excess <= threshold_a + threshold_b + threshold_c + threshold_d + threshold_e;

    leibniz_nonlinear(n, d, x);

    long priority_count = func3(A, B, C);
    //@ assert priority_count >= 1 && priority_count <= 3;

    int32_t feasible = func4(search_x);
    //@ assert feasible == 0 || feasible == 1;

    int32_t result = (excess >= 0 && priority_count >= 1 && feasible == 1) ? 1 : 0;

    //@ assert (result == 1) ==> (excess >= 0 && priority_count >= 1 && feasible == 1);

    return result;
}
