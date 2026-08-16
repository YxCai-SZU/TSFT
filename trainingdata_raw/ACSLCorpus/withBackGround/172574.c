#include <stdbool.h>

/*@ predicate is_even(integer n) = n % 2 == 0; */
/*@ predicate is_odd(integer n) = n % 2 != 0; */

/*@
  requires \true;
  ensures \result == (n % 2 == 0);
*/
bool is_even_fn(unsigned char n) {
    return n % 2 == 0;
}

/*@
  requires \true;
  ensures \result == (n % 2 != 0);
*/
bool is_odd_fn(unsigned char n) {
    return n % 2 != 0;
}

/*@
  requires f_pre: \true;
  ensures f_post: \result == (x % 2 == 0);
*/
bool test_even(unsigned char x) {
    bool res;
    //@ assert f_pre: \true;
    res = is_even_fn(x);
    //@ assert f_post: res == (x % 2 == 0);
    return res;
}

/*@
  requires f_pre: \true;
  ensures f_post: \result == (x % 2 != 0);
*/
bool test_odd(unsigned char x) {
    bool res;
    //@ assert f_pre: \true;
    res = is_odd_fn(x);
    //@ assert f_post: res == (x % 2 != 0);
    return res;
}

int main() {
    bool even;
    bool odd;
    
    even = test_even(10);
    //@ assert even_proof: even == true;
    
    odd = test_odd(11);
    //@ assert odd_proof: odd == true;
    
    return 0;
}
