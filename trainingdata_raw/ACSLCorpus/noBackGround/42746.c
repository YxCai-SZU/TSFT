#include <stdbool.h>
#include <stddef.h>

/*@
  requires (3 <= (n) && (n) <= 100 &&
      1 <= (a) && (a) < (b) && (b) < 20) && (\valid((p) + (0 .. (n)-1)) &&
      \forall integer k; 0 <= k < (n) ==> 1 <= (p)[k] && (p)[k] <= 20);
  ensures \result >= 0 && \result <= n;
*/
int func(int n, int a, int b, int *p)
{
    int count = 0;
    int p0 = 0;
    int p1 = 0;
    int p2 = 0;
    int i = 0;
    int pi = 0;
    int min_value = 0;

    //@ assert (0 <= (i) <= (n) &&       (p0) >= 0 && (p1) >= 0 && (p2) >= 0 &&       (p0) <= (i) && (p1) <= (i) && (p2) <= (i) &&       (\forall integer k; 0 <= k < (i) ==>           ((p)[k] <= (a) ==> (p0) > 0) &&          ((a) < (p)[k] && (p)[k] <= (b) ==> (p1) > 0) &&          ((p)[k] > (b) ==> (p2) > 0)) &&       (\forall integer k; (i) <= k < (n) ==> 1 <= (p)[k] && (p)[k] <= 20));
    
    /*@ loop invariant (0 <= (i) <= (n) &&
      (p0) >= 0 && (p1) >= 0 && (p2) >= 0 &&
      (p0) <= (i) && (p1) <= (i) && (p2) <= (i) &&
      (\forall integer k; 0 <= k < (i) ==> 
         ((p)[k] <= (a) ==> (p0) > 0) &&
         ((a) < (p)[k] && (p)[k] <= (b) ==> (p1) > 0) &&
         ((p)[k] > (b) ==> (p2) > 0)) &&
      (\forall integer k; (i) <= k < (n) ==> 1 <= (p)[k] && (p)[k] <= 20));
        loop assigns i, p0, p1, p2, pi;
        loop variant n - i;
    */
    while (i < n) {
        pi = p[i];
        
        if (pi <= a) {
            p0 = p0 + 1;
        } else if (pi <= b) {
            p1 = p1 + 1;
        } else {
            p2 = p2 + 1;
        }
        
        i = i + 1;
        //@ assert (0 <= (i) <= (n) &&       (p0) >= 0 && (p1) >= 0 && (p2) >= 0 &&       (p0) <= (i) && (p1) <= (i) && (p2) <= (i) &&       (\forall integer k; 0 <= k < (i) ==>           ((p)[k] <= (a) ==> (p0) > 0) &&          ((a) < (p)[k] && (p)[k] <= (b) ==> (p1) > 0) &&          ((p)[k] > (b) ==> (p2) > 0)) &&       (\forall integer k; (i) <= k < (n) ==> 1 <= (p)[k] && (p)[k] <= 20));
    }
    
    min_value = p0;
    
    if (p1 < min_value) {
        min_value = p1;
    }
    
    if (p2 < min_value) {
        min_value = p2;
    }
    
    //@ assert min_value >= 0;
    //@ assert min_value <= n;
    
    return min_value;
}
