#include <stdint.h>

/*@
    requires 1 <= n <= 100000;
    ensures \result >= 0;
    ensures \result <= n;
*/
int64_t func(int64_t n)
{
    int64_t res = 0;
    int64_t i = 1;
    
    /*@
        loop invariant (1 <= (n) <= 100000 &&
        1 <= (i) <= (n) + 1 &&
        (res) >= 0 &&
        (res) <= (i) - 1);
        loop assigns res, i;
        loop variant n - i + 1;
    */
    while (i <= n)
    {
        int64_t div_cnt = 0;
        int64_t temp = i;
        
        /*@
            loop invariant (1 <= (n) <= 100000 &&
        1 <= (i) <= (n) + 1 &&
        0 <= (div_cnt) <= (i) / 3 &&
        (temp) >= 0 &&
        (temp) <= (i) &&
        (temp) == (i) - 3 * (div_cnt) &&
        (res) <= (i) - 1);
            loop assigns div_cnt, temp;
            loop variant temp;
        */
        while (temp >= 3)
        {
            //@ assert (1 <= (n) <= 100000 &&         1 <= (i) <= (n) + 1 &&         0 <= (div_cnt) <= (i) / 3 &&         (temp) >= 0 &&         (temp) <= (i) &&         (temp) == (i) - 3 * (div_cnt) &&         (res) <= (i) - 1);
            temp -= 3;
            div_cnt += 1;
        }
        
        int64_t cnt = 0;
        
        /*@
            loop invariant (1 <= (n) <= 100000 &&
        1 <= (i) <= (n) + 1 &&
        0 <= (div_cnt) <= (i) / 3 &&
        0 <= (cnt) <= (div_cnt) &&
        (temp) >= 0 &&
        (temp) <= (i) &&
        (temp) == (i) - 3 * (div_cnt) &&
        (res) <= (i) - 1 &&
        (cnt) <= (div_cnt));
            loop assigns cnt;
            loop variant div_cnt - cnt;
        */
        while (cnt < div_cnt)
        {
            int64_t temp2 = i;
            int64_t subtract_cnt = 0;
            
            /*@
                loop invariant (1 <= (n) <= 100000 &&
        1 <= (i) <= (n) + 1 &&
        0 <= (subtract_cnt) <= (i) / 3 &&
        (temp2) >= 0 &&
        (temp2) <= (i) &&
        (temp2) == (i) - 3 * (subtract_cnt) &&
        (res) <= (i) - 1);
                loop assigns subtract_cnt, temp2;
                loop variant temp2;
            */
            while (temp2 >= 3)
            {
                //@ assert (1 <= (n) <= 100000 &&         1 <= (i) <= (n) + 1 &&         0 <= (subtract_cnt) <= (i) / 3 &&         (temp2) >= 0 &&         (temp2) <= (i) &&         (temp2) == (i) - 3 * (subtract_cnt) &&         (res) <= (i) - 1);
                temp2 -= 3;
                subtract_cnt += 1;
            }
            
            cnt += 1;
        }
        
        if (cnt == div_cnt)
        {
            res += 1;
        }
        
        i += 1;
    }
    
    return res;
}
