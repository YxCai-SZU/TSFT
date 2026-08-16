#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires 1 <= c <= 10000;
    requires 1 <= d <= 10000;
    ensures \result == true <==> (((((a)) > ((c)) ? ((a)) - ((c)) : ((c)) - ((a))) <= ((d))) || (((((a)) > ((b)) ? ((a)) - ((b)) : ((b)) - ((a))) <= ((d))) && ((((b)) > ((c)) ? ((b)) - ((c)) : ((c)) - ((b))) <= ((d)))));
*/
bool func(int a, int b, int c, int d)
{
    int diff_ac;
    int diff_ab;
    int diff_bc;
    bool result;

    //@ assert 1 <= a <= 10000;
    //@ assert 1 <= b <= 10000;
    //@ assert 1 <= c <= 10000;
    //@ assert 1 <= d <= 10000;

    if (a > c) {
        diff_ac = a - c;
    } else {
        diff_ac = c - a;
    }

    if (a > b) {
        diff_ab = a - b;
    } else {
        diff_ab = b - a;
    }

    if (b > c) {
        diff_bc = b - c;
    } else {
        diff_bc = c - b;
    }

    //@ assert diff_ac == (a > c ? a - c : c - a);
    //@ assert diff_ab == (a > b ? a - b : b - a);
    //@ assert diff_bc == (b > c ? b - c : c - b);

    if (diff_ac <= d) {
        result = true;
        //@ assert (((a) > (c) ? (a) - (c) : (c) - (a)) <= (d));
        //@ assert (((((a)) > ((c)) ? ((a)) - ((c)) : ((c)) - ((a))) <= ((d))) || (((((a)) > ((b)) ? ((a)) - ((b)) : ((b)) - ((a))) <= ((d))) && ((((b)) > ((c)) ? ((b)) - ((c)) : ((c)) - ((b))) <= ((d)))));
    } else if (diff_ab <= d && diff_bc <= d) {
        result = true;
        //@ assert (((a) > (b) ? (a) - (b) : (b) - (a)) <= (d));
        //@ assert (((b) > (c) ? (b) - (c) : (c) - (b)) <= (d));
        //@ assert (((((a)) > ((c)) ? ((a)) - ((c)) : ((c)) - ((a))) <= ((d))) || (((((a)) > ((b)) ? ((a)) - ((b)) : ((b)) - ((a))) <= ((d))) && ((((b)) > ((c)) ? ((b)) - ((c)) : ((c)) - ((b))) <= ((d)))));
    } else {
        result = false;
        //@ assert !(((a) > (c) ? (a) - (c) : (c) - (a)) <= (d));
        //@ assert !((((a) > (b) ? (a) - (b) : (b) - (a)) <= (d)) && (((b) > (c) ? (b) - (c) : (c) - (b)) <= (d)));
        //@ assert !(((((a)) > ((c)) ? ((a)) - ((c)) : ((c)) - ((a))) <= ((d))) || (((((a)) > ((b)) ? ((a)) - ((b)) : ((b)) - ((a))) <= ((d))) && ((((b)) > ((c)) ? ((b)) - ((c)) : ((c)) - ((b))) <= ((d)))));
    }

    return result;
}
