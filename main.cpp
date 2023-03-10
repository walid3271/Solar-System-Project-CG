#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

float r, x, y, theta;
float m = 0, v = 0, e = 0, mr = 0, j = 0, s = 0, u = 0, n = 0, moon=0, jupiter_moon1 = 0, jupiter_moon2 = 0, jupiter_moon3 = 0;
float mercury_x = 200;
float mercury_y = 0;
float venus_x = 400;
float venus_y = 0;
float earth_x = 600;
float earth_y = 0;
float moon_x = 700;
float moon_y = 0;
float mars_x = 800;
float mars_y = 0;
float jupiter_x = 1000;
float jupiter_y = 0;
float jupiter_moon1_x = 1100;
float jupiter_moon1_y = 0;
float jupiter_moon2_x = 1100;
float jupiter_moon2_y = 0;
float jupiter_moon3_x = 1100;
float jupiter_moon3_y = 0;
float saturn_x = 1200;
float saturn_y = 0;
float uranus_x = 1400;
float uranus_y = 0;
float neptune_x = 1600;
float neptune_y = 0;
void timer(int);

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);

    ///200 random star at each frame
    for(int z =0; z <= 200; z++)
    {
        int zx = rand() % 3400 - 1700;
        int zy = rand() % 3400 - 1700;
        glPointSize(0.5);
        glBegin(GL_POINTS);
        glColor3ub(255,255,255);
        glVertex2f(zx, zy);
    }


    r = 1600;
    for(int j=0; j<8; j++)///Planetary orbits
    {
        for(int i=0; i<=360; i++)
        {
            glPointSize(1.0f);
            glBegin(GL_POINTS);
            glColor3ub (255, 255, 255);

            theta = i*3.142/180;
            glVertex2f(r*cos(theta), r*sin(theta));
            glEnd();
        }
        r -=200;
    }


    for(int i=0; i<=360; i++) ///Orbit of the earth moon
    {
        glPointSize(1.0f);
        glBegin(GL_POINTS);
        glColor3ub (255, 255, 255);

        theta = i*3.142/180;
        glVertex2f(100*cos(theta)+earth_x,100*sin(theta)+earth_y);
        glEnd();
    }

    for(int i=0; i<=360; i++) ///Orbit of the jupiter moon
    {
        glPointSize(1.0f);
        glBegin(GL_POINTS);
        glColor3ub (255, 255, 255);

        theta = i*3.142/180;
        glVertex2f(140*cos(theta)+jupiter_x,140*sin(theta)+jupiter_y);
        glEnd();
    }




    ///sun
    glBegin(GL_POLYGON);
    glColor3ub(254,204,25);
    for(int i = 0; i <= 360; i++)
    {
        theta = i*3.142/180;
        glVertex2f(80*cos(theta), 80*sin(theta));
    }
    glEnd();

    ///mercury
    glBegin(GL_POLYGON);
    glColor3ub(204,126,56);
    for(int i = 0; i <= 360; i++)
    {
        theta = i*3.142/180;
        glVertex2f(50*cos(theta) + mercury_x, 50*sin(theta) + mercury_y);
    }
    glEnd();

    ///venus
    glBegin(GL_POLYGON);
    glColor3ub(215,122,98);
    for(int i = 0; i <= 360; i++)
    {
        theta = i*3.142/180;
        glVertex2f(80*cos(theta) + venus_x, 80*sin(theta) + venus_y);
    }
    glEnd();

    ///earth
    glBegin(GL_POLYGON);
    glColor3ub(70,248,202);
    for(int i = 0; i <= 360; i++)
    {
        theta = i*3.142/180;
        glVertex2f(80*cos(theta) +earth_x, 80*sin(theta) +earth_y);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(125,223,63);
    for(int i = 200; i <= 260; i++)
    {
        theta = i*3.142/180;
        glVertex2f(80*cos(theta) +earth_x, 80*sin(theta) +earth_y);
    }
    glVertex2f(-40+earth_x, -10+earth_y);
    glVertex2f(-20+earth_x, -20+earth_y);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(125,223,63);
    for(int i = 280; i <= 350; i++)
    {
        theta = i*3.142/180;
        glVertex2f(80*cos(theta) +earth_x, 80*sin(theta) +earth_y);
    }
    glVertex2f(40+earth_x, -10+earth_y);
    glVertex2f(20+earth_x, -20+earth_y);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(125,223,63);
    for(int i = 70; i <= 130; i++)
    {
        theta = i*3.142/180;
        glVertex2f(80*cos(theta) +earth_x, 80*sin(theta) +earth_y);
    }
    glVertex2f(-40+earth_x, 10+earth_y);
    glVertex2f(20+earth_x, 20+earth_y);
    glEnd();

    ///moon
    glBegin(GL_POLYGON);
    glColor3ub(254, 252, 215);
    for(int i = 0; i <= 360; i++)
    {
        theta = i*3.142/180;
        glVertex2f(25*cos(theta) +moon_x, 25*sin(theta) +moon_y);
    }
    glEnd();




    ///mars
    glBegin(GL_POLYGON);
    glColor3ub(198,62,60);
    for(int i = 0; i <= 360; i++)
    {
        theta = i*3.142/180;
        glVertex2f(70*cos(theta) +mars_x, 70*sin(theta) +mars_y);
    }
    glEnd();

    ///jupiter
    glBegin(GL_POLYGON);
    glColor3ub(214,206,158);
    for(int i = 0; i <= 360; i++)
    {
        theta = i*3.142/180;
        glVertex2f(120*cos(theta) +jupiter_x, 120*sin(theta) + jupiter_y);
    }
    glEnd();

    ///jupiter moon 1
    glBegin(GL_POLYGON);
    glColor3ub(254, 252, 215);
    for(int i = 0; i <= 360; i++)
    {
        theta = i*3.142/180;
        glVertex2f(10*cos(theta) +jupiter_moon1_x, 10*sin(theta) +jupiter_moon1_y);
    }
    glEnd();

    ///jupiter moon 2
    glBegin(GL_POLYGON);
    glColor3ub(254, 252, 215);
    for(int i = 0; i <= 360; i++)
    {
        theta = i*3.142/180;
        glVertex2f(20*cos(theta) +jupiter_moon2_x, 20*sin(theta) +jupiter_moon2_y);
    }
    glEnd();

    ///jupiter moon 3
    glBegin(GL_POLYGON);
    glColor3ub(254, 252, 215);
    for(int i = 0; i <= 360; i++)
    {
        theta = i*3.142/180;
        glVertex2f(15*cos(theta) +jupiter_moon3_x, 15*sin(theta) +jupiter_moon3_y);
    }
    glEnd();

    ///saturn
    glBegin(GL_POLYGON);
    glColor3ub(231,203,191);
    for(int i = 0; i <= 360; i++)
    {
        theta = i*3.142/180;
        glVertex2f(130*cos(theta) + saturn_x, 60*sin(theta) +saturn_y);
    }
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(37,9,50);
    for(int i = 0; i <= 360; i++)
    {
        theta = i*3.142/180;
        glVertex2f(110*cos(theta) + saturn_x, 50*sin(theta) +saturn_y);
    }
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(227,197,101);
    for(int i = 0; i <= 360; i++)
    {
        theta = i*3.142/180;
        glVertex2f(90*cos(theta) +saturn_x, 90*sin(theta) +saturn_y);
    }
    glEnd();

    ///uranus
    glBegin(GL_POLYGON);
    glColor3ub(36,97,253);
    for(int i = 0; i <= 360; i++)
    {
        theta = i*3.142/180;
        glVertex2f(80*cos(theta) +uranus_x, 80*sin(theta) +uranus_y);
    }
    glEnd();

    ///neptune
    glBegin(GL_POLYGON);
    glColor3ub(153,223,254);
    for(int i = 0; i <= 360; i++)
    {
        theta = i*3.142/180;
        glVertex2f(80*cos(theta) + neptune_x, 80*sin(theta) + neptune_y);
    }
    glEnd();



    glutSwapBuffers();
}

