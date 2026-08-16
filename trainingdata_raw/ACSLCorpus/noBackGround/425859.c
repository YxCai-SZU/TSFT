#include <stdint.h>

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == ((2 * 31415926535 * (r)) / 10000000000);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at top of scope
    int64_t pi = 31415926535;
    int64_t result = 0;
    int64_t temp = 2 * pi * r;
    int64_t divisor = 10000000000;
    
    //@ assert pi == 31415926535;
    //@ assert divisor == 10000000000;
    //@ assert temp == (2 * 31415926535 * (r));
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 31415926535;
        loop invariant divisor == 10000000000;
        loop invariant temp >= 0;
        loop invariant result * divisor + temp == 2 * pi * r;
        loop invariant result >= 0;
        loop assigns result, temp;
    */
    while (temp >= divisor) {
        //@ assert temp >= divisor;
        temp -= divisor;
        result += 1;
        //@ assert result * divisor + temp == 2 * pi * r;
    }
    
    //@ assert result * divisor + temp == 2 * pi * r;
    //@ assert temp < divisor;
    //@ assert result == ((2 * 31415926535 * (r)) / 10000000000);
    
    return result;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
