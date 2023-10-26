#ifndef F_VECTOR_H
#define F_VECTOR_H
 
#define SLOMO_K 1.0f

	/// <summary>
	/// Summary description for FVector.
	/// </summary>
	class FVector
	{
		
		public: float x0,y0,z0,  // откуда смотрит вектор
					 x1,y1,z1;  // куда смотрит вектор

		public: float r;
		public: float R;
			static  float gravity;
		FVector()
		{
			//
			// TODO: Add constructor logic here
			//
		}
		void calc_kas(float oldx,    
					  float oldy,   
					   // flolat oldz,
					  float x,    
					  float y//,    
							// flolat z
				  	 )  
		{ 

			x0=x;
			y0=y;
		//	z0=z;
			 
			x1=x+(x-oldx);
			y1=y+(y-oldy);
			//z1=z+(z-oldz);

		}
		
		void  calc_gravity()
		{
			y1-=gravity/SLOMO_K;
		}

		void  calc_antigravity()
		{
			y1+=gravity/SLOMO_K;
		}

		void  calc_in_water( )
		{	
			y1+= (gravity/SLOMO_K + gravity/SLOMO_K*0.4f);
		}
		
		void  calc_veter(float massa, float xa,float ya )
		{
			x1+=gravity/SLOMO_K;
		}

		void add(FVector *vector)
		{
		
		}

		void addImpulse(float impx, float impy)
		{
			this->x1 += impx; 
			this->y1 += impy;
		}

	};




#endif

	/*	void ResultofAddVect(FVector *FRES,FVector A,FVector  B)
	{

		FRES->x0=A.x0;
		FRES->y0=A.y0;
 		FRES->x1=A.x1+B.x1-FRES->x0;
		FRES->y1=A.y1+B.y1-FRES->y0;
	}
 */

