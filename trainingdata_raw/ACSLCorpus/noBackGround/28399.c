#include <stdbool.h>

/*@
    requires 100 <= a <= 999;
    ensures \result == (a / 100 == 7 || (a / 10) % 10 == 7 || a % 10 == 7);
    assigns \nothing;
*/
bool func(unsigned int a) {
    unsigned int quotient_100 = 0;
    unsigned int remainder_100 = a;
    unsigned int quotient_10 = 0;
    unsigned int remainder_10 = 0;
    bool ans = false;

    /*@
        loop invariant 0 <= quotient_100;
        loop invariant remainder_100 <= a;
        loop invariant remainder_100 + 100 * quotient_100 == a;
        loop assigns quotient_100, remainder_100;
        loop variant remainder_100;
    */
    while (remainder_100 >= 100) {
        //@ assert remainder_100 >= 100;
        remainder_100 -= 100;
        quotient_100 += 1;
    }

    remainder_10 = remainder_100;

    /*@
        loop invariant 0 <= quotient_10;
        loop invariant remainder_10 <= remainder_100;
        loop invariant remainder_10 + 10 * quotient_10 == remainder_100;
        loop assigns quotient_10, remainder_10;
        loop variant remainder_10;
    */
    while (remainder_10 >= 10) {
        //@ assert remainder_10 >= 10;
        remainder_10 -= 10;
        quotient_10 += 1;
    }

    //@ assert quotient_100 == a / 100;
    //@ assert quotient_10 == (a / 10) % 10;
    //@ assert remainder_10 == a % 10;

    ans = (quotient_100 == 7) || (quotient_10 == 7) || (remainder_10 == 7);
    return ans;
}

int main() {
    return 0;
}
