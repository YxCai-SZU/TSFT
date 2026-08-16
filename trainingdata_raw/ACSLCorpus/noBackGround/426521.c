#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result <= (a + b + 1) / 4;
    assigns \nothing;
*/
int func(int a, int b)
{
    int sum;
    int res;
    int count;
    int temp_sum;
    
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    
    sum = a + b + 1;
    res = 0;
    count = 0;
    temp_sum = sum;
    
    /*@
        loop invariant 0 <= count <= (a + b + 1) / 4;
        loop invariant res == count;
        loop invariant temp_sum == sum - 4 * count;
        loop invariant temp_sum >= 0;
        loop invariant sum == a + b + 1;
        loop assigns temp_sum, res, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 4)
    {
        //@ assert temp_sum >= 4;
        temp_sum -= 4;
        res += 1;
        count += 1;
        //@ assert temp_sum == sum - 4 * count;
    }
    
    //@ assert res == (a + b + 1) / 4;
    return res;
}

int main()
{
    return 0;
}
