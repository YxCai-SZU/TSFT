#include <stdbool.h>

/*@
    requires (10 <= (n) && (n) <= 99);
    ensures ((\result) == ((n) / 10 == 9 || (n) % 10 == 9));
    assigns \nothing;
*/
bool func(int n)
{
    bool is_nine = false;
    unsigned int abs_n;
    unsigned int div = 0;
    unsigned int temp;
    
    //@ assert (10 <= (n) && (n) <= 99);
    
    if (n < 0) {
        abs_n = (unsigned int)(-n);
    } else {
        abs_n = (unsigned int)n;
    }
    
    temp = abs_n;
    
    /*@
        loop invariant 0 <= temp <= abs_n;
        loop invariant 0 <= div <= abs_n / 10;
        loop invariant temp == abs_n - 10 * div;
        loop invariant (10 <= (n) && (n) <= 99);
        loop assigns temp, div;
        loop variant temp;
    */
    while (temp >= 10) {
        temp -= 10;
        div += 1;
    }
    
    //@ assert temp == abs_n % 10;
    //@ assert div == abs_n / 10;
    
    if (div == 9 || temp == 9) {
        is_nine = true;
    }
    
    //@ assert ((is_nine) == ((n) / 10 == 9 || (n) % 10 == 9));
    return is_nine;
}
