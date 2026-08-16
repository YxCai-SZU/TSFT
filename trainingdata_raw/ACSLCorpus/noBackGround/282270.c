#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 10000 &&
        1 <= (b) && (b) <= 10000 &&
        1 <= (c) && (c) <= 10000 &&
        1 <= (d) && (d) <= 10000);
    ensures \result == ((a * b > c * d) || (a * b == c * d));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    // Variable declarations at top of scope
    unsigned int product1;
    unsigned int product2;
    bool result;

    //@ assert a * b <= 10000 * 10000;
    //@ assert c * d <= 10000 * 10000;

    product1 = a * b;
    product2 = c * d;
    result = (product1 >= product2);
    
    return result;
}

int main()
{
    return 0;
}
