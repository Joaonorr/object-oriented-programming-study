#include "person.hpp"

class Motorcycle {
public:
    Person* person{nullptr};
    int power{1};
    int time{0};

    //Constructor
    Motorcycle(Person* person = nullptr, int power = 1, int time = 0) {
        this->person = person;
        this->power = power;
        this->time = time;
    }

    //verificar se a moto está vazia
    bool empty() {
        if(this->person == nullptr) {
            return true;
        }
        return false;
    }

    //verificar a idade da pessoa
    bool ageVerify(int age) {
        if(age < 18 ) {
            return true;
        }
        std::cout << "age exceeds\n";
        return false;
    }

    //adiconar pessoa
    void enter(Person person) {
        if(this->empty() && this->ageVerify(person.age)) {
            this->person = new Person(person.getName(), person.getAge());
        }
        else if(this->person != nullptr) {
            std::cout << "fail: motorcycle is occupied\n";
        }
    }

    //remover pessoa
    void leave() {
        if(!this->empty() ) {
            delete this->person;
            this->person = nullptr;
        }
        else {
            std::cout << "fail: motorcycle is empty\n";
        }
    }

    //comprar tempo
    void buyTime(int time) {
        this->time += time;
    }

    //fazer a moto se mover (tempo)
    void drive(int time) {
        if(!this->empty() ) {
            this->time -= time;
            if(this->time < 0) {
                this->time = 0;
                std::cout << "fail: time finished\n";
            }
        }
        else {
            std::cout << "fail: motorcycle is empty\n";
        }
    } 

    //fazer a moto buzinar (power)
    void honk() {
        if(!this->empty() ) {
            std::cout << "P";
            for(int i{0}; i < this->power; i++) {
                std::cout << "e";
            }
            std::cout << "m\n";
        }
        else {
            std::cout << "fail: motorcycle is empty\n";
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Motorcycle& motorcycle) {
        os << "power: " << motorcycle.power << ", time: " << motorcycle.time << ", person: ";
        if(motorcycle.person != nullptr) {
            os << *motorcycle.person;
        }
        else {
            os << "null";
        }
        os << '\n';
        return os;
    }
    
};