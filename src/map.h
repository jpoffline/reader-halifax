#pragma once

#include <iostream>
#include <ostream>
#include <map>
#include <set>

namespace MT {

    template<class K, class V>
    void printmultimap_for_key(std::ostream& whereto, const std::multimap<K,V>& mymm, K key)
    {

        auto ret = mymm.equal_range(key);
        if(ret.first == mymm.end())
        {
            whereto << key << " not in map" << "\n";
            return;
        }
        whereto << key << " =>";
        for (auto it=ret.first; it!=ret.second; ++it)
        {
            whereto << ' ' << it->second;
        }
        whereto << '\n';
        
    }

    template<class K, class V>
    V accumulate_map_on_key(const std::multimap<K,V>& mymm, K key)
    {
        auto ret = mymm.equal_range(key);
        V accum(0);
        if(ret.first == mymm.end())
        {
            return accum;
        }
        
        for (auto it=ret.first; it!=ret.second; ++it)
        {
            accum = accum + it->second;
        }
        return accum;
    }



}


template<typename K, typename V>
class MAP {

    private:
        

        std::multimap<K,V> _map;
        // Set to hold the unique keys.
        std::set<K> _keys;

        std::map<K,V> _accumulated_map;

        // Method to print the entire map.
        void _print(std::ostream& whereto)
        {
            for(auto &i : _map)
            {
                whereto << i.first << " " << i.second << "\n";
            }
        }

        // Method to print the map over each unique key.
        void _print_map_on_unique_keys(std::ostream& whereto)
        {
            for(auto&k :_keys)
            {
                MT::printmultimap_for_key<K, V>(whereto, _map, k);
            }
        }


        void _print_keys(std::ostream& whereto)
        {
            for(auto&k :_keys)
            {
                whereto << k << "\n";
            }
        }

        void _print_accumulated(std::ostream& whereto)
        {
            for(auto& a : _accumulated_map)
            {
                whereto << a.first << " -> " << a.second << "\n";
            }
        }

        void _accumulate_on_key()
        {
            for(auto&key :_keys)
            {
                _accumulated_map.insert(
                    std::make_pair(
                        key, 
                        MT::accumulate_map_on_key<K,V>(_map, key)
                    )
                );
            }

        }


    public:

        MAP(){}

        void add(K key, V value)
        {
            _map.insert(
                std::make_pair(key, value)
            );

            _keys.insert(key);
        }

        bool is_key(K key)
        {
            return _map.find(key) != _map.end();
        }

        int count_key(K key)
        {
            return _map.count(key);
        }

        void summarise()
        {

        }

        void accumulate_on_key()
        {
            _accumulate_on_key();
        }

        void print()
        {
            _print(std::cout);
        }

        void print_keys()
        {
            _print_keys(std::cout);
        }

        void print_map_on_unique_keys()
        {
            _print_map_on_unique_keys(std::cout);
        }

        void print_accumulated()
        {
            _print_accumulated(std::cout);
        }



    
};




