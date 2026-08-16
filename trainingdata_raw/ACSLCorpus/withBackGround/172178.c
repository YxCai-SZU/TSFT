#include <stdbool.h>

/*@
    predicate has_duplicate(int *a, integer len) =
        \exists integer i, j; 0 <= i < j < len && a[i] == a[j];

    predicate no_duplicate(int *a, integer len) =
        \forall integer i, j; 0 <= i < j < len ==> a[i] != a[j];
*/

/*@
    requires len >= 1;
    requires \valid(a + (0..len-1));
    assigns \nothing;
    ensures \result == true ==> has_duplicate(a, len);
    ensures \result == false ==> no_duplicate(a, len);
*/
bool test_duplicate(int *a, int len) {
    int i = 0;
    int j = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer ii, jj; 0 <= ii < i && ii < jj < len ==> a[ii] != a[jj];
        loop assigns i, j;
        loop variant len - i;
    */
    while (i < len) {
        j = i + 1;
        
        /*@
            loop invariant i + 1 <= j <= len;
            loop invariant \forall integer jj; i + 1 <= jj < j ==> a[jj] != a[i];
            loop assigns j;
            loop variant len - j;
        */
        while (j < len) {
            //@ assert 0 <= i < len && 0 <= j < len;
            if (a[i] == a[j]) {
                //@ assert has_duplicate(a, len);
                return true;
            }
            j++;
        }
        i++;
    }
    //@ assert no_duplicate(a, len);
    return false;
}

int main() {
    return 0;
}
