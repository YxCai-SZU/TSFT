#include <stdbool.h>
#include <stddef.h>

/* ============================================================
   Scenario: Mail Sorting System - Package Priority Calculator
   ============================================================ */

/*@
    predicate valid_vec(int *a, size_t len) =
        len == 2 &&
        \valid(a + (0 .. 1)) &&
        1 <= a[0] <= 20 &&
        1 <= a[1] <= 20;

    logic integer vec_sum(integer a0, integer a1) = a0 + a1;

    lemma sum_bounds:
        \forall integer a0, a1;
        1 <= a0 <= 20 && 1 <= a1 <= 20 ==> 2 <= vec_sum(a0, a1) <= 40;

    lemma diff_nonnegative:
        \forall integer a0, a1;
        vec_sum(a0, a1) >= 10 ==> vec_sum(a0, a1) - 10 >= 0;
*/

int func1(int *a, size_t len) {
    int sum;
    int result;

    sum = a[0] + a[1];

    if (sum < 10) {
        result = 0;
    } else {
        result = sum - 10;
    }

    return result;
}

/* ===== Original function 2 (adapted for clarity) ===== */
/*@
    predicate is_small(integer a, integer b) = 1 <= a <= 9 && 1 <= b <= 9;
    predicate is_valid_input(integer a, integer b) = 1 <= a <= 20 && 1 <= b <= 20;

    lemma product_in_range:
        \forall integer a, b;
            is_small(a, b) ==> a * b <= 81;
*/

int func2(unsigned int a, unsigned int b)
{
    unsigned int answer = 0;
    unsigned int temp_a = a;
    unsigned int temp_b = b;

    if (a > 9 || b > 9)
    {
        return -1;
    }

    if (a == 1)
    {
        answer = temp_b;
    }
    else if (a == 2)
    {
        answer = temp_b * 2;
    }
    else if (a == 3)
    {
        answer = temp_b * 3;
    }
    else if (a == 4)
    {
        answer = temp_b * 4;
    }
    else if (a == 5)
    {
        answer = temp_b * 5;
    }
    else if (a == 6)
    {
        answer = temp_b * 6;
    }
    else if (a == 7)
    {
        answer = temp_b * 7;
    }
    else if (a == 8)
    {
        answer = temp_b * 8;
    }
    else if (a == 9)
    {
        answer = temp_b * 9;
    }

    return (int)answer;
}

/* ===== Original function 3 (adapted for clarity) ===== */
/*@
    predicate valid_range(integer k, integer a, integer b) =
        1 <= k <= 1000 && 1 <= a <= b <= 1000;

    logic integer bound(integer k) = k * 2 - 1;

    predicate condition_holds(integer k, integer a, integer b) =
        a == b || (a < b && b - a <= bound(k));
*/

bool func3(unsigned int k, unsigned int a, unsigned int b)
{
    bool result;

    if (a == b) {
        result = true;
    } else if (b - a <= (k * 2 - 1)) {
        result = true;
    } else {
        result = false;
    }

    return result;
}

/* ===== Original function 4 (adapted for clarity) ===== */
/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 1000000000;
    predicate loop_inv(integer n, integer i, integer result) =
        is_valid_n(n) &&
        1 <= i && i <= n / 2 + 1 &&
        result <= 3 * i / 2 &&
        (i > 1 ==> result <= 3 * n / 2);
*/

unsigned long func4(unsigned long n)
{
    unsigned long i;
    unsigned long result;
    
    i = 1;
    result = 0;
    
    while (i <= n / 2)
    {
        if (i * 3 <= n)
        {
            result += 1;
        }
        i += 1;
    }
    
    return result;
}

/* ============================================================
   Synthesized Function: compute_priority
   ============================================================ */

/*@
    predicate valid_priority_input(int *vec, size_t len,
                                    unsigned int cat1, unsigned int cat2,
                                    unsigned int k, unsigned int a, unsigned int b,
                                    unsigned long n) =
        valid_vec(vec, len) &&
        is_valid_input(cat1, cat2) &&
        valid_range(k, a, b) &&
        is_valid_n(n);
*/

unsigned long compute_priority(int *vec, size_t len,
                               unsigned int cat1, unsigned int cat2,
                               unsigned int k, unsigned int a, unsigned int b,
                               unsigned long n)
{
    int base_score;
    int multiplier;
    bool fits_constraints;
    unsigned long complexity;
    unsigned long priority;

    base_score = func1(vec, len);

    multiplier = func2(cat1, cat2);

    fits_constraints = func3(k, a, b);

    complexity = func4(n);

    if (multiplier == -1) {
        priority = (unsigned long)(base_score) + complexity;
    } else {
        priority = (unsigned long)(base_score) + (unsigned long)(multiplier) + complexity;
    }

    if (!fits_constraints) {
        priority = priority / 2;
    }

    return priority;
}
