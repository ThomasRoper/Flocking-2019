#ifndef FLOCK_H
#define FLOCK_H

#include <glm/vec3.hpp>
#include <boid.h>
#include <vector>
class Flock// : public Boid
{
public:
    Flock();
    Flock(glm::vec3 pos);
    ~Flock();
    void addNewBoid(glm::vec3 pos);
    void deleteBoid();
    void setWeights();
    void update();
    void setBoidView(float theta, float r);
private:
    glm::vec3 m_flockAveragePos;
    glm::vec3 m_leaderPos;
    glm::vec3 m_flockAverageVel;
    //arrays to store all the positions
    glm::vec3 m_flockPos;
    glm::vec3 m_flockVel;

    std::vector<Boid> m_boidsInFlock;


};

#endif // FLOCK_H
