#include <stdbool.h>
#include <stddef.h>

/*@ requires n > 0;
    requires \valid(v + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (v)[i] > 0);
    assigns \nothing;
    ensures \result == true <==> (n > 0 && (\forall integer i; 0 <= i < (n) ==> (v)[i] > 0));
*/
bool func(int n, int *v) {
    int i;
    i = 0;
    /*@ loop invariant 0 <= i <= n;
        loop invariant \forall integer j; 0 <= j < i ==> v[j] > 0;
        loop assigns i;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (v[i] <= 0) {
            return false;
        }
        i = i + 1;
    }
    return true;
}

int main() {
    int v[3];
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    //@ assert (\forall integer i; 0 <= i < (3) ==> ((int *)&v[0])[i] > 0);
    return 0;
}
