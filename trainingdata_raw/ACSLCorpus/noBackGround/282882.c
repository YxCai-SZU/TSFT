#include <stdint.h>
#include <stdbool.h>

/*@
    requires \valid(a + (0..1));
    requires ((2) == 2 &&
        (a)[0] >= 1 && (a)[0] <= 16 &&
        (a)[1] >= 1 && (a)[1] <= 16 &&
        (a)[0] + (a)[1] <= 16);
    ensures \result >= 1 && \result <= 32;
    assigns \nothing;
*/
int32_t func(int32_t *a) {
    int32_t result;
    int32_t i;

    //@ assert ((2) == 2 &&         (a)[0] >= 1 && (a)[0] <= 16 &&         (a)[1] >= 1 && (a)[1] <= 16 &&         (a)[0] + (a)[1] <= 16);
    
    if (a[0] + a[1] >= 16) {
        //@ assert a[0] + a[1] >= 16;
        //@ assert 1 >= 1 && 1 <= 32;
        return 1;
    } else {
        result = 0;
        i = 0;
        
        /*@
            loop invariant 0 <= i <= a[0];
            loop invariant result == (2 * (i));
            loop invariant ((2) == 2 &&
        (a)[0] >= 1 && (a)[0] <= 16 &&
        (a)[1] >= 1 && (a)[1] <= 16 &&
        (a)[0] + (a)[1] <= 16);
            loop assigns i, result;
            loop variant a[0] - i;
        */
        while (i < a[0]) {
            //@ assert i < a[0];
            result += 2;
            i += 1;
            //@ assert result == (2 * (i));
        }
        
        //@ assert i == a[0];
        //@ assert result == 2 * a[0];
        
        i = 0;
        
        /*@
            loop invariant 0 <= i <= a[1];
            loop invariant result == (2 * (a[0]) + (i));
            loop invariant ((2) == 2 &&
        (a)[0] >= 1 && (a)[0] <= 16 &&
        (a)[1] >= 1 && (a)[1] <= 16 &&
        (a)[0] + (a)[1] <= 16);
            loop assigns i, result;
            loop variant a[1] - i;
        */
        while (i < a[1]) {
            //@ assert i < a[1];
            result += 1;
            i += 1;
            //@ assert result == (2 * (a[0]) + (i));
        }
        
        //@ assert i == a[1];
        //@ assert result == (2 * (a[0]) + (a[1]));
        //@ assert result >= 1 && result <= 32;
        return result;
    }
}

int main() {
    return 0;
}
