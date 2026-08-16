#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == (x >= 2000 || (x % 200 >= 105 && x >= 105));
*/
bool func(long x) {
    long n = 0;
    long temp_x = x;
    const long divisor = 200;
    long r = 0;

    /*@
        loop invariant 0 <= n;
        loop invariant n <= x / divisor;
        loop invariant temp_x == x - n * divisor;
        loop invariant 1 <= x <= 100000;
        loop assigns n, temp_x;
    */
    while (temp_x >= divisor) {
        temp_x -= divisor;
        n += 1;
    }

    r = temp_x;

    if (x >= 2000) {
        //@ assert x >= 2000;
        return true;
    } else if (x >= 105 && r >= 105) {
        //@ assert x >= 105 && r >= 105;
        return true;
    } else {
        //@ assert x < 2000 && (x < 105 || r < 105);
        return false;
    }
}

int main() {
    return 0;
}
