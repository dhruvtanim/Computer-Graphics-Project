#include <GL/gl.h>
#include <GL/glut.h>
#include<bits/stdc++.h>
#include <math.h>
#include <stdio.h>
#include<conio.h>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <time.h>
#include <iomanip>
#include <windows.h>
#define PI 3.1415926535897323846

using namespace std;

float _move_sun = 1.00f;

float _move_cloud_1 = 0.00f;
float _move_cloud_2 = 0.00f;

float _move_tank_1 = 1.4f;
float _move_tank_2 = -1.2f;

float _speed_cloud_1 = 0.00025f;
float _speed_cloud_2 = 0.00025f;

float _move_plane_1 = 1.0f;
float _speed_plane_1 = 0.00025f;

float _speed_tank_1 = 0.00000025f;
float _speed_tank_2 = 0.00000025f;

float _move_ship = 1.4f;
float _speed_ship = 0.00025f;

float move_Snow = 0.00f;
float _speed_Snow = 0.0025f;

bool isRain = false;
bool isSnow = false;

GLfloat i = 0.0f;
GLfloat r = 0.0f;
GLfloat position = 0.0f;
GLfloat speed = 0.00025f;

void rainSound()
{
    PlaySound("rain.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}

void rainSoundOff()
{
    PlaySound(NULL, NULL, SND_ASYNC|SND_FILENAME);
}

void snowSound()
{
    PlaySound("snow.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}

void snowSoundOff()
{
    PlaySound(NULL, NULL, SND_ASYNC|SND_FILENAME);
}

void update_ship(int value)
{
    if(_speed_ship>1 || _speed_ship<0)
    {
        _speed_ship = 0.0f;
    }
    _move_ship -= _speed_ship;

    if(_move_ship +1.3 < -1.0)
    {
        _move_ship = 1.5;
    }
	glutPostRedisplay();

	glutTimerFunc(20, update_ship, 0);
}

void update_cloud_1(int value)
{
    if(_speed_cloud_1>1.00f || _speed_cloud_1<0.00f)
    {
        _speed_cloud_1 = 0.0f;
    }
    _move_cloud_1 += _speed_cloud_1;

    if(_move_cloud_1-1.3 > 1.0)
    {
        _move_cloud_1 = -1.0;
    }
	glutPostRedisplay();

	glutTimerFunc(20, update_cloud_1, 0);
}

void update_cloud_2(int value)
{
    if(_speed_cloud_2>1 || _speed_cloud_2<0)
    {
        _speed_cloud_2 = 0.0f;
    }
    _move_cloud_2 -= _speed_cloud_2;

    if(_move_cloud_2+1.3 < -1.0)
    {
        _move_cloud_2 = 1.5;
    }
	glutPostRedisplay();

	glutTimerFunc(20, update_cloud_2, 0);
}

void update_sun(int value)
{
    _move_sun -= 0.00055f;
    if(_move_sun+1.0 < -1.0)
    {
        _move_sun = 1.0;
    }

	glutPostRedisplay();

	glutTimerFunc(20, update_sun, 0);
}

void update_Snow(int value)
{
    move_Snow -= 0.0055f;
    if(move_Snow+1.0 < -1.0)
    {
        move_Snow = 1.0;
    }
	glutPostRedisplay();

	glutTimerFunc(20, update_Snow, 0);
}

void update_plane(int value)
{
    if(position > 1.6)
        position = -1.2f;

    position += speed;

	glutPostRedisplay();

	glutTimerFunc(20, update_plane, 0);
}

void update_plane1(int value)
{
    if(position > 1.6)
        position = -1.2f;

    position -= speed;

	glutPostRedisplay();

	glutTimerFunc(20, update_plane1, 0);
}

void update_tank_t34(int value)
{
    _move_tank_1 -= _speed_tank_1;
    if(_move_tank_1 + 2.6 < -1.0)
    {
        _move_tank_1 = 1.2;
    }

    glutPostRedisplay();

	glutTimerFunc(20, update_tank_t34, 0);
}

void update_tank_tiger(int value)
{
    _move_tank_2 += _speed_tank_2;
    if(_move_tank_2 - 2.6 > 1.0)
    {
        _move_tank_2 = -1.2;
    }

    glutPostRedisplay();

	glutTimerFunc(20, update_tank_tiger, 0);
}

void star()
{
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.0085;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
}

void Snowball()
{
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.0085;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
}

void specialKeys(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_UP:
        update_plane(0);
        break;

    case GLUT_KEY_DOWN:
        exit(0);
        break;
    }
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'C':
            _speed_cloud_1+=0.0025f;
            update_cloud_1(0);
            break;

        case 'c':
            _speed_cloud_1-=0.0025f;
            update_cloud_1(0);
            break;

        case 'P':
            _speed_plane_1+=0.0025f;
            update_plane(0);
            break;

        case 'p':
            _speed_plane_1-=0.0025f;
            update_plane1(0);
            break;

        case 'R':
            isRain=true;
            rainSound();
            break;

        case 'r':
            isRain=false;
            rainSoundOff();
            break;

        case 'S':
            isSnow=true;
            snowSound();
            break;

        case 's':
            isSnow=false;
            snowSoundOff();
            break;

        case 'J':
            _speed_ship+=0.0025f;
            update_ship(0);
            break;

        case 'j':
            _speed_ship-=0.0025f;
            update_ship(0);
            break;

        case 'D':
            _speed_cloud_2+=0.0025f;
            update_cloud_2(0);
            break;

        case 'd':
            _speed_cloud_2-=0.0025f;
            update_cloud_2(0);
            break;

        case 'T':
            _speed_tank_1+=0.0025f;
            update_tank_t34(0);
            break;

        case 't':
            _speed_tank_1-=0.0025f;
            update_tank_t34(0);
            break;

        case 'U':
            _speed_tank_2 += 0.0025f;
            update_tank_tiger(0);
            break;

        case 'u':
            _speed_tank_2 -= 0.0025f;
            update_tank_tiger(0);
            break;
    }
}

void handleMouse(int button, int state, int x, int y)
{
    if (button == GLUT_RIGHT_BUTTON)
    {
        speed += 0.00055f;
    }
    if (button == GLUT_LEFT_BUTTON)
    {
        speed -= 0.00055f;
    }
    glutPostRedisplay();
}

void ship()
{
    glPushMatrix();//start_pushpop
    glTranslatef(_move_ship, 0.0f, 0.0f);
    glColor3f(0.647, 0.165, 0.165);
    glBegin(GL_POLYGON);
    glVertex2f(-0.75, -0.98);
    glVertex2f(-0.45, -0.98);
    glVertex2f(-0.40, -0.83);
    glVertex2f(-0.80, -0.83);
    glEnd();
    glPopMatrix();

    glPushMatrix();//start_pushpop
    glTranslatef(_move_ship, 0.0f, 0.0f);
    glColor3ub(192, 139, 61);
    glBegin(GL_POLYGON);
    glVertex2f(-0.70, -0.83);
    glVertex2f(-0.45, -0.83);
    glVertex2f(-0.45, -0.75);
    glVertex2f(-0.70, -0.75);
    glEnd();
    glPopMatrix();

    glPushMatrix();//start_pushpop
    glTranslatef(_move_ship, 0.0f, 0.0f);
    glColor3ub(192,192,192);
    glBegin(GL_POLYGON);
    glVertex2f(-0.60, -0.75);
    glVertex2f(-0.50, -0.75);
    glVertex2f(-0.50, -0.65);
    glVertex2f(-0.60, -0.65);
    glEnd();
    glPopMatrix();

    if(_move_sun<-0.10 || _move_sun>0.90 || isRain==true)
    {
        glColor3f(2.000, 1.973, 1.863);
        glPushMatrix();
        glTranslatef(_move_ship, 0.0f, 0.0f);
        glTranslatef(-0.25f, 0.03f, 0.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.40, -0.80);
        glVertex2f(-0.60, -0.75);
        glVertex2f(-0.60, -0.85);
        glEnd();
        glPopMatrix();
    }
}

void sky()
{
    //Sky
    if(isRain==true || isSnow==true)
    {
        glBegin(GL_QUADS);
        glColor3f(0.5647, 0.6196, 0.6235);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);

        glColor3f(0.50, 0.58, 0.60);
        glVertex2f(1.0, -0.05);
        glVertex2f(-1.0, -0.05);
        glEnd();
    }
    else
    {

        if(_move_sun<=1.00f && _move_sun>=0.90f)
        {
            glClear (GL_COLOR_BUFFER_BIT);
            glBegin(GL_QUADS);
            glColor3f(0.529, 0.808, 0.922);
            glVertex2f(-1.0,1.0);
            glVertex2f(1.0,1.0);

            glColor3f(0.529, 0.808, 0.980);
            glVertex2f(1.0, -0.05);
            glVertex2f(-1.0, -0.05);
            glEnd();
        }
        else if(_move_sun<0.90f && _move_sun>=0.55f)
        {
            glBegin(GL_QUADS);
            glColor3f(0.000, 0.749, 1.000);
            glVertex2f(-1.0,1.0);
            glVertex2f(1.0,1.0);

            glColor3f(0.8, 1.000, 1.000);
            glVertex2f(1.0, -0.05);
            glVertex2f(-1.0, -0.05);
            glEnd();
        }
        else if(_move_sun<0.55f && _move_sun>=0.35f)
        {
            glBegin(GL_QUADS);
            glColor3f(0.000, 0.749, 1.000);
            glVertex2f(-1.0,1.0);
            glVertex2f(1.0,1.0);

            glColor3f(1.000, 0.961, 0.933);
            glVertex2f(1.0, -0.05);
            glVertex2f(-1.0, -0.05);
            glEnd();
        }
        else if(_move_sun<0.35f && _move_sun>=0.25f)
        {
            glBegin(GL_QUADS);
            glColor3f(0.529, 0.808, 0.980);
            glVertex2f(-1.0,1.0);
            glVertex2f(1.0,1.0);

            glColor3f(1.000, 0.855, 0.725);
            glVertex2f(1.0, -0.05);
            glVertex2f(-1.0, -0.05);
            glEnd();
        }
        else if(_move_sun<0.25f && _move_sun>=0.10f)
        {
            glBegin(GL_QUADS);
            glColor3f(0.529, 0.808, 0.980);
            glVertex2f(-1.0,1.0);
            glVertex2f(1.0,1.0);

            glColor3f(0.957, 0.643, 0.376);
            glVertex2f(1.0, -0.05);
            glVertex2f(-1.0, -0.05);
            glEnd();
        }
        else if(_move_sun<0.10f && _move_sun>=0.0f)
        {
            glBegin(GL_QUADS);
            glColor3f(1.000, 0.388, 0.278);
            glVertex2f(-1.0,1.0);
            glVertex2f(1.0,1.0);

            glColor3f(0.957, 0.643, 0.376);
            glVertex2f(1.0, -0.05);
            glVertex2f(-1.0, -0.05);
            glEnd();
        }
        else
        {
            glBegin(GL_QUADS);
            glColor3f(0.412, 0.412, 0.412);
            glVertex2f(-1.0,1.0);
            glVertex2f(1.0,1.0);

            glColor3f(0.8, 1.000, 1.000);
            glVertex2f(1.0, -0.05);
            glVertex2f(-1.0, -0.05);
            glEnd();

            glPushMatrix();
            glTranslatef(0.0f, _move_sun, 0.0f);
            glTranslatef(0.80,1.05,0);
            glScalef(0.6,1,1);
            glColor3f(0.902, 0.902, 0.980);
            glBegin(GL_POLYGON);// moon
            for(int i=0;i<200;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/200;
                float r=0.085;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );
            }
            glEnd();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(0.95,0.95,0);
            star();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-0.75,0.85,0);
            star();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-0.65,0.65,0);
            star();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(0.60,0.85,0);
            star();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-0.65,0.93,0);
            star();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-0.10,0.67,0);
            star();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(0.15,0.67,0);

            glPopMatrix();

            glPushMatrix();
            glTranslatef(-0.35,0.85,0);
            star();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(0.25,0.73,0);
            star();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-0.72,0.63,0);
            star();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(0.05,0.43,0);
            star();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(0.15,0.13,0);
            star();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-0.15,0.88,0);
            star();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(0.65,0.73,0);
            star();
            glPopMatrix();
        }
    }
}

