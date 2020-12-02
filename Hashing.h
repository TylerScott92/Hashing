
#ifndef PROJECT5_HASHING_H
#define PROJECT5_HASHING_H
#include "HashTable.h"
#include "Lecturer.h"
#include "LinearProbing.h"
#include "QuadraticProbing.h"
#include "SeparateChaining.h"
#include "Weather.h"
#include <iostream>
#include <vector>

class Hashing {

private:

    const unsigned long TABLE_SIZE_ONE = 2000;
    const unsigned long TABLE_SIZE_TWO = 2250;
    const unsigned long TABLE_SIZE_THREE = 2500;
    const unsigned long TABLE_SIZE_FOUR = 2750;
    const unsigned long TABLE_SIZE_FIVE = 3000;

    unsigned long hornerHash(string key, unsigned long tableSize) {
        unsigned long hashVal = 0;
        for (char &letter : key) {
            hashVal = hashVal * 37 + letter;
        }
        return hashVal % tableSize;
    }

    static string getSolId(MarsWeather sol_key) {
        return std::to_string(sol_key.getSol());
        // return to_string(lec.getClass1());
    }

    static string getPressure(MarsWeather pressure_key) {
        return std::to_string(pressure_key.getPressure());
    }



public:
    /**
     * Separate Chaining
     */

    void weatherSC() {

        vector<MarsWeather> weather;
        getWeather("mars-weather.csv", weather);
        SeparateChaining<MarsWeather> weather_sc_one(TABLE_SIZE_ONE, getSolId);
        SeparateChaining<MarsWeather> weather_sc_two(TABLE_SIZE_TWO, getSolId);
        SeparateChaining<MarsWeather> weather_sc_three(TABLE_SIZE_THREE, getSolId);
        SeparateChaining<MarsWeather> weather_sc_four(TABLE_SIZE_FOUR, getSolId);
        SeparateChaining<MarsWeather> weather_sc_five(TABLE_SIZE_FIVE, getSolId);

        //For second getKey (getPressure)
        SeparateChaining<MarsWeather> weather_sc_pressure(TABLE_SIZE_FIVE, getPressure);

        //For second Hash Function
        SeparateChainingOtherHash<MarsWeather> weather_sc_other_hash(TABLE_SIZE_FIVE, getSolId);

        for (MarsWeather &weather_id_sc : weather) {
            weather_sc_one.insert(weather_id_sc);
            //cout << hornerHash(std::to_string(weather_id_sc.getSol()), TABLE_SIZE_ONE) << endl;
        }

        for (MarsWeather &weather_id_sc : weather) {
            weather_sc_two.insert(weather_id_sc);
            //cout << hornerHash(std::to_string(weather_id_sc.getSol()), TABLE_SIZE_TWO) << endl;
        }

        for (MarsWeather &weather_id_sc : weather) {
            weather_sc_three.insert(weather_id_sc);
            //cout << hornerHash(std::to_string(weather_id_sc.getSol()), TABLE_SIZE_THREE) << endl;
        }

        for (MarsWeather &weather_id_sc : weather) {
            weather_sc_four.insert(weather_id_sc);
            //cout << hornerHash(std::to_string(weather_id_sc.getSol()), TABLE_SIZE_FOUR) << endl;
        }

        for (MarsWeather &weather_id_sc : weather) {
            weather_sc_five.insert(weather_id_sc);
            //cout << hornerHash(std::to_string(weather_id_sc.getSol()), TABLE_SIZE_FIVE) << endl;
        }

        for (MarsWeather &weather_id_sc : weather) {
            weather_sc_pressure.insert(weather_id_sc);
            //cout << hornerHash(std::to_string(weather_id_sc.getSol()), TABLE_SIZE_FIVE) << endl;
        }

        for (MarsWeather &weather_id_sc : weather) {
            weather_sc_other_hash.insert(weather_id_sc);
            //cout << hornerHash(std::to_string(weather_id_sc.getSol()), TABLE_SIZE_FIVE) << endl;
        }



        std::cout << "\nSeparate Chaining" << std::endl;
        std::cout << "Number of Reads: " << weather_sc_one.getReads() << std::endl;
        std::cout << "Number of Reads: " << weather_sc_two.getReads() << std::endl;
        std::cout << "Number of Reads: " << weather_sc_three.getReads() << std::endl;
        std::cout << "Number of Reads: " << weather_sc_four.getReads() << std::endl;
        std::cout << "Number of Reads: " << weather_sc_five.getReads() << std::endl;
        std::cout << "Number of Reads: " << weather_sc_pressure.getReads() << std::endl;
        std::cout << "Number of Reads: " << weather_sc_other_hash.getReads() << std::endl;

    }

