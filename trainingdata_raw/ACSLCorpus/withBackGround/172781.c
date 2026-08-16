#include <stddef.h>
#include <stdbool.h>

/*@ predicate is_valid_range(integer n) = 2 <= n && n <= 100; */

/*@ predicate is_valid_array(int *arr, integer len, integer n) =
    len == n - 1 &&
    \forall integer i; 0 <= i < len ==> 0 <= arr[i] && arr[i] <= 100000; */

/*@ lemma sum_bound_lemma:
    \forall integer i, integer sum;
    0 <= i && sum >= 0 && sum <= i * 100000 ==>
    \forall integer j; 0 <= j < i ==> sum >= 0; */

/*@ requires is_valid_range(n);
    requires is_valid_array(b, n-1, n);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int n, int *b) {
    int sum = 0;
    size_t i = 0;
    size_t len = (size_t)(n - 1);
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant sum >= 0;
        loop invariant sum <= i * 100000;
        loop invariant \forall integer j; 0 <= j < i ==> sum >= b[j];
        loop invariant is_valid_range(n);
        loop invariant is_valid_array(b, n-1, n);
        loop assigns i, sum;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= b[i] && b[i] <= 100000;
        sum += b[i];
        i++;
    }
    
    int max_value = b[n - 2];
    int min_value = b[0];
    int result;
    
    if (max_value < min_value) {
        result = sum - max_value;
    } else {
        result = sum - min_value;
    }
    
    //@ assert result >= 0;
    return result;
}
