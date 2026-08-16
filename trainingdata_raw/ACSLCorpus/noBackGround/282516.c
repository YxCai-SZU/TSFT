#include <limits.h>

/*@
    requires (-1290 <= (x) <= 1290);
    ensures \result == ((x) * (x) * (x));
    assigns \nothing;
*/
int func(int x)
{
    int result;
    
    //@ assert (-1290 <= (x) <= 1290);
    //@ assert x * x >= -1290 * 1290 && x * x <= 1290 * 1290;
    //@ assert x * x * x >= -1290 * 1290 * 1290 && x * x * x <= 1290 * 1290 * 1290;
    
    result = x * x * x;
    return result;
}

/* Test functions */
int test_f1(void)
{
    return func(1) == 1;
}

int test_f2(void)
{
    return func(-1) == -1;
}

int test_f3(void)
{
    return func(-9) == -729;
}

int test_f4(void)
{
    return func(9) == 729;
}

int test_f5(void)
{
    return func(-10) == -1000;
}

int test_f6(void)
{
    return func(10) == 1000;
}
