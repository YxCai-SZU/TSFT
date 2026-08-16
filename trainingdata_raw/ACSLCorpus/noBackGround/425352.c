#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == (a + b + c) / 3;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    // Variable declarations at scope top
    int sum;
    int result;
    int temp_sum;
    
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    
    //@ assert a + b + c <= 300;
    sum = a + b + c;
    
    result = 0;
    temp_sum = sum;
    
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant 1 <= c <= 100;
        loop invariant result == (sum - temp_sum) / 3;
        loop invariant temp_sum >= 0;
        loop invariant sum == a + b + c;
        loop invariant sum == temp_sum + 3 * result;
        loop assigns result, temp_sum;
        loop variant temp_sum;
    */
    while (temp_sum >= 3)
    {
        //@ assert temp_sum >= 3;
        result += 1;
        temp_sum -= 3;
        //@ assert sum == temp_sum + 3 * result;
    }
    
    //@ assert result == (a + b + c) / 3;
    return result;
}

int main()
{
    return 0;
}
