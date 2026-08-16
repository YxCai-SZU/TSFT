#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid(v+(0..len-1));
  requires len > 0;
  requires \forall integer i; 0 <= i < len ==> (\true);
  ensures \result == 1 ==> \forall integer i; 0 <= i < len ==> ((1) == ((v[i]) < 5));
  ensures \result == 0 ==> \exists integer i; 0 <= i < len && ((0) == ((v[i]) < 5));
  assigns \nothing;
*/
bool process_list(const int *v, size_t len) {
    size_t j = 0;
    /*@
      loop invariant 0 <= j <= len;
      loop invariant \forall integer i; 0 <= i < len ==> (\true);
      loop invariant \forall integer i; 0 <= i < j ==> ((1) == ((v[i]) < 5));
      loop assigns j;
      loop variant len - j;
    */
    for (j = 0; j < len; ++j) {
        //@ assert (\true);
        bool check_result = (v[j] < 5);
        //@ assert ((check_result ? 1 : 0) == ((v[j]) < 5));
        if (!check_result) {
            return false;
        }
    }
    return true;
}

int main() {
    int list[] = {-3, -2, 0, 1, 5};
    size_t list_len = 5;
    bool result = process_list(list, list_len);
    //@ assert result == 0;
    return 0;
}
