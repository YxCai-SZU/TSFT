#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid_read(x + (0..len-1));
  requires \valid_read(y + (0..len-1));
  requires \valid_read(z + (0..len-1));
  requires len >= 0;
  requires \forall integer i; 0 <= i < len ==> (1 <= (x[i]) && (x[i]) <= 100000);
  requires \forall integer i; 0 <= i < len ==> (1 <= (y[i]) && (y[i]) <= 100000);
  requires \forall integer i; 0 <= i < len ==> (1 <= (z[i]) && (z[i]) <= 100000);
  assigns \nothing;
  ensures \result == true <==> 
          (\forall integer i; 0 <= i < len ==> ((x[i]) <= (z[i]) && (z[i]) <= (y[i])));
*/
bool func(const int *x, const int *y, const int *z, size_t len) {
    bool flag = true;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant flag == true <==> 
        (\forall integer j; 0 <= j < i ==> ((x[j]) <= (z[j]) && (z[j]) <= (y[j])));
      loop invariant \forall integer j; 0 <= j < len ==> (1 <= (x[j]) && (x[j]) <= 100000);
      loop invariant \forall integer j; 0 <= j < len ==> (1 <= (y[j]) && (y[j]) <= 100000);
      loop invariant \forall integer j; 0 <= j < len ==> (1 <= (z[j]) && (z[j]) <= 100000);
      loop assigns flag, i;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (!(x[i] <= z[i] && z[i] <= y[i])) {
            flag = false;
        }
        i++;
    }
    return flag;
}
