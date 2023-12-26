#include "../header_files/car_rental.hpp"
#include <iostream>

void PrintMenu(){
    std::cout << "1. Rent a car" << std::endl;
    std::cout << "2. Return a car" << std::endl;
    std::cout << "3. See the car table" << std::endl;
    std::cout << "4. Filter the car table" << std::endl;
    std::cout << "5. Reset the car table" << std::endl;
    std::cout << "6. Exit" << std::endl;
}

void RentCar(CAR_RENTAL::CarRental &car_rental){
    int car_id{0};
    int renter_id{0};
    std::cout << "Please enter the car id: ";
    std::cin >> car_id;
    std::cout << "Please enter the renter id: ";
    std::cin >> renter_id;
    car_rental.RentCar(car_id, renter_id);
    std::cout << "The car with id " << car_id << " has been rented by renter with id " << renter_id << std::endl;
}

void ReturnCar(CAR_RENTAL::CarRental &car_rental){
    int car_id{0};
    std::cout << "Please enter the car id: ";
    std::cin >> car_id;
    car_rental.ReturnCar(car_id);
    std::cout << "The car with id " << car_id << " has been returned." << std::endl;
}

void FilterCarDataSet(CAR_RENTAL::CarRental &car_rental){
    std::string filter_type{""};
    std::string filter_value{""};
    std::cout << "Please enter the filter type: ";
    std::cin >> filter_type;
    std::cout << "Please enter the filter value: ";
    std::cin >> filter_value;
    car_rental.FilterCarDataSet(filter_type, filter_value);
    std::cout << "The car table has been filtered." << std::endl;
}

void ResetFilteredCarDataSet(CAR_RENTAL::CarRental &car_rental){
    car_rental.ResetFilteredCarDataSet();
    std::cout << "The filtered car table has been reset." << std::endl;
}

void PrintCarDataSet(CAR_RENTAL::CarRental &car_rental){
    car_rental.PrintCarDataSet();
}

void Exit(){
    std::cout << "Thank you for using the Car Rental System!" << std::endl;
    exit(0);
}

int main(int argc, char *argv[]){
    int choice{0};
    CAR_RENTAL::CarRental car_rental(argv[1]);
    std::cout << "Welcome to the Car Rental System!" << std::endl;
    while(choice != 6){
        PrintMenu();
        std::cout << "Please enter your choice: ";
        std::cin >> choice;
        switch(choice){
            case 1:
                RentCar(car_rental);
                break;
            case 2:
                ReturnCar(car_rental);
                break;
            case 3:
                car_rental.PrintCarDataSet();
                break;
            case 4:
                FilterCarDataSet(car_rental);
                break;
            case 5:
                ResetFilteredCarDataSet(car_rental);
                break;
            case 6:
                Exit();
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
                break;
        }
        
    }

    return 0;
}