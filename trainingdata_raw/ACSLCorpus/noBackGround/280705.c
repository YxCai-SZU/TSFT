#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 10000 &&
        0 <= (a) && (a) <= 1000);
    ensures \result == ((n % 500) <= a);
*/
bool func(unsigned long n, unsigned long a)
{
    long reminder = n;
    
    //@ assert (1 <= (n) && (n) <= 10000 &&         0 <= (a) && (a) <= 1000);
    
    /*@
        loop invariant 1 <= n && n <= 10000;
        loop invariant 0 <= a && a <= 1000;
        loop invariant reminder <= n;
        loop invariant reminder >= 0;
        loop invariant reminder == ((n) - 500 * (((n) - (reminder)) / 500));
        loop assigns reminder;
    */
    while (reminder >= 500)
    {
        //@ assert reminder >= 500;
        reminder -= 500;
    }
    
    /*@
        loop invariant 1 <= n && n <= 10000;
        loop invariant 0 <= a && a <= 1000;
        loop invariant reminder < 500;
        loop invariant reminder >= -500;
        loop invariant reminder == ((n) - 500 * (((n) - (reminder)) / 500));
        loop assigns reminder;
    */
    while (reminder < 0)
    {
        //@ assert reminder < 0;
        reminder += 500;
    }
    
    //@ assert reminder == n % 500;
    return reminder <= a;
}
