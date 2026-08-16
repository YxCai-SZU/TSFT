#include <stdbool.h>

/*@
    predicate valid_range(integer n) = 1 <= n <= 200000;
    
    predicate valid_array(int *arr, integer n) =
        \forall integer i; 0 <= i < n ==> 1 <= arr[i] <= 1000000000;
    
    predicate loop_invariant(integer i, integer n, integer count, integer tmp, int *numbers) =
        0 <= i <= n &&
        0 <= count <= i &&
        1 <= tmp <= 1000000000 + 1 &&
        valid_array(numbers, n) &&
        valid_range(n);
*/

/*@
    requires valid_range(n);
    requires \valid(numbers + (0 .. n-1));
    requires valid_array(numbers, n);
    
    ensures \result >= 0;
    ensures \result <= n;
*/
int func(int n, int *numbers) {
    int count = 0;
    int i = 0;
    int tmp = 1;
    
    /*@
        loop invariant loop_invariant(i, n, count, tmp, numbers);
        loop assigns i, count, tmp;
        loop variant n - i;
    */
    while (i < n) {
        int x = numbers[i];
        
        //@ assert 1 <= x <= 1000000000;
        
        if (x == tmp) {
            tmp += 1;
        } else {
            count += 1;
            tmp = x;
        }
        
        //@ assert 1 <= tmp <= 1000000000 + 1;
        //@ assert 0 <= count <= i + 1;
        
        i += 1;
    }
    
    //@ assert 0 <= count <= n;
    return count;
}