void field_1()
{
    //field 1
    glBegin(GL_QUADS);
    glColor3ub(26, 98, 8);
    glVertex2f(1.0f, -0.60f);

    glColor3f(0.000, 1.000, 0.000);
    glVertex2f(-1.0f, -0.60f);

    glColor3ub(93, 180, 92);
    glVertex2f(-1.0f, -0.05f);

    glColor3ub(77, 130, 3);
    glVertex2f(1.0f,-0.05f);
    glEnd();
}

void roadStrips()
{
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.95, -0.30);
    glVertex2f(-0.95, -0.32);
    glVertex2f(-0.65, -0.32);
    glVertex2f(-0.65, -0.30);
    glEnd();
}

void road()
{
    //Main road lane 1
    glBegin(GL_QUADS);
    glColor3f(0.412, 0.412, 0.412);
    glVertex2f(-1.0, -0.12);
    glVertex2f(-1.0, -0.50);
    glVertex2f(1.0, -0.50);
    glVertex2f(1.0, -0.12);
    glEnd();
    //Main Road Strips 1
    roadStrips();

    //Main Road Strips 2
    glPushMatrix();
    glTranslatef(0.40,0,0);
    roadStrips();
    glTranslatef(0.40,0,0);
    roadStrips();
    glTranslatef(0.40,0,0);
    roadStrips();
    glTranslatef(0.40,0,0);
    roadStrips();
    glPopMatrix();
}

