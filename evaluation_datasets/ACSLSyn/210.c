#include <stdbool.h>

/*@ predicate is_two_digit(integer n) = 10 <= n && n <= 99; */

bool contains_nine(unsigned int n)
{
    //@ assert is_two_digit(n);
    return (n % 10) == 9 || (n / 10) == 9;
}

/*@
    predicate double_precond(integer x) = 0 <= x && x < 128;
    predicate double_postcond(integer x, integer res) = res == 2 * x;
*/

unsigned char call_double(unsigned char x)
{
    //@ assert double_precond(x);
    unsigned char res = 2 * x;
    //@ assert double_postcond(x, res);
    return res;
}


unsigned int process_student_score(unsigned int n)
{
    //@ assert is_two_digit(n);
    bool has_nine = contains_nine(n);
    //@ assert has_nine == ((n % 10) == 9 || (n / 10) == 9);
    
    unsigned char doubled;
    
    if (n < 128) {
        doubled = call_double((unsigned char)n);
    } else {
        doubled = (unsigned char)(2 * n);
    }
    
    unsigned int result = (unsigned int)doubled;
    
    //@ assert (10 <= n && n <= 99) ==> (result % 2 == 0 && result >= 20 && result <= 198);
    
    return result;
}
