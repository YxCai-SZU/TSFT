#include <stdbool.h>

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires 1 <= c && c <= 100;
    ensures \result ==> ((a) <= (b) && (b) <= (c));
    ensures !\result ==> !((a) <= (b) && (b) <= (c));
*/
bool func(int a, int b, int c) {
    bool ans;
    
    if (a <= b && b <= c) {
        ans = true;
        //@ assert ans == true;
    } else {
        ans = false;
        //@ assert ans == false;
    }
    
    return ans;
}
