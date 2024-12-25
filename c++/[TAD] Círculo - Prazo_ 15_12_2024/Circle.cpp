#include <iostream>
#include "Circle.h"

//Implementação das funções-membro

Circle::Circle(){
    m_center = Point(0,0);
    m_radius = 1;
}

Circle::Circle(Point& P, double radius){
    m_center = P;
    m_radius = radius; 
}

void Circle::setRadius(double radius){
    m_radius = radius;
}

void Circle::setCenter(Point& P){
    m_center = P;
}

Point& Circle::getCenter(){
    return m_center;
}

double Circle::getRadius(){
    return m_radius;
}

double Circle::area(){
    return M_PI * pow(m_radius,2);
}

bool Circle::contains(Point& P){
    return (m_center.distance(P)<= m_radius);
}