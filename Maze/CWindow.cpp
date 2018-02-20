#include "CWindow.h"

CWindow::CWindow(const string& name, int argc, char* argv[])
  : mName(name)
{
  glutInit(&argc, argv); // Initialize GLUT
  glutInitWindowSize(sCurrentWidth, sCurrentHeight);
  glutInitWindowPosition(800, 200);
  glutCreateWindow("Maze Game");
  glClearColor(0.0, 0.0, 0.0, 0.0); //  set the "clearing" or background color
  glEnable(GL_DEPTH_TEST);
}

CWindow::~CWindow()
{
}

void CWindow::Init()
{
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

  glGenTextures(1, &texName);
  glBindTexture(GL_TEXTURE_2D, texName);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

void CWindow::DisplayGlut(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear the color buffer (i.e., set background) with the current "clearing" color
  glEnable(GL_TEXTURE_2D);
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
  glBindTexture(GL_TEXTURE_2D, texName);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0, 0.0); glVertex3f(-2.0, -1.0, 0.0);
  glTexCoord2f(0.0, 1.0); glVertex3f(-2.0, 1.0, 0.0);
  glTexCoord2f(1.0, 1.0); glVertex3f(0.0, 1.0, 0.0);
  glTexCoord2f(1.0, 0.0); glVertex3f(0.0, -1.0, 0.0);
  glEnd();
  glFlush();
  //glDisable(GL_TEXTURE_2D);
}

void CWindow::Display(const int width, const int height, const void* pixels)
{
  SpecifyImage(width, height, pixels);
  glutDisplayFunc(DisplayGlut);
}

void CWindow::Reshape(void)
{
  glutReshapeFunc(ReshapeGlut);
}

void CWindow::ReshapeGlut(int w, int h)
{
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 30.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0.0, 0.0, -3.6);
}

void CWindow::SpecifyImage(const int width, const int height, const void* pixels)
{
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
}

void CWindow::Loop(void)
{
  glutMainLoop();
}


