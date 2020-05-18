#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <memory>
#include <random>
#include <string>
#include <stdlib.h>
#include <conio.h>

using namespace std;
// classes

void timer(double second) {
    clock_t endwait;
    endwait = clock() + second * CLOCKS_PER_SEC;
    while (clock() < endwait) {}
}


class Unit {
protected:
    string name;
    int maxHP;
    int HP;
    int position;
    int dodge;
    int prot;
    int speed;
    int accMod;
    int baseCrit;
    int minDmg;
    int maxDmg;
    int stunResist;
    int turnValue;
    int damage;
    bool isAlive;
    bool isCrusader;
    bool isVestal;
    bool isBoneSoldier;
    bool isBoneDefender;
    bool isWitcher;
    bool isStunned;


public:                                             // constructor
    Unit() {
        name = "Unit";
        maxHP = 0;
        HP = 0;
        dodge = 0;
        prot = 0;
        speed = 0;
        accMod = 0;
        baseCrit = 0;
        minDmg = 0;
        maxDmg = 0;
        stunResist = 0;
        position = 0;
        turnValue = 0;
        damage = 0;
        isAlive = true;
        isCrusader = false;
        isVestal = false;
        isBoneSoldier = false;
        isBoneDefender = false;
        isWitcher = false;
        isStunned = false;
    }
    // get functions
public:
    string getName() {
        return name;
    }
    int getHP() {
        return HP;
    }
    int getDodge() {
        return dodge;
    }
    int getProt() {
        return prot;
    }
    int getSpeed() {
        return speed;
    }
    int getAccMod() {
        return accMod;
    }
    int getBaseCrit() {
        return baseCrit;
    }
    int getMinDmg() {
        return minDmg;
    }
    int getMaxDmg() {
        return maxDmg;
    }
    int getStunResist() {
        return stunResist;
    }
    int getDamage() {
        return damage;
    }
    int getPosition() {
        return position;
    }
    bool getisStunned() {
        return isStunned;
    }
    bool getAlive() {
        return isAlive;
    }
    bool getCrusader() {
        return isCrusader;
    }
    bool getVestal() {
        return isVestal;
    }
    bool getBoneSoldier() {
        return isBoneSoldier;
    }
    bool getBoneDefender() {
        return isBoneDefender;
    }
    bool getWitcher() {
        return isWitcher;
    }
    bool isHPMax(int dif) {
        if (HP+dif <= maxHP && HP > 0) {
            return true;
        }
        else {
            return false;
        }
    }
    int getTurnValue() {
        return turnValue;
    }
    int getMaxHP() {
        return maxHP;
    }

public:                                                 // set functions
    void setName(string tmpName) {
        name = tmpName;
    }
    void setHP(int tmpHP) {
        HP = tmpHP;
    }
    void setPosition(int tmpPosition) {
        position = tmpPosition;
    }
    void setisAlive(bool tmpAlive) {
        isAlive = tmpAlive;
    }
    void setisStunned(bool tmpStunned) {
        isStunned = tmpStunned;
    }
    void setTurnVal(int tmpTVal) {
        turnValue = tmpTVal;
    }
    void setDamage(double tmpDamage) {
        damage = tmpDamage;
    }
    void heal(double heal) {
        HP = HP + heal;
        if (HP >= maxHP) {
            HP = maxHP;
        }
    }
    void setProt(int tmpProt) {
        prot = tmpProt;
    }
    void setAccMod(int tmpAccMod) {
        accMod = tmpAccMod;
    }
    void setDodge(int tmpDodge) {
        dodge = tmpDodge;
    }

public:
    void turnGenerate(int tmpSpeed) {
        int turnGenerated;
        turnGenerated = rand() % 8 + 1;
        turnValue = tmpSpeed + turnGenerated;
    }

};
// Hero
class Hero : public Unit {
protected:
    int deathBlowResist;
    bool underBoFeffect;
    bool underQuenEffect;
public:
    Hero() : Unit() {
        deathBlowResist = 0;
    }
    int getBoF() {
        return underBoFeffect;
    }
    void setBoF(bool bof) {
        underBoFeffect = bof;
    }

    int getQuen() {
        return underQuenEffect;
    }

    void setQuen(bool quen) {
        underQuenEffect = quen;
    }

    int getDeathBlowResist() {
        return deathBlowResist;
    }

    void deathsDoor(shared_ptr<Hero> Hero) {
        int dbs = Hero->getDeathBlowResist();
        int randN;
        Hero->setHP(0);
        randN = rand() % 100;
        if (randN > dbs) {
            Hero->setisAlive(false);
            Hero->setisStunned(false);
            cout << Hero->getName() << " is DEAD!" << endl;
        }
        else {
            cout << Hero->getName() << " has got out of Death's door state! " << endl;
        }
    }


};
class Crusader : public Hero {
protected:
    int BoFcounter;
public:
    Crusader() : Hero() {
        BoFcounter = 0;
        maxHP = 33;
        HP = 33;
        dodge = 5;
        prot = 0;
        speed = 1;
        accMod = 0;
        baseCrit = 3;
        minDmg = 6;
        maxDmg = 12;
        deathBlowResist = 67;
        stunResist = 40;
        isCrusader = true;
        isAlive = true;
        underBoFeffect = false;
    }

    void setBoFcounter(int tmpcounter) {
        BoFcounter = tmpcounter;
    }
    int getBoFcounter() {
        return BoFcounter;
    }


};
class Vestal : public Hero {
public:
    Vestal() {
        maxHP = 24;
        HP = 24;
        dodge = 0;
        prot = 0;
        speed = 4;
        accMod = 0;
        baseCrit = 1;
        minDmg = 4;
        maxDmg = 8;
        deathBlowResist = 77;
        stunResist = 30;
        isVestal = true;
        isAlive = true;
    }
};
// Monster
class Monster : public Unit {
public:
    Monster() : Unit() {
    }
};
class Bone_Soldier : public Monster {
public:
    Bone_Soldier() : Monster() {
        maxHP = 10;
        HP = 10;
        dodge = 10;
        prot = 15;
        speed = 2;
        accMod = 0;
        baseCrit = 0;
        minDmg = 3;
        maxDmg = 8;
        stunResist = 25;
        isBoneSoldier = true;
        isAlive = true;
    }
};
class Bone_Defender : public Monster {
public:
    Bone_Defender() : Monster() {
        maxHP = 22;
        HP = 22;
        dodge = 8;
        prot = 45;
        speed = 1;
        accMod = 0;
        baseCrit = 0;
        minDmg = 2;
        maxDmg = 4;
        stunResist = 45;
        isBoneDefender = true;
        isAlive = true;
    }
};

class Witcher : public Hero {
private:
    int quenCounter;
public:
    Witcher() : Hero() {
        quenCounter = 0;
        maxHP = 28;
        dodge = 7;
        prot = 0;
        speed = 4;
        accMod = 0;
        baseCrit = 3;
        minDmg = 4;
        maxDmg = 12;
        deathBlowResist = 50;
        stunResist = 65;
        isWitcher = true;
        isAlive = true;
        underQuenEffect = false;
    }
    void setQuenCounter(int tmpQuen) {
        quenCounter = tmpQuen;
    }
    int getQuenCounter() {
        return quenCounter;
    }
};

//skills
class StunSkill {

protected:
    bool isStun;
    int stunBase;
public:
    StunSkill() {
        isStun = true;
        stunBase = 0;
    }

    int getStunBase() {
        return stunBase;
    }
};
class Skill {
protected:
    int      dmgMod;
    int      baseAcc;
    double   critMod;
    int      Move;
    int      sList;
    bool isCrusaderSkill;
    bool isVestalSkill;
    bool isBoneDefenderSkill;
    bool isBoneAttackerSkill;
public:

    Skill() {
        dmgMod = 0;
        baseAcc = 0;
        critMod = 0.0;
        Move = 0;
        sList = 0;
        isCrusaderSkill = false;
        isVestalSkill = false;
        isBoneDefenderSkill = false;
        isBoneAttackerSkill = false;
    }

public:                                                     //get functions
    int getDmgMod() {
        return dmgMod;
    }
    int getBaseAcc() {
        return baseAcc;
    }
    double getCritMod() {
        return critMod;
    }
    int getMove() {
        return Move;
    }
    int getList() {
        return sList;
    }
public:                                                     //set functions
    void setList(int tmpList) {
        sList = tmpList;
    }
};
class UtilitySkill : public Skill {
public:
    UtilitySkill() : Skill() {
    }
};


