#include <stdbool.h>
#include <stddef.h>

/*@ requires 1 <= n <= 100 && 0 <= m <= n;
    ensures \result == (n == m);
*/
bool func(int n, int m)
{
    //@ assert 1 <= n <= 100;
    //@ assert 0 <= m <= n;
    return n == m;
}

/*@ requires ((5) == 5 &&
      (\forall integer i; 0 <= i < (5) ==> (a)[i] == i+1 || (a)[i] == 0) &&
      (\exists integer i; 0 <= i < (5) && (a)[i] == 0));
    ensures 1 <= \result <= 5;
    ensures a[\result - 1] == 0;
*/
int func2(int *a)
{
    int i = 0;
    /*@ loop invariant 0 <= i <= 5;
        loop invariant ((5) == 5 &&
      (\forall integer i; 0 <= i < (5) ==> (a)[i] == i+1 || (a)[i] == 0) &&
      (\exists integer i; 0 <= i < (5) && (a)[i] == 0));
        loop invariant \forall integer k; 0 <= k < i ==> a[k] != 0;
        loop assigns i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        //@ assert a[i] == i+1 || a[i] == 0;
        if (a[i] == 0) {
            //@ assert a[i] == 0;
            //@ assert 0 <= i < 5;
            return i + 1;
        }
        //@ assert a[i] != 0;
        i++;
        //@ assert \forall integer k; 0 <= k < i ==> a[k] != 0;
    }
    //@ assert i == 5;
    //@ assert \forall integer k; 0 <= k < 5 ==> a[k] != 0;
    //@ assert \exists integer j; 0 <= j < 5 && a[j] == 0;
    return -1;
}
