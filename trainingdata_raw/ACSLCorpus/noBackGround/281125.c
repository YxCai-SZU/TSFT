#include <stdbool.h>
#include <stddef.h>

/*@
    requires (1 <= (x) && (x) <= 100);
    ensures \result == (6 * (x));
    assigns \nothing;
*/
int func(int x)
{
    int pi;
    int result;

    pi = 3;
    result = 2 * x * pi;
    
    //@ assert result == 6 * x;
    return result;
}

/*@
    requires \valid(a + (0 .. len-1));
    requires len >= 0;
    assigns *out;
    ensures \result == (len > 0);
    ensures \result ==> (*out == a[len-1]);
*/
bool vec_pop(unsigned int* a, size_t len, unsigned int* out)
{
    bool success;
    
    if (len == 0) {
        success = false;
    } else {
        *out = a[len - 1];
        success = true;
    }
    
    //@ assert success == (len > 0);
    return success;
}

/*@
    requires (1 <= (x) && (x) <= 100);
    ensures \result == ((x) * (x));
    assigns \nothing;
*/
int func2(int x)
{
    int result;
    
    //@ assert x * x <= 10000;
    result = x * x;
    
    //@ assert result == x * x;
    return result;
}

/*@
    assigns \nothing;
*/
int main()
{
    unsigned int vec[2] = {3, 6};
    unsigned int popped;
    
    //@ assert vec[0] == 3;
    //@ assert vec[1] == 6;
    
    if (vec_pop(vec, 2, &popped)) {
        //@ assert popped == 6;
    }
    
    //@ assert vec[0] == 3;
    //@ assert vec[1] == 6;
    
    return 0;
}
