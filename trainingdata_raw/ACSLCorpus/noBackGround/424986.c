#include <stdint.h>

/*@
    requires (1 <= (l) && (l) <= 1000);
    ensures \result == ((l) * (l) * (l)) / 27;
    assigns \nothing;
*/
int32_t func(int32_t l) {
    // Variable declarations at scope top
    int32_t l_cubed;
    int32_t result = 0;
    int32_t remainder;
    int32_t divisor = 27;

    // Precondition assertions
    //@ assert (1 <= (l) && (l) <= 1000);
    //@ assert ((l) * (l) * (l)) <= 1000000000;

    l_cubed = l * l * l;

    remainder = l_cubed;

    /*@
        loop invariant (1 <= (l) && (l) <= 1000);
        loop invariant l_cubed == ((l) * (l) * (l));
        loop invariant 0 <= result;
        loop invariant result * divisor <= ((l) * (l) * (l));
        loop invariant remainder == ((l) * (l) * (l)) - result * divisor;
        loop invariant 0 <= remainder;
        loop assigns result, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor) {
        remainder -= divisor;
        result += 1;
    }

    // Postcondition verification
    //@ assert remainder == ((l) * (l) * (l)) - result * divisor;
    //@ assert 0 <= remainder && remainder < divisor;
    //@ assert result == ((l) * (l) * (l)) / 27;

    return result;
}

int main() {
    return 0;
}
