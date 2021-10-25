#include <AnchoredSpring.h>

AnchoredSpring::AnchoredSpring() : AnchoredSpring(Vector3D(), 1.0f, 1.0f) {}
AnchoredSpring::AnchoredSpring(Vector3D anchorPoint, float k, float l0) : m_anchorPoint(anchorPoint), m_k(k), m_l0(l0) {}

void AnchoredSpring::updateForce(Particle* particle, float duration)
{
	// l is the spring stretching so the distance beetween the particle and the anchor point
	Vector3D distance = particle->getPosition() - m_anchorPoint;

	// Now we compute the value of the force add it to the particle
	// To compute the force we calculate the force's value and apply it to the distance's unit vector
	//F = k(l0 - l)
	particle->addForce(distance.normalize() * (m_k * (m_l0 - distance.norm())));
}
