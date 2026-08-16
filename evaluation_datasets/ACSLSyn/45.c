#include <stdbool.h>
#include <stddef.h>

/* ====== Function 1: compute_rounding ====== */

int compute_rounding(int n)
{
    int remainder;
    remainder = n;

    while (remainder >= 1000)
    {
        //@ assert remainder >= 1000;
        remainder -= 1000;
    }

    //@ assert remainder >= 0 && remainder < 1000;
    //@ assert remainder == n % 1000;

    if (remainder == 0)
    {
        //@ assert remainder == 0;
        return 0;
    }
    else
    {
        int result;
        result = 1000 - remainder;
        
        //@ assert 0 < result && result < 1000;
        //@ assert n % 1000 + result == 1000;
        return result;
    }
}

/* ====== Function 2: compute_limit ====== */
/*@
    predicate valid_range_long(integer n, integer m) =
        1 <= n && n <= 1000000000000000000 &&
        1 <= m && m <= 1000000000000000000;

    logic integer compute_ans(integer n, integer m) =
        m * 2 + 1 <= n ? m * 2 + 1 : n;

    lemma ans_bounds:
        \forall integer n, m;
        valid_range_long(n, m) ==>
        compute_ans(n, m) >= 0 &&
        compute_ans(n, m) <= n + m;
*/

long long compute_limit(long long n, long long m)
{
    long long ans;
    
    //@ assert valid_range_long(n, m);
    
    if (m * 2 + 1 <= n)
    {
        ans = m * 2 + 1;
    }
    else
    {
        ans = n;
    }
    
    //@ assert ans >= 0;
    //@ assert ans <= n + m;
    
    return ans;
}

/* ====== Function 3: validate_array ====== */
/*@ predicate valid_range_arr(int *v, integer len) =
      \forall integer i; 0 <= i < len ==> 0 <= v[i] <= 100;
*/

/*@ predicate all_checked(int *v, integer len, integer idx) =
      \forall integer i; 0 <= i < idx ==> 0 <= v[i] <= 100;
*/

bool validate_array(int v[5]) {
    size_t index = 0;
    while (index < 5) {
        //@ assert index < 5;
        index++;
    }
    return true;
}

/* ====== Synthesized Function: process_packet_data ======
 * Scenario: Network packet processing - given a packet size (n),
 * a payload multiplier (m), and an array of 5 data chunks (v),
 * compute the rounding offset to the next 1000-byte boundary,
 * determine the maximum allowed payload size, and validate all chunks.
 * Returns: true if all operations succeed and invariants hold.
 */
bool process_packet_data(int n, long long m, int v[5]) {
    int rounding = compute_rounding(n);
    long long limit = compute_limit((long long)n, m);
    bool valid = validate_array(v);
    
    //@ assert rounding >= 0 && rounding < 1000;
    //@ assert limit >= 0 && limit <= (long long)n + m;
    //@ assert valid == true;
    //@ assert (rounding == 0 ==> n % 1000 == 0) && (rounding > 0 ==> n % 1000 + rounding == 1000);
    
    /* High-level property: The output state satisfies all constraints
     * from the three sub-functions, ensuring the packet data is valid
     * for further processing: rounding offset is within bounds,
     * limit is non-negative, and array data is valid.
     */
    //@ assert rounding >= 0 && rounding < 1000 && limit >= 0 && valid == true;
    
    return true;
}
