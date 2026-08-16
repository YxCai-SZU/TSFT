#include <stdbool.h>
#include <stddef.h>

/* ============================================================
   Scenario: Network Packet Filter Validation System
   Description: 
     We have a network packet filter that processes packets 
     with header fields (a,b,c,d) representing sequence numbers 
     in range [1,100]. The system validates:
     1. Each packet header field is within bounds
     2. A batch of packets (array) has all fields within a given limit
     3. The sequence of fields in a packet is strictly non-decreasing
        with gaps less than the previous gap (monotonic decreasing difference)
   ============================================================ */

/* ---------- Function 1: Bounds check for three values ---------- */

/*@ predicate bounds(integer x) = 1 <= x <= 100; */

bool bounds_check(int a, int b, int c)
{
    int d;
    //@ assert bounds(a);
    //@ assert bounds(b);
    //@ assert bounds(c);
    d = c;
    //@ assert bounds(d);
    return d >= a && d <= b;
}

/* ---------- Function 2: Array all-within-bounds check ---------- */

/*@ predicate all_within_bounds(integer m, integer n, size_t *arr) =
      \forall integer j; 0 <= j < m ==> arr[j] <= n;
*/

bool array_within_bounds(size_t n, size_t m, size_t *arr) {
    size_t i = 0;
    while (i < m) {
        //@ assert i < m;
        if (arr[i] > n) {
            return false;
        }
        i = i + 1;
    }
    return true;
}

/* ---------- Function 3: Sequence monotonic decreasing difference ---------- */

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer diff(integer x, integer y) = x - y;

    lemma diff_nonnegative:
        \forall integer a, b; valid_range(a) && valid_range(b) && a >= b ==> diff(a, b) >= 0;
*/

bool decreasing_diff_check(long a, long b, long c, long d)
{
    bool result;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert valid_range(d);

    result = (c - b < b - a) && (c - b >= 0) && (d - c >= 0);
    return result;
}

/* ============================================================
   Synthesized function: validate_packet_filter
   This function validates a complete packet filter scenario:
   - Takes a batch of packets (array arr of size m) with header fields
   - Takes a single packet header (a,b,c,d) to validate
   - Ensures all packet fields in the batch are within limit n
   - Ensures the single packet header fields are within bounds [1,100]
   - Ensures the sequence differences are decreasing non-negative
   High-level property: The entire filter configuration is consistent
   ============================================================ */

bool validate_packet_filter(size_t n, size_t m, size_t *arr, int a, int b, int c, long d)
{
    bool batch_ok = array_within_bounds(n, m, arr);
    bool bounds_ok = bounds_check(a, b, c);
    bool diff_ok = decreasing_diff_check((long)a, (long)b, (long)c, d);

    bool result = batch_ok && bounds_ok && diff_ok;

    //@ assert result ==> (all_within_bounds(m, n, arr) && (c >= a && c <= b) && (c - b < b - a && c - b >= 0 && d - c >= 0));

    return result;
}
