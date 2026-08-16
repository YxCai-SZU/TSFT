#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100);
    ensures \result == n / 2 + n % 2;
    assigns \nothing;
*/
int func(int n)
{
    int half = 0;
    int temp_n = n;
    
    /*@
        loop invariant 0 <= half;
        loop invariant 0 <= temp_n;
        loop invariant temp_n + 2 * half == n;
        loop assigns half, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 2)
    {
        half += 1;
        temp_n -= 2;
    }
    
    int remainder = (temp_n == 1) ? 1 : 0;
    
    //@ assert remainder == n % 2;
    
    int result = half + remainder;
    
    //@ assert result == n / 2 + n % 2;
    
    return result;
}

/*@
    assigns \nothing;
*/
int main()
{
    return 0;
}
