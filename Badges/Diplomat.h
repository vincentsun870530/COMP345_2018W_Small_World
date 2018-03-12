//
// Created by vince on 2018/2/14.
//

#ifndef SMALLWORLD_DIPLOMAT_H
#define SMALLWORLD_DIPLOMAT_H


#include "Badges.h"

class Diplomat : public Badges{
public:
    Diplomat();

    Diplomat(const std::string &badgesName_, const std::string &specialPowerDescription_, int tokenAmount_);

    ~Diplomat() override;

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


#endif //SMALLWORLD_DIPLOMAT_H
