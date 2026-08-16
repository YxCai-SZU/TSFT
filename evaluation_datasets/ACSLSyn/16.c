#include <stdbool.h>
#include <stdint.h>

/* Original function 1: bounds check for product sum */
/*@
    predicate bounds(integer a, integer b, integer c, integer d) =
        0 <= a && a <= 10 &&
        0 <= b && b <= 10 &&
        0 <= c && c <= 10 &&
        0 <= d && d <= 10;

    logic integer product_sum(integer a, integer b, integer c, integer d) =
        a * c + b * d;

    lemma product_bound_a:
        \forall integer a, c; 0 <= a <= 10 && 0 <= c <= 10 ==> a * c <= 100;

    lemma product_bound_b:
        \forall integer b, d; 0 <= b <= 10 && 0 <= d <= 10 ==> b * d <= 100;
*/

bool check_product_sum(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    //@ assert 0 <= a && a <= 10;
    //@ assert 0 <= b && b <= 10;
    //@ assert 0 <= c && c <= 10;
    //@ assert 0 <= d && d <= 10;

    //@ assert a * c <= 100;
    //@ assert b * d <= 100;

    unsigned int product_sum = a * c + b * d;
    return product_sum <= 100;
}

/* Original function 2: compute result based on n and r */
/*@
    predicate valid_params(integer n, integer r) =
        1 <= n <= 100 && 0 <= r <= 4111;

    logic integer compute_result(integer n, integer r) =
        n >= 10 ? r : r + (100 * (10 - n));
*/

int64_t compute_adjusted_value(int64_t n, int64_t r)
{
    int64_t min_val;
    int64_t res;
    
    //@ assert valid_params(n, r);
    
    if (10 < n) {
        min_val = 10;
        //@ assert n >= 10 ==> min_val == 10;
    } else {
        min_val = n;
        //@ assert n < 10 ==> min_val == n;
    }
    
    res = r + (100 * (10 - min_val));
    
    //@ assert n >= 10 ==> res == r;
    //@ assert n < 10 ==> res == r + (100 * (10 - n));
    
    return res;
}

/* Synthesized function: Data packet validation in a network protocol
 * 
 * Scenario: A network device receives data packets with fields:
 *   - a, b: header checksum components (0-10 each)
 *   - c, d: payload checksum components (0-10 each)
 *   - n: packet sequence number (1-100)
 *   - r: base response code (0-4111)
 * 
 * The function validates that the packet is valid:
 *   - The checksum product sum must be within bounds (<= 100)
 *   - The adjusted response value must be non-negative
 * 
 * High-level property: A valid packet must have both a valid checksum 
 * and a non-negative adjusted response value.
 */

/*@
    predicate valid_packet(integer a, integer b, integer c, integer d, integer n, integer r) =
        bounds(a, b, c, d) && valid_params(n, r) &&
        (a * c + b * d <= 100) &&
        (n >= 10 ? r >= 0 : r + (100 * (10 - n)) >= 0);
*/

bool validate_data_packet(unsigned int a, unsigned int b, unsigned int c, unsigned int d, 
                          int64_t n, int64_t r)
{
    bool checksum_valid = check_product_sum(a, b, c, d);
    
    int64_t adjusted_value = compute_adjusted_value(n, r);
    
    bool packet_valid = checksum_valid && (adjusted_value >= 0);
    
    //@ assert checksum_valid <==> (a * c + b * d <= 100);
    //@ assert (n >= 10 ==> adjusted_value == r) && (n < 10 ==> adjusted_value == r + (100 * (10 - n)));
    
    //@ assert packet_valid ==> (a * c + b * d <= 100 && adjusted_value >= 0);
    
    return packet_valid;
}
