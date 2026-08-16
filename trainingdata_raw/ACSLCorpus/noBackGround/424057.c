#include <stdbool.h>
#include <stddef.h>

/*@ requires n > 0;
    requires \valid(a + (0..n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (a)[i] > 0);
    ensures \result == 1 <==> (\forall integer i; 0 <= i < (n) ==> 
        ((a)[i] % 2 != 0) || ((a)[i] % 3 == 0) || ((a)[i] % 5 == 0));
*/
bool func(size_t n, int *a) {
    bool ans = true;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant ans == 1 <==> (\forall integer j; 0 <= j < i ==> 
                              (a[j] % 2 != 0) || (a[j] % 3 == 0) || (a[j] % 5 == 0));
        loop assigns ans, i;
        loop variant n - i;
    */
    while (i < n) {
        int value = a[i];
        //@ assert value > 0;
        
        if (value % 2 == 0 && value % 3 != 0 && value % 5 != 0) {
            ans = false;
        }
        i++;
    }
    return ans;
}
