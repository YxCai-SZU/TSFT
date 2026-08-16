#include <stdbool.h>

/*@
  requires \valid(a + (0..len-1));
  requires (1 <= (len) <= 10 &&
      \forall integer i; 0 <= i < (len) ==> 1 <= (a)[i] <= 1000000000);
  ensures \result == 1 <==> (\forall integer i; 0 <= i < (len) / 2 ==> (a)[i] == (a)[(len) - i - 1]);
*/
bool is_palindrome(int *a, int len) {
    int i = 0;
    /*@
      loop invariant 0 <= i <= len / 2;
      loop invariant \forall integer j; 0 <= j < i ==> a[j] == a[len - j - 1];
      loop assigns i;
      loop variant len / 2 - i;
    */
    while (i < len / 2) {
        //@ assert 0 <= i < len / 2;
        if (a[i] != a[len - i - 1]) {
            return false;
        }
        i++;
    }
    return true;
}
