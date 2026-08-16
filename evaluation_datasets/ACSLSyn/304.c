#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* First function: compute x+4 */
/*@
    predicate in_range(integer v) = INT_MIN <= v <= INT_MAX - 4;

    logic integer max_of_four(integer a, integer b, integer c, integer d) =
        (a >= b && a >= c && a >= d) ? a :
        (b >= a && b >= c && b >= d) ? b :
        (c >= a && c >= b && c >= d) ? c : d;

    lemma max_is_last:
        \forall integer x; in_range(x) ==> max_of_four(x, x+1, x+2, x+3) == x+3;
    lemma max_is_fourth:
        \forall integer x; in_range(x) ==> max_of_four(x, x+1, x+2, x+4) == x+4;
*/

int func1(int x)
{
    int max_val;

    //@ assert in_range(x);
    
    if (x < x + 1) {
        if (x + 1 < x + 2) {
            if (x + 2 < x + 3) {
                if (x + 3 < x + 4) {
                    max_val = x + 4;
                } else {
                    max_val = x + 3;
                }
            } else {
                if (x + 2 < x + 4) {
                    max_val = x + 4;
                } else {
                    max_val = x + 2;
                }
            }
        } else {
            if (x + 1 < x + 3) {
                if (x + 3 < x + 4) {
                    max_val = x + 4;
                } else {
                    max_val = x + 3;
                }
            } else {
                if (x + 1 < x + 4) {
                    max_val = x + 4;
                } else {
                    max_val = x + 1;
                }
            }
        }
    } else {
        if (x < x + 2) {
            if (x + 2 < x + 3) {
                if (x + 3 < x + 4) {
                    max_val = x + 4;
                } else {
                    max_val = x + 3;
                }
            } else {
                if (x + 2 < x + 4) {
                    max_val = x + 4;
                } else {
                    max_val = x + 2;
                }
            }
        } else {
            if (x < x + 3) {
                if (x + 3 < x + 4) {
                    max_val = x + 4;
                } else {
                    max_val = x + 3;
                }
            } else {
                if (x < x + 4) {
                    max_val = x + 4;
                } else {
                    max_val = x;
                }
            }
        }
    }

    //@ assert max_val == x + 4;
    return max_val;
}

/* Second function: check if n == m */
/*@
    predicate is_valid_params(integer n, integer m) =
        1 <= n <= 100 && 0 <= m <= n;

    lemma n_minus_m_bounds:
        \forall integer n, m;
            is_valid_params(n, m) ==> n - m <= n;

    lemma zero_implies_equal:
        \forall integer n, m;
            is_valid_params(n, m) ==> (n - m == 0 ==> n == m);
*/

bool func2(unsigned int n, unsigned int m)
{
    //@ assert n - m <= n;
    //@ assert n - m == 0 ==> n == m;
    return n - m == 0;
}

/* Third function: compute sum of absolute differences */
/*@
    predicate valid_index_range(int64_t* arr, integer len, integer low, integer high) =
        \forall integer i; 0 <= i < len ==> low <= arr[i] <= high;

    predicate array_length_in_range(integer len, integer min, integer max) =
        min <= len <= max;

    logic integer absolute_difference(integer a, integer b) =
        a >= b ? a - b : b - a;

    lemma diff_bounds:
        \forall integer a, b; -1000000000 <= a <= 1000000000 && -1000000000 <= b <= 1000000000 ==> 
        0 <= absolute_difference(a, b) <= 2000000000;
*/

int64_t func3(int64_t* numbers, size_t len) {
    int64_t d = 0;
    size_t i = 0;

    while (i < len - 1) {
        int64_t diff = numbers[i] - numbers[i + 1];
        int64_t abs_diff = diff < 0 ? -diff : diff;

        //@ assert 0 <= abs_diff <= 2000000000;
        d += abs_diff;
        i += 1;
    }
    return d;
}

/* Synthesized function: validate packet sequence integrity in a network protocol
   Scenario: A network protocol processes packets with sequence numbers (x).
   For each packet, it computes x+4 to get the next expected sequence number.
   It checks if the packet length matches a parameter (n == m) to detect truncation.
   Then it computes the total jitter (sum of absolute differences) across all packets.
   The high-level property: if the array length is valid and we have at least 3 packets,
   the total jitter is a non-negative integer that respects the bounds.
*/

int64_t process_packet_sequence(int64_t* numbers, size_t len) {
    int64_t total_jitter = 0;
    
    if (len > 0) {
        int x = (int)numbers[0];
        //@ assert INT_MIN <= x <= INT_MAX - 4;
        int next_seq = func1(x);
        //@ assert next_seq == x + 4;
        
        bool length_ok = func2((unsigned int)len, (unsigned int)len);
        //@ assert length_ok == true;
    }
    
    total_jitter = func3(numbers, len);
    
    //@ assert total_jitter >= 0;
    //@ assert total_jitter <= (len - 1) * 2000000000;
    return total_jitter;
}
