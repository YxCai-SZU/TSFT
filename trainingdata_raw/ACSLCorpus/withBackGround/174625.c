#include <stdbool.h>

/*@
    predicate is_valid_input(integer l) = l >= 0 && l <= 1;

    logic integer volume_cube_spec(integer l) = l * l * l;

    lemma volume_cube_lemma:
        \forall integer l; is_valid_input(l) ==> volume_cube_spec(l) >= 0 && volume_cube_spec(l) <= 1;
*/

/*@
    requires is_valid_input(l);
    ensures \result == volume_cube_spec(l);
    assigns \nothing;
*/
int volume_cube(int l) {
    // Variable declarations at top of scope
    int result;

    //@ assert l >= 0 && l <= 1;
    
    //@ assert l * l >= 0 && l * l <= 1;
    
    //@ assert l * l * l >= 0 && l * l * l <= 1;
    
    result = l * l * l;
    return result;
}

#ifdef TEST
#include <assert.h>

int main() {
    // Variable declarations at top of scope
    int result1;
    int result2;
    int result3;
    
    result1 = volume_cube(0);
    assert(result1 == 0);
    
    result2 = volume_cube(1);
    assert(result2 == 1);
    
    result3 = volume_cube(0);
    assert(result3 == 0);
    
    return 0;
}
#endif
