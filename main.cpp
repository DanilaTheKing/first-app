#include <iostream>
using namespace std;

class Item {
    const int index;
    int value;
public:
    Item() 
        : index(0) {
        value = 0;
    }
    Item(int index, int value) : index(index) {
        this->value = value;
    }
    Item(const Item& other) : index(other.index) {
        value = other.value;
    }
    ~Item() {
        /* nothing to do here */
    }
    Item& operator=(const Item& other) {
        if (this == &other) {
            return *this;
        }

        //index = other.index; 
        value = other.value;

        return *this;
    }

    friend istream& operator>>(std::istream& input, Item& point) {
        //...

        return input;
    }
};


 const unsigned maxSize = 3;
 unsigned currentSize = 0;
 Item* items[maxSize];
 
void add(Item* item) {
    if (currentSize < maxSize) {
        items[currentSize] = item;
        currentSize++;
    }
}
void add(int value) {
    if (currentSize < maxSize) {
        Item* elem = new Item(currentSize, value);
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



// void add(int value) {
//     if (Item::currentSize < K) {
//         items[Item::currentSize] = new Item(Item::currentSize, value);
//         Item::currentSize++;
//     }
// }

Item* create(std::istream & input) {
    cout << ">>";
    
    int age = 0;
    input >> age;
    if (age < 0) {
        cout << "Bad input" << endl;
        return nullptr;
    }
    return new Item(currentSize, age);
}



int main() {
    
    Item b { 0, 20 };
    Item a = Item(b); //copy constructor
    Item c;
    c = a = b;        //operator=()


    Item test;
    cin >> test;

    //if (test.successInput()) {
    //    add(test);
    //}
    
    while (true) {
        Item* test = create(cin);
        if (test != nullptr) {
            add(test);
        }
    }
   


    add(10);
    add(20);
    add(30);
    add(40);
    add(50);


    clear();
    return 0;
}
