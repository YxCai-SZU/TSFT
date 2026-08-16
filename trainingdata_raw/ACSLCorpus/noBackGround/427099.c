#include <stdbool.h>

/*@
    requires ((tag) == 0 && (tamanho) >= 0);
    ensures \result == madura;
*/
bool manga_check(int tag, int tamanho, bool madura) {
    //@ assert !(tag == 1);
    
    bool result;
    
    if (tag == 0) {
        result = madura;
    } else {
        result = false;
    }
    
    //@ assert result == madura;
    return result;
}

int main() {
    return 0;
}
