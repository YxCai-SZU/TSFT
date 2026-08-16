/* ============================================================================
 * Real-world scenario: Network Packet Filtering System
 * 
 * The synthesized function validates whether a packet with a given payload 
 * length (represented by the digit-sum of its header field) falls within 
 * an allowed range. This mimics a real packet filter that checks payload
 * constraints based on extracted header information.
 * ============================================================================ */

#include <stdbool.h>

/* --- First underlying function: digit sum computation --- */

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 10000;
    
    logic integer digit_sum(integer n) =
        1000 * (n / 1000) + 
        100 * ((n % 1000) / 100) + 
        10 * (((n % 1000) % 100) / 10) + 
        ((n % 1000) % 100) % 10;
*/

int compute_digit_sum(int n) {
    int n_mod_1000 = n;
    int count_1000 = 0;
    
    while (n_mod_1000 >= 1000) {
        n_mod_1000 -= 1000;
        count_1000 += 1;
    }
    
    int n_mod_100 = n_mod_1000;
    int count_100 = 0;
    
    while (n_mod_100 >= 100) {
        n_mod_100 -= 100;
        count_100 += 1;
    }
    
    int n_mod_10 = n_mod_100;
    int count_10 = 0;
    
    while (n_mod_10 >= 10) {
        n_mod_10 -= 10;
        count_10 += 1;
    }
    
    int result = count_1000 * 1000 + count_100 * 100 + count_10 * 10 + n_mod_10;
    
    //@ assert result == digit_sum(n);
    return result;
}

/* --- Second underlying function: range check --- */

/*@
    predicate in_range(integer a, integer b, integer x) =
        0 <= a <= 100 &&
        0 <= b <= 100 &&
        0 <= x <= 100;

    predicate result_condition(integer a, integer b, integer x, bool result) =
        result == (a <= x && x <= a + b);
*/

bool check_range(unsigned int a, unsigned int b, unsigned int x)
{
    bool result;

    //@ assert a <= x && x <= a + b ==> (a <= x && x <= a + b);
    result = a <= x && x <= a + b;
    return result;
}

/* --- Synthesized function: packet filter --- */

bool filter_packet(int packet_header, unsigned int range_start, unsigned int range_width)
{
    int payload_length = compute_digit_sum(packet_header);
    
    bool is_allowed = check_range(range_start, range_width, (unsigned int)payload_length);
    
    //@ assert is_allowed == (range_start <= digit_sum(packet_header) <= range_start + range_width);
    return is_allowed;
}
