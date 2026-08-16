#include <limits.h>

/*@
    requires (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
    requires a <= b && c <= d;
    ensures \result == b*d || \result == a*d || \result == b*c || \result == a*c;
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    long max_val;
    long temp_val;

    //@ assert (-1000000000 <= (a) <= 1000000000);
    //@ assert (-1000000000 <= (b) <= 1000000000);
    //@ assert (-1000000000 <= (c) <= 1000000000);
    //@ assert (-1000000000 <= (d) <= 1000000000);

    //@ assert (-1000000000000000000 <= (a) * (c) <= 1000000000000000000);
    max_val = a * c;

    //@ assert (-1000000000000000000 <= (a) * (d) <= 1000000000000000000);
    temp_val = a * d;
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    //@ assert (-1000000000000000000 <= (b) * (c) <= 1000000000000000000);
    temp_val = b * c;
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    //@ assert (-1000000000000000000 <= (b) * (d) <= 1000000000000000000);
    temp_val = b * d;
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    //@ assert max_val == (((a*d) > (a*c) ? (a*d) : (a*c)) > ((b*c) > ((a*d) > (a*c) ? (a*d) : (a*c)) ? (b*c) : ((a*d) > (a*c) ? (a*d) : (a*c))) ?         ((a*d) > (a*c) ? (a*d) : (a*c)) :         ((b*d) > (((a*d) > (a*c) ? (a*d) : (a*c)) > ((b*c) > ((a*d) > (a*c) ? (a*d) : (a*c)) ? (b*c) : ((a*d) > (a*c) ? (a*d) : (a*c))) ?                ((a*d) > (a*c) ? (a*d) : (a*c)) :                ((b*c) > ((a*d) > (a*c) ? (a*d) : (a*c)) ? (b*c) : ((a*d) > (a*c) ? (a*d) : (a*c))))) ?         (b*d) :         (((a*d) > (a*c) ? (a*d) : (a*c)) > ((b*c) > ((a*d) > (a*c) ? (a*d) : (a*c)) ? (b*c) : ((a*d) > (a*c) ? (a*d) : (a*c))) ?          ((a*d) > (a*c) ? (a*d) : (a*c)) :          ((b*c) > ((a*d) > (a*c) ? (a*d) : (a*c)) ? (b*c) : ((a*d) > (a*c) ? (a*d) : (a*c)))));
    //@ assert max_val == b*d || max_val == a*d || max_val == b*c || max_val == a*c;
    return max_val;
}
