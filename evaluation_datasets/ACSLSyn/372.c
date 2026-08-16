#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

/* ACSL predicates and lemmas from the original functions */

/*@
    predicate all_eq(integer a, integer b, integer c) =
        a == b && b == c;
*/

/*@
    predicate is_empty_map{L}(int8_t *m, integer size) =
        \forall integer i; 0 <= i < size ==> m[i] == 0;
*/

/*@
    lemma clear_lemma:
        \forall int8_t *m, integer size;
        is_empty_map(m, size) ==> 
        \forall integer i; 0 <= i < size ==> m[i] == 0;
*/


/*@
    predicate valid_params(integer k, integer x) =
        1 <= k <= 100 && 1 <= x <= 100000;

    logic integer compute_target(integer k, integer x) =
        x + k - 1;

    lemma overflow_prevention:
        \forall integer k, x;
        valid_params(k, x) ==> x + k - 1 <= 100000 + 100 - 1;
*/

/* Original function 1: checks if digit 7 is present in a 3-digit number */
int func(unsigned int N)
{
    unsigned int N_100;
    unsigned int N_10;
    unsigned int N_1;
    int result;

    N_100 = N / 100;
    N_10 = (N / 10) % 10;
    N_1 = N % 10;

    //@ assert N_100 == (N / 100);
    //@ assert N_10 == (N / 10) % 10;
    //@ assert N_1 == N % 10;

    result = (N_100 == 7 || N_10 == 7 || N_1 == 7);
    return result;
}

/* Original function 2: checks if three numbers are all equal */
int func2(int A, int B, int C)
{
    int result;

    //@ assert (A == B && B == C) <==> all_eq(A, B, C);

    result = (A == B && B == C);
    return result;
}

/* Original function 3: clears a memory map */
void func3(int8_t *m, uint32_t size)
{
    uint32_t i = 0;
    
    for (i = 0; i < size; ++i) {
        m[i] = 0;
        //@ assert m[i] == 0;
    }
    
    //@ assert is_empty_map(m, size);
}

/* Original function 4: counts steps based on a and p */
long func4(long a, long p)
{
    long ret;
    long count;
    bool is_non_zero;
    
    ret = a * 3 + p;
    count = 0;
    is_non_zero = false;
    
    while (ret >= 2)
    {
        //@ assert ret >= 2;
        ret -= 2;
        count += 1;
        if (!is_non_zero)
        {
            is_non_zero = count > 0;
        }
    }
    
    if (is_non_zero)
    {
        //@ assert count > 0;
        count *= 1;
    }
    
    //@ assert count >= 0;
    //@ assert count <= a * 3 + p;
    return count;
}

/* Original function 5: computes target position */
int func5(int k, int x)
{
    int min_i32 = INT_MIN;
    int result;

    //@ assert valid_params(k, x);
    
    if (x - 1 < min_i32 || k > x - 1) {
        result = -1;
    } else {
        //@ assert x - 1 >= min_i32;
        //@ assert k <= x - 1;
        //@ assert x + k - 1 <= 100000 + 100 - 1;
        result = x + k - 1;
    }

    //@ assert result == k + x - 1 || result == -1;
    return result;
}

/* Synthesized function: Process a batch of items with validation, mapping, and counting
   Scenario: In a manufacturing quality control system, we have a batch of 3-digit product IDs.
   We need to:
   1. Check if each ID contains digit 7 (indicating a special batch)
   2. Validate that three consecutive IDs form a valid triplet
   3. Clear a memory map for tracking processed items
   4. Count processing steps based on batch parameters
   5. Compute the target position for the next batch
   The high-level property: The count of processed items is consistent with the batch size and validation results.
*/
long process_batch(unsigned int id1, unsigned int id2, unsigned int id3,
                   int A, int B, int C,
                   int8_t *m, uint32_t size,
                   long a, long p,
                   int k, int x)
{
    int has_seven1, has_seven2, has_seven3;
    int all_equal;
    long count_steps;
    int target_pos;
    int processed_count = 0;

    has_seven1 = func(id1);
    has_seven2 = func(id2);
    has_seven3 = func(id3);
    
    all_equal = func2(A, B, C);
    
    func3(m, size);
    
    count_steps = func4(a, p);
    
    target_pos = func5(k, x);
    
    if (has_seven1 || has_seven2 || has_seven3) {
        processed_count = processed_count + 1;
    }
    if (all_equal) {
        processed_count = processed_count + 1;
    }
    if (target_pos != -1) {
        processed_count = processed_count + 1;
    }
    
    //@ assert count_steps >= 0 && count_steps <= a * 3 + p;
    //@ assert processed_count >= 0 && processed_count <= 3;
    //@ assert is_empty_map(m, size);
    
    //@ assert (count_steps >= 0) && (count_steps <= a * 3 + p) && (processed_count >= 0) && (processed_count <= 3);
    
    return count_steps;
}
