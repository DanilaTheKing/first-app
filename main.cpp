#include <iostream>

class Item {
    const int index;
    int value;
public:
    static int currentSize;
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

        //index = other.index; //�� ����� ������� ���������
        value = other.value;

        return *this;
    }
};

const unsigned K = 10;
Item* items[K];
int Item::currentSize = 0;

//void add(Item* item) {
//	if (currentSize < K) {
//		items[currentSize] = item;
//		currentSize++;
//	}
//}
void add(int value) {
    if (Item::currentSize < K) {
        items[Item::currentSize] = new Item(Item::currentSize, value);
        Item::currentSize++;
    }
}
void clear() {
    for (int i = 0; i < Item::currentSize; i++) {
        delete items[i];
        items[i] = nullptr;
    }
}

Item createTest() {
    Item tmp(0, 1);
    return tmp;
}


struct Test {
    int value1;
    int value2;
    Test() {
        value1 = value2 = 1;
    }
    Test(int v) {
        value1 = v;
        value2 = 2;
    }
    Test(int v1, int v2) {
        value1 = v1;
        value2 = v2;
    }
}


int main() {

    Test t0;
    Test t1 = Test(10);
    Test t2 = Test(10, 20);
    Test t3(10);
    Test t4(10, 20);

    std::cout << t0.value1 << std::endl;

    Test* pointer = &t0; //&t0 - взять адрес переменной t0
    std::cout << pointer->value1 << std::endl;


    /*
        clone
        pull
        commit
        push


        https://ravesli.com/urok-133-peregruzka-operatorov-vvoda-i-vyvoda/

    */

    add(100);
    add(200);

    Item &a = *items[0];
    Item &b = *items[1];
    a = b;

    clear();
    return 0;
}