class MoveSkill : public Skill {
public:
    MoveSkill() {
        sList = 13;
        isCrusaderSkill = true;
        isVestalSkill = true;
        isBoneAttackerSkill = true;
        isBoneDefenderSkill = true;
    }
    void HeroSwapPositions(vector<shared_ptr<Hero>>& heroTeam, int movingHero, bool random) {
        if (random == true) {
            int targetDestination = rand() % 4 + 1;
            if (targetDestination == heroTeam.at(movingHero - 1)->getPosition()) {
                HeroSwapPositions(heroTeam, movingHero, random);
            }
            else {
                if (targetDestination < movingHero) {
                    int tempCounter = targetDestination - 1;
                    for (; tempCounter < movingHero - 1; tempCounter++) {
                        cout << "LOG : Changing position of " << heroTeam.at(tempCounter)->getName() << " from " << heroTeam.at(tempCounter)->getPosition() << " to ";
                        heroTeam.at(tempCounter)->setPosition(heroTeam.at(tempCounter)->getPosition() + 1);
                        cout << heroTeam.at(tempCounter)->getPosition() << endl;
                    }
                    heroTeam.insert(heroTeam.begin() + targetDestination - 1, heroTeam.at(movingHero - 1));
                    heroTeam.erase(heroTeam.begin() + movingHero);
                    cout << heroTeam.at(targetDestination - 1)->getName() << " has changed his position from "
                        << movingHero << " to " << targetDestination << endl;
                    heroTeam.at(targetDestination - 1)->setPosition(targetDestination);
                }
                else if (targetDestination > movingHero) {
                    int tempCounter = movingHero;

                    for (; tempCounter < targetDestination; tempCounter++) {
                        cout << "LOG : Changing position of " << heroTeam.at(tempCounter)->getName() << " from " << heroTeam.at(tempCounter)->getPosition() << " to ";
                        heroTeam.at(tempCounter)->setPosition(heroTeam.at(tempCounter)->getPosition() - 1);
                        cout << heroTeam.at(tempCounter)->getPosition() << endl;
                    }
                    heroTeam.insert(heroTeam.begin() + targetDestination, heroTeam.at(movingHero - 1));
                    heroTeam.erase(heroTeam.begin() + movingHero - 1);
                    cout << heroTeam.at(targetDestination - 1)->getName() << " has changed his position from " << movingHero << " to " << targetDestination << endl;
                    heroTeam.at(targetDestination - 1)->setPosition(targetDestination);

                }
            }
        }
        else {
            int targetDestination;
            cout << "You are : " << heroTeam.at(movingHero - 1)->getName() << endl;
            cout << "Your position is : " << heroTeam.at(movingHero - 1)->getPosition() << endl;
            cout << "Where do you want to Move ?" << endl;
            cout << ":";
            cin >> targetDestination;
            if (targetDestination == heroTeam.at(movingHero - 1)->getPosition()) {
                cout << "You cant Move in Yourself... Please Try Again !" << endl;
                cout << "Protip: You should choose between 1-4 except your position ;)" << endl;
                HeroSwapPositions(heroTeam, movingHero, random);
            }
            else if (targetDestination < 1) {
                cout << "Do you try to Move into Void ?" << endl;
                cout << "Protip: You should choose between 1-4 except your position ;)(Void is too cold they say)" << endl;
                HeroSwapPositions(heroTeam, movingHero, random);
            }
            else if (targetDestination > 4) {
                cout << "Rushing the enemy line isn't always a good idea :D Try Again ;)" << endl;
                cout << "Protip: You should choose between 1-4 except your position ;)" << endl;
                HeroSwapPositions(heroTeam, movingHero, random);
            }
            else { // RANDOM DEÐÝLSE
                if (targetDestination < movingHero) {
                    int tempCounter = targetDestination - 1;
                    for (; tempCounter < movingHero - 1; tempCounter++) {
                        cout << "LOG : Changing position of " << heroTeam.at(tempCounter)->getName() << " from " << heroTeam.at(tempCounter)->getPosition() << " to ";
                        heroTeam.at(tempCounter)->setPosition(heroTeam.at(tempCounter)->getPosition() + 1);
                        cout << heroTeam.at(tempCounter)->getPosition() << endl;
                    }
                    heroTeam.insert(heroTeam.begin() + targetDestination - 1, heroTeam.at(movingHero - 1));
                    heroTeam.erase(heroTeam.begin() + movingHero);
                    cout << heroTeam.at(targetDestination - 1)->getName() << " has changed his position from "
                        << movingHero << " to " << targetDestination << endl;
                    heroTeam.at(targetDestination - 1)->setPosition(targetDestination);
                }
                else if (targetDestination > movingHero) {
                    int tempCounter = movingHero;

                    for (; tempCounter < targetDestination; tempCounter++) {
                        cout << "LOG : Changing position of " << heroTeam.at(tempCounter)->getName() << " from " << heroTeam.at(tempCounter)->getPosition() << " to ";
                        heroTeam.at(tempCounter)->setPosition(heroTeam.at(tempCounter)->getPosition() - 1);
                        cout << heroTeam.at(tempCounter)->getPosition() << endl;
                    }
                    heroTeam.insert(heroTeam.begin() + targetDestination, heroTeam.at(movingHero - 1));
                    heroTeam.erase(heroTeam.begin() + movingHero - 1);
                    cout << heroTeam.at(targetDestination - 1)->getName() << " has changed his position from " << movingHero << " to " << targetDestination << endl;
                    heroTeam.at(targetDestination - 1)->setPosition(targetDestination);


                }
            }
        }
    }
    void MonsterSwapPositions(vector<shared_ptr<Monster>>& monsterTeam, int movingMonster, bool random) {
        int targetDestination = rand() % 4 + 1;
        if (targetDestination == monsterTeam.at(movingMonster - 1)->getPosition()) {
            MonsterSwapPositions(monsterTeam, movingMonster, random);
        }
        else {
            if (targetDestination < movingMonster) {
                int tempCounter = targetDestination - 1;
                for (; tempCounter < movingMonster - 1; tempCounter++) {
                    cout << "LOG : Changing position of " << monsterTeam.at(tempCounter)->getName() << " from " << monsterTeam.at(tempCounter)->getPosition() << " to ";
                    monsterTeam.at(tempCounter)->setPosition(monsterTeam.at(tempCounter)->getPosition() + 1);
                    cout << monsterTeam.at(tempCounter)->getPosition() << endl;
                }
                monsterTeam.insert(monsterTeam.begin() + targetDestination - 1, monsterTeam.at(movingMonster - 1));
                monsterTeam.erase(monsterTeam.begin() + movingMonster);
                cout << monsterTeam.at(targetDestination - 1)->getName() << " has changed his position from "
                    << movingMonster << " to " << targetDestination << endl;
                monsterTeam.at(targetDestination - 1)->setPosition(targetDestination);
            }
            else if (targetDestination > movingMonster) {
                int tempCounter = movingMonster;

                for (; tempCounter < targetDestination; tempCounter++) {
                    cout << "LOG : Changing position of " << monsterTeam.at(tempCounter - 1)->getName() << " from " << monsterTeam.at(tempCounter)->getPosition() << " to ";
                    monsterTeam.at(tempCounter)->setPosition(monsterTeam.at(tempCounter)->getPosition() - 1);
                    cout << monsterTeam.at(tempCounter)->getPosition() << endl;
                }
                monsterTeam.insert(monsterTeam.begin() + targetDestination, monsterTeam.at(movingMonster - 1));
                monsterTeam.erase(monsterTeam.begin() + movingMonster - 1);
                cout << monsterTeam.at(targetDestination - 1)->getName() << " has changed his position from " << movingMonster << " to " << targetDestination << endl;
                monsterTeam.at(targetDestination - 1)->setPosition(targetDestination);
            }
        }
    }
};
//Attack Skills
class AttackSkill : public Skill {
public:
    AttackSkill() : Skill() {
    }
};

class Light_Attack : public AttackSkill {
public:
    Light_Attack() : AttackSkill() {
        dmgMod = -40;
        baseAcc = 90;
        critMod = 5.5;
    }
};

class Heavy_Attack : public AttackSkill, public StunSkill {
public:
    Heavy_Attack() : AttackSkill(), StunSkill() {
        dmgMod = -20;
        baseAcc = 90;
        critMod = 0;
        stunBase = 33;
    }
};

class Aard : public AttackSkill, public StunSkill {
public:
    Aard() : AttackSkill(), StunSkill() {
        dmgMod = -20;
        baseAcc = 90;
        critMod = 0;
        stunBase = 30;
    }
};

class Smite : public AttackSkill {
public:
    Smite() : AttackSkill() {

        dmgMod = 0;
        baseAcc = 85;
        critMod = 0;
        sList = 0;
        isCrusaderSkill = true;
    }
};



class Stunning_Blow : public AttackSkill, public StunSkill {
public:
    Stunning_Blow() : AttackSkill(), StunSkill() {
        dmgMod = -50;
        baseAcc = 90;
        critMod = 0;
        stunBase = 100;
        isCrusaderSkill = true;
    }

};

class Holy_Lance : public AttackSkill {
public:
    Holy_Lance() : AttackSkill() {

        dmgMod = 0;
        baseAcc = 85;
        critMod = 0;
        sList = 2;
        isCrusaderSkill = true;

    }
};

class Quen : public UtilitySkill {
public:
    Quen() : UtilitySkill() {

    }
    void quenEffect(shared_ptr<Witcher> Witcher) {
        Witcher->setProt(100);
        Witcher->setQuenCounter(2);
        Witcher->setQuen(true);
        timer(0.9);
        cout << Witcher->getName() << " used Quen!" << endl;
        timer(0.5);
        cout << Witcher->getName() << " has +100 protection now" << endl;
    }
    void endQuen(shared_ptr<Witcher> Witcher) {
        cout << Witcher->getName() << " received a hit and lose the Quen effect" << endl;
    }
    void quenCoolDown(shared_ptr<Witcher> Witcher) {
        if (Witcher->getQuen() > 0 ) {
            cout << endl;
            cout << "Remaining Quen time is for " << Witcher->getQuenCounter() - 1 << " round(s) for " << Witcher->getName() << endl;
            Witcher->setQuenCounter(Witcher->getQuenCounter() - 1);
            if (Witcher->getQuenCounter() == 0) {
                Witcher->setProt(0);
                cout << "Quen effect will end after this turn for " << Witcher->getName() << endl << endl;
                Witcher->setQuen(false);
            }
        }
    }

};
class Bulwark_Of_Faith : public UtilitySkill {
public:

    Bulwark_Of_Faith() : UtilitySkill() {
        sList = 3;
        isCrusaderSkill = true;
    }

    void bofEffect(shared_ptr<Crusader> Crusader) {
        Crusader->setProt(20);
        Crusader->setBoFcounter(3);
        Crusader->setBoF(true);
        timer(0.9);
        cout << Crusader->getName() << " has used Bulwark of Faith!" << endl;
        timer(0.5);
        cout << Crusader->getName() << " has +20 protection now" << endl;
    }

    void bofCooldown(shared_ptr<Crusader> Crusader) {

        if (Crusader->getBoFcounter() > 0) {
            cout << endl;
            cout << "Remaining Bulwark of Faith effect time is " << Crusader->getBoFcounter() - 1 << " round(s) for " << Crusader->getName() << endl;
            Crusader->setBoFcounter(Crusader->getBoFcounter() - 1);
            if (Crusader->getBoFcounter() == 0) {
                Crusader->setProt(Crusader->getProt() - 20);
                cout << "Bulwark of Faith effect will end after this turn  " << Crusader->getName() << endl << endl;
                Crusader->setBoF(false);
            }
        }
    }

};
class Mace_Bash : public AttackSkill {
public:

    Mace_Bash() : AttackSkill() {
        dmgMod = 0;
        baseAcc = 85;
        critMod = 0;
        sList = 4;
        isVestalSkill = true;

    }
};
class Dazzling_Light : public AttackSkill, public StunSkill {
public:
    Dazzling_Light() : AttackSkill(), StunSkill() {
        dmgMod = -75;
        baseAcc = 90;
        critMod = 5;
        stunBase = 100;
        sList = 5;
        isVestalSkill = true;

    }

};
class Divine_Grace : public UtilitySkill {
public:
    Divine_Grace() : UtilitySkill() {
        sList = 6;
        isVestalSkill = true;
    }

    void divineGrace(shared_ptr<Vestal> Vestal, shared_ptr<Hero> TargetHero) {
        int randN;
        randN = rand() % 2 + 4;
        timer(0.8);
        if (Vestal->getPosition() == 3 || Vestal->getPosition() == 4) {
            TargetHero->heal(randN);
            cout << Vestal->getName() << " has casted Divine Grace on ";
            if (TargetHero->getName() == Vestal->getName()) {
                cout << "herself" << endl;
            }
            else {
                cout << TargetHero->getName() << endl;
            }
            timer(0.6);
            cout << TargetHero->getName() << " has " << TargetHero->getHP() << " HP now (" << "+" << randN << ")" << endl;
        }
    }
};
class Divine_Comfort : public UtilitySkill {
public:
    Divine_Comfort() : UtilitySkill() {
        sList = 7;
        isVestalSkill = true;
    }

