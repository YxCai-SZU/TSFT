#include <stdint.h>

/*@
    requires (-1000 <= (x) <= 1000);
    ensures ((\result) == 4 * (x));
    assigns \nothing;
*/
int32_t multiply_by_4(int32_t x)
{
    //@ assert 4 * x == 4 * x;
    int32_t z;
    z = x + x + x + x;
    //@ assert z == 4 * x;
    return z;
}

/*@
    assigns \nothing;
*/
void print_result(int32_t i)
{
    // Implementation placeholder
}

/*@
    assigns \nothing;
*/
int main2()
{
    int32_t result;
    //@ assert -1000 <= 150 <= 1000;
    result = multiply_by_4(150);
    //@ assert result == 4 * 150;
    //@ assert result == 600;
    print_result(result);
    return 0;
}
