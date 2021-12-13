#pragma once
#include <Contact.h>
#include <vector>
#include <Common.h>
class CollisionData
{
public:
	CollisionData(int maxContact = 4);

	vector<Contact> GetContacts() { return m_contacts; };
	int GetMaxContacts() { return m_maxContacts; };

	void AddContacts(Contact contact) { m_contacts.push_back(contact); };
	void ClearContacts() { m_contacts.clear(); };



private:
	vector<Contact> m_contacts;
	int m_maxContacts;
};

