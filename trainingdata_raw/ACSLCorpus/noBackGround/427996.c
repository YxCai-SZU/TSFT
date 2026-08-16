#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == (((a) + (b)) / 2) || \result == (((a) + (b)) / 2) - 1;
*/
int func(int a, int b)
{
    int sum;
    int result;
    int count;
    int temp_sum;
    bool is_odd;
    
    sum = a + b;
    result = 0;
    count = 0;
    temp_sum = sum;
    is_odd = false;
    
    //@ assert sum == a + b;
    //@ assert 1 <= a <= 100 && 1 <= b <= 100;
    
    /*@
        loop invariant 0 <= temp_sum;
        loop invariant count == (sum - temp_sum) / 2;
        loop invariant temp_sum + 2 * count == sum;
        loop invariant sum == a + b;
        loop invariant 1 <= a <= 100 && 1 <= b <= 100;
        loop assigns temp_sum, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        temp_sum -= 2;
        count += 1;
    }
    result = count;
    
    /*@
        loop invariant 0 <= temp_sum;
        loop invariant sum == a + b;
        loop invariant 1 <= a <= 100 && 1 <= b <= 100;
        loop invariant temp_sum == 1 || temp_sum == 0;
        loop assigns temp_sum, is_odd;
        loop variant temp_sum;
    */
    while (temp_sum == 1)
    {
        is_odd = true;
        temp_sum -= 1;
    }
    
    if (is_odd)
    {
        result -= 1;
    }
    
    //@ assert result == (a + b) / 2 || result == (a + b) / 2 - 1;
    
    return result;
}

int main()
{
    return 0;
}
