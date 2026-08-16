#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid(a+(0..4));
  requires (\forall integer i; 0 <= i < (5)-1 ==> (a)[i] < (a)[i+1]);
  requires (\forall integer i; 0 <= i < (5) ==> (a)[i] <= 123);
  requires k <= 123;
  ensures \result == (a[4] - a[0] <= k);
*/
bool func(int *a, size_t k)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert a[0] < a[1] && a[1] < a[2] && a[2] < a[3] && a[3] < a[4];
    
    if (a[4] - a[0] > (int)k) {
        result = false;
    } else {
        //@ assert a[4] - a[0] <= (int)k;
        result = true;
    }
    
    return result;
}
