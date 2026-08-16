// Generated C + ACSL

typedef enum {
    EtherPad
} ComponentType;

typedef struct {
    ComponentType componentType;
} Component;

typedef struct {
    int hasChanges;
} SubComponent;

/*@
    requires components != \null;
    requires components_len > 0;
    requires \valid(components + (0 .. components_len-1));
    requires \exists integer i; 0 <= i < components_len && components[i].componentType == EtherPad;
    assigns \nothing;
    ensures \result == 1 ==>
        (\exists integer i; 0 <= i < components_len && components[i].componentType == EtherPad);
    ensures \result == 0 || \result == 1;
*/
int Configure(Component* components, int components_len)
{
  int i = 0;
  int success = 0;
  /*@ assert success >= 0 && success <= 2147483647; */
/*@
  loop invariant 0 <= i <= components_len;
  loop invariant \forall integer k; 0 <= k < i ==> components[k].componentType != EtherPad;
  loop invariant \at(i, LoopEntry) <= i;
  loop assigns i;
  loop variant components_len - i;
*/
  while ((i < components_len))
    {
      if ((components[i].componentType == EtherPad))
      {
        Component appServer = components[i];
        success = 1;
        return success;
      }
      i = (i + 1);
    }
  return success;  // Dafny implicit return
}

/*@
    requires subComponents_len >= 0;
    requires subComponents != \null || subComponents_len == 0;
    requires subComponents_len > 0 ==> \valid(subComponents + (0 .. subComponents_len-1));
    assigns \nothing;
    ensures \result == 1 <==> (\forall integer i; 0 <= i < subComponents_len ==> subComponents[i].hasChanges == 0);
    ensures \result == 0 <==> (\exists integer i; 0 <= i < subComponents_len && subComponents[i].hasChanges != 0);
*/
int AssertNoSubcomponentChanges(SubComponent* subComponents, int subComponents_len)
{
  int i = 0;
  int result = 1;
  /*@ assert result >= 0 && result <= 2147483647; */
/*@
  loop invariant 0 <= i <= subComponents_len;
  loop invariant result == 1 ==> (\forall integer k; 0 <= k < i ==> subComponents[k].hasChanges == 0);
  loop invariant result == 0 ==> (\exists integer k; 0 <= k < i && subComponents[k].hasChanges != 0);
  loop invariant result == 0 || result == 1;
  loop invariant subComponents_len > 0 ==> \valid_read(subComponents + (0..subComponents_len-1));
  loop assigns i, result;
  loop variant subComponents_len - i;
*/
  while ((i < subComponents_len))
    {
      if (subComponents[i].hasChanges)
      {
        result = 0;
        /*@ assert subComponents[i].hasChanges != 0; */
        /*@ assert \exists integer k; 0 <= k < subComponents_len && subComponents[k].hasChanges != 0; */
        return result;
      }
      /*@ assert subComponents[i].hasChanges == 0; */
      i = (i + 1);
    }
  /*@ assert i == subComponents_len; */
  /*@ assert result == 1 ==> (\forall integer k; 0 <= k < subComponents_len ==> subComponents[k].hasChanges == 0); */
  /*@ assert result == 0 ==> (\exists integer k; 0 <= k < subComponents_len && subComponents[k].hasChanges != 0); */
  return result;  // Dafny implicit return
}