#include <stdbool.h>

/*@ requires 10 <= n <= 99;
    ensures \result == (n % 10 == 9 || n >= 90);
    assigns \nothing;
*/
bool func(int n)
{
    int n_abs;
    int div = 0;
    int temp;
    
    //@ assert 10 <= n <= 99;
    
    if (n < 0) {
        n_abs = -n;
    } else {
        n_abs = n;
    }
    //@ assert (((n) >= 0 ==> (n_abs) == (n)) && ((n) < 0 ==> (n_abs) == -(n)));
    
    temp = n_abs;
    //@ assert temp == n_abs;
    
    /*@ loop invariant 0 <= temp <= n_abs;
        loop invariant temp == ((n_abs) - 10 * (div));
        loop invariant div >= 0;
        loop assigns temp, div;
    */
    while (temp >= 10) {
        int old_temp = temp;
        int old_div = div;
        
        //@ assert temp >= 10;
        temp -= 10;
        //@ assert temp == old_temp - 10;
        div += 1;
        //@ assert div == old_div + 1;
        //@ assert temp == ((n_abs) - 10 * (div));
    }
    
    int remainder = temp;
    //@ assert remainder == ((n_abs) - 10 * (div));
    
    if (remainder == 9 || div >= 9) {
        //@ assert remainder == 9 || div >= 9;
        return true;
    } else {
        //@ assert !(remainder == 9 || div >= 9);
        return false;
    }
}
