#include <stdint.h>

/*@
    requires (1 <= (x) <= 205 && 1 <= (y) <= 205);
    ensures \result >= 0;
    assigns \nothing;
*/
int32_t func(uint32_t x, uint32_t y) {
    int32_t ans = 1000000;
    uint32_t i = 1;
    uint32_t j;
    uint32_t l;

    //@ assert (1 <= (x) <= 205 && 1 <= (y) <= 205);
    //@ assert ans >= 0;

    /*@
        loop invariant 1 <= i <= 206;
        loop invariant ans >= 0;
        loop invariant (1 <= (x) <= 205 && 1 <= (y) <= 205);
        loop assigns i, j, l, ans;
        loop variant 206 - i;
    */
    while (i < 206) {
        j = 1;

        /*@
            loop invariant 1 <= j <= 206;
            loop invariant ans >= 0;
            loop invariant (1 <= (x) <= 205 && 1 <= (y) <= 205);
            loop assigns j, l, ans;
            loop variant 206 - j;
        */
        while (j < 206) {
            l = 1;

            /*@
                loop invariant 1 <= l <= 206;
                loop invariant ans >= 0;
                loop invariant (1 <= (x) <= 205 && 1 <= (y) <= 205);
                loop assigns l, ans;
                loop variant 206 - l;
            */
            while (l < 206) {
                if (x >= i && y >= j && (x + y) <= (i + j + l)) {
                    int32_t val = (int32_t)(i + j + l);
                    if (ans > val) {
                        ans = val;
                    }
                }
                l += 1;
            }
            j += 1;
        }
        i += 1;
    }

    //@ assert ans >= 0;
    return ans;
}

int main() {
    return 0;
}
