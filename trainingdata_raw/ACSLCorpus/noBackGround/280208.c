#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 9) && (1 <= (b) && (b) <= 9) && (1 <= (c) && (c) <= 9);
    ensures \result == ((((a) == (b) && (b) != (c)) || ((b) == (c) && (c) != (a)) || ((c) == (a) && (a) != (b)) ? 1 : 0) == 1);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    // Variable declarations at scope top
    bool result;

    //@ assert (1 <= (a) && (a) <= 9);
    //@ assert (1 <= (b) && (b) <= 9);
    //@ assert (1 <= (c) && (c) <= 9);
    
    result = (a == b && b != c) || (b == c && c != a) || (c == a && a != b);
    return result;
}

int main()
{
    return 0;
}
