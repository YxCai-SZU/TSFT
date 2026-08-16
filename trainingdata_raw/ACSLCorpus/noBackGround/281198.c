#include <stdbool.h>

/*@
    requires \valid(result);
    ensures ((x) >= 0) ==> *result == x;
    ensures ((x) < 0) ==> *result == 0;
*/
void func(int x, int *result) {
    int ans;
    
    if (x >= 0) {
        ans = x;
        //@ assert ans == x;
    } else {
        ans = 0;
        //@ assert ans == 0;
    }
    
    *result = ans;
}
