#include "../header_files/car_rental.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>  // for std::transform
#include <cctype>     // for std::tolower

CAR_RENTAL::CarRental::CarRental(std::string car_data_set_file_path)
{
    car_data_set_file_path_ = car_data_set_file_path;
    ReadCarDataSet();
}

CAR_RENTAL::CarRental::~CarRental()
{
    std::cout << "CarRental destructor called" << std::endl;
}


void CAR_RENTAL::CarRental::ReadCarDataSet()
{
    std::ifstream file(car_data_set_file_path_);

    // Check if the file is open
    if (!file.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
        exit(1);
    }

    std::string line;
    
    // Skip the first line which contains the column names
    std::getline(file, line);
    while (std::getline(file, line))
    {
        // A stringstream to split the line into individual values
        std::istringstream ss(line);
        std::string value;

        std::array<std::string, 11> values;
        int array_pos = 0;
        // Loop through each value in the line
        while (std::getline(ss, value, ';'))
        {
            values[array_pos] = value;
            array_pos++;
        }

        if (array_pos != 11) {
            std::cerr << "A line in the file doesn't have 10 values!" << std::endl;
            exit(1);
        }

        // Create a new car object
        CAR_RENTAL::Car car(std::stoi(values[0]), values[1], values[2], values[3], std::stoi(values[4]), values[5], std::stoi(values[6]), std::stoi(values[7]), values[8], std::stoi(values[9]), std::stoi(values[10]));

        car_data_set_.push_back(car);

    }

    // Close the file
    file.close();
}

void CAR_RENTAL::CarRental::PrintCarDataSet()
{
    std::vector<CAR_RENTAL::Car> dataset_to_print;
    // Check if the filtered car data set is empty
    if (filtered_car_data_set_.empty()) {
        dataset_to_print = car_data_set_;
    }
    else {
        dataset_to_print = filtered_car_data_set_;
    }
    for (CAR_RENTAL::Car car : dataset_to_print) {
        std::cout << "id: \t\t" << car.GetId() << std::endl;
        std::cout << "type: \t\t" << car.GetType() << std::endl;
        std::cout << "manufacturer: \t" << car.GetManufacturer() << std::endl;
        std::cout << "model: \t\t" << car.GetModel() << std::endl;
        std::cout << "year: \t\t" << car.GetYear() << std::endl;
        std::cout << "color: \t\t" << car.GetColor() << std::endl;
        std::cout << "mileage: \t" << car.GetMileage() << std::endl;
        std::cout << "price_per_day: \t" << car.GetPricePerDay() << std::endl;
        std::cout << "last_rented: \t" << car.GetLastRented() << std::endl;
        std::cout << "is_available: \t" << car.GetIsAvailable() << std::endl;
        std::cout << "renter_id: \t" << car.GetRenterId() << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << std::endl;
    }
}

void CAR_RENTAL::CarRental::FilterCarDataSet(std::string filter_type, std::string filter_value)
{
    std::transform(filter_type.begin(), filter_type.end(), filter_type.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    std::vector<CAR_RENTAL::Car> dataset_to_filter;
    // Check if the filtered car data set is empty
    if (filtered_car_data_set_.empty()) {
        dataset_to_filter = car_data_set_;
    }
    else {
        dataset_to_filter = filtered_car_data_set_;
    }

    // Clear the filtered car data set
    filtered_car_data_set_.clear();

    for (CAR_RENTAL::Car car : dataset_to_filter)
    {
        if (filter_type == "id") {
            if (car.GetId() == std::stoi(filter_value)) {
                filtered_car_data_set_.push_back(car);
            }
        }
        else if (filter_type == "type") {
            if (car.GetType() == filter_value) {
                filtered_car_data_set_.push_back(car);
            }
        }
        else if (filter_type == "manufacturer") {
            if (car.GetManufacturer() == filter_value) {
                filtered_car_data_set_.push_back(car);
            }
        }
        else if (filter_type == "model") {
            if (car.GetModel() == filter_value) {
                filtered_car_data_set_.push_back(car);
            }
        }
        else if (filter_type == "year") {
            if (car.GetYear() == std::stoi(filter_value)) {
                filtered_car_data_set_.push_back(car);
            }
        }
        else if (filter_type == "color") {
            if (car.GetColor() == filter_value) {
                filtered_car_data_set_.push_back(car);
            }
        }
        else if (filter_type == "mileage") {
            if (car.GetMileage() == std::stoi(filter_value)) {
                filtered_car_data_set_.push_back(car);
            }
        }
        else if (filter_type == "price_per_day") {
            if (car.GetPricePerDay() == std::stoi(filter_value)) {
                filtered_car_data_set_.push_back(car);
            }
        }
        else if (filter_type == "last_rented") {
            if (car.GetLastRented() == filter_value) {
                filtered_car_data_set_.push_back(car);
            }
        }
        else if (filter_type == "is_available") {
            if (car.GetIsAvailable() == std::stoi(filter_value)) {
                filtered_car_data_set_.push_back(car);
            }
        }
        else if (filter_type == "renter_id") {
            if (car.GetRenterId() == std::stoi(filter_value)) {
                filtered_car_data_set_.push_back(car);
            }
        }
        else {
            std::cerr << "Invalid filter type!" << std::endl;
        }
    }
}

void CAR_RENTAL::CarRental::ResetFilteredCarDataSet()
{
    filtered_car_data_set_.clear();
    std::cout << "Filtered car data set has been reset!" << std::endl;
}

void CAR_RENTAL::CarRental::RentCar(int car_id, int renter_id)
{
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
    for (CAR_RENTAL::Car& car : car_data_set_) {
        if (car.GetId() == car_id) {
            car.SetRented(renter_id);
        }
    }

}

void CAR_RENTAL::CarRental::ReturnCar(int car_id){
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
    for (CAR_RENTAL::Car& car : car_data_set_) {
        if (car.GetId() == car_id) {
            car.SetAvailable();
        }
    }

}
