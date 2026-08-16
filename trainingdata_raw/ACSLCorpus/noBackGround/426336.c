#include <stdbool.h>

/*@
    requires ((l) >= 0 && (l) <= 1290);
    ensures \result == ((l) == 0 ? 0 : (l) * (l) * (l));
    ensures \result >= 0;
*/
int compute_volume_cube(int l) {
    int result;
    //@ assert ((l) >= 0 && (l) <= 1290);
    
    if (l == 0) {
        result = 0;
    } else {
        //@ assert l * l * l >= 0;
        result = l * l * l;
    }
    
    //@ assert result == ((l) == 0 ? 0 : (l) * (l) * (l));
    //@ assert result >= 0;
    return result;
}

int main() {
    return 0;
}
