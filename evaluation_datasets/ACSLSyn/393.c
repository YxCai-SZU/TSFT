#include <stdint.h>
#include <stdbool.h>

/* Predicates for the first function */
/*@ predicate double_pre(uint8_t x) = 0 <= x && x < 128; */
/*@ predicate double_post(uint8_t x, uint8_t res) = res == 2 * x; */

uint8_t double_func(uint8_t x) {
    uint8_t res;
    //@ assert double_pre(x);
    res = 2 * x;
    //@ assert double_post(x, res);
    return res;
}

/* Predicates for the second function */
/*@
    predicate valid_range_ab(integer x) = 1 <= x <= 100;
    logic integer compute_result_ab(integer a, integer b) = 
        a - (b * 2) > 0 ? a - (b * 2) : 0;
*/

int64_t func_ab(int64_t a, int64_t b) {
    int64_t answer;
    int64_t result;
    //@ assert valid_range_ab(b);
    answer = a - (b * 2);
    if (answer > 0) {
        //@ assert answer == a - (b * 2);
        result = answer;
    } else {
        result = 0;
    }
    //@ assert result >= 0;
    //@ assert result == a - (b * 2) || result == 0;
    return result;
}

/* Predicates for the third function */
/*@
    predicate valid_range_xyz(integer x, integer y, integer z) =
        1 <= x && x <= y && y <= z && z < 100;
*/

void calc_functions_example_2(int x, int y, int z) {
    int ans;
    //@ assert valid_range_xyz(x, y, z);
    if (x < y && y < z) {
        ans = y;
    } else {
        ans = -1;
    }
    //@ assert 1 <= y && y <= 100;
}

/* Predicates for the fourth function */
/*@
    predicate is_valid_range_x(integer x) = 1 <= x <= 10;
    logic integer compute_result_x(integer x) = x + x * x + x * x * x;
*/

int func_poly(int x) {
    int x2;
    int result;
    //@ assert is_valid_range_x(x);
    //@ assert x * x <= 100;
    x2 = x * x;
    //@ assert x * x2 <= 1000;
    result = x + x2 + x * x2;
    //@ assert result == compute_result_x(x);
    return result;
}

/* 
 * Synthesized function: Data packet transformation and validation
 * 
 * Scenario: A network data processing pipeline that:
 * 1. Doubles a header value (uint8_t packet_count)
 * 2. Computes a payload offset using func_ab
 * 3. Validates the packet structure with calc_functions_example_2
 * 4. Computes a polynomial checksum with func_poly
 * 
 * The high-level property: the output result is always non-negative
 * and bounded by the packet structure constraints.
 */

int network_packet_processor(uint8_t packet_count, int64_t offset_a, int64_t offset_b,
                             int x, int y, int z, int checksum_input) {
    uint8_t doubled_count;
    int64_t payload_offset;
    int checksum;
    int final_result;

    doubled_count = double_func(packet_count);
    //@ assert doubled_count == 2 * packet_count;

    payload_offset = func_ab(offset_a, offset_b);
    //@ assert payload_offset >= 0;

    calc_functions_example_2(x, y, z);
    //@ assert 1 <= y && y <= 100;

    checksum = func_poly(checksum_input);
    //@ assert checksum == compute_result_x(checksum_input);

    final_result = (int)doubled_count + (int)payload_offset + checksum;
    
    //@ assert final_result >= 0;
    return final_result;
}
