#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid_read(a + (0..2));
  requires \forall integer i; 0 <= i < 3 ==> 1 <= a[i] <= 13;
  ensures \result == 1 <==> ((a[0]) + (a[1]) > (a[2]) && (a[0]) + (a[2]) > (a[1]) && (a[1]) + (a[2]) > (a[0]));
*/
bool func(const int a[3]) {
    int v[3];
    int i = 0;
    
    /*@
      loop invariant 0 <= i <= 3;
      loop invariant \forall integer j; 0 <= j < i ==> v[j] == a[j];
      loop assigns i, v[0..2];
      loop variant 3 - i;
    */
    while (i < 3) {
        v[i] = a[i];
        i++;
    }
    
    //@ assert v[0] == a[0] && v[1] == a[1] && v[2] == a[2];
    
    return (v[0] + v[1] > v[2]) && 
           (v[0] + v[2] > v[1]) && 
           (v[1] + v[2] > v[0]);
}
