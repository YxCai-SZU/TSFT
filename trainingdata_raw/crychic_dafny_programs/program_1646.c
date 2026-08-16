// Generated C + ACSL

typedef enum {
    EQUALS,
    IN,
    NOT_IN,
    NOT_EQUALS
} Condition;

typedef struct {
    Condition condition;
    int* value;
    int value_len;
} Requirement;

/*@ logic integer ValidateDataType(int actual, Condition req_condition, int* req_value, int req_value_len); */

/*@
    requires req.value_len > 0;
    requires \valid_read(req.value + (0 .. req.value_len-1));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    ensures \result == 1 ==>
        ((req.condition == EQUALS ==>
            (\exists integer i; 0 <= i < req.value_len && actual == req.value[i])) &&
         (req.condition == IN ==>
            (\exists integer i; 0 <= i < req.value_len && actual == req.value[i])) &&
         (req.condition == NOT_IN ==>
            (\forall integer i; 0 <= i < req.value_len ==> actual != req.value[i])) &&
         (req.condition == NOT_EQUALS ==>
            (\forall integer i; 0 <= i < req.value_len ==> actual != req.value[i])));
*/
int ValidateDataType(int actual, Requirement req)
{
  switch (req.condition) {
    case EQUALS:
      return actual == req.value[0];
    case IN:
      /*@ 
        loop invariant 0 <= i <= req.value_len;
        loop invariant \forall integer k; 0 <= k < i ==> actual != req.value[k];
        loop assigns i;
        loop variant req.value_len - i;
      */
      for (int i = 0; i < req.value_len; i++) {
        if (actual == req.value[i]) return 1;
      }
      return 0;
    case NOT_IN:
      /*@ 
        loop invariant 0 <= i <= req.value_len;
        loop invariant \forall integer k; 0 <= k < i ==> actual != req.value[k];
        loop assigns i;
        loop variant req.value_len - i;
      */
      for (int i = 0; i < req.value_len; i++) {
        if (actual == req.value[i]) return 0;
      }
      return 1;
    case NOT_EQUALS:
      /*@ 
        loop invariant 0 <= i <= req.value_len;
        loop invariant \forall integer k; 0 <= k < i ==> actual != req.value[k];
        loop assigns i;
        loop variant req.value_len - i;
      */
      for (int i = 0; i < req.value_len; i++) {
        if (actual == req.value[i]) return 0;
      }
      return 1;
    default:
      return 0;
  }
}

/*@
    requires types_len >= 0;
    requires types_len > 0 ==> types != \null;
    requires types_len > 0 ==> \valid_read(types + (0 .. types_len-1));
    requires inputRequirements_len > 0;
    requires inputRequirements != \null;
    requires \valid_read(inputRequirements + (0 .. inputRequirements_len-1));
    requires \forall integer r; 0 <= r < inputRequirements_len ==>
             inputRequirements[r].value_len > 0;
    requires \forall integer r; 0 <= r < inputRequirements_len ==>
             \valid_read(inputRequirements[r].value + (0 .. inputRequirements[r].value_len-1));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
*/
int ValidateDataTypes(int* types, int types_len, Requirement* inputRequirements, int inputRequirements_len)
{
  int result = 1;
  /*@ assert result >= 0 && result <= 2147483647; */
  int i = 0;
/*@
  loop invariant 0 <= i <= inputRequirements_len;
  loop invariant result == 0 || result == 1;
  loop assigns i, result;
  loop variant inputRequirements_len - i;
*/
  while (((i < inputRequirements_len) && result))
    {
      int requirementMet = 0;
      int j = 0;
      int validTypes = 0;
      if (types_len > 0) {
        validTypes = types[j];
      }
/*@
  loop invariant 0 <= j <= types_len;
  loop invariant requirementMet == 0 || requirementMet == 1;
  loop assigns j, requirementMet, validTypes;
  loop variant types_len - j;
*/
      while (((j < types_len) && !(requirementMet)))
        {
          int valid = ValidateDataType(types[j], inputRequirements[i]);
          requirementMet = (requirementMet || valid);
          j = (j + 1);
          if (j < types_len) {
            validTypes = types[j];
          }
        }
      result = (result && requirementMet);
      i = (i + 1);
    }
  return result;
}