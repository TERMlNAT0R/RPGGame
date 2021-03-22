#include "src/hero/HeroClass.h"
#include "src/artifacts/sets/AssassinArtifact.h"
#include "src/skills/sets/AssassinSkills.h"


#ifndef RPG_ASSASSINCLASS_H
#define RPG_ASSASSINCLASS_H
class AssassinClass : public HeroClass {
public:

    explicit AssassinClass(std::string name)
    {
        this->GradeName = "Наёмник";
        this->HeroName = std::move(name);
        this->maxHP = 120;
        this->maxMana = 100;
        this->damage = 35;
        this->defense = 20;
        this->setArtifactHelmet(AssassinArtifact::helmet);
        this->setArtifactArmor(AssassinArtifact::armor);
        this->setArtifactHands(AssassinArtifact::hands);
        this->setArtifactLegs(AssassinArtifact::legs);
        this->allSkillsGrade={
                AssassinSkills::strongBlow,
                AssassinSkills::HiddenImpact,
                AssassinSkills::shuriken,
                AssassinSkills::bomb
        };
    }

protected:
    void up_level() override
    {
        this->level+=1;
        this->damage+=10;
        this->maxHP+=5;
        this->defense+=2;
        this->HP = this->HP< this->getMaxHPAll() / 100 * 70 ? this->getMaxHPAll() / 100 * 70 : this->getMaxHPAll();
    }

};
#endif //RPG_ASSASSINCLASS_H
