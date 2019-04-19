int i1,i2;
void func1();
float f1,f2;
int func2(int,float,int);
int func2(float, float, int);
float func3(float q,float r);
int s;
int func5(int a);
// float func5(int a);

// check re definning a function
int func4(){
	i1=4;
	return (i1+i1);
}

// int func6(int, float, int);

void func1(){
	i2=5;
	f2=5.0;
	// func3(2.0, 3.0);
}

int func2(float a,float b,int i1){
	a=a+10.0;
	i1=5;
	// return a+i1+i2+2;
	return 1>2?3:4;
}


float func3(float a,float b,float c){
	b =b+f2;
	c=c+10.5;
	return b+c;
}

void main(){
	func1();
	// print i2; print f2;
	i2 = func4();
	// print i1; print i2;
	i2 = func2(1.0,f2,i2);
	// print i1; print i2;
	f2 = func3(1.0,f1,f2);
	print f1; print f2;

	i1 = func5(1);

}

float func5(float a)
{
	i2 = 5;
	f2 = 5.0;
}