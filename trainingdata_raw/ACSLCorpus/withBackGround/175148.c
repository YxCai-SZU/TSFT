#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_even(integer x) = (x & 1) == 0; */
/*@ predicate is_divisible_by_2(integer x) = x % 2 == 0; */
/*@ predicate is_divisible_by_3(integer x) = x % 3 == 0; */
/*@ predicate is_divisible_by_5(integer x) = x % 5 == 0; */
/*@ predicate is_ok(integer x) = is_even(x) && (is_divisible_by_2(x) || is_divisible_by_3(x) || is_divisible_by_5(x)); */

/*@ lemma ok_cnt_bound: \forall integer i, integer cnt; 0 <= i && cnt >= 0 && cnt <= i ==> cnt <= i; */

/*@ requires n > 0;
    requires \valid_read(numbers + (0 .. n-1));
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
 */
int func(int n, int* numbers) {
    int ok_cnt = 0;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant ok_cnt >= 0;
        loop invariant ok_cnt <= (int)index;
        loop assigns ok_cnt, index;
        loop variant n - index;
     */
    while (index < (size_t)n) {
        int num = numbers[index];
        bool is_even = (num & 1) == 0;
        bool is_divisible_by_2 = num % 2 == 0;
        bool is_divisible_by_3 = num % 3 == 0;
        bool is_divisible_by_5 = num % 5 == 0;
        
        if (is_even && (is_divisible_by_2 || is_divisible_by_3 || is_divisible_by_5)) {
            ok_cnt += 1;
        }
        index += 1;
    }
    
    int ans = n - ok_cnt;
    //@ assert ans >= 0;
    return ans;
}
