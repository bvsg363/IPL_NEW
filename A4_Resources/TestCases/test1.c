float area;
float perimeter;
float x;
int a, b;

void main()
{
	float r;
	int x, y, k;
	float z;
	int i, j;

	z = 3.0;
	y = 9;
	x = 2;
	area = 4.0;

	x = 5 + !5 < 6 ? 67 : 68;

	y = !5 < 6 ? 67 : 68 + !5 < 6 ? 67 : 68;

	x = y + (x == 0) ? 7 : 33;

	x = (x == 0) ? 7 : 33 + y;

	x = x + (2 < 3 ? 4 : 6);

	{
		{
			x = 9;
			y = 0;
		}
		area = 9.0;
		{
			{
				x = 8;
			}
		}
	}
	

	{
		a = 1;
	}

	if (x == 2)
	{
		{z = 4.0;}
	}

	while (!x != 3)
	{
		x = 3;
		x = 6;
	}

	// z = 1.0/0.0;

	x = !(2.0 < 3.4) || 2 > 3 ? 4 : 6;

	if (x <= 5 || x < 4 && x > 5)
	{
		x = 8;
		y = 7;
	}
	else
	{
		x = 9;
		y = 6;
		do
		{
			area = 1.0;
		} while (area == 0.0);
	}

	do
	{
		if (x <= 5 || x < 4 || x > 5)
		{
			x = 8;
		}
		else
		{
			x = 9;
			x = 8;
			if (x == 9)
				x = 7;
		}

		while (x == 0)
		{
			y = 9;
		}

		while (y == 0)
			y = 8;

	} while (x == 4);

	if (x >= 5 && z < 4.0)
	{
		while (x == 0)
		{
			x = 3;
			x = (!2 > 3) || x < y && x > y || x == y ? 2 : 4;
		}

		if (!((x != 9) || x >= 9))
		{
			if (x > 0)
			{
				x = 8;
				x = ((2.0 > 3.4) && (2 < 3)) ? 4 : 6;
				x = 9;
			}
			x = 5;
		}
		x = 8;
	}

	while (y == 3)
		y = 9;
	if (x == 3)
		y = 9;

	while (y == 3)
		while (y == 3)
		{
			x = 9;
		}

	// do x = 1;
	// while(x == 2);

	// Circle
	area = 2.0 * 3.0;
	perimeter = 2.0 * 22.0;

	i = 0;
	j = 1;
	a = 0;
	if (i > j)
	{
		b = 5;
	}
	else
	{
		b = 4;
	}

	if (i > j)
		b = 5;
	else
		b = 4;

	if (i > j)
	{
		b = 5;
	}
	else
		b = 4;

	if (i > j)
		b = 5;
	else
	{
		b = 4;
	}

	if (i > j)
		if (i > j)
			b = 4;
		else
			b = 5;
	else
		b = 6;
}
