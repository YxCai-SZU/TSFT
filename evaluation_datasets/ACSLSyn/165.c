#include <stdbool.h>

/*@ predicate is_between(integer A, integer B, integer C) =
      (A < C && C < B) || (B < C && C < A);
*/

/*@
  predicate is_in_range(integer x) = 1 <= x <= 100000;
  
  predicate valid_transaction(integer amount, integer a, integer b, integer c) =
    is_in_range(amount) && is_between(a, b, c) &&
    (amount / 100 >= (amount % 100) / 5 + (amount % 100) % 5);
*/

bool func_between(int A, int B, int C)
{
    bool ans = false;
    int a, b, c;

    if (A < B)
    {
        a = A;
        b = B;
        c = C;
    }
    else
    {
        a = B;
        b = A;
        c = C;
    }

    if (a < c && c < b)
    {
        ans = true;
    }

    //@ assert ans == true <==> is_between(A, B, C);
    return ans;
}

bool func_change(unsigned int X) {
    unsigned int t;
    unsigned int Y;
    unsigned int c;
    unsigned int r;
    
    t = X / 100;
    Y = X % 100;
    c = 0;
    r = Y;
    
    while (r >= 5) {
        //@ assert r >= 5;
        c = c + 1;
        r = r - 5;
        //@ assert r == Y - 5 * c;
    }
    
    //@ assert c == Y / 5;
    //@ assert r == Y % 5;
    return t >= c + r;
}

bool process_transaction(int A, int B, int C, unsigned int amount) {
    bool between_check = func_between(A, B, C);
    bool change_check = func_change(amount);
    bool result = between_check && change_check;
    
    //@ assert result == true <==> (is_between(A, B, C) && (amount / 100 >= (amount % 100) / 5 + (amount % 100) % 5));
    return result;
}
