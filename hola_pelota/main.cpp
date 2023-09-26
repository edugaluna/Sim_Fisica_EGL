/*
 * EDUARDO GARCIA LUNA
-Ejercicio práctico del día de hoy:
Crear una SImulación en la cual una pelota de 1m de radio sea lanzada a un angulo de 75° con una Velocidad de 20 Km/h
 */
#include <iostream>
#include <BOX2D/box2d.h>

int main() {
    //se establece gravedad
    b2Vec2 gravity(0.0f,-9.81f);
    //establecer la gravedad al mundo
    b2World world(gravity);

    //definir el cuerpo (pelota)
    b2BodyDef bodyDef;
    //se define el tipo de cuerpo en este caso dinamico
    bodyDef.type = b2_dynamicBody;
    //poner la posicion al cuerpo
    bodyDef.position.Set(0.0f,4.0f);

    //Se coloca el cuerpo en el mundo
    b2Body* body = world.CreateBody(&bodyDef);
    //Se declara la forma al cuerpo
    b2CircleShape ballShape;
    //Establece la forma al cuerpo
    ballShape.m_radius = 1.0f;

    b2FixtureDef ballFixtureDef;//define las caracteristicas de la bola
    //aplicar la forma de la bola al cuerpo
    ballFixtureDef.shape = &ballShape;





}
