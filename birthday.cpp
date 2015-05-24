#include <GL/glut.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;

GLfloat boxVelocity=0.0;
// Variable that determines the balloon velocity.
GLfloat velocity=0.0;
// Variable that determines the clap velocity.
GLfloat clapVelocity=0.0;

// Variable that records the state of the candle flame
int flame=1;
// Variable that records the state of the bithday boy blowing

int blow=0;
// Variable that records the clap state
int clap=0;
int burst=0;

int blink=0;
// A GLfloat array of size 3 name as col(colours)
GLfloat x_pos=0.0;
GLfloat y_pos=0.0;
GLfloat rad=0.0;



typedef GLfloat col[3];

void draw_candle(GLfloat x,GLfloat y,int flame)
{
	glColor3f(0.75,0.75,0.75);
	//Intial Position of vertex of the candle rectangle(a)
	glVertex2f(x,y);
	glColor3f(0.75,0.75,0.75);
	//Vertex(b)
	glVertex2f(x,y+25);
	//Vertex(d)
	glVertex2f(x+10,y+25);
	//Vertex(c)
	glVertex2f(x+10,y);
	

	if(flame==1)
	{
	//Intial triangle for the flame with yellow shading
	
	
	glBegin(GL_TRIANGLES);
	glColor3f(1.0,1.0,0.0);
	glVertex2f(x,y+25);
	glVertex2f(x+5,y+50);
	glVertex2f(x+10,y+25);
	glEnd(); 
	


	// Overlapped triangle with a red shade
	glBegin(GL_TRIANGLES);
	glColor3f(1.0,1.0,0.0);
	glVertex2f(x,y+25);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(x+5,y+50);
	glColor3f(1.0,1.0,0.0);
	glVertex2f(x+10,y+25);
	glEnd();
	
	

	}
}

void draw_circle(float x, float y, float radius) { 
	
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(x, y, 0.0f);
    static const int circle_points = 100;
    static const float angle = 2.0f * 3.1416f / circle_points;

    
    glBegin(GL_POLYGON);
    double angle1=0.0;
    glVertex2d(radius * cos(0.0) , radius * sin(0.0));
    int i;
    for (i=0; i<circle_points; i++)
    {       
        glVertex2d(radius * cos(angle1), radius *sin(angle1));
        angle1 += angle;
    }
    glEnd();
    glPopMatrix();
    

}

void draw_ribbonCircle(float x, float y, float radius) { 
	
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(x, y, 0.0f);
    static const int circle_points = 100;
    static const float angle = 2.0f * 3.1416f / circle_points;
    
    
    	glTranslatef(boxVelocity,0.0,0.0);
    	glBegin(GL_POLYGON);
    	double angle1=0.0;
    	glVertex2d(radius * cos(0.0) , radius * sin(0.0));
    	int i;
    	for (i=0; i<circle_points; i++)
    	{       
        	glVertex2d(radius * cos(angle1), (radius *sin(angle1)));
        	angle1 += angle;
    	}
    	glEnd();
    glPopMatrix();    

}


void spikes(GLfloat x, GLfloat y)
{
	glBegin(GL_TRIANGLES);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(x,y+50);
	glVertex2f(x+10,y+50);
	glVertex2f(x+5,y+60);
	glEnd();


}
void draw_face(GLfloat x, GLfloat y,int blow)
{
	// Face Outline
	/*glBegin(GL_POLYGON);
	glColor3f(1.0,0.7,0.0);
	glVertex2f(x+10,y);
	glVertex2f(x+90,y);
	glVertex2f(x+90,y+50);
	glVertex2f(x+10,y+50);
	glEnd();*/

	glColor3f(1.0,0.7,0.0);	
	draw_circle(x+50,y+35,35.0);
	

	// Black Body
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(x+10,y);
	glVertex2f(x+10,y-40);
	glVertex2f(x+90,y-40);
	glVertex2f(x+90,y);
	glEnd();

	// Left Hand Sleeve
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(x,y);
	glVertex2f(x,y-30);
	glVertex2f(x+10,y-30);
	glVertex2f(x+10,y);
	glEnd();

	// Left Hand Fingers
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.7,0.0);
	glVertex2f(x+10,y-30);
	glVertex2f(x+10,y-40);
	glVertex2f(x,y-40);
	glVertex2f(x,y-30);
	glEnd();

	// Right Hand Sleeve
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(x+90,y);
	glVertex2f(x+90,y-30);
	glVertex2f(x+100,y-30);
	glVertex2f(x+100,y);
	glEnd();

	// Right Hand Fingers
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.7,0.0);
	glVertex2f(x+100,y-30);
	glVertex2f(x+100,y-40);
	glVertex2f(x+90,y-40);
	glVertex2f(x+90,y-30);
	glEnd();

	//Triangular Collar

	// Left Collar
	glBegin(GL_TRIANGLES);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(x+40,y);
	glVertex2f(x+40,y-10);
	glVertex2f(x+50,y-5);
	glEnd();

	// Right Collar
	glBegin(GL_TRIANGLES);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(x+60,y);
	glVertex2f(x+60,y-10);
	glVertex2f(x+50,y-5);
	glEnd();



	// Left leg
	glBegin(GL_POLYGON);
	glColor3f(0.0,1.0,0.0);
	glVertex2f(x+20,y-40);
	glVertex2f(x+20,y-70);
	glVertex2f(x+30,y-70);
	glVertex2f(x+30,y-40);
	glEnd();

	// Right Leg
	glBegin(GL_POLYGON);
	glColor3f(0.0,1.0,0.0);
	glVertex2f(x+70,y-40);
	glVertex2f(x+70,y-70);
	glVertex2f(x+80,y-70);
	glVertex2f(x+80,y-40);
	glEnd();



	// Triangular Cap
	glBegin(GL_TRIANGLES);
	glColor3f(1.0,0.0,0.5);
	glVertex2f(x+5,y+45);
	glVertex2f(x+95,y+45);
	glVertex2f(x+50,y+110);
	glEnd();
	
	glColor3f(1.0,1.0,1.0);
	draw_circle(x+50,y-15,2.5);

	glColor3f(1.0,1.0,1.0);
	draw_circle(x+50,y-25,2.5);

	// Spots on the cap;

	
	// First Row First Green spot
	glColor3f(0.0,1.0,0.0);
	draw_circle(x+21, y+53, 5);

	
	// First Row Second yellow spot
	glColor3f(1.0,1.0,0.0);
	draw_circle(x+40, y+53, 5);

	// First Row Third Black spot
	glColor3f(0.0,0.0,0.0);
	draw_circle(x+57, y+53, 5);


	// First Row Fourth yellow spot
	glColor3f(1.0,1.0,0.0);
	draw_circle(x+75, y+53, 5);

	//Second Row First Black Spot
	glColor3f(0.0,0.0,0.0);
	draw_circle(x+29, y+66, 5);

	// Second Row Second Black Spot
	glColor3f(1.0,1.0,0.0);
	draw_circle(x+50, y+67, 5);

	// Second Row Third Black Spot
	glColor3f(0.0,0.0,0.0);
	draw_circle(x+67, y+67, 5);

	// Third Row Yellow spot
	glColor3f(1.0,1.0,0.0);
	draw_circle(x+40, y+80, 5);

	// Third Row Green spot
	glColor3f(0.0,1.0,0.0);
	draw_circle(x+60, y+80, 5);


	// Fourth Row Black spot
	glColor3f(0.0,0.0,0.0);
	draw_circle(x+50, y+95, 5);

	// Peak Grey spot
	glColor3f(0.5,0.5,0.5);
	draw_circle(x+50, y+111, 5);
	


	// Black Hair
	/*for(int i=20;i<=70;i++)
	{
		spikes(x+i,y+5);

	}*/

	// Right Eye
	//glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	draw_circle(x+30,y+30,2);
	/*glVertex2f(x+30,y+30);
	glVertex2f(x+35,y+30);
	glVertex2f(x+35,y+35);
	glVertex2f(x+30,y+35);
	glEnd();*/

	// Left Eye
	//glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	draw_circle(x+70,y+30,2);
	//glVertex2f(x+70,y+30);
	//glVertex2f(x+70,y+35);
	//glVertex2f(x+65,y+35);
	//glEnd();

	// Triangular Nose
	spikes(x+45,x+25);

	// Lips
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(x+35,y+15);
	glVertex2f(x+65,y+15);
	glVertex2f(x+65,y+10);
	glVertex2f(x+35,y+10);
	glEnd();
 

	// Tongue
	if(blow==1)
	{
		
		glBegin(GL_TRIANGLES);
		glColor3f(0.80,0.0,0.0);
		glVertex2f(x+35,y+10);
		glVertex2f(x+65,y+10);
		glVertex2f(x+50,y+5);
		glEnd();
	}


	
}

