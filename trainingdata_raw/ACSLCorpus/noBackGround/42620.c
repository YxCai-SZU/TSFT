#include <stdbool.h>
#include <stddef.h>

/*@
    requires n > 0 && n <= 100;
    requires \valid(a + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (a)[i] > 0 && (a)[i] <= 1000);
    assigns \nothing;
    ensures \result == true <==> 
        \forall integer i; 0 <= i < n ==> 
            (a[i] % 2 != 0) || (a[i] % 6 == 0) || (a[i] % 10 == 0);
*/
bool func(size_t n, const int a[]) {
    size_t i;
    bool res;
    
    i = 0;
    res = true;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant res == true <==> (\forall integer j; 0 <= j < (i) ==> 
            ((a)[j] % 2 != 0) || ((a)[j] % 6 == 0) || ((a)[j] % 10 == 0));
        loop assigns i, res;
        loop variant n - i;
    */
    while (i < n) {
        int v;
        
        v = a[i];
        
        //@ assert v > 0 && v <= 1000;
        
        if (v % 2 == 0 && v % 6 != 0 && v % 10 != 0) {
            res = false;
        }
        
        i += 1;
    }
    
    return res;
}
