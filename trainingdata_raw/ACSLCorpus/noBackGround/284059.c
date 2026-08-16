#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == (a + b == c || b + c == a || c + a == b);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int max;
    unsigned int sum;
    
    //@ assert a + b <= 200;
    //@ assert b + c <= 200;
    //@ assert c + a <= 200;
    
    if (a > b) {
        if (a > c) {
            max = a;
        } else {
            max = c;
        }
    } else {
        if (b > c) {
            max = b;
        } else {
            max = c;
        }
    }
    
    sum = a + b + c;
    //@ assert sum - max == max ==> ((a) + (b) == (c) || (b) + (c) == (a) || (c) + (a) == (b));
    return (sum - max == max);
}
