#include <stdbool.h>
#include <stdint.h>

/* ========== Function 1 (find_val) ========== */

/*@
    predicate exists_in_range(int *a, integer n, int val) =
        \exists integer j; 0 <= j < n && a[j] == val;

    logic integer remaining(integer n, integer i) = n - i;

    lemma range_preserved:
        \forall integer n, i; 0 <= i <= n ==> remaining(n, i) >= 0;
*/

int find_val(int *a, int n, int val) {
    int i = 0;
    int found = 0;
    
    while (i < n && !found) {
        //@ assert 0 <= i < n;
        if (a[i] == val) {
            found = 1;
        }
        i++;
    }
    return found;
}

/* ========== Function 2 (func_divisible) ========== */

/*@
    predicate is_divisible_by_200(integer x) =
        x >= 2000 && (x % 200 == 0 || x % 200 == 100);
 */

bool func_divisible(unsigned int x)
{
    bool result = false;
    bool divisible = false;
    unsigned int temp_x = x;
    unsigned int remainder;

    if (x < 2000)
    {
        return false;
    }

    while (temp_x >= 200)
    {
        temp_x -= 200;
    }

    remainder = temp_x;

    if (remainder == 0 || remainder == 100)
    {
        divisible = true;
    }

    result = divisible;
    return result;
}

/* ========== Function 3 (func_find_zero) ========== */

/*@ predicate has_zero(uint64_t *arr, integer len) =
      arr[0] == 0 || arr[1] == 0 || arr[2] == 0 || arr[3] == 0 || arr[4] == 0;
*/

/*@ predicate in_range(uint64_t *arr, integer len) =
      \forall integer j; 0 <= j < len ==> 0 <= arr[j] <= 100;
*/

/*@ predicate all_nonzero_until(uint64_t *arr, integer i) =
      \forall integer k; 0 <= k < i ==> arr[k] != 0;
*/

/*@ lemma zero_exists: 
      \forall uint64_t *arr; \forall integer len;
      has_zero(arr, len) && len == 5 ==> 
      (\exists integer idx; 0 <= idx < len && arr[idx] == 0);
*/

uint64_t func_find_zero(uint64_t *numbers)
{
    uint64_t i = 0;
    uint64_t result = 0;
    bool found = false;

    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (numbers[i] == 0) {
            result = i;
            found = true;
            break;
        }
        i = i + 1;
    }

    //@ assert found == true;
    return result;
}

/* ========== High-Level Function ========== */

/*@
  predicate transaction_valid(uint64_t *numbers, int *a, int n, int val, unsigned int x) =
    has_zero(numbers, 5) &&
    exists_in_range(a, n, val) &&
    is_divisible_by_200(x);
*/

int validate_transaction(uint64_t *numbers, int *a, int n, int val, unsigned int x) {
    int result = 0;
    
    uint64_t zero_idx = func_find_zero(numbers);
    //@ assert numbers[zero_idx] == 0;
    
    int found_val = find_val(a, n, val);
    //@ assert (found_val == 1) <==> exists_in_range(a, n, val);
    
    bool divisible = func_divisible(x);
    //@ assert divisible <==> is_divisible_by_200(x);
    
    if (found_val == 1 && divisible == true) {
        result = 1;
    }
    
    //@ assert result == 1 <==> (exists_in_range(a, n, val) && is_divisible_by_200(x));
    
    /* High-level property: The transaction is valid if and only if
       the zero field index exists, the special code is in the audit log,
       and the amount satisfies the batch divisibility rule. */
    //@ assert result == 1 <==> transaction_valid(numbers, a, n, val, x);
    
    return result;
}
