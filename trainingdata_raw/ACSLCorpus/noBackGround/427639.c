#include <stdbool.h>
#include <stddef.h>

/*@
  requires ((len) >= 0 && (len) < 1000 &&
    \valid((numbers) + (0 .. (len)-1)));
  assigns \nothing;
  ensures \result >= 0 ==> (0 <= (\result) < (len) && (numbers)[(\result)] == (target));
  ensures \result == -1 ==> (\forall integer i; 0 <= i < (len) ==> (numbers)[i] != (target));
*/
int find_index(int *numbers, int len, int target) {
    int i = 0;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> numbers[j] != target;
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        if (numbers[i] == target) {
            //@ assert (0 <= (i) < (len) && (numbers)[(i)] == (target));
            return i;
        }
        i++;
    }
    
    //@ assert (\forall integer i; 0 <= i < (len) ==> (numbers)[i] != (target));
    return -1;
}
