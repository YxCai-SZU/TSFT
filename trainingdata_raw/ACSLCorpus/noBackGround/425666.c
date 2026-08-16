#include <limits.h>

/*@
    requires (1 <= (N) <= 100000);
    ensures 0 <= \result <= N;
    assigns \nothing;
*/
int func(int N)
{
    int cnt = 0;
    int num = 1;
    
    /*@
        loop invariant 1 <= num <= N+1;
        loop invariant 0 <= cnt <= num-1;
        loop invariant cnt <= N;
        loop assigns cnt, num;
        loop variant N - num + 1;
    */
    while (num <= N)
    {
        int desible_by_3 = 0;
        int desible_by_5 = 0;
        int temp;
        
        // Check divisibility by 3
        temp = num;
        /*@
            loop invariant 0 <= temp <= num;
            loop invariant temp == num - 3 * ((num - temp) / 3);
            loop assigns temp;
            loop variant temp;
        */
        while (temp >= 3)
        {
            temp -= 3;
        }
        //@ assert temp == num % 3;
        if (temp == 0)
        {
            desible_by_3 = 1;
        }
        
        // Check divisibility by 5
        temp = num;
        /*@
            loop invariant 0 <= temp <= num;
            loop invariant temp == num - 5 * ((num - temp) / 5);
            loop assigns temp;
            loop variant temp;
        */
        while (temp >= 5)
        {
            temp -= 5;
        }
        //@ assert temp == num % 5;
        if (temp == 0)
        {
            desible_by_5 = 1;
        }
        
        //@ assert desible_by_3 == (num % 3 == 0) && desible_by_5 == (num % 5 == 0);
        
        if (!desible_by_3 && !desible_by_5)
        {
            cnt += 1;
        }
        
        num += 1;
        
        //@ assert 0 <= cnt <= num-1;
    }
    
    //@ assert 0 <= cnt <= N;
    return cnt;
}
