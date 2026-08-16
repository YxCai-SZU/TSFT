#include <stddef.h>

/*@
    predicate valid_array(int* arr, size_t n) =
        n >= 1 && n <= 20 &&
        \forall size_t i; 0 <= i < n ==> 1 <= arr[i] <= 50;

    logic integer max_possible_sum(integer i) = i * 49;
*/

/*@
    requires n >= 1 && n <= 20;
    requires \valid(v + (0 .. n-1));
    requires \valid(c + (0 .. n-1));
    requires valid_array(v, n);
    requires valid_array(c, n);
    ensures \result >= 0;
    ensures \result <= max_possible_sum(n);
*/
int func(size_t n, int* v, int* c) {
    int sum = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant sum >= 0;
        loop invariant sum <= max_possible_sum(i);
        loop invariant valid_array(v, n);
        loop invariant valid_array(c, n);
        loop assigns sum, i;
        loop variant n - i;
    */
    while (i < n) {
        int x = v[i];
        int y = c[i];
        
        //@ assert 1 <= x <= 50;
        //@ assert 1 <= y <= 50;
        //@ assert x - y >= -49;
        
        if (x - y > 0) {
            sum += x - y;
        }
        i++;
    }
    return sum;
}
