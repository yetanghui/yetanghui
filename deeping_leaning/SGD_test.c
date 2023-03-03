#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define PI 3.14159265358979

//原函数y = sin(x)^2 + cos(x) + 5



//原函数
double function(double x){
	double y = pow(sin(x*PI/180),2) + cos(x*PI/180) + 5;
	return y;
}



//偏导数
double d_x(double x){
	double d_y = 2*sin(x)*cos(x) - sin(x);
	return d_y;
}


int main(){
	int step = 0;
	double rate = 0.1,x = 6,y_old,y_new,new_theta,old_theta,theta = 6,t = 0.25,eps = 0.00002;
	while(1){
		new_theta = theta - t*(d_x(x));
		if(abs(d_x(new_theta)) < abs(d_x(theta))){
			theta = new_theta;
			y_new = function(theta);
		}
		else
		{
			y_new = function(theta);
		}
		printf("%.10lf %.2lf\n",theta,y_new);
		y_old = y_new;
		step ++;
		if(step > 10000) break;
	}	
	return 0;
}




