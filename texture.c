
 
 #include <GL/gl.h>
 #include <GL/glut.h>
 
 /* This program does not feature some physical simulation screaming
    for continuous updates, disable that waste of resources */
 #define STUFF_IS_MOVING 0
 
 #if STUFF_IS_MOVING
     #include <unistd.h>
 #endif
 
 #include <stdlib.h>
 #include <math.h>
 #include <time.h>
 
 /* using the routine above - replace this declaration with the snippet above */
 GLuint raw_texture_load(const char *filename, int width, int height);
 
 static GLuint texture;
 
 void render()
 {
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     /* fov, aspect, near, far */
     gluPerspective(60, 1, 1, 10);
     gluLookAt(0, 0, -2, /* eye */
               0, 0, 2, /* center */
               0, 1, 0); /* up */
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
         glEnable(GL_TEXTURE_2D);
         
         /* create a square on the XY
            note that OpenGL origin is at the lower left
            but texture origin is at upper left
            => it has to be mirrored
            (gasman knows why i have to mirror X as well) */
         glBegin(GL_QUADS);
         glNormal3f(0.0, 0.0, 1.0);
         glTexCoord2d(1, 1); glVertex3f(0.0, 0.0, 0.0);
         glTexCoord2d(1, 0); glVertex3f(0.0, 1.0, 0.0);
         glTexCoord2d(0, 0); glVertex3f(1.0, 1.0, 0.0);
         glTexCoord2d(0, 1); glVertex3f(1.0, 0.0, 0.0);
         glEnd();
         
         glDisable(GL_TEXTURE_2D);
     glPopAttrib();
     
     glFlush();
     
     glutSwapBuffers();
 }
 
 void init()
 {
     glClearColor(0.0, 0.0, 0.0, 0.0);
     glShadeModel(GL_SMOOTH);
     
     glEnable(GL_LIGHTING);
     glEnable(GL_LIGHT0);
     glEnable(GL_DEPTH_TEST);
     
     glLightfv(GL_LIGHT0, GL_POSITION, (GLfloat[]){2.0, 2.0, 2.0, 0.0});
     glLightfv(GL_LIGHT0, GL_AMBIENT, (GLfloat[]){1.0, 1.0, 1.0, 0.0});
     
     texture = raw_texture_load("texture.raw", 200, 256);
 }
 
 #if STUFF_IS_MOVING
 void idle()
 {
     render();
     usleep((1 / 50.0) * 1000000);
 }
 #endif
 
 void resize(int w, int h)
 {
     glViewport(0, 0, (GLsizei) w, (GLsizei) h);
 }
 
 void key(unsigned char key, int x, int y)
 {
     if (key == 'q') exit(0);
 }
 
 int main(int argc, char *argv[])
 {
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
     glutInitWindowSize(640, 480);
     glutCreateWindow("Texture demo - [q]uit");
     
     init();
     glutDisplayFunc(render);
     glutReshapeFunc(resize);
     #if STUFF_IS_MOVING
         glutIdleFunc(idle);
     #endif
     glutKeyboardFunc(key);
     
     glutMainLoop();
     
     return 0;
 }
 
//  // #include <GL/glew.h>
//  // #include <GL/glut.h>
//  #include "wolf.h"
//  /* This program does not feature some physical simulation screaming
//     for continuous updates, disable that waste of resources */
//  #define STUFF_IS_MOVING 0
 
//  #if STUFF_IS_MOVING
//      #include <unistd.h>
//  #endif
 
//  #include <stdlib.h>
//  #include <math.h>
//  #include <time.h>
 
//  /* using the routine above - replace this declaration with the snippet above */
//  GLuint raw_texture_load(const char *filename, int width, int height);
 
//  static GLuint texture;
 
// //////////////////////////////////////////////////////////////////////////
// GLuint loadBMP_custom(const char * imagepath){

//     printf("Reading image %s\n", imagepath);

//     // Data read from the header of the BMP file
//     unsigned char header[54];
//     unsigned int dataPos;
//     unsigned int imageSize;
//     unsigned int width, height, bpp;
//     // Actual RGB data
//     //////////////// unsigned char * data;

//     // Open the file
//     FILE * file = fopen(imagepath,"rb");
//     if (!file)                              {printf("Image could not be opened\n"); return 0;}

//     // Read the header, i.e. the 54 first bytes

//     // If less than 54 byes are read, problem
//     if ( fread(header, 1, 54, file)!=54 ){ 
//         printf("111Not a correct BMP file\n");
//         return 0;
//     }
//     // A BMP files always begins with "BM"
//     if ( header[0]!='B' || header[1]!='M' ){
//         printf("222Not a correct BMP file\n");
//         return 0;
//     }
//     // Make sure this is a 24bpp file
//     if ( *(int*)&(header[0x1E])!=0  )         {printf("33333Not a correct BMP file\n");    return 0;}
//     // if ( *(int*)&(header[0x1C])!=24 )         {printf("44444Not a correct BMP file\n");    return 0;}

//     // Read the information about the image
//     dataPos    = *(int*)&(header[0x0A]);
//     imageSize  = *(int*)&(header[0x22]);
//     width      = *(int*)&(header[0x12]);
//     height     = *(int*)&(header[0x16]);
//     bpp=3;

//     // Some BMP files are misformatted, guess missing information
//     if (imageSize==0)    imageSize=width*height*3; // 3 : one byte for each Red, Green and Blue component
//     if (dataPos==0)      dataPos=54;

//     // Create a buffer
//     unsigned char data[imageSize];