    void divineComfort(shared_ptr<Vestal> Vestal, vector<shared_ptr<Hero>>& Heroes) {

        int randN;
        timer(0.8);
        if (Vestal->getPosition() == 2 || Vestal->getPosition() == 3 || Vestal->getPosition() == 4) {
            cout << Vestal->getName() << " used Divine Comfort!" << endl << endl;
            timer(0.6);
            for (int i = 0; i < Heroes.size(); i++) {
                if (Heroes.at(i)->getAlive() == true) {
                    randN = rand() % 3 + 1;
                    Heroes.at(i)->heal(randN);
                    cout << Heroes.at(i)->getName() << " has " << Heroes.at(i)->getHP() << " HP now (" << "+" << randN << ")" << endl;
                }
            }

        }
    }

};
class Graveyard_Slash : public AttackSkill {
public:
    Graveyard_Slash() : AttackSkill() {
        dmgMod = 0;
        baseAcc = 85;
        critMod = 6;
        sList = 8;
        isBoneAttackerSkill = true;
    }
};
class Graveyard_Stumble : public AttackSkill {
public:
    Graveyard_Stumble() : AttackSkill() {
        dmgMod = -50;
        baseAcc = 45;
        critMod = 0;
        sList = 9;
        isBoneAttackerSkill = true;
    }
};
class Axeblade : public AttackSkill {
public:
    Axeblade() : AttackSkill() {
        dmgMod = 0;
        baseAcc = 72;
        critMod = 6;
        sList = 10;
        isBoneDefenderSkill = true;
    }
};
class Dead_Weight : public AttackSkill, public StunSkill {
public:
    Dead_Weight() : AttackSkill(), StunSkill() {
        dmgMod = -25;
        baseAcc = 82;
        critMod = 6;
        stunBase = 100;
        sList = 11;
        isBoneDefenderSkill = true;
    }


};
class Knitting_Bones : public UtilitySkill {
public:
    Knitting_Bones() : UtilitySkill() {
        sList = 12;
        isBoneDefenderSkill = true;
    }
    void KnittingBones(shared_ptr<Bone_Defender> BoneDefender, vector<shared_ptr<Monster>> Monsters) {
        int randN;
        int randomTarget;
        int i = 0;
        timer(0.8);
        while (1) {
            randomTarget = rand() % 4;
            if (Monsters.at(randomTarget)->getAlive() && Monsters.at(randomTarget)->isHPMax(2)){
                randN = rand() % 2 + 2;
                Monsters.at(randomTarget)->heal(randN);
                cout << BoneDefender->getName() << " casted Knitting Bones on ";
                if (Monsters.at(randomTarget)->getName() == BoneDefender->getName()) {
                    cout << "itself" << endl;
                }
                else {
                    cout << Monsters.at(randomTarget)->getName() << endl;
                }
                timer(0.8);
                cout << Monsters.at(randomTarget)->getName() << " has " << Monsters.at(randomTarget)->getHP() << " HP now (" << "+" << randN << ")" << endl;
                break;
            }
        }
    }
    void KnittingBones(shared_ptr<Bone_Defender> BoneDefender) {
        
        timer(0.8);
        int randN = rand() % 2 + 2;
        BoneDefender->heal(randN);
        cout << BoneDefender->getName() << " casted Knitting Bones on itself" << endl;
        cout << BoneDefender->getName() << " has " << BoneDefender->getHP() << " HP Now (" << "+" << randN << ")" << endl;

    }

};

double hitChance(shared_ptr<Unit> Attacker, shared_ptr<Unit> Target, shared_ptr<Skill> Skill) {
    double hit = 0.0;
    int randN1;
    int randN2;
    int hitChance;
    int critChance;
    int baseCrit = Attacker->getBaseCrit();
    double critMod = Skill->getCritMod();
    int baseAcc = Skill->getBaseAcc();
    int accMod = Attacker->getAccMod();
    int dodge = Target->getDodge();
    randN1 = rand() % 100;
    randN2 = rand() % 100;

    hitChance = baseAcc + accMod - dodge;
    if (randN1 > hitChance) {
        return hit;
    }
    else {
        hit = 1;
        //Crit vurma ihtimali
        critChance = (double)baseCrit + critMod;
        if (randN2 > critChance) {
            return hit;
        }
        else {
            hit = 2;
            return hit;
        }
    }

}

void dealStunDamage(shared_ptr<Unit> Target, shared_ptr<StunSkill> StunSkill, double hit) {
    int stunResist = Target->getStunResist();
    int stunBase = StunSkill->getStunBase();
    int stunSuccess;
    int randNumber;

    if (hit == 0) {

    }
    else {
        if (hit == 1) {
            stunSuccess = (double)stunBase - (double)stunResist;
        }
        else if (hit == 2) {
            stunSuccess = 20 + (double)stunBase - (double)stunResist;
        }
        randNumber = rand() % 100;

        if (randNumber > stunSuccess) {

        }
        else {
            Target->setisStunned(true);
        }
    }

    if (Target->getisStunned()) {
        cout << Target->getName() << " is STUNNED!" << endl;
    }
    else {
        //    cout << "Failed to STUN!" << endl;
    }

}

void dealDamage(shared_ptr<Unit> Attacker, shared_ptr<Unit> Target, shared_ptr<Skill> Skill, double hit) {
    timer(0.8);
    int dmg;
    int rawDmg;
    int actualDmg;
    int remainHP = Target->getHP();
    int dmgMod = Skill->getDmgMod();
    int maxDmg = Attacker->getMaxDmg();
    int minDmg = Attacker->getMinDmg();
    int prot = Target->getProt();

    if (hit == 0.0) {
        cout << "Missed!" << endl;
    }
    else {
        if (hit == 1.0) {
            cout << "HIT!" << "  ";
            dmg = rand() % (maxDmg - minDmg) + minDmg;
        }
        else if (hit == 2.0) {
            cout << "Critical HIT!" << "  ";
            dmg = 1.5 * (double)maxDmg;
        }

        rawDmg = (double)dmg * (100 + (double)dmgMod) / 100;
        actualDmg = (double)rawDmg - (double)rawDmg * (prot / 100);
        remainHP = (double)remainHP - (double)actualDmg;
        if (remainHP < 0) {
            remainHP = 0;
        }
        Target->setHP(remainHP);
        cout << Target->getName() << " has " << Target->getHP() << " HP left! (" << "-" << actualDmg << ")" << endl;
    }

}

void HolyLanceMove(int AttackerPosition, vector<shared_ptr<Hero>>& Heroes) {

    Heroes.at(AttackerPosition - 1)->setPosition(Heroes.at(AttackerPosition - 1)->getPosition() - 1);
    Heroes.at(AttackerPosition - 2)->setPosition(Heroes.at(AttackerPosition - 2)->getPosition() + 1);
    Heroes.insert(Heroes.begin() + AttackerPosition - 2, Heroes.at(AttackerPosition - 1));
    Heroes.erase(Heroes.begin() + AttackerPosition);
    cout << "LOG: Changed position of " << Heroes.at(AttackerPosition - 1)->getName() << " from "
        << AttackerPosition - 1 << " to " << AttackerPosition << endl;
    cout << Heroes.at(AttackerPosition - 2)->getName() << " has moved 1 unit forward using Holy Lance( from " << AttackerPosition << " to " << AttackerPosition - 1 << " )" << endl;
}

void GraveyardStumbleMove(int AttackerPosition, vector<shared_ptr<Monster>>& Monsters) {

    Monsters.at(AttackerPosition - 1)->setPosition(Monsters.at(AttackerPosition - 1)->getPosition() - 1);
    Monsters.at(AttackerPosition - 2)->setPosition(Monsters.at(AttackerPosition - 2)->getPosition() + 1);
    Monsters.insert(Monsters.begin() + AttackerPosition - 2, Monsters.at(AttackerPosition - 1));
    Monsters.erase(Monsters.begin() + AttackerPosition);
    cout << "LOG: Changed position of " << Monsters.at(AttackerPosition - 1)->getName() << " from "
        << AttackerPosition - 1 << " to " << AttackerPosition << endl;
    cout << Monsters.at(AttackerPosition - 2)->getName() << " has moved 1 unit forward using Graveyard Stumble( from " << AttackerPosition << " to " << AttackerPosition - 1 << " )" << endl;
}

void dots() {
    cout << ".";
    timer(0.45);
    cout << ".";
    timer(0.45);
    cout << ".";
}

