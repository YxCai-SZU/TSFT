#include <stdint.h>
#include <stdbool.h>

/* ========== Provided Functions (with ACSL specs) ========== */

/* --- Function 1: Sum of first n natural numbers --- */
/*@
    predicate is_valid_range(integer n) = 1 <= n <= 100;
    logic integer sum_formula(integer i) = (i - 1) * i / 2;
    lemma sum_step: \forall integer i; 1 <= i <= 100 ==> 
        sum_formula(i) + i == i * (i + 1) / 2;
*/
uint64_t sum_natural(uint64_t n) {
    uint64_t sum;
    uint64_t i;
    sum = 0;
    i = 1;
    while (i <= n) {
        //@ assert 0 <= i * (i + 1) <= 100 * (100 + 1);
        //@ assert sum + i >= sum;
        //@ assert sum + i == i * (i + 1) / 2;
        sum = sum + i;
        i = i + 1;
    }
    return sum;
}

/* --- Function 2: Check if product of two numbers is even --- */
/*@
    predicate a_in_range(integer a) = 1 <= a <= 10000;
    predicate b_in_range(integer b) = 1 <= b <= 10000;
    predicate product_in_range(integer p) = 1 <= p <= 100000000;
    predicate is_even_result(integer p, bool r) = r == (p % 2 == 0);
    logic integer safe_product(integer a, integer b) = a * b;
    lemma product_range: \forall integer a, b; 
        a_in_range(a) && b_in_range(b) ==> product_in_range(safe_product(a, b));
*/
bool is_product_even(int a, int b) {
    unsigned int a_unsigned;
    unsigned int b_unsigned;
    unsigned int product;
    bool is_even = true;
    unsigned int temp;
    a_unsigned = (a < 0) ? (unsigned int)(a + 1) : (unsigned int)a;
    b_unsigned = (b < 0) ? (unsigned int)(b + 1) : (unsigned int)b;
    //@ assert 1 <= a_unsigned && a_unsigned <= 10000;
    //@ assert 1 <= b_unsigned && b_unsigned <= 10000;
    //@ assert a_unsigned * b_unsigned <= 100000000;
    product = a_unsigned * b_unsigned;
    //@ assert product_in_range(product);
    temp = product;
    while (temp > 0) {
        if (temp == 1) {
            is_even = false;
            break;
        }
        temp -= 2;
    }
    //@ assert is_even_result(product, is_even);
    //@ assert is_even_result(a * b, is_even);
    return is_even;
}

/* --- Function 3: Condition check on two integers --- */
/*@
    predicate is_in_range(integer v) = 1 <= v && v <= 100;
    logic integer condition_value(integer a, integer b) =
        (a <= 0 ? 1 : 0) + (b <= 0 ? 1 : 0) + (a > 10 ? 1 : 0) + (b > 10 ? 1 : 0) + (a == b ? 1 : 0);
    lemma condition_equivalence:
        \forall integer a, b;
            is_in_range(a) && is_in_range(b) ==>
            (condition_value(a, b) > 0) == (a <= 0 || b <= 0 || a > 10 || b > 10 || a == b);
*/
bool check_condition(int a, int b) {
    bool result;
    //@ assert is_in_range(a);
    //@ assert is_in_range(b);
    if (a <= 0 || b <= 0 || a > 10 || b > 10 || a == b) {
        //@ assert a <= 0 || b <= 0 || a > 10 || b > 10 || a == b;
        result = true;
    } else {
        //@ assert !(a <= 0 || b <= 0 || a > 10 || b > 10 || a == b);
        result = false;
    }
    //@ assert result == (a <= 0 || b <= 0 || a > 10 || b > 10 || a == b);
    return result;
}

/* ========== Synthesized Complex Function ========== */

bool process_data(uint64_t n, int a, int b, int x, int y) {
    uint64_t sum;
    bool cond_result;
    bool even_result;
    bool final_result;

    sum = sum_natural(n);
    //@ assert sum == (n * (n + 1)) / 2;
    //@ assert sum > 0;

    cond_result = check_condition(a, b);
    //@ assert cond_result == (a <= 0 || b <= 0 || a > 10 || b > 10 || a == b);

    even_result = is_product_even(x, y);
    //@ assert even_result == ((x * y) % 2 == 0);

    if (cond_result) {
        final_result = (sum > 0) && even_result;
        //@ assert final_result == (sum > 0 && even_result);
    } else {
        final_result = (sum % 2 == 0) && even_result;
        //@ assert final_result == (sum % 2 == 0 && even_result);
    }

    //@ assert final_result == (even_result && (cond_result ? sum > 0 : sum % 2 == 0));

    return final_result;
}
