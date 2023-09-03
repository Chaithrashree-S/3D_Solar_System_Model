#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include "tgaload.c"

GLUquadricObj* sphere;
GLuint texture_id[12];
GLuint moon_id[1];
image_t temp_image;

int revspeed = 5.5, menu_id, submenu_id, menu_value = 15;
bool paused = false;
static float Xvalue = 0.0, Yvalue = 0.0, Angle = 0.0, worldX = 0.0, worldY = 12.0, worldZ = 8.0;
int MoveMerc = 0, MoveVenus = 0, MoveEarth = 0, MoveMoon = 0, MoveMars = 0, MoveJup =0, MoveSaturn = 0, MoveUr = 0, MoveNep = 0, MovePlu = 0;
static double x1[720][2];//Mercury
static double x2[720][2];//Venus
static double x3[720][2];//Earth
static double x4[720][2];//Mars
static double x5[720][2];//Jupiter
static double x6[720][2];//Saturn
static double x7[720][2];//Uranus
static double x8[720][2];//Neptune
static double x9[720][2];//Pluto
static double x10[360][2];//Moon

void generateOrbit (void)
{
    for (int i = 0; i <= 360; i++)
    {//Mercury
        x1[i][0] = sin(i*3.1416/180)*2.4;
        x1[i][1] = cos(i*3.1416/180)*2.4;
    //Venus
        x2[i][0] = sin(i*3.1416/180)*3.2;
        x2[i][1] = cos(i*3.1416/180)*3.2;
    //Earth
        x3[i][0] = sin(i*3.1416/180)*4.2;
        x3[i][1] = cos(i*3.1416/180)*4.2;
    //Moon
        x10[i][0] = sin(i*3.1416/180)*0.6;
        x10[i][1] = cos(i*3.1416/180)*0.6;
    //Mars
        x4[i][0] = sin(i*3.1416/180)*5.5;
        x4[i][1] = cos(i*3.1416/180)*5.5;
    //Jupiter
        x5[i][0] = sin(i*3.1416/180)*7;
        x5[i][1] = cos(i*3.1416/180)*7;
    //Saturn
        x6[i][0] = sin(i*3.1416/180)*8.8;
        x6[i][1] = cos(i*3.1416/180)*8.8;
    //Uranus
        x7[i][0] = sin(i*3.1416/180)*10.5;
        x7[i][1] = cos(i*3.1416/180)*10.5;
    //Neptune
        x8[i][0] = sin(i*3.1416/180)*12;
        x8[i][1] = cos(i*3.1416/180)*12;
    //Pluto
        x9[i][0] = sin(i*3.1416/180)*13.2;
        x9[i][1] = cos(i*3.1416/180)*13.2;
    }
}

