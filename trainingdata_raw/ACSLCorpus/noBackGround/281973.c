#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

/*@
  requires ((1 <= (n) <= 100000) &&
      (0 <= (k) <= (n)) &&
      (1 <= (s) <= 1000000000));
  requires (\valid((a) + (0 .. (n)-1)) &&
      (\forall integer j; 0 <= j < (n) ==> 1 <= (a)[j] <= 1000000000));
  requires \valid(res + (0 .. n-1));
  assigns res[0 .. n-1];
  ensures \forall integer i; 0 <= i < n ==> 1 <= res[i] <= 1000000000;
  ensures (\forall integer j; 0 <= j < (k) ==> (res)[j] == (s));
*/
void func(size_t n, size_t k, int64_t s, const int64_t *a, int64_t *res) {
    size_t i = 0;
    
    //@ assert 0 <= i <= k;
    //@ assert \forall integer j; 0 <= j < i ==> res[j] == s;
    
    /*@
      loop invariant 0 <= i <= k;
      loop invariant \forall integer j; 0 <= j < i ==> res[j] == s;
      loop assigns i, res[0 .. k-1];
      loop variant k - i;
    */
    while (i < k) {
        //@ assert i < k;
        res[i] = s;
        i++;
        //@ assert \forall integer j; 0 <= j < i ==> res[j] == s;
    }
    
    //@ assert i == k;
    //@ assert (\forall integer j; 0 <= j < (k) ==> (res)[j] == (s));
    
    /*@
      loop invariant k <= i <= n;
      loop invariant (\forall integer j; 0 <= j < (k) ==> (res)[j] == (s));
      loop invariant \forall integer j; k <= j < i ==> 1 <= res[j] <= 1000000000;
      loop assigns i, res[k .. n-1];
      loop variant n - i;
    */
    while (i < n) {
        //@ assert i < n;
        if (s == 1000000000) {
            res[i] = 1;
        } else {
            res[i] = 1000000000;
        }
        i++;
        //@ assert \forall integer j; k <= j < i ==> 1 <= res[j] <= 1000000000;
    }
    
    //@ assert i == n;
    //@ assert (\forall integer j; 0 <= j < (k) ==> (res)[j] == (s));
    //@ assert (\forall integer j; (k) <= j < (n) ==> 1 <= (res)[j] <= 1000000000);
    //@ assert \forall integer j; 0 <= j < n ==> 1 <= res[j] <= 1000000000;
}