void draw_people(float x, float y, col c)
{
	
	//Circular Face
	glColor3f(1.0,0.80,0.0);
	draw_circle(x,y,20);

	if(blink==1)
	{
		// Left Eye
		glColor3f(0.0,0.0,0.0);
		draw_circle(x-5,y+2,2);

		// Right Eye
		glColor3f(0.0,0.0,0.0);
		draw_circle(x+10,y+2,2);
	}
	if(blink==0)
	{
		// Left Eye
		glColor3f(0.0,0.0,0.0);
		draw_circle(x-5,y+2,1);

		// Right Eye
		glColor3f(0.0,0.0,0.0);
		draw_circle(x+10,y+2,1);
	}

	// Lips
	if(blow==1)
	{
		glBegin(GL_TRIANGLES);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(x,y-10);
		glVertex2f(x+5,y-10);
		glVertex2f(x+2.5,y-15);
		glEnd();

		glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		glEnd();

	}
	else
	{
		glBegin(GL_POLYGON);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(x-3,y-10);
		glVertex2f(x-3,y-12);
		glVertex2f(x+5,y-12);
		glVertex2f(x+5,y-10);
		glEnd();

	}
	

	// body
	glBegin(GL_POLYGON);
	glColor3fv(c);
	glVertex2f(x-10,y-20);
	glVertex2f(x-10,y-60);
	glVertex2f(x+13,y-60);
	glVertex2f(x+13,y-20);
	glEnd();

	
	
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(clapVelocity,0.0,0.0);
	// Left Sleeve
	glBegin(GL_POLYGON);
	glColor3fv(c);
	glVertex2f(x-15,y-20);
	glVertex2f(x-15,y-40);
	glVertex2f(x-10,y-40);
	glVertex2f(x-10,y-20);
	glEnd();

	//Left Hand
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.8,0.0);
	glVertex2f(x-15,y-40);
	glVertex2f(x-15,y-50);
	glVertex2f(x-10,y-50);
	glVertex2f(x-10,y-40);
	glEnd();
	glPopMatrix();


	// Right Sleeve
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(-clapVelocity,0.0,0.0);
	glBegin(GL_POLYGON);
	glColor3fv(c);
	glVertex2f(x+13,y-20);
	glVertex2f(x+13,y-40);
	glVertex2f(x+18,y-40);
	glVertex2f(x+18,y-20);
	glEnd();

	//Right Hand
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.8,0.0);
	glVertex2f(x+13,y-40);
	glVertex2f(x+13,y-50);
	glVertex2f(x+18,y-50);
	glVertex2f(x+18,y-40);
	glEnd();
	glPopMatrix();

	// Pants
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(x+5,y-60);
	glVertex2f(x+5,y-80);
	glVertex2f(x+12,y-80);
	glVertex2f(x+12,y-60);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(x-9,y-60);
	glVertex2f(x-9,y-80);
	glVertex2f(x-1,y-80);
	glVertex2f(x-1,y-60);
	glEnd();

	//if(clapVelocity<1.0)
	//	clapVelocity+=1.0;		
	//else
	//	clapVelocity=0.0;
	

	


}
void draw_people2(float x, float y, col c)
{
	
	//Circular Face
	glColor3f(1.0,0.80,0.0);
	draw_circle(x,y,20);

	if(blink==1)
	{
		// Left Eye
		glColor3f(0.0,0.0,0.0);
		draw_circle(x-5,y+2,2);

		// Right Eye
		glColor3f(0.0,0.0,0.0);
		draw_circle(x+10,y+2,2);
	}
	if(blink==0)
	{
		// Left Eye
		glColor3f(0.0,0.0,0.0);
		draw_circle(x-5,y+2,1);

		// Right Eye
		glColor3f(0.0,0.0,0.0);
		draw_circle(x+10,y+2,1);
	}

	// Lips
	if(blink==0)
	{
		glBegin(GL_TRIANGLES);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(x,y-10);
		glVertex2f(x+5,y-10);
		glVertex2f(x+2.5,y-15);
		glEnd();

		glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		glEnd();

	}
	else
	{
		glBegin(GL_POLYGON);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(x-3,y-10);
		glVertex2f(x-3,y-12);
		glVertex2f(x+5,y-12);
		glVertex2f(x+5,y-10);
		glEnd();

	}
	

	// body
	glBegin(GL_POLYGON);
	glColor3fv(c);
	glVertex2f(x-10,y-20);
	glVertex2f(x-10,y-60);
	glVertex2f(x+13,y-60);
	glVertex2f(x+13,y-20);
	glEnd();

	
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(clapVelocity,0.0,0.0);
	
	// Left Sleeve
	glBegin(GL_POLYGON);
	glColor3fv(c);
	glVertex2f(x-15,y-20);
	glVertex2f(x-15,y-40);
	glVertex2f(x-10,y-40);
	glVertex2f(x-10,y-20);
	glEnd();

	//Left Hand
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.8,0.0);
	glVertex2f(x-15,y-40);
	glVertex2f(x+5,y-40);
	glVertex2f(x+5,y-45);
	glVertex2f(x-15,y-45);
	
	glEnd();
	glPopMatrix();


	// Right Sleeve
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(-clapVelocity,0.0,0.0);
	glBegin(GL_POLYGON);
	glColor3fv(c);
	glVertex2f(x+13,y-20);
	glVertex2f(x+13,y-40);
	glVertex2f(x+18,y-40);
	glVertex2f(x+18,y-20);
	glEnd();

	//Right Hand
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.8,0.0);
	glVertex2f(x+13,y-40);
	glVertex2f(x+23,y-40);
	glVertex2f(x+23,y-45);
	glVertex2f(x+13,y-45);
	glEnd();
	glPopMatrix();

	// Pants
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(x+5,y-60);
	glVertex2f(x+5,y-80);
	glVertex2f(x+12,y-80);
	glVertex2f(x+12,y-60);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(x-9,y-60);
	glVertex2f(x-9,y-80);
	glVertex2f(x-1,y-80);
	glVertex2f(x-1,y-60);
	glEnd();

	//if(clapVelocity<1.0)
	//	clapVelocity+=1.0;		
	//else
	//	clapVelocity=0.0;
	

	


}

