#include <stdbool.h>
#include <stddef.h>

/* ========== First underlying function: search for sum match in 4D space ========== */
/*@
    predicate valid_range(integer x) = 1 <= x <= 7;
    predicate result_valid(integer r) = r == -1 || r == 0 || r == 1;
*/

int func1(int a, int b, int c, int k)
{
    int result = -1;
    int i = 0;
    int j = 0;
    int l = 0;
    int m = 0;

    while (i < k)
    {
        j = 0;
        while (j < k)
        {
            l = 0;
            while (l < k)
            {
                m = 0;
                while (m < k)
                {
                    //@ assert result_valid(result);
                    if (i + j + l + m == a + b + c)
                    {
                        result = 1;
                        break;
                    }
                    m += 1;
                }
                if (result == 1)
                {
                    break;
                }
                l += 1;
            }
            if (result == 1)
            {
                break;
            }
            j += 1;
        }
        if (result == 1)
        {
            break;
        }
        i += 1;
    }
    //@ assert result_valid(result);
    return result;
}

/* ========== Second underlying function: find zero index in array ========== */
/*@ predicate valid_array(int* a, integer len) =
        len == 5 &&
        \forall integer i; 0 <= i < len ==> 1 <= a[i] && a[i] <= 5 &&
        \exists integer i; 0 <= i < len && a[i] == 0;
*/

/*@ predicate zero_at_index(int* a, integer len, integer idx) =
        0 <= idx < len && a[idx] == 0;
*/

/*@ lemma exists_zero_in_array:
        \forall int* a, integer len;
        valid_array(a, len) ==> \exists integer i; 0 <= i < len && a[i] == 0;
*/

/*@ lemma array_length_five:
        \forall int* a, integer len;
        valid_array(a, len) ==> len == 5;
*/

/*@ lemma array_values_bounded:
        \forall int* a, integer len, integer i;
        valid_array(a, len) && 0 <= i < len ==> 1 <= a[i] && a[i] <= 5;
*/

long func2(int* a) {
    size_t i = 0;
    long result = -1;

    while (i < 5) {
        //@ assert 0 <= i < 5;
        
        if (a[i] == 0) {
            result = (long)i + 1;
            //@ assert result >= 1 && result <= 5;
            //@ assert zero_at_index(a, 5, result - 1);
            return result;
        }
        
        i = i + 1;
    }
    
    //@ assert false;
    return result;
}

/* ========== Third underlying function: check sum threshold ========== */
/*@
    predicate valid_params(integer k, integer x) =
        1 <= k <= 100 && 1 <= x <= 100000;

    logic integer compute_sum(integer k) = 500 * k;

    predicate result_condition(integer k, integer x, bool result) =
        result == (compute_sum(k) >= x);
*/

bool func3(unsigned int k, unsigned int x)
{
    unsigned int sum;
    bool result;

    //@ assert valid_params(k, x);
    sum = 500 * k;
    
    //@ assert sum == compute_sum(k);
    
    if (sum >= x) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result_condition(k, x, result);
    return result;
}

/* ========== Fourth underlying function: count special elements ========== */
/*@ predicate valid_array2(unsigned int *arr, size_t n) =
      n > 0 &&
      \forall integer i; 0 <= i < n ==> arr[i] > 0;
*/


unsigned int func4(unsigned int n, unsigned int *numbers) {
    unsigned int count = 0;
    size_t index = 0;
    
    while (index < n) {
        unsigned int i = numbers[index];
        
        //@ assert i > 0;
        
        if (i == 1) {
            count += 1;
        } else {
            //@ assert i >= 2;
            if (count >= i - 1) {
                count += 1;
            }
        }
        
        //@ assert count <= index + 1;
        index += 1;
    }
    
    //@ assert count <= n;
    return count;
}

/* ========== Synthesized complex function: Resource Allocation Validator ========== 
 * Real-world scenario: Validate resource allocation for a batch processing system.
 * Data flow:
 *   1. Use func1 to check if a valid allocation pattern exists (sum of 4 components matches target)
 *   2. Use func2 to find a zero-index in a validation array (indicating a flagged resource)
 *   3. Use func3 to verify if the total allocation exceeds a threshold
 *   4. Use func4 to count how many resources are in "ready" state (value 1 or satisfying condition)
 * The final assertion ensures the allocation decision is consistent with system invariants.
 */

int synthesized_func(
    int a, int b, int c, int k,
    int* arr,
    unsigned int kx, unsigned int xx,
    unsigned int n, unsigned int* numbers
) {
    int result = 0;
    
    int pattern_found = func1(a, b, c, k);
    //@ assert result_valid(pattern_found);
    
    long flagged_idx = func2(arr);
    //@ assert 1 <= flagged_idx <= 5;
    //@ assert zero_at_index(arr, 5, flagged_idx - 1);
    
    bool threshold_met = func3(kx, xx);
    //@ assert result_condition(kx, xx, threshold_met);
    
    unsigned int ready_count = func4(n, numbers);
    //@ assert 0 <= ready_count <= n;
    
    if (pattern_found == 1 && flagged_idx >= 1 && flagged_idx <= 5 && threshold_met && ready_count >= 2) {
        result = 1;
    }
    
    //@ assert (result == 1) ==> (pattern_found == 1 && threshold_met && ready_count >= 2 && 1 <= flagged_idx <= 5);
    return result;
}
