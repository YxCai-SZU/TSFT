#include <stdbool.h>

/*@
    requires 1 <= x && x <= 100;
    requires 1 <= y && y <= 100;
    requires 1 <= z && z <= 100;
    ensures \result == ((x * (y + z)) == (x * y + x * z));
    assigns \nothing;
*/
bool check_distributive(int x, int y, int z) {
    //@ assert (1 <= (x) && (x) <= 100);
    //@ assert (1 <= (y) && (y) <= 100);
    //@ assert (1 <= (z) && (z) <= 100);
    //@ assert ((x) * ((y) + (z))) <= 100 * 200;
    //@ assert ((x) * (y) + (x) * (z)) <= 100 * 200;
    
    return (x * (y + z)) == (x * y + x * z);
}
