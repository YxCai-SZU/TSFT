#include <stdint.h>

/* ACSL specifications for vector functions */
/*@
    predicate is_nonempty(integer len) = len > 0;
    predicate is_nonnegative(integer len) = len >= 0;

    lemma vector_len_nonnegative:
        \forall integer len; is_nonempty(len) ==> is_nonnegative(len);
*/

void calc_vector_example_2(int v[], int length) {
    int l;

    //@ assert is_nonempty(length);
    l = length;
    
    //@ assert is_nonnegative(l);
}

/* ACSL specifications for triangular number functions */
/*@
    predicate is_valid_n(integer n) = 0 <= n <= 2961;

    logic integer triangular_num(integer n) = (n * (n + 1)) / 2;

    lemma triangular_bound: \forall integer n; is_valid_n(n) ==> triangular_num(n) <= triangular_num(2961);
*/

uint32_t find_triangular_num(uint32_t n)
{
    uint32_t result;

    //@ assert n + 1 <= 2962;
    //@ assert n * (n + 1) <= 2961 * 2962;

    result = (n * (n + 1)) / 2;
    //@ assert result == triangular_num(n);
    return result;
}

void print_triangular_num(uint32_t result)
{
}

/* 
 * Real-world scenario: Processing a vector of data block sizes, 
 * computing a triangular number index for each block, and verifying 
 * the final accumulated result is within valid bounds.
 * 
 * The synthesized function processes a vector of block sizes, 
 * uses the first element as an index to compute a triangular number, 
 * and asserts the computed value is non-negative (high-level invariant).
 */

uint32_t process_block_sizes(int v[], int length)
{
    uint32_t index;
    uint32_t result;

    calc_vector_example_2(v, length);

    index = (uint32_t)v[0];
    result = find_triangular_num(index);

    /*@ assert is_nonnegative((int)result); */
    /* High-level property: output satisfies non-negativity invariant 
     * derived from the chain: vector length is non-empty ensures 
     * non-negative length, and triangular number computation ensures 
     * result is within valid bounds (non-negative by definition). */
    
    return result;
}

int main()
{
    int block_sizes[3] = {10, 20, 30};
    uint32_t result;

    result = process_block_sizes(block_sizes, 3);
    //@ assert result == 55;
    print_triangular_num(result);
    return 0;
}
