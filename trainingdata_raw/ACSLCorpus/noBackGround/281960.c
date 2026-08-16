#include <stdbool.h>

/*@
    requires 1 <= r <= 100;
    ensures \result == 2 * r * 3142 / 1000;
    assigns \nothing;
*/
int func(int r)
{
    int pi_approx;
    int scaled_r;
    int result;
    int temp;
    
    pi_approx = 3142;
    scaled_r = r * 2 * pi_approx;
    result = 0;
    temp = scaled_r;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant ((pi_approx) == 3142 && (scaled_r) == (r) * 2 * (pi_approx));
        loop invariant ((result) * 1000 + (temp) == (scaled_r) && (temp) >= 0);
        loop invariant temp <= (2 * (r) * 3142);
        loop invariant result <= (2 * (r) * 3142 / 1000);
        loop assigns result, temp;
        loop variant temp;
    */
    while (temp >= 1000)
    {
        //@ assert result * 1000 + temp == scaled_r;
        temp -= 1000;
        result += 1;
        //@ assert result * 1000 + temp == scaled_r;
    }
    
    //@ assert result * 1000 + temp == scaled_r;
    //@ assert result == 2 * r * 3142 / 1000;
    
    return result;
}

int main()
{
    return 0;
}
