/* Scenario: Network packet validation system
 *
 * The system validates a data packet by:
 * 1. Computing a weighted offset from packet header (func)
 * 2. Counting divisor checksums in payload (func2)
 * 3. Verifying logical consistency of packet flags (proof_example + example_logical_layers)
 *
 * Data flow: header_value -> weighted_offset -> divisor_count -> flag_consistency
 */

/* ====== Original function 1 (adapted for uint32_t) ====== */
/*@
    predicate is_valid_x(integer x) = 0 <= x && x <= 100;

    logic integer compute_expected(integer x, integer i) =
        x * 800 - (i / 15) * 200;
*/

int func(unsigned int x)
{
    int result;
    unsigned int i;

    //@ assert is_valid_x(x);
    result = x * 800;
    i = 0;

    while (i < x)
    {
        //@ assert i < x;
        if ((i + 1) % 15 == 0)
        {
            result -= 200;
        }
        i += 1;
        //@ assert i <= x;
    }

    //@ assert i == x;
    //@ assert result == compute_expected(x, x);
    return result;
}

/* ====== Original function 2 (adapted for uint32_t) ====== */
#include <stdint.h>

/*@
    predicate valid_n(integer n) = 1 <= n <= 100000;

    logic integer half(integer n) = n / 2;
*/

int32_t func2(uint32_t n)
{
    int32_t result = 0;
    uint32_t i = 2;
    uint32_t half_n = n / 2;

    if (n % 2 == 1)
    {
        //@ assert result == 0;
        return 0;
    }

    //@ assert half_n == half(n);

    while (i < half_n + 2)
    {
        if (n % i == 0)
        {
            result += 1;
        }
        i += 1;
    }

    //@ assert result <= (int32_t)half_n;
    return result;
}

/* ====== Original function 3 (combined) ====== */
/*@
    predicate is_in_range(integer a) = 2 <= a && a <= 20;
*/

int proof_example(int a) {
    //@ assert 2 <= a && a <= 20;
    //@ assert a * a <= 20 * 20;
    return a * a;
}

/*@
    predicate all_true(integer a, integer b, integer c) = a != 0 && b != 0 && c != 0;
*/

int example_logical_layers(int a, int b, int c) {
    //@ assert a != 0 && b != 0 && c != 0;
    //@ assert (a && b) == (b && c);
    return (a && b) == (b && c);
}

/* ====== Synthesized complex function ====== */

int process_packet(unsigned int header_value, uint32_t payload_size, int flag_a, int flag_b, int flag_c)
{
    int weighted_offset;
    int32_t divisor_count;
    int squared_flag;
    int logical_consistency;
    int final_result;

    weighted_offset = func(header_value);
    //@ assert weighted_offset == header_value * 800 - (header_value / 15) * 200;

    divisor_count = func2(payload_size);
    //@ assert divisor_count >= 0 && divisor_count <= half(payload_size);

    squared_flag = proof_example(flag_a);
    //@ assert squared_flag == flag_a * flag_a;

    logical_consistency = example_logical_layers(flag_a, flag_b, flag_c);
    //@ assert logical_consistency == ((flag_a && flag_b) == (flag_b && flag_c));

    if (weighted_offset > 0 && divisor_count >= 0 && logical_consistency == 1)
    {
        final_result = 1;
    }
    else
    {
        final_result = 0;
    }

    //@ assert (final_result == 1) ==> (weighted_offset > 0 && divisor_count >= 0 && logical_consistency == 1);

    return final_result;
}
