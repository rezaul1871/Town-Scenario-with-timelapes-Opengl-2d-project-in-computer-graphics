#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>
float p=-0.005;
float s=-0.005;
float u=-0.005;
float m=-0.005;
float n=-0.005;
float o=-0.005;
void circle(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy)//radius_x,radius_y,certre_position_x,centre_position_y
{

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);

    for(int i=0; i<100; i++)

    {
        float angle = 4.0f * 3.1416f * i/100;

        float x = rx * cosf(angle);
        float y = ry * sinf(angle);

        glVertex2f((x+cx),(y+cy));
    }
    glEnd();

}

void all()
{
    glClear (GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);

//top green color part on the building backgound
    glColor3f (0.204,0.51,0.204);
    glVertex3f(-0.05f, 0.0f, 0.0f);
    glVertex3f(-0.05f, 0.20f, 0.0f);
    glVertex3f(0.85f, 0.20f, 0.0f);
    glVertex3f(0.85f, 0.00f, 0.0f);

//Sky part
    glColor3f (0.8, 0.8, 0.8);
    glVertex3f(-0.05f, 0.20f, 0.0f);
    glVertex3f(-0.05f, 0.40f, 0.0f);
    glVertex3f(0.85f, 0.40f, 0.0f);
    glVertex3f(0.85f, 0.20f, 0.0f);
    glEnd();
//cloud and sun
    //loop for sun
    if(s<=0.95)
        s=s+.00002;
    else
        s=-0.00000005;

    if(u<=0.40)
        u=u+.000002;
    else
        u=-0.00000005;
    glutPostRedisplay();

    glColor3f(1.0, 1.0, 0.0);
    circle(0.05,0.05,s-0.05, u+0.25);
    //1st sky cloud motion
        if(m<=2.0)
        m=m+.000035;
    else
        m=-0.0000005;
    //3rd sky  cloud motion
    if(n<=2.0)
        n=n+.00015;
    else
        n=-0.0000003;

    //2nd sky cloud motion
    if(o<=2.0)
        o=o+.000005;
    else
        o=-0.0000005;
    //sky cloud 1
    glColor3f(1.0, 1.0, 1.0);
    circle(0.03,0.03,m-0.04, 0.28);
    circle(0.03,0.03,m-0.055, 0.29);
    circle(0.03,0.03,m-0.07, 0.295);
    circle(0.03,0.03,m-.02, 0.29);
    circle(0.03,0.03,m-0.05, 0.31);

    //sky cloud 2
    circle(0.03,0.03,o-.44, 0.35);
    circle(0.03,0.03,o-0.455, 0.36);
    circle(0.03,0.03,o-0.47, 0.365);
    circle(0.03,0.03,o-.42, 0.36);
    circle(0.03,0.03,o-0.45, 0.38);
    //sky cloud 3
    circle(0.03,0.03,n-0.74, 0.31);
    circle(0.03,0.03,n-0.755, 0.32);
    circle(0.03,0.03,n-0.77, 0.325);
    circle(0.03,0.03,n-0.72, 0.32);
    circle(0.03,0.03,n-0.75, 0.354);

//first building
    glBegin(GL_QUADS);
    glColor3f (0.196078, 0.803922, 0.196078);
    glVertex3f(0.05f, 0.05f, 0.0f);
    glVertex3f(0.15f, 0.05f, 0.0f);
    glVertex3f(0.15f, 0.26f, 0.0f);
    glVertex3f(0.05f, 0.25f, 0.0f);
//first building side
    glColor3f (0.196078, 0.803922, 0.196078);
    glVertex3f(0.05f, 0.05f, 0.0f);
    glVertex3f(0.05f, 0.25f, 0.0f);
    glVertex3f(0.04f, 0.23f, 0.0f);
    glVertex3f(0.04f, 0.06f, 0.0f);

    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.07f, 0.08f, 0.0f);
    glVertex3f(0.13f, 0.08f, 0.0f);
    glVertex3f(0.13f, 0.12f, 0.0f);
    glVertex3f(0.07f, 0.12f, 0.0f);

    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.07f, 0.15f, 0.0f);
    glVertex3f(0.13f, 0.15f, 0.0f);
    glVertex3f(0.13f, 0.19f, 0.0f);
    glVertex3f(0.07f, 0.19f, 0.0f);

    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.07f, 0.21f, 0.0f);
    glVertex3f(0.13f, 0.21f, 0.0f);
    glVertex3f(0.13f, 0.24f, 0.0f);
    glVertex3f(0.07f, 0.24f, 0.0f);

