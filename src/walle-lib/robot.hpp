#pragma once 

#include "environnement.hpp"
#include "element.hpp"
/// Décrire un objet.
class Robot : public MovableElement
{
/// tout le monde peut utiliser (même l'extérieur
public:
    Robot(Environment* e=nullptr) : MovableElement(e) {}

    void stop();

    /// Met à jour le robot en fonction du temps écoulé depuis la dernière mise à jour.
    void run(double dt);

};


