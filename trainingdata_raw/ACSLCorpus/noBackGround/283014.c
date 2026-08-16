#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 1000000000);
    ensures (0 <= (\result) && (\result) <= (n));
    ensures ((\result) == 0 || (\result) == 1 || (\result) == 2 || (\result) == 5 || (\result) == 8);
*/
int64_t func(int64_t n)
{
    int64_t result;
    int64_t count;
    int64_t i;

    if (n == 1) {
        result = 1;
        //@ assert ((result) == 0 || (result) == 1 || (result) == 2 || (result) == 5 || (result) == 8);
        return result;
    } else if (n == 2) {
        result = 1;
        //@ assert ((result) == 0 || (result) == 1 || (result) == 2 || (result) == 5 || (result) == 8);
        return result;
    } else if (n == 5) {
        result = 2;
        //@ assert ((result) == 0 || (result) == 1 || (result) == 2 || (result) == 5 || (result) == 8);
        return result;
    } else if (n == 8) {
        result = 2;
        //@ assert ((result) == 0 || (result) == 1 || (result) == 2 || (result) == 5 || (result) == 8);
        return result;
    } else {
        count = 1;
        i = 1;
        /*@
            loop invariant 1 <= i <= n + 1;
            loop invariant 1 <= count <= i;
            loop invariant count <= i;
            loop assigns i, count;
        */
        while (i < n + 1) {
            if (i == 5 || i == 8) {
                count += 1;
            }
            i += 1;
        }
        if (count == 2) {
            result = 1;
        } else {
            result = 2;
        }
        //@ assert ((result) == 0 || (result) == 1 || (result) == 2 || (result) == 5 || (result) == 8);
        return result;
    }
}
