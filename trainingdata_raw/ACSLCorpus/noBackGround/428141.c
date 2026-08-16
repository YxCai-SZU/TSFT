#include <stdbool.h>

/*@
    requires (1 <= (l) && (l) <= 1000);
    ensures \result == (((l) * (l)) / 4);
    assigns \nothing;
*/
int func(int l)
{
    int result;
    int count;
    int square;
    
    //@ assert (1 <= (l) && (l) <= 1000);
    //@ assert 1 <= ((l) * (l)) <= 1000000;
    
    result = 0;
    count = 0;
    square = l * l;
    
    /*@
        loop invariant 0 <= square <= ((l) * (l));
        loop invariant square == ((l) * (l)) - 4 * count;
        loop invariant 0 <= count <= (((l) * (l)) / 4);
        loop invariant count <= 250000;
        loop assigns square, count;
        loop variant square;
    */
    while (square >= 4)
    {
        //@ assert square >= 4;
        square -= 4;
        count += 1;
    }
    
    result = count;
    //@ assert result == (((l) * (l)) / 4);
    return result;
}

int main(void)
{
    return 0;
}
