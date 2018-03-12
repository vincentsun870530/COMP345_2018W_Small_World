//
// Created by vince on 2018/2/14.
//

#ifndef SMALLWORLD_FORTIFIED_H
#define SMALLWORLD_FORTIFIED_H


#include "Badges.h"

class Fortified : public Badges{
public:
    Fortified();

    Fortified(const std::string &badgesName_, const std::string &specialPowerDescription_, int tokenAmount_);

    ~Fortified() override;

    void setBadgesName_(const std::string &badgesName) override;

    void setSpecialPowerDescription_(const std::string &specialPowerDescription) override;

    void setTokenAmount_(int tokenAmount) override;

    int getTokenAmount_() override;

    const std::string getbadgesName() override;

    const std::string getSpecialPowerName() override;

    int startSuperPowerForVictoryCoin(int victoryCoin) override;

    void startSuperPowerForToken(int tempToken) override;

    void show() override;
};


#endif //SMALLWORLD_FORTIFIED_H
