#include <stdbool.h>

/*@
    requires \valid(a + (0..4));
    requires ((5) == 5 &&
    \forall integer i; 0 <= i < (5) ==> 0 <= (a)[i] && (a)[i] <= 123 &&
    (a)[0] < (a)[1] && (a)[1] < (a)[2] && (a)[2] < (a)[3] && (a)[3] < (a)[4] && (a)[4] <= 123);
    requires 0 <= k && k <= 123;
    ensures \result == true <==> (a[4] - a[0] <= k);
*/
bool func(int *a, int k) {
    int i;
    bool f;
    
    i = 1;
    f = true;
    
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant ((5) == 5 &&
    \forall integer i; 0 <= i < (5) ==> 0 <= (a)[i] && (a)[i] <= 123 &&
    (a)[0] < (a)[1] && (a)[1] < (a)[2] && (a)[2] < (a)[3] && (a)[3] < (a)[4] && (a)[4] <= 123);
        loop invariant 0 <= k && k <= 123;
        loop invariant f == true <==> ((i) > 1 ==> ((a)[(i)-1] - (a)[0] <= (k)));
        loop assigns i, f;
    */
    while (i < 5) {
        //@ assert ((5) == 5 &&     \forall integer i; 0 <= i < (5) ==> 0 <= (a)[i] && (a)[i] <= 123 &&     (a)[0] < (a)[1] && (a)[1] < (a)[2] && (a)[2] < (a)[3] && (a)[3] < (a)[4] && (a)[4] <= 123);
        if ((a[i] - a[0]) > k) {
            f = false;
        }
        i++;
    }
    
    //@ assert f == true <==> (a[4] - a[0] <= k);
    return f;
}
