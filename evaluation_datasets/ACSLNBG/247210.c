#include <stdbool.h>


bool func(int n)
{
    int n_abs;
    int div;
    int temp;
    int mod_res;

    //@ assert (10 <= (n) && (n) <= 99);
    
    n_abs = n;
    if (n < 0)
    {
        n_abs = -n;
    }
    
    //@ assert (10 <= (n_abs) && (n_abs) <= 99);
    
    div = 0;
    temp = n_abs;
    
    
    while (temp >= 10)
    {
        //@ assert temp >= 10;
        temp -= 10;
        div += 1;
    }
    
    //@ assert n_abs == temp + 10 * div;
    
    mod_res = n_abs;
    
    
    while (mod_res >= 10)
    {
        //@ assert mod_res >= 10;
        mod_res -= 10;
    }
    
    //@ assert mod_res == ((n_abs) % 10);
    //@ assert div == ((n_abs) / 10);
    
    return div == 9 || mod_res == 9;
}