void draw_rightPeople(float x, float y, col c)
{
	
	//Circular Face
	glColor3f(1.0,0.80,0.0);
	draw_circle(x,y,20);

	if(blink==1)
	{
		// Left Eye
		glColor3f(0.0,0.0,0.0);
		draw_circle(x-5,y+2,2);

		// Right Eye
		glColor3f(0.0,0.0,0.0);
		draw_circle(x+10,y+2,2);
	}
	if(blink==0)
	{
		// Left Eye
		glColor3f(0.0,0.0,0.0);
		draw_circle(x-5,y+2,1);

		// Right Eye
		glColor3f(0.0,0.0,0.0);
		draw_circle(x+10,y+2,1);
	}

	// Lips
	if(blink==0)
	{
		glBegin(GL_TRIANGLES);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(x,y-10);
		glVertex2f(x+5,y-10);
		glVertex2f(x+2.5,y-15);
		glEnd();

		glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		glEnd();

	}
	else
	{
		glBegin(GL_POLYGON);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(x-3,y-10);
		glVertex2f(x-3,y-12);
		glVertex2f(x+5,y-12);
		glVertex2f(x+5,y-10);
		glEnd();

	}
	

	// body
	glBegin(GL_POLYGON);
	glColor3fv(c);
	glVertex2f(x-10,y-20);
	glVertex2f(x-10,y-60);
	glVertex2f(x+13,y-60);
	glVertex2f(x+13,y-20);
	glEnd();

	
	
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(clapVelocity,0.0,0.0);
	// Left Sleeve
	glBegin(GL_POLYGON);
	glColor3fv(c);
	glVertex2f(x-15,y-20);
	glVertex2f(x-15,y-40);
	glVertex2f(x-10,y-40);
	glVertex2f(x-10,y-20);
	glEnd();

	//Left Hand
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.8,0.0);
	glVertex2f(x-15,y-40);
	glVertex2f(x-15,y-50);
	glVertex2f(x-10,y-50);
	glVertex2f(x-10,y-40);
	glEnd();
	glPopMatrix();


	// Right Sleeve
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(-clapVelocity,0.0,0.0);
	glBegin(GL_POLYGON);
	glColor3fv(c);
	glVertex2f(x+13,y-20);
	glVertex2f(x+13,y-40);
	glVertex2f(x+18,y-40);
	glVertex2f(x+18,y-20);
	glEnd();

	//Right Hand
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.8,0.0);
	glVertex2f(x+13,y-40);
	glVertex2f(x+13,y-50);
	glVertex2f(x+18,y-50);
	glVertex2f(x+18,y-40);
	glEnd();
	glPopMatrix();

	// Pants
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(x+5,y-60);
	glVertex2f(x+5,y-80);
	glVertex2f(x+12,y-80);
	glVertex2f(x+12,y-60);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(x-9,y-60);
	glVertex2f(x-9,y-80);
	glVertex2f(x-1,y-80);
	glVertex2f(x-1,y-60);
	glEnd();

	//if(clapVelocity<1.0)
	//	clapVelocity+=1.0;		
	//else
	//	clapVelocity=0.0;
	

	


}
	


