#include "../header_files/car_rental.hpp"
#include <iostream>

void PrintMenu() {
  std::cout << "1. Add a car" << std::endl;
  std::cout << "2. Remove a car" << std::endl;
  std::cout << "3. Rent a car" << std::endl;
  std::cout << "4. Return a car" << std::endl;
  std::cout << "5. See the car table" << std::endl;
  std::cout << "6. Filter the car table" << std::endl;
  std::cout << "7. Reset the filtered car table" << std::endl;
  std::cout << "8. Exit" << std::endl;
}

void RentCar(CAR_RENTAL::CarRental &car_rental) {
  int car_id{0};
  int renter_id{0};
  std::cout << "Please enter the car id: ";
  std::cin >> car_id;
  std::cout << "Please enter the renter id: ";
  std::cin >> renter_id;
  car_rental.RentCar(car_id, renter_id);
  std::cout << "The car with id " << car_id
            << " has been rented by renter with id " << renter_id << std::endl;
}

void ReturnCar(CAR_RENTAL::CarRental &car_rental) {
  int car_id{0};
  std::cout << "Please enter the car id: ";
  std::cin >> car_id;
  car_rental.ReturnCar(car_id);
  std::cout << "The car with id " << car_id << " has been returned."
            << std::endl;
}

void FilterCarDataSet(CAR_RENTAL::CarRental &car_rental) {
  std::string filter_type{""};
  std::string filter_value{""};
  std::cout << "Please enter the filter type: ";
  std::cin >> filter_type;
  std::cout << "Please enter the filter value: ";
  std::cin >> filter_value;
  car_rental.FilterCarDataSet(filter_type, filter_value);
  std::cout << "The car table has been filtered." << std::endl;
}

void ResetFilteredCarDataSet(CAR_RENTAL::CarRental &car_rental) {
  car_rental.ResetFilteredCarDataSet();
  std::cout << "The filtered car table has been reset." << std::endl;
}

void PrintCarDataSet(CAR_RENTAL::CarRental &car_rental) {
  car_rental.PrintCarDataSet();
}

void Exit() {
  std::cout << "Thank you for using the Car Rental System!" << std::endl;
}

void AddCar(CAR_RENTAL::CarRental &car_rental) {
  int id{0};
  std::string type{""};
  std::string manufacturer{""};
  std::string model{""};
  int year{0};
  std::string color{""};
  int mileage{0};
  int price_per_day{0};
  std::string last_rented{""};
  bool is_available{false};
  int renter_id{0};
  std::cout << "Please enter the car id: ";
  std::cin >> id;
  std::cout << "Please enter the car type: ";
  std::cin >> type;
  std::cout << "Please enter the car manufacturer: ";
  std::cin >> manufacturer;
  std::cout << "Please enter the car model: ";
  std::cin >> model;
  std::cout << "Please enter the car year: ";
  std::cin >> year;
  std::cout << "Please enter the car color: ";
  std::cin >> color;
  std::cout << "Please enter the car mileage: ";
  std::cin >> mileage;
  std::cout << "Please enter the car price per day: ";
  std::cin >> price_per_day;
  std::cout << "Please enter the car last rented: ";
  std::cin >> last_rented;
  std::cout << "Please enter the car is available: ";
  std::cin >> is_available;
  std::cout << "Please enter the car renter id: ";
  std::cin >> renter_id;
  CAR_RENTAL::Car car(id, type, manufacturer, model, year, color, mileage,
                      price_per_day, last_rented, is_available, renter_id);
  car_rental.AddCar(car);
  std::cout << "The car with id " << id << " has been added." << std::endl;
}

void RemoveCar(CAR_RENTAL::CarRental &car_rental) {
  int id{0};
  std::cout << "Please enter the car id: ";
  std::cin >> id;
  car_rental.RemoveCar(id);
  std::cout << "The car with id " << id << " has been removed." << std::endl;
}

int main(int argc, char *argv[]) {
  int choice{0};
  CAR_RENTAL::CarRental car_rental(argv[1]);
  std::cout << "Welcome to the Car Rental System!" << std::endl;
  while (choice != 8) {
    PrintMenu();
    std::cout << "Please enter your choice: ";
    std::cin >> choice;
    switch (choice) {
    case 1:
      AddCar(car_rental);
      break;
    case 2:
      RemoveCar(car_rental);
      break;
    case 3:
      RentCar(car_rental);
      break;
    case 4:
      ReturnCar(car_rental);
      break;
    case 5:
      PrintCarDataSet(car_rental);
      break;
    case 6:
      FilterCarDataSet(car_rental);
      break;
    case 7:
      ResetFilteredCarDataSet(car_rental);
      break;
    case 8:
      Exit();
      break;
    }
  }

  return 0;
}