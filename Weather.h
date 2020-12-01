/*
    Tyler Scott
    Mars Weather (Project 1)
    *****************************
    MarsWeather class
    - Takes in and stores all data from the mars-weather.csv file
    - Adds data to vector

*/

#ifndef PROJECT_1_WEATHER_H
#define PROJECT_1_WEATHER_H

#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

class MarsWeather {

private:

    std::string atmo; // Atmospheric Opacity
    std::string month;
    std::string t_date; // Terrestrial Date (Date on Earth)
    std::string wind_speed; // ALL outputs N/A, will probably remove
    int id; // ID number of individual transmission
    int ls; // Solar Longitude (angle of planet relative to the sun)
    int max_temp;
    int min_temp;
    int pressure; // Atmospheric Pressure (Pa)
    int sol; // Elapsed Martian days since Curiosity landing


public:

    // Constructors
    MarsWeather() {

        id = 0;
        ls = 0;
        max_temp = 0;
        min_temp = 0;
        pressure = 0;
        sol = 0;
        wind_speed = "Default";
        month = "Default";
        atmo = "Default";
        t_date = "Default";
    }

    MarsWeather(int id, std::string t_date, int sol, int ls,
                std::string month, int min_temp, int max_temp,
                int pressure, std::string wind_speed, std::string atmo) {

        this->t_date = t_date;
        this->atmo = atmo;
        this->month = month;
        this->wind_speed = wind_speed;
        setId(id);
        setLs(ls);
        setMaxTemp(max_temp);
        setMinTemp(min_temp);
        setPressure(pressure);
        setSol(sol);

    }

    // Getters
    std::string getAtmo() const {
        return atmo;
    }

    std::string getMonth() const {
        return month;
    }

    std::string getT_date() const {
        return t_date;
    }

    std::string getWindSpeed() const{
        return wind_speed;
    }

    int getId() const {
        return id;

    }

    int getMaxTemp() const {
        return max_temp;
    }

    int getMinTemp() const {
        return min_temp;
    }

    int getPressure() const {
        return pressure;
    }

    int getSol() const {
        return sol;
    }

    int getLs() const {
        return ls;
    }

    // Setters
    void setT_date(std::string t_date) {
        this->t_date = t_date;
    }

    void setAtmo(std::string atmo) {
        this->atmo = atmo;
    }

    void setMonth(std::string month) {
        this->month = month;
    }

    void setId(int id) {
        if (id < 0) {
            this->id = 0;
        } else {
            this->id = id;
        }
    }

    void setSol(int sol) {
        if (sol < 0) {
            this->sol = 0;
        } else {
            this->sol = sol;
        }
    }

    void setLs(int ls) {
        if (ls < 0) {
            this->ls = 0;
        } else {
            this->ls = ls;
        }
    }

    void setMaxTemp(int max_temp) {
            this->max_temp = max_temp;
    }

    void setMinTemp(int min_temp) {
            this->min_temp = min_temp;
    }

    void setPressure(int pressure) {
            this->pressure = pressure;
    }

    // Overloaded Operators
    friend std::ostream& operator << (std::ostream& outs, const MarsWeather &w) {
        outs << std::left << std::setw(5) << w.id;
        outs << std::left << std::setw(10) << w.t_date;
        outs << std::setw(5) << w.sol;
        outs << std::setw(5) << w.ls;
        outs << std::setw(10) << w.month;
        outs << std::setw(5) << w.min_temp;
        outs << std::setw(5) << w.max_temp;
        outs << std::setw(5) << w.pressure;
        outs << std::setw(5) << w.wind_speed;
        outs << std::left << std::setw(5) << w.atmo;
        return outs;
    }


};

/*
    Reads info from file and adds to vector
    @param filename The file name to be read
    @param weather Variable being passed that holds vector

 */
void getWeather(std::string filename, std::vector<MarsWeather> &weather) {

    std::ifstream fIn;
    fIn.open("../" + filename);

    std::string header = "";
    if (fIn) {
        getline(fIn, header);
    }

    // Variables to be used in loop
    std::string t_date = "", month = "", atmo = "", wind_speed = "";
    int id = 0, sol = 0, ls = 0, min_temp = 0, max_temp = 0,
        pressure = 0;

    char comma = ',';

    // Reads file and adds to vector
    while(fIn && fIn.peek() != EOF) {

        fIn >> id;
        if (!fIn) {
            id = 0;
            fIn.clear();
        }

        fIn >> comma;

        getline(fIn, t_date, ',');

        fIn >> sol;

        if (!fIn) {
           sol = 0;
           fIn.clear();
        }

        fIn >> comma;

        fIn >> ls;

        if (!fIn) {

            ls = 0;

            fIn.clear();

        }

        fIn >> comma;

        getline(fIn, month, ',');

        fIn >> min_temp;

        if (!fIn) {

            min_temp = 0;

            fIn.clear();
        }

        fIn >> comma;
        fIn >> max_temp;

        if (!fIn) {

            max_temp = 0;
            fIn.clear();
        }

        fIn >> comma;
        fIn >> pressure;

        if (!fIn) {

            pressure = 0;
            fIn.clear();
        }

        fIn >> comma;
        getline(fIn, wind_speed, ',');

        getline(fIn, atmo);

        // Passes the MarsWeather constructor into the vector, initializing variables
        weather.push_back(MarsWeather(id, t_date, sol, ls,
                                      month, min_temp, max_temp,
                                      pressure, wind_speed, atmo));

    }

    fIn.close();
}

#endif //PROJECT_1_WEATHER_H
