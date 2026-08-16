#include <stdbool.h>
#include <stddef.h>

/*@
    requires (1 <= (n) <= 100000 && 1 <= (m) <= 10000);
    requires (\forall integer i; 0 <= i < (m) ==> 1 <= (arr)[i] <= 10000);
    requires (\forall integer i; 0 <= i < (m) ==> 1 <= (arr1)[i] <= 10000);
    requires \valid(arr + (0 .. m-1));
    requires \valid(arr1 + (0 .. m-1));
    ensures 0 <= \result <= n;
*/
int func(int n, int m, int *arr, int *arr1) {
    int v = 0;
    size_t index = 0;

    /*@
        loop invariant 0 <= index <= m;
        loop invariant 0 <= v <= index;
        loop invariant (\forall integer i; 0 <= i < (m) ==> 1 <= (arr)[i] <= 10000);
        loop invariant (\forall integer i; 0 <= i < (m) ==> 1 <= (arr1)[i] <= 10000);
        loop invariant (1 <= (n) <= 100000 && 1 <= (m) <= 10000);
        loop assigns v, index;
        loop variant m - index;
    */
    while (index < (size_t)m) {
        int a = arr[index];
        int b = arr1[index];

        if ((a & 1) == 1) {
            v += 1;
        } else if ((b & 1) == 1) {
            v += 1;
        }

        index += 1;
    }

    int ans = ((v & 1) == 0) ? 0 : 1;
    //@ assert 0 <= ans <= 1;
    //@ assert 0 <= ans <= n;
    return ans;
}
