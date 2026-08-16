#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    ensures ((n) % 2 == 0) ==> \result == 1;
    ensures ((n) % 2 != 0) ==> \result == 0;
*/
int func(int n)
{
    bool is_even_var;
    int result;

    //@ assert 1 <= n <= 100;
    
    if (n % 2 == 0) {
        is_even_var = true;
        //@ assert ((n) % 2 == 0);
    } else {
        is_even_var = false;
        //@ assert ((n) % 2 != 0);
    }

    if (is_even_var) {
        //@ assert n % 2 == 0;
        result = 1;
    } else {
        //@ assert n % 2 != 0;
        result = 0;
    }

    //@ assert ((n) % 2 == 0) ==> result == 1;
    //@ assert ((n) % 2 != 0) ==> result == 0;
    return result;
}
