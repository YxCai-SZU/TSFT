#include <stdint.h>
#include <stdbool.h>

/* ========== Scenario: Network Packet Priority Filter ========== 
 * A network router processes packets and assigns them priority levels.
 * It uses three stages:
 * 1. func3: Check if a packet's priority code satisfies a condition based on header fields.
 * 2. func2: Compute a scaling factor based on packet size.
 * 3. func1: Validate that all packets in a batch meet filtering criteria.
 * 
 * The synthesized function processes a batch of packets, where each packet has:
 * - header fields a, b, c (priority-related)
 * - size n (number of bytes)
 * - priority code k
 * 
 * Data flow:
 * - For each packet, compute whether condition holds (func3).
 * - Compute scaling factor from packet size (func2).
 * - Check if all packets in batch satisfy a combined property.
 */

/* ========== Original Function 1 (func1) ========== */
/*@
    predicate is_valid_range(int *arr, integer n) =
        n > 0 &&
        \forall integer i; 0 <= i < n ==> arr[i] > 0 && arr[i] <= 1000;

    predicate condition_holds(int *arr, integer i) =
        \forall integer j; 0 <= j < i ==> 
            arr[j] % 2 != 0 || arr[j] % 3 == 0 || arr[j] % 5 == 0;
*/

int func1(int n, int *numbers)
{
    int i = 0;
    int num;
    int ans = 1;

    while (i < n)
    {
        num = numbers[i];

        if (num % 2 != 0)
        {
            i += 1;
            continue;
        }

        if (!(num % 3 == 0 || num % 5 == 0))
        {
            ans = 0;
            break;
        }
        i += 1;
    }

    //@ assert ans == 1 <==> condition_holds(numbers, n);

    return ans;
}

/* ========== Original Function 2 (func2) ========== */
/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;

    logic integer compute_result(integer n) = 800 * n - (n / 15) * 200;

    lemma overflow_safe: \forall integer n; valid_n(n) ==> 800 * n <= 800 * 100;
*/

int64_t func2(uint64_t n)
{
    int64_t x;
    uint64_t quotient;
    uint64_t remainder;
    int64_t y;
    int64_t ans;

    //@ assert valid_n(n);
    //@ assert 800 * n <= 800 * 100;
    x = 800 * (int64_t)n;

    quotient = 0;
    remainder = n;

    while (remainder >= 15)
    {
        //@ assert remainder >= 15;
        remainder -= 15;
        quotient += 1;
        //@ assert remainder + quotient * 15 == n;
    }

    //@ assert quotient == n / 15;
    y = (int64_t)quotient * 200;
    ans = x - y;

    //@ assert ans == compute_result(n);
    return ans;
}

/* ========== Original Function 3 (func3) ========== */
/*@
    predicate valid_range(integer x) = 1 <= x <= 7;

    logic integer expression_value(integer k, integer b, integer a) = k + b - a;

    lemma expression_bounds:
        \forall integer k, b, a;
            valid_range(k) && valid_range(b) && valid_range(a) ==>
            expression_value(k, b, a) <= 7 + 7 - 1;
*/

bool func3(int a, int b, int c, int k)
{
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert valid_range(k);
    
    //@ assert expression_value(k, b, a) <= 7 + 7 - 1;
    
    return c <= k + b - a;
}

/* ========== Synthesized Function ========== 
 * Scenario: Network packet batch processing with priority filtering
 * Checks that for all packets in a batch:
 * - Each packet satisfies the priority condition (func3)
 * - The batch size is valid (func2)
 * - All packet IDs meet the filtering criteria (func1)
 */

/*@
    predicate valid_packet_batch(int *packet_ids, int batch_size, 
                                  int *a_arr, int *b_arr, int *c_arr, int *k_arr) =
        batch_size > 0 &&
        \valid(packet_ids + (0 .. batch_size-1)) &&
        \valid(a_arr + (0 .. batch_size-1)) &&
        \valid(b_arr + (0 .. batch_size-1)) &&
        \valid(c_arr + (0 .. batch_size-1)) &&
        \valid(k_arr + (0 .. batch_size-1)) &&
        is_valid_range(packet_ids, batch_size) &&
        \forall integer i; 0 <= i < batch_size ==>
            valid_range(a_arr[i]) && valid_range(b_arr[i]) && 
            valid_range(c_arr[i]) && valid_range(k_arr[i]);
    
    predicate batch_priority_valid(int batch_size, int *a_arr, int *b_arr, 
                                    int *c_arr, int *k_arr) =
        \forall integer i; 0 <= i < batch_size ==>
            c_arr[i] <= k_arr[i] + b_arr[i] - a_arr[i];
    
    predicate batch_size_valid(integer n) = valid_n(n);
    
    predicate batch_filter_ok(int *packet_ids, int batch_size) =
        condition_holds(packet_ids, batch_size);
*/

int process_packet_batch(int batch_size, int *packet_ids, 
                          int *a_arr, int *b_arr, int *c_arr, int *k_arr)
{
    int i;
    int all_priority_ok = 1;
    int filter_valid;
    int64_t scaling_factor;
    
    for (i = 0; i < batch_size; i++)
    {
        if (!func3(a_arr[i], b_arr[i], c_arr[i], k_arr[i]))
        {
            all_priority_ok = 0;
            break;
        }
    }
    
    //@ assert valid_n((uint64_t)batch_size);
    scaling_factor = func2((uint64_t)batch_size);
    
    filter_valid = func1(batch_size, packet_ids);
    
    //@ assert filter_valid == 1 <==> condition_holds(packet_ids, batch_size);
    
    //@ assert (all_priority_ok == 1 && filter_valid == 1) ==> batch_priority_valid(batch_size, a_arr, b_arr, c_arr, k_arr) && batch_filter_ok(packet_ids, batch_size);
    
    if (all_priority_ok == 1 && filter_valid == 1)
    {
        //@ assert batch_priority_valid(batch_size, a_arr, b_arr, c_arr, k_arr) && batch_filter_ok(packet_ids, batch_size);
        return 1;
    }
    
    return 0;
}