void attack(shared_ptr<Unit> Attacker, shared_ptr<Unit> Target, int skillNum, vector<shared_ptr<Hero>>& Hero, vector<shared_ptr<Monster>>& Monster) {

    double Hit = 0;

    //Check class
    bool Crusader = Attacker->getCrusader();
    bool Vestal = Attacker->getVestal();
    bool BoneSoldier = Attacker->getBoneSoldier();
    bool BoneDefender = Attacker->getBoneDefender();
    bool Witcher = Attacker->getWitcher();

    int attPos = Attacker->getPosition();
    int tarPos = Target->getPosition();

    //Smite
    shared_ptr<AttackSkill> attackSmite = make_shared<Smite>();
    //Stunning Blow
    shared_ptr<AttackSkill> attackStunningBlow = make_shared<Stunning_Blow>();
    shared_ptr<StunSkill>   stunStunningBlow = make_shared<Stunning_Blow>();
    //Holy Lance
    shared_ptr<AttackSkill> attackHolyLance = make_shared<Holy_Lance>();
    //Mace Bash
    shared_ptr<AttackSkill> attackMaceBash = make_shared<Mace_Bash>();
    //Dazzling Light
    shared_ptr<AttackSkill> attackDazzlingLight = make_shared<Dazzling_Light>();
    shared_ptr<StunSkill>   stunDazzlingLight = make_shared<Dazzling_Light>();
    //Graveyard Slash
    shared_ptr<AttackSkill> attackGraveyardSlash = make_shared<Graveyard_Slash>();
    //Graveyard Stumble
    shared_ptr<AttackSkill> attackGraveyardStumble = make_shared<Graveyard_Stumble>();
    //Axeblade
    shared_ptr<AttackSkill> attackAxeblade = make_shared<Axeblade>();
    //Dead Weight
    shared_ptr<AttackSkill> attackDeadWeight = make_shared<Dead_Weight>();
    shared_ptr<StunSkill>   stunDeadWeight = make_shared<Dead_Weight>();
    //Light Attack
    shared_ptr<AttackSkill> attackLightAttack = make_shared<Light_Attack>();
    //Heavy Attack
    shared_ptr<AttackSkill> attackHeavyAttack = make_shared<Heavy_Attack>();
    shared_ptr<StunSkill> stunHeavyAttack = make_shared<Heavy_Attack>();
    //Aard
    shared_ptr<AttackSkill> attackAard = make_shared<Aard>();
    shared_ptr<StunSkill> stunAard = make_shared<Aard>();

    //Smite
    if (skillNum == 0) {
        if (Crusader) {
            if ((attPos == 1 || attPos == 2) && (tarPos == 1 || tarPos == 2)) {
                Hit = hitChance(Attacker, Target, attackSmite);
                cout << "Using Smite on " << Target->getName();
                dots();
                cout << endl;
                dealDamage(Attacker, Target, attackSmite, Hit);
                // cout << "Crusader at position " << attPos << " used Smite against " << Target->getName() << " at position " << Target->getPosition() << endl;
            }
            else {}
        }
        else {}
    }

    //Stunning Blow
    else if (skillNum == 1) {
        if (Crusader) {
            if ((attPos == 1 || attPos == 2) && (tarPos == 1 || tarPos == 2)) {
                Hit = hitChance(Attacker, Target, attackStunningBlow);
                cout << "Using Stunning Blow on " << Target->getName();
                dots();
                cout << endl;
                dealDamage(Attacker, Target, attackStunningBlow, Hit);
                dealStunDamage(Target, stunStunningBlow, Hit);
                //  cout << "Crusader at position " << attPos << " used Stunning Blow against " << Target->getName() << " at position " << Target->getPosition() << endl;
            }
            else {}
        }
        else {}
    }

    //Holy Lance
    //Move?
    else if (skillNum == 2) {
        if (Crusader) {
            if ((attPos == 3 || attPos == 4) && (tarPos == 2 || tarPos == 3 || tarPos == 4)) {
                Hit = hitChance(Attacker, Target, attackHolyLance);
                cout << "Using Holy Lance on " << Target->getName();
                dots();
                cout << endl;
                dealDamage(Attacker, Target, attackHolyLance, Hit);
                HolyLanceMove(attPos, Hero);
                cout << "Crusader at position " << attPos << " used Holy Lance against " << Target->getName() << " at position " << Target->getPosition() << endl;
            }
            else {}
        }
        else {}
    }

    //Mace Bash
    else if (skillNum == 4) {
        if (Vestal) {
            if ((attPos == 1 || attPos == 2) && (tarPos == 1 || tarPos == 2)) {
                Hit = hitChance(Attacker, Target, attackMaceBash);
                cout << "Using Mace Bash on " << Target->getName();
                dots();
                cout << endl;
                dealDamage(Attacker, Target, attackMaceBash, Hit);
            }
            else {}
        }
        else {}
    }

    //Dazzling Light
    else if (skillNum == 5) {
        if (Vestal) {
            if ((attPos == 2 || attPos == 3 || attPos == 4) && (tarPos == 1 || tarPos == 2 || tarPos == 3)) {
                Hit = hitChance(Attacker, Target, attackDazzlingLight);
                cout << "Using Dazzling Light on " << Target->getName();
                dots();
                cout << endl;
                dealDamage(Attacker, Target, attackDazzlingLight, Hit);
                dealStunDamage(Target, stunDazzlingLight, Hit);
            }
            else {}
        }
        else {}
    }

    //Graveyard Slash
    else if (skillNum == 8) {
        if (BoneSoldier) {
            if ((attPos == 1 || attPos == 2 || attPos == 3) && (tarPos == 1 || tarPos == 2 || tarPos == 3)) {
                Hit = hitChance(Attacker, Target, attackGraveyardSlash);
                cout << "Using Graveyard Slash on " << Target->getName();
                dots();
                cout << endl;
                dealDamage(Attacker, Target, attackGraveyardSlash, Hit);
            }
            else {}
        }
        else {}
    }

    //Graveyard Stumble
    //Move?
    else if (skillNum == 9) {
        if (BoneSoldier) {
            if ((attPos == 4) && (tarPos == 1 || tarPos == 2)) {
                Hit = hitChance(Attacker, Target, attackGraveyardStumble);
                cout << "Using Graveyard Stumble on " << Target->getName();
                dots();
                cout << endl;
                dealDamage(Attacker, Target, attackGraveyardStumble, Hit);
                GraveyardStumbleMove(attPos, Monster);
            }
            else {}
        }
        else {}
    }

    //Axeblade Attack
    else if (skillNum == 10) {
        if (BoneDefender) {
            if ((attPos == 1 || attPos == 2) && (tarPos == 1 || tarPos == 2)) {
                Hit = hitChance(Attacker, Target, attackAxeblade);
                cout << "Using Axeblade on " << Target->getName();
                dots();
                cout << endl;
                dealDamage(Attacker, Target, attackAxeblade, Hit);
            }
            else {}
        }
        else {}
    }

    //Dead Weight
    else if (skillNum == 11) {
        if (BoneDefender) {
            if ((attPos == 1 || attPos == 2 || attPos == 3) && (tarPos == 1 || tarPos == 2)) {
                Hit = hitChance(Attacker, Target, attackDeadWeight);
                cout << "Using Dead Weight on " << Target->getName();
                dots();
                cout << endl;
                dealDamage(Attacker, Target, attackAxeblade, Hit);
                dealStunDamage(Target, stunDeadWeight, Hit);
            }
            else {}
        }
        else {}
    }
    // Light Attack
    else if (skillNum == 12) {
        if (Witcher) {
            Hit = hitChance(Attacker, Target, attackDeadWeight);
            cout << "Using Light Attack on " << Target->getName();
            dots();
            cout << endl;
            dealDamage(Attacker, Target, attackLightAttack, Hit);
        }
    }
    //Heavy Attack
    else if (skillNum == 13) {
        if (Witcher) {
            Hit = hitChance(Attacker, Target, attackHeavyAttack);
            cout << "Using Heavy Attack on " << Target->getName();
            dots();
            cout << endl;
            dealDamage(Attacker, Target, attackHeavyAttack, Hit);
            dealStunDamage(Target, stunHeavyAttack, Hit);
        }
    }
    //Aard
    else if (skillNum == 14) {
        if (Witcher) {
            if (Monster.at(0)->getAlive() == false && Monster.at(1)->getAlive() == false && Monster.at(2)->getAlive() == false) {
                cout << "Using Aard";
                dots();
                cout << endl << "Cannot found a living target in the range. Aard was uneffective" << endl << endl;
                cout << Attacker->getName() << " says: Fuck. " << endl;
            }
            else {
                for (int i = 0; i < 3; i++) {
                    cout << "Using Aard";
                    dots();
                    cout << endl;
                    if (Monster.at(i)->getAlive()) {
                        Hit = hitChance(Attacker, Monster.at(i), attackAard);
                        dealDamage(Attacker, Monster.at(i), attackAard, Hit);
                        dealStunDamage(Monster.at(i), stunAard, Hit);
                    }

                }
            }
        }
    }

    timer(0.6);
    if (Target->getHP() <= 0) {
        
        if ((Target->getCrusader() || Target->getVestal()) && Hit!=0) {
            for (int i = 0; i < 4; i++) {
                if (Target->getName() == Hero.at(i)->getName()) {
                    // death's door
                    Hero.at(i)->deathsDoor(Hero.at(i));
                }
            }
        }
        else if (Target->getBoneSoldier() || Target->getBoneDefender()) {
            Target->setHP(0);
            Target->setisAlive(false);
            Target->setisStunned(false);
            cout << Target->getName() << " is DEAD!" << endl;
        }
    }

}

void calculateTurnValue(shared_ptr<Unit> u) {
    int generatedValue = rand() % 8 + 1;
    u->setTurnVal((u->getSpeed() + generatedValue));
}

void CrusaderRandomAction(vector<shared_ptr<Hero>>& heroTeam, vector<shared_ptr<Monster>>& monsterTeam, shared_ptr<Crusader> Crusader) {
    int randomNumber = rand() % 100;
    shared_ptr<MoveSkill>moveCrusader = make_shared<MoveSkill>();
    shared_ptr<Bulwark_Of_Faith>bof = make_shared<Bulwark_Of_Faith>();

    if (randomNumber < 10) {        // move skill
        moveCrusader->HeroSwapPositions(heroTeam, Crusader->getPosition(), true);
    } // move skill

    else {       // attack veya utility
        if (Crusader->getPosition() == 1 || Crusader->getPosition() == 2) { // crusader 1 ve 2. pozisyondayken
            int randomAttackSkill = rand() % 2; // smite veya stunning blow arasýndan birini seçer
            if (monsterTeam.at(0)->getAlive() || monsterTeam.at(1)->getAlive()) {
                while (1) {
                    int randomTarget = rand() % 2;
                    if (monsterTeam.at(randomTarget)->getAlive()) {
                        attack(Crusader, monsterTeam.at(randomTarget), randomAttackSkill, heroTeam, monsterTeam);
                        break;
                    } // ölü mü deðil mi kontrol if'i
                } // while döngüsü
            } //target 1 ve 2 yaþýyorsa
            else {
                //    cout << Crusader->getName() << " has used Bulwark of Faith!" << endl;
                bof->bofEffect(Crusader);
            } // 1 ve 2 ölüyse move kullan
        } // crusader 1 ve 2. pozisyondayken
        else if (Crusader->getPosition() == 3 || Crusader->getPosition() == 4) {
            if (monsterTeam.at(1)->getAlive() || monsterTeam.at(2)->getAlive() || monsterTeam.at(3)->getAlive()) {
                while (1) {
                    int randomTarget = rand() % 3 + 1;
                    if (monsterTeam.at(randomTarget)->getAlive()) {
                        attack(Crusader, monsterTeam.at(randomTarget), 2, heroTeam, monsterTeam);
                        break;
                    } // ölü mü deðil mi kontrol if'i
                } // while döngüsü
            } // target 3 ve 4 yaþýyorsa
            else {
                moveCrusader->HeroSwapPositions(heroTeam, Crusader->getPosition(), true);
            }//3 ve 4 ölüyse move kullan
        } // crusader 3 ve 4.pozisyondayken
    } // attack veya utility

}

void VestalRandomAction(vector<shared_ptr<Hero>>& heroTeam, vector<shared_ptr<Monster>>& monsterTeam, shared_ptr<Vestal> Vestal) {
    int randomNumber = rand() % 100;
    shared_ptr<MoveSkill> moveVestal = make_shared<MoveSkill>();
    shared_ptr<Divine_Grace> divGrace = make_shared<Divine_Grace>();
    shared_ptr<Divine_Comfort> divComfort = make_shared<Divine_Comfort>();

    if (randomNumber < 10) {
        moveVestal->HeroSwapPositions(heroTeam, Vestal->getPosition(), true);
    }//move skill kullan
    else {
        if (Vestal->getPosition() == 1) {
            if (monsterTeam.at(0)->getAlive() || monsterTeam.at(1)->getAlive()) {
                while (1) {
                    int randomTarget = rand() % 2;
                    if (monsterTeam.at(randomTarget)->getAlive()) {
                        attack(Vestal, monsterTeam.at(randomTarget), 4, heroTeam, monsterTeam);
                        break;
                    } // eðer hedef canlýysa
                } // while loop
            } // target 1 ve 2 ölü mü deðil mi
            else {
                moveVestal->HeroSwapPositions(heroTeam, Vestal->getPosition(), true);
            } // ölülerse move
        } // 1.pozisyon
        else if (Vestal->getPosition() == 2) {

            while (1) {
                int randomSkill = rand() % 3;
                if (randomSkill == 0 && (monsterTeam.at(0)->getAlive() || monsterTeam.at(1)->getAlive())) { // Mace Bash
                    while (1) {
                        int randomTarget = rand() % 2;
                        if (monsterTeam.at(randomTarget)->getAlive()) {
                            attack(Vestal, monsterTeam.at(randomTarget), 4, heroTeam, monsterTeam);
                            break;
                        }
                    }
                    break;
                }
                else if (randomSkill == 1 && (monsterTeam.at(0)->getAlive() || monsterTeam.at(1)->getAlive() || monsterTeam.at(2)->getAlive())) { // Dazzling Light
                    if (monsterTeam.at(0)->getAlive() || monsterTeam.at(1)->getAlive() || monsterTeam.at(2)->getAlive()) {
                        while (1) {
                            int randomTarget = rand() % 3;
                            if (monsterTeam.at(randomTarget)->getAlive()) {
                                attack(Vestal, monsterTeam.at(randomTarget), 5, heroTeam, monsterTeam);
                                break;
                            }
                        }
                    }
                    break;
                }
                else if (randomSkill == 2) {
                    divComfort->divineComfort(Vestal, heroTeam);
                    break;
                } // utility kullan
            }

        } // 2.pozisyon
        else {

            while (1) {
                int randomSkill = rand() % 3;
                if (randomSkill == 0 && (monsterTeam.at(0)->getAlive() || monsterTeam.at(1)->getAlive() || monsterTeam.at(2)->getAlive())) { // Dazzling Light
                    while (1) {
                        int randomTarget = rand() % 3;
                        if (monsterTeam.at(randomTarget)->getAlive()) {
                            attack(Vestal, monsterTeam.at(randomTarget), 5, heroTeam, monsterTeam);
                            break;
                        } // hedef canlýysa
                    }  // while loop
                    break;
                } // dazzling light
                else if (randomSkill == 1) {
                    while (1) {
                        int randomTarget = rand() % 4;
                        if (heroTeam.at(randomTarget)->getAlive()) {
                            divGrace->divineGrace(Vestal, heroTeam.at(randomTarget));
                            break;
                        } // eðer hedef canlýysa
                    } // while loop
                    break;
                }//divine grace
                else if (randomSkill == 2) {
                    divComfort->divineComfort(Vestal, heroTeam);
                    break;
                }//divine comfort
            }

        }//3 ve 4. pozisyon
    }//attack ya da utility
}

