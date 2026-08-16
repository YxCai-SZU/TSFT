#include <stdbool.h>

/* Predicates from first snippet */
/*@
    predicate is_valid_params(integer n, integer m) =
        1 <= n && n <= 100 && 0 <= m && m <= n;
*/

/*@
    predicate all_positive(int *arr, integer len) =
        len == 0 ? true :
        arr[0] > 0 ? all_positive(arr+1, len-1) :
        false;
*/

/* Predicates from second snippet */
/*@ predicate is_ascending(integer a, integer b, integer c) = 
      a < b && b < c;
*/

/* Predicates from third snippet */
/*@
    predicate valid_params(integer a, integer b, integer x) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= x && x <= 200;
*/

/* Predicates from fourth snippet */
/*@
    predicate is_valid_range(integer x) = 1 <= x && x <= 100;
*/

/* Function from first snippet */
bool func1(unsigned int n, unsigned int m)
{
    //@ assert 1 <= n && n <= 100;
    return n == m;
}

/* Function from second snippet */
bool func2(int v[3]) {
    bool result;
    //@ assert \valid(v) && \valid(v+1) && \valid(v+2);
    result = v[0] < v[1] && v[1] < v[2];
    return result;
}

/* Function from third snippet */
bool func3(unsigned long long a, unsigned long long b, unsigned long long x)
{
    bool result;
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= x && x <= 200;
    //@ assert a + b <= 200;
    //@ assert x <= 200;
    //@ assert a <= 100;
    result = (x <= a + b);
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= x && x <= 200;
    return result && (a <= x);
}

/* Functions from fourth snippet */
int func_f_impl(int x)
{
    //@ assert is_valid_range(x);
    //@ assert 2 * x - 1 == 2 * (x - 1) + 1;
    return 2 * x - 1;
}

int func_g_impl(int y)
{
    //@ assert is_valid_range(y);
    //@ assert 2 * y + 2 == 2 * (y + 1);
    return 2 * y + 2;
}

int func_h_impl(int z)
{
    //@ assert is_valid_range(z);
    //@ assert z * 3 == 3 * z;
    return z * 3;
}

/* 
 * Synthesized function: Data packet validation in a network protocol
 * Scenario: A network packet has a header with 3 fields (type, subtype, flags)
 * and a payload. The function validates the packet structure and extracts
 * a transformed version of the payload.
 *
 * Data flow:
 * 1. func1 checks if type matches expected subtype
 * 2. func2 checks if the three header fields are in ascending order
 * 3. func3 validates payload size constraints
 * 4. The payload is transformed using func_f_impl, func_g_impl, func_h_impl
 *    and combined into a result
 *
 * The high-level property: The output packet transformation preserves
 * the monotonic relationship between the original values.
 */

int validate_and_transform_packet(
    unsigned int type, 
    unsigned int subtype,
    int header[3],
    unsigned long long payload_size,
    unsigned long long max_payload,
    unsigned long long packet_size,
    int payload_val,
    int transform_a,
    int transform_b
)
{
    int result = 0;
    
    bool type_match = func1(type, subtype);
    
    bool header_valid = func2(header);
    
    bool size_valid = func3(payload_size, max_payload, packet_size);
    
    if (type_match && header_valid && size_valid) {
        int f_result = func_f_impl(payload_val);
        int g_result = func_g_impl(transform_a);
        int h_result = func_h_impl(transform_b);
        result = f_result + g_result + h_result;
    }
    
    //@ assert result >= 0;
    //@ assert (type_match && header_valid && size_valid) ==> (result == (2 * payload_val - 1) + (2 * transform_a + 2) + (3 * transform_b));
    //@ assert (!type_match || !header_valid || !size_valid) ==> (result == 0);
    
    return result;
}
