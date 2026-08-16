#include <stdbool.h>


bool func(int a)
{
    int b = 10;
    int c = 100;
    bool is_allowed = false;
    int temp_b;
    int b_mod_10;
    int temp_c;
    int c_mod_10;

    // First loop: compute b_mod_10
    temp_b = b;
    
    while (temp_b >= 10)
    {
        //@ assert temp_b >= 10;
        temp_b -= 10;
    }
    b_mod_10 = temp_b;

    // Second loop: compute c_mod_10
    temp_c = c;
    
    while (temp_c >= 10)
    {
        //@ assert temp_c >= 10;
        temp_c -= 10;
    }
    c_mod_10 = temp_c;

    //@ assert b_mod_10 == 0;
    //@ assert c_mod_10 == 0;
    
    if ((b_mod_10 == 3 || b_mod_10 == 5 || b_mod_10 == 7) &&
        (c_mod_10 == 3 || c_mod_10 == 5 || c_mod_10 == 7))
    {
        is_allowed = true;
    }

    if (a == 3 || a == 5 || a == 7)
    {
        return true;
    }
    else
    {
        return false;
    }
}