void BoneSoldierRandomAction(vector<shared_ptr<Hero>>& heroTeam, vector<shared_ptr<Monster>>& monsterTeam, shared_ptr<Bone_Soldier> BoneSoldier) {
    int randomNumber = rand() % 100;
    shared_ptr<MoveSkill> moveBoneSol = make_shared<MoveSkill>();
    if (randomNumber < 10) {
        moveBoneSol->MonsterSwapPositions(monsterTeam, BoneSoldier->getPosition(), true);
    }
    else {
        if (BoneSoldier->getPosition() == 1 || BoneSoldier->getPosition() == 2 || BoneSoldier->getPosition() == 3) {
            if (heroTeam.at(1)->getAlive() || heroTeam.at(2)->getAlive() || heroTeam.at(3)->getAlive()) {
                while (1) {
                    int randomTarget = rand() % 3;
                    if (heroTeam.at(randomTarget)->getAlive()) {
                        attack(BoneSoldier, heroTeam.at(randomTarget), 8, heroTeam, monsterTeam);
                        break;
                    }
                }
            }
            else {
                moveBoneSol->MonsterSwapPositions(monsterTeam, BoneSoldier->getPosition(), true);
            }
        }
        else if (BoneSoldier->getPosition() == 4) {
            if (heroTeam.at(1)->getAlive() || heroTeam.at(2)->getAlive()) {
                while (1) {
                    int randomTarget = rand() % 2;
                    if (heroTeam.at(randomTarget)->getAlive()) {
                        attack(BoneSoldier, heroTeam.at(randomTarget), 9, heroTeam, monsterTeam);
                        break;
                    }
                }
            }
            else {
                moveBoneSol->MonsterSwapPositions(monsterTeam, BoneSoldier->getPosition(), true);
            }
        }
    }
}

void BoneDefenderRandomAction(vector<shared_ptr<Hero>>& heroTeam, vector<shared_ptr<Monster>>& monsterTeam, shared_ptr<Bone_Defender> BoneDefender) {
    int randomNumber = rand() % 100;
    shared_ptr<Knitting_Bones> knitBon = make_shared<Knitting_Bones>();
    shared_ptr<MoveSkill> moveBoneDef = make_shared<MoveSkill>();
    if (randomNumber < 10) {
        moveBoneDef->MonsterSwapPositions(monsterTeam, BoneDefender->getPosition(), true);
    }
    else {

        if (BoneDefender->getPosition() == 1 || BoneDefender->getPosition() == 2) {
            int randomSkill = rand() % 2;
            if (randomSkill == 0 && (heroTeam.at(0)->getAlive() || heroTeam.at(1)->getAlive())) {
                while (1) {
                    int randomTarget = rand() % 2;
                    if (heroTeam.at(randomTarget)->getAlive()) {
                        attack(BoneDefender, heroTeam.at(randomTarget), 10, heroTeam, monsterTeam);
                        break;
                    }
                }
            }
            else if (randomSkill == 1 && (heroTeam.at(0)->getAlive() || heroTeam.at(1)->getAlive())) {
                while (1) {
                    int randomTarget = rand() % 2;
                    if (heroTeam.at(randomTarget)->getAlive()) {
                        attack(BoneDefender, heroTeam.at(randomTarget), 11, heroTeam, monsterTeam);
                        break;
                    }
                }
            }
            else {
                moveBoneDef->MonsterSwapPositions(monsterTeam, BoneDefender->getPosition(), true);
            }
        }
        else if (BoneDefender->getPosition() == 3) {
            int randomSkill = rand() % 2;
            if (randomSkill == 0 && (heroTeam.at(0)->getAlive() || heroTeam.at(1)->getAlive())) {
                while (1) {
                    int randomTarget = rand() % 2;
                    if (heroTeam.at(randomTarget)->getAlive()) {
                        attack(BoneDefender, heroTeam.at(randomTarget), 11, heroTeam, monsterTeam);
                        break;
                    }
                }
            }
            else{
                if (BoneDefender->getHP() < 11) {
                    knitBon->KnittingBones(BoneDefender);
                }
                else {
                    if (monsterTeam.at(0)->isHPMax(2) || monsterTeam.at(1)->isHPMax(2) || monsterTeam.at(2)->isHPMax(2) || monsterTeam.at(3)->isHPMax(2)) {
                        knitBon->KnittingBones(BoneDefender, monsterTeam);
                    }
                    else {
                        moveBoneDef->MonsterSwapPositions(monsterTeam, BoneDefender->getPosition(), true);
                    }
                }
                
            }
        }
        else if (BoneDefender->getPosition() == 4) {
            int skillChance = rand() % 100;
            if (BoneDefender->getHP() < 11) {
                knitBon->KnittingBones(BoneDefender);
            }
            else {
                if (monsterTeam.at(0)->isHPMax(2) || monsterTeam.at(1)->isHPMax(2) || monsterTeam.at(2)->isHPMax(2) || monsterTeam.at(3)->isHPMax(2)) {
                    knitBon->KnittingBones(BoneDefender, monsterTeam);
                }
                else {
                    moveBoneDef->MonsterSwapPositions(monsterTeam, BoneDefender->getPosition(), true);
                }

            }
            
        }
    }
}

void CrusaderDisplayActions(vector<shared_ptr<Hero>>& heroTeam, vector<shared_ptr<Monster>>& monsterTeam, int heroPos, shared_ptr<Crusader> Crusader) {
    bool random;
    int input;
    int skillInput;
    int targetInput;
    int choiceDisplay;

    shared_ptr<Bulwark_Of_Faith> bof = make_shared<Bulwark_Of_Faith>();
    shared_ptr<MoveSkill>move = make_shared<MoveSkill>();

    cout << "Which action do you want to select ?" << endl << "1: Act Randomly" << endl << "2: Choose your own path" << endl;
    cin >> choiceDisplay;
    while (1) {
        if (choiceDisplay == 1) {
            random = true;
            break;
        }
        else if (choiceDisplay == 2) {
            random = false;
            break;
        }
        else {
            cout << "Invalid choice please try again : " << endl;
            cin >> choiceDisplay;
        }
    }
    if (!random) { // random olup olmadýðý kontrol edilir.
        if (heroTeam.at(heroPos - 1)->getPosition() < 3 && heroTeam.at(heroPos - 1)->getCrusader() == true && (monsterTeam.at(0)->getAlive() == true || monsterTeam.at(1)->getAlive() == true)) {
            cout << "Displaying actions for Crusader" << endl;
            cout << "Select a skill type to use" << endl;
            cout << "  1. Attack Skill" << endl;
            cout << "  2. Utility Skill" << endl;
            cout << "  3. Move Skill" << endl;
            cin >> input;
        }
        else if (heroTeam.at(heroPos - 1)->getPosition() > 2 && heroTeam.at(heroPos - 1)->getCrusader() == true && (monsterTeam.at(1)->getAlive() == true || monsterTeam.at(2)->getAlive() == true || monsterTeam.at(3)->getAlive() == true)) {
            cout << "Displaying actions for Crusader" << endl;
            cout << "Select a skill type to use" << endl;
            cout << "  1. Attack Skill" << endl;
            cout << "  3. Move Skill" << endl;
            cin >> input;
        }
        else if (heroTeam.at(heroPos - 1)->getPosition() < 3 && heroTeam.at(heroPos - 1)->getCrusader() == true && (monsterTeam.at(0)->getAlive() == false && monsterTeam.at(1)->getAlive() == false)) {
            cout << "Displaying actions for Crusader" << endl;
            cout << "Select a skill type to use" << endl;
            cout << "  2. Utility Skill" << endl;
            cout << "  3. Move Skill" << endl;
            cin >> input;

            if (input < 2 || input>3) {
                while (1) {
                    cout << "Invalid Choice Please Try Again ! : " << endl;
                    cin >> input;
                    if (input == 3 || input == 2) break;
                }
            }
        }
        else if (heroTeam.at(heroPos - 1)->getPosition() > 2 && heroTeam.at(heroPos - 1)->getCrusader() == true && (monsterTeam.at(1)->getAlive() == false && monsterTeam.at(2)->getAlive() == false && monsterTeam.at(3))) {
            cout << "Displaying actions for Crusader" << endl;
            cout << "Select a skill type to use" << endl;
            cout << "  3. Move Skill" << endl;
            cin >> input;

            if (input < 3 || input>3) {
                while (1) {
                    cout << "Invalid Choice Please Try Again ! : " << endl;
                    cin >> input;
                    cout << input << endl;
                    if (input == 3) {
                        break;
                    }
                }
            }
        }
        while (1) {
            if (input == 1) {
                if (heroTeam.at(heroPos - 1)->getPosition() < 3) {
                    cout << "Select an attack skill to use:" << endl;
                    cout << "  1. Smite" << endl;
                    cout << "  2. Stunning Blow" << endl;
                    cin >> skillInput;
                    while (1) { // Skill girdisini kontrol eder
                        if (skillInput == 1 || skillInput == 2) {
                            switch (skillInput) { //Kullanýcýdan alýnan skill inputunu, skill'in orijinal skill numarasýna dönüþtürür
                            case 1:
                                skillInput = 0;
                                break;
                            case 2:
                                skillInput = 1;
                                break;

                            }
                            cout << "Select a target: " << endl;
                            for (int i = 0; i < 2; i++) { // monsterlarý gösterir
                                cout << "  ";
                                if (monsterTeam.at(i)->getAlive()) {
                                    cout << i + 1 << ". " << monsterTeam.at(i)->getName() << endl;
                                }
                                else {
                                    cout << i + 1 << ". " << monsterTeam.at(i)->getName() << " (DEAD)" << endl;
                                }
                            }

                            cin >> targetInput;
                            while (1) { //girilen konumun geçerli olup olmadýðýna bakar
                                if (targetInput == 1 || targetInput == 2) {
                                    while (1) { // seçilen targetýn canlý olup olmadýðýný kontrol eder
                                        if (monsterTeam.at(targetInput - 1)->getAlive()) {
                                            attack(heroTeam.at(heroPos - 1), monsterTeam.at(targetInput - 1),
                                                skillInput, heroTeam, monsterTeam);
                                            break;
                                        }
                                        else {
                                            cout << "Please select a LIVING target";
                                            cin >> targetInput;
                                        }
                                    }
                                    break;
                                }
                                else {
                                    cout << "Please select a VALID target. " << endl;
                                    cin >> targetInput;
                                }
                                break;
                            }
                        }
                        else {
                            cout << "Please enter a VALID skill number." << endl;
                            cin >> skillInput;
                        }
                        break;
                    }
                    break;
                }
                else if (heroTeam.at(heroPos - 1)->getPosition() > 2) {
                    cout << "Select an attack skill to use:" << endl;
                    cout << "  1. Holy Lance" << endl;
                    cin >> skillInput;
                    while (1) {
                        if (skillInput == 1) {
                            switch (skillInput) { //Kullanýcýdan alýnan skill inputunu, skill'in orijinal skill numarasýna dönüþtürür
                            case 1:
                                skillInput = 2;
                                break;
                            }
                            cout << "Select a target: " << endl;
                            for (int i = 1; i < 4; i++) { // monsterlarý gösterir
                                cout << "  ";
                                if (monsterTeam.at(i)->getAlive()) {
                                    cout << i + 1 << ". " << monsterTeam.at(i)->getName() << endl;
                                }
                                else {
                                    cout << i + 1 << ". " << monsterTeam.at(i)->getName() << " (DEAD)" << endl;
                                }
                            }
                            cin >> targetInput;
                            while (1) { //girilen konumun geçerli olup olmadýðýna bakar
                                if (targetInput == 2 || targetInput == 3 || targetInput == 4) {
                                    while (1) { // seçilen targetýn canlý olup olmadýðýný kontrol eder
                                        if (monsterTeam.at(targetInput - 1)->getAlive()) {
                                            attack(heroTeam.at(heroPos - 1), monsterTeam.at(targetInput - 1),
                                                skillInput,
                                                heroTeam, monsterTeam);
                                            break;
                                        }
                                        else {
                                            cout << "Please select a LIVING target";
                                            cin >> targetInput;
                                        }
                                    }
                                    break;
                                }
                                else {
                                    cout << "Please select a VALID target. " << endl;
                                    cin >> targetInput;
                                }

                            }
                            break;
                        }
                        else {
                            cout << "Please enter a VALID skill number." << endl;
                            cin >> skillInput;
                        }
                    }
                    break;
                }
            }
            else if (input == 2) { // Bulwark of Faith ozan help
                if (heroTeam.at(heroPos - 1)->getPosition() < 3) {
                    cout << "Select an utility skill to use:" << endl;
                    cout << " 1. Bulwark of Faith" << endl;
                    cin >> skillInput;
                    while (1) {
                        if (skillInput == 1) {
                            bof->bofEffect(Crusader);
                            //   cout << heroTeam.at(heroPos - 1)->getName() << " has used Bulwark of Faith and gained +20 protection" << endl;
                            break;
                        }
                        else {
                            cout << "Please enter a valid skill number." << endl;
                            cin >> skillInput;
                        }
                    }
                }
                break;
            }
            else if (input == 3) {
                move->HeroSwapPositions(heroTeam, Crusader->getPosition(), false);
                break;
            }
            else {
                cout << "Please enter a VALID skill type number." << endl;
                cin >> input;
            }
        }
    }

    else { // random olursa
        CrusaderRandomAction(heroTeam, monsterTeam, Crusader);
    }
}

