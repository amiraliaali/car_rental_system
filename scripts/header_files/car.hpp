#include <iostream>
#include <string>

namespace CAR_RENTAL
{
    class Car
    {
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
        Car() : id_(0), type_(""), manufacturer_(""), model_(""), year_(0), color_(""), mileage_(0), price_per_day_(0), last_rented_(""), is_available_(false), renter_id_(0) {}

        Car(int id, std::string type, std::string manufacturer, std::string model, int year, std::string color, int mileage, int price_per_day, std::string last_rented, bool is_available, int renter_id) : id_(id), type_(type), manufacturer_(manufacturer), model_(model), year_(year), color_(color), mileage_(mileage), price_per_day_(price_per_day), last_rented_(last_rented), is_available_(is_available), renter_id_(renter_id) {}

        int GetId() { return id_; }
        std::string GetType() { return type_; }
        std::string GetManufacturer() { return manufacturer_; }
        std::string GetModel() { return model_; }
        int GetYear() { return year_; }
        std::string GetColor() { return color_; }
        int GetMileage() { return mileage_; }
        int GetPricePerDay() { return price_per_day_; }
        std::string GetLastRented() { return last_rented_; }
        bool GetIsAvailable() { return is_available_; }
        int GetRenterId() { return renter_id_; }

        void SetAvailable() { 
            is_available_ = true;
            renter_id_ = 0; }

        void SetRented(int renter_id) { 
            is_available_ = false;
            renter_id_ = renter_id; }
};
} // namespace CAR_RENTAL