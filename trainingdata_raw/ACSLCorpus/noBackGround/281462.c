#include <stdint.h>

/*@
    requires (-100 <= (x) <= 100);
    ensures \result == (9 * (x));
    assigns \nothing;
*/
int32_t multiply_by_9(int32_t x)
{
    int32_t product;
    //@ assert (-100 <= (x) <= 100);
    product = 9 * x;
    //@ assert product == (9 * (x));
    return product;
}

/*@
    assigns \nothing;
*/
void print_three_digit_number(int32_t i)
{
    // Implementation provided externally
}

int main()
{
    int32_t n;
    n = multiply_by_9(11);
    //@ assert n == 99;
    print_three_digit_number(n);
    return 0;
}
