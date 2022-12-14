#include "../shared/gltools.h"	
#include <windows.h>
#include <stdlib.h>
#include <math.h>

const int Width=1024;
const int Height = 768;
int DrawAxis = 0;

GLfloat	 lightPos[] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat  whiteLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat  sourceLight[] = { 0.8f, 0.8f, 0.8f, 1.0f };

struct STAR 
{
    GLfloat x;
    GLfloat y;
    GLfloat size;
};

#define NUM_STARS      600
STAR Stars[NUM_STARS];

void drawAxis()
{
     if( DrawAxis )
     {
         
         glColor3f(1,0,0);                   
         glBegin(GL_LINES);
         glVertex3f(-10,0,0);      
         glVertex3f(10,0,0);  
         glEnd();  
         
         
         glColor3f(0,1,0);          
         glBegin(GL_LINES);                  
         glVertex3f(0,-8,0);      
         glVertex3f(0,8,0);  
         glEnd(); 
          
        
         glColor3f(0,0,1);           
         glBegin(GL_LINES);           
         glVertex3f(0,0, -10);      
         glVertex3f(0,0,10);           
         glEnd();  
    }    
}

void renderScene(void)
{
    
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    
    const double a = t*60.0;

    
	glMatrixMode(GL_MODELVIEW);
	
	glLoadIdentity();
	
	gluLookAt(5,6,13, 0,0,0, 0,1,0);

    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_LIGHTING); 
    drawAxis();
           
   
    glColor3f(0.6,0.6,0.6); 
         
 
    for (int i = 0 ; i < NUM_STARS ; i++ )
    {
       
       glPointSize(Stars[i].size);
       
       glBegin(GL_POINTS);
       glVertex3f(Stars[i].x,Stars[i].y, -20.0f);           
       glEnd();    
    }
        
   
    glColor3f(1,1,0);   
   
    glPushMatrix(); 
    
    glScalef(1,1,1);  
      
    glutSolidSphere(1,64,64);
    
    glPopMatrix(); 
    glEnable(GL_LIGHTING);
    
    glLightfv(GL_LIGHT0,GL_POSITION,lightPos);

   
    glColor3f(0,0,1);    
   
    glRotatef(a,0,1,0);    
   
    glTranslatef(0,0,-6);
   
    glPushMatrix();    
    
    glScalef(0.5,0.5,0.5);  
         
    glutSolidSphere(1, 16, 16);
   
    glPopMatrix(); 
 
    glColor3f(0.5f,0.5f,0.5f);  
    
    glRotatef(-4*a,0,1,0);    
       
    glTranslatef(0,0,-1.5);
    
    glScalef(0.25,0.25,0.25); 
                         
    glutSolidSphere(1, 16, 16);

        
    glutSwapBuffers();
}


void keyPress(unsigned char key, int x, int y)
{
    switch (key) 
    {
             
        case 27 : 
        case 'q':
       
            exit(0);
            break;
        case 'a':
        case 'A':
             DrawAxis = 1 - DrawAxis;

    }

    glutPostRedisplay();
}


void init(void)
{
    float fAspect = ((float)Width)/Height;
   
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    
     glMatrixMode (GL_PROJECTION);
   
     glLoadIdentity ();
     
     gluPerspective(45.0f, fAspect, 1.0, 400.0);
             
   
    for (int i = 0 ; i < NUM_STARS ; i++ )
    {
        float x = ((float)((rand() % 800) - 400) * 0.1f);
        float y = ((float)((rand() % 800) - 400) * 0.1f);
        float size = 1 + rand() % 3;
        Stars[i].x = x;
        Stars[i].y = y;
        Stars[i].size = size;
    }
    
     glEnable(GL_CULL_FACE);
     glCullFace(GL_BACK);
     glEnable(GL_DEPTH_TEST);
     glDepthFunc(GL_LESS);    
    
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,whiteLight);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,sourceLight);               
}


int main(int argc, char *argv[])
{
  
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    
    glutInitWindowSize(Width, Height);
    glutInitWindowPosition(150,150);
    glutCreateWindow("Solar System");

  
    glutDisplayFunc(renderScene);

    
    glutKeyboardFunc(keyPress);    
    
  
    glutIdleFunc(renderScene);

    init();
    
    glutMainLoop();

    return EXIT_SUCCESS;
}
