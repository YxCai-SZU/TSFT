#include <stdbool.h>

/*@
    requires (10 <= (n) <= 99);
    ensures \result == (((n) % 10) == 9 || (((n) / 10) % 10) == 9);
    assigns \nothing;
*/
bool func(int n)
{
    int n_abs;
    int div;
    int temp;

    //@ assert (10 <= (n) <= 99);
    
    n_abs = n;
    if (n < 0)
    {
        n_abs = -n;
    }
    
    //@ assert (10 <= (n_abs) <= 99);
    //@ assert n_abs == (((n) < 0) ? -(n) : (n));
    
    div = 0;
    temp = n_abs;
    
    /*@
        loop invariant 0 <= temp <= n_abs;
        loop invariant 0 <= div <= n_abs / 10;
        loop invariant temp + div * 10 == n_abs;
        loop assigns temp, div;
    */
    while (temp >= 10)
    {
        //@ assert temp >= 10;
        temp -= 10;
        div += 1;
        //@ assert temp + div * 10 == n_abs;
    }
    
    //@ assert temp < 10;
    //@ assert temp + div * 10 == n_abs;
    
    int ones_digit_val = n_abs - div * 10;
    int tens_digit_val = div;
    
    //@ assert ones_digit_val == ((n_abs) % 10);
    //@ assert tens_digit_val == (((n_abs) / 10) % 10);
    //@ assert ones_digit_val == ((n) % 10);
    //@ assert tens_digit_val == (((n) / 10) % 10);
    
    return (ones_digit_val == 9) || (tens_digit_val == 9);
}