void draw_leftPeople(float x, float y, col c)
{
	
	//Circular Face
	glColor3f(1.0,0.80,0.0);
	draw_circle(x,y,20);

	if(blink==1)
	{
		// Left Eye
		glColor3f(0.0,0.0,0.0);
		draw_circle(x-10,y+2,2);

		// Right Eye
		glColor3f(0.0,0.0,0.0);
		draw_circle(x+5,y+2,2);
	}
	if(blink==0)
	{
		// Left Eye
		glColor3f(0.0,0.0,0.0);
		draw_circle(x-10,y+2,1);

		// Right Eye
		glColor3f(0.0,0.0,0.0);
		draw_circle(x+5,y+2,1);
	}

	// Lips
	if(blink==1)
	{
		glBegin(GL_TRIANGLES);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(x-5,y-10);
		glVertex2f(x+3,y-10);
		glVertex2f(x-0.5,y-15);
		glEnd();

		glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		glEnd();

	}
	else
	{
		glBegin(GL_POLYGON);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(x-4,y-10);
		glVertex2f(x-4,y-12);
		glVertex2f(x+4,y-12);
		glVertex2f(x+4,y-10);
		glEnd();

	}
	

	// body
	glBegin(GL_POLYGON);
	glColor3fv(c);
	glVertex2f(x-10,y-20);
	glVertex2f(x-10,y-60);
	glVertex2f(x+13,y-60);
	glVertex2f(x+13,y-20);
	glEnd();

	
	
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(clapVelocity,0.0,0.0);
	// Left Sleeve
	glBegin(GL_POLYGON);
	glColor3fv(c);
	glVertex2f(x-15,y-20);
	glVertex2f(x-15,y-40);
	glVertex2f(x-10,y-40);
	glVertex2f(x-10,y-20);
	glEnd();

	//Left Hand
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.8,0.0);
	glVertex2f(x-15,y-40);
	glVertex2f(x-15,y-50);
	glVertex2f(x-10,y-50);
	glVertex2f(x-10,y-40);
	glEnd();
	glPopMatrix();


	// Right Sleeve
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(-clapVelocity,0.0,0.0);
	glBegin(GL_POLYGON);
	glColor3fv(c);
	glVertex2f(x+13,y-20);
	glVertex2f(x+13,y-40);
	glVertex2f(x+18,y-40);
	glVertex2f(x+18,y-20);
	glEnd();

	//Right Hand
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.8,0.0);
	glVertex2f(x+13,y-40);
	glVertex2f(x+13,y-50);
	glVertex2f(x+18,y-50);
	glVertex2f(x+18,y-40);
	glEnd();
	glPopMatrix();

	// Pants
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(x+5,y-60);
	glVertex2f(x+5,y-80);
	glVertex2f(x+12,y-80);
	glVertex2f(x+12,y-60);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(x-9,y-60);
	glVertex2f(x-9,y-80);
	glVertex2f(x-1,y-80);
	glVertex2f(x-1,y-60);
	glEnd();

	//if(clapVelocity<1.0)
	//	clapVelocity+=1.0;		
	//else
	//	clapVelocity=0.0;
	

	


}


void draw_balloon(float x, float y, float radius) { 
	x_pos=x;
	y_pos=y;
	rad=radius;
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(x, y, 0.0f);
    static const int circle_points = 100;
    static const float angle = 2.0f * 3.1416f / circle_points;
    if(burst==0)
    {
    	glTranslatef(0.0,velocity,0.0);
    	glBegin(GL_POLYGON);
    	double angle1=0.0;
    	glVertex2d(radius * cos(0.0) , radius * sin(0.0));
    	int i;
    	for (i=0; i<circle_points; i++)
    	{       
        	glVertex2d(radius * cos(angle1), (radius *sin(angle1)));
        	angle1 += angle;
    	}
    	glEnd();
    }	
    	glPopMatrix();
    
    	//To draw the strings
    	glPushMatrix();
    	if(burst==0)
    	{
    		glTranslatef(0.0,velocity,0.0);
    	}
    	else
    	{
    		glTranslatef(0.0,-(velocity+5.0),0.0);
    	}
    	glBegin(GL_LINES);
    	glColor3f(0.0,0.0,0.0);
    	glVertex2f(x,(y-radius));
    	glVertex2f(x,(y-radius-18));
    	glEnd();
    	glPopMatrix();
	

    
}
void burst_ballon(int x,int y)
{
	if (x_pos+rad<x<x_pos-rad && y_pos+rad<y<y_pos-rad)
	{
		burst=1;

	}

}
void reshape(int w,int h)
{
	glViewport(0,0,w,h); 
	glClearColor(0.5,1.0,0.5,1.0);
	glMatrixMode(GL_PROJECTION);
	//gluOrtho2D(0.0,450.0,0.0,450.0);
	if(w<h)
		glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,-10.0,10.0);
	else
		glOrtho(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);
	
}
void printText(int x, int y, char *string)
{
	glRasterPos2f(x,y);

	while(*string)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*string++);
	}
}

void myinit()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,450.0,0,450.0);
    glMatrixMode(GL_MODELVIEW);


}

GLfloat hx=60.0,hy=50.0;
GLfloat ax=85.0,ay=50.0;
GLfloat px=110.0,py=50.0;
GLfloat px1=135.0;
GLfloat yx=160.0,yy=50.0;

GLfloat bx=205.0,by=50.0;
GLfloat ix=230.0;
GLfloat rx=240.0,ry=50.0;
GLfloat tx=265.0,ty;
GLfloat hx2=295.0;
GLfloat dx=320.0;
GLfloat ax2=350.0;
GLfloat yx2=375.0;



