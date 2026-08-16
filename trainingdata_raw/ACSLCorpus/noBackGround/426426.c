#include <stdbool.h>

/*@
    requires n < 0x80000000;
    ensures \result == (n % 2 == 0);
    assigns \nothing;
*/
bool is_even_f(unsigned int n) {
    bool even;
    even = (n % 2 == 0);
    //@ assert even == (n % 2 == 0);
    return even;
}

/*@
    requires n < 0x80000000;
    ensures \result == (n % 3 == 0);
    assigns \nothing;
*/
bool is_multiple_of_three(unsigned int n) {
    bool multiple;
    multiple = (n % 3 == 0);
    //@ assert multiple == (n % 3 == 0);
    return multiple;
}

/*@
    requires n < 0x80000000;
    ensures \result == (n % 5 == 0);
    assigns \nothing;
*/
bool is_multiple_of_five(unsigned int n) {
    bool multiple;
    multiple = (n % 5 == 0);
    //@ assert multiple == (n % 5 == 0);
    return multiple;
}

/*@
    requires n < 0x80000000;
    ensures \result == (n % 15 == 0);
    assigns \nothing;
*/
bool is_multiple_of_fifteen(unsigned int n) {
    bool multiple;
    multiple = (n % 15 == 0);
    //@ assert multiple == (n % 15 == 0);
    return multiple;
}

int main() {
    bool even;
    bool multiple;
    bool multiple_five;
    bool multiple_fifteen;
    
    even = is_even_f(8);
    //@ assert even == true;
    
    multiple = is_multiple_of_three(12);
    //@ assert multiple == true;
    
    multiple_five = is_multiple_of_five(15);
    //@ assert multiple_five == true;
    
    multiple_fifteen = is_multiple_of_fifteen(30);
    //@ assert multiple_fifteen == true;
    
    return 0;
}
