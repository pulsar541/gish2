#ifndef PHYS_H
#define PHYS_H

#include<iostream>



		bool  Proch(Unit *u1, Unit *u2,float dist)
		{	

			if(fabs(u1->x - u2->x) > (u1->radius + u2->radius)) return false;
			if(fabs(u1->y - u2->y) > (u1->radius + u2->radius)) return false;

			if(u1->spirit || u2->spirit)
				return false;

			bool res;
			if(Dist(u1,u2)-(dist)<0) res=true;
			else  res=false;
			u1->onAlienUnit = false;	
			u2->onAlienUnit = false;
			for(int c=0;Dist(u1,u2)-(dist)<0 && c<1000;c++)
			{ 
					u1->x+= 0.02f*(u1->x - u2->x);
					u1->y+= 0.02f*(u1->y - u2->y);
				
			
					u2->x+= 0.02f*(u2->x - u1->x);	
					u2->y+= 0.02f*(u2->y - u1->y);	
				
					u1->onAlienUnit = true;
					u2->onAlienUnit = true;
			}
			return res;
	
		}


		bool  ProchUnitOne(Unit *u1, Unit *u2,float dist)
		{	
			bool res;
			if(Dist(u1,u2)-(dist)<0) res=true;
			else  res=false;

			for(int c=0;Dist(u1,u2)-(dist)<0 && c<1000;c++)
			{ 	
					u1->x+= 0.02f*(u1->x - u2->x);
					u1->y+= 0.02f*(u1->y - u2->y);
			}
			return res;
	
		}
		void  ProchM(Unit *b1, Unit *b2,float dist,int k)
		{
			for(int c=0;Dist(b1,b2)-(dist)<0 && c<k;c++)
			{ 

					b1->x+= 0.02f*(b1->x - b2->x);
					b1->y+= 0.02f*(b1->y - b2->y);
					b2->x+= 0.02f*(b2->x - b1->x);	
					b2->y+= 0.02f*(b2->y - b1->y);
				
			}
		
		}

		
		bool  Proch(Unit *b1, PointF *p,float dist)
		{
			bool res;
			if(Dist(b1,p)-(dist)<=0) res=true;
			else  res=false;
		
			for(int c=0;Dist(b1,p)-(dist)<=0 && c<1000;c++)
			{ 
				b1->x+= 0.01f*(b1->x - p->x);
				b1->y+= 0.01f*(b1->y - p->y);
				
			}
			return res;
	
		}




		void SVIAZKA(Unit *u1,Unit *u2, float dist,int K)
		{
			
			if(u1->spirit || u2->spirit)
				return ;

					for(int c=0;Dist(u1,u2)-(dist)>0 && c<K;c++)
						{
		
									u1->y-= 0.001*(u1->y - u2->y);
									u1->x-= 0.001*(u1->x - u2->x);
									u2->y-= 0.001*(u2->y - u1->y);
									u2->x-= 0.001*(u2->x - u1->x);	
						}		

					for(int c=0;Dist(u1,u2)-(dist)<0 && c<1000;c++)
						{

									u1->y+= 0.001*(u1->y - u2->y);
									u1->x+= 0.001*(u1->x - u2->x);
									u2->y+= 0.001*(u2->y - u1->y);
									u2->x+= 0.001*(u2->x - u1->x);							
						}				
				
		}

	
		void S_VIAZKA(Unit *u1,Unit *u2, float dist,int K)
		{	
			
			if(u1->spirit || u2->spirit)
				return ;

			 
			for(int c=0;Dist(u1,u2)-(dist)>0 && c<K;c++)
				{
		
							u1->y-= 0.01*(u1->y - u2->y);
							u1->x-= 0.01*(u1->x - u2->x);
							u2->y-= 0.01*(u2->y - u1->y);
							u2->x-= 0.01*(u2->x - u1->x);	
				}	
				

			for(int c=0;Dist(u1,u2)-(dist)<0 && c<K;c++)
				{

							u1->y+= 0.01*(u1->y - u2->y);
							u1->x+= 0.01*(u1->x - u2->x);
							u2->y+= 0.01*(u2->y - u1->y);
							u2->x+= 0.01*(u2->x - u1->x);							
				} 
									
				
		}

		void SVIAZKA_UnitOne(Unit *u1,Unit *u2, float dist,int K)
		{
			
			if(u1->spirit || u2->spirit)
				return ;

					for(int c=0;Dist(u1,u2)-(dist)>0 && c<K;c++)
						{
		
									u1->y-= 0.01*(u1->y - u2->y);
									u1->x-= 0.01*(u1->x - u2->x);

						}		

					for(int c=0;Dist(u1,u2)-(dist)<0 && c<1000;c++)
						{

									u1->y+= 0.01*(u1->y - u2->y);
									u1->x+= 0.01*(u1->x - u2->x);						
						}				
				
		}

		void TROS(Unit **u,int n1,int n2,float dist,int k)
		{

			for(int i=n1;i<n2;i++)			
				SVIAZKA(u[i],u[i+1], dist ,k);	
			
			for(int i=n1+1;i<n2+1;i++)			
				SVIAZKA(u[i],u[i-1], dist ,k);	

		}



		void TROS(vector<Building> *ball,float dist,int k)
		{
	
			//vector<Building>::iterator pBall;
			//for(pBall=ball->begin(); pBall!=ball->end()-1; pBall++)
			int N = ball->size();
			Building* pBall;
			Building* pBallNext;
			for (int i = 0; i < N-1; i++)
			{

				pBall = &ball->at(i);
				pBallNext = &ball->at(i+1);
				 
				S_VIAZKA(pBall,pBallNext, dist ,k);	
			}
			
		}



		void PROCH(Unit *u1,Unit *u2, float dist,int K)
		{	
	
					for(int c=0; Dist(u1,u2)-(dist)<0 && c<K;c++)
					{
						

						u1->y+=  0.02*(u1->y - u2->y)/Dist(u1,u2);
						u1->x+=  0.02*(u1->x - u2->x)/Dist(u1,u2);	
						u2->y+=  0.02*(u2->y - u1->y)/Dist(u1,u2);
						u2->x+=  0.02*(u2->x - u1->x)/Dist(u1,u2);			
						

					}

		}


	void  Proch(Unit *b, MyLine *line)
	{
			
	
		if(Dist(b,&line->a)<b->radius)  Proch(b,&line->a,b->radius);
		if(Dist(b,&line->b)<b->radius)  Proch(b,&line->b,b->radius);

	/*	float dd1;
		float dd2 ;		
		


		dd1 = distance (line->a,
					        line->b,
							PointF(b->x,b->y));
		
		dd2 = distance (line->a,
					         line->b,
							 PointF(b->oldx,b->oldy));*/	

		
	/*	if(SIGN(dd1)!= SIGN(dd2) 
			&& CircleIntersects(&b->x,&b->y,b->radius, line->Length, line->a,line->b))
		
		{
			b->x-=b->dx;
			b->y-=b->dy;

		}*/
			
			
	//	for(int o=0;o<10;o++)
		while(CircleIntersects(&b->x,&b->y,b->radius, line->Length, line->a,line->b))
		{
						b->x+=0.1f * line->KKK().x ;
						b->y+=0.1f * line->KKK().y ;	
		}
								
				
	}	
	
	int  Collision(Unit *u, Primitive *primitive)
	{
	
		int result = -1;

		if(u->spirit)
			return -1;

		if(!primitive->corrected())
			return -1;


		int c=0;
		int numNL = 0;
		if(primitive == NULL)
		{	//MessageBox(NULL,"primitive == NULL","primitive == NULL",MB_OK);
			return -1;
		}
	//	cout<<primitive->NUM<<' ';
		if(primitive->type < 0 || primitive->type >4 )
		{	//MessageBox(NULL,"primitive->type < 0 || primitive->type >3","primitive->type < 0 || primitive->type >3",MB_OK);
			return -1;
		}
				
	//	int flag=0;
		switch (primitive->type)
		{

			case FORBOMB:
			case GEO:
			case ICE:			
		
				if(primitive->inBox(u)) 
				{
					numNL = primitive->numNearLine(PointF(u->x,u->y));
				//	u->onHard = false;
					if(primitive->isHalfBox)
					{
					
						PointF normal = primitive->line[numNL].KKK();

						u->x += normal.x * 0.5 * SIGN(distance(primitive->line[numNL].a,primitive->line[numNL].b , PointF(u->x,u->y)));
						u->y += normal.y * 0.5 * SIGN(distance(primitive->line[numNL].a,primitive->line[numNL].b , PointF(u->x,u->y)));
					
						if(primitive->type!=ICE)
						{
							
							if(u->friction)
							{	u->dx = 0;
								u->dy = 0;
								u->Move();
							}
						}
						u->onHard = true;
						
					}

				//	u->onHard = false;
					for(c=0; primitive->inBox(u) && primitive->pointInPrimitive(PointF(u->x,u->y )) ;)
					{ 
						
						u->x += primitive->line[numNL].KKK().x * 0.5 * SIGN(distance(primitive->line[numNL].a,primitive->line[numNL].b , PointF(u->x,u->y)));
						u->y += primitive->line[numNL].KKK().y * 0.5 * SIGN(distance(primitive->line[numNL].a,primitive->line[numNL].b , PointF(u->x,u->y)));
					
						if(primitive->type!=ICE)
						{
							if(u->friction)
							{
								u->dx = 0;
								u->dy = 0;
								u->Move();
							}
						}

						u->onHard = true;				
					}

				/*	if(primitive->inBox(u) && primitive->isHalfBox  && primitive->type==ICE)
					{
						if((u->y - u->dy) < primitive->boxMAX.y 
							&&  fabs(u->y - primitive->boxMAX.y ) < fabs(u->y - primitive->boxMIN.y ))
							u->y =primitive->boxMAX.y;
							

					}*/

				}

				if(u->radius > 0)
				{
					
					for(int c=0;c<3;c++)
					{
					
				
						Proch(u,&primitive->line[c].a,u->radius);
						Proch(u,&primitive->line[c].b,u->radius);
							
						while(trigonom::CircleIntersects(&u->x,&u->y,u->radius,
							primitive->line[c].Length, 
							primitive->line[c].a,
							primitive->line[c].b))
						{
							u->x+=0.1f * primitive->line[c].KKK().x ;
							u->y+=0.1f * primitive->line[c].KKK().y ;
							u->onHard = true;	
							result = primitive->NUM;
							u->onHard = true;
							
							if(primitive->type==ICE || !u->friction) {}
							else
							{
							
								u->dx = 0;
								u->dy = 0;
								u->Move();
									
									
							}
							
						}
					
	
					
					}
				
				}


				//	Proch(u, &primitive->line[numNL]);			

				break;
			case SAND:
				if( primitive->inBox(u))
				{	if(primitive->pointInPrimitive(PointF(u->x,u->y ))	)
					{ 
						u->dx = 0;
						u->dy = 0;
						u->Move();
						result = primitive->NUM;
					}
				}
				break;
			case HYDRO:
	
				if(primitive->inBox(u)) 
				{
					if(primitive->isHalfBox  )
					{	 
						u->inWater = true;
						result = primitive->NUM;
						break;
					}

					if(primitive->pointInPrimitive(PointF(u->x,u->y)))
					{	 
						u->inWater = true;
						result = primitive->NUM;
					}
					
				}

			break;
			default: 
			
				result = -1;
				break;

		}

		
		return result;		
	}



				
	
		



#endif 