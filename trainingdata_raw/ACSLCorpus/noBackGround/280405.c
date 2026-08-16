#include <stdbool.h>

/*@
    requires (-40 <= (x) && (x) <= 40);
    ensures (-40 <= (\result) && (\result) <= 40);
    ensures (((x) > 0 ==> (\result) == (x)) && ((x) <= 0 ==> (\result) == 0));
*/
int func(int x) {
    int ans;
    
    //@ assert (-40 <= (x) && (x) <= 40);
    
    if (x > 0) {
        //@ assert -40 <= x && x <= 40;
        ans = x;
    } else {
        ans = 0;
    }
    
    //@ assert (((x) > 0 ==> (ans) == (x)) && ((x) <= 0 ==> (ans) == 0));
    return ans;
}
