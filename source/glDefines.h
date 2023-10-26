#pragma once

#define pum	 {glPushMatrix();
#define pom	 glPopMatrix();}

#define lon  glEnable(GL_LIGHTING);
#define loff  glDisable(GL_LIGHTING); 
#define don	 glEnable(GL_DEPTH_TEST);
#define doff glDisable(GL_DEPTH_TEST); 
#define aaon  glEnable(GL_POLYGON_SMOOTH);
#define aaoff glDisable(GL_POLYGON_SMOOTH); 
#define blon  glEnable(GL_BLEND);
#define bloff glDisable(GL_BLEND); 