#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures \result == (((a) * 3) + (b));
    ensures ((\result) >= 0);
    assigns \nothing;
*/
int func(int a, int b) {
    // Variable declarations at scope top
    int a_new;
    int result;
    
    //@ assert 1 <= a && a <= 100;
    //@ assert a * 3 <= 300;
    //@ assert a * 3 >= 3;
    //@ assert a * 3 + b <= 400;
    //@ assert a * 3 + b >= 4;
    
    a_new = a * 3;
    //@ assert a_new == a * 3;
    //@ assert 3 <= a_new && a_new <= 300;
    
    result = a_new + b;
    //@ assert result == (a * 3) + b;
    
    return result;
}
