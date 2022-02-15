#include <iostream>

class Character {
protected:
    std::string name;
    int level;
public:
    Character(std::string name = "undefined", int level = -1) {
        this->name = name;
        this->level = level;
    }

    std::string getName() {
        return this->name;
    }

    int getLevel() {
        return this->level;
    }

    friend std::ostream& operator<<(std::ostream& os, Character& Character) {
        os << "Character: " << Character.name << " | level: " << Character.level << '\n';
        return os;
    }
};

class Beginner : public Character {
protected:
    std::string skill_1;
public:
    Beginner(std::string name, int level, std::string skill_1): Character{name, level} {
        this->skill_1 = skill_1;
    }

    std::string getName() {
        return this->name;
    }

    int getLevel() {
        return this->level;
    }

    std::string getSkill_1() {
        return this->skill_1;
    }

    friend std::ostream& operator<<(std::ostream& os, Beginner& beginner) {
        os << "this character: " << beginner.name << " | leve: " << beginner.level << " is a begginer and chose the skill " << beginner.skill_1 << '\n';
        return os;
    }
};

class Intermediary : Beginner {
protected:
    std::string skill_2;
public:
    Intermediary(std::string name, int level, std::string skill_1, std::string skill_2) : Beginner{name,level,skill_1} {
        this->skill_2 = skill_2;
    }

    std::string getName() {
        return Character::getName();
    }

    friend std::ostream& operator<<(std::ostream& os, Intermediary& intermediary) {
        os << "this character: " << intermediary.name << " | leve: " << intermediary.level << " is a begginer and chose the skills: " << intermediary.skill_1 << " and " << intermediary.skill_2 << '\n';
        return os;
    }


};

int main() {
    Intermediary joao{"joao", 10, "fireboll", "healer"};
    std::cout << joao;
    //std::cout << joao.getName();
    return 0;
}