//Avleen Gill - COMSC 210 Lab 20
//edit chair maker demo code

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
const int SIZE = 3;
const int MIN = 10000, MAX = 99999;

class Chair {
    private:
    int legs;
    double * prices;
    public:
    // constructors
    //CHANGE #1------------------------------------------------
    Chair() {
        prices = new double[SIZE];
        legs = rand() % (4-3+1) + 3;
        for (int i = 0; i < SIZE; i++){
            double price = (rand() % (MAX-MIN+1) + MIN) / (double) 100;
            prices[i] = price;
        }
    }
    //CHANGE #2--------------------------------------------------
    Chair(int l, const double arr[SIZE]) { //arr values do not need to be changed
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
            prices[i] = arr[i];
    }
    // setters and getters
    void setLegs(int l) { legs = l; }   
    int getLegs() { return legs; }

    void setPrices(double p1, double p2, double p3) {
        prices[0] = p1; prices[1] = p2; prices[2] = p3;
    }
    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }
    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: " ;
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};
int main() {
    cout << fixed << setprecision(2);
    srand(time(0));

    //creating pointer to first chair object
    Chair *chairPtr = new Chair;
    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    chairPtr->print();

    //creating dynamic chair object with constructor
    double pricesarr[SIZE] = {500.00, 233.89, 109.38};
    Chair *livingChair = new Chair(3, pricesarr); //parameters changed in class, so must change here too----------
    livingChair->setPrices(525.25, 434.34, 252.52);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    //creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];
    //CHANGE #3------------------------------------------------------------
    //deleted collection calling each setter in order for it to use default constructor
    for (int i = 0; i < SIZE; i++)
        collection[i].print();

    return 0;
}