void TANK_T34()
{
    //tank t - 34
    glPushMatrix();
    glScalef(0.8, 0.6, 0.0);
    glTranslatef(0.0f,-0.4f, 0.0f);
    glTranslatef(_move_tank_1,0.0f, 0.0f);

    //T - 34 Body part -1
    glBegin(GL_QUADS);
    glColor3ub(240,230,140);
    glVertex2f(0.4f,  0.0f);
    glVertex2f(0.4f,  0.1f);
    glVertex2f(0.6f,  0.0f);
    glVertex2f(0.6f,  0.1f);
    glEnd();

    //T - 34 Body part -2
    glBegin(GL_QUADS);
    glColor3ub(238,232,170);
    glVertex2f(0.3f, -0.1f);
    glVertex2f(0.6f, -0.1f);
    glVertex2f(0.6f,  0.0f);
    glVertex2f(0.3f,  0.0f);
    glEnd();

    //T - 34 Body part -3
    glBegin(GL_QUADS);
    glColor3ub(243, 234, 18);
    glVertex2f(0.2f, -0.1f);
    glVertex2f(0.65f, -0.1f);
    glVertex2f(0.65f, -0.3f);
    glVertex2f(0.2f, -0.3f);
    glEnd();

    //T -34 Window -1
    glBegin(GL_QUADS);
    glColor3ub(210,224,190);
    glVertex2f(0.4f, -0.2f);
    glVertex2f(0.3f, -0.2f);
    glVertex2f(0.3f, -0.3f);
    glVertex2f(0.4f, -0.3f);
    glEnd();

    //T -34 Window -2
    glBegin(GL_QUADS);
    glColor3ub(210,224,190);
    glVertex2f(0.6f, -0.2f);
    glVertex2f(0.5f, -0.2f);
    glVertex2f(0.5f, -0.3f);
    glVertex2f(0.6f, -0.3f);
    glEnd();

    //T -34 Window -3
    glBegin(GL_QUADS);
    glColor3ub(210,224,190);
    glVertex2f(0.5f, -0.1f);
    glVertex2f(0.4f, -0.1f);
    glVertex2f(0.4f, -0.2f);
    glVertex2f(0.5f, -0.2f);
    glEnd();

    //T - 34 wheel -1
    int i;
    GLfloat x = 0.2f;
    GLfloat y = -0.356f;
    GLfloat radius = 0.06f;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(44,60,43);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //T - 34 wheel -2
    x = 0.35f;
    y = -0.356f;
    radius = 0.06f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(44,60,43);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //T - 34 wheel -3
    x = 0.5f;
    y = -0.356f;
    radius = 0.06f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(44,60,43);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //T - 34 wheel -4
    x = 0.65f;
    y = -0.356f;
    radius = 0.06f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(44,60,43);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Right Tank Fire Tube (T - 34)
    glLineWidth(15);
    glBegin(GL_LINES);
    glColor3ub(240,230,140);
    glVertex2f(0.3f, -0.035f);
    glVertex2f(-0.05f, -0.035f);
    glEnd();

    //T - 34 wheel chain -1
    glLineWidth(8);
    glBegin(GL_LINES);
    glColor3ub(44,60,43);
    glVertex2f(0.2f, -0.41f);
    glVertex2f(0.65f, -0.41f);
    glEnd();

    //T - 34 wheel chain -2
    glLineWidth(8);
    glBegin(GL_LINES);
    glColor3ub(44,60,43);
    glVertex2f(0.2f, -0.31f);
    glVertex2f(0.65f, -0.31f);
    glEnd();
    glPopMatrix();
}

