#include "../header_files/car_rental.hpp"
#include <algorithm> // for std::transform
#include <cctype>    // for std::tolower
#include <fstream>
#include <iomanip> // for std::setw
#include <iostream>
#include <sstream>
#include <string>

CAR_RENTAL::CarRental::CarRental(std::string car_data_set_file_path) {
  car_data_set_file_path_ = car_data_set_file_path;
  ReadCarDataSet();
}

CAR_RENTAL::CarRental::~CarRental() {
  std::cout << "CarRental destructor called" << std::endl;
}

void CAR_RENTAL::CarRental::ReadCarDataSet() {
  std::ifstream file(car_data_set_file_path_);

  // Check if the file is open
  if (!file.is_open()) {
    std::cerr << "Error opening the file!" << std::endl;
    exit(1);
  }

  std::string line;

  // Skip the first line which contains the column names
  std::getline(file, line);
  while (std::getline(file, line)) {
    // A stringstream to split the line into individual values
    std::istringstream ss(line);
    std::string value;

    std::array<std::string, 11> values;
    int array_pos = 0;
    // Loop through each value in the line
    while (std::getline(ss, value, ';')) {
      values[array_pos] = value;
      array_pos++;
    }

    if (array_pos != 11) {
      std::cerr << "A line in the file doesn't have 11 values!" << std::endl;
      exit(1);
    }

    // Create a new car object
    CAR_RENTAL::Car car(std::stoi(values[0]), values[1], values[2], values[3],
                        std::stoi(values[4]), values[5], std::stoi(values[6]),
                        std::stoi(values[7]), values[8], std::stoi(values[9]),
                        std::stoi(values[10]));

    car_data_set_.push_back(car);
  }

  // Close the file
  file.close();
}

void Lower(std::string &str) {
  std::transform(str.begin(), str.end(), str.begin(),
                 [](unsigned char c) { return std::tolower(c); });
}

void CAR_RENTAL::CarRental::PrintCarDataSet() {
  std::vector<CAR_RENTAL::Car> dataset_to_print;
  // Check if the filtered car data set is empty
  if (filtered_car_data_set_.empty()) {
    dataset_to_print = car_data_set_;
  } else {
    dataset_to_print = filtered_car_data_set_;
  }
  // print the column headers in one line
  std::cout << std::setw(5) << "id"
            << "\t" << std::setw(10) << "type"
            << "\t" << std::setw(15) << "manufacturer"
            << "\t" << std::setw(15) << "model"
            << "\t" << std::setw(5) << "year"
            << "\t" << std::setw(10) << "color"
            << "\t" << std::setw(8) << "mileage"
            << "\t" << std::setw(10) << "price_per_day"
            << "\t" << std::setw(12) << "last_rented"
            << "\t" << std::setw(12) << "is_available"
            << "\t" << std::setw(8) << "renter_id" << std::endl;

  for (CAR_RENTAL::Car car : dataset_to_print) {
    std::cout << std::setw(5) << car.GetId() << "\t" << std::setw(10)
              << car.GetType() << "\t" << std::setw(15) << car.GetManufacturer()
              << "\t" << std::setw(15) << car.GetModel() << "\t" << std::setw(5)
              << car.GetYear() << "\t" << std::setw(10) << car.GetColor()
              << "\t" << std::setw(8) << car.GetMileage() << "\t"
              << std::setw(10) << car.GetPricePerDay() << "\t" << std::setw(12)
              << car.GetLastRented() << "\t" << std::setw(12)
              << car.GetIsAvailable() << "\t" << std::setw(8)
              << car.GetRenterId() << std::endl;
  }
}

