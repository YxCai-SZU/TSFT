#include <stdint.h>
#include <stdbool.h>

/*@
    predicate valid_n(uint32_t n) = 0 <= n <= 4294967295;

    logic integer bitwise_xor(integer n) = n ^ (n >> 1);
*/

uint32_t gray_code(uint32_t n)
{
    uint32_t result;
    
    //@ assert 0 <= n <= 4294967295;
    
    result = n ^ (n >> 1);
    
    //@ assert result == bitwise_xor(n);
    
    return result;
}

/*@
    predicate is_special(integer n) = n == 3 || n == 5 || n == 7;
*/

bool is_special_digit(int n)
{
    //@ assert n >= 1 && n <= 9;
    bool result;
    switch (n) {
        case 3:
        case 5:
        case 7:
            result = true;
            break;
        default:
            result = false;
            break;
    }
    //@ assert result == (n == 3 || n == 5 || n == 7);
    return result;
}

bool check_gray_code_special(uint32_t n)
{
    uint32_t gray;
    bool special;
    
    //@ assert 0 <= n <= 9;
    gray = gray_code(n);
    //@ assert gray == bitwise_xor(n);
    
    if (n >= 1 && n <= 9) {
        special = is_special_digit((int)n);
        //@ assert special == (n == 3 || n == 5 || n == 7);
    } else {
        special = false;
    }
    
    //@ assert special == (n >= 1 && n <= 9 && (n == 3 || n == 5 || n == 7));
    
    return special;
}
