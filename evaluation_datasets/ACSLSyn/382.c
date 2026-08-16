#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* ===== First function: check if range is within limit ===== */
/*@
    predicate ordered(unsigned long a, unsigned long b, unsigned long c, unsigned long d, unsigned long e) =
        a < b && b < c && c < d && d < e;
*/

bool func1(unsigned long a, unsigned long b, unsigned long c, unsigned long d, unsigned long e, unsigned long k) {
    unsigned long dist;
    bool result;

    //@ assert ordered(a, b, c, d, e);
    dist = e - a;
    //@ assert dist == e - a;
    result = dist <= k;
    return result;
}

/* ===== Second function: count distinct consecutive elements ===== */
/*@ predicate valid_array(int n, int *an) =
    n >= 1 && n <= 100 &&
    \valid(an + (0 .. n-1)) &&
    \forall integer i; 0 <= i < n ==> an[i] >= 1 && an[i] <= 1000;
*/

int func2(int n, int m, int *an) {
    int before = 0;
    int now = 0;
    int count = 0;
    int index = 0;
    
    while (now < n && index < n) {
        //@ assert 0 <= index < n;
        now = now + 1;
        count = count + 1;
        if (before == an[index]) {
            now = now - 1;
        } else {
            before = an[index];
        }
        index = index + 1;
    }
    
    if (now == 0) {
        now = -1;
    }
    
    //@ assert now >= -1;
    //@ assert now <= n;
    return now;
}

/* ===== Third function: compute a sum formula ===== */
/*@
    predicate bounds(integer v) = 1 <= v <= 10000;

    logic integer total_sum(integer x, integer y, integer z) =
        (x + y + z + (x * y + y * z + x * z)) / 2;
*/

uint32_t func3(uint32_t x, uint32_t y, uint32_t z)
{
    uint32_t ans;

    //@ assert bounds(x);
    //@ assert bounds(y);
    //@ assert bounds(z);
    //@ assert x + y + z <= 30000;
    //@ assert x * y + y * z + x * z <= 10000 * 10000 * 3;

    ans = (x + y + z + (x * y + y * z + x * z)) / 2;
    //@ assert ans == total_sum(x, y, z);
    return ans;
}

/* ===== Fourth function: add a constant ===== */
/*@
    predicate is_valid_input(integer x) = x <= 0x7FFFFFFF;

    logic integer compute_result(integer x) = x + 0x80000000;
*/

uint32_t func4(uint32_t x)
{
    uint32_t result;

    //@ assert x + 0x80000000 == 0x80000000 + x;
    result = x + 0x80000000;
    return result;
}

/* ===== Synthesized function: Packet Processing Pipeline =====
   Real-world scenario: Network packet validation and analysis.
   Data flow:
   1. func1 checks if packet sequence numbers are within a valid range
   2. func2 counts distinct consecutive packet types in the payload
   3. func3 computes a weighted sum of packet header fields
   4. func4 transforms the result for final output
   The overall property: The final transformed value is positive and bounded.
*/

uint32_t packet_processing_pipeline(
    unsigned long a, unsigned long b, unsigned long c, unsigned long d, unsigned long e, unsigned long k,
    int n, int m, int *an,
    uint32_t x, uint32_t y, uint32_t z,
    uint32_t w
) {
    bool range_check;
    int distinct_count;
    uint32_t sum_result;
    uint32_t final_result;

    range_check = func1(a, b, c, d, e, k);
    //@ assert range_check == (e - a <= k);

    distinct_count = func2(n, m, an);
    //@ assert distinct_count >= -1;
    //@ assert distinct_count <= n;

    sum_result = func3(x, y, z);
    //@ assert sum_result == total_sum(x, y, z);

    final_result = func4(w);
    //@ assert final_result == 0x80000000 + w;

    //@ assert final_result > 0 && final_result <= 0xFFFFFFFF;
    return final_result;
}
