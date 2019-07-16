#ifndef FLOCK_H
#define FLOCK_H

#include <glm/vec3.hpp>
#include <boid.h>
#include <vector>
class Flock// : public Boid
{
public:
    Flock();

    ~Flock();
    void addNewBoids(int amount);
    void deleteBoid();
    void setWeights();
    void draw();
    void update();
    void applyBehavior();
    void setBoidView(float theta, float r);
    float RandomFloat(float a, float b);
private:
    glm::vec3 m_flockAveragePos;
    glm::vec3 m_leaderPos;
    glm::vec3 m_flockAverageVel;
    //arrays to store all the positions
    glm::vec3 m_flockPos;
    glm::vec3 m_flockVel;
    float m_boundingbox = 1.2;
    std::vector<Boid> m_Flock;


};

#endif // FLOCK_H
