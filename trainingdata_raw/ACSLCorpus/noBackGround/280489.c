#include <stdbool.h>

/*@
    requires (1 <= (l) <= 1000);
    ensures \result == (((l) * (l)) / 4);
    assigns \nothing;
*/
int func(int l)
{
    // Variable declarations at top of scope
    int result = 0;
    int temp;
    
    //@ assert (1 <= (l) <= 1000);
    //@ assert l * l <= 1000000;
    
    temp = l * l;
    
    /*@
        loop invariant 1 <= l <= 1000;
        loop invariant result == (l * l - temp) / 4;
        loop invariant temp >= 0;
        loop invariant temp + 4 * result == l * l;
        loop assigns temp, result;
        loop variant temp;
    */
    while (temp >= 4)
    {
        //@ assert temp >= 4;
        temp -= 4;
        result += 1;
        //@ assert temp + 4 * result == l * l;
    }
    
    //@ assert result == (l * l) / 4;
    return result;
}

int main(void)
{
    return 0;
}
