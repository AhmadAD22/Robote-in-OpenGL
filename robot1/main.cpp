#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
static GLfloat shoulder = 0, elbow1 = 0 ,elbow = 0 ,kf=0 ,f1=0, shoulder1 = 0 ,r_thig=0,l_thig=0,body=0;
static GLfloat r_po,l_po,head1=0;
static GLfloat move1=-8,up=0.0 ,dep=0.0;
static int i=0;
//>>>>>>>>>>>>>>>>>>>>>>>LIGHTING<<<<<<<<<<<<<<<<<<<<<<<<<<<<
   GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
   GLfloat mat_a_body[] = { 0.2, 0.2, 0.2, 1.0 };
   GLfloat mat_d_body[] = { 0.4, 0.4, 0.4, 1.0 };
   GLfloat mat_s_body[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat mat_a_middl[] = { 0.2, 0.2, 0.2, 1.0 };
   GLfloat mat_d_middl[] = { 0.9, 0.9, 0.9, 1.0 };
   GLfloat mat_d_shoul[] = { 0.2, 0.2, 0.2, 1.0 };
   GLfloat mat_d_head[] = { 0.2, 0.2, 0.2, 1.0 };
   GLfloat mat_d_head1[] = { 0.9, 0.2, 0.2, 1.0 };
   GLfloat mat_s_head1[] = { 0.1, 0.1, 0.1, 1.0 };
   GLfloat mat_d_h_hand[] = { 0.2, 0.2, 0.2, 1.0 };
   GLfloat mat_d_l_hand[] = { 0.9, 0.9, 0.9, 1.0 };
   GLfloat mat_a_inv[] = { 0.1, 0.4, 0.7, 1.0 };
   GLfloat mat_d_inv[] = { 0.7, 0.7, 0.7, 1.0 };
   GLfloat mat_a_paint[] = { 0.4, 0.4, 0.4, 1.0 };
   GLfloat mat_d_paint[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat mat_a_ground2[] = { 0.1, 0.1, 0.4, 1.0 };
   GLfloat mat_d_ground2[] = { 0.5, 0.5, 0.2, 1.0 };
    GLfloat mat_a_dumb[] = { 0.0, 0.0, 0.0, 1.0 };
     GLfloat mat_s_dumb[] = { 0.1, 0.1, 0.1, 1.0 };
   GLfloat mat_d_dumb[] = { 0.0, 0.0, 0.0, 1.0 };
   GLfloat no_shininess[] = { 0.0 };
   GLfloat low_shininess[] = { 4.0 };
   GLfloat high_shininess[] = { 7.0 };

void init(void)
{
     glClearColor (0.2, 0.2, 0.2, 0.0);
//......................FIRST LIGHT....................
   GLfloat ambient[] = { 0.2,0.2, 0.2, 1.0 };
   GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat specular[] = { 0.1, 0.1, 0.1, 1.0 };
   GLfloat position[] = { 1.0, 5.0, 1.0, 0.0 };
   //....................SEC LIGHT...............
   GLfloat ambient1[] = { 0.1,0.1, 0.1, 1.0 };
   GLfloat diffuse1[] = { 0.6, 0.6, 0.5, 1.0 };
   GLfloat specular1[] = { 0.0, 0.0, 0.0, 1.0 };
   GLfloat position1[] = { 2.0, 3.0, 1.0, 1.0 };

   glEnable(GL_DEPTH_TEST);
   glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
   glLightfv(GL_LIGHT0,GL_SPECULAR, specular);
   glLightfv(GL_LIGHT0, GL_POSITION, position);
   //....................SEC LIGHT...............
   glLightfv(GL_LIGHT1, GL_AMBIENT, ambient1);
   glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse1);
   glLightfv(GL_LIGHT1,GL_SPECULAR, specular1);
   glLightfv(GL_LIGHT1, GL_POSITION, position1);
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_LIGHT1);
  //glEnable(GL_COLOR_MATERIAL);
}
//***************environment*******************************
void ground (){
   glPushMatrix();
   glMaterialfv(GL_FRONT, GL_AMBIENT,mat_a_inv);
   glMaterialfv(GL_FRONT, GL_DIFFUSE,mat_d_inv);
   glMaterialfv(GL_FRONT, GL_SHININESS,low_shininess);
   glColor3f(0.2,0.2,0.2);
   glTranslatef(0.0,-5.0,-3.0);
   glScalef(40,2,-40);
   glutSolidCube(1);
   glPopMatrix();
}
void roof (){
   glPushMatrix();
   glMaterialfv(GL_FRONT, GL_AMBIENT,mat_a_inv);
   glMaterialfv(GL_FRONT, GL_DIFFUSE,mat_d_inv);
   glMaterialfv(GL_FRONT, GL_SHININESS,low_shininess);
   glColor3f(0.2,0.2,0.2);
   glTranslatef(0.0,9.0,-3.0);
   glRotatef(1,1.0,0.0,0.0);
  glScalef(40,2,-40);
   glutSolidCube(1);
   glPopMatrix();
}
void l_wall(){
   glPushMatrix();
   glMaterialfv(GL_FRONT, GL_AMBIENT,mat_a_inv);
   glMaterialfv(GL_FRONT, GL_DIFFUSE,mat_d_inv);
   glMaterialfv(GL_FRONT, GL_SHININESS,low_shininess);
   glColor3f(0.2,0.2,0.2);
   glTranslatef(-11.0,0.0,-3.0);
  glScalef(2,40,-40);
   glutSolidCube(1);
   glPopMatrix();
}
void r_wall(){
   glPushMatrix();
      glPushMatrix();
   glMaterialfv(GL_FRONT, GL_AMBIENT,mat_a_inv);
   glMaterialfv(GL_FRONT, GL_DIFFUSE,mat_d_inv);
   glMaterialfv(GL_FRONT, GL_SHININESS,low_shininess);
   glColor3f(0.2,0.2,0.2);
   glTranslatef(11.0,0.0,-3.0);
   glRotatef(1,0.0,0.0,1.0);
  glScalef(2,40,-40);
   glutSolidCube(1);
   glPopMatrix();
   //............................WINDOW.........................
   glPushMatrix();
      glPushMatrix();
   glMaterialfv(GL_FRONT, GL_AMBIENT,mat_a_paint);
   glMaterialfv(GL_FRONT, GL_DIFFUSE,mat_d_paint);
   glMaterialfv(GL_FRONT, GL_SHININESS,low_shininess);
   glColor3f(0.1,0.3,0.1);
   glTranslatef(10.5,1.0,-3.0);
  glScalef(1.5,3,-3);
   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();
   glColor3f(0.0,1.0,1.0);
   glTranslatef(11.0,2.3,-3.0);
   glRotatef(1,0.0,0.0,-0.01);
  glScalef(3,0.1,0.1);
   glutSolidCube(1);
   glPopMatrix();
   glPopMatrix();
}
void b_wall (){
   glPushMatrix();
   glMaterialfv(GL_FRONT, GL_AMBIENT,mat_a_inv);
   glMaterialfv(GL_FRONT, GL_DIFFUSE,mat_d_inv);
   glMaterialfv(GL_FRONT, GL_SHININESS,low_shininess);
   glColor3f(0.2,0.2,0.2);
   glTranslatef(0.0,0.0,-10.0);
  glScalef(40,40,2);
   glutSolidCube(1);
   glPopMatrix();
}
void front_wall (){
   glPushMatrix();
   glMaterialfv(GL_FRONT, GL_AMBIENT,mat_a_inv);
   glMaterialfv(GL_FRONT, GL_DIFFUSE,mat_d_inv);
   glMaterialfv(GL_FRONT, GL_SHININESS,low_shininess);
   glColor3f(0.2,0.2,0.2);
   glTranslatef(0.0,0.0,10.0);
  glScalef(40,40,2);
   glutSolidCube(1);
   glPopMatrix();
}
void ground2(){
   glPushMatrix();
   glMaterialfv(GL_FRONT, GL_AMBIENT,mat_a_ground2);
   glMaterialfv(GL_FRONT, GL_DIFFUSE,mat_d_ground2);
   glMaterialfv(GL_FRONT, GL_SHININESS,low_shininess);
    glPushMatrix();
   glColor3f(0.2,0.3,0.1);
   glTranslatef(0.0,-3.9,-8.0);
  glScalef(5,0,-5);
   glutSolidCube(1);
   glPopMatrix();
    glPushMatrix();
   glColor3f(0.2,0.3,0.1);
   glTranslatef(0.0,-3.8,-1.0);
   glRotatef(1,1.0,0.0,0.0);
  glScalef(5,0,-5);
   glutSolidCube(1);
   glPopMatrix();
    glPushMatrix();
   glColor3f(0.2,0.3,0.1);
   glTranslatef(-7.2,-3.9,-1.0);
   glRotatef(1,1.0,0.0,0.0);
  glScalef(5,0,-5);
   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();
   glColor3f(0.2,0.3,0.1);
   glTranslatef(7.2,-3.9,-1.0);
   glRotatef(1,1.0,0.0,0.0);
  glScalef(5,0,-5);
   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();
glColor3f(0.2,0.3,0.1);
   glTranslatef(-7.5,-3.9,-8.0);
   glRotatef(1,1.0,0.0,0.0);
  glScalef(5,0,-5);
   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();
  glColor3f(0.2,0.3,0.1);
   glTranslatef(7.5,-3.9,-8.0);
   glRotatef(1,1.0,0.0,0.0);
  glScalef(5,0,-5);
   glutSolidCube(1);
   glPopMatrix();
   glPopMatrix();

   //>>>>>>>>>>>>>>>>>>>>>dumbbell 1>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    glPushMatrix();
   glMaterialfv(GL_FRONT, GL_AMBIENT,mat_a_dumb);
   glMaterialfv(GL_FRONT, GL_DIFFUSE,mat_d_dumb);
   glMaterialfv(GL_FRONT, GL_SPECULAR,mat_s_dumb);
   glMaterialfv(GL_FRONT, GL_SHININESS,high_shininess);
    glTranslatef (-5.0,-1.5,-5.0);
     glPushMatrix();
   glScalef(.5,.5,.5);
   glColor3f(0.5,0.3,0.2);
   glTranslatef (0.0, -4.0,7.0);
   glScalef(2.0, 0.1, 0.2);
   glutSolidCube (1.0);
   glPopMatrix();
   glPushMatrix();
   glScalef(.5,.5,.5);
   glColor3f(0.5,0.3,0.2);
   glTranslatef (-1.0, -4.0,7.0);
   glScalef(1.0,1.0, 1.0);
   glutSolidSphere(0.6,20,20);
   glPopMatrix();
   glPushMatrix();
   glScalef(.5,.5,.5);
   glColor3f(0.5,0.3,0.2);
   glTranslatef (1.0, -4.0,7.0);
   glScalef(1.0,1.0, 1.0);
   glutSolidSphere(0.6,20,20);
   glPopMatrix();
   glPopMatrix();
   //>>>>>>>>>>>>>>>>>>>>>dumbbell 2>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
   glPushMatrix();
       glMaterialfv(GL_FRONT, GL_AMBIENT,mat_a_dumb);
   glMaterialfv(GL_FRONT, GL_DIFFUSE,mat_d_dumb);
   glMaterialfv(GL_FRONT, GL_SPECULAR,mat_s_dumb);
   glMaterialfv(GL_FRONT, GL_SHININESS,high_shininess);
   glRotatef(30,0.0,1.0,0.0);
    glTranslatef (6.0,-1.5,-5.0);
     glPushMatrix();
   glScalef(.5,.5,.5);
  glColor3f(0.0,0.3,0.2);
   glTranslatef (0.0, -4.0,7.0);
   glScalef(2.5, 0.1, 0.5);
   glutSolidCube (1.0);
   glPopMatrix();
   glPushMatrix();
   glScalef(.5,.5,.5);
   glColor3f(0.0,0.3,0.2);
   glTranslatef (-1.0, -4.0,7.0);
   glScalef(1.0,1.0, 1.0);
   glutSolidSphere(0.6,20,20);
   glPopMatrix();
   glPushMatrix();
   glScalef(.5,.5,.5);
   glColor3f(0.0,0.3,0.2);
   glTranslatef (1.0, -4.0,7.0);
   glScalef(1.0, 1.0, 1.0);
   glutSolidSphere(0.6,20,20);
   glPopMatrix();
   glPopMatrix();
}
void dum2 (void){
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT,mat_d_h_hand);
   glMaterialfv(GL_FRONT, GL_DIFFUSE,mat_d_h_hand);
   glMaterialfv(GL_FRONT, GL_SPECULAR,mat_s_dumb);
   glMaterialfv(GL_FRONT, GL_SHININESS,low_shininess);
    glScalef(.5,.5,.5);
   glColor3f(0.2,0.2,0.2);
   glTranslatef(1.0,-5.5,7.0);
  glScalef(0.5,3,0.5);
   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();
   glMaterialfv(GL_FRONT, GL_AMBIENT,mat_d_h_hand);
   glMaterialfv(GL_FRONT, GL_DIFFUSE,mat_d_h_hand);
   glMaterialfv(GL_FRONT, GL_SPECULAR,mat_s_dumb);
   glMaterialfv(GL_FRONT, GL_SHININESS,low_shininess);
    glScalef(.5,.5,.5);
   glColor3f(0.2,0.2,0.2);
   glTranslatef(-1.0,-5.5,7.0);
  glScalef(0.5,3,0.5);
   glutSolidCube(1);
   glPopMatrix();
}
void dumb1(void){
    glPushMatrix();
glTranslatef(0.0,up,dep);
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT,mat_a_dumb);
   glMaterialfv(GL_FRONT, GL_DIFFUSE,mat_d_dumb);
   glMaterialfv(GL_FRONT, GL_SPECULAR,mat_s_dumb);
   glMaterialfv(GL_FRONT, GL_SHININESS,high_shininess);
   glScalef(.5,.5,.5);
