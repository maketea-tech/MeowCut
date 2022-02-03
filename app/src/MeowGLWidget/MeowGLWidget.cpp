#include "MeowGLWidget.h"
#include "ui_MeowGLWidget.h"

#include <QOpenGLShaderProgram>

#ifdef DEBUG
#include <QDebug>
#endif  // !DEBUG

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

    // ����������ɫ��
    QOpenGLShader* vshader = new QOpenGLShader(QOpenGLShader::Vertex, this);
    const char* vsrc =
        "in vec4 vPosition;                        \n"
        "void main() {                             \n"
        "   gl_Position = vPosition;               \n"
        "}                                         \n";
    vshader->compileSourceCode(vsrc);

    // ����Ƭ����ɫ��
    QOpenGLShader* fshader = new QOpenGLShader(QOpenGLShader::Fragment, this);
    const char* fsrc =
        "void main() {                              \n"
        "   gl_FragColor = vec4(0.0, 1.0, 1.0, 1.0);\n"
        "}                                          \n";
    fshader->compileSourceCode(fsrc);

    // ������ɫ������
    program = new QOpenGLShaderProgram;
    program->addShader(vshader);
    program->addShader(fshader);

    program->link();
    program->bind();

    // ����λ��
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
    
    //Ϊ��ɫ���е�λ���趨���㻺��
    program->setAttributeBuffer(vPosition, GL_FLOAT, 0, 3, 0);
    program->enableAttributeArray(vPosition); //ʹ�ܶ�������

    //6.������ж���
    vao.release();
    vbo.release();
    program->release();
}

void MeowGLWidget::paintGL() {
#ifdef DEBUG
    qDebug() << "This is paintGL.";
#endif  // !DEBUG

    int w = width();
    int h = height();
    int side = qMin(w, h);
    static float flag = 2.0f;
    glViewport((w - side) / flag,(h - side) / flag, side, side);
    flag = (flag == 2.0f) ? 3.0f : 2.0f;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // ��ȾShader
    program->bind(); //�󶨼���Program����
    vao.bind();      //�󶨼���vao
    glDrawArrays(GL_TRIANGLES, 0, 3);    //����3������,��ʽΪ������
    vao.release();       //���
    program->release();  //���
    update(); // �ٴδ���paintGL�ĵ���
}

void MeowGLWidget::resizeGL(int width, int height) {

}