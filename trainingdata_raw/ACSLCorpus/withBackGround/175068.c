#include <stdbool.h>

/*@
    predicate valid_range(integer a) = 1 <= a && a <= 3;
    predicate distinct(integer a, integer b) = a != b;
    predicate result_props(integer res, integer a, integer b) = 
        res + a + b == 6 && (res == 1 || res == 2 || res == 3);
*/

/*@
    requires valid_range(a) && valid_range(b) && distinct(a, b);
    ensures result_props(\result, a, b);
    assigns \nothing;
*/
int func(int a, int b) {
    int res;
    
    res = 6 - a - b;
    
    //@ ghost int original_res = res;
    
    /*@
        loop invariant 1 <= a && a <= 3;
        loop invariant 1 <= b && b <= 3;
        loop invariant a != b;
        loop invariant res <= 6 - a - b;
        loop invariant res >= 6 - a - b - 3 * (res / 3);
        loop invariant res + a + b == 6;
        loop assigns res;
        loop variant -res;
    */
    while (res <= 0) {
        //@ assert res + a + b == 6;
        res += 3;
    }
    
    /*@
        loop invariant 1 <= a && a <= 3;
        loop invariant 1 <= b && b <= 3;
        loop invariant a != b;
        loop invariant res >= 6 - a - b;
        loop invariant res <= 6 - a - b + 3 * (res / 3);
        loop invariant res + a + b == 6;
        loop assigns res;
        loop variant res - 4;
    */
    while (res >= 4) {
        //@ assert res + a + b == 6;
        res -= 3;
    }
    
    //@ assert res + a + b == 6;
    //@ assert res == 1 || res == 2 || res == 3;
    
    return res;
}

int main() {
    return 0;
}
