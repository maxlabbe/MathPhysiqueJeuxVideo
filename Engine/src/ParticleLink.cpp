#include "ParticleLink.h"

float ParticleLink::currentLength() const
{
    float length = 0;
    Vector3D position1 = particle[0]->getPosition();
    Vector3D position2 = particle[1]->getPosition();

    Vector3D v_length = position1 - position2;
    length = v_length.norm();

    return length;
}

void ParticleLink::addContact()
{
}
