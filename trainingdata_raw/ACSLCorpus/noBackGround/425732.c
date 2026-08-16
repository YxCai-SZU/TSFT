#include <stdbool.h>
#include <stddef.h>

/*@
  requires (2 <= (n) && (n) <= 20);
  requires \valid_read(a + (0..n-1));
  requires \valid_read(b + (0..n-1));
  requires \valid_read(c + (0..n-2));
  requires (\forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= (n));
  requires (\forall integer i, j; 0 <= i < j < (n) ==> (a)[i] != (a)[j]);
  requires (\forall integer i; 0 <= i < (n) ==> 1 <= (b)[i] && (b)[i] <= 50);
  requires (\forall integer i; 0 <= i < (n)-1 ==> 1 <= (c)[i] && (c)[i] <= 50);
  ensures \result >= 0;
*/
int func(int n, int *a, int *b, int *c) {
    int ret = 0;
    int i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant ret >= 0;
      loop invariant ret <= i * 100;
      loop assigns i, ret;
      loop variant n - i;
    */
    while (i < n) {
        int num = a[i];
        //@ assert 1 <= num && num <= n;
        ret = ret + b[num - 1];
        
        if (i + 1 < n && a[i + 1] == num + 1) {
            //@ assert i >= 0 && i < n - 1;
            //@ assert 1 <= num + 1 && num + 1 <= n;
            //@ assert num - 1 >= 0 && num - 1 < n - 1;
            ret = ret + c[num - 1];
        }
        
        i = i + 1;
    }
    
    return ret;
}
