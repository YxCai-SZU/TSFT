#include <stdbool.h>

/*@
    requires (1 <= (a) <= (b) <= 1000 && 1 <= (k) <= 1000);
    ensures \result == ((a / k) * k == a || (a / k + 1) * k <= b);
*/
bool func(unsigned int k, unsigned int a, unsigned int b)
{
    unsigned int a_div_k;
    unsigned int a_div_k_plus_1;
    unsigned int a_div_k_times_k;
    unsigned int a_div_k_plus_1_times_k;

    //@ assert a / k <= 1000;
    //@ assert (a / k) * k <= 1000000;
    //@ assert a / k + 1 <= 1001;
    //@ assert (a / k + 1) * k <= 1001000;

    a_div_k = a / k;
    a_div_k_plus_1 = a_div_k + 1;
    a_div_k_times_k = a_div_k * k;
    a_div_k_plus_1_times_k = a_div_k_plus_1 * k;

    if (a_div_k_times_k == a)
    {
        //@ assert a_div_k_times_k == a;
        return true;
    }
    else if (a_div_k_plus_1_times_k <= b)
    {
        //@ assert a_div_k_plus_1_times_k <= b;
        return true;
    }
    else
    {
        //@ assert a_div_k_times_k != a && a_div_k_plus_1_times_k > b;
        return false;
    }
}
