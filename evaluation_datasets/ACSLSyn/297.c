#include <limits.h>
#include <stdint.h>

/* ===== Original function 1: max_digit_difference_nums ===== */
/*@
    predicate valid_input(integer n) =
        n >= -999999999 && n <= 999999999;

    logic integer abs_val(integer n) =
        n < 0 ? -n : n;

    predicate max_diff_bounds(integer diff) =
        diff >= 0 && diff <= 9;
*/

int max_digit_difference_nums(int n1, int n2)
{
    unsigned int num1;
    unsigned int num2;
    int max_diff;

    max_diff = 0;
    num1 = (unsigned int)(n1 < 0 ? -n1 : n1);
    num2 = (unsigned int)(n2 < 0 ? -n2 : n2);

    while (num1 > 0 || num2 > 0)
    {
        unsigned int digit1;
        unsigned int digit2;
        int diff;

        digit1 = num1 % 10;
        digit2 = num2 % 10;
        diff = (int)(digit1 > digit2 ? digit1 - digit2 : digit2 - digit1);

        //@ assert 0 <= diff <= 9;
        if (diff > max_diff)
        {
            max_diff = diff;
        }

        num1 = num1 / 10;
        num2 = num2 / 10;
    }

    //@ assert 0 <= max_diff <= 9;
    return max_diff;
}

/* ===== Original function 2: func (square) ===== */
/*@
    predicate valid_range_sq(integer r) = 1 <= r <= 100;
    
    logic integer square(integer r) = r * r;
    
    lemma square_bounds: 
        \forall integer r; valid_range_sq(r) ==> 1 <= square(r) <= 10000;
*/

int64_t func(int64_t r)
{
    int64_t result;
    
    //@ assert valid_range_sq(r);
    
    //@ assert 1 <= r * r <= 10000;
    
    result = r * r;
    
    //@ assert result == square(r);
    return result;
}

int64_t input(void)
{
    int64_t result = 1;
    
    //@ assert result == 1;
    return result;
}

/* ===== Original function 3: func (digit transform) ===== */
/*@
    predicate valid_range_digit(integer x) = 1 <= x <= 9;

    logic integer max_of_two(integer x, integer y) = (x > y) ? x : y;
    logic integer max_of_three(integer x, integer y, integer z) = max_of_two(max_of_two(x, y), z);

    logic integer compute_result(integer a, integer b, integer c, integer max2) =
        (a == max2) ? (a + b * 10 + c + 1) :
        (b == max2) ? (a * 10 + b + c + 1) :
                      (a + b + c * 10 + 1);

    lemma result_satisfies_post:
        \forall integer a, b, c, max2;
        valid_range_digit(a) && valid_range_digit(b) && valid_range_digit(c) &&
        max2 == max_of_three(a, b, c) ==>
        compute_result(a, b, c, max2) == a + b + 10 * c + 1 ||
        compute_result(a, b, c, max2) == a + 10 * b + c + 1 ||
        compute_result(a, b, c, max2) == 10 * a + b + c + 1;
*/

long digit_transform(long a, long b, long c)
{
    long max1;
    long max2;
    long result;

    //@ assert valid_range_digit(a);
    //@ assert valid_range_digit(b);
    //@ assert valid_range_digit(c);

    max1 = (a > b) ? a : b;
    //@ assert max1 == max_of_two(a, b);

    max2 = (max1 > c) ? max1 : c;
    //@ assert max2 == max_of_three(a, b, c);

    if (a == max2)
    {
        result = a + b * 10 + c + 1;
    }
    else if (b == max2)
    {
        result = a * 10 + b + c + 1;
    }
    else
    {
        result = a + b + c * 10 + 1;
    }
    //@ assert result == compute_result(a, b, c, max2);

    //@ assert result == a + b + 10 * c + 1 || result == a + 10 * b + c + 1 || result == 10 * a + b + c + 1;
    return result;
}

/* ===== Synthesized function: process_encoded_digit_pair ===== */
/* Scenario: In a digit-based encoding system, two input numbers are compared digit-by-digit 
   to find the maximum digit difference. This difference is then used as a scaling factor 
   for a square operation, and the result is combined with a three-digit transformation 
   to produce an encoded output. The flow is: 
   1) Compute max_digit_difference_nums(n1, n2) -> diff (0..9)
   2) Use diff+1 as input to func (square) -> scaled_val (square of diff+1)
   3) Use the three digits (diff, diff+1, diff+2) as inputs to digit_transform -> encoded_part
   4) Final result = scaled_val * 1000 + encoded_part
   The core property: the final result lies within a predictable range.
*/

long process_encoded_digit_pair(int n1, int n2)
{
    int diff;
    int64_t scaled_val;
    long a, b, c;
    long encoded_part;
    long final_result;

    diff = max_digit_difference_nums(n1, n2);
    //@ assert 0 <= diff <= 9;

    scaled_val = func((int64_t)(diff + 1));
    //@ assert 1 <= scaled_val <= 100;
    //@ assert scaled_val == (int64_t)(diff+1) * (int64_t)(diff+1);

    a = (long)(diff == 0 ? 1 : diff);
    b = (long)(diff + 1 > 9 ? diff + 1 - 9 : diff + 1);
    c = (long)(diff + 2 > 9 ? diff + 2 - 9 : diff + 2);
    //@ assert 1 <= a <= 9;
    //@ assert 1 <= b <= 9;
    //@ assert 1 <= c <= 9;

    encoded_part = digit_transform(a, b, c);
    //@ assert encoded_part == a + b + 10 * c + 1 || encoded_part == a + 10 * b + c + 1 || encoded_part == 10 * a + b + c + 1;

    final_result = (long)scaled_val * 1000 + encoded_part;

    //@ assert 1 <= final_result / 1000 <= 100;  // scaled_val is 1..100
    //@ assert 0 <= final_result % 1000 <= 999; // encoded_part is at most 9+9*10+9*100+1 = 1000, but actually <= 999

    return final_result;
}

int main(void)
{
    return 0;
}
