//
// Created by vince on 2018/2/13.
//

#ifndef SMALLWORLD_BIVOUACKING_H
#define SMALLWORLD_BIVOUACKING_H


#include "Badges.h"

class Bivouacking : public Badges {

public:
    Bivouacking();

    Bivouacking(const std::string &badgesName_, const std::string &specialPowerDescription_, int tokenAmount_);

    ~Bivouacking() override;

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


#endif //SMALLWORLD_BIVOUACKING_H