//2nd building
    glColor3f (0.5, 0.0, 0.0);
    glVertex3f(0.15f, 0.05f, 0.0f);
    glVertex3f(0.15f, 0.30f, 0.0f);
    glVertex3f(0.25f, 0.30f, 0.0f);
    glVertex3f(0.25f, 0.05f, 0.0f);

// 2nd building windows by floor sequence
//2nd building 1st floor
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.16f, 0.07f, 0.0f);
    glVertex3f(0.19f, 0.07f, 0.0f);
    glVertex3f(0.19f, 0.09f, 0.0f);
    glVertex3f(0.16f, 0.09f, 0.0f);

    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.21f, 0.07f, 0.0f);
    glVertex3f(0.24f, 0.07f, 0.0f);
    glVertex3f(0.24f, 0.09f, 0.0f);
    glVertex3f(0.21f, 0.09f, 0.0f);

//2nd building 2nd floor.

    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.16f, 0.12f, 0.0f);
    glVertex3f(0.19f, 0.12f, 0.0f);
    glVertex3f(0.19f, 0.14f, 0.0f);
    glVertex3f(0.16f, 0.14f, 0.0f);

    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.21f, 0.12f, 0.0f);
    glVertex3f(0.24f, 0.12f, 0.0f);
    glVertex3f(0.24f, 0.14f, 0.0f);
    glVertex3f(0.21f, 0.14f, 0.0f);
//2nd building 3rd floor.
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.16f, 0.17f, 0.0f);
    glVertex3f(0.19f, 0.17f, 0.0f);
    glVertex3f(0.19f, 0.19f, 0.0f);
    glVertex3f(0.16f, 0.19f, 0.0f);

    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.21f, 0.17f, 0.0f);
    glVertex3f(0.24f, 0.17f, 0.0f);
    glVertex3f(0.24f, 0.19f, 0.0f);
    glVertex3f(0.21f, 0.19f, 0.0f);

//2nd building 4th floor
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.16f, 0.22f, 0.0f);
    glVertex3f(0.19f, 0.22f, 0.0f);
    glVertex3f(0.19f, 0.24f, 0.0f);
    glVertex3f(0.16f, 0.24f, 0.0f);

    glVertex3f(0.21f, 0.22f, 0.0f);
    glVertex3f(0.24f, 0.22f, 0.0f);
    glVertex3f(0.24f, 0.24f, 0.0f);
    glVertex3f(0.21f, 0.24f, 0.0f);
//2nd building 5th floor
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.16f, 0.27f, 0.0f);
    glVertex3f(0.19f, 0.27f, 0.0f);
    glVertex3f(0.19f, 0.29f, 0.0f);
    glVertex3f(0.16f, 0.29f, 0.0f);

    glVertex3f(0.21f, 0.27f, 0.0f);
    glVertex3f(0.24f, 0.27f, 0.0f);
    glVertex3f(0.24f, 0.29f, 0.0f);
    glVertex3f(0.21f, 0.29f, 0.0f);

//3rd building
    glColor3f (0 ,0,0);
    glVertex3f(0.25f, 0.05f, 0.0f);
    glVertex3f(0.30f, 0.05f, 0.0f);
    glVertex3f(0.30f, 0.32f, 0.0f);
    glVertex3f(0.25f, 0.32f, 0.0f);
