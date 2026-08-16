#include <stdbool.h>
#include <stddef.h>

/*@
  requires n >= 1 && n <= 100;
  requires \valid_read(a + (0 .. n-1));
  ensures \result == true <==> (\forall integer j; 0 <= j < (n) ==> ((a)[j] % 2 != 0) || ((a)[j] % 3 == 0) || ((a)[j] % 5 == 0));
*/
bool func(size_t n, unsigned int *a) {
    bool flag = true;
    size_t index = 0;

    /*@
      loop invariant 0 <= index <= n;
      loop invariant flag == true <==> (\forall integer j; 0 <= j < (index) ==> ((a)[j] % 2 != 0) || ((a)[j] % 3 == 0) || ((a)[j] % 5 == 0));
      loop assigns index, flag;
      loop variant n - index;
    */
    while (index < n) {
        unsigned int value = a[index];
        if (value % 2 != 0) {
            index += 1;
            continue;
        }
        if (!(value % 3 == 0 || value % 5 == 0)) {
            flag = false;
        }
        index += 1;
    }

    //@ assert flag == true <==> (\forall integer j; 0 <= j < (n) ==> ((a)[j] % 2 != 0) || ((a)[j] % 3 == 0) || ((a)[j] % 5 == 0));
    return flag;
}
