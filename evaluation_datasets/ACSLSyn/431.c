#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

/* ============================================================ */
/* Original functions (adapted with their ACSL specifications) */
/* ============================================================ */

/* --- Function 1: compute_max_balance --- */
/*@ predicate valid_params(integer a, integer b, integer c, integer k) =
   1 <= a && a <= 100 &&
   1 <= b && b <= 100 &&
   1 <= c && c <= 100 &&
   1 <= k && k <= 1000000000000;
*/

/*@ logic integer max_val(integer x, integer y) =
   x > y ? x : y;
*/

/*@ lemma result_bounds:
   \forall integer a, b, c, k, result;
   valid_params(a, b, c, k) &&
   result >= -c && result <= a ==>
   max_val(result, -c) >= -c && max_val(result, -c) <= a;
*/

int32_t compute_max_balance(int32_t a, int32_t b, int32_t c, int64_t k)
{
   int32_t result;
   int64_t temp_k;
   
   result = 0;
   temp_k = k;
   
   if (temp_k >= 1 && a > 0) {
      result += 1;
      temp_k -= 1;
   }
   
   if (temp_k >= 1 && b > 0) {
      temp_k -= 1;
   }
   
   if (temp_k >= 1 && c > 0) {
      result -= 1;
      temp_k -= 1;
   }
   
   int32_t max_val;
   if (result > -c) {
      max_val = result;
   } else {
      max_val = -c;
   }
   
   return max_val;
}

/* --- Function 2: check_color_code --- */
/*@
    predicate valid_color_range(integer x) = 1 <= x <= 9;

    logic integer modulo_4(integer x) = x % 4;
*/

bool check_color_code(int r, int g, int b) {
    int sum;
    int is_divisible;
    int abs_sum;
    int remainder;

    sum = g * 10 + b;
    is_divisible = 0;
    abs_sum = sum;

    if (sum < 0) {
        abs_sum = -sum;
    }

    remainder = abs_sum;

    while (remainder >= 4) {
        remainder -= 4;
    }

    if (remainder == 0) {
        is_divisible = 1;
    }

    return is_divisible;
}

/* --- Function 3: count_rectangles --- */
/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= c && c <= 100;

    logic integer rectangle_count(integer a, integer b, integer c) =
        (a == b && b == c) ? 1 :
        (a != b && b != c && c != a) ? 3 :
        2;

    lemma count_bounds:
        \forall integer a, b, c;
        valid_input(a, b, c) ==>
        1 <= rectangle_count(a, b, c) && rectangle_count(a, b, c) <= 3;
*/

int count_rectangles(unsigned int a, unsigned int b, unsigned int c)
{
    int cnt;
    cnt = 0;

    if (a == b && b == c) {
        cnt += 1;
    } else if (a != b && b != c && c != a) {
        cnt += 3;
    } else {
        cnt += 2;
    }

    return cnt;
}

/* --- Function 4: check_equal --- */
/*@
    predicate valid_equal_range(integer N, integer M) =
        1 <= N <= 100 && 0 <= M <= N;
*/

bool check_equal(unsigned int N, unsigned int M) {
    return N == M;
}

/* ============================================================ */
/* Synthesized function: process_payment_transaction            */
/* Real-world scenario: Payment processing with balance checks, */
/*   color-coded verification, product counting, and validation */
/* ============================================================ */

/*@
    predicate transaction_valid(integer a, integer b, integer c, integer k,
                                integer r, integer g, integer b2,
                                unsigned int prod_a, unsigned int prod_b, unsigned int prod_c,
                                unsigned int N, unsigned int M) =
        valid_params(a, b, c, k) &&
        valid_color_range(r) && valid_color_range(g) && valid_color_range(b2) &&
        valid_input(prod_a, prod_b, prod_c) &&
        valid_equal_range(N, M);
*/

int process_payment_transaction(
    int32_t a, int32_t b, int32_t c, int64_t k,
    int r, int g, int b2,
    unsigned int prod_a, unsigned int prod_b, unsigned int prod_c,
    unsigned int N, unsigned int M)
{
    int32_t max_balance = compute_max_balance(a, b, c, k);

    bool code_valid = check_color_code(r, g, b2);

    int product_count = count_rectangles(prod_a, prod_b, prod_c);

    bool limit_reached = check_equal(N, M);

    int result;
    if (limit_reached && code_valid && max_balance > 0) {
        result = product_count;
    } else {
        result = 1;
    }

    return result;
}
