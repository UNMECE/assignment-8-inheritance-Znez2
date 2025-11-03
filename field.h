#ifndef FIELD_H
#define FIELD_H

#include <iostream>
#include <cmath>

class Field {
private:
    double* components; 

public:
    Field() {
        components = new double[3];
        components[0] = components[1] = components[2] = 0.0;
    }

    Field(double x, double y, double z) {
        components = new double[3];
        components[0] = x;
        components[1] = y;
        components[2] = z;
        
    }

 ~Field() {
        delete[] components;
    }


    void setX(double x) { components[0] = x; }
void setY(double y) { components[1] = y; }

    void setZ(double z) { components[2] = z; }

    double getX() const {return components[0]; }
    
    double getY() const {return components[1]; }
    double getZ() const { return components[2]; }
    


    double* getComponents() const { return components; }
};


class Electric_Field : public Field {
private:
    double calculated_E;  

public:
    Electric_Field() : Field(), calculated_E(0.0) {}
    Electric_Field(double x, double y, double z) : Field(x, y, z), calculated_E(0.0) {}

    void calculateElectricField(double Q, double r) {
        const double eps0 = 8.854e-12; 
        calculated_E = Q / (4 * M_PI * eps0 * r * r);
    }

    double getCalculatedE() const { return calculated_E; }

    double calculateMagnitude() const {
        
        double* E = getComponents();
        
        return sqrt(E[0]*E[0] + E[1]*E[1] + E[2]*E[2]);
        
    }

    double innerProduct(const Electric_Field& other) const {
        double* E1 = getComponents();
        double* E2 = other.getComponents();
        return E1[0]*E2[0] + E1[1]*E2[1] + E1[2]*E2[2];
    }
    

    void printElectricField() const {
        std::cout << "Electric Field magnitude " << calculateMagnitude() <<  std::endl;
        std::cout << "coulomb’s law " << calculated_E <<  std::endl;
    }
};


class Magnetic_Field : public Field {
private:
    double calculated_B;
    

public:
    Magnetic_Field() : Field(), calculated_B(0.0) {}
    Magnetic_Field(double x, double y, double z) : Field(x, y, z), calculated_B(0.0) {}

    void calculateMagneticField(double I, double r) {
        const double mu0 = 4 * M_PI * 1e-7; 
        
        calculated_B = (mu0 * I) / (2 * M_PI * r);
    }

    double getCalculatedB() const { return calculated_B; }

    double calculateMagnitude() const {
        
        double* B = getComponents();
        
        return sqrt(B[0]*B[0] + B[1]*B[1] + B[2]*B[2]);
    }

    void unitVector() const {
        double* B = getComponents();
        double mag = calculateMagnitude();
        
        std::cout << "unit thing magentic " << B[0]/mag << ", " << B[1]/mag << ", " << B[2]/mag << ")" << std::endl;
    }
    

    void printMagneticField() const {
        std::cout << "magnetic field magnatudes " << calculateMagnitude() << " T" << std::endl;
        std::cout << "ampère’s law " << calculated_B << " T" << std::endl;
    }
};

#endif
