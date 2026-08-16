#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100 &&
        0 <= (m) && (m) <= (n));
    ensures \result == (n == m);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m)
{
    unsigned int i = 0;
    
    /*@
        loop invariant (1 <= (n) && (n) <= 100 &&
        0 <= (m) && (m) <= (n));
        loop invariant 0 <= i && i <= n;
        loop assigns i;
        loop variant n - i;
    */
    while (i < n)
    {
        //@ assert (1 <= (n) && (n) <= 100 &&         0 <= (m) && (m) <= (n));
        i += 1;
    }
    
    //@ assert i == n;
    return n == m;
}

/*@
    requires (1 <= (n) && (n) <= 100 &&
        0 <= (m) && (m) <= (n));
    ensures \result == (n != m);
    assigns \nothing;
*/
bool func2(unsigned int n, unsigned int m)
{
    unsigned int i = 0;
    
    /*@
        loop invariant (1 <= (n) && (n) <= 100 &&
        0 <= (m) && (m) <= (n));
        loop invariant 0 <= i && i <= n;
        loop assigns i;
        loop variant n - i;
    */
    while (i < n)
    {
        //@ assert (1 <= (n) && (n) <= 100 &&         0 <= (m) && (m) <= (n));
        i += 1;
    }
    
    //@ assert i == n;
    return n != m;
}

/*@
    requires (1 <= (n) && (n) <= 100 &&
        0 <= (m) && (m) <= (n));
    ensures \result == (n > m);
    assigns \nothing;
*/
bool func3(unsigned int n, unsigned int m)
{
    unsigned int i = 0;
    
    /*@
        loop invariant (1 <= (n) && (n) <= 100 &&
        0 <= (m) && (m) <= (n));
        loop invariant 0 <= i && i <= n;
        loop assigns i;
        loop variant n - i;
    */
    while (i < n)
    {
        //@ assert (1 <= (n) && (n) <= 100 &&         0 <= (m) && (m) <= (n));
        i += 1;
    }
    
    //@ assert i == n;
    return n > m;
}
