#include <limits.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result <= a;
*/
int func(int a, int b) {
    int ans;
    int a_copy;
    int a_mod_b;
    int ans_mod_b;
    
    ans = 0;
    a_copy = a;
    
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant 0 <= a_copy <= a;
        loop assigns a_copy;
    */
    while (a_copy >= b) {
        a_copy -= b;
    }
    ans = a - a_copy;
    
    a_mod_b = a;
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant 0 <= a_mod_b <= a;
        loop assigns a_mod_b;
    */
    while (a_mod_b >= b) {
        a_mod_b -= b;
    }
    ans_mod_b = a_mod_b;
    
    //@ assert ans <= a;
    
    if (ans < ans_mod_b) {
        return ans;
    } else {
        return ans_mod_b;
    }
}
