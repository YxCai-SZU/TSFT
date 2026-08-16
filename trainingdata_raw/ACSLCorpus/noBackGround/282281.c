#include <stdbool.h>

/*@
    requires (1 <= (x) && (x) <= 100000);
    ensures \result == (x >= 2000 || (100 * (x / 100) <= x && x <= 105 * (x / 100)));
*/
bool func(long x) {
    long n = 0;
    long temp_x = x;
    const long hundred = 100;
    
    //@ ghost long initial_x = x;
    
    /*@
        loop invariant (1 <= (initial_x) && (initial_x) <= 100000);
        loop invariant 0 <= n;
        loop invariant n <= initial_x / hundred;
        loop invariant temp_x == ((initial_x) - 100 * (n));
        loop invariant ((initial_x) - 100 * (n)) >= 0;
        loop assigns n, temp_x;
    */
    while (temp_x >= hundred) {
        //@ assert temp_x == ((initial_x) - 100 * (n));
        temp_x -= hundred;
        n += 1;
        //@ assert temp_x == ((initial_x) - 100 * (n));
    }
    
    long nx100 = n * hundred;
    
    //@ assert 100 * (initial_x / 100) == nx100;
    //@ assert 105 * (initial_x / 100) == 105 * n;
    
    if (x >= 2000 || (100 * n <= x && x <= 105 * n)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    return 0;
}
