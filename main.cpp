#include <iostream>
#include <string>
using namespace std;
class Flat;
const unsigned maxSize = 3;
unsigned currentSize = 0;
Flat* items[maxSize];

class Flat {
    const int index;
    float price;
    std::string address;
    int floor;
    int number;
    float square;
public:

    Flat(int index, float price, const std::string& address, int floor, int number, float square ) : index(index) {
        this->address = address;
        this->price = price;
        this->floor = floor;
        this->number = number;
        this->square = square;
    }
    Flat(const Flat& other) : index(other.index) { // не особо осознаю синтаксис
        this->address = other.address;
        this->price = other.price;
        this->floor = other.floor;
        this->number = other.number;
        this->square = other.square;

    }
    ~Flat() {
        /* nothing to do here */
    }
    Flat& operator=(const Flat& other) {
        if (this == &other) {                    //защита от присваивания самому себе
            return *this;
        }

        //index = other.index; 
        address = other.address;
        price = other.price;
        floor = other.floor;
        number = other.number;
        square = other.square;


        return *this;
    }

    friend istream& operator>>(std::istream& input, Flat& flat) {
        /*...>>( 1)ссылка на cin или др станд  поток ввода
         2)ссылка на объект куда помещаем данные){...*/
        char buf[128]={0};
        input.getline(buf,128);
        flat.address = std::string(buf);
        input>>flat.price;
        while(flat.price<0 ){
            cout<<"Try again"<<std::endl;
            input>>flat.price;
        }
        input>>flat.square;
        while(flat.square<0){
            cout<<"Try again"<<std::endl;
            input>>flat.square;
        }
        input>>flat.number;
        while(flat.number<0 || flat.number % 1!=0 ){
            cout<<"Try again"<<std::endl;
            input>>flat.number;
        }
        input>>flat.floor;
        while(flat.floor<0 || flat.floor % 1!=0 ){
            cout<<"Try again"<<std::endl;
            input>>flat.floor;
        }
        return input;
    }
};



 
//void add(Flat* item) {
//    if (currentSize < maxSize) {
//        items[currentSize] = item;
//        currentSize++;
//    }
//}
/*void add(int value) {
    if (currentSize < maxSize) {
        Flat* elem = new Flat(currentSize, value);
        items[currentSize] = elem;
        currentSize++;
    }
}
void clear() {
    for (int i = 0; i < currentSize; i++) {
        delete items[i];
        items[i] = nullptr;
    }
}
*/


// void add(int value) {
//     if (Flat::currentSize < K) {
//         items[Flat::currentSize] = new Flat(Flat::currentSize, value);
//         Flat::currentSize++;
//     }
// }

/*Flat* create(std::istream & input) {
    cout << ">>";
    
    int age = 0;
    input >> age;
    if (age < 0) {
        cout << "Bad input" << endl;
        return nullptr;
    }
    return new Flat(currentSize, age);
}
*/


int main() {
    
//    Flat b {0, 20 };
//    Flat a = Flat(b); //copy constructor
   // Flat c;
   // c = a = b;        //operator=()


    Flat test(0,0,"",0,0,0);

    cin >> test;

    //if (test.successInput()) {
    //    add(test);
    //}
    
    /*while (true) {
        Flat* test = create(cin);
        if (test != nullptr) {
            add(test);
        }
    }
   
*/


    return 0;
}
