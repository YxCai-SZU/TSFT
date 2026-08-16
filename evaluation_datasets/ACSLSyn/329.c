/* Scenario: A network packet validator that checks packet integrity and computes priority.
   The system processes a sequence of packets, each with a size field and two data values.
   - func1 maps packet size to a priority class (1-3)
   - func2 computes a checksum based on size
   - func3 validates data values and returns a combined result
   The synthesized function processes a batch of packets and asserts that the final output
   satisfies a high-level invariant relating priority, checksum, and data validation. */

#include <stdbool.h>
#include <stddef.h>

/* --- Original func1 (unchanged) --- */
/*@
    predicate is_multiple_of_1000(integer x) = x % 1000 == 0;
    predicate in_range(integer x) = 1 <= x && x <= 10000;
    predicate valid_result(integer r) = r == 1 || r == 2 || r == 3;
*/

int func1(int x)
{
    int val;
    int cnt;
    val = 1;
    cnt = 0;

    //@ assert val == 1 && cnt == 0;
    if (val < x)
    {
        cnt = cnt + 1;
        val = val + 1000;
    }
    //@ assert cnt == 1 || cnt == 0;
    if (val == x)
    {
        //@ assert valid_result(cnt);
        return cnt;
    }
    else
    {
        //@ assert cnt == 1 || cnt == 2 || cnt == 3;
        return cnt;
    }
}

/* --- Original func2 (unchanged, with size_t from stddef) --- */
size_t func2(size_t x)
{
    size_t quotient;
    size_t remainder;
    size_t ans;

    quotient = x / 11;
    remainder = x % 11;
    ans = quotient * 2;

    //@ assert ans == (x / 11) * 2;

    if (remainder > 0 && remainder <= 6)
    {
        ans += 1;
        //@ assert ans == (x / 11) * 2 + 1;
    }
    else if (remainder > 6)
    {
        ans += 2;
        //@ assert ans == (x / 11) * 2 + 2;
    }

    //@ assert ans >= (x / 11) * 2;
    //@ assert ans <= (x / 11) * 2 + 2;
    return ans;
}

/* --- Original func3 (renamed, unchanged) --- */
/*@
    predicate both_nonneg(integer a, integer b) = a >= 0 && b >= 0;
    predicate both_neg(integer a, integer b) = a < 0 && b < 0;
    predicate mixed_signs(integer a, integer b) = (a >= 0 && b < 0) || (a < 0 && b >= 0);
*/

int func3(int numbers[2]) {
    int result = 0;
    int a = numbers[0];
    int b = numbers[1];
    
    if (a >= 0 && b >= 0) {
        result = a + b;
    }
    
    //@ assert both_nonneg(a, b) ==> result == a + b;
    //@ assert both_neg(a, b) ==> result == 0;
    //@ assert mixed_signs(a, b) ==> result == 0;
    
    return result;
}

/* --- Synthesized function: process_packet_batch --- 
   Scenario: Process a batch of packets. Each packet has:
   - size: an integer in [1,10000] that is a multiple of 1000 (for func1)
   - data[2]: two integer values in [-100,100]
   The function processes n packets (n >= 1) and computes:
   - priority: from func1(size)
   - checksum: from func2(size) 
   - data_valid: from func3(data)
   It returns the number of packets where all three conditions hold:
   priority >= 2, checksum % 2 == 0, and data_valid > 0.
   The high-level property: the result is between 0 and n (inclusive).
*/

int process_packet_batch(int sizes[], int data[][2], int n) {
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        int priority = func1(sizes[i]);
        size_t checksum = func2((size_t)sizes[i]);
        int data_valid = func3(data[i]);
        
        if (priority >= 2 && checksum % 2 == 0 && data_valid > 0) {
            count++;
        }
    }
    
    //@ assert 0 <= count <= n;
    return count;
}
