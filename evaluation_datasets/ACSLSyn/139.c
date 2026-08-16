#include <stdbool.h>
#include <stddef.h>

/* Predicates from first snippet */
/*@ predicate equal_length{L}(int *vec1, size_t len1, int *vec2, size_t len2) =
      len1 == len2;
*/

/*@ lemma len_bounds:
      \forall int *vec1, size_t len1, int *vec2, size_t len2;
        len1 <= 0x80000000 && len2 <= 0x80000000 ==>
        len1 == len2 ==> equal_length(vec1, len1, vec2, len2);
*/

bool find_equal_vector_length(int *vec1, size_t len1, int *vec2, size_t len2)
{
    //@ assert len1 <= 0x80000000;
    //@ assert len2 <= 0x80000000;
    
    bool result = (len1 == len2);
    //@ assert result == (len1 == len2);
    return result;
}

/* Predicates from second snippet */
/*@
    predicate is_valid_range(integer n, integer m, integer k) =
        1 <= n <= 1000 && 1 <= m <= 1000 && 0 <= k <= n * m;

    logic integer product(integer n, integer m) = n * m;

    lemma product_bound: \forall integer n, m;
        is_valid_range(n, m, 0) ==> product(n, m) <= 1000000;

    lemma subtraction_nonnegative: \forall integer n, m, k;
        is_valid_range(n, m, k) ==> product(n, m) >= k;
*/

bool func(unsigned int n, unsigned int m, unsigned int k)
{
    unsigned int n_m = n * m;
    
    //@ assert product(n, m) <= 1000000;
    
    if (k == 0) {
        //@ assert product(n, m) - k == product(n, m);
        return n_m <= 1;
    } else {
        //@ assert product(n, m) >= k;
        //@ assert product(n, m) - k >= 0;
        return n_m - k <= 1;
    }
}

/* Synthesized function: Matrix Dimension Validation for Image Processing
 * 
 * Scenario: In an image processing pipeline, we need to validate that two image 
 * matrices have compatible dimensions and that a processing block (kernel) fits 
 * within the matrix boundaries. The function first checks if the two matrices 
 * have equal vector lengths (e.g., flattened image rows), then verifies that a 
 * kernel of size k fits within an n x m matrix with at most 1 unit of slack 
 * (i.e., the kernel nearly fills the matrix, for edge detection scenarios).
 *
 * Data flow:
 * - Input: two vectors vec1, vec2 with lengths len1, len2 representing matrix rows,
 *   and dimensions n, m, k for the kernel validation.
 * - Output: true if vectors have equal length AND the kernel fits within the matrix
 *   with slack <= 1 (i.e., n*m - k <= 1), false otherwise.
 */

bool validate_matrix_kernel(int *vec1, size_t len1, int *vec2, size_t len2,
                            unsigned int n, unsigned int m, unsigned int k)
{
    bool lengths_equal = find_equal_vector_length(vec1, len1, vec2, len2);
    
    bool kernel_fits = func(n, m, k);
    
    bool result = lengths_equal && kernel_fits;
    
    //@ assert result == (len1 == len2 && product(n, m) - k <= 1);
    
    return result;
}
