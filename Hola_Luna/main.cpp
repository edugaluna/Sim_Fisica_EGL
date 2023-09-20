#include <iostream>
#include <BOX2D/box2d.h>

int main() {
    //Establece la gravedad
    b2Vec2 gravity(0.0f, -1.62f);
    //Se le establece la gravedad al mundo
    b2World world(gravity);
    //Definiendo el cuerpo
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);

    //Se crea el cuerpo del objeto
    b2Body* groundBody = world.CreateBody(&groundBodyDef);

    //Al cuerpo se le da forma
    b2PolygonShape groundBox;
    groundBox.SetAsBox(50.0f, 10.0f);//Una unidad equivale a un metro.

    //Caracteristicas del cubo.
    groundBody->CreateFixture(&groundBox, 0.0f);


    //Se define un cuerpo.
    b2BodyDef bodyDef;
    //se define el tipo de cuerpo dinamico(se puede mover).
    bodyDef.type = b2_dynamicBody;
    //Se le establece una posicion al cuerpo.
    bodyDef.position.Set(0.0f, 4.0f);
    //se crea el cuerpo en el entorno, en pocas se coloca dentro del mundo.
    b2Body* body = world.CreateBody(&bodyDef);

    //Se declara el cuerpo para que tenga figura.
    b2PolygonShape dynamicBox;
    //Se establece la figura al cuerpo.
    dynamicBox.SetAsBox(1.0f, 1.0f);

    //se definen las caracteristicas.
    b2FixtureDef fixtureDef;
    //Se le establecen caracteristicas a la figura.
    fixtureDef.shape = &dynamicBox;//Establece forma a la figura.
    fixtureDef.density = 15.63f;//Establece densidad del carburo tungsteno.
    fixtureDef.friction = 0.0f;//Establece la friccion del planeta.

    //Se crea la figura.
    body->CreateFixture(&fixtureDef);

    //Se determina cuanto tiempo se actualizara la figura.
    float timeStep = 1.0f / 60.0f;

    //Ciclos de lectura.
    int32 velocityIterations = 6;
    int32 positionIterations = 2;
    //Actualizar la simulacion (update).
    for (int32 i = 0; i < 60; ++i)
    {
        world.Step(timeStep, velocityIterations, positionIterations);
        b2Vec2 position = body->GetPosition();
        float angle = body->GetAngle();
        printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
    }
}
