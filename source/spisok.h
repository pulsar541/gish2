#ifndef SPISOK_H
#define SPISOK_H


void spisok()
{
	bool f=true;
	glNewList(50005,GL_COMPILE);
	pum;

		glTranslatef(0,0,-1000);	
	
//	glEnable(GL_POLYGON_SMOOTH);
		glNormal3f(0,0,1);
	//	glBegin(GL_TRIANGLES);

		glBegin(GL_QUADS);
		glColorMaterial(GL_FRONT_AND_BACK, GL_SPECULAR);
		glEnable(GL_COLOR_MATERIAL);
		for(int i=0;i<limitX;i+=limitX*0.03)
		for(int j=0;j<limitY;j+=limitY*0.03)	
		{		
			f=!f;

			if(minirand()>0.5)
				continue;
			
	//		glTranslatef(i,j,45);
	//		glutSolidCube(limitX*0.01);


		//	float col = 1-minirand()*0.2;
		//	glColor3f(col,col,col);

		glColor3f(
			1-minirand()*0.1,
			1-minirand()*0.1,
			1-minirand()*0.1);
		
	/*		float z = -40;
			glVertex3f(i+limitX*0.01,j,z);	
			glVertex3f(i+limitX*0.01,j+limitY*0.01,z);
			glVertex3f(i,j+limitX*0.01,z);
			glVertex3f(i,j,z);
*/

/*
			if(f)
			{
				glColor3f(1-minirand()*0.2,1-minirand()*0.2,1-minirand()*0.2);
				tr(i,j,0,i+limitX*0.01-1,j,0,i+limitX*0.01-1,j+limitY*0.01-1,0);
			//	glColor3f(1-minirand()*0.2,1-minirand()*0.2,1-minirand()*0.2);
				tr(i,j,0,i,j+limitY*0.01-1,0,i+limitX*0.01-1,j+limitY*0.01-1,0);
			}
			else
			{
				glColor3f(1-minirand()*0.2,1-minirand()*0.2,1-minirand()*0.2);
				tr(i+limitX*0.01-1,j,0,i,j,0,i,j+limitY*0.01-1,0);
			
			//	glColor3f(1-minirand()*0.2,1-minirand()*0.2,1-minirand()*0.2);
				tr(i+limitX*0.01-1,j,0,
					i,j+limitY*0.01-1,0,
					i+limitX*0.01-1,j+limitY*0.01-1,0);				
				
			///	
			//	glColor3f(1-minirand()*0.2,1-minirand()*0.2,1-minirand()*0.2);
			//	tr(i,j,0,i,j+limitY*0.01-1,0,i+limitX*0.01-1,j+limitY*0.01-1,0);		
			}
*/


//
			{
	//	//	glColor3f(0,0,0);	
		//	glBegin(GL_QUADS);
			glVertex3f(i,j,0);
			glVertex3f(i+limitX*0.03,j,0);
			glVertex3f(i+limitX*0.03,j+limitY*0.03,0);
			glVertex3f(i,j+limitY*0.03,0);

		//	glEnd();
			}


		}
	glEnd();
	
//	glDisable(GL_POLYGON_SMOOTH);
		pom;
	glEndList();

	glNewList(3,GL_COMPILE);
	pum;

		glTranslatef(0,0,-10);	
	
	
		//glNormal3f(0,0,-1);

		for(int j=0;j<limitY;j+=limitY*0.04)	
		for( i=0;i<limitX;i+=limitX*0.04)
		{		

			if(rand()%100>70)
			{
				float p1 = minirand();
				float p2 = minirand();
				float p3 = minirand();
				float p4 = minirand();
				float p5 = minirand();
				float p6 = minirand();
				float p7 = minirand();
			doff
			glColor3f(0,0,0);
			glBegin(GL_LINE_STRIP);
			glVertex3f(i,j,-1000);
			glVertex3f(i+limitX*0.1*p1,j,-1000+p2*5);
			glVertex3f(i+limitX*0.1*p3,j+limitY*0.1*p4,-1000+p5*5);
			glVertex3f(i,j+limitY*0.1*p6,-1000+p7*5);		
			glEnd();
			don


		//	glColor3f(0.5,0.5,0.5);
			glColor3f(.7,.7,.7);
			glBegin(GL_QUADS);
			glVertex3f(i,j,-1000);
			glVertex3f(i+limitX*0.1*p1,j,-1000+p2*5);
			glVertex3f(i+limitX*0.1*p3,j+limitY*0.1*p4,-1000+p5*5);
			glVertex3f(i,j+limitY*0.1*p6,-1000+p7*5);
			glEnd();


			}

		}

		pom;
	glEndList();


	glNewList(2,GL_COMPILE);
	glutSolidSphere(1,6,6);
	glEndList();

}
#endif 