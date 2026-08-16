#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_even_spec(integer x) = x % 2 == 0; */

/*@
  requires \true;
  assigns \nothing;
  ensures \result <==> (x % 2 == 0);
*/
bool is_even(unsigned int x) {
    return x % 2 == 0;
}

/*@
  predicate vec_even_pred(unsigned int *v, integer len) =
    \forall integer i; 0 <= i < len ==> v[i] % 2 == 0;
*/

/*@
  requires \valid(v + (0 .. len-1));
  requires \forall integer i; 0 <= i < len ==> \true;
  requires \forall integer i; 0 <= i < len ==> 
    (\forall bool b; b == (v[i] % 2 == 0));
  ensures \result ==> vec_even_pred(v, len);
  ensures !\result ==> \exists integer i; 0 <= i < len && v[i] % 2 != 0;
*/
bool vec_is_all_even(unsigned int *v, size_t len, bool (*f)(unsigned int)) {
    size_t i = 0;
    /*@
      loop invariant 0 <= i <= len;
      loop invariant \forall integer j; 0 <= j < i ==> v[j] % 2 == 0;
      loop assigns i;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (!f(v[i])) {
            return false;
        }
        i++;
    }
    return true;
}

int main() {
    return 0;
}
