#include <iostream>
#include <string>

namespace CAR_RENTAL {
class Car {
private:
  int id_;
  std::string type_;
  std::string manufacturer_;
  std::string model_;
  int year_;
  std::string color_;
  int mileage_;
  int price_per_day_;
  std::string last_rented_;
  bool is_available_;
  int renter_id_;

public:
  Car();

  Car(int id, std::string type, std::string manufacturer, std::string model,
      int year, std::string color, int mileage, int price_per_day,
      std::string last_rented, bool is_available, int renter_id);

  int GetId();
  std::string GetType();
  std::string GetManufacturer();
  std::string GetModel();
  int GetYear();
  std::string GetColor();
  int GetMileage();
  int GetPricePerDay();
  std::string GetLastRented();
  bool GetIsAvailable();
  int GetRenterId();

  void SetAvailable();

  void SetRented(int renter_id);
};
} // namespace CAR_RENTAL