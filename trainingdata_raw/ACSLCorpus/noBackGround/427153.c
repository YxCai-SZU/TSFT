#include <stdbool.h>
/*@
    requires ((N) >= 1 && (N) <= 100 &&
        \valid((a) + (0 .. (N)-1)) &&
        \forall integer i; 0 <= i < (N) ==> (a)[i] >= 1 && (a)[i] <= 1000);
    ensures ((\result) == true <==>
        (\forall integer i; 0 <= i < (N) && (a)[i] % 2 == 0 ==>
            (a)[i] % 3 == 0 || (a)[i] % 5 == 0));
    assigns \nothing;
*/
bool func(int N, int *a) {
    bool flag = true;
    int i = 0;
    /*@
        loop invariant 0 <= i <= N;
        loop invariant ((N) >= 1 && (N) <= 100 &&
        \valid((a) + (0 .. (N)-1)) &&
        \forall integer i; 0 <= i < (N) ==> (a)[i] >= 1 && (a)[i] <= 1000);
        loop invariant flag == true <==>
            (\forall integer j; 0 <= j < i && a[j] % 2 == 0 ==>
                a[j] % 3 == 0 || a[j] % 5 == 0);
        loop assigns i, flag;
        loop variant N - i;
    */
    while (i < N) {
        int ai = a[i];
        if (ai % 2 == 0) {
            if (!(ai % 3 == 0 || ai % 5 == 0)) {
                flag = false;
            }
        }
        i++;
    }
    return flag;
}
