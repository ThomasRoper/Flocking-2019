#include "boid.h"


Boid::Boid()
{
    //m_pos = pos;
}

Boid::~Boid()
{
    //m_pos = pos;
}



void Boid::seek(glm::vec3 target)
{
    glm::vec3 desired = target - m_pos;
    glm::normalize(desired);
    //std::cout<<desired;
    desired *= maxspeed;
    glm::vec3 steer = desired - m_vel;
    //limit
    if (glm::length(steer) > maxforce)
    {
        steer =  glm::normalize(steer) * maxforce;
    }
    applyForce(steer);

}

void Boid::Update(float theta, float r)
{
    m_vel += m_acceleration;
    if (glm::length(m_vel) > maxspeed)
    {
        m_vel =  glm::normalize(m_vel) * maxspeed;
    }

    m_pos += m_vel;

    std::cout<<"updating m_pos = "<<m_pos.x<<" "<<m_pos.y<<" "<<m_pos.z<<"\n";
    m_acceleration = glm::vec3(0.0,0.0,0.0);
}

void Boid::applyForce(glm::vec3 force)
{
    m_acceleration += force;
    std::cout<<"applying force = "<<force.x<<" "<<force.y<<" "<<force.z<<"\n";
}

void Boid::drawBoid()
{
    float scaler = 0.2;
    glm::vec3 foward = glm::normalize(m_vel);
    glm::vec3 right = glm::cross(m_vel,glm::vec3(0.0,0.0,1.0));
    right = glm::normalize(right);
    glm::vec3 left = -right;


    glBegin(GL_LINES);
    glVertex3f((0.0 * scaler)+m_pos.x,  (0.0 * scaler)+m_pos.y, (0.0 * scaler)+m_pos.z);
    glVertex3f((foward.x * scaler)+m_pos.x,  (foward.y * scaler)+m_pos.y, (0.0 * scaler)+m_pos.z);

    glVertex3f((foward.x * scaler)+m_pos.x,  (foward.y * scaler)+m_pos.y, (0.0 * scaler)+m_pos.z);
    glVertex3f((((foward.x * 0.6) + (right.x * 0.5)) * scaler)+m_pos.x,  (((foward.y * 0.6) + (right.y * 0.5)) * scaler)+m_pos.y, (0.0 * scaler)+m_pos.z);

    glVertex3f((foward.x * scaler)+m_pos.x,  (foward.y * scaler)+m_pos.y, (0.0 * scaler)+m_pos.z);
    glVertex3f((((foward.x * 0.6) + (left.x * 0.5)) * scaler)+m_pos.x,  (((foward.y * 0.6) + (left.y * 0.5)) * scaler)+m_pos.y, (0.0 * scaler)+m_pos.z);


    glEnd();


}

void Boid::stayInWalls()
{
    glm::vec3 desired;

    if (m_pos.x > m_boundingbox )
    {

        std::cout<<"i am over the line\n";
        desired = glm::vec3(-maxspeed,m_vel.y,m_vel.z);

        glm::vec3 steer = desired - m_vel;
        //limit
        if (glm::length(steer) > maxforce)
        {
            steer =  glm::normalize(steer) * maxforce;
        }
        applyForce(steer);

    }else if(m_pos.x < -m_boundingbox)
    {
        std::cout<<"i am over the line\n";
        desired = glm::vec3(maxspeed,m_vel.y,m_vel.z);

        glm::vec3 steer = desired - m_vel;
        //limit
        if (glm::length(steer) > maxforce)
        {
            steer =  glm::normalize(steer) * maxforce;
        }
        applyForce(steer);
    }
    if (m_pos.y > m_boundingbox )
    {

        std::cout<<"i am over the line\n";
        desired = glm::vec3(m_vel.x,-maxspeed,m_vel.z);

        glm::vec3 steer = desired - m_vel;
        //limit
        if (glm::length(steer) > maxforce)
        {
            steer =  glm::normalize(steer) * maxforce;
        }
        applyForce(steer);

    }else if(m_pos.y < -m_boundingbox)
    {
        std::cout<<"i am over the line\n";
        desired = glm::vec3(m_vel.x,maxspeed,m_vel.z);

        glm::vec3 steer = desired - m_vel;
        //limit
        if (glm::length(steer) > maxforce)
        {
            steer =  glm::normalize(steer) * maxforce;
        }
        applyForce(steer);
    }
}

void Boid::seekTest()
{

    if (pointx - 0.1 < m_pos.x && m_pos.x < pointx + 0.1)
    {
        if(pointy - 0.1 < m_pos.y && m_pos.y < pointy + 0.1)
        {
            pointx = RandomFloat(-m_boundingbox,m_boundingbox);
            pointy = RandomFloat(-m_boundingbox,m_boundingbox);
        }
    }

    glm::vec3 point = glm::vec3(pointx,pointy,0);
    //cross
    glBegin(GL_LINES);
    glVertex3f(point.x-0.1,point.y-0.1,0.0);
    glVertex3f(point.x+0.1,point.y+0.1,0.0);
    glVertex3f(point.x+0.1,point.y-0.1,0.0);
    glVertex3f(point.x-0.1,point.y+0.1,0.0);
    glEnd();



    seek(point);


}



float Boid::RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}
















