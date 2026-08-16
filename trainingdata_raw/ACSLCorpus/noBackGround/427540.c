#include <stdbool.h>
#include <stddef.h>

/*@
  requires 1 <= n <= 100;
  requires 0 <= m <= n;
  ensures \result == (n == m);
*/
bool func(unsigned int n, unsigned int m) {
    bool result;
    result = (n == m);
    //@ assert result == (n == m);
    return result;
}

/*@
  requires \valid(arr + (0 .. len-1));
  requires len > 0;
  ensures \result == 1 <==> (\forall integer i; 0 <= i < (len) ==> (arr)[i] % 2 == 0);
*/
bool check_all_even(unsigned int *arr, size_t len) {
    size_t i;
    i = 0;
    /*@
      loop invariant 0 <= i <= len;
      loop invariant \forall integer j; 0 <= j < i ==> arr[j] % 2 == 0;
      loop assigns i;
      loop variant len - i;
    */
    while (i < len) {
        if (arr[i] % 2 != 0) {
            //@ assert !(\forall integer i; 0 <= i < (len) ==> (arr)[i] % 2 == 0);
            return false;
        }
        i = i + 1;
    }
    //@ assert (\forall integer i; 0 <= i < (len) ==> (arr)[i] % 2 == 0);
    return true;
}
