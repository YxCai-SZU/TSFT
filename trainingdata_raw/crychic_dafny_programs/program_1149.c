// Generated C + ACSL

typedef enum {
  LOAD_DISTRIBUTION_UNIFORM,
  LOAD_DISTRIBUTION_TRAPEZOIDAL
} LoadDistribution;

typedef struct {
  int magnitude;
  LoadDistribution loadDistribution;
} ForceData;

/*@
    requires magnitude != 0;
    assigns force->magnitude, force->loadDistribution;
    ensures force->magnitude == magnitude;
    ensures force->loadDistribution == LOAD_DISTRIBUTION_UNIFORM;
*/
void ApplyUniformForce(ForceData *force, int magnitude)
{
  force->magnitude = magnitude;
  force->loadDistribution = LOAD_DISTRIBUTION_UNIFORM;
}

/*@
    requires magnitude1 != 0 || magnitude2 != 0;
    requires distanceA >= 0 && distanceB >= 0;
    requires distanceA < distanceB;
    assigns force->magnitude, force->loadDistribution;
*/
void ApplyTrapezoidalForce(ForceData *force, int magnitude1, int magnitude2, int distanceA, int distanceB, int isRelative)
{
  force->magnitude = magnitude1;
  force->loadDistribution = LOAD_DISTRIBUTION_TRAPEZOIDAL;
}

/*@
  predicate IsValid(integer no, integer loadCaseNo, integer memberSets_len) =
    no > 0 && loadCaseNo > 0 && memberSets_len > 0;
*/