#include <stdbool.h>

/*@
    predicate is_valid_n(integer n) = 10 <= n && n <= 99;

    logic integer manual_div(integer n, integer divisor) = n / divisor;
    logic integer manual_mod(integer n, integer divisor) = n % divisor;

    lemma mod_property: \forall integer n, divisor; 
        divisor > 0 ==> n % divisor == n - (n / divisor) * divisor;
*/

/*@
    requires is_valid_n(n);
    ensures \result == (n / 10 % 10 == 9 || n % 10 == 9);
*/
bool func(unsigned long n) {
    unsigned long quotient = 0;
    unsigned long remainder = n;
    unsigned long divisor = 10;

    /*@
        loop invariant 10 <= n <= 99;
        loop invariant 0 <= quotient <= n / divisor;
        loop invariant remainder == n - quotient * divisor;
        loop invariant remainder < n + 1;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor) {
        //@ assert remainder >= divisor;
        remainder -= divisor;
        quotient += 1;
        //@ assert remainder == n - quotient * divisor;
    }

    if (quotient == 9 || remainder == 9) {
        return true;
    } else {
        return false;
    }
}

int main() {
    return 0;
}