void happyBirthday()
{
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(50,60);
	glVertex2f(400,60);
	glVertex2f(400,10);
	glVertex2f(50,10);
	glEnd();
	if(blink==1)
	{
	// H

	// |
	
	glColor3f(1.0,0.0,0.0);
	draw_circle(hx,hy,3);
	draw_circle(hx,hy-5,3);
	draw_circle(hx,hy-10,3);
	draw_circle(hx,hy-15,3);
	
	//     |
	draw_circle(hx+15.0,hy,3);
	draw_circle(hx+15.0,hy-5,3);
	draw_circle(hx+15.0,hy-10,3);
	draw_circle(hx+15.0,hy-15,3);

	// __
	draw_circle(hx+5,hy-15,3);
	draw_circle(hx+10,hy-15,3);

	// down |
	draw_circle(hx,hy-20,3);
	draw_circle(hx,hy-25,3);
	draw_circle(hx,hy-30,3);
	
	// down   |
	draw_circle(hx+15,hy-20,3);
	draw_circle(hx+15,hy-25,3);
	draw_circle(hx+15,hy-30,3);


	// A
	//Top |
	glColor3f(0.0,1.0,0.0);
	draw_circle(ax,ay,3);
	draw_circle(ax,ay-5,3);
	draw_circle(ax,ay-10,3);

	//Top     |
	draw_circle(ax+15.0,ay,3);
	draw_circle(ax+15,ay-5,3);
	draw_circle(ax+15,ay-10,3);

	draw_circle(ax+5,ay,3);
	draw_circle(ax+10,ay,3);
	draw_circle(ax+15,ay,3);


	
	// Bottom |
	draw_circle(ax,ay-15,3);
	draw_circle(ax+5,ay-15,3);
	draw_circle(ax+10,ay-15,3);
	draw_circle(ax+15,ay-15,3);

	// -
	draw_circle(ax,ay-20,3);
	draw_circle(ax,ay-25,3);
	draw_circle(ax,ay-30,3);

	// Bottom     |
	draw_circle(ax+15,ay-20,3);
	draw_circle(ax+15,ay-25,3);
	draw_circle(ax+15,ay-30,3);
	
	//P
	glColor3f(0.0,0.0,1.0);
	// Long |
	draw_circle(px,py,3);
	draw_circle(px,py-5,3);
	draw_circle(px,py-10,3);
	draw_circle(px,py-15,3);
	draw_circle(px,py-20,3);
	draw_circle(px,py-25,3);
	draw_circle(px,py-30,3);

	// top --	
	draw_circle(px+5,py,3);
	draw_circle(px+10,py,3);
	draw_circle(px+15,py,3);
	
	// |
	draw_circle(px+15,py-5,3);
	draw_circle(px+15,py-10,3);
	draw_circle(px+15,py-15,3);

	// mid --
	draw_circle(px+10,py-15,3);
	draw_circle(px+5,py-15,3);

	//Second P in Black
	glColor3f(0.0,0.0,0.0);
	// Long |
	draw_circle(px1,py,3);
	draw_circle(px1,py-5,3);
	draw_circle(px1,py-10,3);
	draw_circle(px1,py-15,3);
	draw_circle(px1,py-20,3);
	draw_circle(px1,py-25,3);
	draw_circle(px1,py-30,3);

	// top --	
	draw_circle(px1+5,py,3);
	draw_circle(px1+10,py,3);
	draw_circle(px1+15,py,3);
	
	// |
	draw_circle(px1+15,py-5,3);
	draw_circle(px1+15,py-10,3);
	draw_circle(px1+15,py-15,3);

	// mid --
	draw_circle(px1+10,py-15,3);
	draw_circle(px1+5,py-15,3);

	// Y
	glColor3f(1.0,1.0,0.0);
	
	// First |
	draw_circle(yx,yy,3);
	draw_circle(yx,yy-5,3);
	draw_circle(yx,yy-10,3);
	draw_circle(yx,yy-15,3);

	// mid --
	draw_circle(yx+5,yy-15,3);
	draw_circle(yx+10,yy-15,3);
	draw_circle(yx+15,yy-15,3);

	// Long |
	draw_circle(yx+15,yy,3);
	draw_circle(yx+15,yy-5,3);
	draw_circle(yx+15,yy-10,3);
	draw_circle(yx+15,yy-15,3);
	draw_circle(yx+15,yy-20,3);
	draw_circle(yx+15,yy-25,3);
	draw_circle(yx+15,yy-30,3);
	
	//Bottom --
	draw_circle(yx+10,yy-30,3);
	draw_circle(yx+5,yy-30,3);
	draw_circle(yx,yy-30,3);

	// B
	// Neon Pink
	glColor3f(1.0,0.43,0.78);

	// front |
	draw_circle(bx,by,3);
	draw_circle(bx,by-5,3);
	draw_circle(bx,by-10,3);
	draw_circle(bx,by-15,3);
	draw_circle(bx,by-20,3);
	draw_circle(bx,by-25,3);
	draw_circle(bx,by-30,3);

	// Top --
	draw_circle(bx+5,by,3);
	draw_circle(bx+10,by,3);
	draw_circle(bx+15,by,3);
	
	//Mid --
	draw_circle(bx+5,by-15,3);
	draw_circle(bx+10,by-15,3);

	// Bottom --
	draw_circle(bx+5,by-30,3);
	draw_circle(bx+10,by-30,3);
	
	
	// Back |
	draw_circle(bx+15,by,3);
	draw_circle(bx+15,by-5,3);
	draw_circle(bx+15,by-10,3);
	draw_circle(bx+15,by-15,3);
	draw_circle(bx+15,by-20,3);
	draw_circle(bx+15,by-25,3);
	draw_circle(bx+15,by-30,3);

	// I
	//Sienna
	glColor3f(0.0,0.0,0.0);
	draw_circle(ix,50.0,3);
	draw_circle(ix,45.0,3);
	draw_circle(ix,40.0,3);
	draw_circle(ix,35.0,3);
	draw_circle(ix,30.0,3);
	draw_circle(ix,25.0,3);
	draw_circle(ix,20.0,3);

	// R
	// fron |
	// Brass
	glColor3f(0.71,0.65,0.26);
	draw_circle(rx,ry,3);
	draw_circle(rx,ry-5,3);
	draw_circle(rx,ry-10,3);
	draw_circle(rx,ry-15,3);
	draw_circle(rx,ry-20,3);
	draw_circle(rx,ry-25,3);
	draw_circle(rx,ry-30,3);

	// Top --
	draw_circle(rx,ry,3);
	draw_circle(rx+5,ry,3);
	draw_circle(rx+10,ry,3);
	

	// Mid --
	draw_circle(rx+5,ry-15,3);
	draw_circle(rx+10,ry-15,3);
	

	// Back |
	draw_circle(rx+15,ry,3);
	draw_circle(rx+15,ry-5,3);
	draw_circle(rx+15,ry-10,3);
	//draw_circle(rx+15,ry-15,3);
	draw_circle(rx+15,ry-20,3);
	draw_circle(rx+15,ry-25,3);
	draw_circle(rx+15,ry-30,3);

	//T
	// Top --
	// Scarlet 
	glColor3f(0.55,0.09,0.09);
	draw_circle(tx,yy,3);
	draw_circle(tx+5,yy,3);
	draw_circle(tx+10,yy,3);
	draw_circle(tx+15,yy,3);
	draw_circle(tx+20,yy,3);

	draw_circle(tx+10,yy-5,3);
	draw_circle(tx+10,yy-10,3);
	draw_circle(tx+10,yy-15,3);
	draw_circle(tx+10,yy-20,3);
	draw_circle(tx+10,yy-25,3);
	draw_circle(tx+10,yy-30,3);

	// H
	// |
	// Steel Blue
	glColor3f( 0.560784, 0.560784, 0.737255);
	draw_circle(hx2,hy,3);
	draw_circle(hx2,hy-5,3);
	draw_circle(hx2,hy-10,3);
	draw_circle(hx2,hy-15,3);
	
	//     |
	draw_circle(hx2+15.0,hy,3);
	draw_circle(hx2+15.0,hy-5,3);
	draw_circle(hx2+15.0,hy-10,3);
	draw_circle(hx2+15.0,hy-15,3);

	// __
	draw_circle(hx2+5,hy-15,3);
	draw_circle(hx2+10,hy-15,3);

	// down |
	draw_circle(hx2,hy-20,3);
	draw_circle(hx2,hy-25,3);
	draw_circle(hx2,hy-30,3);
	
	// down   |
	draw_circle(hx2+15,hy-20,3);
	draw_circle(hx2+15,hy-25,3);
	draw_circle(hx2+15,hy-30,3);

	// D
	glColor3f(0.258824, 0.258824, 0.435294);
	
	// Top --
	draw_circle(dx,yy,3);
	draw_circle(dx+5,yy,3);
	draw_circle(dx+10,yy,3);
	draw_circle(dx+15,yy,3);
	draw_circle(dx+20,yy,3);

	// Front |
	draw_circle(dx+5,yy-5,3);
	draw_circle(dx+5,yy-10,3);
	draw_circle(dx+5,yy-15,3);
	draw_circle(dx+5,yy-20,3);
	draw_circle(dx+5,yy-25,3);
	

	// Back |
	draw_circle(dx+20,yy-5,3);
	draw_circle(dx+20,yy-10,3);
	draw_circle(dx+20,yy-15,3);
	draw_circle(dx+20,yy-20,3);
	draw_circle(dx+20,yy-25,3);

	draw_circle(dx,yy-30,3);
	draw_circle(dx+5,yy-30,3);
	draw_circle(dx+10,yy-30,3);
	draw_circle(dx+15,yy-30,3);
	draw_circle(dx+20,yy-30,3);

	// Second A
	glColor3f(0.0,1.0,0.0);
	draw_circle(ax2,ay,3);
	draw_circle(ax2,ay-5,3);
	draw_circle(ax2,ay-10,3);

	//Top     |
	draw_circle(ax2+15.0,ay,3);
	draw_circle(ax2+15,ay-5,3);
	draw_circle(ax2+15,ay-10,3);

	draw_circle(ax2+5,ay,3);
	draw_circle(ax2+10,ay,3);
	draw_circle(ax2+15,ay,3);


	
	// Bottom |
	draw_circle(ax2,ay-15,3);
	draw_circle(ax2+5,ay-15,3);
	draw_circle(ax2+10,ay-15,3);
	draw_circle(ax2+15,ay-15,3);

	// -
	draw_circle(ax2,ay-20,3);
	draw_circle(ax2,ay-25,3);
	draw_circle(ax2,ay-30,3);

	// Bottom     |
	draw_circle(ax2+15,ay-20,3);
	draw_circle(ax2+15,ay-25,3);
	draw_circle(ax2+15,ay-30,3);

	// Second Y
	glColor3f(1.0,1.0,0.0);
	
	// First |
	draw_circle(yx2,yy,3);
	draw_circle(yx2,yy-5,3);
	draw_circle(yx2,yy-10,3);
	draw_circle(yx2,yy-15,3);

	// mid --
	draw_circle(yx2+5,yy-15,3);
	draw_circle(yx2+10,yy-15,3);
	draw_circle(yx2+15,yy-15,3);

	// Long |
	draw_circle(yx2+15,yy,3);
	draw_circle(yx2+15,yy-5,3);
	draw_circle(yx2+15,yy-10,3);
	draw_circle(yx2+15,yy-15,3);
	draw_circle(yx2+15,yy-20,3);
	draw_circle(yx2+15,yy-25,3);
	draw_circle(yx2+15,yy-30,3);
	
	//Bottom --
	draw_circle(yx2+10,yy-30,3);
	draw_circle(yx2+5,yy-30,3);
	draw_circle(yx2,yy-30,3);

	
	
	}
	



}
void update(int value)
{
	
	glutPostRedisplay();
	
	if(boxVelocity<20.0)
		boxVelocity +=2.0;
	else
		boxVelocity=0.0;

	if(clapVelocity<15.0 && clap == 1)
		clapVelocity+=2.0;
	else
		clapVelocity=0.0;

	if(velocity<250.0)
    	velocity +=2.5;
    else
    	if(burst == 0)
    	velocity=0.0;
	
	
	if(blink==0)
	blink=1;
	else
	blink=0;

		
	//glutTimerFunc(10000,update,0);
	glutPostRedisplay();
			
}


