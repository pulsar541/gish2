#ifndef BUILDING_H
#define BUILDING_H

#include "unit.h"


class Building: public Unit
{


	public: //FVector FSh;
			//FVector FMove;
			
	 bool fix;

//	 float old_dx,old_dy;		
		
	 bool blue ;
	 bool empty ;
	 bool visible;
	 bool enable ;
	 bool moveble;

	 int massa;
	

	 float oldrad ;
		
	 bool inprocess ;
	
	 bool Inert;

	 int iter;
	 float cred,
		   cgreen,
		   cblue;
			
	 bool cc;
	 int coltype ;

	 int extype;
		
	
	 int NUM;
		
	 PointF tochka[36];
		
	 int nt1[44];
	 int nt2[44];
		

	
	
	
	Building(float x, float y, float rad,int NUM)
	{	cc =false;
		iter=0;
		massa = 1;		
		 blue = true;
		empty = true;
		visible = true;
		 enable = true;
		moveble = false;

		Inert  = true;
		fix = false;
		this->NUM = NUM;		
		inprocess = true;
		
		cred = 0.7;
		cgreen =0.7;
		cblue = 0.7;

		oldx=this->x = x;
		oldy=this->y = y;

		oldrad = this->radius = rad;

		
		for(int k=0;k<36;k++)
			{	
			tochka[k].x = this->x + (float)cos(k*10 * _torad)* this->radius;
			tochka[k].y = this->y + (float)sin(k*10 * _torad)* this->radius;
			}

	
		dx = dy = 0;
		

	}
	void actionOnTime(int intervalMilliSec)
	{
	
	}

	int soot(int a)
	{
		if(a<18) return a+18;
		else return a-18;
	}
	
	/*
	void CalcInWater()
	{

			FMove.calc_kas(oldx,oldy,x,y);
			FMove.calc_in_water();
					
			old_dx = dx;
			old_dy = dy;	
			
			dx = 0;
			dy = 0;	
			
			dx = (FMove.x1 - FMove.x0);
			dy = (FMove.y1 - FMove.y0);	
		
		//	if(!Inert) 
		//	{ 
				dx*=0.985;
				dy*=0.985;
			
		//	}

	
	}
*/
	
	void CalcVectorInWater()
	{

			FMove.calc_kas(oldx,oldy,x,y);
			FMove.calc_in_water();
	
	}

	void CalcDxDyInWater()
	{
		///	old_dx = dx;
		//	old_dy = dy;		
			dx = (FMove.x1 - FMove.x0);
			dy = (FMove.y1 - FMove.y0);		
			dx*=0.985;
			dy*=0.985;
	}

	/*	void Calc()
		{
	
		 
				FSh.calc_kas(oldx,oldy,x,y);
				FSh.calc_prit_and_R(massa,x,y);
		
				FMove = FSh;
		
						
				old_dx = dx;
				old_dy = dy;	
				
				dx = 0;
				dy = 0;	
				
				dx = (FMove.x1 - FMove.x0);
				dy = (FMove.y1 - FMove.y0);	
			
				if(!Inert) 
				{ dx*=0.99;dy*=0.99;
				
				}
	
				
			if(!visible && enable)
			{
				radius+=10;
						
			}
			
			
		//	if(life<0)
		//		visible = false;
			
	
		}*/


