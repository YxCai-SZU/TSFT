#include <stdbool.h>
#include <stddef.h>

/*@ requires n >= 1;
    requires \valid(a + (0 .. n-1));
    ensures \result == true <==> 
            (\forall integer i; 0 <= i < n ==> ((a[i]) % 2 == 1 || (a[i]) % 3 == 0 || (a[i]) % 5 == 0));
*/
bool func(size_t n, const int a[]) {
    bool ans = true;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant ans == true ==> 
                     (\forall integer k; 0 <= k < i ==> ((a[k]) % 2 == 1 || (a[k]) % 3 == 0 || (a[k]) % 5 == 0));
        loop invariant ans == false ==> 
                     (\exists integer k; 0 <= k < i && !((a[k]) % 2 == 1 || (a[k]) % 3 == 0 || (a[k]) % 5 == 0));
        loop assigns i, ans;
        loop variant n - i;
    */
    while (i < n) {
        int ai = a[i];
        if (!(ai % 2 == 1 || ai % 3 == 0 || ai % 5 == 0)) {
            ans = false;
            break;
        }
        i++;
    }
    
    //@ assert ans == true <==> (\forall integer i; 0 <= i < n ==> ((a[i]) % 2 == 1 || (a[i]) % 3 == 0 || (a[i]) % 5 == 0));
    return ans;
}
