#include <stdint.h>

/*@
    requires (0 <= (x) <= 1000000000);
    ensures (x >= 205) ==> (\result == (x - 205) / 2);
    ensures (x < 205) ==> (\result == 0);
    assigns \nothing;
*/
uint64_t func(uint64_t x) {
    uint64_t result = 0;
    uint64_t count = 0;
    uint64_t original_x = 0;

    if (x >= 205) {
        original_x = x - 205;
        result = 0;
        count = original_x;

        /*@
            loop invariant 0 <= count <= original_x;
            loop invariant result == (original_x - count) / 2;
            loop invariant count % 2 == original_x % 2;
            loop invariant 0 <= original_x <= 1000000000;
            loop assigns count, result;
            loop variant count;
        */
        while (count >= 2) {
            //@ assert count >= 2;
            count -= 2;
            result += 1;
            //@ assert result == (original_x - count) / 2;
        }
        //@ assert count < 2;
        return result;
    } else {
        //@ assert x < 205;
        return 0;
    }
}
