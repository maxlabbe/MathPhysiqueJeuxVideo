#include "CollisionData.h"

CollisionData::CollisionData(int maxContact = 4) : m_contacts(vector<Contact>()), m_maxContacts(maxContact){}
