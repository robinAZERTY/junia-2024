#pragma once 

#include "environnement.hpp"
#include "element.hpp"
/// Décrire un objet.
class Robot : public Element
{
/// tout le monde peut utiliser (même l'extérieur
public:
    Robot(Environment* e=nullptr) : Element(e) {}

    void set_linear_speed(double linear_speed);              ///
    void set_angular_speed(double angular_speed);    ///

    double get_linear_speed() const;
    double get_angular_speed() const;

    void stop();

    /// Met à jour la position interne à partir de la position(et angle),
    /// de la vitesse (et vitesse_angulaire) et de dt
    void run(double dt);

    /// retourne la capacity de la batterie.
    // virtual double get_battery_capacity() = 0;

/// moi et mes enfants on peut y accéder
private:
    double m_theta{0};  /// position angulaire

    double linear_speed_{0};/// vitesse linéaire
    double angular_speed_{0};  /// vitesse angulaire

protected:
    Environment* environment {nullptr}; //pointeur
};


