#include <stdint.h>

/*@
    requires (-99 <= (i) && (i) < 100);
    assigns \nothing;
*/
void print_two_digit_number(int8_t i);

/*@
    requires (-16 <= (x1) && (x1) < 16);
    ensures \result == (8 * (x1));
    assigns \nothing;
*/
int8_t octuple(int8_t x1)
{
    int8_t x2;
    int8_t x4;
    int8_t result;

    //@ assert (-16 <= (x1) && (x1) < 16);
    x2 = x1 + x1;
    //@ assert x2 == 2 * x1;
    x4 = x2 + x2;
    //@ assert x4 == 4 * x1;
    result = x4 + x4;
    //@ assert result == 8 * x1;
    return result;
}

/*@
    requires (-999 <= (i) && (i) < 1000);
    assigns \nothing;
*/
void print_three_digit_number(int32_t i);

/*@
    requires (-32 <= (x1) && (x1) < 32);
    ensures \result == (2 * (x1) + (x1));
    assigns \nothing;
*/
int8_t double_and_triple(int8_t x1)
{
    int8_t x2;
    int8_t result;

    //@ assert (-32 <= (x1) && (x1) < 32);
    x2 = x1 + x1;
    //@ assert x2 == 2 * x1;
    result = x2 + x1;
    //@ assert result == 3 * x1;
    return result;
}

int main(void)
{
    int8_t n;
    int8_t n2;

    n = octuple(10);
    //@ assert n == 80;
    //@ assert (-99 <= (n) && (n) < 100);
    print_two_digit_number(n);

    n2 = double_and_triple(10);
    //@ assert n2 == 30;
    //@ assert (-999 <= ((int32_t)n2) && ((int32_t)n2) < 1000);
    print_three_digit_number((int32_t)n2);

    return 0;
}
