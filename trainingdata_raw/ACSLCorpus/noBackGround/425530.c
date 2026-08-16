#include <limits.h>

/*@
    requires (0 <= (l) && (l) <= 1290);
    ensures \result == ((l) * (l) * (l));
    assigns \nothing;
*/
int volume_cube(int l) {
    // Variable declarations at top
    int result;
    
    //@ assert 0 <= l;
    //@ assert l <= 1290;
    
    //@ assert l * l <= 1290 * 1290;
    //@ assert l * l * l <= 1290 * 1290 * 1290;
    
    result = l * l * l;
    
    //@ assert result == ((l) * (l) * (l));
    return result;
}

#ifdef TEST
#include <assert.h>
int main() {
    assert(volume_cube(5) == 125);
    return 0;
}
#endif
