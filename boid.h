#ifndef BOID_H
#define BOID_H

#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <iostream>
#include <stdlib.h>
#include <vector>

#include <GL/glut.h>



class Boid// : public Flock
{
public:
        Boid(glm::vec3 pos);
        ~Boid();
        void Update();
        glm::vec3 Seperation(std::vector<Boid>& Flock);
        glm::vec3 Cohesion(std::vector<Boid>& Flock);
        glm::vec3 Alignment(std::vector<Boid>& Flock);
        glm::vec3 WeightRulesets();
        glm::vec3 seek (glm::vec3 target);
        void applyForce(glm::vec3 force);
        void drawBoid();
        void stayInWalls();
        void seekTest();
        float RandomFloat(float a, float b);
        glm::vec3 getPos(){return m_pos;}
        glm::vec3 getVel(){return m_vel;}
private:

        glm::vec3 m_pos;
        glm::vec3 m_vel;
        glm::vec3 m_rot;
        glm::vec3 m_acceleration;
        //maxspeed
        float maxspeed = 0.02;
        //max turning force
        float maxforce = 0.0002;
        float m_boundingbox = 2.0;
        float pointx = 1.25;
        float pointy = 1.25;
        float m_sepAmount = 0.3;
        float m_size = 0.05;
        float m_sight = 0.8;

};

#endif // BOID_H
