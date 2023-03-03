#include<stdio.h>
#include<stdlib.h>
#include<math.h>


//定义损失函数,real为真实值，pre为预测值
double loss(double real,double pre){
	double num =  pow(real-pre,2);
	return num;
}

int main()
{
	//定义eps为最大误差
	double eps = 0.0003;
	//x,y位样本，t为学习率,pre_y为预测值，real_y为真实值，x_d为相应偏导数
	double x[3][7] = {{1,2,2,2,3,4,4},{1,1,2,2,1.5,1.5,3},{1,1,1,2,1,1,1}},real_y[7] = {6,7,9,12,9,10,13},t = 0.01,theta[3] = {1,1,1},pre_y;
	double w = 0;
	for(int i = 0;i < 7; i ++){
		pre_y = x[0][i]*theta[0] + x[1][i]*theta[1] + x[2][i]*theta[2];
		while(loss(pre_y,real_y[i]) > eps);
		{
			for(int m = 0;m < 3; m++){
				for(int q = 0; q < 7;q++){
					
				        w += (theta[0]*x[0][q] + theta[1]*x[1][q] + theta[2]*x[2][q] - real_y[q])*x[m][q];
				}
			}
			for(int m = 0; m < 3;m++){
				theta[m] = theta[m] - t*w;
			}
			printf("%lf %lf %lf",theta[0],theta[1],theta[2]);
		}
	}
	printf("%lf %lf %lf",theta[0],theta[1],theta[2]);
	return 0;
}

