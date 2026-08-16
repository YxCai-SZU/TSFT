#include <stdbool.h>
#include <stdint.h>

struct Wallet {
    uint32_t amount;
};

/*@ requires amount <= w.amount;
    requires ((w).amount >= 0 && (w).amount <= 0xFFFFFFFF);
    ensures \result.amount == w.amount - amount;
    ensures ((\result).amount >= 0 && (\result).amount <= 0xFFFFFFFF);
    assigns \nothing;
*/
struct Wallet withdraw(struct Wallet w, uint32_t amount) {
    //@ assert amount <= w.amount;
    struct Wallet ret = { w.amount - amount };
    //@ assert ret.amount == w.amount - amount;
    return ret;
}

/*@ requires ((w).amount >= 0 && (w).amount <= 0xFFFFFFFF);
    ensures \result == (w.amount >= 0xFFFFFFFF);
    assigns \nothing;
*/
bool check_balance(struct Wallet w) {
    bool ret = w.amount >= 0xFFFFFFFF;
    //@ assert ret == (w.amount >= 0xFFFFFFFF);
    return ret;
}

/*@ requires amount <= 0xFFFFFFFF;
    requires ((w).amount >= 0 && (w).amount <= 0xFFFFFFFF);
    requires (uint64_t)amount + w.amount <= 0xFFFFFFFF;
    ensures \result.amount == amount + w.amount;
    ensures ((\result).amount >= 0 && (\result).amount <= 0xFFFFFFFF);
    assigns \nothing;
*/
struct Wallet replenish(struct Wallet w, uint32_t amount) {
    //@ assert (uint64_t)amount + w.amount <= 0xFFFFFFFF;
    struct Wallet ret = { amount + w.amount };
    //@ assert ret.amount == amount + w.amount;
    return ret;
}

int main() {
    struct Wallet w;
    w.amount = 1000;
    
    //@ assert ((w).amount >= 0 && (w).amount <= 0xFFFFFFFF);
    w = withdraw(w, 500);
    //@ assert ((integer)(w).amount) == 500;
    
    w = replenish(w, 200);
    //@ assert ((integer)(w).amount) == 700;
    
    w = withdraw(w, 700);
    //@ assert ((integer)(w).amount) == 0;
    
    return 0;
}
