#ifndef BULLETCREATURE_H
#define BULLETCREATURE_H

// C++
#include <iostream>
#include <vector>
// External
#include <btBulletDynamicsCommon.h>
// Internal
#include "Creature.h"

class BulletCreature {
public:
    BulletCreature(Creature*);
    void UpdateMotors(const vector<float>& input);

private:
    std::vector<btRigidBody*> m_bodies_;
    std::vector<btHingeConstraint*> m_joints_;
    Creature* blueprint_;
};


#endif // BULLETCREATURE_H
