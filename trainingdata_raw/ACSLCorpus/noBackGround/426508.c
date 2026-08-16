#include <limits.h>

/*@
    requires (1 <= (X) <= 1000000000);
    ensures \result == (((X) / 3) + ((X) / 9) + ((X) / 100) + ((X) / 900) + 
        ((X) / 10000) + ((X) / 90000) + ((X) / 1000000));
    assigns \nothing;
*/
long long func(long long X)
{
    long long X_local;
    long long X_3;
    long long temp;
    long long X_9;
    long long X_100;
    long long X_900;
    long long X_10000;
    long long X_90000;
    long long X_1000000;
    long long result;
    
    X_local = X;
    
    X_3 = 0;
    temp = X_local;
    /*@
        loop invariant 0 <= X_3 <= X_local / 3;
        loop invariant temp == X_local - 3 * X_3;
        loop assigns X_3, temp;
        loop variant temp;
    */
    while (temp >= 3)
    {
        temp -= 3;
        X_3 += 1;
    }
    //@ assert X_3 == X_local / 3;
    
    X_9 = 0;
    temp = X_local;
    /*@
        loop invariant 0 <= X_9 <= X_local / 9;
        loop invariant temp == X_local - 9 * X_9;
        loop assigns X_9, temp;
        loop variant temp;
    */
    while (temp >= 9)
    {
        temp -= 9;
        X_9 += 1;
    }
    //@ assert X_9 == X_local / 9;
    
    X_100 = 0;
    temp = X_local;
    /*@
        loop invariant 0 <= X_100 <= X_local / 100;
        loop invariant temp == X_local - 100 * X_100;
        loop assigns X_100, temp;
        loop variant temp;
    */
    while (temp >= 100)
    {
        temp -= 100;
        X_100 += 1;
    }
    //@ assert X_100 == X_local / 100;
    
    X_900 = 0;
    temp = X_local;
    /*@
        loop invariant 0 <= X_900 <= X_local / 900;
        loop invariant temp == X_local - 900 * X_900;
        loop assigns X_900, temp;
        loop variant temp;
    */
    while (temp >= 900)
    {
        temp -= 900;
        X_900 += 1;
    }
    //@ assert X_900 == X_local / 900;
    
    X_10000 = 0;
    temp = X_local;
    /*@
        loop invariant 0 <= X_10000 <= X_local / 10000;
        loop invariant temp == X_local - 10000 * X_10000;
        loop assigns X_10000, temp;
        loop variant temp;
    */
    while (temp >= 10000)
    {
        temp -= 10000;
        X_10000 += 1;
    }
    //@ assert X_10000 == X_local / 10000;
    
    X_90000 = 0;
    temp = X_local;
    /*@
        loop invariant 0 <= X_90000 <= X_local / 90000;
        loop invariant temp == X_local - 90000 * X_90000;
        loop assigns X_90000, temp;
        loop variant temp;
    */
    while (temp >= 90000)
    {
        temp -= 90000;
        X_90000 += 1;
    }
    //@ assert X_90000 == X_local / 90000;
    
    X_1000000 = 0;
    temp = X_local;
    /*@
        loop invariant 0 <= X_1000000 <= X_local / 1000000;
        loop invariant temp == X_local - 1000000 * X_1000000;
        loop assigns X_1000000, temp;
        loop variant temp;
    */
    while (temp >= 1000000)
    {
        temp -= 1000000;
        X_1000000 += 1;
    }
    //@ assert X_1000000 == X_local / 1000000;
    
    result = X_3 + X_9 + X_100 + X_900 + X_10000 + X_90000 + X_1000000;
    return result;
}
