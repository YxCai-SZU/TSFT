#include <stdbool.h>

/*@ requires ((n) > 0 && (n) <= 100);
    requires (\valid((a) + (0 .. (n)-1)));
    requires (\forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 1000);
    ensures \result == true <==> (\forall integer i; 0 <= i < (n) && (a)[i] % 2 == 0 ==> 
        (a)[i] % 3 == 0 || (a)[i] % 5 == 0);
 */
bool func(int n, int *a) {
    int i = 0;
    int an = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant (\valid((a) + (0 .. (n)-1)));
        loop invariant (\forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 1000);
        loop invariant \forall integer j; 0 <= j < i && a[j] % 2 == 0 ==> 
                      a[j] % 3 == 0 || a[j] % 5 == 0;
        loop assigns i, an;
        loop variant n - i;
     */
    while (i < n) {
        an = a[i];
        if (an % 2 != 0) {
            i += 1;
            continue;
        }
        //@ assert an % 2 == 0;
        if (an % 3 == 0 || an % 5 == 0) {
            i += 1;
            continue;
        } else {
            //@ assert an % 2 == 0 && an % 3 != 0 && an % 5 != 0;
            return false;
        }
    }
    //@ assert \forall integer i; 0 <= i < n && a[i] % 2 == 0 ==> a[i] % 3 == 0 || a[i] % 5 == 0;
    return true;
}
