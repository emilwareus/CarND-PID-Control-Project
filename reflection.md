##  My Reflection on the PID controller

### Describe the effect each of the P, I, D components had in your implementation. 


#### Proportional gain

The P part of the controller is computed throught the following algorithm: 

p_error = cte
P = -Kp*p_error

P is then passed to the total gain output. Proportional gain is a very important part of the PID and is more or less present on most PID's. In the domain of this project this is not different. Working with only P action, the controller thends to be very sensitive to constant loads, which creates static errors, and overshots. Therefore, the P controller would not be enough by itself in the domain. 


#### Integral gain

The I part is calculated through this equation: 

i_error = cte + i_error
I = -Ki*i_error

The I part is very good at handling static errors, as in integrates the error over time. This is only applicable when there is a static error. In the domain of this project, no static error is present. One could argue that the turn brings a static error to the domain, but it is negligible. 


#### Derivative gain

The D part is calculated through this equation: 

d_error = cte - p_error
D = - Kd*d_error

The D part is very good at handling overshots from the P and I part. This part is usually the hardest parameter to tune, which makes many people just put it to 0. The D part is also very sensitive to high frequency noise, which is not present in our simulated environment. In our domin, the D part was key to handle the overshot from the P-gain. 


### Describe how the final hyperparameters were chosen.

At first, I thought of implementing a twiddle algorithm to handle the tuning. But when the decision was made to put the I-gain to 0, as no static error was present, I decided to tune them by hand. My general approach is to start with P, and tune it up from 0 very carefully. When I can see signs of overshot, I start adding a small D-gain. Incrementally I tweaked these parameters until I reached the state of "good enough". This could havebeen improved by measuring the error over a fixt time, but my tweaking method seemed sufficient.
