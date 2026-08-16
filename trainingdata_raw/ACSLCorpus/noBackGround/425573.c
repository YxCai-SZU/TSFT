#include <stdbool.h>
#include <stddef.h>

/*@ requires 2 <= n <= 50;
    requires \valid(v + (0..n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 0 <= (v)[i] && (v)[i] <= 100);
    requires \exists integer i; (0 <= (i) < (n) && (v)[(i)] == (n)-1);
    ensures \result == true <==> \exists integer i; (0 <= (i) < (n) && (v)[(i)] == (n)-1);
*/
bool func(size_t n, int* v) {
    bool ret = false;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant ret == false || ret == true;
        loop invariant (\forall integer i; 0 <= i < (n) ==> 0 <= (v)[i] && (v)[i] <= 100);
        loop invariant 2 <= n <= 50;
        loop invariant \forall integer k; 0 <= k < i ==> 
            (v[k] != n-1 || ret == true);
        loop assigns ret, i;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (v[i] == (int)(n - 1)) {
            ret = true;
        }
        i++;
    }
    return ret;
}