void scene1()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0,1.0,1.0,0.0);
	col cl[]={{0.8,0.8,0.0},{0.0,0.8,0.8},{0.5,0.0,0.5},{0.2,0.5,0.0},{0.5,0.2,0.0},{1.0,0.0,0.5}};

	if(blow==1)
		flame=0;
	else
		flame=1;
	
	

	draw_face(175.0,230.0,blow);

	// Left Dirty green audience
	draw_people(50,270,cl[0]);

	// Left Sky blue audience
	draw_people(50,220,cl[1]);

	// Left purple audience
	draw_people(100,250,cl[2]);

	// Right Dark green audience 
	draw_people(350,250,cl[3]);

	// Right Brown audience
	draw_people(400,270,cl[4]);

	// Right 
	draw_people(400,220,cl[5]);

	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);

	//Red Balloon
	glColor3f(1.0,0.0,0.0);
	draw_balloon(50.0f, 325.0f, 20.0f);


	//Green Ballon
	glColor3f(0.0,1.0,0.0);
	draw_balloon(120.0f, 340.0f, 20.0f);

	//Blue Ballon
	glColor3f(0.0,0.0,1.0);
	draw_balloon(40.0f, 400.0f, 20.0f);

	//Aqua Ballon
	glColor3f(0.0,1.0,1.0);
	draw_balloon(200.0f, 410.0f, 20.0f);

	//Yellow Balloon
	glColor3f(1.0,1.0,0.0);
	draw_balloon(300.0f, 350.0f, 20.0f);

	//Pink Balloon
	glColor3f(1.0,0.0,0.5);
	draw_balloon(380.0f, 400.0f, 20.0f);

	// Light cream Balloon
	glColor3f(1.0,1.0,0.5);
	draw_balloon(410.0f, 325.0f, 20.0f);

	glBegin(GL_QUADS);
	draw_candle(120.0,130.0,flame);
	glEnd();

	glBegin(GL_QUADS);
	draw_candle(160.0,130.0,flame);
	glEnd();

	glBegin(GL_QUADS);
	draw_candle(270.0,130.0,flame);
	glEnd();

	glBegin(GL_QUADS);
	draw_candle(310.0,130.0,flame);
	glEnd();

	// Cake
	glBegin(GL_QUADS);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(80.0,80.0);
	glVertex2f(350.0,80.0);
	glVertex2f(350.0,130.0);
	glVertex2f(80.0,130.0);
	glEnd();

	//char s[16]= "Happy Birthday\0";
	
	/*glColor3f(0.0,0.0,0.0);
	glRasterPos2f(150.0,ax);
	for(int i=0;i<16;i++)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[i]);
	*/
	happyBirthday();
	
	

	//glutPostRedisplay();
	glutTimerFunc(2000,update,0); 
	
	glutSwapBuffers();

	
	
	
}

