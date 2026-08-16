#include <limits.h>

/*@
    requires (1 <= (n) <= 20) && (1 <= (m) <= 20);
    ensures ((1 <= (n) <= 9) && (1 <= (m) <= 9)) ==> \result == n * m;
    ensures (!(1 <= (n) <= 9) || !(1 <= (m) <= 9)) ==> \result == -1;
    assigns \nothing;
*/
int func(int n, int m)
{
    int max_value;
    int result;

    //@ assert (1 <= (n) <= 20) && (1 <= (m) <= 20);
    max_value = (n > m) ? n : m;
    
    //@ assert max_value == n || max_value == m;
    //@ assert (1 <= (max_value) <= 20);
    
    if (max_value <= 9)
    {
        //@ assert (1 <= (n) <= 9) && (1 <= (m) <= 9);
        //@ assert n * m <= 81;
        result = n * m;
    }
    else
    {
        result = -1;
    }
    
    return result;
}
