#include <stdbool.h>
#include <stddef.h>

/*@
    requires (((integer)len) >= 0 && \valid((vec) + (0 .. ((integer)len)-1)));
    ensures \result == (((integer)len));
    assigns \nothing;
*/
size_t count_elements_int(int *vec, size_t len) {
    //@ assert (integer)len >= 0;
    return len;
}

/*@
    requires (((integer)len) >= 0 && \valid((vec) + (0 .. ((integer)len)-1)));
    ensures \result == (((integer)len));
    assigns \nothing;
*/
size_t count_elements_bool(bool *vec, size_t len) {
    //@ assert (integer)len >= 0;
    return len;
}

/*@
    assigns \nothing;
*/
void print_count(size_t count) {
    //@ assert (integer)count >= 0;
}

/*@
    assigns \nothing;
*/
int main() {
    int array_int[5];
    size_t count_int;
    bool array_bool[5];
    size_t count_bool;
    
    //@ assert ((5) >= 0 && \valid((&array_int[0]) + (0 .. (5)-1)));
    count_int = count_elements_int(&array_int[0], 5);
    //@ assert (integer)count_int == 5;
    print_count(count_int);
    
    //@ assert ((5) >= 0 && \valid((&array_bool[0]) + (0 .. (5)-1)));
    count_bool = count_elements_bool(&array_bool[0], 5);
    //@ assert (integer)count_bool == 5;
    print_count(count_bool);
    
    return 0;
}
