#include <stddef.h>
#include <stdint.h>

/* First function: resource allocation calculation */
/*@
    predicate is_valid_params(integer n, integer m) =
        1 <= n && 1 <= m && n <= 1000000000 && m <= 1000000000;

    logic integer func_spec(integer n, integer m) =
        n * 2 > m ?
            (m % 2 == 0 ? m / 2 : m / 2 + 1)
        :
            n + (m - n * 2) / 4;

    lemma func_bound: \forall integer n, m;
        is_valid_params(n, m) ==> 0 <= func_spec(n, m) && func_spec(n, m) <= n + (m / 2);
*/

unsigned long func(unsigned long n, unsigned long m)
{
    unsigned long result;
    //@ assert is_valid_params(n, m);
    
    if (n * 2 > m)
    {
        if (m % 2 == 0)
        {
            result = m / 2;
            //@ assert result == func_spec(n, m);
        }
        else
        {
            result = m / 2 + 1;
            //@ assert result == func_spec(n, m);
        }
    }
    else
    {
        //@ assert n + (m - n * 2) / 4 <= n + (m / 2);
        result = n + (m - n * 2) / 4;
        //@ assert result == func_spec(n, m);
    }
    
    //@ assert result >= 0;
    //@ assert result <= n + (m / 2);
    return result;
}

/* Second function: threshold-based counting */
/*@
    predicate valid_array(int32_t *arr, size_t n) =
        n > 0 && n <= 100 &&
        \forall size_t i; 0 <= i < n ==> 0 < arr[i] && arr[i] <= 100;

    logic integer count_condition(integer tmp, integer elem) =
        tmp <= elem ? 1 : 0;
*/

int32_t func2(size_t n, int32_t *a) {
    size_t tmp = 0;
    int32_t count = 0;
    size_t index = 0;

    while (tmp <= 100 && index < n) {
        //@ assert 0 <= index < n;
        if (tmp <= a[index]) {
            count++;
        }
        tmp++;
        index++;
    }
    return count;
}

/* Synthesized function: Resource-constrained array processing
   Scenario: Given an array of resource sizes and total capacity parameters,
   compute how many resources fit within the optimal allocation threshold.
   The first function calculates the optimal allocation limit, and the second
   function counts how many array elements are not less than each threshold step. */
int32_t process_resources(size_t n, int32_t *a, unsigned long resource_count, unsigned long total_capacity)
{
    unsigned long allocation_limit = func(resource_count, total_capacity);
    int32_t result;
    
    //@ assert allocation_limit >= 0;
    //@ assert allocation_limit <= resource_count + (total_capacity / 2);
    
    size_t tmp = 0;
    int32_t count = 0;
    size_t index = 0;
    
    while (tmp <= (size_t)allocation_limit && index < n) {
        //@ assert 0 <= index < n;
        if (tmp <= a[index]) {
            count++;
        }
        tmp++;
        index++;
    }
    
    result = count;
    
    //@ assert result >= 0;
    //@ assert result <= (int32_t)n;
    return result;
}
