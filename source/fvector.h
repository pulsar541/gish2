#ifndef F_VECTOR_H
#define F_VECTOR_H
 
#define SLOMO_K 1.0f

	/// <summary>
	/// Summary description for FVector.
	/// </summary>
	class FVector
	{
		
		public: float x0,y0,z0,  // ������ ������� ������
					 x1,y1,z1;  // ���� ������� ������

		public: float r;
		public: float R;
			static  float gravity;
		FVector();
		void calc_kas(float oldx,    
					  float oldy,   
					   // flolat oldz,
					  float x,    
					  float y//,    
							// flolat z
				  	 );
		
		void  calc_gravity();

		void  calc_antigravity();

		void  calc_in_water( );
		
		void  calc_veter(float massa, float xa,float ya );

		void add(FVector *vector);

		void addImpulse(float impx, float impy);

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

