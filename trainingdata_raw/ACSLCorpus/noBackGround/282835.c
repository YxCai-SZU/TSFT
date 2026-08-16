#include <stdint.h>

typedef struct {
    uint32_t balance;
    uint32_t interest_rate;
} SavingsAccount;

/*@
    requires \valid(account);
    requires account->interest_rate <= 100;
    requires account->balance <= 10000;
    assigns \nothing;
    ensures \result.balance == account->balance + (account->interest_rate * account->balance / 100);
    ensures \result.interest_rate == account->interest_rate;
*/
SavingsAccount add_interest(const SavingsAccount* account) {
    uint32_t new_balance;
    
    //@ assert account->interest_rate <= 100;
    //@ assert account->balance <= 10000;
    //@ assert account->interest_rate * account->balance <= 10000 * 100;
    
    new_balance = account->balance + (account->interest_rate * account->balance / 100);
    
    SavingsAccount result = {
        .balance = new_balance,
        .interest_rate = account->interest_rate
    };
    
    return result;
}

int main() {
    return 0;
}
