
#include "map.h"






void map_play()
{
    auto myMap = MAP<int,int>();
    myMap.add(1,432);
    myMap.add(2,1);
    myMap.add(1,32);
    myMap.add(2,343789);
    myMap.print();
  
    
    myMap.print_map_on_unique_keys();
    myMap.accumulate_on_key();
    myMap.print_accumulated();

    
}


int main()
{
    map_play();
    return 0;

}