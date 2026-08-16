#include <stdbool.h>
#include <stddef.h>

/*@
    requires (3 <= (a) && (a) <= 20) && (3 <= (b) && (b) <= 20);
    ensures \result == a + b || \result == 2 * a - 1 || \result == 2 * b - 1;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    
    //@ assert (3 <= (a) && (a) <= 20) && (3 <= (b) && (b) <= 20);
    
    if (a >= b + 1) {
        result = a * 2 - 1;
        //@ assert result == 2 * a - 1;
    } else if (b >= a + 1) {
        result = b * 2 - 1;
        //@ assert result == 2 * b - 1;
    } else {
        result = a + b;
        //@ assert result == a + b;
    }
    
    //@ assert result >= 0;
    return result;
}

/*@
    assigns \nothing;
*/
void example2(void)
{
    unsigned int v[2];
    size_t v_len = 0;
    
    //@ assert ((v_len) <= 2 &&          ((v_len) >= 1 ==> (&v[0])[0] == 3) &&         ((v_len) == 2 ==> (&v[0])[1] == 6));
    
    v[v_len] = 3;
    v_len++;
    //@ assert ((v_len) <= 2 &&          ((v_len) >= 1 ==> (&v[0])[0] == 3) &&         ((v_len) == 2 ==> (&v[0])[1] == 6));
    
    v[v_len] = 6;
    v_len++;
    //@ assert ((v_len) <= 2 &&          ((v_len) >= 1 ==> (&v[0])[0] == 3) &&         ((v_len) == 2 ==> (&v[0])[1] == 6));
    
    if (v_len > 0) {
        unsigned int x = v[v_len - 1];
        v_len--;
        //@ assert x == 6;
        //@ assert ((v_len) <= 2 &&          ((v_len) >= 1 ==> (&v[0])[0] == 3) &&         ((v_len) == 2 ==> (&v[0])[1] == 6));
    }
    
    //@ assert v_len == 1;
    //@ assert ((v_len) <= 2 &&          ((v_len) >= 1 ==> (&v[0])[0] == 3) &&         ((v_len) == 2 ==> (&v[0])[1] == 6));
}
