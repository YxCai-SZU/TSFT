#include <stdint.h>

/*@
    logic integer volume_cube(integer x) =
        x * x * x;

    lemma volume_cube_nonneg:
        \forall integer x;
            0 <= x <= 0x10000000 ==>
            volume_cube(x) >= 0;
*/

/*@
    requires 0 <= x <= 0x10000000;
    ensures \result == volume_cube(x);
    ensures \result >= 0;
    assigns \nothing;
*/
int64_t compute_volume_cube(int64_t x) {
    int64_t result;
    
    //@ assert 0 <= x <= 0x10000000;
    //@ assert volume_cube(x) >= 0;
    
    result = x * x * x;
    
    //@ assert result == volume_cube(x);
    //@ assert result >= 0;
    
    return result;
}

int main() {
    return 0;
}
