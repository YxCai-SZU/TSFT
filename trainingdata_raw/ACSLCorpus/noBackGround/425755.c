#include <stdbool.h>

/*@ requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == true <==> a + b >= c;
    assigns \nothing;
*/
bool func(int a, int b, int c) {
    bool transaction_result;
    bool no_transaction_result;
    
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    
    if (a + b >= c) {
        //@ assert a + b >= c;
        //@ assert ((a) + (b) >= (c));
        transaction_result = true;
        //@ assert transaction_result == true;
        return transaction_result;
    } else {
        //@ assert a + b < c;
        //@ assert !((a) + (b) >= (c));
        no_transaction_result = false;
        //@ assert no_transaction_result == false;
        return no_transaction_result;
    }
}
