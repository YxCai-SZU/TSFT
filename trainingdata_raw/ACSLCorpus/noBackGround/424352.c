#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == n / 2 + n % 2;
    assigns \nothing;
*/
int func(int n)
{
    int half = 0;
    int temp_n = n;
    
    /*@
        loop invariant 0 <= half;
        loop invariant half <= n / 2;
        loop invariant 0 <= temp_n;
        loop invariant temp_n + 2 * half == n;
        loop invariant (1 <= (n) && (n) <= 100);
        loop assigns half, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 2)
    {
        //@ assert temp_n >= 2;
        temp_n -= 2;
        half += 1;
        //@ assert temp_n + 2 * half == n;
    }
    
    int remainder = temp_n;
    
    //@ assert half == n / 2;
    //@ assert remainder == n % 2;
    
    return half + remainder;
}
