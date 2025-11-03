#include <iostream>
#include "field.h"

int main() {


    
    Electric_Field E1(3.0, 4.0, 0.0); 
    
    double Q = 0.05; 
    double r = 0.5; 
    
    E1.calculateElectricField(Q, r);

    std::cout << "E field  blah blah" << std::endl;
    E1.printElectricField();
    std::cout << std::endl;
    

    Magnetic_Field B1(0.0, 5.0, 0.0);
    double I = 10.0; 
    double r_B = 0.2; 
    
    B1.calculateMagneticField(I, r_B);
    

    std::cout << "the field that makes metal stick or somethiong" << std::endl;
    
    B1.printMagneticField();
    B1.unitVector();
    

    std::cout << "pancakes are better than waffles but also btw i think the program is ended rip"<< std::endl;

    return 0;
}
