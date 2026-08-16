#include <stdbool.h>
#include <stdint.h>

/*@ requires ((len) >= 3 &&
    1 <= (v)[0] && (v)[0] <= 9 &&
    1 <= (v)[1] && (v)[1] <= 9 &&
    1 <= (v)[2] && (v)[2] <= 9);
    ensures \result == ((v[1] * 10 + v[2]) % 4 < 1);
*/
bool func(unsigned int *v, unsigned int len)
{
    unsigned int sum;
    unsigned int remainder;
    
    //@ assert 1 <= v[1] && v[1] <= 9;
    //@ assert 1 <= v[2] && v[2] <= 9;
    
    sum = v[1] * 10 + v[2];
    //@ assert sum == ((((v))[(1)]) * 10 + (((v))[(2)]));
    
    remainder = sum % 4;
    //@ assert remainder == ((((v))[(1)]) * 10 + (((v))[(2)])) % 4;
    
    //@ assert remainder == ((v[1] * 10 + v[2]) % 4);
    
    return remainder < 1;
}
