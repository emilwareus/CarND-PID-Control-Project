#include "PID.h"

#include <iostream>
#include cstdlib
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
    this->Ki = Hi;
    this->Kd = Hd;

    this->p_error = 0;
    this->i_error = 0;
    this->d_error = 0;
    this->I = 0;
    this->old_error = 0;
    this->last_t = getMilliCount();

    cout<< "Initialized!" <<endl;

  
}

void PID::UpdateError(double cte) {
    double cur_time = getMilliCount();
    double delta_t = this->last_t - cur_time
    this-> last_t = cur_time;

    I = cte*delta_t + I; 
    double D = (cte - old_error)/delta_t;



}

double PID::TotalError() {


}