//     // Read the actual data from the file into the buffer
//     fread(data,1,imageSize,file);

//     // Everything is in memory now, the file wan be closed
//     fclose (file);

//     // Swap Red and Blue component for each texel of the image
//     unsigned char t;
//     for (unsigned int i = 0; i < imageSize; i += 3 )
//     {
//         t = data[i];
//         data[i] = data[i+2];
//         data[i+2] = t;
//     }

//     // Create one OpenGL texture
//     GLuint textureID;
//     glGenTextures(1, &textureID);
    
//     // "Bind" the newly created texture : all future texture functions will modify this texture
//     glBindTexture(GL_TEXTURE_2D, textureID);

//     // Give the image to OpenGL
//     glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0,(bpp == 3 ? GL_RGB : GL_RGBA), GL_UNSIGNED_BYTE, data);

//     // Poor filtering, or ...
//     //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//     //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); 

//     // ... nice trilinear filtering.
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); 
//     glGenerateMipmap(GL_TEXTURE_2D);

//     // Return the ID of the texture we just created
//     return textureID;
// }
// //////////////////////////////////////////////////////////////////////////

// GLuint raw_texture_load(const char *filename, int width, int height)
//  {
//      GLuint texture;
//      unsigned char *data;
//      FILE *file;
     
//      // open texture data
//      file = fopen(filename, "rb");
//      if (file == NULL) return 0;
     
//      // allocate buffer
//      data = (unsigned char*) malloc(width * height * 4);
     
//      // read texture data
//      fread(data, width * height * 4, 1, file);
//      fclose(file);
     
//      // allocate a texture name
//      glGenTextures(1, &texture);
     
//      // select our current texture
//      glBindTexture(GL_TEXTURE_2D, texture);
     
//      // select modulate to mix texture with color for shading
//      glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
     
//      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_DECAL);
//      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_DECAL);
     
//      // when texture area is small, bilinear filter the closest mipmap
//      glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
//      // when texture area is large, bilinear filter the first mipmap
//      glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
     
//      // texture should tile
//      glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//      glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
     
//      // build our texture mipmaps
//      glGenerateMipmap(GL_TEXTURE_2D);
     
//      // free buffer
//      free(data);
     
//      return texture;
//  }



//  void render(GLFWwindow  *window)
//  {
//      // glMatrixMode(GL_PROJECTION);
//      // glLoadIdentity();
//      /* fov, aspect, near, far */
//      // glMatrixMode(GL_MODELVIEW);
//      // glLoadIdentity();
     
//      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//      glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//          glEnable(GL_TEXTURE_2D);
         
//          /* create a square on the XY
//             note that OpenGL origin is at the lower left
//             but texture origin is at upper left
//             => it has to be mirrored
//             (gasman knows why i have to mirror X as well) */
//          glBegin(GL_QUADS);
//          glNormal3f(0.0, 0.0, 1.0);
//          glTexCoord2d(1, 1); glVertex3f(0.0, 0.0, 0.0);
//          glTexCoord2d(1, 0); glVertex3f(0.0, 1.0, 0.0);
//          glTexCoord2d(0, 0); glVertex3f(1.0, 1.0, 0.0);
//          glTexCoord2d(0, 1); glVertex3f(1.0, 0.0, 0.0);
//          glEnd();
         
//          glDisable(GL_TEXTURE_2D);
//      glPopAttrib();
     
//      // glfwSwapBuffers(window);
//  }
 
//  void init()
//  {
//      glClearColor(0.0, 0.0, 0.0, 0.0);
//      glShadeModel(GL_SMOOTH);
     
//      glEnable(GL_LIGHTING);
//      glEnable(GL_LIGHT0);
//      glEnable(GL_DEPTH_TEST);
     
//      glLightfv(GL_LIGHT0, GL_POSITION, (GLfloat[]){2.0, 2.0, 2.0, 0.0});
//      glLightfv(GL_LIGHT0, GL_AMBIENT, (GLfloat[]){1.0, 1.0, 1.0, 0.0});
     
//      // texture = raw_texture_load("texture.raw", 200, 256);
//      // texture = raw_texture_load("WallPack/Flag.bmp", 64, 64);
//      // stbi_load("./WallPack/Black3.bmp", &width, &height, &nrChannels, 0);
//      texture = loadBMP_custom("./WallPack/Black3.bmp");
//  }
 
//  #if STUFF_IS_MOVING
//  void idle()
//  {
//      render();
//      usleep((1 / 50.0) * 1000000);
//  }
//  #endif
 
//  void resize(int w, int h)
//  {
//      glViewport(0, 0, (GLsizei) w, (GLsizei) h);
//  }
 
// void    key_callback(GLFWwindow* window, int key, int scan, int act, int mods)
//  {
//      if (key == GLFW_KEY_ESCAPE)
//      exit(0);
//  }
 
//  int main(int argc, char *argv[])
//  {
//     GLFWwindow  *window;
//     t_main      *win;
//     void        *data;

//     glfwInit();

//     glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//     window = glfwCreateWindow(WIDTH, HEIGHT, "WOLF", NULL, NULL);
// glfwMakeContextCurrent(window);

// glfwSetKeyCallback(window, key_callback);
// // glfwSetCursorPosCallback(window, *mouse_pos);
//     glfwSwapInterval(1);
    
//     init();

// while (!glfwWindowShouldClose(window))
//     {
//         render(window);
//         glfwSwapBuffers(window);
//         glfwPollEvents();
//     }
     
//      return 0;
//  }
// // -framework GLUT -framework OpenGL -framework Cocoa