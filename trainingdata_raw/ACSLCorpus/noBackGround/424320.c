#include <stdbool.h>

/*@
    requires 1 <= n <= 1000000;
    ensures \result >= 0;
    ensures \result <= n;
    ensures \result == ((n) / 9);
*/
int func(int n)
{
    int count = 0;
    int i = 1;
    
    /*@
        loop invariant 1 <= i <= n + 1;
        loop invariant count >= 0;
        loop invariant count <= i - 1;
        loop invariant count == ((i - 1) / 9);
        loop assigns i, count;
        loop variant n - i + 1;
    */
    while (i <= n)
    {
        bool is_nine_multiple = false;
        int temp = i;
        
        /*@
            loop invariant temp >= 0;
            loop invariant temp <= i;
            loop invariant \exists integer k; i == temp + 9 * k;
            loop assigns temp;
            loop variant temp;
        */
        while (temp >= 9)
        {
            temp -= 9;
        }
        
        //@ assert temp == i % 9;
        
        if (temp == 0)
        {
            is_nine_multiple = true;
        }
        
        //@ assert is_nine_multiple <==> (\exists integer k; (i) == 9 * k);
        
        if (is_nine_multiple)
        {
            count += 1;
        }
        
        //@ assert count == ((i) / 9);
        i += 1;
    }
    
    //@ assert count == ((n) / 9);
    return count;
}
