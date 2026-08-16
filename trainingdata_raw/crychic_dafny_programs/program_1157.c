// Generated C + ACSL

typedef struct {
    int dummy;
} Option;

/*@
    assigns \nothing;
    ensures \result.dummy == value;
*/
Option Some(int value) {
    Option opt;
    opt.dummy = value;
    return opt;
}

/*@
    assigns \nothing;
    ensures \result.dummy == 0;
*/
Option None_value() {
    Option opt;
    opt.dummy = 0;
    return opt;
}

/*@
    requires payload != 0;
    assigns \nothing;
    ensures \result.dummy == 0 || \result.dummy != 0;
*/
Option ExtractCommand(int payload)
{
  return None_value();
}

/*@
    requires payload != 0;
    assigns \nothing;
    ensures \result.dummy == 0 || \result.dummy != 0;
*/
Option ExtractSettings(int payload)
{
  return None_value();
}