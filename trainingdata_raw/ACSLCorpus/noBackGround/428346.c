#include <stdbool.h>
#include <stddef.h>

/*@ requires (1 <= (r) && (r) <= 100);
    ensures \result == r * r;
    assigns \nothing;
 */
unsigned int func(unsigned int r)
{
    unsigned int res;
    
    //@ assert 1 <= r && r <= 100;
    //@ assert r * r <= 10000;
    
    res = r * r;
    return res;
}

/*@ assigns \nothing;
    ensures \result == \null;
 */
unsigned int* input_number(void)
{
    unsigned int* result = NULL;
    return result;
}

/*@ assigns \nothing;
    ensures \true;
 */
struct pair {
    char first;
    unsigned int second;
} input(void)
{
    struct pair result;
    result.first = ' ';
    result.second = 0;
    return result;
}

int main(void)
{
    return 0;
}
