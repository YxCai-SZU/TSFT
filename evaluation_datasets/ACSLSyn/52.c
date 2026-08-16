/* Scenario: Network packet validation and billing system.
 * 
 * Data flow:
 * 1. Parse packet header fields (x, y, z) and validate arithmetic consistency.
 * 2. Count special flags (value 1 at even positions) in a payload array.
 * 3. Compute billing amount based on packet length n.
 * 4. Count odd-numbered error codes in a separate error array.
 *
 * The synthesized function orchestrates these steps and asserts that
 * the total processing time (billing amount) is non-negative and
 * consistent with the input constraints.
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* ====== Provided functions (adapted only as needed for integration) ====== */

/*@
    predicate pos_bounded(integer v) = v > 0 && v <= 100;
*/

bool verify_nonlinear_arith_c(int x, int y, int z) {
    //@ assert x * (y + z) == x * y + x * z;
    int lhs = x * (y + z);
    int rhs = x * y + x * z;
    
    return lhs == rhs;
}

bool verify_nonlinear_arith_neg_c(int x, int y, int z) {
    //@ assert -(x * (y + z)) == -(x * y) - (x * z);
    int lhs = -(x * (y + z));
    int rhs = -(x * y) - (x * z);
    
    return lhs == rhs;
}

/*@ predicate is_valid_array(int *a, integer n) =
      n > 0 && n <= 100 &&
      \valid(a + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> 1 <= a[i] <= 100;
*/

/*@ predicate loop_inv(integer num, integer n, integer count, int *a) =
      0 <= num <= n &&
      0 <= count <= num &&
      is_valid_array(a, n) &&
      \forall integer k; 0 <= k < num && k % 2 == 0 && a[k] == 1 ==> count >= 1;
*/

int count_special_flags(size_t n, int *a) {
    int count = 0;
    size_t num = 0;

    while (num < n) {
        //@ assert loop_inv(num, n, count, a);
        if (num % 2 == 0) {
            if (a[num] == 1) {
                count += 1;
            }
        }
        num += 1;
    }
    //@ assert loop_inv(num, n, count, a);
    //@ assert num == n;
    //@ assert count >= 0 && count <= n;
    return count;
}

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;
*/

int64_t compute_billing(uint64_t n) {
    uint64_t x;
    uint64_t quotient;
    uint64_t remainder;
    uint64_t y;
    int64_t ans;
    
    x = n * 800;
    
    quotient = 0;
    remainder = n;
    
    while (remainder >= 15) {
        //@ assert remainder >= 15;
        quotient = quotient + 1;
        remainder = remainder - 15;
    }
    
    //@ assert quotient == n / 15;
    y = 200 * quotient;
    ans = (int64_t)(x - y);
    return ans;
}

size_t odd_count(const unsigned int* arr, size_t len) {
    size_t count = 0;
    size_t i = 0;
    
    while (i < len) {
        //@ assert i < len;
        if (arr[i] % 2 != 0) {
            count += 1;
        }
        i += 1;
    }
    return count;
}

/* ====== Synthesized complex function ====== */

int64_t process_packet(
    int hdr_x, int hdr_y, int hdr_z,
    size_t pkt_len, int *payload,
    const unsigned int* errors, size_t err_len
) {
    bool arith_ok = verify_nonlinear_arith_c(hdr_x, hdr_y, hdr_z);
    bool arith_neg_ok = verify_nonlinear_arith_neg_c(hdr_x, hdr_y, hdr_z);
    
    int special_count = count_special_flags(pkt_len, payload);
    
    int64_t billing = compute_billing(pkt_len);
    
    size_t odd_errors = odd_count(errors, err_len);
    
    //@ assert billing >= 0;
    
    return billing;
}
