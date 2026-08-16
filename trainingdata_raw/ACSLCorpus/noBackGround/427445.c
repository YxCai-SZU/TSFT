#include <stdbool.h>

/*@
    requires n < 0x80000000;
    ensures \result == (n % 2 != 0);
*/
bool is_odd_c(unsigned int n)
{
    unsigned int num = n;
    
    /*@
        loop invariant 0 <= num <= n;
        loop invariant num % 2 == n % 2;
        loop invariant n < 0x80000000;
        loop assigns num;
        loop variant num;
    */
    while (num > 1)
    {
        //@ assert num >= 2;
        num -= 2;
    }
    
    //@ assert num == 0 || num == 1;
    //@ assert num == 1 ==> n % 2 != 0;
    
    return num == 1;
}

int main()
{
    return 0;
}
