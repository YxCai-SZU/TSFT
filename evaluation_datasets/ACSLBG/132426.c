#include <limits.h>

/*@ predicate is_in_range(integer x) = -100 <= x <= 100; */


int func(int a, int b, int c)
{
    int ans;
    //@ assert is_in_range(a);
    //@ assert is_in_range(b);
    //@ assert is_in_range(c);
    
    if (a == b) {
        ans = c;
    } else if (b == c) {
        ans = a;
    } else {
        ans = b;
    }
    
    //@ assert ans == c || ans == a || ans == b;
    //@ assert (a == b && a != c) ==> ans == c;
    //@ assert (a == c && a != b) ==> ans == b;
    //@ assert (b == c && a != b) ==> ans == a;
    
    return ans;
}
