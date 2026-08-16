#include <stdbool.h>

/*@
    requires 1 <= k <= 100;
    requires 1 <= x <= 100000;
    ensures \result == (500 * k >= x);
    assigns \nothing;
*/
bool func(unsigned int k, unsigned int x)
{
    unsigned int mul_result;
    bool result;

    mul_result = 500 * k;
    //@ assert mul_result == 500 * k;
    result = (mul_result >= x);
    //@ assert result == (500 * k >= x);
    return result;
}

int main()
{
    int v[3];
    bool check_result;
    unsigned int k_val;
    unsigned int x_val;

    v[0] = 1;
    v[1] = -2;
    v[2] = 3;
    //@ assert (\exists integer i; 0 <= i < (3) && (&v[0])[i] < 0);

    k_val = 50;
    x_val = 20000;
    check_result = func(k_val, x_val);
    //@ assert check_result == (500 * k_val >= x_val);
    return 0;
}
