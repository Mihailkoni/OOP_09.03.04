#include <iostream>
#include <string>

using namespace std;

class TemperatureSensor {
private:
    int temperature;

public:
    TemperatureSensor() : temperature(0.0) {}

    double getTemperature()  {
        return temperature;
    }

    void setTemperature(double newTemperature) {
        temperature = newTemperature;
    }

    string getTemperatureInfo() {
        return "Temperature: " + to_string(temperature);
    }
};

class CPU {
private:
    string info;
    TemperatureSensor temperatureSensor;

public:
    CPU() : info("CPU is loaded at 0%") {}

    void setLoad(int load) {
        info = "CPU is loaded at " + to_string(load) + "%";
    }

    string getInfo() {
        return info + "\n" + temperatureSensor.getTemperatureInfo();
    }

    void setTemperature(double temperature) {
        temperatureSensor.setTemperature(temperature);
    }
};

class GPU {
private:
    string info;
    TemperatureSensor temperatureSensor;

public:
    GPU() : info("GPU is loaded at 0%"){}

    void setLoad(int load) {
        info = "GPU is loaded at " + to_string(load) + "%";
    }

    string getInfo() {
        return info + "\n" + temperatureSensor.getTemperatureInfo();
    }

    void setTemperature(double temperature) {
        temperatureSensor.setTemperature(temperature);
    }
};

class RAM {
private:
    string info;
public:
    RAM() : info("0/16.0 GB used") {}

    string getInfo() {
        return info;
    }

    void setMemoryUsage(double usage) {
        info = to_string(usage) + "/16.0 GB used";
    }
};

class HDD {
private:
    string info;

public:
    HDD() : info("0/512 GB used") {}

    string getInfo() {
        return info;
    }

    void setUsedSpace(double space) {
        info = to_string(space) + "/512 GB used";
    }
};

class Computer {
protected:
    bool turnedOn;
public:
    CPU cpu;
    GPU gpu;
    RAM ram;
    HDD hdd;

    
    Computer() : turnedOn(false) {}
    void turnOn() {
        turnedOn = true;
        cout << "Computer is now turned on." << endl;
    }

    void turnOff() {
        turnedOn = false;
        cout << "Computer is now turned off." << endl;
    }

    virtual void displayComputerInfo() {
        cout << "Computer Information: " << endl;
        cout << "Status: " << (turnedOn ? "On" : "Off") << endl;
        cout << "Details: " << endl;
        cout << "CPU Info: " << cpu.getInfo() << endl;
        cout << "GPU Info: " << gpu.getInfo() << endl;
        cout << "RAM Info: " << ram.getInfo() << endl;
        cout << "HDD Info: " << hdd.getInfo() << endl;
    }
};



class Battery {
private:
    string em;

public:
    Battery() : em("0 mah") {}

    string getEm() {
        return em;
    }

    void setEm(double mah) {
        em = to_string(mah) + " mah";
    }
};


class Laptop :public Computer {
private:
    Battery bat;
public:
    void BatterySet(double x) {
        return bat.setEm(x);
    }
    string BatteryGet() {
        return bat.getEm();
    }
    virtual void displayComputerInfo() {
        cout << "Computer Information: " << endl;
        cout << "Status: " << (turnedOn ? "On" : "Off") << endl;
        cout << "Details: " << endl;
        cout << "CPU Info: " << cpu.getInfo() << endl;
        cout << "GPU Info: " << gpu.getInfo() << endl;
        cout << "RAM Info: " << ram.getInfo() << endl;
        cout << "HDD Info: " << hdd.getInfo() << endl;
        cout << "Battery Info: " << bat.getEm() << endl;
    }
    
};


int main() {
    Laptop* computerInstance = new Laptop();
    computerInstance->turnOn();
    
    computerInstance->BatterySet(578934);
    computerInstance->cpu.setLoad(45);
    computerInstance->gpu.setLoad(30);
    computerInstance->cpu.setTemperature(65.5);
    computerInstance->gpu.setTemperature(55.2);
    computerInstance->ram.setMemoryUsage(14.2);
    computerInstance->hdd.setUsedSpace(74);

    computerInstance->displayComputerInfo();
    

    return 0;
}
