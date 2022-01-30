#pragma once

#include <QOpenGLWidget>

#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>

namespace Ui { class MeowGLWidget; };

class QOpenGLShaderProgram;

class MeowGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
	Q_OBJECT

public:
	MeowGLWidget(QWidget *parent = Q_NULLPTR);
	~MeowGLWidget();

protected:
	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);

private:
	Ui::MeowGLWidget *ui;
private:
	QOpenGLShaderProgram* program;
	QOpenGLBuffer vbo;
	QOpenGLVertexArrayObject vao;
};
