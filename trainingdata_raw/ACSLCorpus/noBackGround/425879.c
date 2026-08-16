#include <stdbool.h>

/*@
    requires (100 <= (n) && (n) <= 999);
    ensures \result == true <==> (((n) / 100) % 10) == ((n) % 10);
    assigns \nothing;
*/
bool func(unsigned long n)
{
    unsigned long n_100;
    unsigned long n_10;
    unsigned long a;
    unsigned long b;
    unsigned long c;
    bool result;
    
    //@ assert (100 <= (n) && (n) <= 999);
    
    //@ assert n / 100 <= 9 && n / 10 <= 99 && n <= 999;
    n_100 = n / 100;
    n_10 = n / 10;
    a = n_100 % 10;
    b = n_10 % 10;
    c = n % 10;
    
    if (a == c) {
        //@ assert (((n) / 100) % 10) == ((n) % 10);
        result = true;
    } else {
        //@ assert (((n) / 100) % 10) != ((n) % 10);
        result = false;
    }
    
    //@ assert result == true <==> (((n) / 100) % 10) == ((n) % 10);
    return result;
}