void TANK_TIGER()
{
    //tank tiger
    glPushMatrix();
    glScalef(0.8, 0.6, 0.0);
    glTranslatef(0.0f,-0.4f, 0.0f);
    glTranslatef(_move_tank_2,0.0f, 0.0f);

    //Tiger Body part -1
    glBegin(GL_QUADS);
    glColor3ub(46,139,87);
    glVertex2f(-0.4f,  -0.0f);
    glVertex2f(-0.4f,  -0.1f);
    glVertex2f(-0.6f,  -0.0f);
    glVertex2f(-0.6f,  -0.1f);
    glEnd();

    //Tiger Body part -2
    glBegin(GL_QUADS);
    glColor3ub(107,142,35);
    glVertex2f(-0.3f, -0.1f);
    glVertex2f(-0.6f, -0.1f);
    glVertex2f(-0.6f,  -0.0f);
    glVertex2f(-0.3f,  -0.0f);
    glEnd();

    //Tiger Body part -3
    glBegin(GL_QUADS);
    glColor3ub(85,107,47);
    glVertex2f(-0.2f, -0.1f);
    glVertex2f(-0.65f, -0.1f);
    glVertex2f(-0.65f, -0.3f);
    glVertex2f(-0.2f, -0.3f);
    glEnd();

    //Tiger Window -1
    glBegin(GL_QUADS);
    glColor3ub(210,224,190);
    glVertex2f(-0.4f, -0.2f);
    glVertex2f(-0.3f, -0.2f);
    glVertex2f(-0.3f, -0.3f);
    glVertex2f(-0.4f, -0.3f);
    glEnd();

    //Tiger Window -2
    glBegin(GL_QUADS);
    glColor3ub(210,224,190);
    glVertex2f(-0.6f, -0.2f);
    glVertex2f(-0.5f, -0.2f);
    glVertex2f(-0.5f, -0.3f);
    glVertex2f(-0.6f, -0.3f);
    glEnd();

    //Tiger Window -3
    glBegin(GL_QUADS);
    glColor3ub(210,224,190);
    glVertex2f(-0.5f, -0.1f);
    glVertex2f(-0.4f, -0.1f);
    glVertex2f(-0.4f, -0.2f);
    glVertex2f(-0.5f, -0.2f);
    glEnd();

    //Tiger wheel -1
    int i;
    GLfloat x = -0.2f;
    GLfloat y = -0.356f;
    GLfloat radius = 0.06f;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(44,60,43);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Tiger wheel -2
    x = -0.35f;
    y = -0.356f;
    radius = 0.06f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(44,60,43);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Tiger wheel -3
    x = -0.5f;
    y = -0.356f;
    radius = 0.06f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(44,60,43);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Tiger wheel -4
    x = -0.65f;
    y = -0.356f;
    radius = 0.06f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(44,60,43);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Left Tank Fire Tube (Tiger)
    glLineWidth(15);
    glBegin(GL_LINES);
    glColor3ub(107,142,35);
    glVertex2f(-0.3f, -0.035f);
    glVertex2f(-0.05f, -0.035f);
    glEnd();

    //Tiger wheel chain -1
    glLineWidth(8);
    glBegin(GL_LINES);
    glColor3ub(44,60,43);
    glVertex2f(-0.2f, -0.41f);
    glVertex2f(-0.65f, -0.41f);
    glEnd();

    //Tiger wheel chain -2
    glLineWidth(8);
    glBegin(GL_LINES);
    glColor3ub(44,60,43);
    glVertex2f(-0.2f, -0.31f);
    glVertex2f(-0.65f, -0.31f);
    glEnd();
    glPopMatrix();
}

