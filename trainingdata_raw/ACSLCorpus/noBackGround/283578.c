#include <stdbool.h>

/*@
    requires 2 <= n <= 100;
    requires 1 <= a < b <= n;
    ensures \result == ((b - a) % 2 == 0);
*/
bool func(int n, int a, int b) {
    int diff;
    bool is_even = true;
    int temp_diff;
    
    //@ assert 1 <= a < b <= n;
    //@ assert 2 <= n <= 100;
    
    diff = b - a;
    temp_diff = diff;
    
    /*@
        loop invariant 0 <= temp_diff <= diff;
        loop invariant (diff - temp_diff) % 2 == 0;
        loop assigns temp_diff;
    */
    while (temp_diff > 1) {
        //@ assert temp_diff > 1;
        temp_diff -= 2;
        //@ assert (diff - temp_diff) % 2 == 0;
    }
    
    //@ assert temp_diff == 0 || temp_diff == 1;
    
    if (temp_diff == 1) {
        is_even = false;
    }
    
    //@ assert is_even == ((b - a) % 2 == 0);
    return is_even;
}
