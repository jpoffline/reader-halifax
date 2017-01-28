
#include "dateutils.h"


DATEUTILS::DATEUTILS(std::string date) 
    : yyyymmdd(date)
{
    date_to_tokens();
}

void DATEUTILS::date_to_tokens()
{
    std::vector<std::string> results;
    split(yyyymmdd, "/", results);
    
    year = results[2];
    month = results[1];
    day = results[0];
}

void DATEUTILS::print(std::ostream& where)
{
    where << year << "-" << month << "-" << day << "\n";
}

void DATEUTILS::print()
{
    print(std::cout);
}
