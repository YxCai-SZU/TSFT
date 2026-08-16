#include <limits.h>

/*@
    requires (1 <= (a) <= 1000) && (1 <= (b) <= 1000) && (1 <= (c) <= 1000) && (1 <= (d) <= 1000);
    ensures \result == ((a) + (b) + (c) + (d) - 3 * ((((a)) > ((b))) ? ((a)) : ((b))) - 3 * ((((c)) > ((d))) ? ((c)) : ((d))) + 1);
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int result = 0;
    //@ assert result == 0;
    
    result += a;
    //@ assert result == a;
    
    result += b;
    //@ assert result == a + b;
    
    result += c;
    //@ assert result == a + b + c;
    
    result += d;
    //@ assert result == a + b + c + d;
    
    if (a > b)
    {
        //@ assert 3 * a <= 3 * 1000;
        result -= 3 * a;
        //@ assert result == a + b + c + d - 3 * a;
    }
    else
    {
        //@ assert 3 * b <= 3 * 1000;
        result -= 3 * b;
        //@ assert result == a + b + c + d - 3 * b;
    }
    
    if (c > d)
    {
        //@ assert 3 * c <= 3 * 1000;
        result -= 3 * c;
        //@ assert result == a + b + c + d - 3 * (((a) > (b)) ? (a) : (b)) - 3 * c;
    }
    else
    {
        //@ assert 3 * d <= 3 * 1000;
        result -= 3 * d;
        //@ assert result == a + b + c + d - 3 * (((a) > (b)) ? (a) : (b)) - 3 * d;
    }
    
    result += 1;
    //@ assert result == ((a) + (b) + (c) + (d) - 3 * ((((a)) > ((b))) ? ((a)) : ((b))) - 3 * ((((c)) > ((d))) ? ((c)) : ((d))) + 1);
    
    return result;
}
