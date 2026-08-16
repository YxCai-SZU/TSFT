#include <stdint.h>

typedef struct {
    uint32_t issues;
    uint32_t subscriptions;
} Magazine;

/*@ requires ((mag).issues <= 12 && (mag).subscriptions <= 10000);
    assigns \nothing;
    ensures \result.issues == mag.issues;
    ensures \result.subscriptions == mag.subscriptions / 2;
*/
Magazine renew_subscriptions(Magazine mag) {
    //@ assert mag.issues <= 12;
    //@ assert mag.subscriptions <= 10000;
    //@ assert mag.subscriptions / 2 <= 5000;
    
    Magazine ret;
    ret.issues = mag.issues;
    ret.subscriptions = mag.subscriptions / 2;
    return ret;
}