//3rd building windows
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.26f, 0.07f, 0.0f);
    glVertex3f(0.29f, 0.07f, 0.0f);
    glVertex3f(0.29f, 0.13f, 0.0f);
    glVertex3f(0.26f, 0.13f, 0.0f);

    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.26f, 0.17f, 0.0f);
    glVertex3f(0.29f, 0.17f, 0.0f);
    glVertex3f(0.29f, 0.23f, 0.0f);
    glVertex3f(0.26f, 0.23f, 0.0f);

    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.26f, 0.26f, 0.0f);
    glVertex3f(0.29f, 0.26f, 0.0f);
    glVertex3f(0.29f, 0.30f, 0.0f);
    glVertex3f(0.26f, 0.30f, 0.0f);

    // last border black on building footer
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f(0.04f, 0.05f, 0.0f);
    glVertex3f(0.04f, 0.06f, 0.0f);
    glVertex3f(0.05f, 0.05f, 0.0f);
    glVertex3f(0.05f, 0.04f, 0.0f);

    glColor3f (0.0, 0.0, 0.0);
    glVertex3f(0.05f, 0.04f, 0.0f);
    glVertex3f(0.05f, 0.05f, 0.0f);
    glVertex3f(0.30f, 0.05f, 0.0f);
    glVertex3f(0.30f, 0.04f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
//1st building win 1
    glColor3f(0.0 ,0.0,0.0);
    glVertex3f( 0.10f, 0.08f ,0.0f );
    glVertex3f( 0.10f, 0.12f ,0.0f );
//sideline 1 building
    glColor3f(0.0 ,0.0,0.0);
    glVertex3f( 0.05f, 0.05f ,0.0f );
    glVertex3f( 0.05f, 0.25f ,0.0f );

//sideline 2 building
    glColor3f(0.0 ,0.0,0.0);
    glVertex3f( 0.15f, 0.05f ,0.0f );
    glVertex3f( 0.15f, 0.30f ,0.0f );
//sideline 1 building
    glColor3f(0.0 ,0.0,0.0);
    glVertex3f( 0.25f, 0.05f ,0.0f );
    glVertex3f( 0.25f, 0.32f ,0.0f );

// 1st building win 2
    glColor3f(0.0 ,0.0,0.0);
    glVertex3f( 0.10f, 0.15f ,0.0f );
    glVertex3f( 0.10f, 0.19f ,0.0f );
//1st building win 3
    glColor3f(0.0 ,0.0,0.0);
    glVertex3f( 0.10f, 0.21f ,0.0f );
    glVertex3f( 0.10f, 0.24f ,0.0f );
// 2nd building 1st floor
    glColor3f(0.0 ,0.0,0.0);
    glVertex3f( 0.15f, 0.10f ,0.0f );
    glVertex3f( 0.25f, 0.10f ,0.0f );
// 2nd building 2nd floor
    glColor3f(0.0 ,0.0,0.0);
    glVertex3f( 0.15f, 0.15f ,0.0f );
    glVertex3f( 0.25f, 0.15f ,0.0f );
// 2nd floor 3rd floor
    glColor3f(0.0 ,0.0,0.0);
    glVertex3f( 0.15f, 0.20f ,0.0f );
    glVertex3f( 0.25f, 0.20f ,0.0f );
// 2nd floor 4th floor
    glColor3f(0.0 ,0.0,0.0);
    glVertex3f( 0.15f, 0.25f ,0.0f );
    glVertex3f( 0.25f, 0.25f ,0.0f );

//3rd building
    glColor3f(0.0 ,0.0,0.0);
    glVertex3f( 0.25f, 0.14f ,0.0f );
    glVertex3f( 0.30f, 0.14f ,0.0f );

    glVertex3f( 0.25f, 0.24f ,0.0f );
    glVertex3f( 0.30f, 0.24f ,0.0f );
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f (0.5, 0.0, 0.0);
    glVertex3f(0.15f, 0.30f, 0.0f);
    glVertex3f(0.06f, 0.25f, 0.0f);
    glVertex3f(0.15f, 0.26f, 0.0f);

    glColor3f (0.4, 0.4, 0.4);
    glVertex3f(0.25f, 0.30f, 0.0f);
    glVertex3f(0.25f, 0.32f, 0.0f);
    glVertex3f(0.22f, 0.30f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    //black font Road here
    glColor3f (0.4, 0.4, 0.4);
    glVertex3f(-0.05f, -0.05f, 0.0f);
    glVertex3f(-0.05f, 0.03f, 0.0f);
    glVertex3f(0.90f, 0.03f, 0.0f);
    glVertex3f(0.90f, -0.05f, 0.0f);

    // road devider1
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(-0.05f, -0.01f, 0.0f);
    glVertex3f(-0.05f, 0.0f, 0.0f);
    glVertex3f(-0.02f, 0.0f, 0.0f);
    glVertex3f(-0.02f, -0.01f, 0.0f);
// road devider2
    glVertex3f(0.03f, 0.0f, 0.0f);
    glVertex3f(0.03f, -0.01f, 0.0f);
    glVertex3f(0.08f, -0.01f, 0.0f);
    glVertex3f(0.08f, 0.0f, 0.0f);

// road devider3
    glVertex3f(0.13f, 0.0f, 0.0f);
    glVertex3f(0.13f, -0.01f, 0.0f);
    glVertex3f(0.18f, -0.01f, 0.0f);
    glVertex3f(0.18f, 0.0f, 0.0f);

// road devider3
    glVertex3f(0.23f, 0.0f, 0.0f);
    glVertex3f(0.23f, -0.01f, 0.0f);
    glVertex3f(0.28f, -0.01f, 0.0f);
    glVertex3f(0.28f, 0.0f, 0.0f);

// road devider4
    glVertex3f(0.33f, 0.0f, 0.0f);
    glVertex3f(0.33f, -0.01f, 0.0f);
    glVertex3f(0.38f, -0.01f, 0.0f);
    glVertex3f(0.38f, 0.0f, 0.0f);
// road devider5
    glVertex3f(0.43f, 0.0f, 0.0f);
    glVertex3f(0.43f, -0.01f, 0.0f);
    glVertex3f(0.48f, -0.01f, 0.0f);
    glVertex3f(0.48f, 0.0f, 0.0f);

// road devider3
    glVertex3f(0.53f, 0.0f, 0.0f);
    glVertex3f(0.53f, -0.01f, 0.0f);
    glVertex3f(0.58f, -0.01f, 0.0f);
    glVertex3f(0.58f, 0.0f, 0.0f);

// road devider3
    glVertex3f(0.63f, 0.0f, 0.0f);
    glVertex3f(0.63f, -0.01f, 0.0f);
    glVertex3f(0.68f, -0.01f, 0.0f);
    glVertex3f(0.68f, 0.0f, 0.0f);

// road devider3
    glVertex3f(0.73f, 0.0f, 0.0f);
    glVertex3f(0.73f, -0.01f, 0.0f);
    glVertex3f(0.78f, -0.01f, 0.0f);
    glVertex3f(0.78f, 0.0f, 0.0f);

// road devider3
    glVertex3f(0.83f, 0.0f, 0.0f);
    glVertex3f(0.83f, -0.01f, 0.0f);
    glVertex3f(0.88f, -0.01f, 0.0f);
    glVertex3f(0.88f, 0.00f, 0.0f);
    glEnd();
    glBegin(GL_QUADS);
    // bus stand
    glColor3f (0.0, 0.05, 1.0);
    glVertex3f(-0.05f, 0.16f, 0.0f);
    glVertex3f(0.03f, 0.16f, 0.0f);
    glVertex3f(0.00f, 0.20f, 0.0f);
    glVertex3f(-0.05f, 0.20f, 0.0f);

//bus stand upper corner
    glColor3f (0, 0, 0);
    glVertex3f(-0.05f, 0.15f, 0.0f);
    glVertex3f(0.03f, 0.15f, 0.0f);
    glVertex3f(0.03f, 0.16f, 0.0f);
    glVertex3f(-0.05f, 0.16f, 0.0f);

//bus stand lower corner
    glColor3f (0.3, 0.3, 0.3);
    glVertex3f(-0.05f, 0.12f, 0.0f);
    glVertex3f(0.01f, 0.12f, 0.0f);
    glVertex3f(0.01f, 0.05f, 0.0f);
    glVertex3f(-0.05f, 0.05f, 0.0f);

// bus stand large pillar
    glColor3f (0, 0, 0);
    glVertex3f(0.0f, 0.05f, 0.0f);
    glVertex3f(0.0f, 0.15f, 0.0f);
    glVertex3f(-0.01f, 0.15f, 0.0f);
    glVertex3f(-0.01f, 0.05f, 0.0f);

// bus stand small pillar
    glColor3f (0, 0, 0);
    glVertex3f(-0.02f, 0.10f, 0.0f);
    glVertex3f(-0.02f, 0.15f, 0.0f);
    glVertex3f(-0.03f, 0.15f, 0.0f);
    glVertex3f(-0.03f, 0.10f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);

    //clubhouse frame beside house
    glColor3f (1.0, 0.0, 1.0);
    glVertex3f(0.55f, 0.05f, 0.0f);
    glVertex3f(0.55f, 0.20f, 0.0f);
    glVertex3f(0.80f, 0.20f, 0.0f);
    glVertex3f(0.80f, 0.05f, 0.0f);

    //clubshouse frame upper
    glColor3f (0.255,0.102,0.255);
    glVertex3f(0.55f, 0.20f, 0.0f);
    glVertex3f(0.60f, 0.22f, 0.0f);
    glVertex3f(0.84f, 0.22f, 0.0f);
    glVertex3f(0.80f, 0.20f, 0.0f);

    //clubhouse frame sider
    glColor3f (0.51,0.255,0.255);
    glVertex3f(0.80f, 0.05f, 0.0f);
    glVertex3f(0.80f, 0.20f, 0.0f);
    glVertex3f(0.84f, 0.22f, 0.0f);
    glVertex3f(0.84f, 0.07f, 0.0f);


    //windows clubhouse in row 1
    glColor3f (1,1,1);
    glVertex3f(0.60f, 0.10f, 0.0f);
    glVertex3f(0.62f, 0.10f, 0.0f);
    glVertex3f(0.62f, 0.12f, 0.0f);
    glVertex3f(0.60f, 0.12f, 0.0f);

    glVertex3f(0.60f, 0.13f, 0.0f);
    glVertex3f(0.62f, 0.13f, 0.0f);
    glVertex3f(0.62f, 0.15f, 0.0f);
    glVertex3f(0.60f, 0.15f, 0.0f);

    //windows clubhouse in row 2
    glColor3f (1,1,1);
    glVertex3f(0.63f, 0.10f, 0.0f);
    glVertex3f(0.65f, 0.10f, 0.0f);
    glVertex3f(0.65f, 0.12f, 0.0f);
    glVertex3f(0.63f, 0.12f, 0.0f);

    glVertex3f(0.63f, 0.13f, 0.0f);
    glVertex3f(0.65f, 0.13f, 0.0f);
    glVertex3f(0.65f, 0.15f, 0.0f);
    glVertex3f(0.63f, 0.15f, 0.0f);

    //windows clubhouse in row 3
    glColor3f (1,1,1);
    glVertex3f(0.66f, 0.10f, 0.0f);
    glVertex3f(0.68f, 0.10f, 0.0f);
    glVertex3f(0.68f, 0.12f, 0.0f);
    glVertex3f(0.66f, 0.12f, 0.0f);

    glVertex3f(0.66f, 0.13f, 0.0f);
    glVertex3f(0.68f, 0.13f, 0.0f);
    glVertex3f(0.68f, 0.15f, 0.0f);
    glVertex3f(0.66f, 0.15f, 0.0f);

    //windows clubhouse in row 4
    glColor3f (1,1,1);
    glVertex3f(0.69f, 0.10f, 0.0f);
    glVertex3f(0.71f, 0.10f, 0.0f);
    glVertex3f(0.71f, 0.12f, 0.0f);
    glVertex3f(0.69f, 0.12f, 0.0f);

    glVertex3f(0.69f, 0.13f, 0.0f);
    glVertex3f(0.71f, 0.13f, 0.0f);
    glVertex3f(0.71f, 0.15f, 0.0f);
    glVertex3f(0.69f, 0.15f, 0.0f);

    //windows clubhouse in row 5
    glColor3f (1,1,1);
    glVertex3f(0.73f, 0.10f, 0.0f);
    glVertex3f(0.75f, 0.10f, 0.0f);
    glVertex3f(0.75f, 0.12f, 0.0f);
    glVertex3f(0.73f, 0.12f, 0.0f);

    glVertex3f(0.73f, 0.13f, 0.0f);
    glVertex3f(0.75f, 0.13f, 0.0f);
    glVertex3f(0.75f, 0.15f, 0.0f);
    glVertex3f(0.73f, 0.15f, 0.0f);


    //clubhouse door
    glColor3f (1,1,1);
    glVertex3f(0.65f, 0.05f, 0.0f);
    glVertex3f(0.65f, 0.08f, 0.0f);
    glVertex3f(0.70f, 0.08f, 0.0f);
    glVertex3f(0.70f, 0.05f, 0.0f);

    glEnd();
    glBegin(GL_LINES);
    // clubhouse lines
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f(0.55f, 0.20f, 0.0f);
    glVertex3f(0.80f, 0.20f, 0.0f);

    glVertex3f(0.80f, 0.20f, 0.0f);
    glVertex3f(0.84f, 0.22f, 0.0f);

    glVertex3f(0.55f, 0.20f, 0.0f);
    glVertex3f(0.60f, 0.22f, 0.0f);

    glVertex3f(0.60f, 0.22f, 0.0f);
    glVertex3f(0.84f, 0.22f, 0.0f);

    glVertex3f(0.80f, 0.05f, 0.0f);
    glVertex3f(0.80f, 0.20f, 0.0f);

    glVertex3f(0.84f, 0.07f, 0.0f);
    glVertex3f(0.84f, 0.22f, 0.0f);

    glVertex3f(0.80f, 0.05f, 0.0f);
    glVertex3f(0.84f, 0.07f, 0.0f);

    glVertex3f(0.55f, 0.05f, 0.0f);
    glVertex3f(0.80f, 0.05f, 0.0f);

    glVertex3f(0.55f, 0.05f, 0.0f);
    glVertex3f(0.55f, 0.20f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    //shohid miner ground

    glColor3f (1.0, 0.5, .0);
    glVertex3f(0.35f, 0.10f, 0.0f);
    glVertex3f(0.32f, 0.20f, 0.0f);
    glVertex3f(0.53f, 0.20f, 0.0f);
    glVertex3f(0.50f, 0.10f, 0.0f);
    //minar 1
    //left piller
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.34f, 0.17f, 0.0f);
    glVertex3f(0.35f, 0.17f, 0.0f);
    glVertex3f(0.35f, 0.22f, 0.0f);
    glVertex3f(0.34f, 0.22f, 0.0f);
    //right piller
    glVertex3f(0.36f, 0.17f, 0.0f);
    glVertex3f(0.37f, 0.17f, 0.0f);
    glVertex3f(0.37f, 0.22f, 0.0f);
    glVertex3f(0.36f, 0.22f, 0.0f);
    //upper piller
    glVertex3f(0.34f, 0.22f, 0.0f);
    glVertex3f(0.34f, 0.23f, 0.0f);
    glVertex3f(0.37f, 0.23f, 0.0f);
    glVertex3f(0.37f, 0.22f, 0.0f);
    glEnd();
    //background red color
    glColor3f (1.0, 0.0, 0.0);
    circle(0.03,0.03,0.425, 0.21);
    //main miner(miner 2)
    //left piller
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.40f, 0.17f, 0.0f);
    glVertex3f(0.41f, 0.17f, 0.0f);
    glVertex3f(0.41f, 0.22f, 0.0f);
    glVertex3f(0.40f, 0.22f, 0.0f);
    //right piller
    glVertex3f(0.44f, 0.17f, 0.0f);
    glVertex3f(0.45f, 0.17f, 0.0f);
    glVertex3f(0.45f, 0.22f, 0.0f);
    glVertex3f(0.44f, 0.22f, 0.0f);

    //up1
    glVertex3f(0.40f, 0.22f, 0.0f);
    glVertex3f(0.39f, 0.24f, 0.0f);
    glVertex3f(0.40f, 0.24f, 0.0f);
    glVertex3f(0.41f, 0.22f, 0.0f);
    //up2
    glVertex3f(0.44f, 0.22f, 0.0f);
    glVertex3f(0.43f, 0.24f, 0.0f);
    glVertex3f(0.44f, 0.24f, 0.0f);
    glVertex3f(0.45f, 0.22f, 0.0f);
    //up vertical
    glVertex3f(0.39f, 0.24f, 0.0f);
    glVertex3f(0.39f, 0.25f, 0.0f);
    glVertex3f(0.44f, 0.25f, 0.0f);
    glVertex3f(0.44f, 0.24f, 0.0f);

    //minar 2
    //left piller
    glVertex3f(0.47f, 0.17f, 0.0f);
    glVertex3f(0.48f, 0.17f, 0.0f);
    glVertex3f(0.48f, 0.22f, 0.0f);
    glVertex3f(0.47f, 0.22f, 0.0f);
    //right piller
    glVertex3f(0.50f, 0.17f, 0.0f);
    glVertex3f(0.51f, 0.17f, 0.0f);
    glVertex3f(0.51f, 0.22f, 0.0f);
    glVertex3f(0.50f, 0.22f, 0.0f);
    //upper piller
    glVertex3f(0.47f, 0.22f, 0.0f);
    glVertex3f(0.47f, 0.23f, 0.0f);
    glVertex3f(0.51f, 0.23f, 0.0f);
    glVertex3f(0.51f, 0.22f, 0.0f);
    glEnd();

    //glClear(GL_COLOR_BUFFER_BIT);
    if(p<=2.0)
        p=p+.0002;
    else
        p=-0.00000005;
    glutPostRedisplay();
    //glutOverlayDisplayFunc();
    glBegin(GL_QUADS); //upper body
    glColor3f(1.0,0.0,0);
    glVertex3f(p+0.01,0.06,0);
    glVertex3f(p+0.01,0.02,0);
    glVertex3f(p+0.10,0.02,0);
    glVertex3f(p+0.10,0.06,0);
    glEnd();
    glBegin(GL_QUADS); // lower body
    glColor3f(1.0,0.0,0);
    glVertex3f(p-0.05,-0.015,0);
    glVertex3f(p-0.05,0.025,0);
    glVertex3f(p+0.16,0.025,0);
    glVertex3f(p+0.16,-0.015,0);
    glEnd();
    //first car body in back side
    glBegin(GL_TRIANGLES);
    glVertex3f(p+0.01,0.02,0);
    glVertex3f(p+0.01,0.06,0);
    glVertex3f(p-0.01,0.02,0);

    glVertex3f(p+0.10,0.02,0);
    glVertex3f(p+0.10,0.06,0);
    glVertex3f(p+0.125,0.02,0);
    glEnd();

    glBegin(GL_QUADS);
    //window 1
    glColor3f(0.0,0.0,0);
    glVertex3f(p+0.01,0.03,0);
    glVertex3f(p+0.025,0.05,0);
    glVertex3f(p+0.05,0.05,0);
    glVertex3f(p+0.05,0.03,0);
    //windows 2
    glVertex3f(p+0.06,0.03,0);
    glVertex3f(p+0.06,0.05,0);
    glVertex3f(p+0.08,0.05,0);
    glVertex3f(p+0.095,0.03,0);
    glEnd();

    glColor3f(0.0,0.0,0);
    circle(0.02,0.02,p+0.0, -0.01); //tier 1
    circle(0.02,0.02,p+0.10, -0.01); //tier 2


    /*car2*/
    glBegin(GL_QUADS); //upper body
    glColor3f(0.255,0.102,0.255);
    glVertex3f(p-0.31,0.06,0);
    glVertex3f(p-0.31,0.02,0);
    glVertex3f(p-0.40,0.02,0);
    glVertex3f(p-0.40,0.06,0);
    glEnd();
    glBegin(GL_QUADS); // lower body
    glVertex3f(p-0.46,-0.015,0);
    glVertex3f(p-0.46,0.025,0);
    glVertex3f(p-0.25,0.025,0);
    glVertex3f(p-0.25,-0.015,0);
    glEnd();
    //first car body in back side
    glBegin(GL_TRIANGLES);
    glVertex3f(p-0.31,0.02,0);
    glVertex3f(p-0.31,0.06,0);
    glVertex3f(p-0.29,0.02,0);

    glVertex3f(p-0.40,0.02,0);
    glVertex3f(p-0.40,0.06,0);
    glVertex3f(p-0.425,0.02,0);
    glEnd();

    glBegin(GL_QUADS);
    //window 1
    glColor3f(0.0,0.0,0);
    glVertex3f(p-0.31,0.03,0);
    glVertex3f(p-0.325,0.05,0);
    glVertex3f(p-0.35,0.05,0);
    glVertex3f(p-0.35,0.03,0);
    //windows 2
    glVertex3f(p-0.36,0.03,0);
    glVertex3f(p-0.36,0.05,0);
    glVertex3f(p-0.38,0.05,0);
    glVertex3f(p-0.395,0.03,0);
    glEnd();

    glColor3f(0.0,0.0,0);
    circle(0.02,0.02,p-0.30, -0.01); //tier 1
    circle(0.02,0.02,p-0.40, -0.01); //tier 2

    //bus
    glBegin(GL_QUADS); //lower body
    glColor3f(0.0 ,0.0, 1.0);
    glVertex3f(p-0.55,-0.02,0);
    glVertex3f(p-0.55,0.05,0);
    glVertex3f(p-0.75,0.05,0);
    glVertex3f(p-0.75,-0.02,0);
    //upper body

    glVertex3f(p-0.75,0.08,0);
    glVertex3f(p-0.75,0.05,0);
    glVertex3f(p-0.55,0.05,0);
    glVertex3f(p-0.55,0.08,0);


    //windows 1
    glColor3f(1.0,1.0,1);
    glVertex3f(p-0.56,0.02,0);
    glVertex3f(p-0.56,0.07,0);
    glVertex3f(p-0.59,0.07,0);
    glVertex3f(p-0.59,0.02,0);
    //windows 2
    glColor3f(1.0,1.0,1);
    glVertex3f(p-0.60,0.02,0);
    glVertex3f(p-0.60,0.07,0);
    glVertex3f(p-0.63,0.07,0);
    glVertex3f(p-0.63,0.02,0);

    //windows 3
    glColor3f(1.0,1.0,1);
    glVertex3f(p-0.64,0.02,0);
    glVertex3f(p-0.64,0.07,0);
    glVertex3f(p-0.67,0.07,0);
    glVertex3f(p-0.67,0.02,0);
    //windows 4
    glColor3f(1.0,1.0,1);
    glVertex3f(p-0.68,0.02,0);
    glVertex3f(p-0.68,0.07,0);
    glVertex3f(p-0.71,0.07,0);
    glVertex3f(p-0.71,0.02,0);
    //windows 5
    glColor3f(1.0,1.0,1);
    glVertex3f(p-0.72,0.02,0);
    glVertex3f(p-0.72,0.07,0);
    glVertex3f(p-0.735,0.07,0);
    glVertex3f(p-0.735,0.02,0);

    glEnd();

    //tier1
    glColor3f(0.0,0.0,0);
    circle(0.025,0.025,p-0.60, -0.01); //tier 1
    circle(0.025,0.025,p-0.70, -0.01); //tier 2


    glFlush();
}

void mydisplay(void)
{

    all();
}



void init ()
{
    glClearColor (1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-0.05, 0.85, -0.05, 0.40, 0.0, 10.0);
    //glOrtho(-0.9, 1.85, -0.05, 1.40, 0.0, 10.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    //glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1200, 720);
    glutInitWindowPosition (70, 80);
    glutCreateWindow ("Final Project");
    init ();
    glutDisplayFunc(mydisplay);
    glutMainLoop();
    return 0;
}
