#include <stdbool.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100);
    ensures ((\result) == ((c) >= (a) && (c) <= (b)));
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    bool is_a_less_than_or_equal_to_b;
    bool is_c_greater_than_or_equal_to_a;
    bool is_c_less_than_or_equal_to_b;
    bool result;

    //@ assert (-100 <= (a) <= 100);
    //@ assert (-100 <= (b) <= 100);
    //@ assert (-100 <= (c) <= 100);

    is_a_less_than_or_equal_to_b = (a <= b);
    is_c_greater_than_or_equal_to_a = (c >= a);
    is_c_less_than_or_equal_to_b = (c <= b);

    if (is_a_less_than_or_equal_to_b)
    {
        if (is_c_greater_than_or_equal_to_a && is_c_less_than_or_equal_to_b)
        {
            result = true;
            //@ assert ((result) == ((c) >= (a) && (c) <= (b)));
            return result;
        }
        else
        {
            //@ assert (-100 <= (a) <= 100);
            //@ assert (-100 <= (b) <= 100);
            //@ assert (-100 <= (c) <= 100);
            result = false;
            //@ assert ((result) == ((c) >= (a) && (c) <= (b)));
            return result;
        }
    }
    else
    {
        //@ assert (-100 <= (a) <= 100);
        //@ assert (-100 <= (b) <= 100);
        //@ assert (-100 <= (c) <= 100);
        result = false;
        //@ assert ((result) == ((c) >= (a) && (c) <= (b)));
        return result;
    }
}
