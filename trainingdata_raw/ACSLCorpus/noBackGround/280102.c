#include <stdbool.h>
#include <stdint.h>

/*@
    requires 0 <= length && length < 0x80000000;
    assigns \nothing;
    ensures \result <==> (length % 2 != 0);
*/
bool is_odd_list_length(const int *list, int length) {
    //@ assert length % 2 == 0 || length % 2 == 1;
    return length % 2 != 0;
}

int main() {
    //@ assert ((((2020) % 4 == 0) && ((2020) % 100 != 0)) || ((2020) % 400 == 0));
    //@ assert !((((1900) % 4 == 0) && ((1900) % 100 != 0)) || ((1900) % 400 == 0));
    //@ assert ((1) % 2 != 0);
    //@ assert !((2) % 2 != 0);
    
    int list1[] = {1, 2, 3};
    int list2[] = {1, 2, 3, 4};
    
    bool result1 = is_odd_list_length(list1, 3);
    bool result2 = is_odd_list_length(list2, 4);
    
    //@ assert result1 == true;
    //@ assert result2 == false;
    
    return 0;
}
