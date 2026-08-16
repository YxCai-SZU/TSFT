#include <limits.h>

/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (h) <= 100 &&
        (h) % 2 == 0);
    ensures \result == ((((a) + (b)) * (h)) / 2);
    assigns \nothing;
*/
int func(int a, int b, int h)
{
    int sum;
    int product;
    int half;
    int result;
    int temp;

    //@ assert (1 <= (a) <= 100 &&         1 <= (b) <= 100 &&         1 <= (h) <= 100 &&         (h) % 2 == 0);
    
    sum = a + b;
    //@ assert 2 <= sum <= 200;
    
    //@ assert 2 <= sum * h <= 20000;
    product = sum * h;
    
    half = 2;
    result = 0;
    temp = product;
    
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant 1 <= h <= 100;
        loop invariant h % 2 == 0;
        loop invariant sum == a + b;
        loop invariant product == sum * h;
        loop invariant half == 2;
        loop invariant result >= 0;
        loop invariant temp >= 0;
        loop invariant temp + result * half == product;
        loop assigns result, temp;
        loop variant temp;
    */
    while (temp >= half)
    {
        temp -= half;
        result += 1;
    }
    
    //@ assert result == ((a + b) * h) / 2;
    return result;
}
