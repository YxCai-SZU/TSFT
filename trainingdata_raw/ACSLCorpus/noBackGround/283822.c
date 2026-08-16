#include <stdbool.h>

/*@
    requires \valid(a+(0..4));
    requires (\forall integer i; 0 <= i < (5) ==> (a)[i] <= (123));
    requires (\forall integer i; 0 <= i < (5)-1 ==> (a)[i] < (a)[i+1]);
    requires k <= 123;
    ensures \result == true <==> (a[4] - a[0] <= k);
*/
bool func(unsigned long long *a, unsigned long long k) {
    bool ans = false;
    
    //@ assert a[0] <= 123;
    
    //@ assert a[4] <= 123;
    
    //@ assert a[4] - a[0] <= 123;
    
    if (a[4] - a[0] <= k) {
        ans = true;
    }
    
    return ans;
}
