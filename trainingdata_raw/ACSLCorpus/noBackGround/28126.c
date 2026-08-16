#include <stdbool.h>
#include <stdint.h>

/*@
    requires
        (\exists integer i; 0 <= i && (m)[i] == (k1)) &&
        (\exists integer i; 0 <= i && (m)[i] == (k2)) &&
        (\exists integer i; 0 <= i && (m)[i] == (k3));
    ensures
        \forall integer k; (k == k1 || k == k2 || k == k3) ==> (\exists integer i; 0 <= i && (m)[i] == (k));
*/
void contains_all_three(int *m, uint32_t k1, uint32_t k2, uint32_t k3)
{
    //@ assert (\exists integer i; 0 <= i && (m)[i] == (k1));
    //@ assert (\exists integer i; 0 <= i && (m)[i] == (k2));
    //@ assert (\exists integer i; 0 <= i && (m)[i] == (k3));
}
