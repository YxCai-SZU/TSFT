#include <limits.h>
#include <stdint.h>
#include <stdbool.h>

/* ====== Function 1: square_numbers_have_no_remainder ====== */
/*@
    predicate is_positive(integer n) = n > 0;
    
    logic integer square_mod_two(integer n) = (n * n) % 2;
    
    lemma square_mod_two_range: 
        \forall integer n; is_positive(n) ==> 
        (square_mod_two(n) == 0 || square_mod_two(n) == 1);
*/

int square_numbers_have_no_remainder(int n) {
    int result;
    
    //@ assert n > 0;
    result = (n * n) % 2;
    
    //@ assert result == 0 || result == 1;
    return result;
}

/* ====== Function 2: clamp_and_check ====== */
/*@
    predicate in_range(integer x) = -100 <= x <= 100;

    logic integer compute_tmp(integer a, integer b, integer c) = a + b - c;

    lemma tmp_in_range:
        \forall integer a, b, c;
            in_range(a) && in_range(b) && in_range(c) ==>
            -300 <= compute_tmp(a, b, c) <= 300;
*/

int clamp_and_check(int a, int b, int c, int d)
{
    int tmp;
    int result;

    tmp = a + b - c;

    //@ assert -300 <= tmp <= 300;

    if (tmp > 100)
    {
        result = 100;
    }
    else if (tmp < -100)
    {
        result = -100;
    }
    else
    {
        result = tmp;
    }

    //@ assert result == a + b - c || result == -100 || result == 100;
    //@ assert in_range(result);

    return result;
}

/* ====== Function 3: transform ====== */
/*@
    predicate quotient_plus_one_no_overflow(uint32_t x) =
        x / 10 + 1 <= 0x4b1;

    predicate remainder_bound(uint32_t x) =
        x % 10 <= 0x4b0;

    logic integer expected_result(integer x) =
        ((x / 10) + 1) * 100 + (x % 10) * 5;

    lemma quotient_bound: \forall uint32_t x; x <= 0x4b0 ==> x / 10 + 1 <= 0x4b1;
    lemma remainder_bound_lemma: \forall uint32_t x; x <= 0x4b0 ==> x % 10 <= 0x4b0;
    lemma multiplication_bound: \forall integer q; q + 1 <= 0x4b1 ==> (q + 1) * 100 <= 0x4b100;
    lemma final_bound: \forall integer q, r; q + 1 <= 0x4b1 && r <= 0x4b0 ==> 
        (q + 1) * 100 + r * 5 <= 0x4b100 + 0x4b0 * 5;
*/

uint32_t transform(uint32_t x)
{
    uint32_t quotient;
    uint32_t remainder;
    uint32_t result;

    quotient = x / 10;
    remainder = x % 10;

    //@ assert quotient + 1 <= 0x4b1;
    //@ assert (quotient + 1) * 100 <= 0x4b100;
    //@ assert (quotient + 1) * 100 + remainder * 5 <= 0x4b100 + 0x4b0 * 5;

    result = (quotient + 1) * 100 + remainder * 5;
    return result;
}

/* ====== Function 4: check_triangle ====== */
/*@
    predicate valid_triangle(integer a, integer b, integer c) =
        a > 0 && b > 0 && c > 0 &&
        a <= 100 && b <= 100 && c <= 100 &&
        b < a + c && c < b + a && a < b + c;
*/

bool check_triangle(unsigned int numbers[3]) {
    bool result = false;
    unsigned int a = 0;
    unsigned int b = 0;
    unsigned int c = 0;

    a = numbers[0];
    b = numbers[1];
    c = numbers[2];

    if (b < a + c && c < b + a && a < b + c) {
        result = true;
    }

    //@ assert result == (numbers[1] < numbers[0] + numbers[2] && numbers[2] < numbers[1] + numbers[0] && numbers[0] < numbers[1] + numbers[2]);

    return result;
}

/* ====== Synthesized complex function: validate_and_process_triangle_data ====== */
int validate_and_process_triangle_data(unsigned int numbers[3]) {
    bool is_valid;
    int parity_a, parity_b, parity_c;
    int clamped_a, clamped_b, clamped_c;
    uint32_t transformed_a, transformed_b, transformed_c;
    int final_parity;

    is_valid = check_triangle(numbers);
    //@ assert is_valid == (numbers[1] < numbers[0] + numbers[2] && numbers[2] < numbers[1] + numbers[0] && numbers[0] < numbers[1] + numbers[2]);

    if (is_valid) {
        parity_a = square_numbers_have_no_remainder((int)numbers[0]);
        parity_b = square_numbers_have_no_remainder((int)numbers[1]);
        parity_c = square_numbers_have_no_remainder((int)numbers[2]);
    } else {
        parity_a = 0;
        parity_b = 0;
        parity_c = 0;
    }
    //@ assert (is_valid ==> (parity_a == 0 || parity_a == 1));
    //@ assert (is_valid ==> (parity_b == 0 || parity_b == 1));
    //@ assert (is_valid ==> (parity_c == 0 || parity_c == 1));

    clamped_a = clamp_and_check((int)numbers[0], (int)numbers[1], (int)numbers[2], 0);
    clamped_b = clamp_and_check((int)numbers[1], (int)numbers[2], (int)numbers[0], 0);
    clamped_c = clamp_and_check((int)numbers[2], (int)numbers[0], (int)numbers[1], 0);
    //@ assert in_range(clamped_a) && in_range(clamped_b) && in_range(clamped_c);

    transformed_a = transform(numbers[0]);
    transformed_b = transform(numbers[1]);
    transformed_c = transform(numbers[2]);

    final_parity = (parity_a + parity_b + parity_c) % 2;

    //@ assert final_parity == 0 || final_parity == 1;

    return final_parity;
}

int main() {
    return 0;
}
