#include <limits.h>

/*@
    requires (1 <= (n) <= 1000);
    ensures \result == ((n) / 3);
    assigns \nothing;
*/
int func(int n)
{
    int result = 0;
    int temp_n = n;
    const int three = 3;
    
    /*@
        loop invariant 0 <= result <= ((n) / 3);
        loop invariant 0 <= temp_n <= n;
        loop invariant temp_n == n - result * three;
        loop invariant (1 <= (n) <= 1000);
        loop assigns result, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= three)
    {
        //@ assert temp_n >= three;
        //@ assert 0 <= temp_n - three <= 997;
        
        temp_n -= three;
        result += 1;
        
        //@ assert 0 <= result <= 333;
    }
    
    return result;
}

int main(void)
{
    return 0;
}
