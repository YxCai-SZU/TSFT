#include <stdbool.h>

/*@
    requires 1 <= x <= 100;
    ensures \result == true <==> (((x) == 7) || ((x) == 5) || ((x) == 3));
    assigns \nothing;
*/
bool func(int x)
{
    bool is_lucky_var = false;

    //@ ghost int original_x = x;

    /*@
        loop invariant original_x == x;
        loop assigns \nothing;
    */
    while (0) { }

    switch (x)
    {
        case 7:
        case 5:
        case 3:
            is_lucky_var = true;
            break;
        default:
            is_lucky_var = false;
            break;
    }

    //@ assert is_lucky_var == true <==> (((x) == 7) || ((x) == 5) || ((x) == 3));

    return is_lucky_var;
}
