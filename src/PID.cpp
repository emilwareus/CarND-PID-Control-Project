#include "PID.h"

#include <iostream>
#include <cstdlib>
#include <sys/timeb.h>


using namespace std;

double getMilliCount(){
	timeb tb;
	ftime(&tb);
	int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
	return double(nCount);
}

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;

    this->p_error = 0;
    this->i_error = 0;
    this->d_error = 0;
    this->last_t = getMilliCount();

    cout<< "Initialized!" <<endl;

  
}

void PID::UpdateError(double cte) {

    double cur_time = getMilliCount();
    double delta_t = cur_time - last_t;
    last_t = cur_time;
    
    d_error = (cte - p_error) / delta_t;
    p_error = cte;
    i_error = cte*delta_t + i_error; 
    

}

double PID::TotalError() {

    double u = -Kp*p_error - Ki*i_error - Kd*d_error;

    //Saturation 
    if(u > 1.0){
        u = 1.0;
    }else if(u < -1.0 ){
        u = -1.0;
    }
    return u;

}

