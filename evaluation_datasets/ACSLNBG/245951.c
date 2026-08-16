#include <stdbool.h>

bool func(int *v, int len) {
    //@ assert len >= 3;
    //@ assert v[0] == 1;
    //@ assert v[1] == 2;
    //@ assert v[2] == 3;
    return len == 3;
}
