#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/* First function: extracts last 12 bits */
/*@
    predicate is_last_12_bits(uint32_t a, uint32_t result) =
        result == (a & 0x00000FFF);
*/

uint32_t extract_last_12_bits(uint32_t a)
{
    uint32_t result;
    //@ assert a <= 0x00000FFF;
    result = a & 0x00000FFF;
    //@ assert is_last_12_bits(a, result);
    return result;
}

/* Second function: checks for equal pairs in first three elements */
/*@
    predicate valid_vec(unsigned int *arr, size_t len) =
        len >= 3 && \valid(arr + (0 .. len-1));

    predicate has_equal_pair(unsigned int *arr, size_t len) =
        arr[1] == arr[2] || arr[0] == arr[2] || arr[1] == arr[0];
*/

bool check_equal_pair(unsigned int *v, size_t v_len) {
    unsigned int a;
    unsigned int b;
    unsigned int c;
    bool result;

    //@ assert v_len >= 3;
    
    if (v_len < 3) {
        return false;
    }

    a = v[0];
    b = v[1];
    c = v[2];

    //@ assert \valid(v + (0 .. 2));

    if (a == b || b == c || c == a) {
        return true;
    }

    return false;
}

/* Synthesized function: extracts last 12 bits from first three elements and checks for equal pairs */
/*@
    predicate synthesized_property(uint32_t *arr, size_t len) =
        len >= 3 && \valid(arr + (0 .. len-1)) &&
        (\let a = (arr[0] & 0x00000FFF);
         \let b = (arr[1] & 0x00000FFF);
         \let c = (arr[2] & 0x00000FFF);
         (a == b || b == c || c == a));
*/

int process_vector_packet(uint32_t *arr, size_t len) {
    uint32_t extracted[3];
    bool has_pair;
    
    //@ assert len >= 3;
    //@ assert \valid(arr + (0 .. 2));
    
    /* Extract last 12 bits from each of the first three elements */
    extracted[0] = extract_last_12_bits(arr[0]);
    extracted[1] = extract_last_12_bits(arr[1]);
    extracted[2] = extract_last_12_bits(arr[2]);
    
    /*@ assert \forall integer i; 0 <= i < 3 ==> 
        extracted[i] == (arr[i] & 0x00000FFF); */
    
    /* Check for equal pairs among extracted values */
    has_pair = check_equal_pair((unsigned int *)extracted, 3);
    
    //@ assert has_pair == 1 <==> synthesized_property(arr, len);
    
    return has_pair ? 1 : 0;
}
