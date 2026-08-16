#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <limits.h>

/* ACSL predicates and lemmas from the original functions */

/* Predicates from func1 */
/*@ predicate is_even_divisible(integer value) =
      value % 2 == 0 ==> (value % 3 == 0 || value % 5 == 0);
*/

/*@ predicate all_even_divisible(int *a, integer n) =
      \forall integer i; 0 <= i < n ==>
        (a[i] % 2 == 0 ==> (a[i] % 3 == 0 || a[i] % 5 == 0));
*/

/* Predicates from func4 */
/*@ predicate is_valid_index(integer n) = 1 <= n && n <= 32; */

/*@ logic integer array_value(integer n) = 
      n == 1 ? 1 :
      n == 2 ? 1 :
      n == 3 ? 1 :
      n == 4 ? 2 :
      n == 5 ? 1 :
      n == 6 ? 2 :
      n == 7 ? 1 :
      n == 8 ? 5 :
      n == 9 ? 2 :
      n == 10 ? 2 :
      n == 11 ? 1 :
      n == 12 ? 5 :
      n == 13 ? 1 :
      n == 14 ? 2 :
      n == 15 ? 1 :
      n == 16 ? 14 :
      n == 17 ? 1 :
      n == 18 ? 5 :
      n == 19 ? 1 :
      n == 20 ? 5 :
      n == 21 ? 2 :
      n == 22 ? 2 :
      n == 23 ? 1 :
      n == 24 ? 15 :
      n == 25 ? 2 :
      n == 26 ? 2 :
      n == 27 ? 5 :
      n == 28 ? 4 :
      n == 29 ? 1 :
      n == 30 ? 4 :
      n == 31 ? 1 :
      51; */

/*@ lemma array_value_property: 
      \forall integer n; 
      is_valid_index(n) ==> 
      (array_value(n) == 1 || 
       array_value(n) == 2 || 
       array_value(n) == 5 || 
       array_value(n) == 14 || 
       array_value(n) == 15 || 
       array_value(n) == 51 || 
       array_value(n) == 4); */

/* Predicates from func2 */
/*@ predicate is_zero_at_index(int64_t *arr, integer idx) =
      arr[idx] == 0;
*/

/*@ predicate no_zero_before(int64_t *arr, integer bound) =
      \forall integer k; 0 <= k < bound ==> arr[k] != 0;
*/


/* Predicates from func3 */
/*@
    predicate valid_range(integer x) = 0 <= x <= 100;
    
    logic integer max_of(integer a, integer b, integer c) =
        (a > b && a > c) ? a : ((b > c) ? b : c);
    
    lemma max_bounds:
        \forall integer a, b, c;
            valid_range(a) && valid_range(b) && valid_range(c) ==>
            max_of(a, b, c) >= 0 && max_of(a, b, c) <= 100;
*/

/* Original function 1: check if all even numbers in array are divisible by 3 or 5 */
bool func1(size_t n, int a[])
{
    size_t i = 0;
    size_t num = 0;
    
    while (i < n)
    {
        int value = a[i];
        //@ assert 0 <= i < n;
        
        if (value % 2 == 0)
        {
            if (!(value % 3 == 0 || value % 5 == 0))
            {
                num++;
            }
        }
        
        i++;
    }
    
    //@ assert num == 0 <==> all_even_divisible(a, n);
    return num == 0;
}

/* Original function 2: find first zero index in array of 5 elements */
int64_t func2(int64_t *x) {
    int64_t ans = 0;
    size_t i = 0;
    while (i < 5) {
        //@ assert i < 5;
        if (x[i] == 0) {
            ans = (int64_t)i + 1;
        }
        i++;
    }
    //@ assert ans >= 0 && ans <= 5;
    return ans;
}

/* Original function 3: compute (max - a) + (max - b) + (max - c), ensure even, then divide by 2 */
long func3(long a, long b, long c)
{
    long max;
    long d;
    char is_odd;
    long temp_d;
    long result;
    
    if (a > b && a > c)
        max = a;
    else if (b > c)
        max = b;
    else
        max = c;
    
    //@ assert max >= 0 && max <= 100;
    
    d = max - a + max - b + max - c;
    
    //@ assert d >= 0;
    
    is_odd = 0;
    temp_d = d;
    
    while (temp_d >= 2)
    {
        temp_d -= 2;
    }
    
    if (temp_d == 1)
        is_odd = 1;
    
    if (is_odd)
        d += 3;
    
    //@ assert d >= 0;
    
    result = 0;
    temp_d = d;
    
    while (temp_d >= 2)
    {
        temp_d -= 2;
        result += 1;
    }
    
    //@ assert result >= 0;
    //@ assert result <= a + b + c;
    
    return result;
}

/* Original function 4: lookup value in array based on index */
int32_t func4(uint32_t n)
{
    int32_t v[32] = {
        1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14,
        1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51
    };
    
    //@ assert is_valid_index(n);
    //@ assert v[n-1] == array_value(n);
    
    return v[n-1];
}

/* 
   Scenario: Data validation and transformation pipeline for a sensor processing system.
   
   The synthesized function processes sensor data through a multi-stage pipeline:
   1. Validate sensor data array (func1) - ensures all even readings satisfy divisibility properties
   2. Find first zero-crossing index in calibration data (func2)
   3. Compute a compensation factor from three calibration parameters (func3)
   4. Look up a correction coefficient from a precomputed table (func4)
   
   The pipeline ensures that if the sensor data passes validation, the final compensation value
   is guaranteed to be non-negative and bounded by the sum of calibration parameters.
*/

long synthesized_pipeline(size_t n, int a[], int64_t *calib, long p1, long p2, long p3, uint32_t idx)
{
    bool data_valid;
    int64_t zero_pos;
    long compensation;
    int32_t coeff;
    
    data_valid = func1(n, a);
    //@ assert data_valid == true <==> all_even_divisible(a, n);
    
    zero_pos = func2(calib);
    //@ assert zero_pos >= 0 && zero_pos <= 5;
    
    compensation = func3(p1, p2, p3);
    //@ assert compensation >= 0 && compensation <= p1 + p2 + p3;
    
    coeff = func4(idx);
    //@ assert coeff == 1 || coeff == 2 || coeff == 5 || coeff == 14 || coeff == 15 || coeff == 51 || coeff == 4;
    
    long result;
    if (data_valid && zero_pos > 0) {
        result = compensation + (long)coeff;
    } else {
        result = compensation;
    }
    
    //@ assert result >= 0;
    //@ assert result <= p1 + p2 + p3 + 51;
    
    return result;
}