    /**
     * Quadratic Probing
     */

    void weatherQP() {

        vector<MarsWeather> weather;
        getWeather("mars-weather.csv", weather);

        QuadraticProbing<MarsWeather> weather_qp_one(TABLE_SIZE_ONE, getSolId);
        QuadraticProbing<MarsWeather> weather_qp_two(TABLE_SIZE_TWO, getSolId);
        QuadraticProbing<MarsWeather> weather_qp_three(TABLE_SIZE_THREE, getSolId);
        QuadraticProbing<MarsWeather> weather_qp_four(TABLE_SIZE_FOUR, getSolId);
        QuadraticProbing<MarsWeather> weather_qp_five(TABLE_SIZE_FIVE, getSolId);

        //Second getKey (getPressure)
        QuadraticProbing<MarsWeather> weather_qp_pressure(TABLE_SIZE_FIVE, getPressure);

        //Second hash function
        QuadraticProbingOtherHash<MarsWeather> weather_qp_other_hash(TABLE_SIZE_TWO, getSolId);

        for (MarsWeather &weather_id_qp : weather) {
            weather_qp_one.insert(weather_id_qp);
            //cout << hornerHash(std::to_string(weather_id_qp.getSol()), TABLE_SIZE_ONE) << endl;
        }

        for (MarsWeather &weather_id_qp : weather) {
            weather_qp_two.insert(weather_id_qp);
            //cout << hornerHash(std::to_string(weather_id_qp.getSol()), TABLE_SIZE_ONE) << endl;
        }

        for (MarsWeather &weather_id_qp : weather) {
            weather_qp_three.insert(weather_id_qp);
            //cout << hornerHash(std::to_string(weather_id_qp.getSol()), TABLE_SIZE_ONE) << endl;
        }

        for (MarsWeather &weather_id_qp : weather) {
            weather_qp_four.insert(weather_id_qp);
            //cout << hornerHash(std::to_string(weather_id_qp.getSol()), TABLE_SIZE_ONE) << endl;
        }

        for (MarsWeather &weather_id_qp : weather) {
            weather_qp_five.insert(weather_id_qp);
            //cout << hornerHash(std::to_string(weather_id_qp.getSol()), TABLE_SIZE_ONE) << endl;
        }

        for (MarsWeather &weather_id_qp : weather) {
            weather_qp_pressure.insert(weather_id_qp);
            //cout << hornerHash(std::to_string(weather_id_qp.getSol()), TABLE_SIZE_ONE) << endl;
        }

        for (MarsWeather &weather_id_qp : weather) {
            weather_qp_other_hash.insert(weather_id_qp);
            //cout << hornerHash(std::to_string(weather_id_qp.getSol()), TABLE_SIZE_ONE) << endl;
        }

        std::cout << "\nQuadratic Probing" << std::endl;
        std::cout << "Number of reads: " << weather_qp_one.getReads() << std::endl;
        std::cout << "Number of reads: " << weather_qp_two.getReads() << std::endl;
        std::cout << "Number of reads: " << weather_qp_three.getReads() << std::endl;
        std::cout << "Number of reads: " << weather_qp_four.getReads() << std::endl;
        std::cout << "Number of reads: " << weather_qp_five.getReads() << std::endl;
        std::cout << "Number of reads: " << weather_qp_pressure.getReads() << std::endl;
        std::cout << "Number of reads: " << weather_qp_other_hash.getReads() << std::endl;
    }

};

#endif //PROJECT5_HASHING_H
