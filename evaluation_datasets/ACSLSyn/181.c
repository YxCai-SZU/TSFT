#include <stdbool.h>

/* First function: checks divisibility/range condition */
/*@
    predicate is_divisible(integer n, integer k) = n % k == 0;
    predicate condition_check(integer n, integer k) = n % k + k - 1 >= 2 * k - 1;
    predicate result_condition(integer n, integer k) = is_divisible(n, k) || condition_check(n, k);
*/

bool func1(unsigned long n, unsigned long k) {
    unsigned long mod_result;
    bool result;
    
    mod_result = n % k;
    
    if (mod_result == 0 || mod_result + k - 1 >= 2 * k - 1) {
        result = true;
        //@ assert result == (n % k == 0 || n % k + k - 1 >= 2 * k - 1);
        return result;
    } else {
        //@ assert mod_result != 0 && mod_result + k - 1 < 2 * k - 1;
        result = false;
        //@ assert result == (n % k == 0 || n % k + k - 1 >= 2 * k - 1);
        return result;
    }
}

/* Second function: checks if any two points are within distance k */
/*@
    predicate reachable(integer a, integer b, integer c, integer d, integer e, integer k) =
        (b - a <= k) || (c - a <= k) || (d - a <= k) || (e - a <= k) ||
        (c - b <= k) || (d - b <= k) || (e - b <= k) ||
        (d - c <= k) || (e - c <= k) ||
        (e - d <= k);
*/

bool func2(int a, int b, int c, int d, int e, int k)
{
    bool isReachable = false;

    //@ assert a < b && b < c && c < d && d < e;

    if (b - a <= k || c - a <= k || d - a <= k || e - a <= k)
    {
        isReachable = true;
    }
    else if (c - b <= k || d - b <= k || e - b <= k)
    {
        isReachable = true;
    }
    else if (d - c <= k || e - c <= k)
    {
        isReachable = true;
    }
    else if (e - d <= k)
    {
        isReachable = true;
    }

    //@ assert isReachable == 1 <==> reachable(a, b, c, d, e, k);

    return isReachable;
}

/* Synthesized function: Network packet processing scenario
 * Checks if a packet with sequence number and 5 timestamps meets delivery conditions
 * The packet is considered deliverable if:
 * - The sequence number satisfies the modulo condition (func1), AND
 * - The timestamps indicate reachability within a threshold (func2)
 * 
 * Real-world scenario: IoT sensor network where packets have sequence numbers
 * and 5 relay timestamps; delivery requires valid sequence and timely relays
 */

/*@
    predicate valid_packet(integer seq, integer k_seq, integer a, integer b, integer c, integer d, integer e, integer k_dist) =
        (seq % k_seq == 0 || seq % k_seq + k_seq - 1 >= 2 * k_seq - 1) &&
        ((b - a <= k_dist) || (c - a <= k_dist) || (d - a <= k_dist) || (e - a <= k_dist) ||
         (c - b <= k_dist) || (d - b <= k_dist) || (e - b <= k_dist) ||
         (d - c <= k_dist) || (e - c <= k_dist) ||
         (e - d <= k_dist));
*/

bool process_packet(unsigned long seq, unsigned long k_seq, int a, int b, int c, int d, int e, int k_dist) {
    bool seq_valid = func1(seq, k_seq);
    bool timestamps_valid = func2(a, b, c, d, e, k_dist);
    bool packet_deliverable = seq_valid && timestamps_valid;
    
    //@ assert packet_deliverable == (seq_valid && timestamps_valid);
    //@ assert packet_deliverable == 1 <==> valid_packet(seq, k_seq, a, b, c, d, e, k_dist);
    
    return packet_deliverable;
}
