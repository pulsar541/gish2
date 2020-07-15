#ifndef _door_h_
#define _door_h_

#define YELLOW  0
#define BLUE	1
#define RED		2
#define GREEN	3

class Door: public Primitive
{
public :
	bool isOpen;
	Door()
	{
		isOpen=false;
		setInterval(0,10);
	}

	void close()
	{
		isOpen=false;
	}

	void open()
	{
		isOpen=true;
	}

	void actionOnTime(int numInterval)
	{
		switch(numInterval)
		{
			case 0:
				if(isOpen)
				{
					if(A.y < C.y - 10) 
						A.y +=10;
					setPos(A,B,C);
				//	MessageBox(NULL,"rty","ty3",MB_OK);
				}

			//	
		
				break;
		}
	}
};

#endif