#include "car.hpp"
#include <array>
#include <iostream>
#include <vector>

namespace CAR_RENTAL {
class CarRental {
private:
  std::vector<CAR_RENTAL::Car> car_data_set_;
  std::vector<CAR_RENTAL::Car> filtered_car_data_set_;
  std::string car_data_set_file_path_;

public:
  CarRental(std::string car_data_set_file_path);
  ~CarRental();

  void ReadCarDataSet();

  void PrintCarDataSet();

  void FilterCarDataSet(std::string filter_type, std::string filter_value);

  void ResetFilteredCarDataSet();

  void RentCar(int car_id, int renter_id);

  void ReturnCar(int car_id);
};
} // namespace CAR_RENTAL