#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (k) && (k) <= 100);
    ensures \result == ((((n) - 1) / 2 + 1) <= k);
*/
bool func(unsigned int n, unsigned int k)
{
    // Variable declarations at top of scope
    bool result;
    unsigned int temp1;
    unsigned int temp2;
    unsigned int temp3;

    //@ assert n >= 1 && n <= 100;
    //@ assert k >= 1 && k <= 100;

    temp1 = n - 1;
    //@ assert temp1 >= 0 && temp1 <= 99;

    temp2 = temp1 / 2;
    //@ assert temp2 >= 0 && temp2 <= 49;

    temp3 = temp2 + 1;
    //@ assert temp3 >= 1 && temp3 <= 50;

    if (temp3 <= k) {
        //@ assert temp3 <= k;
        result = true;
    } else {
        //@ assert !(temp3 <= k);
        result = false;
    }

    //@ assert result == (temp3 <= k);
    return result;
}
