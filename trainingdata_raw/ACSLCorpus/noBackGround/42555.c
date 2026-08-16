#include <stdbool.h>

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    ensures (a == b && a != c) ==> \result == c;
    ensures (a == c && a != b) ==> \result == b;
    ensures (b == c && a != b) ==> \result == a;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    //@ assert -100 <= a <= 100 && -100 <= b <= 100 && -100 <= c <= 100;
    
    if (a == b) {
        //@ assert a == b;
        return c;
    } else if (a == c) {
        //@ assert a == c;
        return b;
    } else if (b == c) {
        //@ assert b == c;
        return a;
    } else {
        //@ assert a != b && a != c && b != c;
        return 0;
    }
}

/*@
    requires true;
    ensures \result == (n % 2 != 0);
    assigns \nothing;
*/
bool is_odd_impl(unsigned int n)
{
    //@ assert true;
    return n % 2 != 0;
}

int main()
{
    return 0;
}
