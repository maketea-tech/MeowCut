#include "MeowGLWidget.h"
#include "ui_MeowGLWidget.h"

#include <QOpenGLShaderProgram>
#include <QDebug>

/**
* refrence: https://cloud.tencent.com/developer/article/1705815
*/

MeowGLWidget::MeowGLWidget(QWidget *parent)
	: QOpenGLWidget(parent)
{
	ui = new Ui::MeowGLWidget();
	ui->setupUi(this);
}

MeowGLWidget::~MeowGLWidget()
{
	delete ui;
}

void MeowGLWidget::initializeGL() {
	initializeOpenGLFunctions();

    // 创建顶点着色器
    QOpenGLShader* vshader = new QOpenGLShader(QOpenGLShader::Vertex, this);
    const char* vsrc =
        "in vec4 vPosition;                        \n"
        "void main() {                             \n"
        "   gl_Position = vPosition;               \n"
        "}                                         \n";
    vshader->compileSourceCode(vsrc);

    // 创建片段着色器
    QOpenGLShader* fshader = new QOpenGLShader(QOpenGLShader::Fragment, this);
    const char* fsrc =
        "void main() {                              \n"
        "   gl_FragColor = vec4(0.0, 1.0, 1.0, 1.0);\n"
        "}                                          \n";
    fshader->compileSourceCode(fsrc);

    // 创建着色器程序
    program = new QOpenGLShaderProgram;
    program->addShader(vshader);
    program->addShader(fshader);

    program->link();
    program->bind();

    // 顶点位置
    GLfloat vertices[] = {
        -0.8f, 0.8f, 0.0f,
        -0.8f, -0.8f, 0.0f,
        0.8f, -0.8f, 0.0f,
        0.8f, 0.8f, 0.0f
    };

    vbo.create();
    vbo.bind();
    vbo.allocate(vertices, 9 * sizeof(GLfloat));
    vbo.setUsagePattern(QOpenGLBuffer::StreamDraw);

    vao.create();
    vao.bind();

    GLuint vPosition = program->attributeLocation("vPosition");
    
    //为着色器中的位置设定顶点缓存
    program->setAttributeBuffer(vPosition, GL_FLOAT, 0, 3, 0);
    program->enableAttributeArray(vPosition); //使能顶点属性

    //6.解绑所有对象
    vao.release();
    vbo.release();
    program->release();
}

void MeowGLWidget::paintGL() {
    qDebug() << "This is paintGL.";

    int w = width();
    int h = height();
    int side = qMin(w, h);
    static float flag = 2.0f;
    glViewport((w - side) / flag,(h - side) / flag, side, side);
    flag = (flag == 2.0f) ? 3.0f : 2.0f;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // 渲染Shader
    program->bind(); //绑定激活Program对象
    vao.bind();      //绑定激活vao
    glDrawArrays(GL_TRIANGLES, 0, 3);    //绘制3个定点,样式为三角形
    vao.release();       //解绑
    program->release();  //解绑
    update(); // 再次触发paintGL的调用
}

void MeowGLWidget::resizeGL(int width, int height) {

}