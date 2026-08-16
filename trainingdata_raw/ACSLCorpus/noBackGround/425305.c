#include <stdbool.h>
#include <stddef.h>

/*@
    requires n >= 1 && n <= 1000000;
    requires \valid(a_vec + (0 .. len-1));
    requires ((len) >= 1 && (len) <= 10000 &&
    \forall integer i; 0 <= i < (len) ==> (a_vec)[i] >= 1 && (a_vec)[i] <= 10000);
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
*/
int func(int n, int *a_vec, size_t len) {
    int sum = 0;
    size_t index = 0;
    
    /*@
        loop invariant ((index) >= 0 && (index) <= (len) &&
    (sum) >= 0 &&
    (sum) <= (index) * 10000 &&
    (((len)) >= 1 && ((len)) <= 10000 &&
    \forall integer i; 0 <= i < ((len)) ==> ((a_vec))[i] >= 1 && ((a_vec))[i] <= 10000) &&
    (n) >= 1 && (n) <= 1000000 &&
    (len) >= 1 && (len) <= 10000 &&
    (index) <= (len) &&
    (sum) <= (n) + (index) * 10000 &&
    ((index) > 0 ==> \forall integer k; 0 <= k < (index) ==> (sum) >= (a_vec)[k]));
        loop invariant index <= len;
        loop assigns sum, index;
        loop variant len - index;
    */
    while (index < len) {
        //@ assert ((index) >= 0 && (index) <= (len) &&     (sum) >= 0 &&     (sum) <= (index) * 10000 &&     (((len)) >= 1 && ((len)) <= 10000 &&     \forall integer i; 0 <= i < ((len)) ==> ((a_vec))[i] >= 1 && ((a_vec))[i] <= 10000) &&     (n) >= 1 && (n) <= 1000000 &&     (len) >= 1 && (len) <= 10000 &&     (index) <= (len) &&     (sum) <= (n) + (index) * 10000 &&     ((index) > 0 ==> \forall integer k; 0 <= k < (index) ==> (sum) >= (a_vec)[k]));
        sum += a_vec[index];
        index++;
        //@ assert sum <= n + (int)index * 10000;
    }
    
    int result = 0;
    if (n > sum) {
        result = n - sum;
    }
    
    //@ assert result >= 0;
    //@ assert result <= n;
    return result;
}
