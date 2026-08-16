#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/*@ predicate condition_holds(integer n) =
      n >= 2000 || (n % 100) * 21 <= n;
*/

/*@ lemma arithmetic_bounds:
      \forall integer n;
        1 <= n <= 10000 ==>
        (n / 100) * 21 <= 2100 &&
        (n % 100) * 21 <= 2100 &&
        (n / 100) * 21 + (n % 100) * 21 <= 4200;
*/

bool func(int n)
{
    int n_mod_100;
    int n_div_100;
    int div_result;
    bool ans;

    n_mod_100 = n % 100;
    n_div_100 = n / 100;
    
    //@ assert n_div_100 * 21 <= 2100;
    
    //@ assert n_mod_100 * 21 <= 2100;
    
    //@ assert n_div_100 * 21 + n_mod_100 * 21 <= 4200;

    div_result = (n_mod_100 > 0) ? (n_div_100 + 1) : n_div_100;
    
    ans = (n >= 2000 || (n_mod_100 * 21 <= n));
    
    //@ assert ans == (n >= 2000 || (n % 100) * 21 <= n);
    
    return ans;
}

/*@ predicate all_older_than(uint32_t *nums, integer len, uint32_t threshold) =
      \forall integer j; 0 <= j < len ==> nums[j] > threshold;
*/

bool check_all_older_than(uint32_t *nums, uint32_t len, uint32_t threshold) {
    uint32_t i = 0;
    bool result = false;
    
    while (i < len) {
        if (nums[i] <= threshold) {
            result = false;
            return result;
        }
        i = i + 1;
    }
    
    result = true;
    return result;
}

/*@ predicate access_granted(integer n, uint32_t *ages, uint32_t len) =
      condition_holds(n) && all_older_than(ages, len, (uint32_t)(n / 100));
*/

bool check_access(int n, uint32_t *ages, uint32_t len) {
    bool code_valid;
    bool ages_valid;
    uint32_t threshold;
    
    threshold = (uint32_t)(n / 100);
    
    code_valid = func(n);
    
    if (code_valid) {
        ages_valid = check_all_older_than(ages, len, threshold);
        
        return code_valid && ages_valid;
    } else {
        return false;
    }
}
