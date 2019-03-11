
float area;
float perimeter;

void main()
{
	int x, y;
	float z;
	z = 3.0;
	x = 3;


	while(x < 2){
		x = 3;
	}

	if(x == 3){
		x = 8;
	}

	do{
		if(x <= 5){
			 x = 8;
		}
		else{
			x = 9;
		}
	} while(x == 4);

	if(x >= 5 && z < 4.0){
		if(!(x < 4) || x > 5){
			if(x>0){
				x = 8;
				// x= ((2>3) && (2 < 3))?4:6;
				// x > 3 ? x=4:x=6;
				x = 9;
			}
		}
	}

	// do x = 1;
	// while(x == 2);

	// // Circle
	// area = 22 * x * x / 7;
	// perimeter = 2 * 22 * x /7;
	// return 0;
}