void planets (void)
{//SUN
     glPushMatrix();
     gluLookAt (worldX, worldY, worldZ, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);//(0.0, 10.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
     glTranslatef(Xvalue, 0.0, Yvalue);
     glColor3f(1.0,1.0,1.0);
     glBegin(GL_POINTS);
     for (int i=0; i <= 360; i++)
     {
        glVertex3f(sin(i*3.1416/180)*2.4, cos(i*3.1416/180)*2.4, 0 );
        glVertex3f(sin(i*3.1416/180)*3.2, cos(i*3.1416/180)*3.2, 0 );
        glVertex3f(sin(i*3.1416/180)*4.2, cos(i*3.1416/180)*4.2, 0 );
        glVertex3f(sin(i*3.1416/180)*5.5, cos(i*3.1416/180)*5.5, 0 );
        glVertex3f(sin(i*3.1416/180)*7, cos(i*3.1416/180)*7, 0 );
        glVertex3f(sin(i*3.1416/180)*8.8, cos(i*3.1416/180)*8.8, 0 );
        glVertex3f(sin(i*3.1416/180)*10.5, cos(i*3.1416/180)*10.5, 0 );
        glVertex3f(sin(i*3.1416/180)*12, cos(i*3.1416/180)*12, 0 );
        glVertex3f(sin(i*3.1416/180)*13.2, cos(i*3.1416/180)*13.2, 0 );
     }
     glEnd();
     glRotatef(Angle/25, 0.0, 0.0, 1.0);
     glBindTexture ( GL_TEXTURE_2D, texture_id[0] );
     gluSphere(sphere,2,100,100);
     glPopMatrix();
//Mercury
     glPushMatrix();
     gluLookAt (worldX, worldY, worldZ, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
     if (MoveMerc==360)
        MoveMerc = 0;
     glTranslatef(x1[MoveMerc][1], x1[MoveMerc][0], 0.0);
     glRotatef(Angle, 0.0, 0.0, 1.0);
     glBindTexture ( GL_TEXTURE_2D, texture_id[1] );
     gluSphere(sphere, 0.25, 100, 100);
     glPopMatrix();
//Venus
     glPushMatrix();
     gluLookAt (worldX, worldY, worldZ, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
     if (MoveVenus == 720)
        MoveVenus = 0;
     glTranslatef(x2[MoveVenus/2][1], x2[MoveVenus/2][0], 0.0);
     glRotatef(Angle, 0.0, 0.0, -1.0);
     glBindTexture ( GL_TEXTURE_2D, texture_id[2] );
     gluSphere(sphere, 0.28, 100, 100);
     glPopMatrix();
//EARTH
     glPushMatrix();
     gluLookAt (worldX, worldY, worldZ, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
     if(MoveEarth==1080)
        MoveEarth = 0;
     glTranslatef(x3[MoveEarth/3][1], x3[MoveEarth/3][0], 0.0);
     glRotatef(Angle*2, 0.1, 0.3, 0.7);
     glBindTexture(GL_TEXTURE_2D, texture_id[3]);
     gluSphere(sphere, 0.3, 100, 100);
//MOON
     if (MoveMoon == 360)
        MoveMoon = 0;
     glTranslatef(x10[MoveMoon][1], x10[MoveMoon][0], 0.0); //glTranslated(-0.3,-0.3,0.3);
     glBindTexture ( GL_TEXTURE_2D, moon_id[0] );
     gluSphere (sphere, 0.1, 100, 100);
     glPopMatrix();
//Mars
     glPushMatrix();
     gluLookAt (worldX, worldY, worldZ, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
     if (MoveMars == 1440)
        MoveMars = 0;
     glTranslatef(x4[MoveMars/4][1], x4[MoveMars/4][0], 0.0);
     glRotatef(Angle, 0.0, 0.0, 1.0);
     glBindTexture ( GL_TEXTURE_2D, texture_id[4] );
     gluSphere(sphere, 0.28, 100, 100);
     glPopMatrix();
//Jupiter
     glPushMatrix();
     gluLookAt (worldX, worldY, worldZ, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
     if (MoveJup == 1800)
        MoveJup = 0;
     glTranslatef(x5[MoveJup/5][1], x5[MoveJup/5][0], 0.0);
     glRotatef(Angle, 0.0, 0.0, 0.1);
     glBindTexture ( GL_TEXTURE_2D, texture_id[5] );
     gluSphere(sphere, 0.7, 100, 100);
     glPopMatrix();
//SATURN
     glPushMatrix();
     gluLookAt (worldX, worldY, worldZ, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
     if(MoveSaturn==2160)
        MoveSaturn = 0;
     glTranslatef(x6[MoveSaturn/6][1], x6[MoveSaturn/6][0], 0.0);
     glRotatef(Angle, 0.0, 0.0, 0.1);
     glBindTexture ( GL_TEXTURE_2D, texture_id[6] );
     gluSphere (sphere, 0.50, 100, 100);
     int i = 0;
     glBindTexture(GL_TEXTURE_2D, texture_id[10]);
     glBegin(GL_QUAD_STRIP);//Saturn Rings
     for(i=0; i <= 360; i++)
     {
        glVertex3f(sin(i*3.1416/180)*0.58, cos(i*3.1416/180)*0.58, 0 );
        glVertex3f(sin(i*3.1416/180)*0.61, cos(i*3.1416/180)*0.61, 0 );
     }
     for (i = 0; i <= 360; i++)
     {
        glVertex3f(sin(i*3.1416/180)*0.65, cos(i*3.1416/180)*0.65, 0 );
        glVertex3f(sin(i*3.1416/180)*0.72, cos(i*3.1416/180)*0.72, 0 );
     }
     glEnd();
     glRotatef(Angle, 0.5, 0.2, 1.5);
     glPopMatrix();
//Uranus
     glPushMatrix();
     gluLookAt (worldX, worldY, worldZ, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
     if (MoveUr == 2520)
        MoveUr = 0;
     glTranslatef(x7[(MoveUr/7)][1], x7[(MoveUr/7)][0], 0.0);
     glRotatef(Angle, 0.0, 0.0, -0.1);
     glBindTexture ( GL_TEXTURE_2D, texture_id[7] );
     gluSphere(sphere, 0.4, 100, 100);
     glBindTexture(GL_TEXTURE_2D, texture_id[11]);
     glBegin(GL_QUAD_STRIP);
     for(int i=0; i <= 360; i++)
     {
        glVertex3f(sin(i*3.1416/180)*0.58, cos(i*3.1416/180)*0.58, 0 );
        glVertex3f(sin(i*3.1416/180)*0.61, cos(i*3.1416/180)*0.61, 0 );
     }
     glEnd();
     glPopMatrix();
//Neptune
     glPushMatrix();
     gluLookAt (worldX, worldY, worldZ, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
     if (MoveNep == 2880)
        MoveNep = 0;
     glTranslatef(x8[MoveNep/8][1], x8[MoveNep/8][0], 0.0);
     glRotatef(Angle, 0.0, 0.0, 0.1);
     glBindTexture ( GL_TEXTURE_2D, texture_id[8] );
     gluSphere(sphere, 0.33, 100, 100);
     glPopMatrix();
//Pluto
     glPushMatrix();
     gluLookAt (worldX, worldY, worldZ, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
     if (MovePlu == 3240)
        MovePlu = 0;
     glTranslatef(x9[MovePlu/9][1], x9[MovePlu/9][0], 0.0);
     glRotatef(Angle, 0.0, 0.0, 0.1);
     glBindTexture ( GL_TEXTURE_2D, texture_id[9] );
     gluSphere(sphere, 0.2, 100, 100);
     glPopMatrix();
}

void myDisplay (void)
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f (0, 0, 0);
    glLoadIdentity();
    if (menu_value != 0 && menu_value != 15)
    {
        glPushMatrix();
        gluLookAt (worldX, worldY, worldZ, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
        glTranslated(Xvalue, 0.0, Yvalue);
        glRotatef(Angle, 0.0, 0.0, 1.0);
        glDisable(GL_LIGHTING);
        glBindTexture(GL_TEXTURE_2D,texture_id[menu_value]);
        gluSphere(sphere,4,100,100);
        glBegin(GL_QUAD_STRIP);
        if (menu_value == 6 || menu_value == 7)
        {
            if(menu_value == 6)
                glBindTexture(GL_TEXTURE_2D, texture_id[10]);
            else glBindTexture(GL_TEXTURE_2D, texture_id[11]);
            for(int i=0; i <= 360; i++)
             {
                glVertex3f(sin(i*3.1416/180)*4.38, cos(i*3.1416/180)*4.38, 0 );
                glVertex3f(sin(i*3.1416/180)*5.11, cos(i*3.1416/180)*5.11, 0 );
             }
        }
        if (menu_value == 6)
        {
             for (int i = 0; i <= 360; i++)
             {
                glVertex3f(sin(i*3.1416/180)*5.5, cos(i*3.1416/180)*5.5, 0 );
                glVertex3f(sin(i*3.1416/180)*5.92, cos(i*3.1416/180)*5.92, 0 );
             }
        }
        glEnd();
        glEnable(GL_LIGHTING);
        glPopMatrix();
    }
    else if (menu_value == 15)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        planets();
    }
     glutSwapBuffers();
}

void keys (unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'q': exit(0);              break;
        case 'y': worldY -= 1.0f;       break;
        case 'Y': worldY += 1.0f;       break;
        case 'z': worldZ -= 1.0f;       break;
        case 'Z': worldZ += 1.0f;       break;
        case 'x': worldX -= 1.0f;       break;
        case 'X': worldX += 1.0f;       break;
        case ' ': if (!paused) Sleep(2000);    break;
        case '+': revspeed=5.5;         break;
        case '-': revspeed-=0.5;        break;
        case 'r': menu_value = 15; MoveMerc = MoveVenus = MoveEarth = MoveMoon = 0;
                    MoveMars = MoveJup = MoveSaturn = MoveUr = 0;
                    MoveNep = MovePlu = 0;      break;
	}
	glutPostRedisplay();
}

void reshape (int w, int h)
{
     glViewport (0, 0, (GLsizei) w, (GLsizei) h);
     glMatrixMode (GL_PROJECTION);
     glLoadIdentity ();
     glFrustum (-2.0, 2.0, -2.0, 2.0, 1.5, 30.0);
     glMatrixMode (GL_MODELVIEW);
     glLoadIdentity ();
}

void animation (int value)
{
    Angle += 7.0;
    MoveMerc += revspeed;   //MoveMerc += 7;
    MoveVenus += revspeed;  //MoveVenus += 6.5;
    MoveEarth += revspeed;  //MoveEarth +=6;
    MoveMoon += revspeed;
    MoveMars += revspeed;   //MoveMars += 5.0;
    MoveJup += revspeed;    //MoveJup += 4.6;
    MoveSaturn += revspeed; //MoveSaturn += 3.9;
    MoveUr += revspeed;     //MoveUr += 2.9;
    MoveNep += revspeed;    //MoveNep += 2.1;
    MovePlu += revspeed;    //MovePlu += 1;
    glutPostRedisplay();
    glutTimerFunc(30, animation, 0);
}

void menu (int num)
{
    if(num == 0)
        exit(0);
    else
        menu_value = num;
    glutPostRedisplay();
}

void CreateMenuItem (void)
{
    submenu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Mercury",1);
    glutAddMenuEntry("Venus",2);
    glutAddMenuEntry("Earth",3);
    glutAddMenuEntry("Mars",4);
    glutAddMenuEntry("Jupiter",5);
    glutAddMenuEntry("Saturn",6);
    glutAddMenuEntry("Uranus",7);
    glutAddMenuEntry("Neptune",8);
    glutAddMenuEntry("Pluto",9);
    //glutAddMenuEntry("All",15);
    menu_id = glutCreateMenu(menu);
    glutAddSubMenu("Display Planet",submenu_id);
    glutAddMenuEntry("Quit", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void myInit (void)
{
    generateOrbit();
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    // Create light components
    GLfloat ambientLight[] = { 1.5f, 1.5f, 1.5f, 1.0f };
    GLfloat diffuseLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat specularLight[] = { 0.5f, 0.5f, 0.5f, 1.0f };
    GLfloat position[] = {0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat shininess[] = { 1.0f };
    GLfloat intensity[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    //glMaterialfv(GL_BACK, GL_AMBIENT, ambientLight);
    // Assign created components to GL_LIGHT0
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, intensity);
    glLightfv(GL_LIGHT0, GL_SHININESS, shininess);
    glShadeModel(GL_SMOOTH);

    glEnable ( GL_TEXTURE_2D );
    glGenTextures (12, texture_id);
    glBindTexture ( GL_TEXTURE_2D, texture_id[0] );
    tgaLoad ( "C:/Chaithra/Solar_System/bin/Debug/Sun.tga", &temp_image, TGA_FREE | TGA_LOW_QUALITY );
    sphere = gluNewQuadric();
    gluQuadricNormals( sphere, GLU_SMOOTH);
    gluQuadricTexture( sphere, GL_TRUE);

    glBindTexture ( GL_TEXTURE_2D, texture_id[1] );
    tgaLoad ( "C:/Chaithra/Solar_System/bin/Debug/Mercury.tga", &temp_image, TGA_FREE | TGA_LOW_QUALITY );

    glBindTexture ( GL_TEXTURE_2D, texture_id[2] );
    tgaLoad ( "C:/Chaithra/Solar_System/bin/Debug/Venus.tga", &temp_image, TGA_FREE | TGA_LOW_QUALITY );

    glBindTexture ( GL_TEXTURE_2D, texture_id[3] );
    tgaLoad ( "C:/Chaithra/Solar_System/bin/Debug/Earth.tga", &temp_image, TGA_FREE | TGA_LOW_QUALITY );

    //glGenTextures(1,moon_id);
    //glBindTexture ( GL_TEXTURE_2D, moon_id[0] );
    //tgaLoad ( "C:/Chaithra/Solar_System/bin/Debug/Moon.tga", &temp_image, TGA_FREE | TGA_LOW_QUALITY );

    glBindTexture ( GL_TEXTURE_2D, texture_id[4] );
    tgaLoad ( "C:/Chaithra/Solar_System/bin/Debug/Mars.tga", &temp_image, TGA_FREE | TGA_LOW_QUALITY );

    glBindTexture ( GL_TEXTURE_2D, texture_id[5] );
    tgaLoad ( "C:/Chaithra/Solar_System/bin/Debug/Jupiter.tga", &temp_image, TGA_FREE | TGA_LOW_QUALITY );

    glBindTexture ( GL_TEXTURE_2D, texture_id[6] );
    tgaLoad ( "C:/Chaithra/Solar_System/bin/Debug/Saturn.tga", &temp_image, TGA_FREE | TGA_LOW_QUALITY );

    glBindTexture ( GL_TEXTURE_2D, texture_id[7] );
    tgaLoad ( "C:/Chaithra/Solar_System/bin/Debug/Uranus.tga", &temp_image, TGA_FREE | TGA_LOW_QUALITY );

    glBindTexture ( GL_TEXTURE_2D, texture_id[8] );
    tgaLoad ( "C:/Chaithra/Solar_System/bin/Debug/Neptune.tga", &temp_image, TGA_FREE | TGA_LOW_QUALITY );

    glBindTexture ( GL_TEXTURE_2D, texture_id[9] );
    tgaLoad ( "C:/Chaithra/Solar_System/bin/Debug/Pluto.tga", &temp_image, TGA_FREE | TGA_LOW_QUALITY );

    glBindTexture ( GL_TEXTURE_2D, texture_id[10] );
    tgaLoad ( "C:/Chaithra/Solar_System/bin/Debug/SaturnRings.tga", &temp_image, TGA_FREE | TGA_LOW_QUALITY );

    glBindTexture ( GL_TEXTURE_2D, texture_id[11] );
    tgaLoad ( "C:/Chaithra/Solar_System/bin/Debug/UranusRings.tga", &temp_image, TGA_FREE | TGA_LOW_QUALITY );
}

int main(int argc, char **argv)
{
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
     glutInitWindowSize(1800, 800);
     glutInitWindowPosition(100, 100);
     glutCreateWindow("Three Dimensional Model Of Solar System");
     myInit();
     CreateMenuItem();
     glutDisplayFunc(myDisplay);
     glutReshapeFunc(reshape);
     glutKeyboardFunc(keys);
     glutTimerFunc(0, animation, 0);
     glutMainLoop();
}
