#include <stdbool.h>
#include <stddef.h>

/*@
    requires n >= 1;
    requires \valid(arr + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (arr)[i] <= 1000);
    assigns \nothing;
    ensures \result == true <==> (\forall integer i; 0 <= i < (n) && (arr)[i] % 2 == 0 ==> 
            (arr)[i] % 3 == 0 || (arr)[i] % 5 == 0);
*/
bool func(size_t n, int *arr) {
    size_t i;
    int an;

    i = 0;
    /*@
        loop invariant 0 <= i <= n;
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (arr)[i] <= 1000);
        loop invariant \forall integer j; 0 <= j < i && arr[j] % 2 == 0 ==> 
            arr[j] % 3 == 0 || arr[j] % 5 == 0;
        loop assigns i, an;
        loop variant n - i;
    */
    while (i < n) {
        an = arr[i];
        if (an % 2 == 0) {
            //@ assert an % 2 == 0;
            if (an % 3 != 0 && an % 5 != 0) {
                //@ assert an % 3 != 0 && an % 5 != 0;
                return false;
            }
        }
        i++;
    }
    return true;
}
