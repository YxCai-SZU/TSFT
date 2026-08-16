#include <stdbool.h>
#include <stddef.h>

/*@
    requires n >= 2 && n <= 100000;
    requires \valid(a + (0 .. n-1));
    requires ((n) >= 2 && (n) <= 100000 &&
      \forall integer j; 0 <= j < (n) ==> ((a)[j] == 1 || (a)[j] == 2 || (a)[j] == 3));
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> \result <= (int)n;
*/
int func(size_t n, int* a)
{
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant count1 >= 0 && count2 >= 0 && count3 >= 0;
        loop invariant count1 <= (int)i && count2 <= (int)i && count3 <= (int)i;
        loop invariant count1 + count2 + count3 <= (int)i;
        loop invariant ((n) >= 2 && (n) <= 100000 &&
      \forall integer j; 0 <= j < (n) ==> ((a)[j] == 1 || (a)[j] == 2 || (a)[j] == 3));
        loop assigns i, count1, count2, count3;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        //@ assert a[i] == 1 || a[i] == 2 || a[i] == 3;
        if (a[i] == 1) {
            count1++;
        } else if (a[i] == 2) {
            count2++;
        } else if (a[i] == 3) {
            count3++;
        }
        i++;
        //@ assert ((i) >= 0 && (i) <= (n) &&       (count1) >= 0 && (count2) >= 0 && (count3) >= 0 &&       (count1) <= (i) && (count2) <= (i) && (count3) <= (i) &&       (count1) + (count2) + (count3) <= (i));
    }

    int ans = 0;
    if (count1 > 0) {
        ans++;
    }
    if (count2 > 0) {
        ans++;
    }
    if (count3 > 0) {
        ans++;
    }

    //@ assert ans >= 0;
    //@ assert ans <= 3;
    //@ assert ans <= (int)n;

    if (ans == 3) {
        return 3;
    } else {
        return -1;
    }
}
