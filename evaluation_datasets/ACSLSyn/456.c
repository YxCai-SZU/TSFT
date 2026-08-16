#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/* Original function 1: parity check */
/*@
    predicate in_range(integer x) = 1 <= x <= 100;
    logic integer parity(integer a, integer b) = (a + b) % 2;
*/
int32_t func1(uint32_t a, uint32_t b)
{
    int32_t result;
    //@ assert in_range(a) && in_range(b);
    
    if ((a + b) % 2 == 0) {
        if (a >= 1 && a <= 100) {
            if (b >= 1 && b <= 100) {
                //@ assert parity(a, b) == 0;
                result = 0;
            } else {
                //@ assert b < 1 || b > 100;
                result = 1;
            }
        } else {
            if (b >= 1 && b <= 100) {
                //@ assert a < 1 || a > 100;
                result = 1;
            } else {
                //@ assert a < 1 || a > 100 && b < 1 || b > 100;
                result = 0;
            }
        }
    } else {
        if (a >= 1 && a <= 100) {
            if (b >= 1 && b <= 100) {
                //@ assert parity(a, b) != 0;
                result = 1;
            } else {
                //@ assert b < 1 || b > 100;
                result = 0;
            }
        } else {
            if (b >= 1 && b <= 100) {
                //@ assert a < 1 || a > 100;
                result = 0;
            } else {
                //@ assert a < 1 || a > 100 && b < 1 || b > 100;
                result = 1;
            }
        }
    }
    
    //@ assert result >= 0 && result <= 1;
    return result;
}

/* Original function 2: size calculation */
/*@
    predicate valid_n(integer n) = 1 <= n && n <= 1000000;
    logic integer ans_formula(integer n) = 
        1000 * (n / 1000) + (n % 1000) * 2;
*/
size_t func2(size_t n)
{
    size_t ans = 0;
    size_t i = 1;
    size_t limit = n / 1000;
    
    while (i <= limit)
    {
        //@ assert ans + 1000 == 1000 * i;
        ans += 1000;
        i += 1;
    }
    
    //@ assert ans == 1000 * limit;
    ans += (n % 1000) * 2;
    
    //@ assert ans <= ans_formula(n);
    return ans;
}

/* Original function 3: digit nine check */
/*@ predicate is_nine(integer n) = n % 10 == 9 || (n / 10) % 10 == 9; */
bool func3(int n)
{
    int n_abs;
    int quotient;
    int remainder;
    int last_digit;
    int first_digit;
    bool is_nine_result;

    n_abs = (n < 0) ? -n : n;

    quotient = 0;
    remainder = n_abs;

    while (remainder >= 10)
    {
        quotient = quotient + 1;
        remainder = remainder - 10;
    }

    last_digit = remainder;
    first_digit = quotient;

    //@ assert quotient == n_abs / 10;
    //@ assert remainder == n_abs % 10;

    is_nine_result = (last_digit == 9) || (first_digit == 9);

    //@ assert is_nine_result == 1 <==> is_nine(n_abs);

    return is_nine_result;
}

/* Original function 4: offset calculation */
/*@
    predicate valid_params(integer n, integer m) =
        1 <= n <= 100 && 1 <= m <= 100;

    logic integer func_result(integer n, integer m) =
        n > m - 1 ? n - m + 1 : 0;

    lemma result_properties:
        \forall integer n, m;
        valid_params(n, m) ==>
        (
            func_result(n, m) >= 0 &&
            func_result(n, m) <= n &&
            (func_result(n, m) == n - m + 1 || func_result(n, m) == 0)
        );
*/
int func4(int n, int m)
{
    int max_value;
    int result;

    //@ assert valid_params(n, m);
    
    if (n > m - 1)
    {
        max_value = n;
        //@ assert max_value == n;
        result = n - m + 1;
    }
    else
    {
        max_value = m - 1;
        //@ assert max_value == m - 1;
        result = 0;
    }

    //@ assert result >= 0;
    //@ assert result <= n;
    //@ assert result == n - m + 1 || result == 0;
    return result;
}

/* 
 * Scenario: Data packet validation and offset computation for a network protocol
 * 
 * This function simulates processing a network packet where:
 * - func1 checks if two header fields have valid parity (0 for even, 1 for odd)
 * - func2 computes the payload size based on a size field
 * - func3 checks if a two-digit packet type contains digit 9 (error indicator)
 * - func4 computes the data offset within the packet
 * 
 * The combined function validates a packet and computes the final offset,
 * ensuring the offset is valid and consistent with the packet properties.
 */
int process_packet(uint32_t a, uint32_t b, size_t n, int packet_type, int m)
{
    int32_t parity_result;
    size_t size_result;
    bool has_nine;
    int offset;
    int final_result;

    parity_result = func1(a, b);
    
    size_result = func2(n);
    
    has_nine = func3(packet_type);
    
    offset = func4(packet_type, m);
    
    if (has_nine) {
        final_result = 0;
    } else {
        final_result = offset;
    }
    
    //@ assert final_result >= 0 && final_result <= packet_type && (final_result == packet_type - m + 1 || final_result == 0);
    return final_result;
}

int main(void)
{
    return 0;
}
