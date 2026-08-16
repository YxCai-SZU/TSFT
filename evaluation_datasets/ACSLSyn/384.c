#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/* ACSL predicates from original functions */

/*@ predicate valid_params(integer n, integer x, int *ls) =
    n >= 1 && n <= 100 &&
    x >= 1 && x <= 10000 &&
    \valid(ls + (0 .. n-1)) &&
    \forall integer j; 0 <= j < n ==> ls[j] >= 1 && ls[j] <= 100;
*/



uint32_t func1(uint32_t n, uint32_t x, const int *ls) {
    uint32_t di = 0;
    uint32_t i = 0;
    
    while (i < n) {
        int li = ls[i];
        di += (uint32_t)li;
        
        //@ assert di <= (i + 1) * 100;
        
        if (di > x) {
            //@ assert i + 1 <= n + 1;
            return i + 1;
        }
        i += 1;
    }
    
    //@ assert n + 1 <= n + 1;
    return n + 1;
}

/*@
    predicate valid_range(integer v) = 1 <= v <= 100;

    logic integer total_sum(integer a, integer b, integer c) = a + b + c;

    lemma sum_range: \forall integer a, b, c; valid_range(a) && valid_range(b) && valid_range(c) ==> 3 <= total_sum(a, b, c) <= 300;
*/

int func2(int a, int b, int c)
{
    int sum;
    int result;
    int temp_sum;

    sum = a + b + c;
    result = 0;
    temp_sum = sum;

    while (temp_sum >= 2)
    {
        //@ assert temp_sum >= 2;
        result += 1;
        temp_sum -= 2;
    }

    //@ assert 0 <= temp_sum < 2;
    //@ assert result == (a + b + c) / 2;
    return result;
}

/*@ predicate valid_index(integer i, integer len) = 0 <= i < len; */

/*@ predicate first_three_bounded(unsigned long long *arr, integer len) =
        len >= 3 &&
        \forall integer i; 0 <= i < 3 ==> arr[i] <= 100 &&
        \forall integer i; 0 <= i < len ==> arr[i] <= 100; */

/*@ lemma index_in_bounds: 
        \forall unsigned long long *arr, integer len; 
        first_three_bounded(arr, len) ==> valid_index(2, len); */

bool func3(unsigned long long *numbers, size_t len) {
    unsigned long long a;
    unsigned long long b;
    unsigned long long c;
    
    a = numbers[0];
    b = numbers[1];
    
    //@ assert valid_index(2, len);
    c = numbers[2];
    
    return a < b && b < c;
}

/*@
    predicate is_odd(integer n) = n % 2 != 0;
*/

int func4(unsigned int n) {
    int ret;
    //@ assert n >= 0;
    ret = (n % 2 != 0) ? 1 : 0;
    //@ assert ret == 1 ==> is_odd(n);
    //@ assert ret == 0 ==> !is_odd(n);
    return ret;
}

/* 
 * Real-world scenario: Packet Processing in a Network Traffic Monitor
 * 
 * This function processes a network packet represented by:
 * - ls: array of packet segment sizes
 * - n: number of segments
 * - x: maximum allowed total size before overflow
 * - numbers: array of 3 timestamp values (must be strictly increasing for valid sequence)
 * - a, b, c: three quality-of-service parameters (each 1-100)
 * 
 * The function:
 * 1. Checks if the packet is valid (no overflow) using func1
 * 2. Verifies timestamps are strictly increasing using func3
 * 3. Computes average QoS parameter using func2
 * 4. Checks if the average is odd using func4
 * 
 * Returns: 1 if packet is valid, timestamps are ordered, and average QoS is odd; 0 otherwise.
 */

int process_packet(uint32_t n, uint32_t x, const int *ls, 
                   unsigned long long *numbers, size_t len,
                   int a, int b, int c) 
{
    uint32_t overflow_pos;
    bool ordered;
    int avg_qos;
    int is_avg_odd;
    
    overflow_pos = func1(n, x, ls);
    
    ordered = func3(numbers, len);
    
    avg_qos = func2(a, b, c);
    
    is_avg_odd = func4((unsigned int)avg_qos);
    
    
    if (overflow_pos > n && ordered && is_avg_odd == 1) {
        return 1;
    }
    
    return 0;
}

int main() {
    return 0;
}
