#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
*/
int func(int n)
{
    int count = 0;
    int x = 1;
    
    /*@
        loop invariant 1 <= x <= n + 1;
        loop invariant count >= 0;
        loop invariant count <= x - 1;
        loop assigns x, count;
        loop variant n - x + 1;
    */
    while (x <= n)
    {
        bool is_divisible_by_3 = false;
        int temp = x;
        
        /*@
            loop invariant 0 <= temp <= x;
            loop invariant temp % 3 == x % 3;
            loop assigns temp;
            loop variant temp;
        */
        while (temp >= 3)
        {
            temp -= 3;
        }
        
        //@ assert temp == x % 3;
        if (temp == 0)
        {
            is_divisible_by_3 = true;
        }
        
        bool is_divisible_by_5 = false;
        temp = x;
        
        /*@
            loop invariant 0 <= temp <= x;
            loop invariant temp % 5 == x % 5;
            loop assigns temp;
            loop variant temp;
        */
        while (temp >= 5)
        {
            temp -= 5;
        }
        
        //@ assert temp == x % 5;
        if (temp == 0)
        {
            is_divisible_by_5 = true;
        }
        
        //@ assert is_divisible_by_3 == (x % 3 == 0);
        //@ assert is_divisible_by_5 == (x % 5 == 0);
        
        if (!is_divisible_by_3 && !is_divisible_by_5)
        {
            count += 1;
        }
        
        //@ assert count >= 0;
        //@ assert count <= x;
        x += 1;
    }
    
    //@ assert count >= 0;
    //@ assert count <= n;
    return count;
}
