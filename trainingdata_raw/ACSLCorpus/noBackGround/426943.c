#include <stdbool.h>

/*@
requires \true;
ensures \result <==> (a == b);
*/
bool test_equality(bool a, bool b) {
    bool result;
    result = (a == b);
    //@ assert result <==> (a == b);
    return result;
}

/*@
requires 0 <= n <= 100;
requires 0 <= m <= 100;
ensures \result <==> (n > m);
*/
bool test_size(int n, int m) {
    bool result;
    result = (n > m);
    //@ assert result <==> (n > m);
    return result;
}

int main() {
    //@ assert ((1) <==> (1));
    //@ assert ((0) <==> (0));
    //@ assert !((1) <==> (0));
    //@ assert ((1) || (0) || (0));
    //@ assert !((0) || (0) || (0));
    
    bool test1 = test_equality(true, false);
    bool test2 = test_size(10, 5);
    
    return 0;
}
