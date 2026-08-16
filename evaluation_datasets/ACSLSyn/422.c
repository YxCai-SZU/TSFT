#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* ========== Provided Functions (adapted with ACSL) ========== */

/* --- Function 1: func for permutation count --- */
/*@ predicate valid_params(integer n, int *p) =
      n >= 1 && n <= 200000 &&
      \valid(p + (0 .. n-1)) &&
      (\forall integer i; 0 <= i < n ==> p[i] >= 1 && p[i] <= n) &&
      (\forall integer i, j; 0 <= i < j < n ==> p[i] != p[j]);
*/


int func_perm(int n, int *p) {
    int count = 0;
    size_t index = 0;
    
    while (index < (size_t)n && index < 3) {
        int i = p[index];
        if (i - (int)index <= 2) {
            count += 1;
        }
        index += 1;
    }
    
    //@ assert count <= n;
    return count;
}

/* --- Function 2: func for bounded computation --- */
/*@
    predicate ans_condition(uint64_t x, uint64_t ans) =
        ans <= 3 * (x / 11) + 3;
*/

uint64_t func_bounded(uint64_t x)
{
    uint64_t ans;

    if (x % 11 <= 6 && x > 11)
    {
        ans = 3 * (x / 11);
    }
    else if (x % 11 > 6)
    {
        ans = 3 * (x / 11) + 1;
    }
    else
    {
        ans = 3 * (x / 11) + 3;
    }

    //@ assert ans <= 3 * (x / 11) + 3;

    return ans;
}

/* --- Function 3: func for range check --- */
/*@
    predicate is_valid_range(integer X) = 1 <= X <= 100000;
*/

uint32_t func_range(uint64_t X)
{
    uint32_t res;

    if (X / 100 * 100 + 100 == X || X / 100 * 100 + 200 == X)
    {
        res = 1;
    }
    else
    {
        res = 0;
    }
    return res;
}

/* --- Function 4: func for sorted check --- */
/*@
    predicate sorted(int *arr, integer len) =
        \forall integer i; 0 <= i < len - 1 ==> arr[i] <= arr[i + 1];
*/

bool is_sorted(int *arr, size_t len) {
    size_t i;
    
    if (len == 0) {
        return true;
    }
    
    i = 1;
    
    while (i < len) {
        //@ assert arr[i - 1] <= arr[i];
        i = i + 1;
    }
    return true;
}

/* ========== Synthesized Complex Function ========== */

/* Scenario: Data validation pipeline for a scheduling system.
   Input: 
     - n: number of processes (1..200000)
     - p: permutation of process IDs (1..n)
     - X: a timestamp value (1..100000)
     - arr: sorted array of process priorities
     - len: length of arr
   Process:
     1. Check if arr is sorted (must be, per precondition)
     2. Compute count of early processes from permutation (func_perm)
     3. Compute bounded resource estimate from timestamp (func_bounded)
     4. Check if timestamp aligns with special boundaries (func_range)
   Output: A combined status code indicating validity of all checks.
*/

/*@
    predicate valid_system_state(integer n, int *p, uint64_t X, int *arr, integer len) =
        valid_params(n, p) &&
        1 <= X <= 100000 &&
        \valid_read(arr + (0 .. len - 1)) &&
        sorted(arr, len);
*/

int process_schedule(int n, int *p, uint64_t X, int *arr, size_t len) {
    bool sorted_ok = is_sorted(arr, len);
    
    int early_count = func_perm(n, p);
    
    uint64_t resource_est = func_bounded(X);
    
    uint32_t boundary_flag = func_range(X);
    
    int result = (sorted_ok && early_count <= n && resource_est <= 3 * (X / 11) + 3 && boundary_flag <= 1) ? 1 : 0;
    
    return result;
}
