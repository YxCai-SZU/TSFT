#include <stdbool.h>

/*@
    requires \valid_read(a + (0..2));
    requires ((3) == 3 &&
    \forall integer i; 0 <= i < (3) ==> (1 <= (a)[i] && (a)[i] <= 9));
    ensures \result == 1 <==> ((a)[0] < (a)[1] && (a)[1] < (a)[2]);
    assigns \nothing;
*/
bool is_increasing(int *a) {
    int i;
    bool result;

    i = 0;
    /*@
        loop invariant 0 <= i <= 3;
        loop invariant \forall integer j; 0 <= j < i ==> (1 <= a[j] && a[j] <= 9);
        loop assigns i;
        loop variant 3 - i;
    */
    while (i < 3) {
        //@ assert 1 <= a[i] && a[i] <= 9;
        i++;
    }

    if (a[0] < a[1] && a[1] < a[2]) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == 1 <==> ((a)[0] < (a)[1] && (a)[1] < (a)[2]);
    return result;
}

int main() {
    return 0;
}
