#include <stdbool.h>

/*@ requires \valid(s+(0..1));
    requires s[0] >= -100 && s[0] <= 100;
    requires s[1] >= -100 && s[1] <= 100;
    assigns \nothing;
    ensures \result == ((s[0]) == (s[1]) ? 0 : 1);
*/
int func(long long *s) {
    int ans;
    
    //@ ghost long long s0 = s[0];
    //@ ghost long long s1 = s[1];
    
    /*@ loop invariant 0 <= i <= 2;
        loop assigns i;
    */
    for (int i = 0; i < 2; i++) {
        //@ assert i == 0 || i == 1;
    }
    
    //@ assert s[0] == s[1] || s[0] != s[1];
    
    if (s[0] == s[1]) {
        ans = 0;
        //@ assert ans == ((s[0]) == (s[1]) ? 0 : 1);
    } else {
        ans = 1;
        //@ assert ans == ((s[0]) == (s[1]) ? 0 : 1);
    }
    
    //@ assert (s[0] == s[1] && ans == 0) || (s[0] != s[1] && ans == 1);
    return ans;
}
