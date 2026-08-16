// Generated C + ACSL

typedef enum {
    Business,
    Residential
} ConsumerType;

typedef struct {
    ConsumerType consumerType;
    int name;
    int createdBy;
    int created;
    int modifiedBy;
    int modified;
} Consumer;

/*@
    assigns \nothing;
    ensures \result != 0;
*/
int Facility(Consumer consumer, int name, int createdBy, int created, int modifiedBy, int modified);

/*@
    assigns \nothing;
    ensures \result != 0;
*/
int FacilityAssoc(int facility);

/*@
    assigns \nothing;
    ensures \result != 0;
*/
int Household(Consumer consumer, int name, int createdBy, int created, int modifiedBy, int modified);

/*@
    assigns \nothing;
    ensures \result != 0;
*/
int HouseholdAssoc(int household);

/*@
    requires \valid(consumer);
    assigns \nothing;
    ensures \result != 0;
*/
int CreateConsumerAssociation(Consumer *consumer)
{
  if ((consumer->consumerType == Business))
  {
    int facility = Facility(*consumer, consumer->name, consumer->createdBy, consumer->created, consumer->modifiedBy, consumer->modified);
    /*@ assert facility != 0; */
    int result = FacilityAssoc(facility);
    /*@ assert result != 0; */
    return result;
  }
  else
  {
    int household = Household(*consumer, consumer->name, consumer->createdBy, consumer->created, consumer->modifiedBy, consumer->modified);
    /*@ assert household != 0; */
    int result = HouseholdAssoc(household);
    /*@ assert result != 0; */
    return result;
  }
}

/*@
    requires \valid(consumer);
    assigns \nothing;
    ensures \result != 0;
*/
int ConnectSignal(Consumer *consumer)
{
  int association = CreateConsumerAssociation(consumer);
  /*@ assert association != 0; */
  return association;
}