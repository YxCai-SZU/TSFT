#include <stdbool.h>
/*@
    predicate valid_array(int *arr, integer n) =
        n > 0 && n <= 100000 &&
        \forall integer i; 0 <= i < n ==> arr[i] > 0 && arr[i] <= 1000000000;

    logic integer count_odds(int *arr, integer idx) =
        idx <= 0 ? 0 : ((arr[idx-1] & 1) == 1 ? 1 + count_odds(arr, idx-1) : count_odds(arr, idx-1));

    logic integer count_evens(int *arr, integer idx) =
        idx <= 0 ? 0 : ((arr[idx-1] & 1) == 0 ? 1 + count_evens(arr, idx-1) : count_evens(arr, idx-1));

    lemma bounds_lemma:
        \forall integer idx, integer a, integer b;
            a >= 0 && b >= 0 && a + b == idx && idx >= 0 ==>
            a <= idx && b <= idx;
*/

/*@
    requires n > 0 && n <= 100000;
    requires \valid(arr + (0 .. n-1));
    requires valid_array(arr, n);
    assigns \nothing;
    ensures \result >= 0 && \result <= 1000000000;
*/
int func(int n, int *arr) {
    int a = 0;
    int b = 0;
    int index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant a >= 0 && b >= 0;
        loop invariant a + b == index;
        loop invariant a == count_odds(arr, index);
        loop invariant b == count_evens(arr, index);
        loop invariant a <= index && b <= index;
        loop assigns a, b, index;
        loop variant n - index;
    */
    while (index < n) {
        int x = arr[index];
        if (x & 1) {
            a++;
        } else {
            b++;
        }
        index++;
        //@ assert a <= index && b <= index;
    }
    
    if (a >= b) {
        return a - b;
    } else {
        return b - a;
    }
}
