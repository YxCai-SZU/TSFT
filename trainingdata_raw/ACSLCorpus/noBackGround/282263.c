#include <stdint.h>

/*@
    requires ((2) == 2 &&
        \valid((v) + (0..1)) &&
        0 <= (v)[0] && (v)[0] <= 1000000000 &&
        0 <= (v)[1] && (v)[1] <= 1000000000);
    ensures \result >= 0;
    ensures \result <= v[0] + v[1];
    assigns \nothing;
*/
unsigned long long func(unsigned long long *v) {
    unsigned long long a;
    unsigned long long b;
    unsigned long long max;
    unsigned long long result;
    unsigned long long temp_max;

    a = v[0];
    b = v[1];
    max = (a > b) ? a : b;

    result = 0;
    temp_max = max;

    /*@
        loop invariant temp_max <= max;
        loop invariant result <= max / 2;
        loop invariant temp_max + 2 * result == max;
        loop assigns temp_max, result;
        loop variant temp_max;
    */
    while (temp_max >= 2) {
        temp_max -= 2;
        result += 1;
    }

    //@ assert result <= max / 2;

    if (a == max && temp_max == 0) {
        //@ assert result + b <= a + b;
        return result + b;
    } else if (b == max && temp_max == 0) {
        //@ assert result + a <= a + b;
        return result + a;
    } else {
        //@ assert result <= max / 2;
        //@ assert result <= a + b;
        return result;
    }
}
