#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result >= 0 && \result <= 200;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    int diff_ab;
    int diff_bc;
    int diff_ca;
    int min_ab;
    int min_val;

    result = 0;
    
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    
    diff_ab = a > b ? a - b : b - a;
    //@ assert diff_ab == ((a) > (b) ? (a) - (b) : (b) - (a));
    
    diff_bc = b > c ? b - c : c - b;
    //@ assert diff_bc == ((b) > (c) ? (b) - (c) : (c) - (b));
    
    diff_ca = c > a ? c - a : a - c;
    //@ assert diff_ca == ((c) > (a) ? (c) - (a) : (a) - (c));
    
    min_ab = diff_ab < diff_bc ? diff_ab : diff_bc;
    //@ assert min_ab == ((diff_ab) < (diff_bc) ? (diff_ab) : (diff_bc));
    
    min_val = min_ab < diff_ca ? min_ab : diff_ca;
    //@ assert min_val == ((min_ab) < (diff_ca) ? (min_ab) : (diff_ca));
    
    result += min_val;
    //@ assert result >= 0;
    
    if (diff_ab == diff_bc + diff_ca || 
        diff_bc == diff_ab + diff_ca || 
        diff_ca == diff_ab + diff_bc)
    {
        result += min_val;
    }
    
    //@ assert result >= 0;
    //@ assert result <= 200;
    
    return result;
}
