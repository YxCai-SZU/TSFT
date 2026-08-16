#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (h) <= 100 &&
        (h) % 2 == 0);
    ensures \result == (((a) + (b)) * (h) / 2);
*/
int func(int a, int b, int h)
{
    int sum;
    int product;
    int result;
    int temp;
    int count;

    //@ assert (1 <= (a) <= 100 &&         1 <= (b) <= 100 &&         1 <= (h) <= 100 &&         (h) % 2 == 0);
    
    sum = a + b;
    //@ assert 2 <= sum <= 200;
    
    product = sum * h;
    //@ assert 2 <= product <= 20000;
    
    result = 0;
    temp = product;
    count = 0;

    /*@
        loop invariant 0 <= temp <= product;
        loop invariant 0 <= count <= product / 2;
        loop invariant temp == product - 2 * count;
        loop invariant (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (h) <= 100 &&
        (h) % 2 == 0);
        loop invariant sum == a + b;
        loop invariant product == sum * h;
        loop assigns temp, count;
    */
    while (temp >= 2)
    {
        temp -= 2;
        count += 1;
    }

    result = count;
    //@ assert result == product / 2;
    //@ assert result == (((a) + (b)) * (h) / 2);
    
    return result;
}
