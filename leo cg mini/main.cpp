#include <GL/glut.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <GL/freeglut.h>
#include<unistd.h>
#include <iostream>
#include <conio.h>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const float SPHERE_RADIUS = 1.0f;
const float OUTER_SPHERE_RADIUS = 1.5f;
 float temperature = 20.0f;
float viewingDistance = 5.0f;
float sphereRotation = 0.0f;
float sphereTilt = 23.5f; // Tilt angle in degrees

float outerSphereOpacity = 0.0f;
int fadeStartTime = 0;

const int MAX_STARS = 1500;

float starPositions[MAX_STARS][3];

void initializeStars()
{
    for (int i = 0; i < MAX_STARS; ++i)
    {
        starPositions[i][0] = static_cast<float>(rand() % 21 - 10);
        starPositions[i][1] = static_cast<float>(rand() % 21 - 10);
        starPositions[i][2] = static_cast<float>(rand() % 21 - 10);
    }
}
void showWelcomePage() {
    std::cout << "Welcome" << std::endl;
    std::cout << "Press any key to start..." << std::endl;
    _getch(); // Wait for a key press
}

void calculatePointOnSphere(float latitude, float longitude, float& x, float& y, float& z)
{
    float latR = latitude * (M_PI / 180.0f);
    float lonR = longitude * (M_PI / 180.0f);

    x = SPHERE_RADIUS * sinf(latR) * cosf(lonR);
    y = SPHERE_RADIUS * sinf(latR) * sinf(lonR);
    z = SPHERE_RADIUS * cosf(latR);
}



void renderTemperatureText()
{
    glDisable(GL_LIGHTING); // Disable lighting for the text
    glDisable(GL_DEPTH_TEST); // Disable depth testing
float t = (temperature - 20.0f) / 10.0f; // Scale temperature between 20.0 and 30.0
t = fmaxf(0.0f, fminf(t, 1.0f));
    // Interpolate between green and red colors
GLfloat colorR = 0.0f + t * (1.0f - 0.0f);  // Red component
GLfloat colorG = 1.0f - t * (1.0f - 0.0f);  // Green component
GLfloat colorB = 0.0f; // Blue component (constant as 0.0 for green to red gradient)

// Set the interpolated color
glColor3f(colorR, colorG, colorB);
 // Set text color to white

    // Set the position and orientation for the text
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-2.0f, -2.0f, -5.0f); // Adjust the position as needed

    char temperatureText[50]; // Buffer to hold the temperature text
   // Example temperature value (replace with your own)

    // Format the temperature text
    snprintf(temperatureText, sizeof(temperatureText), "Temperature: %.1f°C", temperature);

    // Render the temperature text using GLUT bitmap font
    glRasterPos2f(0.0f, 0.0f); // Set the raster position

    for (int i = 0; i < strlen(temperatureText); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, temperatureText[i]);
    }

    glPopMatrix();
glColor3f(1.0f, 1.0f, 1.0f);

 glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(1.2f, 1.2f, -5.0f); // Adjust the position as needed

    char ozoneText[50]; // Buffer to hold the temperature text
   // Example temperature value (replace with your own)

    // Format the temperature text
    snprintf(ozoneText, sizeof(ozoneText), "ozone");

    // Render the temperature text using GLUT bitmap font
    glRasterPos2f(0.0f, 0.0f); // Set the raster position

    for (int i = 0; i < strlen(ozoneText); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ozoneText[i]);
    }
    glPopMatrix();
    glColor3f(0.0f, 0.5f, 0.7f);

 glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-1.3f, 1.2f, -5.0f); // Adjust the position as needed

    char earthText[50]; // Buffer to hold the temperature text
   // Example temperature value (replace with your own)

    // Format the temperature text
    snprintf(earthText, sizeof(earthText), "earth");

    // Render the temperature text using GLUT bitmap font
    glRasterPos2f(0.0f, 0.0f); // Set the raster position

    for (int i = 0; i < strlen(earthText); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, earthText[i]);
    }
    glEnable(GL_LIGHTING); // Re-enable lighting
    glEnable(GL_DEPTH_TEST); // Re-enable depth testing
}

