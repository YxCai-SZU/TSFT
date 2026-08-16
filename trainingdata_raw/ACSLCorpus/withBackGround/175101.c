#include <stdint.h>

/*@
    predicate is_three_digit(integer v) = -99 <= v < 100;
*/

/*@
    requires is_three_digit(x) && is_three_digit(y) && is_three_digit(z);
    requires x < y && y <= z;
    ensures \result == 1 || \result == 2 || \result == 3;
    ensures \result == 1 ==> x == y && y == z;
    ensures \result == 2 ==> (x == y || y == z);
    ensures \result == 3 ==> x < y && y < z;
    assigns \nothing;
*/
int8_t non_strictly_increasing(int8_t x, int8_t y, int8_t z)
{
    int8_t ret;
    //@ assert is_three_digit(x) && is_three_digit(y) && is_three_digit(z);
    
    if (x == y && y == z) {
        ret = 1;
    } else if (x == y || y == z) {
        ret = 2;
    } else {
        ret = 3;
    }
    
    //@ assert ret == 1 || ret == 2 || ret == 3;
    return ret;
}

/*@
    requires is_three_digit(i);
    requires i == 1 || i == 2 || i == 3;
    assigns \nothing;
*/
void print_three_digit_number(int8_t i)
{
    //@ assert is_three_digit(i);
}

/*@
    assigns \nothing;
*/
int main()
{
    int8_t n;
    n = non_strictly_increasing(1, 2, 3);
    //@ assert n == 3;
    print_three_digit_number(n);
    return 0;
}
