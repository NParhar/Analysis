#include <iostream>  
#include <fstream>   
#include <math.h>
#include <cmath>
#include <cstdlib>
#include <vector>

vector<double> vecx, veco;
double x, o;
vector<double> vecy;
double y;
vector<double> vecv;
double v;
double totalchi;
int chi()
{
    std::ifstream inputdata("calculate_chisq_data.data");  
   
    while (inputdata >> x >> o)
    {
      vecx.push_back(x);
      veco.push_back(o);
    } 
    //Change file name to change the theory prediction
    std::ifstream inputdata2("calculate_chisq_theory1.data");
    while (inputdata2 >> y )
    {
      vecy.push_back(y);
    }    

    for(double i(0); i < vecx.size(); i++) 
        vecv.push_back(((vecy[i]-vecx[i])/veco[i])*((vecy[i]-vecx[i])/veco[i]));
            
    for(double i(0); i < vecx.size(); i++)
        std::cout << "the measured value is : " << vecx[i] <<  ", the statistical err is : " << veco[i] << ", the predicted value is : " << vecy[i] << ", the chi value is:" << vecv[i] <<std::endl;
        
    for(double i(0); i < vecv.size(); i++)
        totalchi+=vecv[i];
    totalchi=totalchi;    
    std::cout << "the total chi value is : " << totalchi <<std::endl;        
        
    return 0;
}