void init (void)
{
    glClearColor (0.142, 0.0353, 0.196, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1700, 1700, -1700, 1700);

}


int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (700, 700);
    glutInitWindowPosition (100, 0);
    glutCreateWindow ("Solar System Model");
    init ();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(40, timer, 0);
    if(n < 360)
    {
        theta = n*3.142/180;
        neptune_x = 1600*cos(theta);
        neptune_y = 1600*sin(theta);
    }
    if(n >= 360)
    {
        n = 0;
    }
    if(u < 360)
    {
        theta = u*3.142/180;
        uranus_x = 1400*cos(theta);
        uranus_y = 1400*sin(theta);
    }
    if(u >= 360)
    {
        u = 0;
    }
    if(s < 360)
    {
        theta = s*3.142/180;
        saturn_x = 1200*cos(theta);
        saturn_y = 1200*sin(theta);
    }
    if(s >= 360)
    {
        s = 0;
    }
    if(j < 360)
    {
        theta = j*3.142/180;
        jupiter_x = 1000*cos(theta);
        jupiter_y = 1000*sin(theta);
    }
    if(j >= 360)
    {
        j = 0;
    }

    if(jupiter_moon1 < 360)
    {
        theta = jupiter_moon1*3.142/180;
        jupiter_moon1_x = 140*cos(theta)+jupiter_x;
        jupiter_moon1_y = 140*sin(theta)+jupiter_y;
    }
    if(jupiter_moon1 >= 360)
    {
        jupiter_moon1 = 0;
    }
    if(jupiter_moon2 < 360)
    {
        theta = jupiter_moon2*3.142/180;
        jupiter_moon2_x = 140*cos(theta)+jupiter_x;
        jupiter_moon2_y = 140*sin(theta)+jupiter_y;
    }
    if(jupiter_moon2 >= 360)
    {
        jupiter_moon2 = 0;
    }
    if(jupiter_moon3 < 360)
    {
        theta = jupiter_moon3*3.142/180;
        jupiter_moon3_x = 140*cos(theta)+jupiter_x;
        jupiter_moon3_y = 140*sin(theta)+jupiter_y;
    }
    if(jupiter_moon3 >= 360)
    {
        jupiter_moon3 = 0;
    }

    if(mr < 360)
    {
        theta = mr*3.142/180;
        mars_x = 800*cos(theta);
        mars_y = 800*sin(theta);
    }
    if(mr >= 360)
    {
        mr = 0;
    }

    if(e < 360)
    {
        theta = e*3.142/180;
        earth_x = 600*cos(theta);
        earth_y = 600*sin(theta);
    }
    if(e >= 360)
    {
        e = 0;
    }

    if(moon < 360)
    {
        theta = moon*3.142/180;
        moon_x = 100*cos(theta)+earth_x;
        moon_y = 100*sin(theta)+earth_y;
    }
    if(moon >= 360)
    {
        moon = 0;
    }

    if(v < 360)
    {
        theta = v*3.142/180;
        venus_x = 400*cos(theta);
        venus_y = 400*sin(theta);
    }
    if(v >= 360)
    {
        v = 0;
    }

    if(m < 360)
    {
        theta = m*3.142/180;
        mercury_x = 200*cos(theta);
        mercury_y = 200*sin(theta);
    }
    if(m >= 360)
    {
        m = 0;
    }
    n += 0.012;
    u += 0.018;
    s += 0.068;
    j += 0.168;
    jupiter_moon1 += 2.168;
    jupiter_moon2 -= 3.168;
    jupiter_moon3 += 1.5;
    mr += 1.06;
    e += 1.5;
    moon+= 4.5;
    v += 3.24;
    m += 8.32;
}
