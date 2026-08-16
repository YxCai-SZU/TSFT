#include <stdbool.h>
#include <stddef.h>

/*@
    requires
        (2 <= (n) && (n) <= 20) &&
        (\valid((a) + (0 .. (n)-1)) &&
        (\forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= (n)) &&
        (\forall integer i, j; 0 <= i < j < (n) ==> (a)[i] != (a)[j])) &&
        (\valid((b) + (0 .. (n)-1)) &&
        (\forall integer i; 0 <= i < (n) ==> 1 <= (b)[i] && (b)[i] <= 50)) &&
        (\valid((c) + (0 .. (n)-2)) &&
        (\forall integer i; 0 <= i < (n)-1 ==> 1 <= (c)[i] && (c)[i] <= 50));
    ensures
        \result >= 0;
*/
int func(int n, int *a, int *b, int *c)
{
    int ret = 0;
    int i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant ret >= 0;
        loop invariant ret <= i * 100;
        loop assigns i, ret;
        loop variant n - i;
    @*/
    while (i < n) {
        int num = a[i];
        //@ assert 1 <= num && num <= n;
        ret = ret + b[num - 1];
        //@ assert ret >= 0;
        
        if (i + 1 < n && a[i + 1] == num + 1) {
            //@ assert 0 <= num-1 < n-1;
            ret = ret + c[num - 1];
            //@ assert ret >= 0;
        }
        
        i = i + 1;
        //@ assert ret <= i * 100;
    }
    
    //@ assert ret <= n * 100;
    return ret;
}
