
#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "utils.h"

class DATEUTILS{
    private:
        std::string year;
        std::string month;
        std::string day;
        std::string yyyymmdd;
    public:
        DATEUTILS(std::string date);
        void date_to_tokens();
        void print(std::ostream& where);
        void print();
};