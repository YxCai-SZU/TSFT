#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid_read(l + (0 .. len-1));
  ensures \result <==> (\forall integer i; 0 <= i < (len)/2 ==> (l)[i] == (l)[(len) - i - 1]);
*/
bool is_palindrome(unsigned int *l, size_t len) {
    size_t i = 0;
    /*@
      loop invariant 0 <= i <= len/2;
      loop invariant \forall integer j; 0 <= j < i ==> l[j] == l[len - j - 1];
      loop assigns i;
      loop variant len/2 - i;
    */
    while (i < len / 2) {
        //@ assert 0 <= i < len/2;
        if (l[i] != l[len - i - 1]) {
            return false;
        }
        i++;
    }
    return true;
}

/*@
  ensures \result <==> (x > 5);
*/
bool check_greater_than(unsigned int x) {
    //@ assert \true;
    return x > 5;
}

int main() {
    return 0;
}