	 void ShowShadow1(bool flag, PointF *light,float addx,float addy, float *onlgt)
	{	
		
	//	if(!visible) 
	////		return;
	//	if(NUM<2)
	//		return;
		if(NUM==1 || NUM == 2) return;


		int numLights=(((int)sizeof(light))>>1);



		int numONLights = 0;
		for (int i=0; i<numLights;i++ )
		 if(onlgt[i]) numONLights++;
	
			 


			glDisable (GL_CULL_FACE);

/*		
	for(int i=0; i<numLights; i++)
	{	
		if(!onlgt[i])
				continue;


		PointF pnt[4][36];

		for(int k=0;k<36;k++)
				{	
				tochka[k].x = x + cos(k*10*_torad)* radius;
				tochka[k].y = y + sin(k*10*_torad)* radius;
			
			
				
				pnt[0][k].x = tochka[k].x; 
				pnt[0][k].y = tochka[k].y;
				pnt[1][k].x =  tochka[soot(k)].x;
				pnt[1][k].y = 	tochka[soot(k)].y;
			
				float tmp2x = (tochka[soot(k)].x-light[i].x);
				float tmp2y = (tochka[soot(k)].y-light[i].y);
						
				float tmp3x = (tochka[k].x-light[i].x);
				float tmp3y = (tochka[k].y-light[i].y);		
				
				pnt[2][k].x =tochka[soot(k)].x+tmp2x * (0.500);
				pnt[2][k].y =tochka[soot(k)].y+tmp2y * (0.500);
				pnt[3][k].x =tochka[k].x+tmp3x * (0.500);
				pnt[3][k].y =tochka[k].y+tmp3y * (0.500);
			
			 
					
				//	loff;
					    
				pum;
				glBegin(GL_POLYGON);
						glColor4f(0,0,0,shadow_volume/numONLights/18);
						glVertex3f(pnt[0][k].x,pnt[0][k].y,-30);			
						glVertex3f(pnt[1][k].x,pnt[1][k].y,-30);			
						glVertex3f(pnt[2][k].x,pnt[2][k].y,-30);
							glVertex3f(pnt[3][k].x,pnt[3][k].y,-30);
					glEnd();			
				//	lon;	
					pom;
			
			
				}
		}



	//	glBegin(GL_POLYGON);
		
	//		for(int k=0;k<36;k++)
	//			{	
	//			glVertex2f( x + cos(k*10*_torad)* radius*2,y + sin(k*10*_torad)* radius *2) ;
	
	//			}
	//		glEnd();

	*/			

//return;

		
 static PointF pnt2[4];
	for(int k=0;k<36;k++)
				{	
				tochka[k].x = x + cos(k*10*_torad)* radius;
				tochka[k].y = y + sin(k*10*_torad)* radius;
				}

			
				glBegin(GL_QUADS);	
			
					
				
				
			
					for(int i=0; i<numLights; i++)
					{
						if(!onlgt[i]) 
							continue;

						float tmp2x = (tochka[nt2[i]].x-light[i].x);
						float tmp2y = (tochka[nt2[i]].y-light[i].y);
						
						float tmp3x = (tochka[nt1[i]].x-light[i].x);
						float tmp3y = (tochka[nt1[i]].y-light[i].y);
					
	
							
							pnt2[0].x = tochka[nt1[i]].x; 
							pnt2[0].y = tochka[nt1[i]].y;
							
							pnt2[1].x =  tochka[nt2[i]].x;
							pnt2[1].y = 	tochka[nt2[i]].y;
			
							
							pnt2[2].x =tochka[nt2[i]].x+tmp2x*0.05;
							pnt2[2].y =tochka[nt2[i]].y+tmp2y*0.05;
						    pnt2[3].x =tochka[nt1[i]].x+tmp3x*0.05;
						    pnt2[3].y =tochka[nt1[i]].y+tmp3y*0.05;
						
			
					
			
				//	loff;
				    	pum;
						glColor4f(0,0,0,shadow_volume/numONLights);
						glVertex3f(pnt2[0].x,pnt2[0].y,-30);			
						glVertex3f(pnt2[1].x,pnt2[1].y,-30);	
						glColor4f(0,0,0,0);						
						glVertex3f(pnt2[2].x,pnt2[2].y,-30);
						glVertex3f(pnt2[3].x,pnt2[3].y,-30);
						pom;
				//	lon;	
				

							//buildgr.FillPolygon(tbr,pnt);
						
					}
					glEnd();
				

				
		}
		
		
		void Show(float addx,float addy)
		{
			if(visible)
			{	
		
			/*	if(NUM==2 || NUM==11) 
				{ 
				
					if(NUM==11 )		glColor3f(onlgt[1],onlgt[1],onlgt[1]);
					
					 if(NUM==2 )	 glColor3f(onlgt[0],onlgt[0],onlgt[0]);


				

					pum;
					glTranslatef(x,y,-30+radius);
					glDisable(GL_LIGHTING);
				
					glutSolidSphere(radius
					,20,20);
					glEnable(GL_LIGHTING);

					pom;
					return;
				}
			*/
				pum;
			
				glTranslatef(x,y,0);
				glColor3f(cred,cgreen,cblue);
			//	glScalef(1 ,1, 7);
			//	glCallList(2);
			glutSolidSphere(radius
					,8,8);
				
				pom;
		
					
				
			
			}

		}


	};



#endif