//
//int CWindow::sCurrentWidth = 800;
//int CWindow::sCurrentHeight = 600;
//unsigned CWindow::FrameCount = 0;
//
//
//GLuint CWindow::VertexShaderId = 0;
//GLuint CWindow::FragmentShaderId = 0;
//GLuint CWindow::ProgramId = 0;
//GLuint CWindow::VaoId = 0;
//GLuint CWindow::VboId = 0;
//GLuint CWindow::ColorBufferId = 0;
//
//CWindow::CWindow(const string& name, int argc, char* argv[])
//  : mWindowHandle(0)
//  , mName(name)
//{
//  Init(argc, argv);
//
//  mGlewInitResult = glewInit();
//
//  if (GLEW_OK != mGlewInitResult)
//  {
//    fprintf(stderr, "ERROR: %s\n", glewGetErrorString(mGlewInitResult));
//    exit(EXIT_FAILURE);
//  }
//
//  fprintf(stdout, "INFO: OpenGL Version: %s\n", glGetString(GL_VERSION));
//
//  CreateShaders();
//  CreateVBO();
//
//  glClearColor(sRead, sGreen, sBlue, sAlpha);
//}
//
//CWindow::~CWindow()
//{
//}
//
//void CWindow::Init(int argc, char* argv[])
//{
//  glutInit(&argc, argv);
//
//  glutInitContextVersion(sMajorVersion, sMinorVersion);
//  glutInitContextFlags(GLUT_FORWARD_COMPATIBLE);
//  glutInitContextProfile(GLUT_CORE_PROFILE);
//
//  glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
//
//  glutInitWindowSize(sCurrentWidth, sCurrentHeight);
//
//  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
//
//  char* chr = _strdup(mName.c_str());
//  mWindowHandle = glutCreateWindow(chr);
//
//  if (mWindowHandle < sMaxWIndowHandles)
//  {
//    fprintf(stderr,"ERROR: Could not create a new rendering window.\n");
//    exit(EXIT_FAILURE);
//  }
//
//  glutReshapeFunc(sResize);
//  glutDisplayFunc(sRender);
//
//  glutIdleFunc(IdleFunction);
//  glutTimerFunc(0, TimerFunction, 0);
//
//  glutCloseFunc(Cleanup);
//}
//
//void CWindow::sResize(int Width, int Height)
//{
//  sCurrentWidth = Width;
//  sCurrentHeight = Height;
//  glViewport(sGLintX, sGLintY, sCurrentWidth, sCurrentHeight);
//}
//
//void CWindow::sRender(void)
//{
//  ++FrameCount;
//
//  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//  glDrawArrays(GL_TRIANGLES, 0, 3);
//
//  glutSwapBuffers();
//  glutPostRedisplay();
//}
//
//void CWindow::IdleFunction(void)
//{
//  glutPostRedisplay();
//}
//
//void CWindow::TimerFunction(int Value)
//{
//  if (0 != Value)
//  {
//    char* TempString = _strdup("bla");
//
//    //sprintf(TempString,"%s: %d Frames Per Second @ %d x %d",WINDOW_TITLE_PREFIX,FrameCount * 4,sCurrentWidth,sCurrentHeight);
//
//    glutSetWindowTitle(TempString);
//    free(TempString);
//  }
//
//  FrameCount = 0;
//  glutTimerFunc(250, TimerFunction, 1);
//}
//
//void CWindow::Cleanup(void)
//{
//  DestroyShaders();
//  DestroyVBO();
//}
//
//void CWindow::CreateVBO(void)
//{
//  GLfloat Vertices[] =
//  {
//    -0.8f, -0.8f, 0.0f, 1.0f,
//    0.0f,  0.8f, 0.0f, 1.0f,
//    0.8f, -0.8f, 0.0f, 1.0f
//  };
//
//  GLfloat Colors[] =
//  {
//    1.0f, 0.0f, 0.0f, 1.0f,
//    0.0f, 1.0f, 0.0f, 1.0f,
//    0.0f, 0.0f, 1.0f, 1.0f
//  };
//
//  GLenum ErrorCheckValue = glGetError();
//
//  glGenVertexArrays(1, &VaoId);
//  glBindVertexArray(VaoId);
//
//  glGenBuffers(1, &VboId);
//  glBindBuffer(GL_ARRAY_BUFFER, VboId);
//  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
//  glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
//  glEnableVertexAttribArray(0);
//
//  glGenBuffers(1, &ColorBufferId);
//  glBindBuffer(GL_ARRAY_BUFFER, ColorBufferId);
//  glBufferData(GL_ARRAY_BUFFER, sizeof(Colors), Colors, GL_STATIC_DRAW);
//  glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);
//  glEnableVertexAttribArray(1);
//
//  ErrorCheckValue = glGetError();
//  if (ErrorCheckValue != GL_NO_ERROR)
//  {
//    fprintf(
//      stderr,
//      "ERROR: Could not create a VBO: %s \n",
//      gluErrorString(ErrorCheckValue)
//    );
//
//    exit(-1);
//  }
//}
//
//void CWindow::DestroyVBO(void)
//{
//  GLenum ErrorCheckValue = glGetError();
//
//  glDisableVertexAttribArray(1);
//  glDisableVertexAttribArray(0);
//
//  glBindBuffer(GL_ARRAY_BUFFER, 0);
//  glDeleteBuffers(1, &ColorBufferId);
//  glDeleteBuffers(1, &VboId);
//
//  glBindVertexArray(0);
//  glDeleteVertexArrays(1, &VaoId);
//
//  ErrorCheckValue = glGetError();
//  if (ErrorCheckValue != GL_NO_ERROR)
//  {
//    fprintf(
//      stderr,
//      "ERROR: Could not destroy the VBO: %s \n",
//      gluErrorString(ErrorCheckValue)
//    );
//
//    exit(-1);
//  }
//}
//
//void CWindow::CreateShaders(void)
//{
//  GLenum ErrorCheckValue = glGetError();
//
//  VertexShaderId = glCreateShader(GL_VERTEX_SHADER);
//  glShaderSource(VertexShaderId, 1, &VertexShader, NULL);
//  glCompileShader(VertexShaderId);
//
//  FragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
//  glShaderSource(FragmentShaderId, 1, &FragmentShader, NULL);
//  glCompileShader(FragmentShaderId);
//
//  ProgramId = glCreateProgram();
//  glAttachShader(ProgramId, VertexShaderId);
//  glAttachShader(ProgramId, FragmentShaderId);
//  glLinkProgram(ProgramId);
//  glUseProgram(ProgramId);
//
//  ErrorCheckValue = glGetError();
//  if (ErrorCheckValue != GL_NO_ERROR)
//  {
//    fprintf(
//      stderr,
//      "ERROR: Could not create the shaders: %s \n",
//      gluErrorString(ErrorCheckValue)
//    );
//
//    exit(-1);
//  }
//}
//
//void CWindow::DestroyShaders(void)
//{
//  GLenum ErrorCheckValue = glGetError();
//
//  glUseProgram(0);
//
//  glDetachShader(ProgramId, VertexShaderId);
//  glDetachShader(ProgramId, FragmentShaderId);
//
//  glDeleteShader(FragmentShaderId);
//  glDeleteShader(VertexShaderId);
//
//  glDeleteProgram(ProgramId);
//
//  ErrorCheckValue = glGetError();
//  if (ErrorCheckValue != GL_NO_ERROR)
//  {
//    fprintf(
//      stderr,
//      "ERROR: Could not destroy the shaders: %s \n",
//      gluErrorString(ErrorCheckValue)
//    );
//
//    exit(-1);
//  }
//}