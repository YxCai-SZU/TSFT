#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 10000);
    ensures ((\result) == 0 || (\result) == 1);
    assigns \nothing;
*/
int func(int n)
{
    int num;
    int i;
    int temp_n;
    bool is_sufficient;
    
    //@ assert (1 <= (n) && (n) <= 10000);
    
    num = 0;
    i = 0;
    
    /*@
        loop invariant 0 <= i <= 2010;
        loop invariant (1 <= (n) && (n) <= 10000);
        loop assigns i, num, temp_n, is_sufficient;
        loop variant 2010 - i;
    */
    while (i < 2010)
    {
        num = i * 100 + 8;
        temp_n = n;
        is_sufficient = true;
        
        /*@
            loop invariant 0 <= temp_n <= n;
            loop invariant (1 <= (n) && (n) <= 10000);
            loop assigns temp_n;
            loop variant temp_n;
        */
        while (temp_n >= num)
        {
            temp_n -= num;
        }
        
        //@ assert 0 <= temp_n <= n;
        
        if (temp_n == 0)
        {
            //@ assert ((1) == 0 || (1) == 1);
            return 1;
        }
        
        i += 1;
    }
    
    //@ assert ((0) == 0 || (0) == 1);
    return 0;
}
