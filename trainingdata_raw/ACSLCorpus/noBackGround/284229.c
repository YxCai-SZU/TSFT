#include <stdbool.h>

/*@
    requires \valid_read(v + (0..len-1));
    requires (\forall integer i, j; 0 <= i < j < (len) ==> (v)[i] < (v)[j]);
    requires len > 0;
    ensures \result == true ==> 
            \forall integer i, j; 0 <= i < j < len ==> v[i] < v[j];
    assigns \nothing;
*/
bool func(int *v, unsigned int len) {
    unsigned int i = 0;
    
    /*@
        loop invariant 0 <= i <= len-1;
        loop invariant \forall integer k; 0 <= k < i ==> v[k] < v[k+1];
        loop assigns i;
        loop variant len - i;
    */
    while (i < len - 1) {
        //@ assert i < len - 1;
        if (v[i] >= v[i + 1]) {
            return false;
        }
        i++;
    }
    return true;
}

int main() {
    return 0;
}
