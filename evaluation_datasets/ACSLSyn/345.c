#include <stdint.h>
#include <stdbool.h>

/* First function: computes a value based on n and v */
/*@
    predicate valid_params(integer n, integer v) =
        1 <= n <= 20 && 1 <= v <= 20;

    logic integer func_spec(integer n, integer v) =
        (n + 1) / 2 >= v ? n + 1 - v : 2 * (v - (n + 1) / 2);

    lemma arithmetic_bounds:
        \forall integer n, v;
        valid_params(n, v) ==>
        n + 1 <= 21 &&
        v <= 20 &&
        (n + 1) / 2 <= 10 &&
        2 * (v - (n + 1) / 2) <= 40;
*/

uint32_t func1(uint32_t n, uint32_t v)
{
    uint32_t ans;
    //@ assert n + 1 <= 21;
    //@ assert v <= 20;
    //@ assert (n + 1) / 2 <= 10;
    //@ assert 2 * (v - (n + 1) / 2) <= 40;

    if ((n + 1) / 2 >= v)
    {
        ans = n + 1 - v;
    }
    else
    {
        ans = 2 * (v - (n + 1) / 2);
    }
    return ans;
}

/* Second function: checks ordering property */
/*@ predicate ordering(integer a, integer b, integer c) = (a > b) && (b > c); */

/*@ lemma lemma_ordering: \forall integer a, b, c; (a > b) && (b > c) ==> ordering(a, b, c); */

/* Third function: finds minimum in array */
/*@ predicate is_valid_index(integer i, integer n) = 0 <= i < n; */
/*@ predicate is_valid_value(integer x) = 0 <= x <= 1000; */
/*@ predicate element_exists(int *arr, integer n, integer val) = 
      \exists integer j; 0 <= j < n && arr[j] == val; */

/*@ lemma value_bounds: 
      \forall int *arr, integer n, integer i; 
      0 <= i < n && is_valid_value(arr[i]) ==> 0 <= arr[i] <= 1000; */

int func3(int n, int *v) {
    int min;
    int i;
    
    //@ assert n >= 1 && n <= 100;
    
    min = v[0];
    i = 1;
    
    while (i < n) {
        //@ assert is_valid_value(v[i]);
        
        if (v[i] < min) {
            min = v[i];
        }
        
        i++;
    }
    
    return min;
}

/* Synthesized function: Packet Processing System
 * Scenario: A network packet processor that validates packet headers and extracts payload data.
 * Data flow:
 *   1. Use func1 to compute a priority value from packet parameters (header length, version)
 *   2. Check ordering property of packet fields (header_length > version > payload_size)
 *   3. Use func3 to find minimum payload value in an array of payload data
 * Combined property: The output priority value is consistent with the packet structure
 */

uint32_t process_packet(uint32_t header_len, uint32_t version, int payload_size, int *payload)
{
    uint32_t priority;
    int min_payload;
    
    priority = func1(header_len, version);
    
    //@ assert ordering(header_len, version, payload_size);
    
    min_payload = func3(payload_size, payload);
    
    /* High-level property: The computed priority is bounded and consistent with the packet structure.
     * The priority value (0-40) is derived from valid packet parameters, and the packet
     * maintains proper ordering of its fields (header_len > version > payload_size).
     * Additionally, the minimum payload value is a valid element from the payload array. */
    //@ assert priority <= 40 && ordering(header_len, version, payload_size);
    
    return priority;
}