int i;
void display1()
{

	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,1000,0,1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glBegin(GL_POLYGON);
        glColor3f(0.439,0.502,0.565);
        glVertex2f(0,500);
        glVertex2f(500,500);
        glVertex2f(1000,500);
	glEnd();
	char str1[]="SAHYADRI COLLEGE OF ENGINEERING AND MANAGEMENT";
	glColor3f(0,0,0);
	glRasterPos2f(300,950);
	for(i=0;i<strlen(str1);i++)
	{
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str1[i]);
    }
	char str2[]="ADYAR,MANGALURU:574143";
	glColor3f(0,0,0);
	glRasterPos2f(350,900);
	for(i=0;i<strlen(str2);i++)
	{
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str2[i]);
    }
	char str3[]="DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING";
	glColor3f(0,0,1);
	glRasterPos2f(220,820);
	for(i=0;i<strlen(str3);i++)
	{
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str3[i]);
    }
	char str4[]="COMPUTER GRAPHICS AND VISUALIZATION";
	glColor3f(0,0,1);
	glRasterPos2f(280,770);
	for(i=0;i<strlen(str4);i++)
	{
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str4[i]);
    }
	char str5[]="MINI PROJECT";
	glColor3f(0,0,0);
	glRasterPos2f(390,690);
	for(i=0;i<strlen(str5);i++)
	{
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str5[i]);
    }
	char str6[]="ON";
	glColor3f(0,0,0);
	glRasterPos2f(440,640);
	for(i=0;i<strlen(str6);i++)
	{
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str6[i]);
    }
	char str16[]="GLOBAL WARMING AND OZONE";
	glColor3f(0,0,1);
	glRasterPos2f(330,570);
	for(i=0;i<strlen(str16);i++)
	{
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str16[i]);
    }
	char str7[]="TEAM MEMBERS:";
	glColor3f(0,0,0);
	glRasterPos2f(0,400);
	for(i=0;i<strlen(str7);i++)
	{
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str7[i]);
    }
	char str8[]="LEONARD YESUDAS-4SF20CS056";
	glColor3f(0,0.3,1);
	glRasterPos2f(0,350);
	for(i=0;i<strlen(str8);i++)
	{
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str8[i]);
    }
	char str9[]="";
	glColor3f(0,0.3,1);
	glRasterPos2f(0,300);
	for(i=0;i<strlen(str9);i++)
	{
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str9[i]);
    }
	char str10[]="DEPT OF CSE,SEC B";
	glColor3f(0,0,0);
	glRasterPos2f(0,250);
	for(i=0;i<strlen(str10);i++)
	{
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str10[i]);
    }
	char str11[]="PROJECT GUIDED BY:";
	glColor3f(0,0,0);
	glRasterPos2f(800,400);
	for(i=0;i<strlen(str11);i++)
	{
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str11[i]);
    }
	char str12[]="Ms. Megha Rani";
	glColor3f(0,0.3,1);
	glRasterPos2f(800,350);
	for(i=0;i<strlen(str12);i++)
	{
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str12[i]);
    }
	char str13[]="Associate Professor";
	glColor3f(0,0.3,1);
	glRasterPos2f(800,300);
	for(i=0;i<strlen(str13);i++)
	{
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str13[i]);
    }
	char str14[]="DEPT OF CSE";
	glColor3f(0,0,0);
	glRasterPos2f(800,250);
	for(i=0;i<strlen(str14);i++)
	{
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str14[i]);
    }
	char str15[]="PRESS 'Q' TO START";
	glColor3f(0,0,0);
	glRasterPos2f(390,30);
	for(i=0;i<strlen(str15);i++)
	{
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str15[i]);
    }
    glFlush();
}




void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Set the camera position
    gluLookAt(0.0f, 0.0f, viewingDistance,  // camera position
          0.0f, 0.0f, 0.0f,             // target position
          0.0f, 1.0f, 0.0f); // up vector

    // Draw stars in the background
    glDisable(GL_LIGHTING);
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(2.0f);
    glBegin(GL_POINTS);
    for (int i = 0; i < MAX_STARS; ++i)
    {
        // Randomly change the star's brightness
        if (rand() % 100 < 5)
            glColor3f(1.0f, 1.0f, 1.0f);
        else
            glColor3f(0.5f, 0.5f, 0.5f);

        glVertex3fv(starPositions[i]);
    }
    glEnd();

    // Enable lighting for the sphere
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    // Set light position and properties
    GLfloat lightPosition[] = { 3.0, 3.0, 0.0, 0.0 }; // Light from the right
    GLfloat lightAmbient[] = { 0.1, 0.1, 0.1, 1.0 };
    GLfloat lightDiffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat lightSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat materialShininess[] = { 100.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);

    // Enable color material and set material properties
    glEnable(GL_COLOR_MATERIAL);
     glColor4f(0.0f, 0.5f, 0.7f, 1.0f);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    GLfloat materialAmbientDiffuse[] = { 0.0f, 0.5f, 0.7f, 1.0f }; // Sea blue color
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, materialAmbientDiffuse);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

    glColor3f(0.0f, 1.0f, 0.0f);
     glBegin(GL_TRIANGLES);

    float latitude1 = 30.0f;
    float latitude2 = 60.0f;
    float latitude3 = 90.0f;

    float longitude1 = 0.0f;
    float longitude2 = 120.0f;
    float longitude3 = 240.0f;

    float x1, y1, z1;
    float x2, y2, z2;
    float x3, y3, z3;

    calculatePointOnSphere(latitude1, longitude1, x1, y1, z1);
    calculatePointOnSphere(latitude2, longitude2, x2, y2, z2);
    calculatePointOnSphere(latitude3, longitude3, x3, y3, z3);

    glVertex3f(x1, y1, z1);
    glVertex3f(x2, y2, z2);
    glVertex3f(x3, y3, z3);
    glEnd();




    // Calculate the color interpolation factor based on time
    glEnable(GL_COLOR_MATERIAL);

    // Calculate the color interpolation factor based on time
    float t = glutGet(GLUT_ELAPSED_TIME) / 12500.0f; // Change color over 5 seconds
    t = fmod(t, 1.0f); // Wrap the value between 0.0 and 1.0

    // Interpolate between the sea blue and reddish brown colors
    GLfloat colorR = 0.0f + t * (0.6f - 0.0f);  // Red component
    GLfloat colorG = 0.5f - t * (0.5f - 0.4f);  // Green component
    GLfloat colorB = 0.7f - t * (0.7f - 0.2f);  // Blue component

    // Set the interpolated color
    glColor4f(colorR, colorG, colorB, 1.0f);



    // Draw the sphere
    glPushMatrix();
    glRotatef(sphereTilt, 1.0f, 0.0f, 0.0f);
    glRotatef(sphereRotation, 0.0f, 1.0f, 0.0f);

    glutSolidSphere(SPHERE_RADIUS, 50, 50);
    glPopMatrix();
     if (outerSphereOpacity > 0.0f)
    {
        glPushMatrix();
        glRotatef(90.0f - sphereTilt, 1.0f, 0.0f, 0.0f); // Tilt the sphere
        glRotatef(sphereRotation, 0.0f, 1.0f, 0.0f); // Rotate the sphere

        glDisable(GL_LIGHTING);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glColor4f(1.0f, 1.0f, 1.0f, outerSphereOpacity); // White transparent color
        glutWireSphere(OUTER_SPHERE_RADIUS, 50, 50); // Draw the transparent white sphere

        glDisable(GL_BLEND);
        glPopMatrix();
    }
    glPushMatrix();
    glRotatef(90.0f - sphereTilt, 1.0f, 0.0f, 0.0f); // Tilt the sphere
    glRotatef(sphereRotation, 0.0f, 1.0f, 0.0f); // Rotate the sphere
    glColor3f(0.0f, 1.0f, 0.0f);
    // Render the temperature text
