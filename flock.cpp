#include "flock.h"

Flock::Flock()
{

}



Flock::~Flock()
{

}

void Flock::addNewBoids(int amount)
{
    float spawnArea = 1.9;
    for(int i = 0; i < amount; i++)
    {
        Boid dummy(glm::vec3(RandomFloat(-spawnArea,spawnArea),RandomFloat(-spawnArea,spawnArea),RandomFloat(-spawnArea,spawnArea)));

        m_Flock.push_back(dummy);
        std::cout<<"just pushed back Boid: "<<i+1<<".\n";
    }
}
void Flock::deleteBoid()
{


}

void Flock::draw()
{
    unsigned int sizeOfFlock = m_Flock.size();

    for(int i = 0; i < sizeOfFlock; i++)
    {
        m_Flock[i].drawBoid();
    }
}


void Flock::setWeights()
{

}
void Flock::update()
{

    applyBehavior();
    unsigned int sizeOfFlock = m_Flock.size();

    for(int i = 0; i < sizeOfFlock; i++)
    {
        std::cout<<"Boid "<<i+1<<" ";
        m_Flock[i].Update();
        m_Flock[i].stayInWalls();
        std::cout<<"updated\n";

    }
    std::cout<<"\n\n";
    draw();


}
void Flock::setBoidView(float theta, float r)
{

}
float Flock::RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}


void Flock::applyBehavior()
{
    unsigned int sizeOfFlock = m_Flock.size();

    for(int i = 0; i < sizeOfFlock; i++)
    {
        glm::vec3 seperation = m_Flock[i].Seperation(m_Flock);
        glm::vec3 alignment = m_Flock[i].Alignment(m_Flock);
        glm::vec3 cohesion = m_Flock[i].Cohesion(m_Flock);




        //scale as you like
        seperation *=  1.0;
        alignment *=   0.1;
        cohesion *=    0.1;
       // stayIn *= 0.1;

       m_Flock[i].applyForce(seperation);
       m_Flock[i].applyForce(alignment);
       m_Flock[i].applyForce(cohesion);
       //m_Flock[i].applyForce(stayIn);

    }

}