void scene2()
{
	
	col c[]={{1.0,0.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},{1.0,1.0,0.0},
	{1.0,0.5,0.5},{0.5,0.0,1.0},{0.0,0.5,0.0},{0.0,1.0,1.0},{1.0,0.0,1.0}};
	GLfloat x=210.0, y=280.0;
	

	glClear(GL_COLOR_BUFFER_BIT);
	
	//glutSwapBuffers();
	glColor3f(1.0,1.0,0.0);
	draw_people2(200,300,c[0]);

	// gift box
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(boxVelocity,0.0,0.0);
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x-5,y);
	glVertex2f(x+20,y);
	glVertex2f(x+20,y-20);
	glVertex2f(x-5,y-20);
	glEnd();

	// Ribbon circle
	glColor3f(0.0,0.0,1.0);
	draw_ribbonCircle(x+7.5,y+2.5,3);

	// Vertical Ribbon Strip
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(x+5.5,y);
	glVertex2f(x+10.5,y);
	glVertex2f(x+10.5,y-20);
	glVertex2f(x+5.5,y-20);
	glEnd();

	// Horizontal Ribbon strip
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(x-5,y-10);
	glVertex2f(x+20,y-10);
	glVertex2f(x+20,y-5);
	glVertex2f(x-5,y-5);
	glEnd();
	glPopMatrix();

	//Birthday Boy

	// Circular Face
	glColor3f(1.0,0.7,0.0);	
	draw_circle(275,300,25);
	

	//Black eyes
	
	// Left Eye 
	glColor3f(0.0,0.0,0.0);
	draw_circle(270,305,1.5);

	// Right Eye
	glColor3f(0.0,0.0,0.0);
	draw_circle(255,305,1.5);

	//Red Lips
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(x+45,y+15);
	glVertex2f(x+60,y+15);
	glVertex2f(x+60,y+12);
	glVertex2f(x+45,y+12);
	glEnd();

	// Black body
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(x+40,y);
	glVertex2f(x+40,y-40);
	glVertex2f(x+90,y-40);
	glVertex2f(x+90,y);
	glEnd();

	//Left Hand
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.8,0.0);
	glVertex2f(x+20,y-20);
	glVertex2f(x+40,y-20);
	glVertex2f(x+40,y-25);
	glVertex2f(x+20,y-25);
	glEnd();

	// Left Leg
	glBegin(GL_POLYGON);
	glColor3f(0.0,1.0,0.0);
	glVertex2f(x+50,y-40);
	glVertex2f(x+50,y-60);
	glVertex2f(x+60,y-60);
	glVertex2f(x+60,y-40);
	glEnd();

	// Right Leg
	glBegin(GL_POLYGON);
	glColor3f(0.0,1.0,0.0);
	glVertex2f(x+70,y-40);
	glVertex2f(x+70,y-60);
	glVertex2f(x+80,y-60);
	glVertex2f(x+80,y-40);
	glEnd();



	// Bottom Left Pair
	draw_rightPeople(30,200,c[0]);
	draw_leftPeople(100,200,c[1]);

	// Bottom Right Pair
	draw_rightPeople(350,200,c[2]);
	draw_leftPeople(410,200,c[3]);

	// Top Left  Pair
	draw_rightPeople(50,350,c[3]);
	draw_leftPeople(120,350,c[4]);
		
	
	// Top Right Pair
	draw_rightPeople(350,350,c[5]);
	draw_leftPeople(410,350,c[6]);

	// Bottom Middle Pair
	draw_rightPeople(200,150,c[7]);
	draw_leftPeople(270,150,c[8]);
	
	glutTimerFunc(3000,update,0);
	glutSwapBuffers();
}

