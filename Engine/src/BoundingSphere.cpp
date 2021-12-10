#include "BoundingSphere.h"

BoundingSphere::BoundingSphere(RigidBody* rigidBody): m_center(rigidBody->GetMassCenter()), m_radius(rigidBody->GetMaxDimension()), m_rigidBody(rigidBody) {}