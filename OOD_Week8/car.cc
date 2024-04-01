#include "car.h"
#include "door.h"
#include "wheel.h"
#include "roof.h"


Car::Car(Part* door, Part* wheel, Part* roof, std::string color)
         : door_(door), wheel_(wheel), roof_(roof), color_(color) {}


Car::Car(const Car& car) {
    if (car.door_ != nullptr) {
        door_ = new Door(car.door_->factory_name());
    }

    if (car.wheel_ != nullptr) {
        wheel_ = new Wheel(car.wheel_->factory_name());
    }

    if (car.roof_ != nullptr) {
        roof_ = new Roof(car.roof_->factory_name());
    }

    color_ = car.color_;
}

Car& Car::operator=(const Car& car) {
    if (this != &car) {
        delete door_;
        delete wheel_;
        delete roof_;

        door_ = new Door(car.door_->factory_name());
        wheel_ = new Wheel(car.wheel_->factory_name());
        roof_ = new Roof(car.roof_->factory_name());
        color_ = car.color_;
    }
    return *this;
}


Car::~Car() {
    delete door_;
    delete wheel_;
    delete roof_;
}

std::string Car::GetSpec() const {
    std::string spec = "Car(";

    if (door_ != nullptr) {
        spec += door_->GetInfo();
    }
    if (roof_ != nullptr) {
        if (door_ != nullptr) {
            spec += ", ";
        }
        spec += roof_->GetInfo();
    }
    if (wheel_ != nullptr) {
        if (door_ != nullptr || roof_ != nullptr) {
            spec += ", ";
        }
        spec += wheel_->GetInfo();
    }
    if (!color_.empty()) {
        if (door_ != nullptr || roof_ != nullptr || wheel_ != nullptr) {
            spec += ", ";
        }
        spec += color_;
    }
    spec += ")";
    return spec;
}
