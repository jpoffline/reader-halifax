
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "utils.h"
#include "dateutils.h"
#include "transaction_file.h"






int main(){

    TRANSACTION_FILE htf;
    //DATEUTILS date("01/01/1988");
    //date.print(std::cout);
    htf.read_file("data/tmp.csv");
    //htf.print_balances();
    //htf.print_date_description();
    std::cout << "about to unique" << std::endl;
    htf.print_unique_descriptions();
    //htf.create_time_series();
    //htf.print_time_series();
}