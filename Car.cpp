
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Car {
    string make;
    string model;
    int year;
    double mileage;
    bool rented;
  
public:
    Car(string make, string model, int year, double mileage) {
        this->make = make;
        this->model = model;
        this->year = year;
        this->mileage = mileage;
        this->rented = false;
    }
  
    string getMake() {
        return make;
    }
  
    string getModel() {
        return model;
    }
  
    int getYear() {
        return year;
    }
  
    double getMileage() {
        return mileage;
    }
  
    bool isRented() {
        return rented;
    }
  
    void setRented(bool rented) {
        this->rented = rented;
    }
};

class CarHireSystem {
    vector<Car> cars;
  
public:
    void addCar(string make, string model, int year, double mileage) {
        Car car(make, model, year, mileage);
        cars.push_back(car);
    }
  
    void rentCar(string make, string model) {
        for (Car& car : cars) {
            if (car.getMake() == make && car.getModel() == model && !car.isRented()) {
                car.setRented(true);
                cout << "Car rented successfully!" << endl;
                return;
            }
        }
      
        cout << "Car not available for rent." << endl;
    }
  
    void returnCar(string make, string model) {
        for (Car& car : cars) {
            if (car.getMake() == make && car.getModel() == model && car.isRented()) {
                car.setRented(false);
                cout << "Car returned successfully!" << endl;
                return;
            }
        }
      
        cout << "No such rented car found." << endl;
    }
  
    void displayAvailableCars() {
        cout << "Available Cars:" << endl;
      
        for (const Car& car : cars) {
            if (!car.isRented()) {
                cout << "Make: " << car.getMake() << endl;
                cout << "Model: " << car.getModel() << endl;
                cout << "Year: " << car.getYear() << endl;
                cout << "Mileage: " << car.getMileage() << endl;
                cout << "------------------------" << endl;
            }
        }
    }
  
    void displayRentedCars() {
        cout << "Rented Cars:" << endl;
      
        for (const Car& car : cars) {
            if (car.isRented()) {
                cout << "Make: " << car.getMake() << endl;
                cout << "Model: " << car.getModel() << endl;
                cout << "Year: " << car.getYear() << endl;
                cout << "Mileage: " << car.getMileage() << endl;
                cout << "------------------------" << endl;
            }
        }
    }
};

int main() {
    CarHireSystem carHire;

    // Adding sample cars
    carHire.addCar("Toyota", "Camry", 2019, 20000);
    carHire.addCar("Honda", "Civic", 2020, 15000);
    carHire.addCar("Ford", "Mustang", 2018, 30000);

    // Renting a car
    carHire.rentCar("Toyota", "Camry");

    // Displaying available and rented cars
    carHire.displayAvailableCars();
    carHire.displayRentedCars();

    // Returning the rented car
    carHire.returnCar("Toyota", "Camry");

    // Displaying available and rented cars after returning
    carHire.displayAvailableCars();
    carHire.displayRentedCars();

    return 0;
}
