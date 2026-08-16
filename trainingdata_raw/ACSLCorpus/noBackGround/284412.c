#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid(arr + (0 .. len-1));
  requires ((len) >= 3 && (len) <= 3000 &&
      \forall integer i; 0 <= i < (len) ==> (((arr)[i]) == 1 || ((arr)[i]) == 2 || ((arr)[i]) == 3 || ((arr)[i]) == 4 || ((arr)[i]) == 5));
  ensures \result >= 0 && \result <= 10;
  assigns \nothing;
*/
int func(int *arr, size_t len) {
    int p1 = 0;
    int p2 = 0;
    int p3 = 0;
    int p4 = 0;
    int p5 = 0;
    size_t index = 0;

    /*@
      loop invariant 0 <= index <= len;
      loop invariant 0 <= p1 <= (int)index;
      loop invariant 0 <= p2 <= (int)index;
      loop invariant 0 <= p3 <= (int)index;
      loop invariant 0 <= p4 <= (int)index;
      loop invariant 0 <= p5 <= (int)index;
      loop invariant ((len) >= 3 && (len) <= 3000 &&
      \forall integer i; 0 <= i < (len) ==> (((arr)[i]) == 1 || ((arr)[i]) == 2 || ((arr)[i]) == 3 || ((arr)[i]) == 4 || ((arr)[i]) == 5));
      loop assigns index, p1, p2, p3, p4, p5;
      loop variant len - index;
    */
    while (index < len) {
        int value = arr[index];
        //@ assert ((value) == 1 || (value) == 2 || (value) == 3 || (value) == 4 || (value) == 5);
        
        if (value == 1) {
            p1 += 1;
        } else if (value == 2) {
            p2 += 1;
        } else if (value == 3) {
            p3 += 1;
        } else if (value == 4) {
            p4 += 1;
        } else if (value == 5) {
            p5 += 1;
        }
        index += 1;
    }

    int ans;
    if (p3 >= 8) {
        ans = 3;
    } else if (p2 >= 8) {
        ans = 2;
    } else if (p4 >= 8) {
        ans = 4;
    } else if (p5 >= 6) {
        ans = 5;
    } else if (p1 >= 5 && p5 >= 1) {
        ans = 1;
    } else if (p2 >= 1 && p4 >= 5) {
        ans = 4;
    } else {
        ans = 0;
    }

    //@ assert ans >= 0 && ans <= 10;
    return ans;
}