glDisable(GL_LIGHTING);
glDisable(GL_COLOR_MATERIAL);

    // Render the temperature text
    renderTemperatureText();

    glutSwapBuffers();
}

void fadeOuterSphere(int value)
{
    int currentTime = glutGet(GLUT_ELAPSED_TIME);
    int elapsedTime = currentTime - fadeStartTime;

    if (elapsedTime >= 3000) // Wait for 5 seconds before starting the fade
    {
        float fadeDuration = 7000.0f; // Fade duration in milliseconds
        float fadeProgress = (elapsedTime - 5000.0f) / fadeDuration; // Calculate fade progress

        if (fadeProgress >= 1.0f)
        {
            outerSphereOpacity = 0.0f; // Set opacity to 0 after fade duration
        }
        else
        {
            outerSphereOpacity = 1.0f - fadeProgress; // Gradually decrease the opacity
        }
    }
    else if (elapsedTime >= 10000) // Wait for 10 seconds before reappearing
    {
        float fadeDuration = 10000.0f; // Fade duration in milliseconds
        float fadeProgress = (elapsedTime - 10000.0f) / fadeDuration; // Calculate fade progress

        if (fadeProgress >= 1.0f)
        {
            outerSphereOpacity = 1.0f; // Set opacity to 1 after fade duration
            fadeStartTime = currentTime; // Reset fade start time
        }
        else
        {
            outerSphereOpacity = fadeProgress; // Gradually increase the opacity
        }
    }
    else
    {
        outerSphereOpacity = 1.0f; // Set opacity to 1 initially
    }

    glutTimerFunc(30, fadeOuterSphere, 0); // Recursive call for smooth fading

    glutPostRedisplay();
}








void update(int value)
{


    // Update sphere rotation
    sphereRotation += 0.5f;
    if (sphereRotation > 360.0f)
        sphereRotation -= 360.0f;

    // Update outer sphere opacity


    temperature += 0.019f;
    if (temperature > 31.5f)
        temperature = 20.0f;

    fadeOuterSphere(0);// Call fadeOuterSphere to initiate fading

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // 60 FPS (1000ms / 16.66ms)
}

void idle()
{
    // Update rotation angle
    sphereRotation += 0.01f; // Slower rotation speed

    // Redraw the scene
    glutPostRedisplay();
}

void reshape(int width, int height)
{
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0, 100.0);
}
void key(unsigned char key,int x,int y)
{
    if(key=='Q')
    {
        showWelcomePage();
    //glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("GLOBAL WARMING AND OZONE");
    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, update, 0);
    initializeStars();
    glutMainLoop();
    }

}
int main(int argc, char** argv)
{
    //showWelcomePage();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("GLOBAL WARMING AND OZONE");
    //glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display1);
    glutKeyboardFunc(key);
    //glutReshapeFunc(reshape);
    //glutTimerFunc(0, update, 0);
    //initializeStars();
    glutMainLoop();
    return 0;
}
