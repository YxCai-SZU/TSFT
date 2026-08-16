#include <stdbool.h>

/*@
    requires 0 <= n <= 100;
    ensures \result == true <==> n % 3 == 0;
    assigns \nothing;
*/
bool is_multiple_of_3(int n)
{
    int num = n;
    
    /*@
        loop invariant 0 <= num <= n;
        loop invariant num % 3 == n % 3;
        loop assigns num;
        loop variant num;
    */
    while (num >= 3)
    {
        num -= 3;
    }
    
    //@ assert num == 0 <==> n % 3 == 0;
    return num == 0;
}

int main(void)
{
    return 0;
}
