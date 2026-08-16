#include <stdbool.h>

/*@
    requires (1 <= (A) <= 3) && (1 <= (B) <= 3);
    ensures \result == (((A) * (B) * (B)) == 9);
*/
bool func(unsigned long long A, unsigned long long B)
{
    // Variable declarations at scope top
    bool result;

    //@ assert 1 <= A && A <= 3;
    //@ assert 1 <= B && B <= 3;
    //@ assert A * B <= 9;
    //@ assert A * B * B <= 81;

    if (A * B * B == 9) {
        //@ assert A * B * B == 9;
        result = true;
    } else {
        //@ assert A * B * B != 9;
        result = false;
    }

    return result;
}
