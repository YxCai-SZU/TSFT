#include <stdbool.h>

enum Transaction_Tag { Deposit, Withdrawal };
struct Transaction {
    enum Transaction_Tag tag;
    unsigned long long amount;
};

enum AccountType_Tag { Checking, Savings };
struct AccountType {
    enum AccountType_Tag tag;
};

/*@
    requires \true;
    ensures ((\result.tag) == Checking);
    assigns \nothing;
*/
struct AccountType new_account(void) {
    struct AccountType account_type;
    account_type.tag = Checking;
    //@ assert ((account_type.tag) == Checking);
    return account_type;
}

/*@
    requires ((account_type.tag) == Checking);
    requires ((transaction.tag) == Deposit);
    assigns \nothing;
*/
void perform_transaction(struct AccountType account_type, struct Transaction transaction) {
    //@ assert ((account_type.tag) == Checking);
    //@ assert ((transaction.tag) == Deposit);
}
