#include <stdbool.h>
#include <stdint.h>

/*@ predicate is_valid_range(integer n) = 2 <= n && n <= 100000; */
/*@ predicate is_valid_value(integer v) = 1 <= v && v <= 1000000000; */
/*@ predicate is_valid_array(int64_t *a, integer n) = 
      \forall integer i; 0 <= i < n ==> is_valid_value(a[i]); */

/*@ lemma cnt_bound: \forall integer cnt, integer index; 
      cnt <= index && index <= 100000 ==> cnt <= 100000; */

/*@ requires is_valid_range(n);
    requires \valid(a + (0 .. n-1));
    requires is_valid_array(a, n);
    assigns \nothing;
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> \result < n;
*/
int32_t func(int64_t n, int64_t *a) {
    int64_t cnt = 0;
    int64_t index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant 0 <= cnt <= index;
        loop invariant is_valid_array(a, n);
        loop assigns cnt, index;
        loop variant n - index;
    */
    while (index < n) {
        int64_t i = a[index];
        //@ assert is_valid_value(i);
        if (i & 1) {
            cnt += 1;
        }
        index += 1;
    }
    
    int32_t res;
    if (cnt & 1) {
        res = 0;
    } else {
        res = -1;
    }
    
    //@ assert res >= 0 || res == -1;
    //@ assert res >= 0 ==> res < n;
    return res;
}