void VestalDisplayActions(vector<shared_ptr<Hero>>& heroTeam, vector<shared_ptr<Monster>>& monsterTeam, int heroPos, shared_ptr<Vestal> Vestal) {
    bool random;
    int input;
    int skillInput;
    int targetInput;
    int choiceDisplay;

    shared_ptr<Divine_Grace> divineGrace = make_shared<Divine_Grace>();
    shared_ptr<Divine_Comfort> divineComfort = make_shared<Divine_Comfort>();
    shared_ptr<MoveSkill>move = make_shared<MoveSkill>();

    cout << "Which action do you want to select ?" << endl << "1: Act Randomly" << endl << "2: Choose your own path" << endl;
    cin >> choiceDisplay;
    while (1) {
        if (choiceDisplay == 1) {
            random = true;
            break;
        }
        else if (choiceDisplay == 2) {
            random = false;
            break;
        }
        else {
            cout << "Invalid choice please try again : " << endl;
            cin >> choiceDisplay;
        }
    }
    if (!random) { // random olup olmadýðý kontrol edilir.
        if (heroTeam.at(heroPos - 1)->getPosition() == 1 && heroTeam.at(heroPos - 1)->getVestal() == true && (monsterTeam.at(0)->getAlive() == true || monsterTeam.at(1)->getAlive() == true)) {
            cout << "Displaying actions for Vestal" << endl;
            cout << "Select a skill type to use" << endl;
            cout << "  1. Attack Skill" << endl;
            cout << "  3. Move Skill" << endl;
            cin >> input;
            if (input < 1 || input >3 || input == 2) {
                while (1) {
                    cout << "Invalid Choice Please Try Again ! : " << endl;
                    cin >> input;
                    if (input == 1 || input == 3) break;
                }

            }
        }
        else if (heroTeam.at(heroPos - 1)->getPosition() > 1 && heroTeam.at(heroPos - 1)->getVestal() == true && (monsterTeam.at(0)->getAlive() == true || monsterTeam.at(1)->getAlive() == true || monsterTeam.at(2)->getAlive() == true)) {
            cout << "Displaying actions for Vestal" << endl;
            cout << "Select a skill type to use" << endl;
            cout << "  1. Attack Skill" << endl;
            cout << "  2. Utility Skill" << endl;
            cout << "  3. Move Skill" << endl;
            cin >> input;
        }
        else if (heroTeam.at(heroPos - 1)->getPosition() == 1 && heroTeam.at(heroPos - 1)->getVestal() == true && (monsterTeam.at(0)->getAlive() == false && monsterTeam.at(1)->getAlive() == false)) {
            cout << "Displaying actions for Vestal" << endl;
            cout << "Select a skill type to use" << endl;
            cout << "  3. Move Skill" << endl;
            cin >> input;

            if (input < 3 || input > 3) {
                while (1) {
                    cout << "Invalid Choice Please Try Again ! : " << endl;
                    cin >> input;
                    if (input == 3) break;
                }
            }
        }
        else if (heroTeam.at(heroPos - 1)->getPosition() > 1 && heroTeam.at(heroPos - 1)->getVestal() == true && (monsterTeam.at(0)->getAlive() == false && monsterTeam.at(1)->getAlive() == false && monsterTeam.at(2)->getAlive() == false)) {
            cout << "Displaying actions for Vestal" << endl;
            cout << "Select a skill type to use" << endl;
            cout << "  2. Utility Skill" << endl;
            cout << "  3. Move Skill" << endl;
            cin >> input;

            if (input < 2 || input>3) {
                while (1) {
                    cout << "Invalid Choice Please Try Again ! : " << endl;
                    cin >> input;
                    if (input == 3 || input == 2) {
                        break;
                    }
                }
            }
        }
        while (1) {
            if (input == 1) {
                if (heroTeam.at(heroPos - 1)->getPosition() == 1) {
                    cout << "Select an attack skill to use:" << endl;
                    cout << "  1. Mace Bash" << endl;
                    cin >> skillInput;
                    while (1) { // Skill girdisini kontrol eder
                        if (skillInput == 1) {
                            switch (skillInput) { //Kullanýcýdan alýnan skill inputunu, skill'in orijinal skill numarasýna dönüþtürür
                            case 1:
                                skillInput = 4;
                                break;
                            }
                            cout << "Select a target: " << endl;
                            for (int i = 0; i < 2; i++) { // monsterlarý gösterir
                                cout << "  ";
                                if (monsterTeam.at(i)->getAlive()) {
                                    cout << i + 1 << ". " << monsterTeam.at(i)->getName() << endl;
                                }
                                else {
                                    cout << i + 1 << ". " << monsterTeam.at(i)->getName() << " (DEAD)" << endl;
                                }
                            }

                            cin >> targetInput;
                            while (1) { //girilen konumun geçerli olup olmadýðýna bakar
                                if (targetInput == 1 || targetInput == 2) {
                                    while (1) { // seçilen targetýn canlý olup olmadýðýný kontrol eder
                                        if (monsterTeam.at(targetInput - 1)->getAlive()) {
                                            attack(heroTeam.at(heroPos - 1), monsterTeam.at(targetInput - 1),
                                                skillInput, heroTeam, monsterTeam);
                                            break;
                                        }
                                        else {
                                            cout << "Please select a LIVING target";
                                            cin >> targetInput;
                                        }
                                    }
                                    break;
                                }
                                else {
                                    cout << "Please select a VALID target. " << endl;
                                    cin >> targetInput;
                                }
                                break;
                            }
                        }
                        else {
                            cout << "Please enter a VALID skill number." << endl;
                            cin >> skillInput;
                        }
                        break;
                    }
                    break;
                }
                else if (heroTeam.at(heroPos - 1)->getPosition() == 2) {
                    cout << "Select an attack skill to use:" << endl;
                    if (monsterTeam.at(0)->getAlive() || monsterTeam.at(1)->getAlive()) {
                        cout << "  1. Mace Bash" << endl;
                        cout << "  2. Dazzling Light" << endl;
                    }
                    else {
                        cout << "  2. Dazzling Light" << endl;
                    }
                    cin >> skillInput;

                    while (1) {
                        if ((skillInput == 1 && (monsterTeam.at(0)->getAlive() || monsterTeam.at(1)->getAlive())) || skillInput == 2) {
                            switch (skillInput) { //Kullanýcýdan alýnan skill inputunu, skill'in orijinal skill numarasýna dönüþtürür
                            case 1:
                                skillInput = 4;
                                break;
                            case 2:
                                skillInput = 5;
                                break;
                            }
                            cout << "Select a target: " << endl;
                            if (skillInput == 4) {
                                for (int i = 0; i < 2; i++) { // monsterlarý gösterir
                                    cout << "  ";
                                    if (monsterTeam.at(i)->getAlive()) {
                                        cout << i + 1 << ". " << monsterTeam.at(i)->getName() << endl;
                                    }
                                    else {
                                        cout << i + 1 << ". " << monsterTeam.at(i)->getName() << " (DEAD)" << endl;
                                    }
                                }
                            }
                            else if (skillInput == 5) {
                                for (int i = 0; i < 3; i++) { // monsterlarý gösterir
                                    cout << "  ";
                                    if (monsterTeam.at(i)->getAlive()) {
                                        cout << i + 1 << ". " << monsterTeam.at(i)->getName() << endl;
                                    }
                                    else {
                                        cout << i + 1 << ". " << monsterTeam.at(i)->getName() << " (DEAD)" << endl;
                                    }
                                }


                            }
                            cin >> targetInput;
                            while (1) { //girilen konumun geçerli olup olmadýðýna bakar
                                if (targetInput < 3 && skillInput == 4) {
                                    while (1) { // seçilen targetýn canlý olup olmadýðýný kontrol eder
                                        if (monsterTeam.at(targetInput - 1)->getAlive()) {
                                            attack(heroTeam.at(heroPos - 1), monsterTeam.at(targetInput - 1), skillInput, heroTeam, monsterTeam);
                                            break;
                                        }
                                        else {
                                            cout << "Please select a LIVING target";
                                            cin >> targetInput;
                                        }
                                    }
                                    break;
                                }
                                else if (targetInput < 4 && skillInput == 5) {
                                    while (1) { // seçilen targetýn canlý olup olmadýðýný kontrol eder
                                        if (monsterTeam.at(targetInput - 1)->getAlive()) {
                                            attack(heroTeam.at(heroPos - 1), monsterTeam.at(targetInput - 1), skillInput, heroTeam, monsterTeam);
                                            break;
                                        }
                                        else {
                                            cout << "Please select a LIVING target";
                                            cin >> targetInput;
                                        }
                                    }
                                    break;
                                }
                                else {
                                    cout << "Please select a VALID target. " << endl;
                                    cin >> targetInput;
                                }
                            }
                            break;
                        }
                        else {
                            cout << "Please enter a VALID skill number." << endl;
                            cin >> skillInput;
                        }
                    }
                    break;
                }
                else if (heroTeam.at(heroPos - 1)->getPosition() > 2) {
                    cout << "Select an attack skill to use:" << endl;
                    cout << "  1. Dazzling Light" << endl;
                    cin >> skillInput;
                    while (1) {
                        if (skillInput == 1) {
                            switch (skillInput) { //Kullanýcýdan alýnan skill inputunu, skill'in orijinal skill numarasýna dönüþtürür
                            case 1:
                                skillInput = 5;
                                break;
                            }
                            cout << "Select a target: " << endl;
                            if (skillInput == 4) {
                                for (int i = 0; i < 2; i++) { // monsterlarý gösterir
                                    cout << "  ";
                                    if (monsterTeam.at(i)->getAlive()) {
                                        cout << i + 1 << ". " << monsterTeam.at(i)->getName() << endl;
                                    }
                                    else {
                                        cout << i + 1 << ". " << monsterTeam.at(i)->getName() << " (DEAD)" << endl;
                                    }
                                }
                            }
                            else if (skillInput == 5) {
                                for (int i = 0; i < 3; i++) { // monsterlarý gösterir
                                    cout << "  ";
                                    if (monsterTeam.at(i)->getAlive()) {
                                        cout << i + 1 << ". " << monsterTeam.at(i)->getName() << endl;
                                    }
                                    else {
                                        cout << i + 1 << ". " << monsterTeam.at(i)->getName() << " (DEAD)" << endl;
                                    }
                                }


                            }
                            cin >> targetInput;
                            while (1) { //girilen konumun geçerli olup olmadýðýna bakar
                                if (targetInput < 3 && skillInput == 4) {
                                    while (1) { // seçilen targetýn canlý olup olmadýðýný kontrol eder
                                        if (monsterTeam.at(targetInput - 1)->getAlive()) {
                                            attack(heroTeam.at(heroPos - 1), monsterTeam.at(targetInput - 1), skillInput, heroTeam, monsterTeam);
                                            break;
                                        }
                                        else {
                                            cout << "Please select a LIVING target";
                                            cin >> targetInput;
                                        }
                                    }
                                    break;
                                }
                                else if (targetInput < 4 && skillInput == 5) {
                                    while (1) { // seçilen targetýn canlý olup olmadýðýný kontrol eder
                                        if (monsterTeam.at(targetInput - 1)->getAlive()) {
                                            attack(heroTeam.at(heroPos - 1), monsterTeam.at(targetInput - 1), skillInput, heroTeam, monsterTeam);
                                            break;
                                        }
                                        else {
                                            cout << "Please select a LIVING target";
                                            cin >> targetInput;
                                        }
                                    }
                                    break;
                                }
                                else {
                                    cout << "Please select a VALID target. " << endl;
                                    cin >> targetInput;
                                }
                            }
                            break;
                        }
                        else {
                            cout << "Please enter a VALID skill number." << endl;
                            cin >> skillInput;
                        }
                    }
                    break;
                }
            }
            else if (input == 2) {
                if (heroTeam.at(heroPos - 1)->getPosition() > 2) {
                    cout << "Select an utility skill to use:" << endl;
                    cout << " 1. Divine Grace" << endl;
                    cout << " 2. Divine Comfort" << endl;
                    cin >> skillInput;
                    while (1) {
                        if (skillInput == 1) {
                            int TargetPos;
                            cout << "Select a target Hero to cast Divine Grace on :" << endl;
                            /*   for (int j = 0; j < heroTeam.size(); j++) {
                                   cout << heroTeam.at(j)->getName() << " at position " << heroTeam.at(j)->getPosition() << endl;
                               }*/
                            cin >> TargetPos;
                            if (TargetPos > 0 && TargetPos < 5) {
                                divineGrace->divineGrace(Vestal, heroTeam.at(TargetPos - 1));
                                //    cout << endl << heroTeam.at(heroPos - 1)->getName() << " has used Divine Grace on " << heroTeam.at(TargetPos - 1)->getName() << endl;
                                break;
                            }
                            else {
                                cout << "Please choose a VALID Position" << endl;
                            }
                        }
                        else if (skillInput == 2) {
                            divineComfort->divineComfort(Vestal, heroTeam);
                            //    cout << endl << heroTeam.at(heroPos - 1)->getName() << " has used Divine Comfort" << endl;
                            break;
                        }
                        else {
                            cout << "Please enter a valid skill number." << endl;
                            cin >> skillInput;
                        }
                    }
                }
                else if (heroTeam.at(heroPos - 1)->getPosition() == 2) {
                    cout << "Select an utility skill to use:" << endl;
                    cout << " 1. Divine Comfort" << endl;
                    cin >> skillInput;
                    while (1) {
                        if (skillInput == 1) {
                            divineComfort->divineComfort(Vestal, heroTeam);
                            //     cout << endl << heroTeam.at(heroPos - 1)->getName() << " has used Divine Comfort" << endl;
                            break;
                        }
                        else {
                            cout << "Please enter a valid skill number." << endl;
                            cin >> skillInput;
                        }
                    }
                }
                break;
            }
            else if (input == 3) {
                move->HeroSwapPositions(heroTeam, Vestal->getPosition(), false);
                break;
            }
            else {
                cout << "Please enter a VALID skill type number." << endl;
                cin >> input;
            }
        }
    }

    else { // random olursa
        VestalRandomAction(heroTeam, monsterTeam, Vestal);
    }
}

