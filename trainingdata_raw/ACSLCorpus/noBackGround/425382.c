#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == (a * b + 1) / 2;
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at scope top
    int product_val;
    int result;
    int count;
    int temp;

    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    
    product_val = a * b + 1;
    //@ assert product_val == ((a) * (b) + 1);
    
    result = 0;
    count = 0;
    temp = product_val;
    
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant 0 <= count;
        loop invariant count <= (a * b + 1) / 2;
        loop invariant temp == a * b + 1 - 2 * count;
        loop invariant 1 <= a * b <= 10000;
        loop assigns count, temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
        count += 1;
    }
    
    result = count;
    //@ assert result == (a * b + 1) / 2;
    
    return result;
}
