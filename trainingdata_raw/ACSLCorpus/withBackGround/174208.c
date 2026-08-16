#include <stdbool.h>
#include <stdint.h>

/*@ predicate valid_range(integer n) = 1 <= n <= 100000; */
/*@ predicate valid_value(integer v) = 1 <= v <= 1000000000; */
/*@ predicate valid_array(int *arr, integer n) = 
      \forall integer i; 0 <= i < n ==> valid_value(arr[i]); */

/*@ lemma count_bounds: 
      \forall integer n, integer idx, integer cnt; 
      valid_range(n) && 0 <= cnt <= idx <= n ==> 0 <= cnt <= n; */

/*@ requires valid_range(n);
    requires n >= 1;
    requires \valid(arr + (0 .. n-1));
    requires valid_array(arr, n);
    assigns \nothing;
    ensures 0 <= \result <= n;
    ensures valid_array(arr, n);
*/
int func(int n, int *arr) {
    int a = 0;
    int b = 0;
    int c = 0;
    int count = 0;
    unsigned int index = 0;

    /*@ loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop invariant valid_array(arr, n);
        loop invariant 0 <= a <= 1000000000;
        loop invariant 0 <= b <= 1000000000;
        loop invariant 0 <= c <= 1000000000;
        loop assigns a, b, c, count, index;
        loop variant n - index;
    */
    while (index < (unsigned int)n) {
        int x = arr[index];
        
        if (a == x) {
            a = x;
            count += 1;
        } else if (b == x) {
            b = x;
            count += 1;
        } else if (c == x) {
            c = x;
            count += 1;
        } else if (a == b && b == c) {
            a = x;
            b = x;
            c = x;
            count += 1;
        } else if (a == b) {
            c = x;
            count += 1;
        } else if (b == c) {
            a = x;
            count += 1;
        } else if (a == c) {
            b = x;
            count += 1;
        } else {
            a = x;
            b = x;
            c = x;
            count += 1;
        }
        
        //@ assert 0 <= count <= index + 1;
        index += 1;
    }
    
    //@ assert 0 <= count <= n;
    return count;
}