void WitcherDisplayActions(vector<shared_ptr<Hero>>& heroTeam, vector<shared_ptr<Monster>>& monsterTeam, shared_ptr<Witcher> Witcher) {
    
    int selectedSkill;
    int pos = Witcher->getPosition();
    
    shared_ptr<Quen> quen = make_shared<Quen>();
    shared_ptr<MoveSkill> move = make_shared<MoveSkill>();
    
    
    cout << "Select a skill: " << endl << endl;
    cout << "               Position:           Targets:" << endl;
    cout << "1. Light Attack (1, 2)             (1 or 2)" << endl;
    cout << "2. Heavy Attack (1, 2)             (2 or 3 or 4)" << endl;
    cout << "3. Aard         (2, 3, 4)          (1 and 2 and 3)" << endl;
    cout << "4. Quen         (3, 4)             (SELF)" << endl;
    cout << "5. Move Skill" << endl;
    
    
    while (1){
        cin >> selectedSkill;
        if (selectedSkill == 1 && (pos == 1 || pos == 2) && (monsterTeam.at(0)->getAlive() || monsterTeam.at(1)->getAlive())) {
            cout << "Choose a target: " << endl;
            for (int i = 0; i < 1; i++) {
                cout << i+1 << ". " << monsterTeam.at(i)->getName();
                if (monsterTeam.at(i)->getAlive() == false) {
                    cout << " (DEAD)";
                }
                cout << endl;
            }
            while (1) {
                int selectedTarget;
                cin >> selectedTarget;
                if ((selectedTarget == 1 || selectedTarget == 2) && monsterTeam.at(selectedTarget - 1)->getAlive()) {
                    attack(Witcher, monsterTeam.at(selectedTarget - 1), 12, heroTeam, monsterTeam);
                    break;
                }
                else {
                    cout << "Please select a VALID Target" << endl;
                }
            }
            break;
        }
        else if (selectedSkill == 2 && (pos == 2 || pos == 3 || pos == 4) && (monsterTeam.at(1)->getAlive() || monsterTeam.at(2)->getAlive() || monsterTeam.at(3)->getAlive())) {
            cout << "Choose a target: " << endl;
            for (int i = 1; i < 3; i++) {
                cout << i + 1 << ". " << monsterTeam.at(i)->getName();
                if (monsterTeam.at(i)->getAlive() == false) {
                    cout << " (DEAD)";
                }
                cout << endl;
            }
            while (1) {
                int selectedTarget;
                cin >> selectedTarget;
                if ((selectedTarget == 2 || selectedTarget == 3 || selectedTarget == 4) && monsterTeam.at(selectedTarget - 1)->getAlive()) {
                    attack(Witcher, monsterTeam.at(selectedTarget - 1), 13, heroTeam, monsterTeam);
                    break;
                }
                else {
                    cout << "Please select a VALID Target" << endl;
                }
            }
            break;
        }
        else if (selectedSkill == 3 && (pos == 2 || pos == 3)) {
            // belli bir target olmadýðý için olmayacak yeniden düzenle!!!!
            attack(Witcher, monsterTeam.at(0), 14, heroTeam, monsterTeam);
            break;
        }
        else if (selectedSkill == 4 && (pos == 3 || pos == 4)) {
            quen->quenEffect(Witcher);
            break;
        }
        else if (selectedSkill == 5) {
            move->HeroSwapPositions(heroTeam, Witcher->getPosition(), false);
            break;
        }
        else {
            cout << "Invalid choice. Please try again" << endl;
        }
    }
       
}

void displayUnits(vector<shared_ptr<Hero>>& heroes, vector<shared_ptr<Monster>>& monsters) {
    cout << endl;
    cout << "        4     3     2     1" << "           " << "  1     2     3     4" << endl;
    cout << "       ---   ---   ---   ---" << "           " << "---   ---   ---   ---" << endl;
    cout << "       ";
    for (int i = 3; i >= 0; i--) {
        if (heroes.at(i)->getCrusader()) {
            if (heroes.at(i)->getName() == "William") {
                cout << "WIL";
            }
            else {
                cout << "EZK";
            }

        }
        else {
            if (heroes.at(i)->getName() == "Jeanne") {
                cout << "JEA";
            }
            else {
                cout << "MAR";
            }
        }
        if (heroes.at(i)->getVestal()) {
            if (heroes.at(i)->getisStunned()) {
                cout << "*  ";
            }
            else {
                cout << "   ";
            }
        }
        else {
            if (heroes.at(i)->getBoF()) {
                if (heroes.at(i)->getisStunned()) {
                    cout << "+* ";
                }
                else {
                    cout << "+  ";
                }
            }
            else if (heroes.at(i)->getisStunned()) {
                cout << "*  ";
            }
            else {
                cout << "   ";
            }
        }

    }
    cout << "        ";
    for (int i = 0; i < 4; i++) {
        if (monsters.at(i)->getBoneSoldier()) {
            if (monsters.at(i)->getName() == "Bone Soldier #1") {
                cout << "BS1";
            }
            else {
                cout << "BS2";
            }
        }
        else {
            if (monsters.at(i)->getName() == "Bone Defender #1") {
                cout << "BD1";
            }
            else {
                cout << "BD2";
            }
        }
        if (monsters.at(i)->getisStunned()) {
            cout << "*  ";
        }
        else {
            cout << "   ";
        }
    }
    cout << endl;
    cout << "HP:";
    cout << "     ";
    for (int i = 3; i >= 0; i--) {
        if (heroes.at(i)->getAlive()) {
            if (heroes.at(i)->getHP() < 10) {
                cout << heroes.at(i)->getHP() << " ";
            }
            else {
                cout << heroes.at(i)->getHP();
            }
        }
        else {
            cout << "X ";
        }
        cout << "    ";
    }
    cout << "        ";
    for (int i = 0; i < 4; i++) {
        if (monsters.at(i)->getAlive()) {
            if (monsters.at(i)->getHP() < 10) {
                cout << monsters.at(i)->getHP() << " ";
            }
            else {
                cout << monsters.at(i)->getHP();
            }
        }
        else {
            cout << "X ";
        }
        cout << "    ";
    }
    cout << endl << endl;
}