void keyPressed(unsigned char key, int x, int y)
{
	if(key==13)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glutDisplayFunc(scene1);
		glutPostRedisplay();
		
	}
}


void projectTitle()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	
	//Aqua Ballon
	glColor3f(0.0,1.0,1.0);
	draw_balloon(200.0f, 410.0f, 20.0f);

	//Pink Balloon
	glColor3f(1.0,0.0,0.5);
	draw_balloon(380.0f, 400.0f, 20.0f);

	//Blue Ballon
	glColor3f(0.0,0.0,1.0);
	draw_balloon(40.0f, 400.0f, 20.0f);

	//Aqua Ballon
	glColor3f(0.0,1.0,1.0);
	draw_balloon(200.0f, 410.0f, 20.0f);

	//Purple Ballon
	glColor3f(1.0,0.0,1.0);
	draw_balloon(40.0f, 400.0f, 20.0f);

	//Top Right Light Brown Balloon
	glColor3f(0.8,0.8,0.0);
	draw_balloon(380.0f, 400.0f, 20.0f);
	
	//Yellow Balloon
	glColor3f(1.0,1.0,0.0);
	draw_balloon(300.0f, 350.0f, 20.0f);

	// green
	glColor3f(1.0,1.0,0.0);
	draw_balloon(120.0f, 340.0f, 20.0f);

	// Red Balloon
	glColor3f(1.0,0.0,0.0);
	draw_balloon(50.0f, 260.0f, 20.0f);
	
	// Dark Blue Balloon
	glColor3f(0.0,0.0,0.3);
	draw_balloon(410.0f, 325.0f, 20.0f);

	//Dirty Brown Ballon
	glColor3f(0.5,0.5,0.0);
	draw_balloon(200.0f, 280.0f, 20.0f);

	// green ballon
	glColor3f(0.0,1.0,0.0);
	draw_balloon(120.0f, 240.0f, 20.0f);

	//Pink Balloon
	glColor3f(1.0,0.0,0.5);
	draw_balloon(380.0f, 200.0f, 20.0f);

	// Aqua light Blue Ballon
	glColor3f(0.0,0.0,0.0);
	draw_balloon(200.0f, 160.0f, 20.0f);

	//Blue Ballon
	glColor3f(0.0,0.0,1.0);
	draw_balloon(40.0f, 150.0f, 20.0f);

	//Bottom Dark purple Balloon
	glColor3f(0.5,0.0,0.5);
	draw_balloon(300.0f, 150.0f, 20.0f);

	// Light Cream Ballo0n
	glColor3f(1.0,1.0,0.5);
	draw_balloon(410.0f, 125.0f, 20.0f);

	glColor3f(0.0,0.0,0.0);
	printText(120,400,(char *)"Graphical Implementation of");
	printText(150,380,(char *)"Birthday Celebration");

	glColor3f(1.0,0.0,0.0);
	printText(50,250,(char *)"Akshay Kumar H");

	glColor3f(1.0,0.0,0.0);
	printText(50,230,(char *)"1BY12CS006");

	glColor3f(0.0,1.0,0.0);
	printText(270,250,(char *)" L Surya Prakash");

	glColor3f(0.0,1.0,0.0);
	printText(273,230, (char *)"1BY12CS029");
	

	glColor3f(0.0,0.0,1.0);
	printText(130,100, (char *)"Under the guidance of: ");
	printText(150,80, (char *)"Ms.Ambika G N");
	printText(140,60,(char *)"Assistant Professor");
	printText(40,40, (char *)"Department of Computer Science and Engineering");
	printText(180,20, (char *)"BMSIT");

	glutSwapBuffers();
	
	
}



void display()
{
	
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0,1.0,1.0,1.0);
	
	projectTitle();
	
	
	
	glutTimerFunc(2000,update,0); 
	//RenderString(0.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Hello", RGB(1.0f, 0.0f, 0.0f));
	
	
	/*glBegin(GL_TRIANGLES);
	glColor3f(1.0,1.0,0.0);
	glVertex2f(100.0,100.0);
	glVertex2f(105.0,150.0);
	glVertex2f(110.0,100.0);*/
	
	//glVertex2f(360.0,350.0);
	
	glutSwapBuffers();
}

void mouse_handler(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		
		burst_ballon(x,y);


	}
}

void menu_function(int id)
{
	switch(id)
	{
		case 1: blow = 1;
		break;
		case 2: clap = 1;
		break;
		case 3:
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
		glutDisplayFunc(scene2);
		break;

	}

}

	


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Birthday Celebration");

	glutDisplayFunc(display);

	glutMouseFunc(mouse_handler);

	glutKeyboardFunc(keyPressed);

	
	glutCreateMenu(menu_function);
	glutAddMenuEntry("Blow Candle",1);
	glutAddMenuEntry("Clap Hands",2);
	glutAddMenuEntry("Give Gift",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
	//glutReshapeFunc(reshape);
	myinit();

	glutMainLoop();
	return 0;
}