void CAR_RENTAL::CarRental::FilterCarDataSet(std::string filter_type,
                                             std::string filter_value) {
  std::transform(filter_type.begin(), filter_type.end(), filter_type.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  std::transform(filter_value.begin(), filter_value.end(), filter_value.begin(),
                 [](unsigned char c) { return std::tolower(c); });

  std::vector<CAR_RENTAL::Car> dataset_to_filter;
  // Check if the filtered car data set is empty
  if (filtered_car_data_set_.empty()) {
    dataset_to_filter = car_data_set_;
  } else {
    dataset_to_filter = filtered_car_data_set_;
  }

  // Clear the filtered car data set
  filtered_car_data_set_.clear();

  for (CAR_RENTAL::Car car : dataset_to_filter) {
    std::string str_filter_value{""};
    if (filter_type == "id") {
      if (car.GetId() == std::stoi(filter_value)) {
        filtered_car_data_set_.push_back(car);
      }
    } else if (filter_type == "type") {
      str_filter_value = car.GetType();
      Lower(str_filter_value);
      if (str_filter_value == filter_value) {
        filtered_car_data_set_.push_back(car);
      }
    } else if (filter_type == "manufacturer") {
      str_filter_value = car.GetManufacturer();
      Lower(str_filter_value);
      if (str_filter_value == filter_value) {
        filtered_car_data_set_.push_back(car);
      }
    } else if (filter_type == "model") {
      str_filter_value = car.GetModel();
      Lower(str_filter_value);
      if (str_filter_value == filter_value) {
        filtered_car_data_set_.push_back(car);
      }
    } else if (filter_type == "year") {
      if (car.GetYear() == std::stoi(filter_value)) {
        filtered_car_data_set_.push_back(car);
      }
    } else if (filter_type == "color") {
      str_filter_value = car.GetColor();
      Lower(str_filter_value);
      if (str_filter_value == filter_value) {
        filtered_car_data_set_.push_back(car);
      }
    } else if (filter_type == "mileage") {
      if (car.GetMileage() == std::stoi(filter_value)) {
        filtered_car_data_set_.push_back(car);
      }
    } else if (filter_type == "price_per_day") {
      if (car.GetPricePerDay() == std::stoi(filter_value)) {
        filtered_car_data_set_.push_back(car);
      }
    } else if (filter_type == "last_rented") {
      str_filter_value = car.GetLastRented();
      Lower(str_filter_value);
      if (str_filter_value == filter_value) {
        filtered_car_data_set_.push_back(car);
      }
    } else if (filter_type == "is_available") {
      if (car.GetIsAvailable() == std::stoi(filter_value)) {
        filtered_car_data_set_.push_back(car);
      }
    } else if (filter_type == "renter_id") {
      if (car.GetRenterId() == std::stoi(filter_value)) {
        filtered_car_data_set_.push_back(car);
      }
    } else {
      std::cerr << "The filter type is not valid!" << std::endl;
      exit(1);
    }
  }
}

void CAR_RENTAL::CarRental::ResetFilteredCarDataSet() {
  filtered_car_data_set_.clear();
}

void CAR_RENTAL::CarRental::RentCar(int car_id, int renter_id) {
  bool car_found = false;
  // Check if the car is available
  for (CAR_RENTAL::Car car : car_data_set_) {
    if (car.GetId() == car_id) {
      car_found = true;
      if (car.GetIsAvailable() == false) {
        std::cerr << "The car is currently not available!" << std::endl;
        exit(1);
      }
    }
  }

  if (car_found == false) {
    std::cerr << "A car with the given id doesn't exist!" << std::endl;
    exit(1);
  }

  // Update the car data set
  for (CAR_RENTAL::Car &car : car_data_set_) {
    if (car.GetId() == car_id) {
      car.SetRented(renter_id);
    }
  }
}

void CAR_RENTAL::CarRental::ReturnCar(int car_id) {
  bool car_found = false;
  // Check if the car exists
  for (CAR_RENTAL::Car car : car_data_set_) {
    if (car.GetId() == car_id) {
      car_found = true;
    }
  }

  if (car_found == false) {
    std::cerr << "A car with the given id doesn't exist!" << std::endl;
    exit(1);
  }

  // Update the car data set
  for (CAR_RENTAL::Car &car : car_data_set_) {
    if (car.GetId() == car_id) {
      car.SetAvailable();
    }
  }
}

void CAR_RENTAL::CarRental::AddCar(CAR_RENTAL::Car car) {
  car_data_set_.push_back(car);
}

void CAR_RENTAL::CarRental::RemoveCar(int car_id) {
  bool car_found = false;
  // Check if the car exists
  for (CAR_RENTAL::Car car : car_data_set_) {
    if (car.GetId() == car_id) {
      car_found = true;
    }
  }

  if (car_found == false) {
    std::cerr << "A car with the given id doesn't exist!" << std::endl;
    exit(1);
  }

  // Remove the car from the car data set
  car_data_set_.erase(
      std::remove_if(car_data_set_.begin(), car_data_set_.end(),
                     [car_id](CAR_RENTAL::Car car) { return car.GetId() == car_id; }),
      car_data_set_.end());
}
