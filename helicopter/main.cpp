#include<windows.h>
#include <GL/glut.h>
#include <math.h>

//DIASTASEIS OTHONIS
const GLint Width=800;
const GLint Height = 600;
GLint DrawAxis = 0, Power=0;
GLdouble b,x_1,f,f1,x1;

/*********************************************
   SXEDIASMOS SYSTHMATOS AKSONON
*********************************************/
void drawAxis()
{
     if( DrawAxis )
     {
	 	glLineWidth(3);
         //X 
         glColor3f(1,0,0);                   
         glBegin(GL_LINES);
         glVertex3f(-10,0,0);      
         glVertex3f(10,0,0);  
         glEnd();  
         
         //Y 
         glColor3f(1,1,0);          
         glBegin(GL_LINES);                  
         glVertex3f(0,-8,0);      
         glVertex3f(0,8,0);  
         glEnd(); 
          
         //Z 
         glColor3f(0,1,0);           
         glBegin(GL_LINES);           
         glVertex3f(0,0, -10);      
         glVertex3f(0,0,10);           
         glEnd();  
    }    
}

// KONOS
/*void konos()
{
float radius, halfLength;
int slices;
radius=2, halfLength=3;slices=16;
for(int i=0; i<slices; i++) {
float theta = ((float)i)*2.0*M_PI/slices;
float nextTheta = ((float)i+1)*2.0*M_PI/slices;

glColor3f(0,1,0);

glBegin(GL_TRIANGLE_STRIP);
/*vertex at middle of end */ 
//glVertex3f(0.0, halfLength, 0.0);
/*vertices at edges of circle*/ 
//glVertex3f(radius*cos(theta), halfLength, radius*sin(theta));
// glVertex3f (radius*cos(nextTheta), halfLength, radius*sin(nextTheta));
/* the same vertices at the bottom of the cylinder*/

//glVertex3f (radius*cos(nextTheta), -halfLength, radius*sin(nextTheta));
//glVertex3f(radius*cos(theta), -halfLength, radius*sin(theta));
//glVertex3f(0.0, -halfLength, 0.0);
//glEnd();
//} 
// }



//kentro
void kentro()
{
       //SWMA ELIKOPTEROU
  glColor3f(1,2,0.6);
  //glTranslated(0,5,0);
  glTranslated(0,-1.2,0);
  //glTranslated(2,5,2);
  glScalef(4,1,1.5);
   glutSolidCube(2);
   //SWMA ELIKOPTEROU 
    
     }
 
// MISOS ELIKAS 
void semiHelix()
{
     glRotatef(180,0.5,0,0);
     glBegin(GL_TRIANGLE_FAN);
     glVertex3f(0,0,0);
     glVertex3f(2,0,1);
     glVertex3f(4,0,1); 
     glVertex3f(4,0,-1);
     glVertex3f(2,0,-1);
     glEnd(); 
   }    
     
/*********************************************
    SXEDIASMOS ANTIKEIMENVN STH SKHNH
*********************************************/
void renderScene(void)
{
    //ZHTAEI TO XRONO POY EXEI PERASEI APO THN ARXH TOY PROGRAMMATOS
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    //TO A 8A EINAI H GWNEIA PERISTROFHS AYTH TH XRONIKH STIGMH
    const double a = t*60.0;
 
    //KA8ORISE TON PINAKA ModelView SAN TON ENERGO PINAKA
	glMatrixMode(GL_MODELVIEW);
	//KANE TON PINAKA ModelView ISO ME TON MONADIAIO PINAKA
	glLoadIdentity();
	//KA8ORISE POY 8A KOITAEI H KAMERA
	gluLookAt(5,4,20, 0,0,0, 0,1,0);
    //KA8ARISE THN O8ONH
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 //   glDisable(GL_LIGHTING); 
    drawAxis();     
   
glTranslatef(x1,0,x_1);

glRotatef(f,0,0,1);

glTranslatef(x1,f1,0);
glPushMatrix();
kentro();
glPopMatrix();

//PERISTROFH ELIKAS
glRotatef(a+Power,0,1,0);


//glPopMatrix();
//***************************

//glColor3f(1,1,0);		
//glLineWidth(6);
 
//glRotatef(f,0,0,1); 

//glBegin(GL_LINES);
//                  glVertex3f(0,0,0);
//                  glVertex3f(0,5,0);
//glEnd();

//glTranslatef(0,5,0); 
//glRotatef(f1,0,0,1);  

//;

//glBegin(GL_LINES);
//                  glVertex3f(0,0,0);
//                  glVertex3f(3,3,0);
//glEnd();  
//********************   
//     konos();

     
// DHMIOYRGIA SPHERAS STON ELIKA
glColor3f(0.5,0.5,0.5);  
glutSolidCube(1);
glColor3f(0,0,0);
 
  glScalef(2,.5,.5);
  semiHelix();
  
 
//glPopMatrix();

  
//elikas2    
  glColor3f(0,0,0);
   
// DHMIOYRGIA DEYTERHS ELIKAS APENANTI
  glRotatef(180,0,1,0);
  //glScalef(1.5,.5,.5);
  //glScalef(1,1,2);
   
semiHelix();

 
//glPopMatrix();    
  //glColor3f(0,0,1);
  
// DHMIOYRGIA DEYTERHS ELIKAS APENANTI
  glRotatef(180,0,0,0);
  //glScalef(0.5,.5,.5);
  //glScalef(1,1,2);
  
semiHelix();

// ENERGOPOIHSH DIPLOY PINAKA O8ONHS
	glutSwapBuffers();
	
}

