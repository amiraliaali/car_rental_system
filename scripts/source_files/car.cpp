#include "car.hpp"
#include <iostream>

CAR_RENTAL::Car::Car()
    : id_(0), type_(""), manufacturer_(""), model_(""), year_(0), color_(""),
      mileage_(0), price_per_day_(0), last_rented_(""), is_available_(false),
      renter_id_(0) {}

CAR_RENTAL::Car::Car(int id, std::string type, std::string manufacturer,
                     std::string model, int year, std::string color,
                     int mileage, int price_per_day, std::string last_rented,
                     bool is_available, int renter_id)
    : id_(id), type_(type), manufacturer_(manufacturer), model_(model),
      year_(year), color_(color), mileage_(mileage),
      price_per_day_(price_per_day), last_rented_(last_rented),
      is_available_(is_available), renter_id_(renter_id) {}

int CAR_RENTAL::Car::GetId() { return id_; }

std::string CAR_RENTAL::Car::GetType() { return type_; }

std::string CAR_RENTAL::Car::GetManufacturer() { return manufacturer_; }

std::string CAR_RENTAL::Car::GetModel() { return model_; }

int CAR_RENTAL::Car::GetYear() { return year_; }

std::string CAR_RENTAL::Car::GetColor() { return color_; }

int CAR_RENTAL::Car::GetMileage() { return mileage_; }

int CAR_RENTAL::Car::GetPricePerDay() { return price_per_day_; }

std::string CAR_RENTAL::Car::GetLastRented() { return last_rented_; }

bool CAR_RENTAL::Car::GetIsAvailable() { return is_available_; }

int CAR_RENTAL::Car::GetRenterId() { return renter_id_; }

void CAR_RENTAL::Car::SetAvailable() {
  is_available_ = true;
  renter_id_ = 0;
}

void CAR_RENTAL::Car::SetRented(int renter_id) {
  is_available_ = false;
  renter_id_ = renter_id;
}