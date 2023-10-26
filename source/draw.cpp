#include "draw.h"
#include "glut.h"
#include "trigonom.h"

float dddx[10000];
float dddy[10000];
bool lx[10000];
bool ly[10000];



 void draw::SetDif(float r, float g, float b)
{
	GLfloat	diffuse[4] = { r,g,b,1 };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

}

 void draw::ShowGish(MyGish* mygish)
{

	pum;

	glDisable(GL_CULL_FACE);


	//	loff;
	//	glColor3f(0,0,0);


	glColor3f(0.7, 0.7, 0.7);

	if (0)//mygish->TVER) 
	{
		lon

			glBegin(GL_TRIANGLES);
		for (int i = 0; i<mygish->N - 1; i++)
		{	//glColor3f(mygish->bui[i]->cred,   mygish->bui[i]->cgreen, mygish->bui[i]->cblue);


			glColor3f(1, 0, 0);
			float a = 0;
			if (mygish->TVER) { a = 50; lon }

			loff

				tr(mygish->bui[i + 1]->x, mygish->bui[i + 1]->y, a,
					mygish->bui[i]->x, mygish->bui[i]->y, 2,
					(mygish->medium().x + mygish->bui[i]->x) / 2, (mygish->medium().y + mygish->bui[i]->y) / 2, 0);

			lon

				tr((mygish->medium().x + mygish->bui[i + 1]->x) / 2,
					(mygish->medium().y + mygish->bui[i + 1]->y) / 2,
					0,
					mygish->bui[i + 1]->x, mygish->bui[i + 1]->y,
					2 + a,
					(mygish->medium().x + mygish->bui[i]->x) / 2, (mygish->medium().y + mygish->bui[i]->y) / 2, 0);
		}

		tr(mygish->bui[0]->x, mygish->bui[0]->y, 2,
			mygish->bui[mygish->N - 1]->x, mygish->bui[mygish->N - 1]->y, 2,
			(mygish->medium().x + mygish->bui[mygish->N - 1]->x) / 2, (mygish->medium().y + mygish->bui[mygish->N - 1]->y) / 2, 00);


		tr((mygish->medium().x + mygish->bui[0]->x) / 2, (mygish->medium().y + mygish->bui[0]->y) / 2, 00,
			mygish->bui[0]->x, mygish->bui[0]->y, 2,
			(mygish->medium().x + mygish->bui[mygish->N - 1]->x) / 2, (mygish->medium().y + mygish->bui[mygish->N - 1]->y) / 2, 00);


		glEnd();

	}


	glColor4f(0.5, 0.5, 0.5, 1);

	if (mygish->LIP)
	{
		loff;
		glColor3f(0, 1, 0);

	}


	/*	if(!mygish->TVER )
	{

	glBegin(GL_TRIANGLES);
	for(int i=0;i<mygish->N-1;i++)
	{

	//	glColor3f(bui[i]->cred,   bui[i]->cgreen, bui[i]->cblue);

	if(!mygish->LIP ||  mygish->LIP && i%2 )
	{
	tr( mygish->bui[i]->x,  mygish->bui[i]->y,   0,
	mygish->bui[i]->x,  mygish->bui[i]->y,   50,
	mygish->bui[i+1]->x,mygish->bui[i+1]->y  ,50);
	tr( mygish->bui[i+1]->x,  mygish->bui[i+1]->y,   50,
	mygish->bui[i+1]->x,  mygish->bui[i+1]->y,   0,
	mygish->bui[i]->x,mygish->bui[i]->y  ,0);
	}
	}

	tr( mygish->bui[mygish->N-1]->x,  mygish->bui[mygish->N-1]->y,   0,
	mygish->bui[mygish->N-1]->x,  mygish->bui[mygish->N-1]->y,   50,
	mygish->bui[0]->x,mygish->bui[0]->y  ,50);
	tr( mygish->bui[0]->x,  mygish->bui[0]->y,   50,
	mygish->bui[0]->x,  mygish->bui[0]->y,   0,
	mygish->bui[mygish->N-1]->x,mygish->bui[mygish->N-1]->y  ,0);

	glEnd();

	}*/



	//	if(!mygish->TVER )
	{

		/*	glBegin(GL_TRIANGLES);
		for(int i=0;i<mygish->N-1;i++)
		{
		float xi = (mygish->bui[i]->x + mygish->medium().x)/2;
		float yi = (mygish->bui[i]->y + mygish->medium().y)/2;

		float xii = (mygish->bui[i+1]->x + mygish->medium().x)/2;
		float yii = (mygish->bui[i+1]->y + mygish->medium().y)/2;



		tr( xi,  yi,   0,
		xi,  yi,   50,
		xii, yii  ,50);
		tr( xii,  yii,   50,
		xii,  yii,   0,
		xi,yi  ,0);

		}

		glEnd();
		*/
		lon;

		for (int i = 0; i<mygish->N; i++)
		{



			float xii = (mygish->bui[i]->x + mygish->medium().x) / 2; // seredina
			float yii = (mygish->bui[i]->y + mygish->medium().y) / 2;

			float xiii = (xii + mygish->bui[i]->x) / 2; // krai i seredina
			float yiii = (yii + mygish->bui[i]->y) / 2;

			float xiiii = (xiii + mygish->bui[i]->x) / 2;
			float yiiii = (yiii + mygish->bui[i]->y) / 2;



			pum

				//glColor4f(0.5,0.5,0.5,1);
				glColor3f(0.5, 0.5 * mygish->H / 100, 0.5 * mygish->H / 100);

			if (mygish->H <= 0)
				glColor4f(0.5, 0, 0, 1);

			glTranslatef(xiii, yiii, 0);


			if (mygish->LIP)
			{

				glColor3f(0, 1, 0);
				if (i % 2) {


					//	glColor3f(1,mygish->H/100,mygish->H/100 );
					pum

						glRotatef(90 + trigonom::ugol(
							mygish->bui[i]->x,
							mygish->bui[i]->y,
							mygish->medium().x,
							mygish->medium().y)
							, 0, 0, 1);



					glRotatef(90, 1, 0, 0);
					glTranslatef(0, 0, -18);



					glutSolidCone(11, 10, 8, 8);

					pom

				}
				glutSolidSphere(11, 7, 7);

			}
			else
				glutSolidSphere(18, 7, 7);


			if (mygish->TVER)
			{

				glColor3f(0.5, mygish->H / 200, mygish->H / 200);
				pum

					glRotatef(-90 + trigonom::ugol(
						mygish->bui[i]->x,
						mygish->bui[i]->y,
						mygish->medium().x,
						mygish->medium().y)
						, 0, 0, 1);

				glRotatef(90, 1, 0, 0);
				glutSolidCone(5, 35, 8, 8);
				pom
			}

			lon
				glColor3f(1, mygish->H / 100, mygish->H / 100);
			glTranslatef(0, 0, 10);
			glutSolidSphere(11, 8, 8);





			pom


		}
	}


	lon;
	/*
	if(!mygish->TVER)
	{
	loff;


	//	glColor4fv(mygish->color);
	glColor4f(0,0,0.4,0.4);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(mygish->medium().x, mygish->medium().y ,80);
	for(int i=0;i<mygish->N;i++)
	glVertex3f(mygish->bui[i]->x, mygish->bui[i]->y , 40);
	glEnd();

	lon;
	}

	/*	if(mygish->LIP)
	{
	glColor3f(0,0,0);
	glDisable(GL_LINE_SMOOTH);
	glLineWidth(7);

	glBegin(GL_LINES);
	for(int i=0;i<mygish->N;i++)
	{	glVertex3f(mygish->bui[i]->x,mygish->bui[i]->y,80);
	glVertex3f(mygish->bui[i]->x,mygish->bui[i]->y,50);

	}
	glEnd();

	}*/

	pom
		glEnable(GL_CULL_FACE);

}

 void draw::ShowEnemy(Enemy* enemy)
{
	//	doff

	if (enemy->moveLeft)
	{
		if (enemy->enemyView.angleHorizontal>-70)  enemy->enemyView.angleHorizontal -= 3;
	}
	if (enemy->moveRight)
	{
		if (enemy->enemyView.angleHorizontal<70)  enemy->enemyView.angleHorizontal += 3;
	}

	if (enemy->moveUp)
	{
		if (enemy->enemyView.angleVertical>-20)  enemy->enemyView.angleVertical -= 2;
	}
	if (enemy->moveDown)
	{
		if (enemy->enemyView.angleVertical<20)  enemy->enemyView.angleVertical += 2;
	}

	if (!enemy->moveLeft
		&& !enemy->moveRight)
	{
		if (enemy->enemyView.angleHorizontal<0)  enemy->enemyView.angleHorizontal += 1;
		if (enemy->enemyView.angleHorizontal>0)  enemy->enemyView.angleHorizontal -= 1;
	}

	if (!enemy->moveDown
		&& !enemy->moveUp)
	{
		if (enemy->enemyView.angleVertical<0)  enemy->enemyView.angleVertical += 1;
		if (enemy->enemyView.angleVertical>0)  enemy->enemyView.angleVertical -= 1;
	}



	pum


		//	doff
		glTranslatef(enemy->x, enemy->y, 0);
	if (enemy->health <= 0)
		glTranslatef(0, -enemy->radius * 0.1, 0);

	glRotatef(enemy->enemyView.angleHorizontal, 0, 1, 0);
	glRotatef(enemy->enemyView.angleVertical, 1, 0, 0);

	if (enemy->health <= 0)
		glScalef(1, 0.95, 1);

	float colorLive[3] = { 1,enemy->health / enemy->maxHealth,enemy->health / enemy->maxHealth };

	if (enemy->health <= 0) colorLive[0] = 0.33;

	if (enemy->spirit)
	{

		doff
			float colorLive1[4] = { 1,1,1,0.7 };
		glColor4fv(colorLive1);
		glutSolidSphere(enemy->radius, 16, 16);
		don

	}
	else
	{
		switch (enemy->type)
		{

		case ANTI_JUMPER:
			glRotatef(180, 1, 0, 0);
		case JUMPER:
			glColor3fv(colorLive);
			glRotatef(-90, 1, 0, 0);
			glTranslatef(0, 1, -enemy->radius);
			glutSolidCone(enemy->radius, enemy->radius * 2, 8, 8);
			glRotatef(-180, 1, 0, 0);
			glutSolidCone(enemy->radius, 0, 8, 8);
			break;
		case FLY:
			glColor3fv(colorLive);
			glutSolidSphere(enemy->radius, 16, 16);

			//	glTranslatef(0,0, 8);
			//	glColor3f(0,0.5,1);
			//	glutSolidSphere(39,16,16);

			loff
				glTranslatef(0, 0, enemy->radius - enemy->radius * 0.5);
			glColor3f(cos(enemy->angle * _torad), 0, 0);
			glutSolidSphere(enemy->radius * 0.6, 16, 16);


			glTranslatef(0, 0, enemy->radius * 0.35);
			glColor3f(sin(enemy->angle * _torad), 0, 0);
			glutSolidSphere(enemy->radius * 0.3, 16, 16);

			lon



				break;

		case TURRET:

			glColor3fv(colorLive);

			glRotatef(enemy->angle, 0, 0, 1);
			glRotatef(90, 0, 1, 0);
			//	glCullFace(GL_FRONT_AND_BACK);

			//	glScalef(45,45,45);
			//	glutSolidCone(enemy->radius,enemy->radius*2,10,10);
			glutSolidSphere(enemy->radius, 16, 16);
			glRotatef(180, 0, 1, 0);
			glTranslatef(0, 0, -enemy->radius * 1.5);
			glDisable(GL_CULL_FACE);
			glutSolidCone(enemy->radius * 0.4, enemy->radius * 2, 10, 10);
			glutSolidTorus(enemy->radius * 0.05, enemy->radius * 0.4, 10, 10);
			glEnable(GL_CULL_FACE);
			break;
		default:
			glColor3fv(colorLive);
			glutSolidSphere(enemy->radius, 16, 16);
			break;

		}

	}
	//	don
	pom



		//	don	
}

 void draw::ShowEnemyImpacts(Enemy* enemy)
{
	static float scale = 10;
	static bool scaleUp = true;
	if (scaleUp) scale += 0.5;
	else scale -= 0.5;
	if (scale > 10) scaleUp = false;
	if (scale < 4) scaleUp = true;
	glColor3f(1, 1, 0);
	for (int i = 0; i<10; i++)
	{
		if (enemy->impact[i].H > 0)
		{
			loff;
			if (!enemy->impact[i].isMassive) { glColor3f(1, 0, 0); }
			pum
				glTranslatef(enemy->impact[i].x, enemy->impact[i].y, 0);
			glRotatef(45, 1, 1, 1);
			glScalef(scale, scale, scale);
			if (!enemy->impact[i].isMassive)
				glutSolidSphere(1, 8, 8);
			else glutSolidCube(1);
			pom
				//	if(!enemy->impact[i].isMassive) {	 }
				lon;
		}
	}
}

 void draw::ShowField()
{
	glCallList(50005);
}

 void draw::ShowField2()
{//loff
	glCallList(3);
	//lon
}

 void draw::ShowLimit()
{
	/*	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	pum;
	glColor3f(.5,1,.5);
	glBegin(GL_QUADS);
	glNormal3f(1,0,0);
	for(int j=-30;j<150;j+=30)
	for(int i=0;i<limitY;i+=30)
	{
	glVertex3f(0,i,  j);
	glVertex3f(0,i+30,j);
	glVertex3f(0,i+30,j+30);
	glVertex3f(0,i,j+30);
	}
	glEnd();
	pom;

	glCullFace(GL_FRONT);
	pum;
	glBegin(GL_QUADS);
	glNormal3f(-1,0,0);
	for(int j=-30;j<150;j+=30)
	for(int i=0;i<limitY;i+=30)
	{
	glVertex3f(limitX,i,  j);
	glVertex3f(limitX,i+30,j);
	glVertex3f(limitX,i+30,j+30);
	glVertex3f(limitX,i,j+30);
	}
	glEnd();
	pom;*/

}

 void draw::ShowDoor(Door* door)
{
	switch (door->NUM)
	{
	case YELLOW:
		glColor3f(1, 1, 0);
		break;
	case BLUE:
		glColor3f(0, 0, 1);
		break;
	case RED:
		glColor3f(1, 0, 0);
		break;
	case GREEN:
		glColor3f(0, 1, 0);
		break;
	default:
		glColor3f(1, 1, 1);
		break;
	}


	blon
		door->line[0].ShowLite();
	door->line[1].ShowLite();
	door->line[2].ShowLite();
	bloff

		pum
		tr(door->A.x, door->A.y, door->Width,
			door->C.x, door->C.y, door->Width,
			door->B.x, door->B.y, door->Width);
	pom
}

 void draw::ShowKey(Key* key)
{
	switch (key->NUM)
	{
	case YELLOW:
		glColor3f(1, 1, 0);
		break;
	case BLUE:
		glColor3f(0, 0, 1);
		break;
	case RED:
		glColor3f(1, 0, 0);
		break;
	case GREEN:
		glColor3f(0, 1, 0);
		break;
	default:
		glColor3f(1, 1, 1);
		break;
	}

	pum
		glTranslatef(key->x, key->y, 0);
	//	glScalef(key->radius*1.2,key->radius*1.2,key->radius*1.2);
	glutSolidTorus(key->radius * 0.3, key->radius - key->radius * 0.3, 16, 16);

	pom

}

 void draw::ShowPrimitive(Primitive* primitive)
{/*

 if(desc[curDescI][curDescJ].num1 == primitive->NUM
 || desc[curDescI][curDescJ].num2 == primitive->NUM)
 return;*/

	float mx, my;

	mx = primitive->medx;
	my = primitive->medy;

	primitive->view.color[3] = 1;

	switch (primitive->type)
	{


	case SAND:
		//	if(primitive->isLegal)
		//		if(primitive->view.color[3]<0.9) primitive->view.color[3]+=0.01;

		primitive->view.color[0] = 1;
		primitive->view.color[1] = 1;
		primitive->view.color[2] = 0.5;
		primitive->view.color[3] = 0.5;

		glColor4fv(primitive->view.color);

		pum blon
			primitive->line[0].ShowLite();
		primitive->line[1].ShowLite();

		tr(primitive->A.x, primitive->A.y, primitive->Width,
			primitive->C.x, primitive->C.y, primitive->Width,
			primitive->B.x, primitive->B.y, primitive->Width);
		pom bloff
			break;
		break;
	case ICE:
		//	if(primitive->isLegal)
		//		if(primitive->view.color[3]<0.5) primitive->view.color[3]+=0.01;

		primitive->view.color[0] = 0.9;
		primitive->view.color[1] = 1;
		primitive->view.color[2] = 1;
		primitive->view.color[3] = 0.9;

		glColor4fv(primitive->view.color);

		pum blon
			primitive->line[0].ShowLite();
		primitive->line[1].ShowLite();
		primitive->line[2].ShowLite();
		tr(primitive->A.x, primitive->A.y, primitive->Width,
			primitive->C.x, primitive->C.y, primitive->Width,
			primitive->B.x, primitive->B.y, primitive->Width);
		pom bloff
			break;

	case FORBOMB:
	case GEO:

		//	if(primitive->isLegal)
		//	if(primitive->view.color[3]<1) primitive->view.color[3]+=0.02;				

		//	glColor4fv(primitive->view.color);

		//M:


		//	if((primitive->NUM%3) == 0)	glColor3f(0.8,0.8,0.8);	
		//	else
		//	if(primitive->type == GEO)
		glColor3f(1 - commonColor[0],
			1 - commonColor[1],
			1 - commonColor[2]);
		//	else
		//		glColor3f(1,1,1);	


		//		int idesc = SIZE1*100 


		if (/*!ORTHO  &&*/ !primitive->isDepth /*&& primitive->isLegal*/)
		{
			blon
				primitive->line[0].ShowLite();
			primitive->line[1].ShowLite();

			//	if(!primitive->isHalfBox)
			primitive->line[2].ShowLite();
			bloff
		}


		pum


			//	if(!ORTHO)

			//if((primitive->NUM%3) == 0)
			//	if(0)
		{
			blon
			//	glColor4fv(primitive->view.color);


			//		glColor3f(0.3,0.3,0.3);	
			//	if((primitive->NUM%8) != 0)
			{
				float a;
		//	if((primitive->NUM%3) == 0)
		a = 1.1;
		//	else 
		//		a=0.9;

		tr2(mx,my,primitive->Width * a,
			primitive->B.x,primitive->B.y,primitive->Width,
			primitive->A.x,primitive->A.y,primitive->Width);
		//		glColor3f(0.2,0.2,0.2);	

		tr2(primitive->C.x,primitive->C.y,primitive->Width,
			primitive->B.x,primitive->B.y,primitive->Width,
			mx,my,primitive->Width * a);

		//	glColor3f(0,0,0);


		tr2(primitive->A.x,primitive->A.y,primitive->Width,
			primitive->C.x,primitive->C.y,primitive->Width,
			mx,my,primitive->Width * a);

		}

			//tr2(A.x,A.y,Width,   C.x,C.y,Width,		   mx,my,Width*0.8);
			//tr(A.x,A.y,Width,   C.x,C.y,Width,		   B.x,B.y,Width);

			bloff
		}
			/*			else
			{
			glColor4fv(primitive->view.colorDark);
			tr(primitive->A.x,primitive->A.y,primitive->Width,
			primitive->C.x,primitive->C.y,primitive->Width,
			primitive->B.x,primitive->B.y,primitive->Width);

			}
			*/

			pom
			break;
	case HYDRO:


		if (primitive->typeOfImpact == EVIL)
			primitive->view.color[3] = 0.8;
		else
			primitive->view.color[3] = 0.5;

		/*	doff
		glColor3f(1,1,1);

		tr2( mx,my,primitive->Width*0.1,
		primitive->B.x,primitive->B.y,0,
		primitive->A.x,primitive->A.y,0);

		tr2(primitive->C.x,primitive->C.y,0,
		primitive->B.x,primitive->B.y,0,
		mx,my,primitive->Width*0.1);

		tr2(primitive->A.x,primitive->A.y,0,
		primitive->C.x,primitive->C.y,0,
		mx,my,primitive->Width*0.1);
		don*/

		//	if(primitive->isLegal)
		//		if(primitive->view.color[3]<0.5) primitive->view.color[3]+=0.01;				


		glColor4fv(primitive->view.color);

		//	glColor4f(0,1,1,0.4);


		if (dddx[primitive->NUM] > 20) lx[primitive->NUM] = false;
		if (dddx[primitive->NUM] < -20) lx[primitive->NUM] = true;

		if (dddy[primitive->NUM] > 20) ly[primitive->NUM] = false;
		if (dddy[primitive->NUM] < -20) ly[primitive->NUM] = true;

		if (lx[primitive->NUM]) dddx[primitive->NUM] += 0.5;
		else	dddx[primitive->NUM] -= 0.5;

		if (ly[primitive->NUM]) dddy[primitive->NUM] += 0.5;
		else    dddy[primitive->NUM] -= 0.5;


		float mx = primitive->medx + dddx[primitive->NUM];
		float my = primitive->medy + dddy[primitive->NUM];
		float mz = primitive->medz + dddy[primitive->NUM];


		pum

			//	if(!ORTHO)
		{

			blon
			//	doff
			//	tr2( mx,my,primitive->Width-5,  primitive->B.x,primitive->B.y,primitive->Width-5, 	primitive->A.x,primitive->A.y,primitive->Width-5);
			//	tr2(primitive->C.x,primitive->C.y,primitive->Width-5,   primitive->B.x,primitive->B.y,		primitive->Width-5,	mx,my,primitive->Width-5);
			//	tr2(primitive->A.x,primitive->A.y,primitive->Width-5,   primitive->C.x,primitive->C.y,primitive->Width-5,		   mx,my,primitive->Width-5);
			//	don	

			tr2(primitive->A.x,primitive->A.y,primitive->Width - 5,
				primitive->C.x,primitive->C.y,primitive->Width - 5,
				primitive->B.x, primitive->B.y,primitive->Width - 5);



		/*
		tr2(primitive->A.x,primitive->A.y,0,
		primitive->C.x,primitive->C.y,0,
		primitive->B.x, primitive->B.y,0);

		*/

		bloff


			/*

			tr2( mx,my,1.1,
			primitive->B.x,primitive->B.y,0,
			primitive->A.x,primitive->A.y,0);

			tr2(primitive->C.x,primitive->C.y,0,
			primitive->B.x,primitive->B.y,0,
			mx,my,1.1);

			tr2(primitive->A.x,primitive->A.y,0,
			primitive->C.x,primitive->C.y,0,
			mx,my,1.1);*/


			if (primitive->uppest)
			{
				lon
					blon
					don

					mz = 0;
				//	glColor4f(primitive->color[0],primitive->color[1],primitive->color[2], primitive->color[3]);

				tr2(primitive->A.x,primitive->C.y,primitive->Width - 5,
					primitive->C.x,primitive->C.y,primitive->Width - 5,
					mx,primitive->C.y + dddy[primitive->NUM],mz);

				//	glColor4f(color[0]*0.3,color[1]*0.3,color[2]*0.3,  color[3]);
				tr2(primitive->A.x,primitive->C.y,primitive->Width - 5,
					mx,primitive->C.y + dddy[primitive->NUM],mz,
					primitive->A.x,primitive->C.y,-primitive->Width
				);
				//	glColor4f(color[0]*0.4,color[1]*0.4,color[2]*0.4,  color[3]);
				tr2(primitive->C.x,primitive->C.y,primitive->Width - 5,
					primitive->A.x,primitive->C.y,-primitive->Width,
					mx,primitive->C.y + dddy[primitive->NUM],mz
				);

				//	glColor4f(color[0]*0.5,color[1]*0.5,color[2]*0.5,  color[3]);
				tr(primitive->C.x,primitive->C.y,-primitive->Width,
					primitive->C.x,primitive->C.y,primitive->Width - 5,
					mx + 50,primitive->C.y + dddx[primitive->NUM],mz);

				//	glColor4f(color[0]*0.3,color[1]*0.3,color[2]*0.3,  color[3]);
				tr(primitive->C.x,primitive->C.y,-primitive->Width,
					mx + 50,primitive->C.y + dddx[primitive->NUM],mz,
					primitive->A.x,primitive->C.y,-primitive->Width
				);
				//	glColor4f(color[0]*0.4,color[1]*0.4,color[2]*0.4,  color[3]);
				tr(primitive->C.x,primitive->C.y,primitive->Width - 5,
					primitive->A.x,primitive->C.y,-primitive->Width,
					mx + 50,primitive->C.y + dddx[primitive->NUM],mz
				);


				doff	bloff lon
			}




		}
			//	else
			//	{	loff blon doff


			//		tr2(primitive->A.x,primitive->A.y,primitive->Width-5,   primitive->C.x,primitive->C.y,primitive->Width-5,		  primitive->B.x, primitive->B.y,primitive->Width-5);

			//		lon bloff don

			//	}
			pom


			break;

	}
}

 void draw::ShowCheckPoint(PointF* checkPoint)
{
	pum
		glColor3f(1, 1, 0);
	glTranslatef(checkPoint->x, checkPoint->y, 0);
	glScalef(30, 45, 30);
	glutSolidOctahedron();
	pom

}

 void draw::ShowExit(PointF* exitPoint)
{
	static float rotx;
	static float rotz;

	rotx += 1;
	rotz += 2;

	loff
		glColor3f(1, 0, 0.5);
	pum

		glTranslatef(exitPoint->x, exitPoint->y, 0);
	glRotatef(rotx, 1, 0, 0);
	glRotatef(rotz, 0, 0, 1);
	glutSolidTorus(2, 40, 16, 32);
	pom

		pum

		glTranslatef(exitPoint->x, exitPoint->y, 0);
	glRotatef(-rotx, 1, 0, 1);
	glRotatef(-rotz, 0, 0, 1);
	glutSolidTorus(2, 35, 16, 32);
	pom

		pum

		glTranslatef(exitPoint->x, exitPoint->y, 0);
	glRotatef(-rotz * 0.8, 1, 0, 0);
	glRotatef(rotx * 0.7, 0, 1, 1);
	glutSolidTorus(2, 30, 16, 32);
	pom


		lon


}

 void draw::ShowImpactLine(MyGish* mygish, float crossX, float crossY)
{
	//	float maxx =  MAX(fabs(mygish->medium().x - mygish->impactx), fabs(mygish->medium().x - mygish->impactx) );
	//	float minn =  MIN(fabs(mygish->medium().x - mygish->impactx), fabs(mygish->medium().x - mygish->impactx) );


	float duloLength = 80;
	float ammorad = 2000;//mygish->impact[0].ammoDist;

	float dist = trigonom::Dist(mygish->medium(), PointF(crossX, crossY));
	float k = dist / ammorad;
	float k2 = dist / duloLength;


	float ammox = mygish->medium().x + (crossX - mygish->medium().x) / k;
	float ammoy = mygish->medium().y + (crossY - mygish->medium().y) / k;

	float dulox = mygish->medium().x + (crossX - mygish->medium().x) / k2;
	float duloy = mygish->medium().y + (crossY - mygish->medium().y) / k2;

	//	mygish->impact[0].x = ammox;
	//	mygish->impact[0].y = ammoy;

	static int c = 0;
	static int c2 = 0;
	static int c3 = 0;
	static int c4 = 0;

	pum
		loff
		glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex3f(mygish->medium().x, mygish->medium().y, 50);
	glVertex3f(dulox, duloy, 50);
	glEnd();
	lon
		pom

		if (mygish->FIRE)
		{

			if (c++ % 2 == 0) return;
			if (c2++ % 2 == 0) return;
			//	if(c3++%2 == 0) return;

			glLineWidth(3);
			pum
				loff
				glColor3f(1, 0, 0);
			//glTranslatef(exitPoint->x, exitPoint->y, 50);
			//	glutSolidCube(120);
			glBegin(GL_LINES);
			//	glColor3f(0.8,0.8,0.8);
			glColor3f(trigonom::minirand(), trigonom::minirand(), trigonom::minirand());
			glVertex3f(mygish->medium().x, mygish->medium().y, 40);
			glVertex3f(ammox, ammoy, 40);
			glEnd();
			lon
				pom
		}
}

 void draw::ShowWeaponWithImpacts(Weapon* weapon)
{
	if (weapon->type == ROCKET_LAUNCHER)
		return;

	switch (weapon->type)
	{
	case 0:
		glColor3f(1, 1, 1);
		pum
			loff
			glTranslatef(weapon->x, weapon->y, 0);
		glutSolidSphere(weapon->radius, 16, 16);
		lon
			pom
			return;
		break;
	case 1: 	glColor3f(.3, .3, 0);
		break;
	case 2: 	glColor3f(0, .3, 0);
		break;
	case 3: 	glColor3f(0, .3, .3);
		break;
		//case 4: 	glColor3f(0,0,1);
		//		break;
		//case 5: 	glColor3f(.3,0,.3);
		//	break;
	case 6: 	glColor3f(.3, .5, .3);
		break;
	case 7: 	glColor3f(.5, .3, .5);
		break;
	case 8: 	glColor3f(.5, .5, .5);
		break;

	case DETONATOR:

		glColor3f(1, 0, 1);
		pum
			loff
			glTranslatef(weapon->x, weapon->y, 0);
		glScalef(weapon->radius, weapon->radius * 2, weapon->radius);
		glutSolidCube(1);
		lon
			pom
			return;

		break;
	case BOMB:


		//	float colorLive[3]  = {1,weapon->health/100,weapon->health/100};
		//	glColor3fv(colorLive);

		if (weapon->health <= 0) 	glColor3f(1, 0, 0);
		else  	glColor3f(1, 1, 1);
		pum
			if (weapon->active)	loff
				glTranslatef(weapon->x, weapon->y, 0);
		glutSolidSphere(weapon->radius, 16, 16);
		lon
			pom
			return;
		break;



	}
	pum
		//	loff
		glTranslatef(weapon->x, weapon->y, 0);
	glScalef(weapon->radius * 1.2, weapon->radius * 1.2, weapon->radius * 1.2);
	glutSolidIcosahedron();
	lon
		pom



		loff
		for (int i = 0; i<10; i++)
		{
			if (weapon->impact[i].H > 0)
			{
				if (!weapon->impact[i].isMassive) loff
					pum
					glTranslatef(weapon->impact[i].x, weapon->impact[i].y, 0);
				glRotatef(45, 1, 1, 1);
				glScalef(10, 10, 10);
				glutSolidCube(1);
				pom
					if (!weapon->impact[i].isMassive) lon
			}
		}


	if (weapon->fire && weapon->impactSpeed == 2000)
	{

		//static int c = 0;
		//	static int c2 = 0;
		//	if(c++%2 == 0) return;
		//	if(c2++%2 == 0) return;
		if (weapon->impact[0].H > 0)
		{
			for (int i = 1; i<9; i++)
			{
				if (weapon->impact[i].x != 0)
				{
					pum
						loff
						glColor3f(0.5, 0.5, 0.5);
					glBegin(GL_LINES);
					glVertex3f(weapon->impact[0].x, weapon->impact[0].y, 0);
					glVertex3f(weapon->impact[i].x, weapon->impact[i].y, 0);
					glEnd();
					lon
						pom
				}
				weapon->impact[i].H = 0;

			}
			weapon->impact[0].H = 0;
		}
	}
	lon




}

 void draw::ShowItem(Item* item)
{

	static float angle = 0;
	static float angle2 = 0;
	if ((angle += 0.1) >= 360) angle = 0;
	if ((angle2 += 0.03) >= 360) angle2 = 0;
	pum
		glTranslatef(item->x, item->y, 0);
	glRotatef(angle2, 0, 1, 0);
	glRotatef(angle, 0, 0, 1);


	switch (item->type)
	{

	case HEALTH:
		//loff
		glColor3f(1, 0, 0);
		pum
			glScalef(3, 1, 1);
		glutSolidCube(item->radius);
		pom

			pum
			glScalef(1, 3, 1);
		glutSolidCube(item->radius);
		pom
			//	lon
			break;
	case AMMO:
		break;
	default:
		glutSolidCube(item->radius);
		break;

	}

	pom
}

 void draw::spisok()
{
	bool f = true;
	glNewList(50005, GL_COMPILE);
	pum;

	glTranslatef(0, 0, -2000);

	//	glEnable(GL_POLYGON_SMOOTH);
	glNormal3f(0, 0, 1);
	//	glBegin(GL_TRIANGLES);

	glBegin(GL_QUADS);
	glColorMaterial(GL_FRONT_AND_BACK, GL_SPECULAR);
	glEnable(GL_COLOR_MATERIAL);
	for (int i = 0; i < limitX; i += limitX * 0.03)
		for (int j = 0; j < limitY; j += limitY * 0.03)
		{
			f = !f;

			if (trigonom::minirand() > 0.5)
				continue;

			//		glTranslatef(i,j,45);
			//		glutSolidCube(limitX*0.01);


			//	float col = 1-minirand()*0.2;
			//	glColor3f(col,col,col);

			glColor3f(
				1 - trigonom::minirand() * 0.1,
				1 - trigonom::minirand() * 0.1,
				1 - trigonom::minirand() * 0.1);

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

			float z = trigonom::minirand() * 1000;
			//
			{
				//	//	glColor3f(0,0,0);	
				//	glBegin(GL_QUADS);
				glVertex3f(i, j, z);
				glVertex3f(i + limitX * 0.03, j, z);
				glVertex3f(i + limitX * 0.03, j + limitY * 0.03, z);
				glVertex3f(i, j + limitY * 0.03, z);

				//	glEnd();
			}


		}
	glEnd();

	//	glDisable(GL_POLYGON_SMOOTH);
	pom;
	glEndList();

	glNewList(3, GL_COMPILE);
	pum;

	glTranslatef(0, 0, -10);


	//glNormal3f(0,0,-1);

	for (int j = 0; j < limitY; j += limitY * 0.04)
		for (float i = 0; i < limitX; i += limitX * 0.04)
		{

			if (rand() % 100 > 70)
			{
				float p1 = trigonom::minirand();
				float p2 = trigonom::minirand();
				float p3 = trigonom::minirand();
				float p4 = trigonom::minirand();
				float p5 = trigonom::minirand();
				float p6 = trigonom::minirand();
				float p7 = trigonom::minirand();
				doff
					glColor3f(0, 0, 0);
				glBegin(GL_LINE_STRIP);
				glVertex3f(i, j, -1000);
				glVertex3f(i + limitX * 0.1 * p1, j, -1000 + p2 * 5);
				glVertex3f(i + limitX * 0.1 * p3, j + limitY * 0.1 * p4, -1000 + p5 * 5);
				glVertex3f(i, j + limitY * 0.1 * p6, -1000 + p7 * 5);
				glEnd();
				don


					//	glColor3f(0.5,0.5,0.5);
					glColor3f(.7, .7, .7);
				glBegin(GL_QUADS);
				glVertex3f(i, j, -1000);
				glVertex3f(i + limitX * 0.1 * p1, j, -1000 + p2 * 5);
				glVertex3f(i + limitX * 0.1 * p3, j + limitY * 0.1 * p4, -1000 + p5 * 5);
				glVertex3f(i, j + limitY * 0.1 * p6, -1000 + p7 * 5);
				glEnd();


			}

		}

	pom;
	glEndList();


	glNewList(2, GL_COMPILE);
	glutSolidSphere(1, 6, 6);
	glEndList();

}

 void draw::displayFunc()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glutSwapBuffers();

	glFlush();

}



 /*
static void ShowShadowsStena()
{

	 int	NUM_PRIM_GR_ACTUAL = n_prim_graph_actual.size();

	pum;

			for(int n = 0; n < NUM_PRIM_GR_ACTUAL; n++)
			//	if(	prim[n_prim_graph_actual[n]].ACTUAL)
				for(int j=0;j<3;j++)
					{

						prim[n_prim_graph_actual[n]].line[j]->ShowShadow(0,light);
					}
	pom;
}
*/


/*
static void ShowShadowsPrimitive()
{

	pum;

			if(	primitive->ACTUAL)
				for(int j=0;j<3;j++)
					{

						primitive->ShowShadow(0,light);
					}
	pom;
}
*/

