
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

    static string getSolId(MarsWeather sol_key) {
        return std::to_string(sol_key.getSol());
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
        SeparateChaining<MarsWeather> weather_sc_pressure(TABLE_SIZE_ONE, getPressure);

        //For second Hash Function
        SeparateChainingOtherHash<MarsWeather> weather_sc_other_hash(TABLE_SIZE_ONE, getSolId);

        //Both
        SeparateChainingOtherHash<MarsWeather> weather_sc_both(TABLE_SIZE_ONE, getPressure);

        for (MarsWeather &weather_id_sc : weather) {
            weather_sc_one.insert(weather_id_sc);
        }

        for (MarsWeather &weather_id_sc : weather) {
            weather_sc_two.insert(weather_id_sc);
        }

        for (MarsWeather &weather_id_sc : weather) {
            weather_sc_three.insert(weather_id_sc);
        }

        for (MarsWeather &weather_id_sc : weather) {
            weather_sc_four.insert(weather_id_sc);
        }

        for (MarsWeather &weather_id_sc : weather) {
            weather_sc_five.insert(weather_id_sc);
        }

        for (MarsWeather &weather_id_sc : weather) {
            weather_sc_pressure.insert(weather_id_sc);
        }

        for (MarsWeather &weather_id_sc : weather) {
            weather_sc_other_hash.insert(weather_id_sc);
        }

        for (MarsWeather &weather_id_sc : weather) {
            weather_sc_both.insert(weather_id_sc);
        }

        // Write to file
        std::ofstream file_sequence;
        file_sequence.open("../separate_chaining.csv");
        if (file_sequence) {

            file_sequence << weather_sc_one.getReads() << std::endl;
            file_sequence << weather_sc_two.getReads() << std::endl;
            file_sequence << weather_sc_three.getReads() << std::endl;
            file_sequence << weather_sc_four.getReads() << std::endl;
            file_sequence << weather_sc_five.getReads() << std::endl;
            file_sequence << weather_sc_pressure.getReads() << std::endl;
            file_sequence << weather_sc_other_hash.getReads() << std::endl;
            file_sequence << weather_sc_both.getReads() << std::endl;


        }
        file_sequence.close();

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
        QuadraticProbing<MarsWeather> weather_qp_pressure(TABLE_SIZE_TWO, getPressure);

        //Second hash function
        QuadraticProbingOtherHash<MarsWeather> weather_qp_other_hash(TABLE_SIZE_TWO, getSolId);

        //Both
        QuadraticProbingOtherHash<MarsWeather> weather_qp_both(TABLE_SIZE_TWO, getPressure);

        for (MarsWeather &weather_id_qp : weather) {
            weather_qp_one.insert(weather_id_qp);
        }

        for (MarsWeather &weather_id_qp : weather) {
            weather_qp_two.insert(weather_id_qp);
        }

        for (MarsWeather &weather_id_qp : weather) {
            weather_qp_three.insert(weather_id_qp);
        }

        for (MarsWeather &weather_id_qp : weather) {
            weather_qp_four.insert(weather_id_qp);
        }

        for (MarsWeather &weather_id_qp : weather) {
            weather_qp_five.insert(weather_id_qp);
        }

        for (MarsWeather &weather_id_qp : weather) {
            weather_qp_pressure.insert(weather_id_qp);
        }

        for (MarsWeather &weather_id_qp : weather) {
            weather_qp_other_hash.insert(weather_id_qp);
        }

        for (MarsWeather &weather_id_qp : weather) {
            weather_qp_both.insert(weather_id_qp);
        }

        // Write to file
        std::ofstream file_sequence;
        file_sequence.open("../quadratic_probing.csv");
        if (file_sequence) {

            file_sequence << weather_qp_one.getReads() << std::endl;
            file_sequence << weather_qp_two.getReads() << std::endl;
            file_sequence << weather_qp_three.getReads() << std::endl;
            file_sequence << weather_qp_four.getReads() << std::endl;
            file_sequence << weather_qp_five.getReads() << std::endl;
            file_sequence << weather_qp_pressure.getReads() << std::endl;
            file_sequence << weather_qp_other_hash.getReads() << std::endl;
            file_sequence << weather_qp_both.getReads() << std::endl;


        }
        file_sequence.close();
    }

};

#endif //PROJECT5_HASHING_H
