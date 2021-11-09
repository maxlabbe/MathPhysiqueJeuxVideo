#include "ParticleLink.h"

ParticleLink::ParticleLink(Particle* particle[2]) : p_particle()
{
    p_particle[0] = particle[0];
    p_particle[1] = particle[1];
}

float ParticleLink::currentLength() const
{
    return (p_particle[0]->getPosition() - p_particle[1]->getPosition()).norm();
}

void ParticleLink::addContact(vector<ParticleContact*> contacts)
{
}
