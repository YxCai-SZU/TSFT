#include <stdbool.h>

/*@
    requires (1 <= (N) && (N) <= 100000);
    ensures \result == (N >= 2000 || N % 200 == 0);
*/
bool func(unsigned int N) {
    // Variable declarations at scope top
    bool result;
    unsigned int n_mod_200;
    
    if (N >= 2000) {
        //@ assert N >= 2000;
        return true;
    }
    
    n_mod_200 = N;
    
    /*@
        loop invariant 1 <= N && N <= 100000;
        loop invariant n_mod_200 <= N;
        loop invariant n_mod_200 >= 0;
        loop invariant n_mod_200 == ((N) - 200 * (((N) - (n_mod_200)) / 200));
        loop assigns n_mod_200;
    */
    while (n_mod_200 >= 200) {
        //@ assert n_mod_200 >= 200;
        n_mod_200 -= 200;
    }
    
    result = (n_mod_200 == 0);
    //@ assert result == (N >= 2000 || N % 200 == 0);
    return result;
}
