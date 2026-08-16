#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires 1 <= c <= 10000;
    requires 1 <= d <= 10000;
    ensures \result == 1 <==> (((((a)) > ((c)) ==> ((a)) - ((c)) <= ((d))) && (((a)) <= ((c)) ==> ((c)) - ((a)) <= ((d)))) || ((((b)) > ((c)) ==> ((b)) - ((c)) <= ((d)) + ((d))) && (((b)) <= ((c)) ==> ((c)) - ((b)) <= ((d)) + ((d)))));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int diff;
    bool result;

    diff = (a > c) ? (a - c) : (c - a);
    if (diff <= d)
    {
        result = true;
        //@ assert (((a) > (c) ==> (a) - (c) <= (d)) && ((a) <= (c) ==> (c) - (a) <= (d)));
        return result;
    }
    else
    {
        diff = (b > c) ? (b - c) : (c - b);
        if (diff <= d + d)
        {
            result = true;
            //@ assert (((b) > (c) ==> (b) - (c) <= (d) + (d)) && ((b) <= (c) ==> (c) - (b) <= (d) + (d)));
            return result;
        }
        else
        {
            result = false;
            //@ assert !(((((a)) > ((c)) ==> ((a)) - ((c)) <= ((d))) && (((a)) <= ((c)) ==> ((c)) - ((a)) <= ((d)))) || ((((b)) > ((c)) ==> ((b)) - ((c)) <= ((d)) + ((d))) && (((b)) <= ((c)) ==> ((c)) - ((b)) <= ((d)) + ((d)))));
            return result;
        }
    }
}
