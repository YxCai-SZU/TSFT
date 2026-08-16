#include <stdint.h>
#include <stddef.h>

/*@
    predicate valid_nums(int64_t *nums, size_t len) =
        len >= 1 && len <= 10000 &&
        \forall size_t i; 0 <= i < len ==> nums[i] >= 1 && nums[i] <= 1000;

    predicate loop_invariant(int64_t *nums, size_t len, size_t i, int64_t sum, int64_t input) =
        i >= 0 && i <= len &&
        sum >= 0 &&
        sum <= i * 1000 &&
        \forall size_t j; 0 <= j < i ==> nums[j] >= 1 && nums[j] <= 1000 &&
        input >= 1 && input <= 1000000 &&
        len >= 1 && len <= 10000 &&
        \forall size_t k; 0 <= k < len ==> nums[k] >= 1 && nums[k] <= 1000;

    lemma loop_decreases:
        \forall size_t len, i; i <= len ==> len - i >= 0;
*/

/*@
    requires 1 <= input && input <= 1000000;
    requires \valid(nums + (0 .. len-1));
    requires valid_nums(nums, len);
    assigns \nothing;
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> \result <= input;
*/
int64_t func(int64_t input, int64_t *nums, size_t len)
{
    int64_t sum = 0;
    size_t i = 0;

    /*@
        loop invariant loop_invariant(nums, len, i, sum, input);
        loop assigns i, sum;
        loop variant len - i;
    */
    while (i < len)
    {
        //@ assert i >= 0 && i < len;
        sum += nums[i];
        i += 1;
    }

    if (sum <= input)
    {
        //@ assert sum <= input;
        return input - sum;
    }
    else
    {
        //@ assert sum > input;
        return -1;
    }
}
