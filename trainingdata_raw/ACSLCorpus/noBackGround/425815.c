#include <stdbool.h>

/*@
    requires (1 <= (n) <= 1000);
    ensures \result == ((n) / 3);
    assigns \nothing;
*/
int func(int n)
{
    int result = 0;
    int remainder = n;
    const int three = 3;
    
    /*@
        loop invariant 0 <= result;
        loop invariant 0 <= remainder;
        loop invariant n == remainder + result * three;
        loop assigns result, remainder;
        loop variant remainder;
    */
    while (remainder >= three)
    {
        //@ assert remainder >= three;
        result += 1;
        remainder -= three;
        //@ assert n == remainder + result * three;
    }
    
    //@ assert result == ((n) / 3);
    return result;
}

int main()
{
    return 0;
}