void sun_circle()
{
    glScalef(0.6,1,1);
    glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.125;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
}

void sun()
{
    //Sun
    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
    if(isRain==true || isSnow==true)
    {

    }
    else
    {
        if(_move_sun<=1.00 && _move_sun>=0.90f)
        {
            glPushMatrix();
            glTranslatef(0.0f, _move_sun, 0.0f);
            glColor3f(1.000, 0.647, 0.000);
            sun_circle();
            glPopMatrix();
        }
        else if(_move_sun<0.90f && _move_sun>=0.80f)
        {
            glPushMatrix();
            glTranslatef(0.0f, _move_sun, 0.0f);
            glColor3f(1.000, 0.843, 0.000);
            sun_circle();
            glPopMatrix();
        }
        else if(_move_sun<0.80 && _move_sun>=0.65)
        {
            glPushMatrix();
            glTranslatef(0.0f, _move_sun, 0.0f);
            glColor3f(1.000, 1.000, 0.000);
            sun_circle();
            glPopMatrix();
        }
        else if(_move_sun<0.65 && _move_sun>=0.45)
        {
            glPushMatrix();
            glTranslatef(0.0f, _move_sun, 0.0f);
            glColor3f(1.000, 0.843, 0.000);
            sun_circle();
            glPopMatrix();
        }

        else if(_move_sun<0.45 && _move_sun>=0.25){
            glPushMatrix();
            glTranslatef(0.0f, _move_sun, 0.0f);
            glColor3f(1.000, 0.647, 0.000);
            sun_circle();
            glPopMatrix();
        }
        else if(_move_sun<0.25 && _move_sun>=0.0)
        {
            glPushMatrix();
            glTranslatef(0.0f, _move_sun, 0.0f);
            glColor3f(1.000, 0.549, 0.000);
            sun_circle();
            glPopMatrix();
        }
        else
        {
            glPushMatrix();
            glTranslatef(0.0f, _move_sun, 0.0f);
            glColor3f(1.000, 0.271, 0.000);
            sun_circle();
            glPopMatrix();
        }
    }
}

void cloud_struct()
{

    if(isRain==true)
    {
        glColor3f(0.500, 0.500, 0.500);
    }
    else
    {
        glColor3f(1.000, 1.000, 1.000);
    }
    glScalef(0.6,1,1);
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.075;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
}

