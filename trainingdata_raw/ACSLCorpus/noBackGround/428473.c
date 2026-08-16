#include <stdbool.h>
#include <stddef.h>

/*@
  requires y > x;
  ensures \result == true;
  assigns \nothing;
*/
bool check_greater_than_x(int x, int y) {
    //@ assert y > x;
    return y > x;
}

/*@
  requires \forall integer i; 0 <= i < len ==> l[i] > x;
  ensures \result == true;
  assigns \nothing;
*/
bool func(const int *l, size_t len, int x) {
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant \forall integer j; 0 <= j < i ==> l[j] > x;
      loop assigns i;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert l[i] > x;
        if (!check_greater_than_x(x, l[i])) {
            return false;
        }
        i++;
    }
    return true;
}

int main() {
    return 0;
}
