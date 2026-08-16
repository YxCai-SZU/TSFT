#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == (a <= c && c <= a + b);
*/
bool can_reach_house_3_straight(int a, int b, int c) {
    // Variable declarations at top of scope
    bool result;
    
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;
    
    //@ assert a <= c && c <= a + b ==> (a <= c && c <= a + b);
    
    result = a <= c && c <= a + b;
    return result;
}
