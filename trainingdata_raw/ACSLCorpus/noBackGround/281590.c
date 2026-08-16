#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == (n >= 30);
    assigns \nothing;
*/
bool func(int n) {
    int i = 0;
    
    //@ ghost int original_n = n;
    
    /*@
        loop invariant (0 <= (i) && (i) <= (original_n));
        loop invariant (1 <= (original_n) && (original_n) <= 100);
        loop assigns i;
        loop variant ((original_n) - (i));
    */
    while (i < n) {
        //@ assert 0 <= i * i && i * i <= 10000;
        int _ = i * i;
        i = i + 1;
    }
    
    return n >= 30;
}

int main() {
    return 0;
}
