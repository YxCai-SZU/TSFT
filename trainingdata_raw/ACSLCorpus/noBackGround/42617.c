#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * ((r)) * 314) / 100);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations
    int64_t pi = 314;
    int64_t two = 2;
    int64_t scale = 100;
    int64_t product = r * two * pi;
    int64_t scaled_result = 0;
    int64_t remainder = product;

    //@ assert product == 2 * r * 314;

    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 314;
        loop invariant two == 2;
        loop invariant scale == 100;
        loop invariant scaled_result * scale + remainder == product;
        loop invariant 0 <= scaled_result * scale + remainder <= 100 * 2 * 314;
        loop invariant 0 <= scaled_result;
        loop invariant scaled_result <= product / scale;
        loop assigns scaled_result, remainder;
        loop variant remainder;
    */
    while (remainder >= scale)
    {
        scaled_result += 1;
        remainder -= scale;
    }

    //@ assert scaled_result * scale + remainder == product;
    return scaled_result;
}

int main()
{
    return 0;
}
