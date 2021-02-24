#include <iostream>  
#include <fstream>   
#include <math.h>
#include <cmath>
#include <cstdlib>


int func(){
    std::ifstream inputdata("calc1.data");
    double xvalue = 0.;
    double mean=0.;
    double number=0;
    double var=0;
    double vari=0;
    while (inputdata >> xvalue ){
        mean+=xvalue;
        number++;
    }
    inputdata.close();
    mean=mean/number;
    std::cout << "the mean is : " << mean << " for " << number << " entries" << std::endl;
    
//calculate population variance
    inputdata.open("calc1.data");
    while (inputdata >> xvalue ){
        var+=(xvalue-mean)*(xvalue-mean);
    }
    inputdata.close();
    var=var/number;
    
    std::cout << "the variance is : " << var << " for " << number << " entries" << std::endl;    

//calculate variance in the notes
    inputdata.open("calc1.data");
    while (inputdata >> xvalue ){
        vari+=(xvalue-mean)*(xvalue-mean);
    }
    inputdata.close();
    vari=vari/(number-1);   
    
    std::cout << "the variance calculated using the notes is : " << vari << " for " << number << " entries" << std::endl; 
    
    return 0; 
}