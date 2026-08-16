#include <limits.h>

/*@ requires 1 <= n <= 1000;
    ensures \result == n / 3;
    assigns \nothing;
 */
int func(int n)
{
    int result;
    int remainder;
    int divisor;
    
    result = 0;
    remainder = n;
    divisor = 3;
    
    /*@ loop invariant 0 <= remainder <= n;
        loop invariant result >= 0;
        loop invariant remainder == n - divisor * result;
        loop assigns remainder, result;
        loop variant remainder;
     */
    while (remainder >= divisor) {
        remainder -= divisor;
        result += 1;
    }
    
    //@ assert remainder == n - divisor * result;
    
    return result;
}

/*@ assigns \nothing; */
int main(void)
{
    return 0;
}