void stress(vector<shared_ptr<Hero>> heroes, vector<shared_ptr<Monster>> monsters, int &stressLevel, int &rounds) {
    double stressChance;
    int randomStress = rand() % 100;
    int monstersHP = 0;
    if (rounds > 1) {
        for (int i = 0; i < 4; i++) {
            if (monsters.at(i)->getAlive()) {
                monstersHP = monstersHP + monsters.at(i)->getHP();
            }
        }

        stressChance = (double)monstersHP + ((double)rounds * 2.4);
        timer(0.8);
        if (randomStress < stressChance && stressLevel + 2 < rounds) {
            stressLevel++;
            cout << "Stress level has increased! It is now " << stressLevel << endl << endl;
        }
        timer(0.6);
        if (stressLevel > 0) {
            for (int i = 0; i < 4; i++) {
                if (heroes.at(i)->getAlive()) {
                    randomStress = rand() % 100;
                    if (randomStress < stressChance * stressLevel) {
                        timer(1.5);
                        int randomChance = rand() % 100;
                        if (randomChance < 60) {
                            int randomAccMod = rand() % 2 + 1;
                            int newAccMod = heroes.at(i)->getAccMod() - randomAccMod;
                            heroes.at(i)->setAccMod(newAccMod);
                            cout << heroes.at(i)->getName() << "'s accuracy modifier is now " << newAccMod << " (" << "-" << randomAccMod << ")" << endl;
                        }
                        else {
                            int randomDealDamage = rand() % 2 + 1 + stressLevel + rounds;
                            int randomStun = rand() % 100;
                            int randomPercent = rand() % 3 + 6;
                            int heroHP = heroes.at(i)->getHP();
                            int newHP = heroHP - (double) randomDealDamage * randomPercent / 10;
                            if (newHP < 0) {
                                newHP = 0;
                                heroes.at(i)->setHP(newHP);
                            }
                            else {
                                heroes.at(i)->setHP(newHP);
                            }

                            cout << heroes.at(i)->getName() << "'s HP is now " << newHP << " (" << "-" << randomDealDamage * randomPercent / 10 << ")" << endl;

                            if (rounds > 2 && randomStun < (randomDealDamage * stressLevel) / 2) {
                                heroes.at(i)->setisStunned(true);
                                cout << heroes.at(i)->getName() << " is now STUNNED due to stress level " << endl;
                            }
                        }
                    }

                    int newDodge = heroes.at(i)->getDodge() - (stressLevel + 1);
                    heroes.at(i)->setDodge(newDodge);
                }
                else {

                }

            }

            timer(2);
        }
        
    }    
}

void displayTurns(vector<shared_ptr<Unit>> TurnP, int presentIndex) {
    for (int i = presentIndex; i < TurnP.size(); i++) {
        if (i < 7) {
            if (TurnP.at(i + 1)->getAlive()) {
                cout << ">> " << TurnP.at(i + 1)->getName() << endl;
                cout << "                                         ";
                for (int j = i+1; j < TurnP.size(); j++) {
                    if (j < 7) {
                        if (TurnP.at(j + 1)->getAlive()) {
                            cout << ">>> " << TurnP.at(j + 1)->getName();
                            break;
                        }
                    }
                    else {
                        cout << ">>> " << "Next Round";
                    }
                }
                break;
            }
            else {
                continue;
            }
        }
        else {
            cout << ">> Next Round" << endl;
            break;
        }
    }
}

int main() {
    srand(time(NULL));
    int skillInput;
    bool gameOver = false;
    int b;
    system("color 0C");
    int roundCount = 1;
    int stressCount = 0;
    shared_ptr<MoveSkill> MovingSkill = make_shared<MoveSkill>();
    shared_ptr<Bulwark_Of_Faith> bulwarkoffaith = make_shared<Bulwark_Of_Faith>();
    vector<shared_ptr<Hero>> heroes;
    vector<shared_ptr<Monster>> monsters;

    shared_ptr<Crusader> Crusader1 = make_shared<Crusader>();
    Crusader1->setName("William");
    shared_ptr<Crusader> Crusader2 = make_shared<Crusader>();
    Crusader2->setName("Ezekiel");
    shared_ptr<Vestal> Vestal1 = make_shared<Vestal>();
    Vestal1->setName("Jeanne");
    shared_ptr<Vestal> Vestal2 = make_shared<Vestal>();
    Vestal2->setName("Margaret");

    shared_ptr<Bone_Soldier> Bone_Soldier1 = make_shared<Bone_Soldier>();
    Bone_Soldier1->setName("Bone Soldier #1");
    shared_ptr<Bone_Soldier> Bone_Soldier2 = make_shared<Bone_Soldier>();
    Bone_Soldier2->setName("Bone Soldier #2");
    shared_ptr<Bone_Defender> Bone_Defender1 = make_shared<Bone_Defender>();
    Bone_Defender1->setName("Bone Defender #1");
    shared_ptr<Bone_Defender> Bone_Defender2 = make_shared<Bone_Defender>();
    Bone_Defender2->setName("Bone Defender #2");


    Bone_Soldier1->setPosition(1);
    Bone_Defender1->setPosition(2);
    Bone_Soldier2->setPosition(3);
    Bone_Defender2->setPosition(4);

    heroes.push_back(Crusader1);
    heroes.push_back(Crusader2);
    heroes.push_back(Vestal1);
    heroes.push_back(Vestal2);

    Crusader1->setPosition(1);
    Crusader2->setPosition(2);
    Vestal1->setPosition(3);
    Vestal2->setPosition(4);

    monsters.push_back(Bone_Soldier1);
    monsters.push_back(Bone_Defender1);
    monsters.push_back(Bone_Soldier2);
    monsters.push_back(Bone_Defender2);

    vector<shared_ptr<Unit>> TurnPriority;


    TurnPriority.push_back(Vestal1);
    TurnPriority.push_back(Vestal2);
    TurnPriority.push_back(Crusader1);
    TurnPriority.push_back(Crusader2);
    TurnPriority.push_back(Bone_Defender1);
    TurnPriority.push_back(Bone_Defender2);
    TurnPriority.push_back(Bone_Soldier1);
    TurnPriority.push_back(Bone_Soldier2);

    cout << endl << endl << "            " << endl;
    cout << "//----------------------------------------------------------------------------------\\\\" << endl;
    cout << "||                                                                                  ||" << endl;
    cout << "||                                 DARKEST                                          ||" << endl;
    cout << "||                                          DUNGEON                                 ||" << endl;
    cout << "||                                                                                  ||" << endl;
    cout << "\\\\----------------------------------------------------------------------------------//" << endl;
    timer(3.4);

    while (!gameOver) {


        // Checking Units if they're Alive
        system("cls");
        displayUnits(heroes, monsters);
        cout << endl << endl << endl;
        cout << "_______________________________[ " << roundCount << " ]__________________________" << endl;
        timer(2.4);
        if (monsters.at(0)->getAlive() || monsters.at(1)->getAlive() || monsters.at(2)->getAlive() || monsters.at(3)->getAlive()) {
            stress(heroes, monsters, stressCount, roundCount);
        }
        
        // Calculating Turn Values

        for (int i = 0; i < TurnPriority.size(); i++) {
            calculateTurnValue(TurnPriority.at(i));
        }

        // Sorting Values & Classes

        for (int i = 0; i < TurnPriority.size(); i++) {
            for (int j = 0; j < TurnPriority.size() - 1; j++) {
                if (TurnPriority.at(i)->getTurnValue() > TurnPriority.at(j)->getTurnValue()) {
                    shared_ptr<Unit> tmp = make_shared<Unit>();
                    tmp = TurnPriority.at(i);
                    TurnPriority.at(i) = TurnPriority.at(j);
                    TurnPriority.at(j) = tmp;
                }
            }
        }
        // End of Sorting Values & Classes

        // Turns

        for (int i = 0; i < TurnPriority.size(); i++) {
            if (TurnPriority.at(i)->getAlive()) {
                system("cls");
                displayUnits(heroes, monsters);

                cout << endl;
                cout << "Stress: " << stressCount;
                cout << "                                ";
                if (monsters.at(0)->getAlive() || monsters.at(1)->getAlive() || monsters.at(2)->getAlive() || monsters.at(3)->getAlive()) {
                    displayTurns(TurnPriority, i);
                }
                cout << endl;
                cout << "_______________________________[ " << roundCount << " ]__________________________" << endl;

                if (heroes.at(0)->getAlive() == false && heroes.at(1)->getAlive() == false && heroes.at(2)->getAlive() == false && heroes.at(3)->getAlive() == false) {
                    cout << "                             GAME OVER!" << endl;
                    gameOver = true;
                    break;
                }
                if (monsters.at(0)->getAlive() == false && monsters.at(1)->getAlive() == false && monsters.at(2)->getAlive() == false && monsters.at(3)->getAlive() == false) {
                    cout << "                              YOU WON!" << endl;
                    gameOver = true;
                    break;
                }


                if (TurnPriority.at(i)->getAlive() && TurnPriority.at(i)->getisStunned() == false) {


                    cout << TurnPriority.at(i)->getName() << "'s turn" << "            " << endl;
                    cout << "Position: " << TurnPriority.at(i)->getPosition() << endl << endl;
                    timer(1.2);
                    if (TurnPriority.at(i)->getBoneDefender() == true || TurnPriority.at(i)->getBoneSoldier() == true) {
                        if (TurnPriority.at(i)->getBoneSoldier() == true) {
                            if (monsters.at(TurnPriority.at(i)->getPosition() - 1) == Bone_Soldier1) {
                                BoneSoldierRandomAction(heroes, monsters, Bone_Soldier1);
                            }
                            else {
                                BoneSoldierRandomAction(heroes, monsters, Bone_Soldier2);
                            }
                        }
                        else if (TurnPriority.at(i)->getBoneDefender() == true) {
                            if (monsters.at(TurnPriority.at(i)->getPosition() - 1) == Bone_Defender1) {
                                BoneDefenderRandomAction(heroes, monsters, Bone_Defender1);
                            }
                            else {
                                BoneDefenderRandomAction(heroes, monsters, Bone_Defender2);
                            }
                        }
                    }

                    else if (TurnPriority.at(i)->getCrusader() == true || TurnPriority.at(i)->getVestal() == true) {
                        if (TurnPriority.at(i)->getCrusader() == true) {
                            if (heroes.at(TurnPriority.at(i)->getPosition() - 1) == Crusader1) {
                                if (heroes.at(TurnPriority.at(i)->getPosition() - 1)->getBoF() == true) {
                                    bulwarkoffaith->bofCooldown(Crusader1);
                                }
                                CrusaderDisplayActions(heroes, monsters, TurnPriority.at(i)->getPosition(), Crusader1);
                            }
                            else {
                                if (heroes.at(TurnPriority.at(i)->getPosition() - 1)->getBoF() == true) {
                                    bulwarkoffaith->bofCooldown(Crusader2);
                                }
                                CrusaderDisplayActions(heroes, monsters, TurnPriority.at(i)->getPosition(), Crusader2);
                            }
                        }
                        else if (TurnPriority.at(i)->getVestal() == true) {
                            if (heroes.at(TurnPriority.at(i)->getPosition() - 1) == Vestal1) {
                                VestalDisplayActions(heroes, monsters, TurnPriority.at(i)->getPosition(), Vestal1);
                            }
                            else {
                                VestalDisplayActions(heroes, monsters, TurnPriority.at(i)->getPosition(), Vestal2);
                            }
                        }
                    }

                }
                else if (TurnPriority.at(i)->getAlive() && TurnPriority.at(i)->getisStunned() == true) {
                    cout << TurnPriority.at(i)->getName() << " is STUNNED!" << endl;
                    timer(1.2);
                    if (TurnPriority.at(i)->getCrusader()) {
                        cout << "He won't be able to use any skills this turn" << endl;
                        if (heroes.at(TurnPriority.at(i)->getPosition() - 1)->getBoF() == true) {
                            bulwarkoffaith->bofCooldown(Crusader1);
                        }
                    }
                    else if (TurnPriority.at(i)->getBoneSoldier() || TurnPriority.at(i)->getBoneDefender()) {
                        cout << "It won't be able to use any skills this turn" << endl;
                    }
                    else if (TurnPriority.at(i)->getVestal()) {
                        cout << "She won't be able to use any skills this turn" << endl;
                    }
                    TurnPriority.at(i)->setisStunned(false);
                }
                timer(2);
            }
        }
        roundCount++;
    }
    //    gameOver=true;

    return 0;
}