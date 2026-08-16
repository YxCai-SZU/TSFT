#include <stdbool.h>

/*@
  requires \valid(v + (0..4));
  requires ((5) == 5 &&
      \forall integer i; 0 <= i < (5) ==> 0 <= (v)[i] && (v)[i] <= 123);
  requires 0 <= k <= 123;
  ensures \result == true <==>
    \forall integer i, j;
      0 <= i < 5 && 0 <= j < 5 && i != j ==> ((v)[(j)] - (v)[(i)] <= (k) || (v)[(i)] - (v)[(j)] <= (k));
*/
bool func(int *v, int k) {
    int i = 0;
    /*@
      loop invariant (0 <= (i) <= 5 &&
      ((5) == 5 &&
      \forall integer i; 0 <= i < (5) ==> 0 <= ((v))[i] && ((v))[i] <= 123) &&
      (k) >= 0 && (k) <= 123 &&
      \forall integer x, y;
        0 <= x < (i) && 0 <= y < 5 && x != y ==> (((v))[(y)] - ((v))[(x)] <= ((k)) || ((v))[(x)] - ((v))[(y)] <= ((k))));
      loop assigns i;
      loop variant 5 - i;
    */
    while (i < 5) {
        int a = v[i];
        int j = i + 1;
        /*@
          loop invariant ((i) < 5 &&
      0 <= (j) <= 5 &&
      ((5) == 5 &&
      \forall integer i; 0 <= i < (5) ==> 0 <= ((v))[i] && ((v))[i] <= 123) &&
      (k) >= 0 && (k) <= 123 &&
      \forall integer x, y;
        0 <= x < (i) && 0 <= y < 5 && x != y ==> (((v))[(y)] - ((v))[(x)] <= ((k)) || ((v))[(x)] - ((v))[(y)] <= ((k))) &&
      \forall integer x, y;
        0 <= x < (i) && (i) < y < (j) && x != y ==> (((v))[(y)] - ((v))[(x)] <= ((k)) || ((v))[(x)] - ((v))[(y)] <= ((k))));
          loop assigns j;
          loop variant 5 - j;
        */
        while (j < 5) {
            int b = v[j];
            //@ assert 0 <= b && b <= 123;
            //@ assert 0 <= a && a <= 123;
            int diff = (a > b) ? (a - b) : (b - a);
            //@ assert 0 <= diff && diff <= 123;
            if (diff > k) {
            }
            j += 1;
        }
        i += 1;
    }
    return true;
}
