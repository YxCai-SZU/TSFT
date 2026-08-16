#include <stdbool.h>


bool func(unsigned int k, unsigned int x) {
    unsigned int en;
    bool result;
    
    en = 500;
    
    //@ assert k * en >= x ==> k * 500 >= x;
    
    result = (k * en >= x);
    return result;
}
