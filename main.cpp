#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
using namespace std;
enum class CarStatus { AVAILABLE, RENTED, IN_REPAIR };

struct Car {
    int carID;
    string brand;
    string model;
    CarStatus status;
    string description;
};

struct RentalHistory {
    int rentalID;
    int carID;
    string rentalDate;
    string endrent;
};

class ECars {
private:
    vector<Car> cars;


public:
    vector<RentalHistory> rentalHistory;

   bool isInRepair(const Car& car) {
    return car.status == CarStatus::IN_REPAIR;
}

    void remove_car(int carid){
        int i=0;bool test=false;
        for(auto &car : cars){
                i++;
            if(car.carID==carid){
                    test=true;
                 cars.erase(cars.begin()+i);
        cout<<"car removed successsfully!!"<<endl;
            }
        }if(test==false) cout<<"car not found !!"<<endl;
    }

    void show_history(int carid){
      for(auto &rh : rentalHistory){
        if(rh.carID==carid) cout<<"rental date : "<<rh.rentalDate<<"     "<<"end of rent : "<<rh.endrent<<endl;
      }
    }
    void aff_desc(int carid){
        for(auto &car : cars){
                if(car.carID==carid) cout<<car.description<<endl;
        }
    }
    void addCar(int carID, const string &brand, const string &model, CarStatus status,string description) {
        cars.push_back({carID, brand, model, status,description});
        cout << "Voiture ajoutee avec succes." << endl;
    }

    void rentCar(int carID, const string &rentalDate, const string &endrent) {
        for (auto &car : cars) {
            if (car.carID == carID) {
                if (car.status == CarStatus::AVAILABLE) {
                    rentalHistory.push_back({static_cast<int>(rentalHistory.size()) + 1, carID, rentalDate,endrent});
                    car.status = CarStatus::RENTED;
                    cout << "Voiture louée avec succès." <<endl;
                    return;
                } else {
                    cout << "Cette voiture n'est pas disponible pour la location." << endl;
                    return;
                }
            }
        }
        cout << "Voiture introuvable." << endl;
    }
    void modify_description(int carid, string desc ){
        bool test=false;
        for(auto car : cars){
            if(car.carID==carid){
                test=true;
                string *p=&car.description,*d=&desc;
                *p=*d;
                cout<<"description modified for the car with the id : "<<carid<<endl;
            }
        }
    }
    void reclamation(int carid){
        for(auto car : cars){
            if(car.carID==carid && car.status== CarStatus::RENTED){
                car.status=CarStatus::IN_REPAIR;
                cout<<"reclamation de la voiture de ID= "<<carid<<"   ajoutee avec success"<<endl;

            }
        }
    }


};

int main() {
    ECars eCars;

    eCars.addCar(1, "Toyota", "Corolla", CarStatus::AVAILABLE,"aa");
    eCars.addCar(2, "Honda", "Civic", CarStatus::AVAILABLE,"az");

    eCars.rentCar(1, "2023-12-16","2023-12-18");

    eCars.aff_desc(1);
    eCars.show_history(1);
    eCars.addCar(3, "polo", "polo7", CarStatus::IN_REPAIR,"nn");
    eCars.remove_car(1);
    eCars.remove_car(178);
    eCars.modify_description(1,"azzerrty");
    eCars.rentCar(1,"2023-12-17","2023-12-17");
    eCars.reclamation(1);


    return 0;
}
