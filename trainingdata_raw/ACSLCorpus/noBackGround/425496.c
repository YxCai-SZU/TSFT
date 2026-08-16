#include <stdbool.h>

/*@
    requires 1 <= N <= 10000;
    requires 0 <= a <= 1000;
    ensures \result == (N % 500 <= a);
    assigns \nothing;
*/
bool func(int N, int a)
{
    int rem;
    rem = N;

    /*@
        loop invariant 0 <= rem <= N;
        loop invariant rem == N - 500 * ((N - rem) / 500);
        loop assigns rem;
        loop variant rem;
    */
    while (rem >= 500)
    {
        rem -= 500;
    }

    //@ assert rem == N % 500;
    
    if (rem <= a)
    {
        //@ assert rem <= a;
        return true;
    }
    else
    {
        //@ assert rem > a;
        return false;
    }
}
