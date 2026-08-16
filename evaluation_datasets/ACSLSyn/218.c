#include <stddef.h>
#include <stdbool.h>

/* ACSL predicates from the first function */
/*@ predicate is_valid_element(integer v) = v == 0 || v == 1; */
/*@ predicate array_constraints(int *arr, integer len) =
    len == 5 &&
    \forall integer j; 0 <= j < len ==> is_valid_element(arr[j]); */

/* ACSL predicates from the second function */
/*@ predicate valid_params(integer n, integer m) =
        1 <= n && n <= 100 &&
        0 <= m && m <= n * n; */

/*@ logic integer square(integer n) = n * n; */

/* ACSL lemma from first function */
/*@ lemma count_bound: \forall int *arr, integer len, integer i, integer cnt;
    array_constraints(arr, len) && i <= len && cnt <= i ==> cnt <= len; */

/* ACSL lemma from second function */
/*@ lemma square_bounded:
        \forall integer n; 1 <= n && n <= 100 ==> n * n <= 10000; */

/* First underlying function - checks if majority of array elements are 0 */
int func(int *input) {
    size_t i = 0;
    size_t count = 0;
    int result;
    
    while (i < 5) {
        int value = input[i];
        
        //@ assert is_valid_element(value);
        
        if (value == 0) {
            count += 1;
        }
        i += 1;
    }
    
    //@ assert count <= 5;
    
    if (count > 2) {
        result = 0;
        //@ assert result == 0;
    } else {
        result = 1;
        //@ assert result == 1;
    }
    
    return result;
}

/* Second underlying function - checks if m equals n*n */
int func2(int n, int m)
{
    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= m && m <= n * n;
    
    //@ assert n * n <= 10000;
    
    if (m != n * n)
    {
        return 0;
    }
    
    if (m == n * n)
    {
        return 1;
    }
    
    return 0;
}

/* Synthesized function: Network packet validation system
 * 
 * Real-world scenario: This function validates a network packet's structure.
 * The packet contains 5 flag bits (input array), and a data field (m) that 
 * should match the square of a header field (n) for the packet to be considered 
 * well-formed. The function returns 1 if the packet is well-formed, 0 otherwise.
 *
 * Data flow:
 * 1. First, check if the majority of flag bits are set to 0 (indicating normal operation)
 * 2. Then, verify the data field constraint: m == n*n
 * 3. A packet is well-formed only if both conditions are met
 */
int check_packet_validity(int *input, int n, int m)
{
    int flag_result = func(input);
    int data_result = func2(n, m);
    int final_result;
    
    if (flag_result == 1 && data_result == 1)
    {
        final_result = 1;
    }
    else
    {
        final_result = 0;
    }
    
    //@ assert (final_result == 1) ==> (flag_result == 1 && data_result == 1);
    
    return final_result;
}
