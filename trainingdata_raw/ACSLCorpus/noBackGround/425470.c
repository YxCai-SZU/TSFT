#include <stddef.h>
#include <stdbool.h>

/*@
  requires (2 <= (n) && (n) <= 20);
  requires \valid(aa + (0 .. n-1));
  requires \valid(bb + (0 .. n-1));
  requires \valid(cc + (0 .. n-2));
  requires (\forall integer i; 0 <= i < (n) ==> 1 <= (aa)[i] && (aa)[i] <= (n));
  requires (\forall integer i; 0 <= i < (n) ==> 1 <= (bb)[i] && (bb)[i] <= 50);
  requires (\forall integer i; 0 <= i < (n) - 1 ==> 1 <= (cc)[i] && (cc)[i] <= 50);
  ensures \result >= 0;
*/
int func(int n, int *aa, int *bb, int *cc)
{
    int ans = 0;
    int i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant ans >= 0;
      loop invariant ans <= i * 101;
      loop assigns i, ans;
    */
    while (i < n) {
        int a = aa[i];
        //@ assert 0 <= a - 1 && a - 1 < n;
        int b = bb[a - 1];
        ans += b;
        
        if (i > 0) {
            if (aa[i] == aa[i - 1] + 1) {
                //@ assert 0 <= aa[i - 1] - 1 && aa[i - 1] - 1 < n - 1;
                ans += cc[aa[i - 1] - 1];
            }
        }
        i += 1;
    }
    return ans;
}

int main() {
    return 0;
}
