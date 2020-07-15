#ifndef CANVAS_H
#define CANVAS_H

inline void tr(float ax,float ay,float az,
		float bx,float by,float bz,
		float cx,float cy,float cz
		)
{

			 static float v1[3],v2[3],v3[3];
			 v1[0] = ax;
			 v1[1] = ay;
			 v1[2] = az;

			 v2[0] = bx;
			 v2[1] = by;
			 v2[2] = bz;

			 v3[0] = cx;
			 v3[1] = cy;
			 v3[2] = cz;

	   			float vector1X = ax-bx;
				float vector1Y = ay-by;
				float vector1Z = az-bz;

				float vector2X = bx-cx;
				float vector2Y = by-cy;
				float vector2Z = bz-cz;

				float normalX = vector1Y * vector2Z - vector1Z * vector2Y;         
				float normalY = vector1Z * vector2X - vector1X * vector2Z;
				float normalZ = vector1X * vector2Y - vector1Y * vector2X;



			glEnable(GL_CULL_FACE);
			glCullFace(GL_FRONT);

				glNormal3f(normalX,normalY,normalZ);
				glVertex3fv( v1);
				glVertex3fv( v2);
				glVertex3fv( v3);

			glCullFace(GL_BACK);
				glNormal3f(-normalX,-normalY,-normalZ);
				glVertex3fv( v3);
				glVertex3fv( v2);
				glVertex3fv( v1);

			glDisable(GL_CULL_FACE);


}


inline void tr2(float ax,float ay,float az,
		float bx,float by,float bz,
		float cx,float cy,float cz
		)
{

			 static float v1[3],v2[3],v3[3];
			 v1[0] = ax;
			 v1[1] = ay;
			 v1[2] = az;

			 v2[0] = bx;
			 v2[1] = by;
			 v2[2] = bz;

			 v3[0] = cx;
			 v3[1] = cy;
			 v3[2] = cz;

	   			float vector1X = ax-bx;
				float vector1Y = ay-by;
				float vector1Z = az-bz;

				float vector2X = bx-cx;
				float vector2Y = by-cy;
				float vector2Z = bz-cz;

				float normalX = vector1Y * vector2Z - vector1Z * vector2Y;         
				float normalY = vector1Z * vector2X - vector1X * vector2Z;
				float normalZ = vector1X * vector2Y - vector1Y * vector2X;



			glEnable(GL_CULL_FACE);
			glCullFace(GL_FRONT);

				glNormal3f(normalX,normalY,normalZ);
				glVertex3fv( v1);
				glVertex3fv( v2);
				glVertex3fv( v3);

			glDisable(GL_CULL_FACE);


}

inline void tr2(PointF a,float az,
				PointF b,float bz,
				PointF c,float cz
		)
{

			 static float v1[3],v2[3],v3[3];
			 v1[0] = a.x;
			 v1[1] = a.y;
			 v1[2] = az;

			 v2[0] = b.x;
			 v2[1] = b.y;
			 v2[2] = bz;

			 v3[0] = c.x;
			 v3[1] = c.y;
			 v3[2] = cz;

	   			float vector1X = a.x-b.x;
				float vector1Y = a.y-b.y;
				float vector1Z = az-bz;

				float vector2X = b.x-c.x;
				float vector2Y = b.y-c.y;
				float vector2Z = bz-cz;

				float normalX = vector1Y * vector2Z - vector1Z * vector2Y;         
				float normalY = vector1Z * vector2X - vector1X * vector2Z;
				float normalZ = vector1X * vector2Y - vector1Y * vector2X;



			glEnable(GL_CULL_FACE);
			glCullFace(GL_FRONT);

				glNormal3f(normalX,normalY,normalZ);
				glVertex3fv( v1);
				glVertex3fv( v2);
				glVertex3fv( v3);

			glDisable(GL_CULL_FACE);


}
#endif
