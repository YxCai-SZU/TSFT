#include <stdbool.h>
#include <stddef.h>

/* ============ Function 1: bounds check ============ */
/*@
    predicate bounds(integer a, integer b, integer c) =
        0 <= a && a <= 10 &&
        0 <= b && b <= 10 &&
        0 <= c && c <= 10;

    logic integer product(integer a, integer b, integer c) = a * b * c;

    lemma product_bound:
        \forall integer a, b, c;
            bounds(a, b, c) ==> product(a, b, c) <= 1000;
*/

bool func1(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;

    //@ assert bounds(a, b, c);
    //@ assert a * b <= 100;
    //@ assert a * b * c <= 1000;

    result = (a * b * c <= 1000);
    return result;
}

/* ============ Function 2: find mismatch ============ */
/*@
    predicate x_valid(int *x) =
        \forall integer j; 0 <= j < 5 ==> x[j] == j + 1;

    predicate y_valid(int *y) =
        \forall integer j; 0 <= j < 5 ==> y[j] == j + 1;

    predicate y_has_mismatch(int *y) =
        \exists integer j; 0 <= j < 5 && y[j] != j + 1;

    lemma mismatch_exists:
        \forall int *y; y_valid(y) && y_has_mismatch(y) ==>
            \exists integer j; 0 <= j < 5 && y[j] != j + 1;
*/

int func2(int *x, int *y)
{
    size_t i;
    i = 0;

    while (i < 5)
    {
        //@ assert 0 <= i < 5;
        if (y[i] != (int)(i + 1))
        {
            //@ assert y[i] != i + 1;
            return (int)i;
        }
        i++;
    }
    return -1;
}

/* ============ Function 3: count even pairs ============ */
/*@ predicate is_valid_range3(integer n) = 1 <= n && n <= 100; */
/*@ predicate is_valid_value3(integer v) = 1 <= v && v <= 100; */
/*@ predicate array_valid3(int *a, integer n) = 
      \forall integer i; 0 <= i < n ==> is_valid_value3(a[i]); */

/*@ logic integer count_even_pairs(int *a, integer n, integer i, integer ans) =
      i == 0 ? ans : 
      count_even_pairs(a, n, i-1, ans - (((i-1) + a[i-1]) % 2 == 0 ? 1 : 0)); */

/*@ lemma ans_bounds3: 
      \forall integer n, ans, i; 
      0 <= i <= n && 0 <= ans <= i ==> 0 <= ans <= n; */

int func3(int n, int *a) {
    int ans = 0;
    int i = 0;
    
    while (i < n) {
        int value = a[i];
        
        //@ assert is_valid_value3(value);
        
        if (((i + value) % 2) == 0) {
            ans = ans + 1;
        }
        
        i = i + 1;
    }
    
    //@ assert 0 <= ans <= n;
    return ans;
}

/* ============ Function 4: weighted sum with unique check ============ */
/*@ predicate is_valid_range4(int n) = 1 <= n <= 20; */
/*@ predicate is_valid_a_len4(int n, int len) = len == n; */
/*@ predicate is_valid_b_len4(int n, int len) = len == n; */
/*@ predicate is_valid_a_elem4(int n, int val) = 1 <= val <= n; */
/*@ predicate is_valid_b_elem4(int val) = 1 <= val <= 50; */
/*@ predicate is_unique_a4(int* a, int n, integer i, integer j) = 
      (0 <= i < j < n) ==> a[i] != a[j]; */

/*@ logic integer sum_upper_bound4(integer i) = i * 50; */

/*@ lemma sum_non_negative4: \forall integer i; 0 <= i ==> 0 <= sum_upper_bound4(i); */

int func4(int n, int* a, int a_len, int* b, int b_len) {
    int sum = 0;
    unsigned int i = 0;
    
    while (i < (unsigned int)n) {
        int x = a[i];
        int y = b[x - 1];
        
        //@ assert 1 <= x <= n;
        //@ assert 1 <= y <= 50;
        
        if (x == (int)i + 1) {
            sum += y;
            //@ assert sum >= 0;
        }
        
        i++;
        //@ assert sum <= sum_upper_bound4(i);
    }
    
    return sum;
}

/* ============================================================
   Synthesized function: validate_and_compute_weighted_even_pairs
   
   Scenario: In a data validation and scoring pipeline, we first validate
   that three parameters (a, b, c) satisfy bounds. Then we check a reference
   array x (must be [1,2,3,4,5]) and data array y for the first mismatch 
   position. After that, we count how many pairs (index, value) in array a 
   have even sum (quality metric). Finally, we compute a weighted sum from 
   array a indices mapping into array b, but only for positions where 
   a[i] == i+1 (identity positions). The overall output is a tuple-like 
   structure encoded in an integer: the mismatch position (0-4) is stored 
   in the lowest 3 bits, the even pair count in the next 8 bits, and the 
   weighted sum in the remaining bits.
   
   High-level property: The result encodes valid values from each stage,
   specifically: mismatch_pos < 5, even_count >= 0, weighted_sum >= 0.
   ============================================================ */

int synthesized_func(unsigned int a, unsigned int b, unsigned int c,
                     int *x, int *y,
                     int n, int *arr,
                     int m, int *a2, int a_len, int *b2, int b_len)
{
    int result = 0;
    
    /* Stage 1: Validate bounds */
    bool valid = func1(a, b, c);
    //@ assert valid == (a * b * c <= 1000);
    
    /* Stage 2: Find mismatch position in y (compared to [1,2,3,4,5]) */
    int mismatch_pos = func2(x, y);
    //@ assert 0 <= mismatch_pos < 5;
    //@ assert y[mismatch_pos] != mismatch_pos + 1;
    
    /* Stage 3: Count even pairs in arr */
    int even_count = func3(n, arr);
    //@ assert 0 <= even_count <= n;
    
    /* Stage 4: Compute weighted sum from a2 mapping into b2 */
    int weighted_sum = func4(m, a2, a_len, b2, b_len);
    //@ assert weighted_sum >= 0;
    
    /* Encode results: mismatch_pos in lowest 3 bits, even_count in next 8 bits, weighted_sum in remaining bits */
    result = (mismatch_pos & 0x7) | ((even_count & 0xFF) << 3) | (weighted_sum << 11);
    
    //@ assert (result & 0x7) < 5;
    //@ assert ((result >> 3) & 0xFF) <= n;
    //@ assert (result >> 11) >= 0;
    
    return result;
}