glColor3f(0.0,0.5,0.2);
   glTranslatef (0.0, -4.0,7.0);
   glScalef(9.0, 0.1, 0.2);
   glutSolidCube (1.0);
   glPopMatrix();
   glPushMatrix();
   glScalef(.5,.5,.5);
   glColor3f(0.0,0.5,0.2);
   glTranslatef (-4.0, -4.0,7.0);
   glScalef(1.0, 1.0, 1.0);
   glutSolidSphere(0.6,20,20);
   glPopMatrix();
   glPushMatrix();
   glScalef(.5,.5,.5);
   glColor3f(0.0,0.5,0.2);
   glTranslatef (4.0, -4.0,7.0);
   glScalef(1.0, 1.0, 1.0);
   glutSolidSphere(0.6,20,20);
   glPopMatrix();
   glPopMatrix();
}
//******************parts of robot******************************
void r_arm(void){
     glPushMatrix();
    glColor3f(0.2,0.2,1.0);
   glTranslatef (2.1,2.0,0.0);
   glRotatef ((GLfloat)shoulder1, 1.0, 0.0, 0.0);
   glTranslatef (0.0,-1.0, 0.0);
   glPushMatrix();
   glMaterialfv(GL_FRONT, GL_AMBIENT,no_mat);
   glMaterialfv(GL_FRONT, GL_DIFFUSE,mat_d_h_hand);
   glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
   glMaterialfv(GL_FRONT, GL_SHININESS,high_shininess);
   glScalef(0.5, 2.0, 1.0);
   glutSolidCube (1.0);
   glPopMatrix();
   glTranslatef (0.0, -1.0, 0.0);
   glRotatef ((GLfloat) elbow1, 1.0, 0.0, 0.0);
   glTranslatef (0.0,-1.0, 0.0);
   glPushMatrix();
   glMaterialfv(GL_FRONT, GL_AMBIENT,no_mat);
   glMaterialfv(GL_FRONT, GL_DIFFUSE,mat_d_l_hand);
   glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
   glMaterialfv(GL_FRONT, GL_SHININESS,high_shininess);
   glColor3f(0.6,0.6,1.0);
  glScalef (0.4, 2.0, 1.0);
   glutSolidCube (1.0);
   glPopMatrix();
    glTranslatef (0.0, -0.3, 0.0);
   glRotatef (kf, 0.0, 1.0, 0.0);
   glTranslatef (0.0, -0.9, 0.0);
   glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT,no_mat);
   glMaterialfv(GL_FRONT, GL_DIFFUSE,mat_d_h_hand);
   glMaterialfv(GL_FRONT, GL_SPECULAR,mat_s_body);
   glMaterialfv(GL_FRONT, GL_SHININESS,high_shininess);
  glScalef (1.5, 1.5 ,1.0);
   glColor3f(0.2,0.2,1.0);
   glutSolidCube(0.5);
   glPopMatrix();
   glTranslatef (-0.2, -0.2, 0.0);
   glRotatef (f1, 1.0, 0.0, 0.0);
   glTranslatef (0.0,-0.5, 0.0);
   glPushMatrix();
  glScalef (0.3, 2.5 ,0.5);
   glColor3f(0.6,0.6,1.0);
   glTranslatef (-0.3, 0.0, 0.0);
   glutSolidCube(0.4);
   glTranslatef(1.0, 0.0, 0.0);
   glutSolidCube(0.4);
   glTranslatef (1.2, 0.0, 0.0);
   glutSolidCube(0.4);
   glPopMatrix();
   glPopMatrix();
}
void l_arm(void){
      glPushMatrix();
  glColor3f(0.2,0.2,1.0);
   glTranslatef (-2.1,2.0,0.0);
   glRotatef ((GLfloat)shoulder, 1.0, 0.0, 0.0);
   glTranslatef (0.0,-1.0, 0.0);
   glPushMatrix();
   glMaterialfv(GL_FRONT, GL_AMBIENT,no_mat);
   glMaterialfv(GL_FRONT, GL_DIFFUSE,mat_d_h_hand);
   glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
   glMaterialfv(GL_FRONT, GL_SHININESS,high_shininess);
   glScalef(0.5, 2.0, 1.0);
   glutSolidCube (1.0);
   glPopMatrix();
   glTranslatef (0.0, -1.0, 0.0);
   glRotatef ((GLfloat) elbow, 1.0, 0.0, 0.0);
   glTranslatef (0.0,-1.0, 0.0);
   glPushMatrix();
      glMaterialfv(GL_FRONT, GL_AMBIENT,no_mat);
   glMaterialfv(GL_FRONT, GL_DIFFUSE,mat_d_l_hand);
   glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
   glMaterialfv(GL_FRONT, GL_SHININESS,high_shininess);
   glColor3f(0.6,0.6,1.0);
  glScalef (0.4, 2.0, 1.0);
   glutSolidCube (1.0);
   glPopMatrix();
    glTranslatef (0.0, -0.3, 0.0);
   glRotatef ((GLfloat) kf, 0.0, 1.0, 0.0);
   glTranslatef (0.0, -0.9, 0.0);
   glPushMatrix();
   glMaterialfv(GL_FRONT, GL_AMBIENT,no_mat);
   glMaterialfv(GL_FRONT, GL_DIFFUSE,mat_d_h_hand);
   glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
   glMaterialfv(GL_FRONT, GL_SHININESS,high_shininess);
  glScalef (1.5, 1.5 ,1.0);
    glColor3f(0.2,0.2,1.0);
   glutSolidCube(0.5);
   glPopMatrix();
    glTranslatef (-0.2, -0.2, 0.0);
   glRotatef ((GLfloat) f1, 1.0, 0.0, 0.0);
   glTranslatef (0.0,-0.5, 0.0);
   glPushMatrix();
  glScalef (0.3, 2.5 ,0.5);
   glColor3f(0.6,0.6,1.0);
   glTranslatef (-0.3, 0.0, 0.0);
   glutSolidCube(0.4);
   glTranslatef(1.0, 0.0, 0.0);
   glutSolidCube(0.4);
   glTranslatef (1.2, 0.0, 0.0);
   glutSolidCube(0.4);
   glPopMatrix();
   glPopMatrix();
}
void l_leg(void){
    glPushMatrix();
    glColor3f(0.2,0.2,1.0);
   glTranslatef (-1.0,-3.0,0.0);
   glRotatef ((GLfloat)l_thig, 1.0, 0.0, 0.0);
   glTranslatef (0.0,-1.0, 0.0);
   glPushMatrix();
   glMaterialfv(GL_FRONT, GL_AMBIENT,no_mat);
   glMaterialfv(GL_FRONT, GL_DIFFUSE,mat_d_h_hand);
   glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
   glMaterialfv(GL_FRONT, GL_SHININESS,high_shininess);
   glScalef(1.0, 2.0, 1.0);
   glutSolidCube (1.0);
   glPopMatrix();
   glTranslatef (0.0, -0.9, 0.0);
   glRotatef ((GLfloat) l_po, 1.0, 0.0, 0.0);
   glTranslatef (0.0,-1.0, 0.0);
   glPushMatrix();
      glMaterialfv(GL_FRONT, GL_AMBIENT,no_mat);
   glMaterialfv(GL_FRONT, GL_DIFFUSE,mat_d_l_hand);
   glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
   glMaterialfv(GL_FRONT, GL_SHININESS,high_shininess);
    glColor3f(0.6,0.6,1.0);
  glScalef (1.0, 2.2, 1.0);
   glutSolidCube (1.0);
   glPopMatrix();
    glTranslatef (0.0, -0.3, 0.0);
   glRotatef ((GLfloat) kf, 1.0, 0.0, 0.0);
   glTranslatef (0.0, -1.0, 0.0);
   glPushMatrix();
  glScalef (2.0, 1.0 ,4.0);
   glColor3f(0.2,0.2,1.0);
   glutSolidCube(0.5);
   glPopMatrix();
   glPopMatrix();
}
void r_leg(void){
   glPushMatrix();
    glColor3f(0.2,0.2,1.0);
   glTranslatef (1.0,-3.0,0.0);
   glRotatef ((GLfloat)r_thig, 1.0, 0.0, 0.0);
   glTranslatef (0.0,-1.0, 0.0);
   glPushMatrix();
   glMaterialfv(GL_FRONT, GL_AMBIENT,no_mat);
   glMaterialfv(GL_FRONT, GL_DIFFUSE,mat_d_h_hand);
   glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
   glMaterialfv(GL_FRONT, GL_SHININESS,high_shininess);
   glScalef(1.0, 2.0, 1.0);
   glutSolidCube (1.0);
   glPopMatrix();
   glTranslatef (0.0, -0.9, 0.0);
   glRotatef ((GLfloat) r_po, 1.0, 0.0, 0.0);
   glTranslatef (0.0,-1.0, 0.0);
   glPushMatrix();
   glMaterialfv(GL_FRONT, GL_AMBIENT,no_mat);
   glMaterialfv(GL_FRONT, GL_DIFFUSE,mat_d_l_hand);
   glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
   glMaterialfv(GL_FRONT, GL_SHININESS,low_shininess);
    glColor3f(0.6,0.6,1.0);
  glScalef (1.0, 2.2, 1.0);
   glutSolidCube (1.0);
   glPopMatrix();
    glTranslatef (0.0, -0.3, 0.0);
   glRotatef ((GLfloat) kf, 1.0, 0.0, 0.0);
   glTranslatef (0.0, -1.0, 0.0);
   glPushMatrix();
  glScalef (2.0, 1.0 ,4.0);
   glColor3f(0.2,0.2,1.0);
   glutSolidCube(0.5);
   glPopMatrix();
   glPopMatrix();
}
void head0_r(void){
   glPushMatrix();
   glMaterialfv(GL_FRONT, GL_AMBIENT,no_mat);
   glMaterialfv(GL_FRONT, GL_DIFFUSE,mat_d_head);
   glMaterialfv(GL_FRONT, GL_SPECULAR,mat_s_head1);
   glMaterialfv(GL_FRONT, GL_SHININESS,high_shininess);
    glScalef(0.8, 0.8,0.8);
     glTranslatef (0.0,1.0,0.0);
   glRotatef ((GLfloat)head1, 0.0, 1.0, 0.0);
   glTranslatef (0.0,-1.0, 0.0);
   glPushMatrix();
 glMaterialfv(GL_FRONT, GL_AMBIENT,no_mat);
   glMaterialfv(GL_FRONT, GL_DIFFUSE,mat_d_head);
   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_s_head1);
   glMaterialfv(GL_FRONT, GL_SHININESS,low_shininess);
   glTranslatef (0.0,3.7,0.0);
   glScalef(0.8, 0.7,0.7);
  glutSolidSphere(1.2,20,20);
   glPopMatrix();
   glPushMatrix();
   glColor3f(0.5,0.5,1.0);
   glTranslatef (0.0,4.5,0.0);
   glScalef(1.0,1.3,1.0);
  glutSolidSphere(1.2,20,20);
   glPopMatrix();
   glPushMatrix();
     glMaterialfv(GL_FRONT, GL_AMBIENT,no_mat);
   glMaterialfv(GL_FRONT, GL_DIFFUSE,mat_d_head1);
   glMaterialfv(GL_FRONT, GL_SPECULAR,mat_s_head1);
   glMaterialfv(GL_FRONT, GL_SHININESS,low_shininess);
   glTranslatef (0.0,4.5,0.1);
   glScalef(1.0,0.5,1.0);
  glutSolidSphere(1.2,20,20);
   glPopMatrix();
   glPopMatrix();
}
void sh_r(void){
   glPushMatrix();
   glMaterialfv(GL_FRONT, GL_AMBIENT,no_mat);
   glMaterialfv(GL_FRONT, GL_DIFFUSE,mat_d_shoul);
   glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
   glMaterialfv(GL_FRONT, GL_SHININESS,low_shininess);
   glScalef(.3,.3,.3);
   glTranslatef(5.5,7.0,0.0);
   glutSolidSphere(2.5,20,20);
   glPopMatrix();
}
void sh_l(void){
   glPushMatrix();
   glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_d_shoul);
   glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
   glMaterialfv(GL_FRONT, GL_SHININESS,low_shininess);
   glScalef(.3,.3,.3);
   glColor3f(0.6,0.6,1.0);
   glTranslatef(-5.5,7.0,0.0);
   glutSolidSphere(2.5,20,20);
   glPopMatrix();
}
void middle(void){
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT,no_mat);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_d_middl);
   glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
   glMaterialfv(GL_FRONT, GL_SHININESS,high_shininess);
  glColor3f(0.6,0.6,1.0);
   glTranslatef (0.0, -3.0,0.0);
   glScalef(3.4, 0.8, 2.0);
   glutSolidCube (1.0);
   glPopMatrix();
}
void bodyf(void){
     glTranslatef (0.0,-2.0,0.0);
   glRotatef ((GLfloat)body, 1.0, 0.0, 0.0);
   glTranslatef (0.0,2.0, 0.0);
     glPushMatrix();
   glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_d_body);
   glMaterialfv(GL_FRONT, GL_SPECULAR,mat_s_body);
   glMaterialfv(GL_FRONT, GL_SHININESS,high_shininess);
   glTranslatef (0.0,-0.2,0.0);
   glScalef(3.0, 5.0,2.0);
   glutSolidCube (1.0);
   glPopMatrix();
}
//move1......................................................................................................
void run2 (){
           head1=180;
      if (move1<=1.0&&move1>=-8.0){
           if (i==0){
                 if(r_thig<=-20.0)
             {
                 i=1;
             }
            r_thig= (r_thig - 0.2);
            l_thig=(l_thig +0.2);
            if (r_po<=0&&r_po>=-30)
                    r_po= (r_po-0.6);
             if (l_po<=0&&l_po>=-31)
                      l_po= (l_po+0.6);
            if (elbow1>=0&&elbow1<=21)
                     elbow1=elbow1-1;
             if(elbow>=-1&&elbow<=20)
                       elbow=elbow+1;
             shoulder=(shoulder+0.1);
             shoulder1=(shoulder1-0.1);
             move1= (move1 - 0.003);

      }else if (i==1){
          if(l_thig<=-20.0)
             {
                 i=0;
             }
             if (r_po<=-1&&r_po>=-31)
                    r_po= (r_po+0.6);
             if (l_po<=1&&l_po>=-30)
                      l_po= (l_po-0.6);
             if (elbow1>=-1&&elbow1<=20)
                     elbow1=elbow1+1;
             if(elbow>=0&&elbow<=21)
                       elbow=elbow-1;
            r_thig= (r_thig + 0.2);
             l_thig=(l_thig -0.2);
             shoulder=(shoulder-0.1);
             shoulder1=(shoulder1+0.1);
             move1= (move1 - 0.003);
      }
      }
glutPostRedisplay();
}
void run1 (){
       head1=0;
      if (move1<=0.6&&move1>=-9.0){
           if (i==0){
                 if(r_thig<=-25.0)
             {
                 i=1;
             }
            r_thig= (r_thig - 0.2);
            l_thig=(l_thig +0.2);
           if (r_po>=-1&&r_po<=30)
                   r_po= (r_po+0.6);
           if (l_po>=0&&l_po<=31)
                    l_po= (l_po-0.6);
            if (elbow1<=1&&elbow1>=-20)
                elbow1=elbow1-1;
             if(elbow<=0&&elbow>=-21)
             elbow=elbow+1;
             shoulder=(shoulder+0.1);
             shoulder1=(shoulder1-0.1);
             move1= (move1 + 0.003);

      }else if (i==1){
          if(l_thig<=-25.0)
             {
                 i=0;
             }
            r_thig= (r_thig + 0.2);
             l_thig=(l_thig -0.2);
             if (r_po>=0&&r_po<=31)
           r_po= (r_po-0.6);
           if (l_po>=-1&&l_po<=30)
           l_po= (l_po+0.6);
           if (elbow1<=0&&elbow1>=-21)
                elbow1=elbow1+1;
             if(elbow<=1&&elbow>=-20)
             elbow=elbow-1;
             shoulder=(shoulder-0.1);
             shoulder1=(shoulder1+0.1);
             move1= (move1 + 0.003);
      }
      }
glutPostRedisplay();
}
//MOVE2...................................................................................................
void sen_play1(void){
   if (move1<=0.0&&move1>=-10.0){
           if (r_thig==0&&l_thig==0){
            r_thig= (r_thig - 20);
             l_thig=(l_thig +20);
             r_po= (r_po+50);
             shoulder=(shoulder+25);
            shoulder1=(shoulder1-50);
             move1= (move1 + 0.5);
           }
           else if (r_thig==-20&&l_thig==20){
                r_thig= (r_thig +40);
                l_thig=(l_thig -40);
                r_po= (r_po-25);
                l_po= (l_po+25);
               shoulder=(shoulder-50);
               shoulder1=(shoulder1+75);
                 move1= (move1 + 0.5);
           }else if (r_thig==20 && l_thig==-20){
            r_thig=0;
                 l_thig=0;
                 r_po=0;
                 l_po=0;
                 shoulder=0;
                 shoulder1=0;
           }
           }else{
               shoulder=0;
                 shoulder1=0;
           }
glutPostRedisplay();
}
void sen_play2(void){
    if (move1<=1.0&move1>=-1)
    {
        if (body <=80&&(shoulder<=0&&shoulder>=-94)){
        body=body+5;
        shoulder=shoulder-6;
        shoulder1=shoulder1-6;
        f1=f1-6;
        }
        else if (body<=80&& body>=75)
        {
            elbow=elbow-5;
            elbow1=elbow1-5;
            f1=f1-10;
            body=body-5;
            //shoulder=shoulder+2;
        }else if (body==70&&f1>=-140)
            f1=f1-5;


    }

}
void sen_play3(void){
     if (move1<=1.0&move1>=-1){
    if (up>=0&&up<=4.9)
    {
        if (body<=70&&body>=0)
        {
            body=body-4;
            up=up+0.2;
            dep=dep-0.07;
        }
        else if(body>=-5&&body<=0){
            shoulder=shoulder-5;
            shoulder1=shoulder1-5;
            glutPostRedisplay();
            up=up+0.12;
            dep=dep-0.1;


        }else if (shoulder<=-70 &&shoulder>=-90)
        {
            shoulder=shoulder-2;
             dep=dep-0.2;

        }
    }
     }
glutPostRedisplay();
}
void sen_play4(){
     if (move1<=1.0&move1>=-1){
 if (up>=-1.9&&up<=5)
    {
         if((body>=-5&&body<=0)&&shoulder1<=0&&shoulder!=0){
            shoulder=shoulder+6;
            shoulder1=shoulder1+6;
                f1=f1+5;
            up=up-0.12;
            dep=dep+0.1;
            }else
            up=up-0.12;
            dep=dep+0.05;


glutPostRedisplay();
}
     }
}
void rest1(void){
    shoulder = 0;elbow = 0 ;kf=0 ;f1=0; shoulder1 = 0 ;r_thig=0;l_thig=0;body=0;
    move1=-8;up=0.0 ;dep=0.0;
    r_po=0;l_po=0;head1=0;
    elbow1 = 0 ;

}
void display(void){
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glPushMatrix();

      ground();
     ground2();
      l_wall();
      r_wall();
      roof();
      b_wall();
      front_wall();
      l_wall();
      dum2();
      dumb1();
glTranslatef(0.0,0.0,move1);
glScalef(.5,.5,.5);
     middle();
     l_leg();
     r_leg();
     bodyf();
     head0_r();
     sh_l();
     sh_r();
     l_arm();
     r_arm();
glPopMatrix();
   glutSwapBuffers();
}
void reshape (int w, int h){
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(70, (GLfloat) w/(GLfloat) h,2.0,20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
  gluLookAt(0.0, 0.0,9.0, 0.0, 0.0,0.0, 0.0, 1.0, 0.0);
}
void keyboard (unsigned char key, int x, int y){
   switch (key) {
           case 'W':   /* RUN  1 */
           sen_play1();
         break;
          case 'S':  //CATCH THE DUMBL 2
          sen_play2();
         glutPostRedisplay();
         break;
      case 'D':   // UP 3
          sen_play3();
         break;
           break;
      case 'A': //DOWN 4
          sen_play4();
         break;
         case 'R'://REST 5
              glutIdleFunc(NULL);
          rest1();
           glutPostRedisplay();

         break;
           case 27:
            exit(0);

         break;
      default:
         break;
   }
}
void menu (int value){
    if (value==1){
        r_thig=0;
        l_thig=0;
        l_po=0;
         r_po=0;
         elbow1 = 0 ;
         elbow = 0;
           glutIdleFunc(run1);
           shoulder1=0;
           shoulder=0;
           glutPostRedisplay();

    }
     if (value==2){
            r_thig=0;
         l_thig=0;
         l_po=0;
         r_po=0;
         elbow1 = 0 ;
         elbow = 0;
          glutIdleFunc(run2);
         glutPostRedisplay();

     }
     if (value==3){
                glutIdleFunc(NULL);
          rest1();
           glutPostRedisplay();

     }
     if (value==4){

           glutPostRedisplay();
           gluLookAt(0.0, 0.0,0.0,1.0,0.0,0.0, 0.0, 1.0, 0.0);

     }

}
int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE| GLUT_RGB| GLUT_DEPTH);
   glEnable(GL_DEPTH_TEST);
   glutInitWindowSize (1700,650);
   glutInitWindowPosition (0, 0);
   glutCreateWindow ("ROBOT");
   init();
//>>>>>>>>>>>>>menu>>>>>>>>>>>>>>>>>>>>>
glutCreateMenu(menu);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutAddMenuEntry("Move",1);
	glutAddMenuEntry("Go Back",2);
	glutAddMenuEntry("Rest",3);
	glutAddMenuEntry("Move the Camera",4);
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}
