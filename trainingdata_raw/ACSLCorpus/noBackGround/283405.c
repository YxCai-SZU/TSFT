#include <stdbool.h>
#include <stdint.h>

/*@
    requires \valid(v + (0 .. 2));
    requires 1 <= v[0] <= 20;
    requires 1 <= v[1] <= v[0];
    requires 1 <= v[2] <= 20;
    assigns \nothing;
    ensures \result == (\let result = \min((v)[1], (v)[2]);
        result);
*/
uint32_t func(uint32_t *v) {
    uint32_t result = 0;
    uint32_t i = 1;
    
    //@ assert ((3) == 3 &&         \valid((v) + (0 .. 2)) &&         1 <= (v)[0] <= 20 &&         1 <= (v)[1] <= (v)[0] &&         1 <= (v)[2] <= 20);
    
    /*@
        loop invariant 1 <= i <= v[2] + 1;
        loop invariant result == i - 1;
        loop invariant result <= v[1];
        loop invariant result <= v[2];
        loop assigns result, i;
        loop variant v[2] - i + 1;
    */
    while (i <= v[2]) {
        if (v[1] < i) {
            break;
        }
        result += 1;
        i += 1;
    }
    
    //@ assert result == (\let result = \min((v)[1], (v)[2]);         result);
    
    return result;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
