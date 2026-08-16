#include <stddef.h>

/*@
    requires ((v1_len) >= 0) && ((v2_len) >= 0);
    requires v1_len == 3 && v2_len == 4;
    ensures v1_len + v2_len == 7;
*/
void calc_example_vector_length(int* v1, size_t v1_len, int* v2, size_t v2_len)
{
    //@ assert v1_len == 3;
    //@ assert v2_len == 4;
    //@ assert v1_len + v2_len == 7;
}

int main()
{
    return 0;
}
