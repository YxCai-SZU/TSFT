#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == (((a) * (b) + 1) / 2);
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at scope top
    int product;
    int result;
    int abs_product;
    int divisor;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100);
    //@ assert 1 <= a * b <= 10000;

    product = a * b;
    result = 0;
    abs_product = (product < 0 ? -product : product) + 1;
    divisor = 2;

    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant abs_product >= 0;
        loop invariant result == (product + 1 - abs_product) / 2;
        loop invariant abs_product + divisor * result == product + 1;
        loop assigns abs_product, result;
        loop variant abs_product;
    */
    while (abs_product >= divisor)
    {
        abs_product -= divisor;
        result += 1;
    }

    //@ assert abs_product < 2;
    //@ assert product >= 0;
    //@ assert result == (product + 1 - abs_product) / 2;
    //@ assert abs_product + divisor * result == product + 1;

    if (product < 0)
    {
        result = -result;
    }

    //@ assert result == (((a) * (b) + 1) / 2);
    return result;
}

int main()
{
    return 0;
}
