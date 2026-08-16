#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    ensures \result == true <==> a * b / 2 + b * c / 2 >= c * a / 2;
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int product1;
    unsigned int product2;
    unsigned int product3;
    unsigned int sum;
    unsigned int target;
    bool result;

    //@ assert a * b <= 10000;
    product1 = a * b;

    //@ assert b * c <= 10000;
    product2 = b * c;

    //@ assert c * a <= 10000;
    product3 = c * a;

    sum = product1 / 2 + product2 / 2;
    target = product3 / 2;

    result = (sum >= target);
    //@ assert result == true <==> ((((((a))) * (((b)))) / 2) + (((((b))) * (((c)))) / 2)) >= ((((((c))) * (((a)))) / 2));
    return result;
}
