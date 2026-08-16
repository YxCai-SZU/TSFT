#include <stdbool.h>

/*@
    predicate r_in_range(integer r) = 1 <= r && r <= 100;
    
    logic integer calculate_result(integer r) = (2 * r * 314) / 100;
*/

/*@
    requires r_in_range(r);
    ensures \result == calculate_result(r);
    assigns \nothing;
*/
int func(int r)
{
    int pi = 314;
    int result = 2 * r * pi;
    int adjusted_result = 0;
    int count = 0;
    
    //@ assert r_in_range(r);
    //@ assert pi == 314;
    //@ assert result == 2 * r * pi;
    
    /*@
        loop invariant 1 <= r && r <= 100;
        loop invariant pi == 314;
        loop invariant result >= 0;
        loop invariant result == 2 * r * pi - 100 * count;
        loop invariant adjusted_result == count;
        loop invariant count >= 0;
        loop invariant count <= (2 * r * pi) / 100;
        loop assigns result, adjusted_result, count;
        loop variant result;
    */
    while (result >= 100)
    {
        //@ assert result >= 100;
        result -= 100;
        adjusted_result += 1;
        count += 1;
        //@ assert result == 2 * r * pi - 100 * count;
        //@ assert adjusted_result == count;
    }
    
    //@ assert result == 2 * r * pi - 100 * count;
    //@ assert result < 100;
    //@ assert adjusted_result == count;
    //@ assert adjusted_result == (2 * r * pi) / 100;
    
    return adjusted_result;
}

int main(void)
{
    return 0;
}
