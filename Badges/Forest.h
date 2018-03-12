//
// Created by vince on 2018/2/14.
//

#ifndef SMALLWORLD_FOREST_H
#define SMALLWORLD_FOREST_H


#include "Badges.h"

class Forest : public Badges {

public:
    Forest();

    Forest(const std::string &badgesName_, const std::string &specialPowerDescription_, int tokenAmount_);

    ~Forest() override;

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


#endif //SMALLWORLD_FOREST_H
