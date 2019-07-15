#ifndef BOID_H
#define BOID_H

#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <iostream>
#include <stdlib.h>

#include <GL/glut.h>



class Boid// : public Flock
{
public:
        Boid();
        ~Boid();
        void Update(float theta, float r);
        void Seperation();
        void Cohesion();
        void Alignment();
        glm::vec3 WeightRulesets();
        void seek (glm::vec3 target);
        void applyForce(glm::vec3 force);
        void drawBoid();
        void stayInWalls();
        void seekTest();
        float RandomFloat(float a, float b);
private:

        glm::vec3 m_pos = glm::vec3(0.0,0.0,0.0);
        glm::vec3 m_vel = glm::vec3(0.015,0.01,0.0);
        glm::vec3 m_rot;
        glm::vec3 m_acceleration;
        //maxspeed
        float maxspeed = 0.02;
        //max turning force
        float maxforce = 0.0001;
        float m_boundingbox = 1.2;
        float pointx = 1.25;
        float pointy = 1.25;
};

#endif // BOID_H
