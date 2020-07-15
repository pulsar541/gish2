#ifndef MY_LINE
#define MY_LINE


#include "canvas.h"

 class MyLine
	{
 
		public:
		PointF a;
		PointF b;
		
		PointF med;
		
		PointF KK ;
		float Length ;

		int rotMode ;	
		bool Rotable ;
		bool Bad ;		
		bool Lift ;		
		
		PointF pnt[4]  ;
		float ang;
		
	
		 float Angle;
		
		 float OldAngle;

		 float dA;
		 int NUM;
		 float Width;

		 bool invertNormal;

		 MyLine ()
		 {}
		void set(float x1, float y1, float x2, float y2 ,float Width, int num)
		{
			this->Width=Width;

			invertNormal = false;

//			PointF tmpp;
		
			Angle = ang=0;

			 Rotable = false;
			  Bad = false;		
			  Lift = false;	
			NUM = num;
			a.x = x1;
			a.y = y1;

			b.x = x2;
			b.y = y2;

		
		//	if(b.x<a.x)
		//	{	tmpp = a;	
		//		a = b; 
		//		b = tmpp;
		//	
		//	}
			
			med.x = (a.x+b.x)*0.5f;
			med.y = (a.y+b.y)*0.5f;		
			
			KK =  KKK();

			Length = (float)sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y)*(a.y - b.y));
			
			
		//	Rotate (Angle);
		}
		
		 void SetRotable(bool f1,int f2)
		{
			Rotable = f1;
			rotMode = f2;
		
		}
		
		 void SetBad(bool f)
		{
			Bad = f;
			
		}		
		
		 void SetLift(bool f)
		{
			Lift = f;
		}			
	
		
		 void Rotate (float angle)
		{return;
		 //  PointF rotPnt;

		//	if (rotMode == 0) 
			{	a.x = med.x - (float)cos (angle*_torad)*Length*0.5f;
				a.y = med.y - (float)sin (angle*_torad)*Length*0.5f;
			
				b.x = med.x + med.x - a.x;
				b.y = med.y + med.y - a.y;
					
		//		if(NUM<0)
			//	{
			//		b.x = med.x ;
			//		b.y = med.y ;
			//	}
	
			}



	/*		if (rotMode == 1) 
			{
				b.x = a.x + (float)cos (angle*_torad)*Length;
				b.y = a.y + (float)sin (angle*_torad)*Length;
			}
		*/
			if(b.x<a.x)
				{	PointF  tmpp = a;	a = b; b = tmpp;
		
				}
	
			
		}
					
		 PointF  KKK()
		{
	
			PointF rezz ;

			float nx = a.x-b.x;
			float ny = a.y-b.y;
			float L = 1/sqrt (nx*nx + ny*ny);
			nx*=L;
			ny*=L;  
	
			

			if(!invertNormal)
			{
			rezz.x = ny ;
			rezz.y = -nx;
			}
			else
			{
			rezz.x = -ny ;
			rezz.y = nx;
			}

			return rezz; 

		}
		
		 void Show2D ()
		 { 	 glLineWidth(1);
			 pum doff 
				 loff
		 	
	 	
			 glColor3f(0,0,0);
			
			 glBegin(GL_LINES);
			 glVertex3f(a.x,a.y,Width+3);
			 glVertex3f(b.x,b.y,Width+3);
			 glEnd();
				
			pom don lon
		 }
			 

		 void Show ()
		{	

			 pum;


			 glBegin(GL_TRIANGLES);
			 tr2(a.x,a.y,Width,
				b.x,b.y,Width,
				b.x,b.y,0);

			 tr2(b.x,b.y,0,
				a.x,a.y,0,
				a.x,a.y,Width);
			glEnd();



			pom;
			
		}

		void ShowLite ()
		{	

			 pum;

			 tr(a.x,a.y,Width,
				b.x,b.y,Width,
				b.x,b.y,-Width);

			 tr(b.x,b.y,-Width,
				a.x,a.y,-Width,
				a.x,a.y,Width);
			pom;
			
		}


		
		 void ShowF ()
		{	

			 pum;


			
			 glBegin(GL_TRIANGLES);
			 tr(a.x,a.y,Width,
				b.x,b.y,Width,
				b.x,b.y,-30);

			 tr(b.x,b.y,-30,
				a.x,a.y,-30,
				a.x,a.y,Width);
			glEnd();



			pom;
			
		}
	
		void ShowShadow (bool flag, PointF *light, float *onlgt)		
		{
		//	 doff


			static int numLights=(((int)sizeof(light))>>1);
		

			int numONLights = 0;
			for (int i=0; i<numLights;i++ )
			 if(onlgt[i]) numONLights++;

						
			for(i=0; i<numLights; i++)
			{
				if(!onlgt[i]) 
				continue;


				//float mtx = (med.x-light[i].x);
				//float mty = (med.y-light[i].y);	
				
				//float kk = (float)Math.Sqrt(mtx*mtx +mty*mty );	
				
				float tmp2x = (b.x-light[i].x);
				float tmp2y = (b.y-light[i].y);
				float tmp3x = (a.x-light[i].x);
				float tmp3y = (a.y-light[i].y);
				
	
					
				

			/*		
				tmp2x /= kk;
				tmp2y /= kk;
				tmp3x /= kk;
				tmp3y /= kk;
				*/
			//	int ck=220-flag*50;
			//	float dk = 0.2f;
				
		
			
				pnt[0].x = a.x;
				pnt[0].y = a.y;			
				
				pnt[1].x =  b.x;
				pnt[1].y = 	b.y;
				
				
				pnt[2].x =b.x+tmp2x*1000;
				pnt[2].y =b.y+tmp2y*1000 ;
			    pnt[3].x =a.x+tmp3x*1000 ;
			    pnt[3].y =a.y+tmp3y*1000 ;

	
					pum;
					
					loff;

					bloff;
							
					glDisable (GL_CULL_FACE);
					glBegin(GL_QUADS);
				
				//	glColor4f(0,0,0,shadow_volume/numONLights);
					
					//	glColor4f(0.1,0.1,0.1,0.2);	
						glColor3f(0,0,0);
						
						if(SH1)
						{
						glVertex3f(pnt[0].x,pnt[0].y,Width+3);
						glVertex3f(pnt[1].x,pnt[1].y,Width+3);
					//	glColor4f(0,0,0,1);	
					
						glVertex3f(pnt[2].x,pnt[2].y,Width+3);
						glVertex3f(pnt[3].x,pnt[3].y,Width+3);
						}

						glVertex3f(pnt[0].x,pnt[0].y,10);
						glVertex3f(pnt[1].x,pnt[1].y,10);

						glVertex3f(pnt[2].x,pnt[2].y,10);
						glVertex3f(pnt[3].x,pnt[3].y,10);

/*
						glVertex3f(pnt[2].x,pnt[2].y,-30);
						glVertex3f(pnt[3].x,pnt[3].y,-30);
						glVertex3f(pnt[3].x+tmp3x*500,pnt[3].y+tmp3y*500,-30);
						glVertex3f(pnt[2].x+tmp2x*500,pnt[2].y+tmp2y*500,-30);
*/

					glEnd();


					blon;
					lon;		
					pom;
						glEnable(GL_CULL_FACE);

				//	if(UDANG>-50) continue;
					
				/*
					pum;
						glDisable (GL_CULL_FACE);
					loff;
					glBegin(GL_QUADS);
						glColor4f(0,0,0,shadow_volume/numONLights);	
						glVertex3f(pnt[0].x,pnt[0].y,150);
						glVertex3f(pnt[1].x,pnt[1].y,150);
						glColor4f(0,0,0,shadow_volume);
						glVertex3f(pnt[2].x,pnt[2].y,150);
						glVertex3f(pnt[3].x,pnt[3].y,150);
					glEnd();
					glEnable(GL_CULL_FACE);

					lon;	
					pom;
*/
				
			}
		
			
			//linegr.DrawString(KK.y.ToString(),new Font("arial",10),Brushes.Black,0.5f*(a.x+b.x)-5f,0.5f*(a.y+b.y)+5f);
			//linegr.DrawString(KK.x.ToString(),new Font("arial",10),Brushes.Black,0.5f*(a.x+b.x)-5f,0.5f*(a.y+b.y)-15f);			
		//	don
		}
	};

#endif