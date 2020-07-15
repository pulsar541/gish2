#include "idle.h"

#include "MyGish.h"


void Collisions()
{


		for( int i=0;i<gislh.N;i++)	
			gish.bui[i]->inWater = false;


		for(iter_water=water.begin();    iter_water!=water.end(); 	iter_water++)
		{

			if(	(iter_water)->ACTUAL )
			{
				for( int i=0;i<gish.N;i++)	
				{	(iter_water)->Collision(gish.bui[i]);
					

						
				}	
				
				if((iter_water)->Tak(gish.medium()))
					gish.DelOx=true;
			}


		}





		for(int n = 0; n < n_prim_graph_actual.size(); n++)
		{
		
				if(prim[n_prim_graph_actual[n]].ACTUAL )
				{
					gish.Colliz(&prim[n_prim_graph_actual[n]],NUM_TR);
					
///						for( int i=0;i<gish.N;i++)	
///							prim[n_prim_graph_actual[n]].Collision(gish.bui[i], !gish.SKOL);
			
						
				}

		}
		

		
		ball[0].x = 3400;
		ball[0].y =	limitY-720;

		ball[ball.size()-1].x = 3800;
		ball[ball.size()-1].y =	limitY-720;
		
		TROS(&ball,15,5000);
	
		for(pBall=ball.begin(); pBall!=ball.end(); pBall++)
		{
			pBall->Calc(1);
			pBall->Move();
			for( int i=0;i<gish.N;i++)	
			{

				if(gish.LIP && Dist(gish.bui[i],pBall)<gish.bui[i]->radius+pBall->radius+5)
				{
					SVIAZKA(gish.bui[i],pBall,14,5000);
				}
				else 	Proch(pBall,	gish.bui[i],	gish.bui[i]->radius+pBall->radius);

			}
		}

	//	
			
		

}




DWORD starttime1=timeGetTime(),time_1;
DWORD starttime2=timeGetTime(),time_2;
DWORD starttime3=timeGetTime(),time_3;
DWORD tGT=timeGetTime ();


void myIdle()
{ 

   tGT = timeGetTime ();         
   time_1 = tGT-starttime1; 
   time_2 = tGT-starttime2; 
   time_3 = tGT-starttime3;
 

  if ( time_2 > 1000/15 )  
   {
   	 starttime2 += time_2; 


	  gish.Red = false;


	  n_prim_graph_actual.empty();
	  n_prim_graph_actual.clear();
	  
	  static int NUMPRIMS = prim.size();

	  for(int n = 0;  n<NUMPRIMS; 	n++)
	  {
	   
	     	prim[n].GRAPH_ACTUAL = 
			((prim[n]).boxMIN.X > gish.boxMIN.X - 2000 && 
			 (prim[n]).boxMAX.X < gish.boxMAX.X + 2000 && 
			 (prim[n]).boxMIN.Y > gish.boxMIN.Y - 2000 && 				   
			 (prim[n]).boxMAX.Y < gish.boxMAX.Y + 2000 );

			if((prim[n]).GRAPH_ACTUAL)
			{
				n_prim_graph_actual.push_back(n);

				(prim[n]).ACTUAL =
				((prim[n]).boxMIN.X > gish.boxMIN.X - 100 && 
				 (prim[n]).boxMAX.X < gish.boxMAX.X + 100 && 
				 (prim[n]).boxMIN.Y > gish.boxMIN.Y - 100 && 				   
				 (prim[n]).boxMAX.Y < gish.boxMAX.Y + 100 );

				if((prim[n]).isDepth)
					(prim[n]).ACTUAL = false;

				

				if
				 ((prim[n]).boxMIN.X > gish.boxMIN.X - 300 && 
				 (prim[n]).boxMAX.X < gish.boxMAX.X + 300 && 
				 (prim[n]).boxMIN.Y > gish.boxMIN.Y - 150 && 				   
				 (prim[n]).boxMAX.Y < gish.boxMAX.Y + 150 )
			//	 if((iter_prim)->ACTUAL)
					 (prim[n]).isLegal = true;


			}




			if (ORTHO)
				(iter_prim)->GRAPH_ACTUAL = true;

	}		
		


	static int t_ = 0;
	for(iter_water=water.begin();    iter_water!=water.end(); 	iter_water++)
	{

	     	(iter_water)->GRAPH_ACTUAL = 
			((iter_water)->boxMIN.X > gish.boxMIN.X - 1000 && 
			 (iter_water)->boxMAX.X < gish.boxMAX.X + 1000 && 
			 (iter_water)->boxMIN.Y > gish.boxMIN.Y - 1000 && 				   
			 (iter_water)->boxMAX.Y < gish.boxMAX.Y + 1000 );
		

			if (iter_water->GRAPH_ACTUAL)
			{
				if(t_++>10)		
				{
						(iter_water)->randomddd();
					t_=0;

				}

	     		(iter_water)->ACTUAL = 
				((iter_water)->boxMIN.X > gish.boxMIN.X - 400 && 
				 (iter_water)->boxMAX.X < gish.boxMAX.X + 400 && 
				 (iter_water)->boxMIN.Y > gish.boxMIN.Y - 250 && 				   
				 (iter_water)->boxMAX.Y < gish.boxMAX.Y + 250 );
				if (iter_water->ACTUAL)
					iter_water->isLegal = true;




			}
			
			if (ORTHO)
				(iter_water)->GRAPH_ACTUAL = true;
	}					   


      
   if (time_1 > 1000/100 )  
   {
	
	   starttime1 += time_1; 
	   static float deltaOpen[4];
	   static int napr=1;
	   static int  TT = 0;
	   
	   if(TT++>300) {TT=0; napr=-napr;}

		MEDGISH = gish.medium();

		light[0].X= gish.medium().X; 
		light[0].Y= gish.medium().Y+10; 

		light[1].X = 0; 
		light[1].Y = 4000;

	
	   if(gish.LIP && !gish.SKOL)	
		   gish.Slipanie(&prim,NUM_TR);
	   
	   
	   Collisions();
	   gish.CalcAndMove(y);
 
  }
  
  if(time_3>1000/100)
	   {
		  try
		  {
  			glutPostRedisplay();
		  }
		  catch(...){}
		starttime3+=time_3;

	   }


}