void cloud_left()
{
    //Cloud on the left
    glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
    glTranslatef(-0.78,0.82,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
    glTranslatef(-0.74,0.87,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
    glTranslatef(-0.70,0.91,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
    glTranslatef(-0.65,0.88,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
    glTranslatef(-0.61,0.80,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
    glTranslatef(-0.68,0.77,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
    glTranslatef(-0.75,0.78,0);
    cloud_struct();
    glPopMatrix();
}

void cloud_right()
{
    //Cloud on the right
    glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
    glTranslatef(0.78,0.70,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
    glTranslatef(0.74,0.75,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
    glTranslatef(0.70,0.79,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
    glTranslatef(0.65,0.76,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
    glTranslatef(0.61,0.76,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
    glTranslatef(0.68,0.65,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
    glTranslatef(0.63,0.66,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
    glTranslatef(0.75,0.66,0);
    cloud_struct();
    glPopMatrix();
}

void river()
{
    glBegin(GL_QUADS);
    glColor3ub(0, 141, 168);
    glVertex2f(1.0, -0.60);

    glColor3ub(67, 95, 97);
    glVertex2f(-1.0, -0.60);

    glColor3ub(123, 192, 217);
    glVertex2f(-1.0, -1.0);

    glColor3ub(121, 146,175);
    glVertex2f(1.0, -1.0);

    glEnd();
}

void planeWindow()
{
   glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(-0.1f, -0.1f);
    glVertex2f(-0.1f, 0.1f);
    glVertex2f(0.1f, 0.1f);
    glVertex2f(0.1f, -0.1f);
   glEnd();
}

void plane()
{
    glBegin(GL_TRIANGLES);
    glColor3ub(51, 78, 144);
    glVertex2f(0.9f, 0.0f);
    glColor3f(0.9, 0.9, 1.0);
    glVertex2f(0.5f, 0.2f);
    glColor3f(0.9, 0.9, 1.0);
    glVertex2f(0.5f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(165, 166, 175);
    glVertex2f(0.5f, 0.2f);
    glVertex2f(-0.4f, 0.2f);
    glVertex2f(-0.4f, 0.0f);
    glVertex2f(0.5f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.000, 0.5, 1.000);
    glVertex2f(-0.4f, 0.2f);
    glVertex2f(-0.6f, 0.4f);
    glVertex2f(-0.7f, 0.4f);
    glVertex2f(-0.6f, 0.0f);
    glVertex2f(-0.4f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.000, 0.5, 1.000);
    glVertex2f(-0.1f, 0.2f);
    glVertex2f(-0.3f, 0.5f);
    glVertex2f(-0.2f, 0.5f);
    glVertex2f(0.2f, 0.2f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.000, 0.5, 1.000);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.3f, -0.3f);
    glVertex2f(-0.2f, -0.3f);
    glVertex2f(0.2f, 0.0f);
    glEnd();

    glPushMatrix();
    glScalef(0.2, 0.4, 0.0);
    glTranslatef( 0.3, 0.32, 0.0);
    planeWindow();
    glTranslatef( 0.3, 0.0, 0.0);
    planeWindow();
    glTranslatef( 0.3, 0.0, 0.0);
    planeWindow();
    glTranslatef( 0.3, 0.0, 0.0);
    planeWindow();
    glPopMatrix();
}

void tower()
{
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);

    if(_move_sun<0.10 || _move_sun>0.90)
    {
        glColor3f(2.0, 2.0, 2.0);
    }
    glVertex2f(-0.28, -0.03);
    glVertex2f(-0.20, -0.03);
    glVertex2f(-0.20, 0.05);
    glVertex2f(-0.28, 0.05);
    glEnd();
}

void building1()
{
    //Red Building
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.133, 0.133);
    glVertex2f(-0.95, -0.05);
    glVertex2f(-0.75, -0.05);
    glVertex2f(-0.75, 0.42);
    glVertex2f(-0.95, 0.42);

    //Door of Red Building
    glBegin(GL_QUADS);
    glColor3f(1.000, 0.894, 0.882);
    glVertex2f(-0.90, -0.05);
    glVertex2f(-0.80, -0.05);
    glVertex2f(-0.80, 0.15);
    glVertex2f(-0.90, 0.15);

    //2 Window of Red Building
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);;
    glVertex2f(-0.93, 0.26);
    glVertex2f(-0.88, 0.26);
    glVertex2f(-0.88, 0.36);
    glVertex2f(-0.93, 0.36);

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.82, 0.26);
    glVertex2f(-0.77, 0.26);
    glVertex2f(-0.77, 0.36);
    glVertex2f(-0.82, 0.36);

    //Roof top of red building
    glBegin(GL_QUADS);
    glColor3f(0.502, 0.000, 0.000);
    glVertex2f(-0.93, 0.42);
    glVertex2f(-0.87, 0.42);
    glVertex2f(-0.87, 0.52);
    glVertex2f(-0.93, 0.52);

    glBegin(GL_QUADS);
    glColor3f(0.647, 0.165, 0.165);
    glVertex2f(-0.94, 0.52);
    glVertex2f(-0.86, 0.52);
    glVertex2f(-0.86, 0.54);
    glVertex2f(-0.94, 0.54);
    glEnd();
}

void building2()
{
    //Blue Building
    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex2f(-0.45, -0.05);
    glVertex2f(-0.52, -0.05);
    glVertex2f(-0.52, 0.43);
    glVertex2f(-0.45, 0.43);

    glVertex2f(-0.52, -0.05);
    glVertex2f(-0.55, -0.05);
    glVertex2f(-0.55, 0.32);
    glVertex2f(-0.52, 0.43);

    glVertex2f(-0.55, -0.05);
    glVertex2f(-0.60, -0.05);
    glVertex2f(-0.60, 0.30);
    glVertex2f(-0.55, 0.32);

    glVertex2f(-0.60, -0.05);
    glVertex2f(-0.65, -0.05);
    glVertex2f(-0.65, 0.25);
    glVertex2f(-0.60, 0.30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.153, 0.204, 0.253);
    glVertex2f(-0.45, 0.43);
    glVertex2f(-0.51, 0.43);
    glVertex2f(-0.51, 0.50);
    glVertex2f(-0.45, 0.50);

    tower();
    glPushMatrix();
    glTranslatef(-0.258,0.00,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glTranslatef(0,0.1,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.358,0.00,0);
    tower();
    glTranslatef(0.0,0.0,0.0);
    tower();
    glTranslatef(0.0,0.1,0.0);
    tower();
    glTranslatef(0.0,0.1,0.0);
    tower();

    glPopMatrix();
}

void building3()
{
    glBegin(GL_QUADS);
    glColor3f(0.647, 0.165, 0.165);
    glVertex2f(-0.30, -0.05);
    glVertex2f(-0.25, -0.05);
    glVertex2f(-0.25, 0.60);
    glVertex2f(-0.30, 0.60);

    glVertex2f(-0.1, -0.05);
    glVertex2f(-0.08, -0.05);
    glVertex2f(-0.08, 0.42);
    glVertex2f(-0.1, 0.45);

    glVertex2f(-0.12, -0.05);
    glVertex2f(-0.1, -0.05);
    glVertex2f(-0.1, 0.46);
    glVertex2f(-0.12, 0.48);

    glVertex2f(-0.14, -0.05);
    glVertex2f(-0.12, -0.05);
    glVertex2f(-0.12, 0.50);
    glVertex2f(-0.14, 0.51);

    glVertex2f(-0.16, -0.05);
    glVertex2f(-0.14, -0.05);
    glVertex2f(-0.14, 0.52);
    glVertex2f(-0.16, 0.54);

    glVertex2f(-0.20, -0.05);
    glVertex2f(-0.16, -0.05);
    glVertex2f(-0.16, 0.54);
    glVertex2f(-0.20, 0.54);

    glVertex2f(-0.28, -0.05);
    glVertex2f(-0.20, -0.05);
    glVertex2f(-0.20, 0.58);
    glVertex2f(-0.28, 0.58);
    glEnd();

    tower();

    glPushMatrix();
    glTranslatef(0.0,0.10,0);
    tower();
    glColor3f(0.0, 0.0, 0.0);
    tower();
    glTranslatef(0.0,0.10,0);
    tower();
    glTranslatef(0.0,0.10,0);
    tower();
    glTranslatef(0.0,0.10,0);
    tower();
    glTranslatef(0.0,0.10,0);
    tower();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.10,0.0,0);
    tower();
    glTranslatef(0.0,0.0,0);
    tower();
    glTranslatef(0.0,0.10,0);
    tower();
    glTranslatef(0.0,0.10,0);
    tower();
    glTranslatef(0.0,0.10,0);
    tower();
    glTranslatef(0.0,0.10,0);
    tower();
    glPopMatrix();
}

void building4()
{
    //Tower 1 of twin tower
    //Tower 2 of twin tower
    glBegin(GL_QUADS);
    glColor3f(0.647, 0.165, 0.165);
    glVertex2f(0.30, -0.05);
    glVertex2f(0.28, -0.05);
    glVertex2f(0.28, 0.56);
    glVertex2f(0.30, 0.56);

    glVertex2f(0.1, -0.05);
    glVertex2f(0.08, -0.05);
    glVertex2f(0.08, 0.45);
    glVertex2f(0.1, 0.45);

    glVertex2f(0.12, -0.05);
    glVertex2f(0.1, -0.05);
    glVertex2f(0.1, 0.48);
    glVertex2f(0.12, 0.48);

    glVertex2f(0.14, -0.05);
    glVertex2f(0.12, -0.05);
    glVertex2f(0.12, 0.51);
    glVertex2f(0.14, 0.51);

    glVertex2f(0.16, -0.05);
    glVertex2f(0.14, -0.05);
    glVertex2f(0.14, 0.5);
    glVertex2f(0.16, 0.5);

    glVertex2f(0.20, -0.05);
    glVertex2f(0.16, -0.05);
    glVertex2f(0.16, 0.54);
    glVertex2f(0.20, 0.54);

    glVertex2f(0.28, -0.05);
    glVertex2f(0.20, -0.05);
    glVertex2f(0.20, 0.58);
    glVertex2f(0.28, 0.58);
    glEnd();

    glPushMatrix();
    glTranslatef(0.38,0.0,0);
    tower();
    glTranslatef(0.0,0.0,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.48,0.0,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glPopMatrix();
    glEnd();
}
void building5()
{
    //House 1
    glBegin(GL_QUADS);
    glColor3f(0.400, 0.804, 0.667);
    glVertex2f(0.45, -0.05);
    glVertex2f(0.50, -0.05);
    glVertex2f(0.50, 0.47);
    glVertex2f(0.45, 0.47);

    glVertex2f(0.50, -0.05);
    glVertex2f(0.55, -0.05);
    glVertex2f(0.55, 0.47);
    glVertex2f(0.50, 0.47);

    glVertex2f(0.55, -0.05);
    glVertex2f(0.60, -0.05);
    glVertex2f(0.60, 0.40);
    glVertex2f(0.55, 0.42);

    glVertex2f(0.60, -0.05);
    glVertex2f(0.65, -0.05);
    glVertex2f(0.65, 0.30);
    glVertex2f(0.60, 0.40);

    //black
    glColor3f(0.00, 0.255, 0.0);
    glVertex2f(0.45, 0.47);
    glVertex2f(0.50, 0.47);

    glVertex2f(0.50, 0.52);
    glVertex2f(0.45, 0.52);

    tower();
    glPushMatrix();
    glTranslatef(0.745,0.00,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glTranslatef(0,0.1,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.835,0.00,0);
    tower();
    glTranslatef(0.0,0.0,0.0);
    tower();
    glTranslatef(0.0,0.1,0.0);
    tower();
    glTranslatef(0.0,0.1,0.0);
    tower();
    glTranslatef(0.0,0.1,0.0);
    tower();

    glPopMatrix();
}

void building6()
{
    //House 2
    glBegin(GL_QUADS);
    glColor3f(0.804, 0.361, 0.361);
    glVertex2f(0.75, -0.05);
    glVertex2f(0.80, -0.05);
    glVertex2f(0.80, 0.40);
    glVertex2f(0.75, 0.38);

    glVertex2f(0.80, -0.05);
    glVertex2f(0.85, -0.05);
    glVertex2f(0.85, 0.48);
    glVertex2f(0.80, 0.40);

    glVertex2f(0.85, -0.05);
    glVertex2f(0.90, -0.05);
    glVertex2f(0.90, 0.48);
    glVertex2f(0.85, 0.48);

    glVertex2f(0.90, -0.05);
    glVertex2f(0.95, -0.05);
    glVertex2f(0.95, 0.50);
    glVertex2f(0.90, 0.48);

    glEnd();

    glPushMatrix();
    glTranslatef(1.14,0.00,0);
    tower();
    glTranslatef(0.0,0.0,0);
    tower();
    glTranslatef(0,0.1,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.04,0.00,0);
    tower();
    glTranslatef(0.0,0.0,0.0);
    tower();
    glTranslatef(0.0,0.0,0.0);
    tower();
    glTranslatef(0.0,0.1,0.0);
    tower();
    glTranslatef(0.0,0.1,0.0);
    tower();
    glTranslatef(0.0,0.1,0.0);
    tower();

    glPopMatrix();
}

void airplane()
{
    glLoadIdentity();

    glPushMatrix();
    glTranslatef(position,0.0f, 0.0f);
    glScalef(0.2, 0.2, 0.0);
    glTranslatef(0.0, 4.0, 0.0);
    plane();
    glPopMatrix();
}

void rain()
{
    if(isRain==true)
    {
        int i=0,j=0;
        float x,y;
        x=-1.0f;
        y=2.0f;

        while(j<=100)
        {
            x = -1.0f;
            while(i<=100)
            {
                glColor3f(0.313, 0.560, 0.713);
                glLineWidth(1.5);
                glBegin(GL_LINES);
                glVertex2f(x,y);
                glVertex2f(x-0.02f,y-0.07f);
                glEnd();

                x=x+0.03f;
                i++;
            }
            y = y-0.05f;
            j++;
            i=0;
        }
    }
}

void snow()
{
    double x=-0.99,y=-0.95;
    if(isSnow==true)
    {
        for(int i=0;i<200;i++)
        {

            for(int j=0;j<200;j++)
            {

                glPushMatrix();
                glTranslatef(x,y+move_Snow,0);
                Snowball();
                glPopMatrix();

                y=y+0.03f;
            }
            y=-0.95f;
            x = x+0.03f;
        }
    }
}

void myDisplay(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    sky();
    sun();

    cloud_left();
    cloud_right();

    field_1();

    building1();
    building2();
    building4();
    building3();
    building5();
    building6();

    road();

    TANK_T34();
    TANK_TIGER();

    river();
    ship();

    airplane();

    rain();
    snow();
    glFlush();
}

void myInit (void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);
}

int main(int argc, char** argv)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 1);
    cout << endl << "******************** Tiger Vs T-34 ********************" << endl << endl;

    SetConsoleTextAttribute(h, 2);
    cout << "          COMPUTER GRAPHICS [G]           " << endl ;
    cout << "  Project Submission [ Spring 2021-2022 ]" << endl;
    cout << "  Submitted To : MD SIYAMUL ISLAM" << endl << endl <<endl;
    SetConsoleTextAttribute(h, 3);
    cout << "Group Members:" << endl;
    cout << "============================================================="<<endl;
    cout <<"| AFTAB, RAKIN SAD           |    20-41991-1    |           |"<<endl;
    cout <<"| HAMIM, MD. ASHADUZZAMAN    |    20-42062-1    |           |"<<endl;
    cout <<"| SARKAR, ANONNYA            |    20-42600-1    | Group - 4 |"<<endl;
    cout <<"| HAMID, MD.ABDUL            |    20-42602-1    |           |"<<endl;
    cout <<"| SHADHIN, MD YOUSUF ALI     |    20-42783-1    |           |"<<endl;
    cout << "============================================================="<<endl<<endl<<endl;

    SetConsoleTextAttribute(h, 4);
    cout <<"******************** Keyboard Interaction ********************"<<endl<<endl<<endl;

    cout << "Press C : To Forward the Cloud-1 && Press c : To Backward the Cloud-1" << endl << endl;

    cout << "Press D : To Forward the Cloud-2 && Press d : To Backward the Cloud-2" << endl << endl;

    cout << "Press P : To Forward the Plane && Press p : To Backward the Plane" << endl << endl;

    cout << "Press J : To Forward the Ship && Press u : To Backward the Ship" << endl << endl;

    cout << "Press T : To Forward the T-34 && Press t : To Backward the T-34" << endl << endl;

    cout << "Press U : To Forward the Tiger && Press u : To Backward the Tiger" << endl << endl;

    cout << "Press R : For Rain && Press r : To Stop The Rain" << endl << endl;

    cout << "Press S : For Snow && Press s : To Stop Snow" << endl << endl << endl;

    SetConsoleTextAttribute(h, 5);
    cout << "******************** Mouse Interaction ********************"<<endl <<endl<<endl;

    cout << "Mouse Right Click : To Increase the Plane Speed"<<endl<<endl;

    cout << "Mouse Left Click : To Decrease the Plane Speed"<<endl<<endl<<endl;

    SetConsoleTextAttribute(h, 11);
    cout <<"******************** Special Keywords ********************"<<endl<<endl<<endl;
    cout <<"Press KEY UP : For Move Plane"<<endl;
    cout <<"Press KEY DOWN : For EXIT"<<endl;
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (1920, 1080);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("Tiger Vs T - 34");
    glutDisplayFunc(myDisplay);
    glutSpecialFunc(specialKeys);

    glutMouseFunc(handleMouse);

    glutKeyboardFunc(keyboard);
    glutTimerFunc(20, update_sun, 0);
    glutTimerFunc(20, update_cloud_1, 0);
    glutTimerFunc(20, update_cloud_2, 0);

    glutTimerFunc(20, update_tank_t34, 0);
    glutTimerFunc(20, update_tank_tiger, 0);

    glutTimerFunc(20, update_plane, 0);
    glutTimerFunc(20, update_ship, 0);
    glutTimerFunc(20, update_Snow, 0);
    myInit ();
    glutMainLoop();
}
