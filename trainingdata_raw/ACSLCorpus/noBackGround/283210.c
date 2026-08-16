#include <stdbool.h>

/*@
  requires \valid_read(a + (0..2));
  requires ((3) == 3 &&
      \forall integer i; 0 <= i < (3) ==> 1 <= (a)[i] <= 13);
  ensures \result == 1 <==> ((a)[1] + (a)[2] > (a)[0] &&
      (a)[0] + (a)[2] > (a)[1] &&
      (a)[0] + (a)[1] > (a)[2]);
*/
bool check_values(const int* a) {
    int array[3];
    int i = 0;
    
    /*@
      loop invariant 0 <= i <= 3;
      loop invariant \forall integer j; 0 <= j < i ==> array[j] == a[j];
      loop assigns i, array[0..2];
      loop variant 3 - i;
    */
    while (i < 3) {
        array[i] = a[i];
        i = i + 1;
    }
    
    //@ assert \forall integer j; 0 <= j < 3 ==> array[j] == a[j];
    
    return (array[1] + array[2] > array[0]) && 
           (array[0] + array[2] > array[1]) && 
           (array[0] + array[1] > array[2]);
}