/*********************************************
    SYNARTHSH POY ELEGXEI TI EXEI PATH8EI STO PLHTROLOGIO
*********************************************/
void keyPress(unsigned char key, int x, int y)
{
    switch (key) 
    {
        //ELEGXEI AN EXEI PATH8EI "ESC" H 'q'        
        case 27 : 
        case 'q':
        //AN EXEI PATH8EI "ESC" H 'q' TERMATIZETAI TO PROGRAMMA
        exit(0);
        break;        
        case 'h':
             DrawAxis = 1 - DrawAxis;
              break;
          case 'p': 
		  Power=Power+50;     
      			break;
      
          //mprosta
          case 'f': 
		  x_1=x_1+1;      
		  break;
		  
		  //pisw
           case 'b': 
		  x_1=x_1-1; 
               
          //peristrofes
          case 'g': 
		  f=f+1;      
		  break;
          case 'j': 
		  f=f-1;      
		  break; 
		  
		  //anevenei
          case 'w': 
		  f1=f1+1;    
          Power=Power+50;
		  break;
		  
		  //katevenei
          case 's': 
		  f1=f1-1;      
		  break;
		  
		  //aristera
          case 'a': 
		  x1=x1-1;      
		  break;
		  
		  //dexia
		  case 'd': 
		  x1=x1+1;      
		  break;
    }

}

/*********************************************
    ERXIKOPOIHSH THS EFARMOGHS. OI ENTOLES AYTES 8A EKTELESTOYN MONO MIA FORA
*********************************************/
void init(void)
{
    float fAspect = ((float)Width)/Height;
    //XRWMA KA8ARISMOY TOY PARA8YROY
    glClearColor(0.6f, 0.2f, 0.3f, 0.0f);
    b=x_1=0;f=f1=0;
     
     /* KA8ORISMOS ENERGOY PINAKA. 
     OTI METASXIMATISMOYS EFARMOSOYME 8A EPIRAESOYN TON PINAKA PROBOLHS */
     glMatrixMode (GL_PROJECTION);
          
     //KANE TON PINAKA PROBOLHS ISO ME TON MONADIAIO PINAKA
     glLoadIdentity ();
     
     //ORISE PROBOLH ME PROOPTIKH
    gluPerspective(50.0f, fAspect, 1.0, 400.0);
    //glOrtho(-35,35,-35,35,40,-40);         
   
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);    
              
}
/* ARXIKH SYNARTHSH. ME AYTH ARXIZEI H EKTELESH TOY PROGRAMMATOS*/
int main(int argc, char *argv[])
{
    //ARXIKOPOIHSH  GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    
    //DHMIOYRGEIA PARA8YROY EFARMOGHS
    glutInitWindowSize(Width, Height);
    glutInitWindowPosition(10,10);
    glutCreateWindow("MARIA PAPADOPOULOU");
    
    /* KA8ORISMOS SYNARTHSHS POY KALEITE OTAN XREIAZETAI 
    NA EPANASXEDIASTEI TO PARA8YRO */
    
     //Polygon front faces are to be filled. 
               // glPolygonMode(GL_FRONT,GL_LINE); 
     //Polygon back faces are to be drawn as lines 
               //glPolygonMode(GL_BACK,GL_LINE);
    
    glutDisplayFunc(renderScene);
    
    //KA8ORISMOS THS SYNARTHSHS POY ELEGXEI TO PLHKTROLOGIO
    glutKeyboardFunc(keyPress);
           
    /*KA8ORISMOS THS SYNARTHSHS POY KALEITAI OTAN TO GLUT 
    DEN E3YPHRETEI KAPOIO SYMBAN*/
    glutIdleFunc(renderScene);
    init();
    glutMainLoop();
   // return EXIT_SUCCESS;
}

