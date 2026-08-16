#include <stdbool.h>

/*@
  requires n >= 0;
  ensures \result == (n % 2 == 0);
  assigns \nothing;
*/
bool is_even_func(unsigned int n) {
    //@ assert n % 2 == 0 ==> ((n) % 2 == 0);
    return n % 2 == 0;
}

/*@
  requires n >= 0;
  ensures \result == (n % 2 != 0);
  assigns \nothing;
*/
bool is_odd_func(unsigned int n) {
    //@ assert n % 2 != 0 ==> ((n) % 2 != 0);
    return n % 2 != 0;
}

/*@
  requires n >= 0;
  ensures \result == (n % 10 == (n / 10) % 10);
  assigns \nothing;
*/
bool is_palindrome_func(unsigned int n) {
    //@ assert n % 10 == (n / 10) % 10 ==> ((n) % 10 == ((n) / 10) % 10);
    return n % 10 == (n / 10) % 10;
}

/*@
  requires n >= 0;
  ensures \result == (n % 3 == 0);
  assigns \nothing;
*/
bool is_multiple_of_3_func(unsigned int n) {
    //@ assert n % 3 == 0 ==> ((n) % 3 == 0);
    return n % 3 == 0;
}

/*@
  requires n >= 0;
  ensures \result == (n % 5 == 0);
  assigns \nothing;
*/
bool is_multiple_of_5_func(unsigned int n) {
    //@ assert n % 5 == 0 ==> ((n) % 5 == 0);
    return n % 5 == 0;
}

/*@
  requires n >= 0;
  ensures \result == (n % 7 == 0);
  assigns \nothing;
*/
bool is_multiple_of_7_func(unsigned int n) {
    //@ assert n % 7 == 0 ==> ((n) % 7 == 0);
    return n % 7 == 0;
}

/*@
  assigns \nothing;
*/
void main2(void) {
    unsigned int num;
    bool even;
    bool odd;
    bool palindrome;
    bool multiple_of_3;
    bool multiple_of_5;
    bool multiple_of_7;
    
    num = 123;
    even = is_even_func(num);
    odd = is_odd_func(num);
    palindrome = is_palindrome_func(num);
    multiple_of_3 = is_multiple_of_3_func(num);
    multiple_of_5 = is_multiple_of_5_func(num);
    multiple_of_7 = is_multiple_of_7_func(num);
    
    //@ assert even == (num % 2 == 0);
}
