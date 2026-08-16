#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100 && 1 <= (k) && (k) <= 100);
    ensures \result == ((((n) % 2 == 1 && (n) / 2 >= (k)) ? 1 : 
        ((n) % 2 == 0 && ((n) / 2 - 1 + (n) % 2) >= (k)) ? 1 : 0) == 1);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int k) {
    bool result;
    
    //@ assert (1 <= (n) && (n) <= 100 && 1 <= (k) && (k) <= 100);
    
    if (n % 2 == 1) {
        //@ assert n % 2 == 1;
        if (n / 2 >= k) {
            result = true;
            //@ assert result == ((((n) % 2 == 1 && (n) / 2 >= (k)) ? 1 :          ((n) % 2 == 0 && ((n) / 2 - 1 + (n) % 2) >= (k)) ? 1 : 0) == 1);
            return result;
        } else {
            result = false;
            //@ assert result == ((((n) % 2 == 1 && (n) / 2 >= (k)) ? 1 :          ((n) % 2 == 0 && ((n) / 2 - 1 + (n) % 2) >= (k)) ? 1 : 0) == 1);
            return result;
        }
    } else {
        //@ assert n % 2 == 0;
        if (n / 2 - 1 + n % 2 >= k) {
            result = true;
            //@ assert result == ((((n) % 2 == 1 && (n) / 2 >= (k)) ? 1 :          ((n) % 2 == 0 && ((n) / 2 - 1 + (n) % 2) >= (k)) ? 1 : 0) == 1);
            return result;
        } else {
            result = false;
            //@ assert result == ((((n) % 2 == 1 && (n) / 2 >= (k)) ? 1 :          ((n) % 2 == 0 && ((n) / 2 - 1 + (n) % 2) >= (k)) ? 1 : 0) == 1);
            return result;
        }
    }
}

#ifdef TESTING
#include <assert.h>

void test1(void) {
    unsigned int n = 7;
    unsigned int k = 3;
    bool result = func(n, k);
    //@ assert result == ((((n) % 2 == 1 && (n) / 2 >= (k)) ? 1 :          ((n) % 2 == 0 && ((n) / 2 - 1 + (n) % 2) >= (k)) ? 1 : 0) == 1);
    assert(result == ((n % 2 == 1 && n / 2 >= k) || 
                     (n % 2 == 0 && (n / 2 - 1 + n % 2) >= k)));
}

void test2(void) {
    unsigned int n = 10;
    unsigned int k = 5;
    bool result = func(n, k);
    //@ assert result == ((((n) % 2 == 1 && (n) / 2 >= (k)) ? 1 :          ((n) % 2 == 0 && ((n) / 2 - 1 + (n) % 2) >= (k)) ? 1 : 0) == 1);
    assert(result == ((n % 2 == 1 && n / 2 >= k) || 
                     (n % 2 == 0 && (n / 2 - 1 + n % 2) >= k)));
}

void test3(void) {
    unsigned int n = 5;
    unsigned int k = 3;
    bool result = func(n, k);
    //@ assert result == ((((n) % 2 == 1 && (n) / 2 >= (k)) ? 1 :          ((n) % 2 == 0 && ((n) / 2 - 1 + (n) % 2) >= (k)) ? 1 : 0) == 1);
    assert(result == ((n % 2 == 1 && n / 2 >= k) || 
                     (n % 2 == 0 && (n / 2 - 1 + n % 2) >= k)));
}

void test4(void) {
    unsigned int n = 2;
    unsigned int k = 1;
    bool result = func(n, k);
    //@ assert result == ((((n) % 2 == 1 && (n) / 2 >= (k)) ? 1 :          ((n) % 2 == 0 && ((n) / 2 - 1 + (n) % 2) >= (k)) ? 1 : 0) == 1);
    assert(result == ((n % 2 == 1 && n / 2 >= k) || 
                     (n % 2 == 0 && (n / 2 - 1 + n % 2) >= k)));
}

int main(void) {
    test1();
    test2();
    test3();
    test4();
    return 0;
}
#endif
